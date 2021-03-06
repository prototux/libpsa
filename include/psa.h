#ifndef __PSA_H__
#define __PSA_H__

#include <inttypes.h>
#include <stdbool.h>

#include "common.h"

// Generic CAN frame struct (without support for extended IDs)
struct psa_can_frame {
	uint8_t bus;
	uint16_t id;
	uint8_t len;
	uint8_t data[8];
};

enum named_data_type {
	BOOL,
	STRING,
	FLOAT,
	U8,
	U16,
	U32,
	U64,
	S8,
	S16,
	S32,
	S64
};

// Named data struct
struct named_data {
    char *name;
	enum named_data_type type;
	union {
    	void *data;
		bool *data_bool;
		uint8_t *data_u8;
		uint16_t *data_u16;
		uint32_t *data_u32;
		uint64_t *data_u64;
		int8_t *data_s8;
		int16_t *data_s16;
		int32_t *data_s32;
		int64_t *data_s64;
		char *data_str;
		float *data_float;
	};
};

// API definition
void psa_init(enum arch arch);
void *psa_get_raw(uint8_t bus, uint8_t id);
struct named_data *psa_get_named(uint8_t can_bus, uint16_t id);
struct named_data *psa_parse(struct psa_can_frame *frame);
struct named_data *psa_get_named_element(uint8_t can_bus, uint16_t id, char *element);

#endif /* __PSA_H__ */
