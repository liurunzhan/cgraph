#ifndef _CGRAPH_BIGNUM_H_
#define _CGRAPH_BIGNUM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_BIGNUM
#include "template.h"

typedef struct {
  CGRAPH_DATA_BASE
  cgraph_size_t point;
  CGRAPH_DATA_ROOT
} cgraph_bignum_t;

#include "data_base.ht"

extern TYPE *FUNCTION(NAME, unit)(const cgraph_size_t size);
extern TYPE *FUNCTION(NAME, unit_inv)(const cgraph_size_t size);
extern TYPE *FUNCTION(NAME, zero)(const cgraph_size_t size);

#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_BIGNUM_H_ */
