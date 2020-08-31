#ifndef __AEE2004_HANDLERS_H__
#define __AEE2004_HANDLERS_H__

#include "handlers_hs.h"
#include "handlers_ls.h"

// Define global handlers
struct id_handler **AEE2004_handlers[] = { hs_handlers, ls_handlers };

#endif /* __AEE2004_HANDLERS_H__ */