#include <inttypes.h>

#include "../../../include/psa.h"
#include "../../../include/common.h"
#include "../../ids_common.h"
#include "0B6.h"

// General informations about the frame
ID_INFOS_DEF(AEE2004, LS, 0B6) = {
	.name = "DONNEES_BSI_RAPIDES",
	.source_ecu = AEE2004_ECU_LS_BSI,
};

STRUCT_DATA_RAW(AEE2004, LS, 0B6);

LIST_NAMED_DATA(AEE2004, LS, 0B6) = {
	NAMED_DATA(AEE2004, LS, 0B6, S16, x_regime_moteur),
	NAMED_DATA(AEE2004, LS, 0B6, S16, x_vitesse),
};

ID_PARSE(AEE2004, LS, 0B6)
{
	RAW_NAME(AEE2004, LS, 0B6).x_regime_moteur = (frame->data[0]<<16|frame->data[1])/10;
	RAW_NAME(AEE2004, LS, 0B6).x_vitesse = (frame->data[2]<<16|frame->data[3])/100;
	return (struct named_data*)&AEE2004_LS_0B6_named_data;
}

ID_PACK(AEE2004, LS, 0B6)
{
	data = data;
	return 0;
}
