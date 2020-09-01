#ifndef __IDS_COMMON_H__
#define __IDS_COMMON_H__

#include <inttypes.h>
#include "../include/common.h"
#include "../include/psa.h"

// ID metadata
struct id_infos {
	char *name;
	uint8_t source_ecu;
};

// Common macro for IDs handlers
struct id_handler {
	struct id_infos *infos;
	void *raw;
	struct named_data *named;
	struct named_data* (*parse)(struct psa_can_frame *psa_frame);
	uint8_t* (*pack)(void *data);
};


#define ID_HANDLER(A, B, C) { .infos = &A##_##B##_##C##_infos, .raw = (void*)&A##_##B##_##C##_data_raw, .named = (struct named_data*)&A##_##B##_##C##_named_data, .parse = &A##_##B##_##C##_parse, .pack = &A##_##B##_##C## _pack }

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

// Raw data struct
#define STRUCT_DATA(A, B, C) struct A##_##B##_##C##_data

// Named data list
#define LIST_NAMED_DATA(A, B, C) struct named_data A##_##B##_##C##_named_data[]

// Parse function
#define ID_PARSE(A, B, C) struct named_data* A##_##B##_##C##_parse(struct psa_can_frame *frame)

// Pack function
#define ID_PACK(A, B, C) uint8_t* A##_##B##_##C##_pack(void *data)

#endif /* __IDS__COMMON_H__ */
