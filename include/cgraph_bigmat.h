/**
 * @file cgraph_bigmat.h
 * @brief the apis of STRUCTURE TYPE cgraph_bigmat_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_BIGMAT_H__
#define __CGRAPH_BIGMAT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_BIGMAT
#include "cgraph_template.h"

typedef struct {
  CGRAPH_STRUCTURE_BASE
  CGRAPH_MATRIX_INDEXES
  CGRAPH_STRUCTURE_ROOT
} cgraph_bigmat_t;

/** template module */
#include "cgraph_template_matrix.ht"

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_BIGMAT_H__ */
