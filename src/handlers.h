#ifndef __HANDLERS_H__
#define __HANDLERS_H__

#include "ids_common.h"
#include <stddef.h>

struct named_data* ignore_frame_parse(struct psa_can_frame *frame);
uint8_t* ignore_frame_pack(void *data);
#define IGNORE_FRAME { .infos = (struct id_infos*)NULL, .raw = NULL, .named = (struct named_data *)NULL, .parse = ignore_frame_parse, .pack = ignore_frame_pack }

// Extern elements
extern struct id_handler *AEE2004_handlers[];
extern struct id_handler **handlers[];

#endif /* __HANDLERS_H__ */
