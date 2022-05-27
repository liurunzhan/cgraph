/**
 * @file cgraph_mobject.h
 * @brief the apis of DATA TYPE cgraph_mobject_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_MOBJECT_H__
#define __CGRAPH_MOBJECT_H__

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(__CGRAPH_H__) || defined(__CGRAPH_STRUCT_H__)) && defined(OBJECT)
#error <cgraph_mobject.h> cannot be included in the same file together with \
<cgraph_object.h>, \
<cgraph_hobject.h>, \
<cgraph_gobject.h> or \
<cgraph_m3object.h>, \
except in <cgraph.h> and <cgraph_struct.h>
#endif

#include "cgraph_config.h"

extern cgraph_vtable_t *CGRAPH_OBJECTS_NAME(mobject)[];
#define CGRAPH_MOBJECT(type, opt) ((CGRAPH_OBJECTS_NAME(mobject)[type])->opt)

#include "cgraph_template_off.h"
#define TYPE_MOBJECT
#include "cgraph_template.h"

#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#define NAME mobject
#define TYPE TYPE_T(NAME)
#define ID ID_T(MOBJECT)
#define OUT_FMT CGRAPH_VARADDR_OUT_FMT
#define ZERO NULL

#define OBJECT(type, opt) CGRAPH_MOBJECT(type, opt)

/**
 * @struct cgraph_mobject_t
 * @brief the object used in 2-d matrix
 */
typedef struct {
  CGRAPH_OBJECT_BASE
  CGRAPH_MATRIX_INDEXES
  CGRAPH_OBJECT_ROOT
} cgraph_mobject_t;

/** template module */
#include "cgraph_template_object.ht"

extern cgraph_size_t FUNCTION(NAME, row)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, column)(const TYPE *cthis);

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_H__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_MOBJECT_H__ */
