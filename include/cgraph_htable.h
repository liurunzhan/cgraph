#ifndef _CGRAPH_HTABLE_H_
#define _CGRAPH_HTABLE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

typedef struct
{
  cgraph_boolean_t visited;
  const cgraph_type_t ktype;
  cgraph_type_t vtype;
  const void *key;
  void *data;
  struct cgraph_hobject_t *next; 
} cgraph_hobject_t;

typedef struct 
{
  cgraph_size_t len, size;
  cgraph_hobject_t *table;
}cgraph_htable_t;

#define TYPE_HTABLE
#include "templete.h"
#include "struct_templete.h"
#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_HTABLE_H_ */