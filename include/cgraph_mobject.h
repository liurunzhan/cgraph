/**
 * @file cgraph_mobject.h
 * @brief the apis of DATA TYPE cgraph_mobject_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

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
#include "cgraph_template.h"

typedef struct {
  CGRAPH_OBJECT_BASE
  CGRAPH_MATRIX_INDEXES
  CGRAPH_OBJECT_ROOT
} cgraph_mobject_t;

/** template module */
#include "cgraph_template_object.ht"

extern cgraph_size_t FUNCTION(NAME, row)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, column)(const TYPE *cthis);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_MOBJECT_H_ */
