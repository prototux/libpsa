#include <stddef.h>
#include "arch_handlers.h"
#include "../handlers.h"

// Empty handler table
struct id_handler _VAN_empty_handlers[] = {
	NULL,
};

// Define global handlers
struct id_handler *VAN_handlers[] = { _VAN_empty_handlers };
