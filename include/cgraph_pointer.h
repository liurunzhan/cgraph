#ifndef _CGRAPH_POINTER_H_
#define _CGRAPH_POINTER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"
#include "cgraph_object.h"

typedef struct 
{
  cgraph_boolean_t visited;
  struct cgraph_pointer_t *p1, *p2;
  cgraph_object_t *data;
}cgraph_pointer_t;

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_POINTER_H_ */