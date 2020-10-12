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
  cgraph_size_t point;
  CGRAPH_DATA_BASE
}cgraph_bignum_t;


#include "data_base.ht"

extern TYPE *FUNCTION(NAME, abs)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, format)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z);

extern cgraph_boolean_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y);
extern cgraph_boolean_t FUNCTION(NAME, ne)(const TYPE *x, const TYPE *y);
extern cgraph_boolean_t FUNCTION(NAME, gr)(const TYPE *x, const TYPE *y);
extern cgraph_boolean_t FUNCTION(NAME, ge)(const TYPE *x, const TYPE *y);
extern cgraph_boolean_t FUNCTION(NAME, ls)(const TYPE *x, const TYPE *y);
extern cgraph_boolean_t FUNCTION(NAME, le)(const TYPE *x, const TYPE *y);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_BIGNUM_H_ */
