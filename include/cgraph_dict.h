#ifndef _CGRAPH_DICT_H_
#define _CGRAPH_DICT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_DICT
#include "templete.h"

typedef struct
{
  cgraph_boolean_t visited;
  const cgraph_type_t ktype;
  cgraph_type_t vtype;
  const void *key;
  void *data;
  struct cgraph_dobject_t *next; 
} cgraph_dobject_t;

typedef struct 
{
  cgraph_size_t size, len;
  cgraph_dobject_t *root, *table;
}cgraph_dict_t;

#include "struct_base.ht"
#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_DICT_H_ */
