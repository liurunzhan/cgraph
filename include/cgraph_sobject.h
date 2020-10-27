#ifndef _CGRAPH_SOBJECT_H_
#define _CGRAPH_SOBJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_CGRAPH_OBJECT_H_) || defined(_CGRAPH_POBJECT_H_)
#error "\"cgraph_sobject.h\" can not be included together with \"cgraph_object.h\" or \"cgraph_pobject,h\""
#endif

#include "cgraph_config.h"

#define TYPE_SOBJECT
#include "templete.h"

typedef struct 
{
  cgraph_size_t row, column;
  CGRAPH_OBJECT_BASE
}cgraph_sobject_t;

#include "data_base.ht"

extern void *FUNCTION(NAME, data)(void *cthis);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_SOBJECT_H_ */
