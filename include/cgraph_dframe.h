#ifndef _CGRAPH_DFRAME_H_
#define _CGRAPH_DFRAME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

typedef struct 
{
  cgraph_size_t row, column, size, len;
  cgraph_type_t type;
  cgraph_boolean_t with_hash;
  cgraph_boolean_t *visited;
  void **data;
}cgraph_dframe_t;

#define TYPE_DFRAME
#include "templete.h"
#include "struct_templete.h"
#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_DFRAME_H_ */
