#ifndef _CGRAPH_BIGNUM_H_
#define _CGRAPH_BIGNUM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_BIGNUM
#include "cgraph_template.h"

typedef struct {
  CGRAPH_DATA_BASE
  cgraph_size_t point;
  CGRAPH_DATA_ROOT
} cgraph_bignum_t;

#include "cgraph_template_data.ht"

extern TYPE *FUNCTION(NAME, unit)(TYPE *cthis, const cgraph_size_t size);
extern TYPE *FUNCTION(NAME, unit_inv)(TYPE *cthis, const cgraph_size_t size);

extern cgraph_bool_t FUNCTION(NAME, iszero)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isone)(const TYPE *cthis);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_BIGNUM_H_ */
