#ifndef _CGRAPH_LIST_H_
#define _CGRAPH_LIST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

typedef struct 
{
  cgraph_boolean_t visited;
  const cgraph_type_t type;
  struct cgraph_lobject_t *p1, *p2;
  void *data;
}cgraph_lobject_t;

typedef struct 
{
  cgraph_size_t len, size;
  cgraph_lobject_t *header, *tail;
  cgraph_boolean_t with_hash;
  cgraph_lobject_t *list;
}cgraph_list_t;

#define TYPE_LIST
#include "templete.h"
#include "struct_templete.h"
#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_LIST_H_ */