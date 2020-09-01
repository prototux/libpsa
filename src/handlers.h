#ifndef __HANDLERS_H__
#define __HANDLERS_H__

#include "ids_common.h"
#include "AEE2004/handlers.h"

// Handlers
struct id_handler **handlers[] = {
    NULL, // VAN_handlers
    AEE2004_handlers,
    NULL // AEE2010_handlers
};

#endif /* __HANDLERS_H__ */
