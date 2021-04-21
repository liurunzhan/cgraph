/**
 * @file cgraph_hobject.h
 * @brief the apis of DATA TYPE cgraph_hobject_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef _CGRAPH_HOBJECT_H_
#define _CGRAPH_HOBJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(_CGRAPH_H_) || defined(_CGRAPH_STRUCT_H_)) && defined(OBJECT)
#error <cgraph_hobject.h> can not be included in the same file together with \
<cgraph_object.h>, \
<cgraph_gobject.h>, \
<cgraph_mobject.h> or \
<cgraph_m3object.h>, \
except in <cgraph.h> and <cgraph_struct.h>
#endif

#include "cgraph_config.h"

extern CGVTable *CGRAPH_OBJECTS_NAME(hobject)[];
#define CGRAPH_HOBJECT(type, opt) ((CGRAPH_OBJECTS_NAME(hobject)[type])->opt)

#define TYPE_HOBJECT
#include "cgraph_template.h"

typedef struct {
  CGRAPH_OBJECT_BASE
  cgraph_size_t hash, index;
  union {
    cgraph_size_t id;
    DATA_TYPE *value;
  } __CGRAPH_TYPE_END(ext);
  CGRAPH_OBJECT_ROOT
} cgraph_hobject_t;

/** template module */
#include "cgraph_template_object.ht"

#define HOBJECT_EXT(x) __CGRAPH_TYPE_ELEMENT((x), ext)
#define HOBJECT_INDEX(x) (HOBJECT_EXT(x).index)
#define HOBJECT_VALUE(x) (HOBJECT_EXT(x).value)

extern cgraph_type_t FUNCTION(NAME, obj_ktype)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, obj_kaccessiable)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, obj_khashed)(const TYPE *cthis);

extern cgraph_type_t FUNCTION(NAME, obj_vtype)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, obj_vaccessiable)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, obj_vhashed)(const TYPE *cthis);

extern TYPE *FUNCTION(NAME, ksetaccess)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, unksetaccess)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, khashed)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, unkhashed)(TYPE *cthis);

extern TYPE *FUNCTION(NAME, vsetaccess)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, unvsetaccess)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, vhashed)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, unvhashed)(TYPE *cthis);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_HOBJECT_H_ */
