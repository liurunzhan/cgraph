#ifndef _CGRAPH_BIGINT_H_
#define _CGRAPH_BIGINT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"
#include "cgraph_string.h"
#include "cgraph_bignum.h"

#define TYPE_BIGINT
#include "templete.h"

typedef struct 
{
  cgraph_boolean_t pos;
  cgraph_size_t size, len;
  DATA_TYPE *root, *data;
}cgraph_bigint_t;

#include "data_templete.h"

extern TYPE *FUNCTION(NAME, abs)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, tonum)(const cgraph_string_t *cthis);
extern TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y);
extern TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y);
extern TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y);
extern TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y);
extern cgraph_string_t *FUNCTION(NAME, tostr)(const TYPE *cthis);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_BIGINT_H_ */
