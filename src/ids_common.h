#ifndef __IDS_COMMON_H__
#define __IDS_COMMON_H__

// Common macro for IDs handlers
struct id_handler {
	void *raw;
	void *named;
	void* (*parse)(struct psa_can_struct psa_frame);
	uint8_t* (*pack)(struct psa_can_struct psa_frame);
};

#define ID_HANDLER(A, B, C) { .raw = (void*)&A_B_C_data_raw, .named = (void*)&A_B_C_named_data, .parse = &A_B_C_parse, .pack = &A_B_C_pack }

// Named data struct
struct named_data {
    char *name;
    void *data;
};

/* For the following Macros
   * A == can_arch
   * B == can_bus
   * C == can_id
   * D == data_name
*/

// Named data item
#define NAMED_DATA(A, B, C, D) { .name = "D", .data = &(A_B_C_data_raw.D) }

// Raw data struct definition
#define STRUCT_DATA_RAW(A, B, C) struct A_B_C_data A_B_C_data_raw;

// Raw data struct
#define STRUCT_DATA(A, B, C) struct A_B_C_data

// Named data list
#define LIST_NAMED_DATA(A, B, C) struct named_data A_B_C_named_data[]

// Parse function
#define ID_PARSE(A, B, C) void* A_B_C_parse(struct psa_can_frame *frame)

// Pack function
#define ID_PACK(A, B, C) uint8_t* A_B_C_pack(void *data)

#endif /* __IDS__COMMON_H__ */
