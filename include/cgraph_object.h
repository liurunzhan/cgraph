/**
 * @file cgraph_object.h
 * @brief the apis of DATA TYPE cgraph_object_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_OBJECT_H__
#define __CGRAPH_OBJECT_H__

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(__CGRAPH_H__) || defined(__CGRAPH_STRUCT_H__)) && defined(OBJECT)
#error <cgraph_object.h> cannot be included in the same file together with \
<cgraph_hobject.h>, \
<cgraph_gobject.h>, \
<cgraph_m3object.h> or \
<cgraph_mobject.h>, \
except in <cgraph.h> and <cgraph_struct.h>
#endif

#include "cgraph_config.h"

extern cgraph_vtable_t *CGRAPH_OBJECTS_NAME(object)[];
#define CGRAPH_OBJECT(type, opt) ((CGRAPH_OBJECTS_NAME(object)[type])->opt)

/** definition of  */
#include "cgraph_template_off.h"
#define TYPE_OBJECT
#include "cgraph_template.h"

#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#define NAME object
#define TYPE TYPE_T(NAME)
#define ID ID_T(OBJECT)
#define OUT_FMT CGRAPH_VARADDR_OUT_FMT
#define ZERO NULL

#define OBJECT(type, opt) CGRAPH_OBJECT(type, opt)

/**
 * @struct cgraph_object_t
 * @brief the object defined in common data structure
 */
typedef struct {
  CGRAPH_OBJECT_BASE
  CGRAPH_OBJECT_ROOT
} cgraph_object_t;

/** template module */
#include "cgraph_template_object.ht"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_OBJECT_H__ */
