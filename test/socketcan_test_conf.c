#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <inttypes.h>

#include <psa.h>
#include <psa-socketcan.h>

void print_id(uint16_t id)
{
    struct named_data *data = psa_get_named(AEE2004_BUS_CONF, id);
    uint8_t i = 0;
    while (data[i].name)
    {
        if (data[i].type == BOOL)
            printf("%s: %x\n", data[i].name, *data[i].data_bool);
        else if (data[i].type == U8)
            printf("%s: %d\n", data[i].name, *data[i].data_u8);
        else if (data[i].type == U16)
            printf("%s: %d\n", data[i].name, *data[i].data_u16);
        else if (data[i].type == U32)
            printf("%s: %x\n", data[i].name, *data[i].data_u32);
		else if (data[i].type == S8)
			printf("%s: %d\n", data[i].name, *data[i].data_s8);
		else if (data[i].type == S16)
			printf("%s: %d\n", data[i].name, *data[i].data_s16);
		else if (data[i].type == S32)
			printf("%s: %d\n", data[i].name, *data[i].data_s32);
		else if (data[i].type == STRING)
			printf("%s: %s\n", data[i].name, data[i].data_str);
		else if (data[i].type == FLOAT)
			printf("%s: %f\n", data[i].name, *data[i].data_float);
        i++;
    }
}

void clear_screen()
{
	write(STDOUT_FILENO, (const char*)"\x1B[1;1H\x1B[2J", 12);
}

int main(void)
{
	printf("Init AEE2004\n");
	psa_init(AEE2004);
	printf("Open vcanconf\n");
	psa_socketcan_open(AEE2004_BUS_CONF, "vcanconf");
	printf("Done, parsing...\n");

	while (1)
	{
		//clear_screen();
		psa_socketcan_read(AEE2004_BUS_CONF);
		print_id(0x0B6);
		sleep(0.01);
	}
	return EXIT_SUCCESS;
}
