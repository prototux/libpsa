#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <inttypes.h>

#include "../include/common.h"
#include "../include/socketcan.h"
#include "../include/psa.h"

int main(int argc, char **argv)
{
	psa_init(ARCH_AEE2004);
	psa_socketcan_open(AEE2004_BUS_CONF, "vcanconf");
	struct psa_can_frame frame = {
		.bus = AEE2004_BUS_CONF,
		.id = 0x21F,
		.len = 3,
		.data = {0x02, 0x00, 0x00}
	};
	psa_parse(&frame);
	return EXIT_SUCCESS;
}
