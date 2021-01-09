#ifndef _CGRAPH_QUEUE_H_
#define _CGRAPH_QUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_QUEUE
#include "template.h"

typedef struct {
    CGRAPH_STRUCTURE_BASE
    CGRAPH_STRUCTURE_ROOT
} cgraph_queue_t;

#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_QUEUE_H_ */
