#ifndef _CGRAPH_STACK_H_
#define _CGRAPH_STACK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"
#include "cgraph_pobject.h"

#define TYPE_STACK
#include "template.h"

typedef struct
{
  CGRAPH_STRUCTURE_BASE
  CGRAPH_STRUCTURE_ROOT
}cgraph_stack_t;

#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_STACK_H_ */
