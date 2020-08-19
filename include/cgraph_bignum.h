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
  CGRAPH_DATA_BASE
  cgraph_size_t point;
}cgraph_bignum_t;


#include "data_templete.h"

extern TYPE *FUNCTION(NAME, abs)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, format)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y);
extern TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y);
extern TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y);
extern TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_BIGNUM_H_ */
