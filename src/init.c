#include <inttypes.h>
#include <sys/socket.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/ioctl.h>

// libpsa public includes
#include "../include/common.h"
#include "../include/socketcan.h"

// libpsa private includes
#include "handlers.h"

void psa_init(uint8_t arch)
{

	return;
}

void psa_set_write_handler(void (*handler)(struct psa_can_frame *frame))
{
	write_handler = handler;
	return;
}

void psa_set_read_handler(uint8_t (*handler)(uint8_t bus, struct psa_can_frame *frame))
{
	read_handler = handler;
	return;
}
