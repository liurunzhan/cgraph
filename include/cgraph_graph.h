#ifndef _CGRAPH_GRAPH_H_
#define _CGRAPH_GRAPH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"
#include "cgraph_string.h"

typedef struct 
{
  cgraph_integer_t id, date;
  cgraph_string_t *name;
  cgraph_real_t weight;
  cgraph_boolean_t visited;
}cgraph_detail_t;

typedef struct 
{
  cgraph_size_t len;
  cgraph_detail_t *data;
}cgraph_node_t;

typedef struct 
{
  cgraph_size_t len;
  cgraph_detail_t *data;
  cgraph_node_t *nodes;
}cgraph_edge_t;

typedef struct 
{
  cgraph_type_t type;
  cgraph_node_t *nodes;
  cgraph_edge_t *edges;
}cgraph_graph_t;


#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_GRAPH_H_ */