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
#include "handlers.h"

// Current architecture (global)
enum arch current_arch = UNDEFINED;

void psa_init(enum arch arch)
{
	current_arch = arch;
}

struct named_data *psa_parse(struct psa_can_frame *frame)
{
	uint8_t bus;
	if (current_arch == AEE2004)
		bus = (frame->bus == AEE2004_BUS_IS)? 0:1;
	struct named_data* (*parser)(struct psa_can_frame *frame) = handlers[current_arch][bus][frame->id].parse;
	return (*parser)(frame);
}

void *psa_get_raw(uint8_t bus, uint8_t id)
{
	return handlers[current_arch][bus][id].raw;
}

struct named_data *psa_get_named(uint8_t can_bus, uint16_t id)
{
	uint8_t bus;
    if (current_arch == AEE2004)
	{
		bus = (can_bus == AEE2004_BUS_IS)? 0:1;
	}
	return handlers[current_arch][bus][id].named;
}
