#ifndef _CGRAPH_GOBJECT_H_
#define _CGRAPH_GOBJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(_CGRAPH_H_) || defined(_CGRAPH_STRUCT_H_)) && (defined(_CGRAPH_OBJECT_H_) || defined(_CGRAPH_HOBJECT_H_) || defined(_CGRAPH_POBJECT_H_) || defined(_CGRAPH_SOBJECT_H_))
#error <cgraph_hobject.h> can not be included in the same file together with <cgraph_object.h>, <cgraph_hobject.h>, <cgraph_pobject.h> or <cgraph_sobject.h> except in <cgraph.h> and <cgraph_struct.h>
#endif

#include "cgraph_config.h"
#include "cgraph_string.h"

extern CGVTable *CGRAPH_OBJECTS_NAME(gobject)[];
#define CGRAPH_GOBJECT(type, opt) ((CGRAPH_OBJECTS_NAME(hobject)[type])->opt)

#define TYPE_OBJECT
#include "template.h"

typedef struct
{
  CGRAPH_OBJECT_BASE
  cgraph_size_t addr;
  union 
  {
    cgraph_string_t *names;
    cgraph_size_t id;
  }key;
  CGRAPH_OBJECT_ROOT
}cgraph_gobject_t;


#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_GOBJECT_H_ */
