#ifndef __PSA_H__
#define __PSA_H__

#include <inttypes.h>

// Generic CAN frame struct (without support for extended IDs)
struct psa_can_frame {
	uint8_t bus;
	uint16_t id;
	uint8_t len;
	uint8_t data[8];
};


// API definition
void psa_set_write_handler(void (*handler)(struct psa_can_frame *frame));
void psa_set_read_handler(struct psa_can_frame* (*handler)(void));
void psa_open_socketcan(uint8_t bus_id, char *network_name);

#endif /* __PSA_H__ */
