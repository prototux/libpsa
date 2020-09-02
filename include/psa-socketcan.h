#ifndef __SOCKETCAN_H__
#define __SOCKETCAN_H__

#include <stddef.h>

#define ESOCKINIT 0x01
#define ESOCKBIND 0x02
#define ESOCKEMPTY 0x03
#define ESOCKNOTFOUND 0x04
#define ESOCKREAD 0x05
#define ESOCKALREADYDEFINED 0x06

struct psa_socketcan_socket {
	uint8_t bus;
	int *sock;
	struct psa_socketcan_socket *next;
};

uint8_t psa_socketcan_read(uint8_t bus);
//void psa_socketcan_write_frame(struct psa_can_frame *frame);
uint8_t psa_socketcan_getsock(uint8_t bus, int *sock);
uint8_t psa_socketcan_addsock(uint8_t bus, int *sock);
uint8_t psa_socketcan_open(uint8_t bus, const char *network_name);

#endif /* __SOCKETCAN_H__ */
