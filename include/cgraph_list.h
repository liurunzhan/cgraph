#ifndef _CGRAPH_LIST_H_
#define _CGRAPH_LIST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"
#include "cgraph_pobject.h"

#define TYPE_LIST
#include "templete.h"

typedef struct 
{
  cgraph_size_t size, len;
  cgraph_pobject_t *header, *tail;
  cgraph_pobject_t *root, *data;
}cgraph_list_t;

#include "struct_base.ht"
#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_LIST_H_ */
