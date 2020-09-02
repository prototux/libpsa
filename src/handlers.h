#ifndef __HANDLERS_H__
#define __HANDLERS_H__

#include <stddef.h>
#include <inttypes.h>
#include <psa.h>

// ID metadata structure
struct id_infos {
	char *name;
	uint8_t source_ecu;
};

// ID Handler structure and macro
struct id_handler {
	struct id_infos *infos;
	void *raw;
	struct named_data *named;
	struct named_data* (*parse)(struct psa_can_frame *psa_frame);
	uint8_t* (*pack)(void *data);
};

#define ID_HANDLER(A, B, C) { \
	.infos = &A##_##B##_##C##_infos, \
	.raw = (void*)&A##_##B##_##C##_data_raw, \
	.named = (struct named_data*)&A##_##B##_##C##_named_data, \
	.parse = &A##_##B##_##C##_parse, \
	.pack = &A##_##B##_##C## _pack \
}

// Global handlers table (contain all architectures)
extern struct id_handler **handlers[];

/* For the following Macros
   * A == can_arch
   * B == can_bus
   * C == can_id
   * D == data type
   * E == data name
*/

#define ID_INFOS_DEF(A, B, C) struct id_infos A##_##B##_##C##_infos

// Named data item
#define NAMED_DATA(A, B, C, D, E) { .name = #E, .type = D, .data = &A##_##B##_##C##_data_raw.E }

// Raw data struct definition
#define STRUCT_DATA_RAW(A, B, C) struct A##_##B##_##C##_data A##_##B##_##C##_data_raw

// Raw data name
#define RAW_NAME(A, B, C) A##_##B##_##C##_data_raw

// Raw data struct
#define STRUCT_DATA(A, B, C) struct A##_##B##_##C##_data

// Named data list
#define LIST_NAMED_DATA(A, B, C) struct named_data A##_##B##_##C##_named_data[]

// Parse function
#define ID_PARSE(A, B, C) struct named_data* A##_##B##_##C##_parse(struct psa_can_frame *frame)

// Pack function
#define ID_PACK(A, B, C) uint8_t* A##_##B##_##C##_pack(void *data)

// Special handler to ignore a frame
struct named_data* ignore_frame_parse(struct psa_can_frame *frame);
uint8_t* ignore_frame_pack(void *data);
#define IGNORE_FRAME { .infos = (struct id_infos*)NULL, .raw = NULL, .named = (struct named_data *)NULL, .parse = ignore_frame_parse, .pack = ignore_frame_pack }

// Handlers for each architecture
#include "VAN/arch_handlers.h"
#include "AEE2004/arch_handlers.h"
#include "AEE2010/arch_handlers.h"

#endif /* __HANDLERS_H__ */
