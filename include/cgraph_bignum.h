#ifndef _CGRAPH_BIGNUM_H_
#define _CGRAPH_BIGNUM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_BIGNUM
#include "templete.h"

typedef struct 
{
  cgraph_size_t len, size, point;
  DATA_TYPE *data;
}cgraph_bignum_t;


#include "data_templete.h"
#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_BIGNUM_H_ */