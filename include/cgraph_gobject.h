#ifndef _CGRAPH_GOBJECT_H_
#define _CGRAPH_GOBJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(_CGRAPH_H_) || defined(_CGRAPH_STRUCT_H_)) && defined(OBJECT)
#error <cgraph_hobject.h> can not be included in the same file together with \
<cgraph_object.h>, \
<cgraph_hobject.h>, \
<cgraph_pobject.h>, \
<cgraph_mobject.h> or \
<cgraph_m3object.h>, \
except in <cgraph.h> and <cgraph_struct.h>
#endif

#include "cgraph_config.h"

extern CGVTable *CGRAPH_OBJECTS_NAME(gobject)[];
#define CGRAPH_GOBJECT(type, opt) ((CGRAPH_OBJECTS_NAME(gobject)[type])->opt)

#define TYPE_GOBJECT
#include "template.h"

typedef struct {
    CGRAPH_OBJECT_BASE
    cgraph_size_t hash, index;
    union {
        cgraph_string_t *names;
        cgraph_size_t id;
    } key;
    CGRAPH_OBJECT_ROOT
} cgraph_gobject_t;

#include "object_base.ht"

extern cgraph_bool_t FUNCTION(NAME, keyisid)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, directed)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, weighted)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, multiple)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, hyper)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, dynamic)(const TYPE *cthis);

#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_GOBJECT_H_ */
