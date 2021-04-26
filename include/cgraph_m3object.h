/**
 * @file cgraph_m3object.h
 * @brief the apis of DATA TYPE cgraph_m3object_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_M3OBJECT_H__
#define __CGRAPH_M3OBJECT_H__

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(__CGRAPH_H__) || defined(__CGRAPH_STRUCT_H__)) && defined(OBJECT)
#error <cgraph_m3object.h> can not be included in the same file together with \
<cgraph_object.h>, \
<cgraph_hobject.h>, \
<cgraph_gobject.h> or \
<cgraph_mobject.h>, \
except in <cgraph.h> and <cgraph_struct.h>
#endif

#include "cgraph_config.h"

extern CGVTable *CGRAPH_OBJECTS_NAME(m3object)[];
#define CGRAPH_M3OBJECT(type, opt) ((CGRAPH_OBJECTS_NAME(m3object)[type])->opt)

#define TYPE_M3OBJECT
#include "cgraph_template.h"

typedef struct {
  CGRAPH_OBJECT_BASE
  CGRAPH_MATRIX3D_INDEXES
  CGRAPH_OBJECT_ROOT
} cgraph_m3object_t;

/** template module */
#include "cgraph_template_object.ht"

extern cgraph_size_t FUNCTION(NAME, index_i)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, index_j)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, index_k)(const TYPE *cthis);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_M3OBJECT_H__ */
