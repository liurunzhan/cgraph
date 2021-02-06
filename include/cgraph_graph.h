#ifndef _CGRAPH_GRAPH_H_
#define _CGRAPH_GRAPH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"
#include "cgraph_string.h"

typedef struct {
    struct cgraph_keyval_t *next;
    cgraph_size_t index;
    union {
        cgraph_string_t *names;
        cgraph_size_t id;
    } __CGRAPH_TYPE_END(key);
} cgraph_keyval_t;

typedef struct {
    cgraph_keyval_t *dict;
    cgraph_size_t *id;
    cgraph_bool_t *visited;
    cgraph_string_t **name;
    cgraph_float64_t *weight;
    cgraph_size_t *time;
    cgraph_int_t *color;
    void *next;
} cgraph_detail_t;

typedef struct {
    cgraph_detail_t data;
    cgraph_bool_t key_is_id;
    cgraph_size_t len;
} cgraph_nodes_t;

typedef struct {
    cgraph_detail_t data;
    cgraph_bool_t key_is_id;
    cgraph_size_t len;
} cgraph_edges_t;

typedef struct {
    cgraph_bool_t directed, weighted, hyper, dynamic;
    cgraph_nodes_t *nodes;
    cgraph_edges_t *edges;
    union {
        union {
            cgraph_bool_t **unweighted_adjmatrix;
            cgraph_float64_t **weighted_adjmatrix;
        } __CGRAPH_TYPE_END(adjmatrix);
        union {
            cgraph_size_t **id_edgelist;
            cgraph_string_t ***name_edgelist;
        } __CGRAPH_TYPE_END(edgelist);
    } __CGRAPH_TYPE_END(data);
} cgraph_graph_t;

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_GRAPH_H_ */
