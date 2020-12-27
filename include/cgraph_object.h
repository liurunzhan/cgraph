#ifndef _CGRAPH_OBJECT_H_
#define _CGRAPH_OBJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(_CGRAPH_H_) || defined(_CGRAPH_STRUCT_H_)) && (defined(_CGRAPH_HOBJECT_H_) || defined(_CGRAPH_POBJECT_H_) || defined(_CGRAPH_SOBJECT_H_))
#error <cgraph_object.h> can not be included in the same file together with <cgraph_hobject.h>, <cgraph_pobject.h> or <cgraph_sobject.h> except in <cgraph.h> and <cgraph_struct.h>
#endif

#include "cgraph_config.h"

extern CGVTable *CGRAPH_OBJECTS_NAME(object)[];
#define CGRAPH_OBJECT(type, opt) ((CGRAPH_OBJECTS_NAME(object)[type])->opt)

#define TYPE_OBJECT
#include "template.h"

typedef struct 
{
  CGRAPH_OBJECT_BASE
  CGRAPH_OBJECT_ROOT
}cgraph_object_t;

#include "object_base.ht"

#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_OBJECT_H_ */
