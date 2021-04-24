/**
 * @file cgraph_tree.h
 * @brief the apis of STRUCTURE TYPE cgraph_tree_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef _CGRAPH_TREE_H_
#define _CGRAPH_TREE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"
#include "cgraph_snode.h"

#define TYPE_TREE
#include "cgraph_template.h"

typedef struct {
  CGRAPH_STRUCTURE_BASE
  cgraph_bool_t with_hash;
  CGRAPH_STRUCTURE_ROOT
} cgraph_tree_t;

/** template module */
#include "cgraph_template_struct.ht"

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_TREE_H_ */
