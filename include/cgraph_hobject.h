#ifndef _CGRAPH_HOBJECT_H_
#define _CGRAPH_HOBJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(_CGRAPH_H_) || defined(_CGRAPH_STRUCT_H_)) && defined(OBJECT)
#error <cgraph_hobject.h> can not be included in the same file together with \
<cgraph_object.h>, \
<cgraph_gobject.h>, \
<cgraph_pobject.h>, \
<cgraph_mobject.h> or \
<cgraph_m3object.h>, \
except in <cgraph.h> and <cgraph_struct.h>
#endif

#include "cgraph_config.h"

extern CGVTable *CGRAPH_OBJECTS_NAME(hobject)[];
#define CGRAPH_HOBJECT(type, opt) ((CGRAPH_OBJECTS_NAME(hobject)[type])->opt)

#define TYPE_HOBJECT
#include "template.h"

typedef struct {
    CGRAPH_OBJECT_BASE
    struct cgraph_hobject_t *next;
    DATA_TYPE *key;
    CGRAPH_OBJECT_ROOT
} cgraph_hobject_t;

#include "object_base.ht"

extern cgraph_type_t FUNCTION(NAME, obj_ktype)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, obj_kaccessiable)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, obj_khashed)(const TYPE *cthis);

extern cgraph_type_t FUNCTION(NAME, obj_vtype)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, obj_vaccessiable)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, obj_vhashed)(const TYPE *cthis);

extern TYPE *FUNCTION(NAME, kaccessible)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, unkaccessible)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, khashed)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, unkhashed)(TYPE *cthis);

extern TYPE *FUNCTION(NAME, vaccessible)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, unvaccessible)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, vhashed)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, unvhashed)(TYPE *cthis);

#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_HOBJECT_H_ */
