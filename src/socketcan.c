#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <sys/socket.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <string.h>

// libpsa public includes
#include "../include/common.h"
#include "../include/socketcan.h"
#include "../include/psa.h"

// libpsa private includes
//#include "handlers.h"

// Global sockets list
int sockets[5] = {0};

uint8_t psa_socketcan_read(uint8_t bus)
{
	struct can_frame can_frame;
	struct psa_can_frame psa_frame;
	int sock = 0;

	// Get the socket
	if (!sockets[bus])
		return 1;
	sock = sockets[bus];

	// Read from socket
	if (read(sock, &can_frame, sizeof(struct can_frame)) < 0)
		return ESOCKREAD;

	// Copy data to a psa_can_frame
	psa_frame.bus = bus;
	psa_frame.id = can_frame.can_id;
	psa_frame.len = can_frame.can_dlc;
	memcpy(&(psa_frame.data), &(can_frame.data), 8);

	// Parse it
	psa_parse(&psa_frame);
	return SUCCESS;
}

void psa_socketcan_write_frame(struct psa_can_frame *frame)
{
	int sock = 0;
	sock = sockets[frame->bus];
	struct can_frame can_frame;
	can_frame.can_id = frame->id;
	can_frame.can_dlc = frame->len;
	memcpy(&(can_frame.data), &(frame->data), 8);
	write(sock, &can_frame, sizeof(struct can_frame));
}

uint8_t psa_socketcan_open(uint8_t bus, const char *network_name)
{
	int sock = 0;
	if (bus >=5)
		return 1;

	// Check if the bus isn't already opened
	if (sockets[bus])
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

	if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
		return ESOCKBIND;

	// Add the socket to the list of opened sockets
	sockets[bus] = sock;
	return SUCCESS;
}
