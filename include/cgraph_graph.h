#ifndef _CGRAPH_GRAPH_H_
#define _CGRAPH_GRAPH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"
#include "cgraph_string.h"

typedef struct 
{
  union 
  {
    cgraph_string_t *names;
    cgraph_size_t id;
  }key;
  cgraph_size_t addr;
  struct cgraph_keyval_t *next;
}cgraph_keyval_t;

typedef struct 
{
  cgraph_keyval_t *dict;
  cgraph_size_t *id;
  cgraph_boolean_t *visited;
  cgraph_string_t **name;
  cgraph_real_t *weight;
  cgraph_size_t *time;
  cgraph_integer_t *color;
  void *next;
}cgraph_detail_t;

typedef struct 
{
  cgraph_detail_t data;
  cgraph_boolean_t key_is_id;
  cgraph_size_t len;
}cgraph_nodes_t;

typedef struct 
{
  cgraph_detail_t data;
  cgraph_boolean_t key_is_id;
  cgraph_size_t len;
}cgraph_edges_t;

typedef struct 
{
  cgraph_boolean_t directed, weighted, hyper, dynamic;
  cgraph_nodes_t *nodes;
  cgraph_edges_t *edges;
  union 
  {
    union 
    {
      cgraph_boolean_t **unweighted;
      cgraph_real_t **weighted;
    }adjmatrix;
    union
    {
      cgraph_size_t **is_id;
      cgraph_string_t ***is_name;
    }edgelist;
  }data;
}cgraph_graph_t;


#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_GRAPH_H_ */
