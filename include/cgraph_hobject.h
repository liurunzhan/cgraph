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

#ifndef __CGRAPH_HOBJECT_H__
#define __CGRAPH_HOBJECT_H__

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(__CGRAPH_H__) || defined(__CGRAPH_STRUCT_H__)) && defined(OBJECT)
#error <cgraph_hobject.h> can not be included in the same file together with \
<cgraph_object.h>, \
<cgraph_gobject.h>, \
<cgraph_mobject.h> or \
<cgraph_m3object.h>, \
except in <cgraph.h> and <cgraph_struct.h>
#endif

#include "cgraph_config.h"

extern cgraph_vtable_t *CGRAPH_OBJECTS_NAME(hobject)[];
#define CGRAPH_HOBJECT(type, opt) ((CGRAPH_OBJECTS_NAME(hobject)[type])->opt)

#define TYPE_HOBJECT
#include "cgraph_template.h"

/**
 * @struct cgraph_hobject_t
 * @brief the object of hash object
 */
typedef struct {
  CGRAPH_OBJECT_BASE
  cgraph_size_t hash, index;
  union {
    cgraph_size_t id;
    DATA_TYPE *value;
  } __TYPE_END(ext);
  CGRAPH_OBJECT_ROOT
} cgraph_hobject_t;

/** template module */
#include "cgraph_template_object.ht"

#define HOBJECT_EXT(x) __TYPE_ELEMENT((x), ext)
#define HOBJECT_INDEX(x) (HOBJECT_EXT(x).index)
#define HOBJECT_VALUE(x) (HOBJECT_EXT(x).value)

extern cgraph_type_t FUNCTION(NAME, ktype)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, iskaccess)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, iskconst)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, iskhash)(const TYPE *cthis);

extern TYPE *FUNCTION(NAME, setkaccess)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, unsetkaccess)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, setkconst)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, unsetkconst)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, setkhash)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, unsetkhash)(TYPE *cthis);

extern cgraph_type_t FUNCTION(NAME, vtype)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isvaccess)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isvconst)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isvhash)(const TYPE *cthis);

extern TYPE *FUNCTION(NAME, setvaccess)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, unsetvaccess)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, setvconst)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, unsetvconst)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, setvhash)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, unsetvhash)(TYPE *cthis);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_HOBJECT_H__ */
