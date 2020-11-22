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
  CGRAPH_STRUCTURE_BASE
  cgraph_pobject_t *header, *tail;
  CGRAPH_STRUCTURE_ROOT
}cgraph_list_t;

#include "struct_base.ht"
#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_LIST_H_ */
