#ifndef _CGRAPH_BIGINT_H_
#define _CGRAPH_BIGINT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_BIGINT
#include "templete.h"

typedef struct 
{
  cgraph_size_t len, size;
  cgraph_boolean_t pos;
  DATA_TYPE *data;
}cgraph_bigint_t;

#include "data_templete.h"
#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_BIGINT_H_ */