/**
 * @file cgraph_spamat3d.h
 * @brief the apis of STRUCTURE TYPE cgraph_spamat3d_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_SPAMAT3D_H__
#define __CGRAPH_SPAMAT3D_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_SPAMAT3D
#include "cgraph_template.h"

#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#define NAME spamat3d
#define TYPE TYPE_T(NAME)
#define ID ID_T(SPAMAT3D)
#define ZERO NULL

/**
 * @struct cgraph_spamat3d_t
 * @brief the object of 3-d matrix
 */
typedef struct {
  CGRAPH_STRUCTURE_BASE
  CGRAPH_MATRIX3D_INDEXES
  CGRAPH_STRUCTURE_ROOT
} cgraph_spamat3d_t;

/** template module */
#include "cgraph_template_matrix3d.ht"

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_SPAMAT3D_H__ */
