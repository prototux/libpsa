#ifndef __AEE2004_LS_IDS_0B6_H__
#define __AEE2004_LS_IDS_0B6_H__

#include <stdbool.h>
#include "../../ids_common.h"

STRUCT_DATA(AEE2004, LS, 0B6) {
	int16_t x_regime_moteur;
	int16_t x_vitesse;
};

extern ID_INFOS_DEF(AEE2004, LS, 0B6);
extern STRUCT_DATA_RAW(AEE2004, LS, 0B6);
extern LIST_NAMED_DATA(AEE2004, LS, 0B6);

ID_PARSE(AEE2004, LS, 0B6);
ID_PACK(AEE2004, LS, 0B6);

#endif /* __AEE2004_LS_IDS_0B6_H__ */
