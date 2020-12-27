#ifndef _CGRAPH_STRUCT_H_
#define _CGRAPH_STRUCT_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
  structure with integer index:
  --> vector
  --> matrix
  --> bigmat
*/
#include "cgraph_vector.h"
#include "cgraph_matrix.h"
#include "cgraph_bigmat.h"

/*
  structure with multiple index:
  --> set
  --> directory
  --> data frame
*/
#include "cgraph_set.h"
#include "cgraph_dict.h"
#include "cgraph_dframe.h"

/*
  structure with node pointers:
  --> queue
  --> stack
  --> list
  --> tree
*/
#include "cgraph_queue.h"
#include "cgraph_stack.h"
#include "cgraph_list.h"
#include "cgraph_tree.h"

/*
  multiple structure:
  --> graph
*/
#include "cgraph_graph.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_STRUCT_H_ */
