#ifndef _CGRAPH_TREE_H_
#define _CGRAPH_TREE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"
#include "cgraph_pobject.h"

#define TYPE_TREE
#include "template.h"

typedef struct 
{
  CGRAPH_STRUCTURE_BASE
  cgraph_bool_t with_hash;
  CGRAPH_STRUCTURE_ROOT
}cgraph_tree_t;

#include "struct_base.ht"
#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_TREE_H_ */
