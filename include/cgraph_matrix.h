#ifndef _CGRAPH_MATRIX_H_
#define _CGRAPH_MATRIX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

typedef struct 
{
  cgraph_type_t type;
  cgraph_boolean_t with_hash;
  cgraph_size_t row, column, size, len;
  void *root, *data;
}cgraph_matrix_t;

#define TYPE_MATRIX
#include "templete.h"
#include "struct_templete.h"
#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_MATRIX_H_ */