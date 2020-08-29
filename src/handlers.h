#ifndef __HANDLERS_H__
#define __HANDLERS_H__

#include "AEE2004/handlers.h"

// Handlers
void (*write_handler)(struct psa_can_frame *frame);
uint8_t (*read_handler)(uint8_t bus, struct psa_can_frame *frame);

#endif /* __HANDLERS_H__ */
