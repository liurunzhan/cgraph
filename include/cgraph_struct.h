/**
 * @file cgraph_struct.h
 * @brief the apis of structure types in cgraph
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_STRUCT_H__
#define __CGRAPH_STRUCT_H__

#ifdef __cplusplus
extern "C" {
#endif

/** used to clear common-defined macro variables, except included only */
#ifndef __CGRAPH_MACRO_CFLAG__
#define __CGRAPH_MACRO_CFLAG__
#endif

/** vector type: */
#include "cgraph_vector.h"

/**
 * 2D and 3D matrix types:
 * --> matrix
 * --> bigmat
 * --> spamat
 * --> matrix3d
 * --> bigmat3d
 * --> spamat3d
 */
#include "cgraph_bigmat.h"
#include "cgraph_matrix.h"
#include "cgraph_spamat.h"

#include "cgraph_bigmat3d.h"
#include "cgraph_matrix3d.h"
#include "cgraph_spamat3d.h"

/**
 * structure with multiple index:
 * --> set
 * --> directory
 * --> data frame
 */
#include "cgraph_dframe.h"
#include "cgraph_dict.h"
#include "cgraph_set.h"

/**
 * structure with node pointers:
 * --> queue
 * --> stack
 * --> list
 * --> tree
 */
#include "cgraph_list.h"
#include "cgraph_queue.h"
#include "cgraph_stack.h"
#include "cgraph_tree.h"

/**
 * multiple structure:
 * --> graph
 */
#include "cgraph_graph.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_STRUCT_H__ */
