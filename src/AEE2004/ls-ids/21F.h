#ifndef __AEE2004_LS_IDS_21F_H__
#define __AEE2004_LS_IDS_21F_H__

#include <stdbool.h>
#include "../../ids_common.h"

STRUCT_DATA(AEE2004, LS, 21F) {
	bool HDC_SOURCE;
	bool HDC_VOLUME_DOWN;
	bool HDC_VOLUME_UP;
	bool HDC_PRECEDENT;
	bool HDC_SUIVANT;
	uint8_t HDC_MOLETTE;
	bool HDC_MOLETTE_SUP;
	bool HDC_MOLETTE_INF;
};

extern ID_INFOS_DEF(AEE2004, LS, 21F);
extern STRUCT_DATA_RAW(AEE2004, LS, 21F);
extern LIST_NAMED_DATA(AEE2004, LS, 21F);

ID_PARSE(AEE2004, LS, 21F);
ID_PACK(AEE2004, LS, 21F);

#endif /* __AEE2004_LS_IDS_21F_H__ */
