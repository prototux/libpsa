#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <sys/socket.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/ioctl.h>

// libpsa public includes
#include "../include/common.h"
#include "../include/socketcan.h"
#include "../include/psa.h"

// libpsa private includes
//#include "handlers.h"

// Global sockets list
struct psa_socketcan_socket *sockets = NULL;

uint8_t psa_socketcan_read_handler(uint8_t bus, struct psa_can_frame *psa_frame)
{
	struct can_frame can_frame;
	int sock = NULL;
	psa_socketcan_getsock(bus, &sock);

	// Read from socket
	if (read(sock, &can_frame, sizeof(struct can_frame)) < 0)
		return ESOCKREAD;

	// Copy data to a psa_can_frame
	psa_frame->bus = bus;
	psa_frame->id = can_frame.can_id;
	psa_frame->len = can_frame.can_dlc;
	memcpy(&(psa_frame->data), &(can_frame.data), 8);
	return NULL;
}

void psa_socketcan_write_handler(struct psa_can_frame *frame)
{
	int sock = NULL;
	psa_socketcan_getsock(frame->bus, &sock);
	struct can_frame can_frame;
	can_frame.can_id = frame->id;
	can_frame.can_dlc = frame->len;
	memcpy(&(can_frame.data), &(frame->data), 8);
	write(sock, &can_frame, sizeof(struct can_frame));
}

uint8_t psa_socketcan_getsock(uint8_t bus, int *sock)
{
	struct psa_socketcan_socket *tmp_sockets = sockets;
	if (!sockets)
		return ESOCKEMPTY;

	while (tmp_sockets->next)
	{
		if (tmp_sockets->bus == bus)
		{
			*sock = *(tmp_sockets->sock);
			return NULL;
		}
		tmp_sockets = tmp_sockets->next;
	}
	return ESOCKNOTFOUND;
}

uint8_t psa_socketcan_addsock(uint8_t bus, int *sock)
{
	struct psa_socketcan_socket *tmp_sockets = sockets;
	struct psa_socketcan_socket new_socket;
	new_socket.bus = bus;
	new_socket.sock = *sock;
	new_socket.next = NULL;
	if (!sockets)
		sockets = &new_socket;
	else
	{
		while(tmp_sockets->next)
			tmp_sockets = tmp_sockets->next;
		tmp_sockets->next = &new_socket;
	}
	return NULL;
}

uint8_t psa_socketcan_open(uint8_t bus, const char *network_name)
{
	int sock = NULL;
	// Check if the bus isn't already opened
	if (psa_socketcan_getsock(bus, &sock) != ESOCKNOTFOUND)
		return ESOCKALREADYDEFINED;

	// sock is a global var
	sock = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	if (!sock)
		return ESOCKINIT;

	// Setup ifreq with the vcan name
	struct ifreq ifr;
	strcpy(ifr.ifr_name, network_name);
	ioctl(sock, SIOCGIFINDEX, &ifr);

	struct sockaddr_can addr;
	memset(&addr, 0, sizeof(addr));
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	if(!bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
		return ESOCKBIND;

	psa_set_write_handler(&psa_socketcan_write_handler);
	psa_set_read_handler(&psa_socketcan_read_handler);

	// Add the socket to the list of opened sockets
	psa_socketcan_addsock(bus, &sock);
	return NULL;
}
