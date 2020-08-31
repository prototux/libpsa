#ifndef __HANDLERS_H__
#define __HANDLERS_H__

#include "AEE2004/handlers.h"
#include "ids_common.h"

// Handlers
struct id_handler ***handlers = {
	NULL, // VAN_handlers
	AEE2004_handlers,
	//AEE2010_handlers,
};

#endif /* __HANDLERS_H__ */
