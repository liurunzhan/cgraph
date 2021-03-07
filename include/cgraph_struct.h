#ifndef _CGRAPH_STRUCT_H_
#define _CGRAPH_STRUCT_H_

#ifdef __cplusplus
extern "C" {
#endif

/** vector type: */
#include "cgraph_vector.h"

/**
  2D and 3D matrix types:
  --> matrix
  --> bigmat
  --> spamat
  --> matrix3d
  --> bigmat3d
  --> spamat3d
*/
#include "cgraph_bigmat.h"
#include "cgraph_matrix.h"
#include "cgraph_spamat.h"

#include "cgraph_bigmat3d.h"
#include "cgraph_matrix3d.h"
#include "cgraph_spamat3d.h"

/**
  structure with multiple index:
  --> set
  --> directory
  --> data frame
*/
#include "cgraph_dframe.h"
#include "cgraph_dict.h"
#include "cgraph_set.h"

/**
  structure with node pointers:
  --> queue
  --> stack
  --> list
  --> tree
*/
#include "cgraph_list.h"
#include "cgraph_queue.h"
#include "cgraph_stack.h"
#include "cgraph_tree.h"

/**
  multiple structure:
  --> graph
*/
#include "cgraph_graph.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_STRUCT_H_ */
