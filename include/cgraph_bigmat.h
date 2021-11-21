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

#include "cgraph_template_off.h"
#define TYPE_BIGMAT
#include "cgraph_template.h"

#define NAME bigmat
#define TYPE TYPE_T(NAME)
#define ID ID_T(BIGMAT)
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

/**
 * @struct cgraph_bigmat_t
 * @brief the object of 2-d big matrix
 */
typedef struct {
  CGRAPH_STRUCTURE_BASE
  CGRAPH_MATRIX_INDEXES
  CGRAPH_STRUCTURE_ROOT
} cgraph_bigmat_t;

/** template module */
#include "cgraph_template_matrix.ht"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_BIGMAT_H__ */
