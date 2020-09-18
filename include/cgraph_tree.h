#ifndef _CGRAPH_TREE_H_
#define _CGRAPH_TREE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_TREE
#include "templete.h"

typedef struct 
{
  cgraph_boolean_t visited;
  const cgraph_type_t type;
  cgraph_size_t num_of_child;
  struct cgraph_tobject_t **child;
  void *data;
}cgraph_tobject_t;

typedef struct 
{
  cgraph_size_t len, size;
  cgraph_boolean_t with_hash;
  cgraph_tobject_t *root;
}cgraph_tree_t;

#define TYPE_TREE
#include "templete.h"
#include "struct_base.ht"
#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_TREE_H_ */
