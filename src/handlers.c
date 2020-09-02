#include <stddef.h>
#include <inttypes.h>
#include <stdio.h>

#include <psa.h>

#include "handlers.h"

// Handlers
struct id_handler **handlers[] = {
    VAN_handlers,
    AEE2004_handlers,
    AEE2010_handlers
};

// Just a useless frame handler as a generic "ignore the frame" handler
struct named_data *ignore_frame_parse(__attribute__((unused))struct psa_can_frame *frame)
{
	printf("IGNORED: bus=%x id=%x len=%d\n", frame->bus, frame->id, frame->len);
	return NULL;
}

uint8_t *ignore_frame_pack(__attribute__((unused))void *data)
{
	return NULL;
}
