#ifndef __IDS_COMMON_H__
#define __IDS_COMMON_H__

struct named_data {
    char *name;
    void *data;
};

#define NAMED_DATA(can_id, data_name) { .name = "data_name", .data = &(id_##can_id##_data_raw.data_name) }
#define STRUCT_DATA_RAW(can_id) struct id_##can_id##_data id_##can_id##_data_raw;
#define STRUCT_DATA(can_id) struct id_##can_id##_data
#define LIST_NAMED_DATA(can_id) struct named_data id_##can_id##_named_data[]
#define ID_READ(can_id) void id_##can_id##_read(struct psa_can_frame *frame)
#define ID_WRITE(can_id) void id_##can_id##_write(struct id_##can_id##_data *data)

#endif /* __IDS__COMMON_H__ */
