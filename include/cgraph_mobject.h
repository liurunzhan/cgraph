#ifndef _CGRAPH_MOBJECT_H_
#define _CGRAPH_MOBJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(_CGRAPH_H_) || defined(_CGRAPH_STRUCT_H_)) && defined(OBJECT)
#error <cgraph_mobject.h> can not be included in the same file together with \
<cgraph_object.h>, \
<cgraph_hobject.h>, \
<cgraph_gobject.h>, \
<cgraph_m3object.h> or \
<cgraph_pobject.h>, \
except in <cgraph.h> and <cgraph_struct.h>
#endif

#include "cgraph_config.h"

extern CGVTable *CGRAPH_OBJECTS_NAME(mobject)[];
#define CGRAPH_MOBJECT(type, opt) ((CGRAPH_OBJECTS_NAME(mobject)[type])->opt)

#define TYPE_MOBJECT
#include "template.h"

typedef struct {
    CGRAPH_OBJECT_BASE
    cgraph_size_t row, column;
    CGRAPH_OBJECT_ROOT
} cgraph_mobject_t;

#include "object_base.ht"
#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_MOBJECT_H_ */
