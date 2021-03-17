#ifndef _CGRAPH_OBJECT_H_
#define _CGRAPH_OBJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(_CGRAPH_H_) || defined(_CGRAPH_STRUCT_H_)) && defined(OBJECT)
#error <cgraph_object.h> can not be included in the same file together with \
<cgraph_hobject.h>, \
<cgraph_gobject.h>, \
<cgraph_m3object.h> \
<cgraph_mobject.h> \
<cgraph_pobject.h>, \
except in <cgraph.h> and <cgraph_struct.h>
#endif

#include "cgraph_config.h"

extern CGVTable *CGRAPH_OBJECTS_NAME(object)[];
#define CGRAPH_OBJECT(type, opt) ((CGRAPH_OBJECTS_NAME(object)[type])->opt)

#define TYPE_OBJECT
#include "cgraph_template.h"

typedef struct {
  CGRAPH_OBJECT_BASE
  CGRAPH_OBJECT_ROOT
} cgraph_object_t;

#include "cgraph_template_object.ht"
#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_OBJECT_H_ */
