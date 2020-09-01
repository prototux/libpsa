#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <inttypes.h>

#include "../include/common.h"
#include "../include/socketcan.h"
#include "../include/psa.h"

int main(int argc, char **argv)
{
	printf("Init AEE2004\n");
	psa_init(ARCH_AEE2004);
	printf("Open vcanconf\n");
	psa_socketcan_open(AEE2004_BUS_CONF, "vcanconf");
	struct psa_can_frame frame = {
		.bus = AEE2004_BUS_CONF,
		.id = 0x21F,
		.len = 3,
		.data = {0x02, 0x00, 0x00}
	};
	printf("Parse frame\n");
	struct named_data *ret = psa_parse(&frame);
	struct named_data *data = ret; //psa_get_named(AEE2004_BUS_CONF, 0x21F);
	uint8_t i = 0;
	while (data[i+1].name)
	{
		if (data[i].type == BOOL)
			printf("%s: %x\n", data[i].name, *data[i].data_bool);
		else if (data[i].type == U8)
			printf("%s: %x\n", data[i].name, *data[i].data_u8);
		i++;
	}
	return EXIT_SUCCESS;
}
