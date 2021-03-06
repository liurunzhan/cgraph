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

#ifndef __CGRAPH_BIGNUM_H__
#define __CGRAPH_BIGNUM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#ifndef CGRAPH_BIGNUM_BUFFER_SIZE
#define CGRAPH_BIGNUM_BUFFER_SIZE __CGRAPH_BUFFER_SIZE5
#endif

#define TYPE_BIGNUM
#include "cgraph_template.h"

typedef struct {
  CGRAPH_BASE
  cgraph_bool_t postive;
  cgraph_size_t point;
  CGRAPH_DATA_ROOT
} cgraph_bignum_t;

/** template module */
#include "cgraph_template_buffer.ht"
#include "cgraph_template_data.ht"

extern cgraph_size_t FUNCTION(NAME, fprintn)(FILE *fp, const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, fprinte)(FILE *fp, const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, snprintn)(cgraph_char_t *buffer,
                                              const cgraph_size_t size,
                                              const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, snprinte)(cgraph_char_t *buffer,
                                              const cgraph_size_t size,
                                              const TYPE *cthis);
extern TYPE *FUNCTION(NAME, initc)(TYPE *cthis, const cgraph_char_t *data,
                                   const cgraph_size_t len);
extern TYPE *FUNCTION(NAME, initf32)(TYPE *cthis, const cgraph_float32_t data);
extern TYPE *FUNCTION(NAME, initf64)(TYPE *cthis, const cgraph_float64_t data);

extern TYPE *FUNCTION(NAME, mul10)(TYPE *cthis, const cgraph_size_t exp);
extern TYPE *FUNCTION(NAME, div10)(TYPE *cthis, const cgraph_size_t exp);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_BIGNUM_H__ */
