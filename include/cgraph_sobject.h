#ifndef _CGRAPH_SOBJECT_H_
#define _CGRAPH_SOBJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(_CGRAPH_H_) || defined(_CGRAPH_STRUCT_H_)) &&       \
    (defined(_CGRAPH_OBJECT_H_) || defined(_CGRAPH_HOBJECT_H_) || \
     defined(_CGRAPH_GOBJECT_H_) || defined(_CGRAPH_POBJECT_H_))
#error <cgraph_sobject.h> can not be included in the same file together with <cgraph_object.h>, <cgraph_hobject.h>, <cgraph_gobject.h> or <cgraph_pobject.h> except in <cgraph.h> and <cgraph_struct.h>
#endif

#include "cgraph_config.h"

extern CGVTable *CGRAPH_OBJECTS_NAME(sobject)[];
#define CGRAPH_SOBJECT(type, opt) ((CGRAPH_OBJECTS_NAME(sobject)[type])->opt)

#define TYPE_SOBJECT
#include "template.h"

typedef struct {
    CGRAPH_OBJECT_BASE
    cgraph_size_t row, column;
    CGRAPH_OBJECT_ROOT
} cgraph_sobject_t;

#include "object_base.ht"
#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_SOBJECT_H_ */
