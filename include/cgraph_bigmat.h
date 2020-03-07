#ifndef _CGRAPH_BIGMAT_H_
#define _CGRAPH_BIGMAT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

typedef struct 
{
  cgraph_size_t row, column, len, size;
  cgraph_type_t type;
  cgraph_boolean_t with_hash;
  void **data;
}cgraph_bigmat_t;

#define TYPE_BIGMAT
#include "templete.h"
#include "struct_templete.h"
#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_BIGMAT_H_ */