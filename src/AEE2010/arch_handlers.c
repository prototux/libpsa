#include <stddef.h>
#include "arch_handlers.h"
#include "../handlers.h"

// Empty handler table
struct id_handler _AEE2010_empty_handlers[] = {
	NULL,
};

// Define global handlers
struct id_handler *AEE2010_handlers[] = { _AEE2010_empty_handlers };
