#include <inttypes.h>

#include "../../../include/psa.h"
#include "../../../include/common.h"
#include "../../ids_common.h"
#include "21F.h"

// General informations about the frame
ID_INFOS_DEF(AEE2004, LS, 21F) = {
	.name = "CDE_RADIO",
	.source_ecus = {AEE2004_ECU_LS_HDC},
};

STRUCT_DATA_RAW(AEE2004, LS, 21F)

LIST_NAMED_DATA(AEE2004, LS, 21F) = {
	NAMED_DATA(AEE2004, LS, 21F, BOOL, HDC_SOURCE),
	NAMED_DATA(AEE2004, LS, 21F, BOOL, HDC_VOLUME_DOWN),
    NAMED_DATA(AEE2004, LS, 21F, BOOL, HDC_VOLUME_UP),
	NAMED_DATA(AEE2004, LS, 21F, BOOL, HDC_PRECEDENT),
	NAMED_DATA(AEE2004, LS, 21F, BOOL, HDC_SUIVANT),
	NAMED_DATA(AEE2004, LS, 21F, U8, HDC_MOLETTE),
	NAMED_DATA(AEE2004, LS, 21F, BOOL, HDC_MOLETTE_SUP),
	NAMED_DATA(AEE2004, LS, 21F, BOOL, HDC_MOLETTE_INF)
};__attribute__ ((visibility ("default")))

ID_PARSE(AEE2004, LS, 21F)
{
	printf("Parsing!\n");
	AEE2004_LS_21F_data_raw.HDC_SOURCE = true;
	AEE2004_LS_21F_data_raw.HDC_VOLUME_DOWN = true;
	AEE2004_LS_21F_data_raw.HDC_VOLUME_UP = true;
	printf("Parsed!\n");
	return &AEE2004_LS_21F_named_data;
}

ID_PACK(AEE2004, LS, 21F)
{
	return 0;
}
