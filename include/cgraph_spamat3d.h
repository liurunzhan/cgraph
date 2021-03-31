/**
 * @file cgraph_spamat3d.h
 * @brief the apis of STRUCTURE TYPE cgraph_spamat3d_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef _CGRAPH_SPAMAT3D_H_
#define _CGRAPH_SPAMAT3D_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"
#include "cgraph_m3object.h"

#define TYPE_SPAMAT3D
#include "cgraph_template.h"

typedef struct {
  CGRAPH_STRUCTURE_BASE
  CGRAPH_MATRIX3D_INDEXES
  CGRAPH_STRUCTURE_ROOT
} cgraph_spamat3d_t;

#include "cgraph_template_matrix3d.ht"

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_SPAMAT3D_H_ */
