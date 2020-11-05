#ifndef _CGRAPH_POBJECT_H_
#define _CGRAPH_POBJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(_CGRAPH_H_) || defined(_CGRAPH_STRUCT_H_)) && (defined(_CGRAPH_OBJECT_H_) || defined(_CGRAPH_HOBJECT_H_) || defined(_CGRAPH_SOBJECT_H_))
#error <cgraph_pobject.h> can not be included in the same file together with <cgraph_object.h>, <cgraph_hobject.h> or <cgraph_sobject.h> except in <cgraph.h> and <cgraph_struct.h>
#endif

#include "cgraph_config.h"

extern CGVTable *CGRAPH_OBJECTS_NAME(pobject)[];
#define CGRAPH_POBJECT(type, opt) ((CGRAPH_OBJECTS_NAME(pobject)[type])->opt)

#define TYPE_POBJECT
#include "templete.h"

typedef struct 
{
  struct cgraph_pobject_t *s1, *s2;
  CGRAPH_OBJECT_BASE
}cgraph_pobject_t;

#include "data_base.ht"

extern void *FUNCTION(NAME, data)(void *cthis);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_POBJECT_H_ */
