/**
 * @file cgraph_set.h
 * @brief the apis of STRUCTURE TYPE cgraph_set_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_SET_H__
#define __CGRAPH_SET_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"
#include "cgraph_snode.h"

#include "cgraph_template_off.h"
#define TYPE_SET
#include "cgraph_template.h"

#define NAME set
#define TYPE TYPE_T(NAME)
#define ID ID_T(SET)
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

/**
 * @struct cgraph_set_t
 * @brief the object of set
 */
typedef struct {
  CGRAPH_STRUCTURE_BASE
  CGRAPH_STRUCTURE_ROOT
} cgraph_set_t;

/** template module */
#include "cgraph_template_struct.ht"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_SET_H__ */
