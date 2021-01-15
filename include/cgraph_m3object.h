#ifndef _CGRAPH_M3OBJECT_H_
#define _CGRAPH_M3OBJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(_CGRAPH_H_) || defined(_CGRAPH_STRUCT_H_)) && defined(OBJECT)
#error <cgraph_m3object.h> can not be included in the same file together with \
<cgraph_object.h>, \
<cgraph_hobject.h>, \
<cgraph_gobject.h>, \
<cgraph_mobject.h> or \
<cgraph_pobject.h>, \
except in <cgraph.h> and <cgraph_struct.h>
#endif

#include "cgraph_config.h"

extern CGVTable *CGRAPH_OBJECTS_NAME(m3object)[];
#define CGRAPH_M3OBJECT(type, opt) ((CGRAPH_OBJECTS_NAME(m3object)[type])->opt)

#define TYPE_M3OBJECT
#include "template.h"

typedef struct {
    CGRAPH_OBJECT_BASE
    CGRAPH_MATRIX3D_INDEXES
    CGRAPH_OBJECT_ROOT
} cgraph_m3object_t;

#include "object_base.ht"
#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_M3OBJECT_H_ */
