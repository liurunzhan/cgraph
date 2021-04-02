/**
 * @file cgraph_bignum.h
 * @brief the apis of DATA TYPE cgraph_bignum_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

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
  cgraph_bool_t postive;
  cgraph_size_t point;
  CGRAPH_DATA_ROOT
} cgraph_bignum_t;

#include "cgraph_template_data.ht"

extern TYPE *FUNCTION(NAME, initc)(TYPE *cthis, const cgraph_char_t *data,
                                   const cgraph_size_t len);
extern TYPE *FUNCTION(NAME, unit)(TYPE *cthis, const cgraph_size_t len);
extern TYPE *FUNCTION(NAME, unit_inv)(TYPE *cthis, const cgraph_size_t len);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_BIGNUM_H_ */
