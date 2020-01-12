#ifndef _CGRAPH_LIST_H_
#define _CGRAPH_LIST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"
#include "cgraph_pointer.h"

typedef struct 
{
  cgraph_size_t len, size;
  cgraph_object_t *header, *tail;
  cgraph_object_t *data;
}cgraph_list_t;

#define TYPE_LIST
#include "templete.h"
#include "struct_templete.h"
#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_LIST_H_ */