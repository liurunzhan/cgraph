#ifndef _CGRAPH_BIGMAT_H_
#define _CGRAPH_BIGMAT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_BIGMAT
#include "templete.h"

typedef struct 
{
  cgraph_size_t row, column;
  CGRAPH_STRUCTURE_BASE
}cgraph_bigmat_t;

#include "struct_base.ht"
#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_BIGMAT_H_ */
