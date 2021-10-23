/**
 * @file cgraph_gobject.h
 * @brief the apis of DATA TYPE cgraph_gobject_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_GOBJECT_H__
#define __CGRAPH_GOBJECT_H__

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(__CGRAPH_H__) || defined(__CGRAPH_STRUCT_H__)) && defined(OBJECT)
#error <cgraph_gobject.h> can not be included in the same file together with \
<cgraph_object.h>, \
<cgraph_hobject.h>, \
<cgraph_mobject.h> or \
<cgraph_m3object.h>, \
except in <cgraph.h> and <cgraph_struct.h>
#endif

#include "cgraph_config.h"

extern cgraph_vtable_t *CGRAPH_OBJECTS_NAME(gobject)[];
#define CGRAPH_GOBJECT(type, opt) ((CGRAPH_OBJECTS_NAME(gobject)[type])->opt)

#define TYPE_GOBJECT
#include "cgraph_template.h"

/**
 * @struct cgraph_gobject_t
 * @brief the object of graph object
 */
typedef struct {
  CGRAPH_OBJECT_BASE
  cgraph_size_t hash, index;
  union {
    cgraph_size_t id;
    cgraph_string_t *names;
  } key;
  CGRAPH_OBJECT_ROOT
} cgraph_gobject_t;

/** template module */
#include "cgraph_template_object.ht"

extern cgraph_bool_t FUNCTION(NAME, keyisid)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, directed)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, weighted)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, multiple)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, hyper)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, dynamic)(const TYPE *cthis);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_GOBJECT_H__ */
