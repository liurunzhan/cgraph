/**
 * @file cgraph_dframe.h
 * @brief the apis of STRUCTURE TYPE cgraph_dframe_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_DFRAME_H__
#define __CGRAPH_DFRAME_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_DFRAME
#include "cgraph_template.h"

/**
 * @struct cgraph_dframe_t
 * @brief the object of data frame
 */
typedef struct {
  CGRAPH_STRUCTURE_BASE
  cgraph_size_t row, column;
  CGRAPH_STRUCTURE_ROOT
} cgraph_dframe_t;

/** template module */
#include "cgraph_template_struct.ht"

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_DFRAME_H__ */
