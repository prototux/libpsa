#ifndef __AEE2004_LS_IDS_21F_H__
#define __AEE2004_LS_IDS_21F_H__

#include <stdbool.h>
#include "../../ids_common.h"
STRUCT_DATA(21F) {
	bool HDC_SOURCE;
	bool HDC_VOLUME_DOWN;
	bool HDC_VOLUME_UP;
	bool HDC_PRECEDENT;
	bool HDC_SUIVANT;
	uint8_t HDC_MOLETTE;
};

//struct id_21F_data id_21F_data_raw;
STRUCT_DATA_RAW(21F)

//struct named_data id_21F_named_data[] = {
LIST_NAMED_DATA(21F) = {
	{ .name = "HDC_SOURCE", .data = &(id_21F_data_raw.HDC_SOURCE) },
	{ .name = "HDC_VOLUME_DOWN", .data = &(id_21F_data_raw.HDC_VOLUME_DOWN) },
	NAMED_DATA(21F, HDC_VOLUME_UP),
};

//void id_21F_read(struct psa_can_frame *frame);
ID_READ(21F);
//void id_21F_write(struct id_21F_data *data);
ID_WRITE(21F);

#endif /* __AEE2004_LS_IDS_21F_H__ */
