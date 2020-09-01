#ifndef __AEE2004_HANDLERS_LS_H__
#define __AEE2004_HANDLERS_LS_H__

#include "../ids_common.h"
#include "ls-ids/all.h"

struct id_handler ls_handlers[] = {
	[0x21F] = ID_HANDLER(AEE2004, LS, 21F), // CDE_RADIO
};

#endif /* __AEE2004_HANDLERS_LS_H__ */
