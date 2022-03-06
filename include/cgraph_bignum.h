/**
 * @file cgraph_bignum.h
 * @brief the apis of DATA TYPE cgraph_bignum_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_BIGNUM_H__
#define __CGRAPH_BIGNUM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define CGRAPH_BIGNUM_CBUF_SIZE CGRAPH_CBUF_SIZE5

#include "cgraph_template_off.h"
#define TYPE_BIGNUM
#include "cgraph_template.h"

#define TYPE_WITH_DATA
#define DATA_NAME int8
#define DATA_UNAME uint8
#define DATA_TYPE TYPE_T(DATA_UNAME)
#define DATA_UTYPE TYPE_T(DATA_UNAME)
#define DATA_ID ID_T(UINT8)
#define DATA_BITS CGRAPH_UINT8_BITS
#define DATA_BITS_LOG2 CGRAPH_UINT8_BITS_LOG2
#define DATA_BYTES(x) FUNCTION(DATA_NAME, ubitceil)((x))
#define DATA_END (0)
#define DATA_ZERO (0)
#define DATA_ONE (1)
#define DATA_ONES (1)
#define DATA_MIN (0)
#define DATA_MAX (9)

#define NAME bignum
#define TYPE TYPE_T(NAME)
#define ID ID_T(BIGNUM)
#define BITS (8 * sizeof(TYPE))
#define OUT_FMT "%s"
#define ZERO(x) FUNCTION(NAME, zero)((x))
#define ONE(x) FUNCTION(NAME, one)((x))
#define ONES(x) FUNCTION(NAME, ones)((x))
#define MIN FUNCTION(NAME, min)((x))
#define MAX FUNCTION(NAME, max)((x))

/**
 * @struct cgraph_bignum_t
 * @brief the object of big float number
 */
typedef struct {
  CGRAPH_BASE
  cgraph_bool_t postive;
  cgraph_size_t point;
  CGRAPH_DATA_ROOT
} cgraph_bignum_t;

/** template module */
#include "cgraph_template_cbuf.ht"
#include "cgraph_template_data.ht"

extern cgraph_size_t FUNCTION(NAME, fprintn)(FILE *fp, const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, fprinte)(FILE *fp, const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, snprintn)(cgraph_char_t *cbuf,
                                              const cgraph_size_t size,
                                              const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, snprinte)(cgraph_char_t *cbuf,
                                              const cgraph_size_t size,
                                              const TYPE *cthis);
extern TYPE *FUNCTION(NAME, initc)(TYPE *cthis, const cgraph_char_t *data,
                                   const cgraph_size_t len);

extern TYPE *FUNCTION(NAME, mul10)(TYPE *cthis, const cgraph_size_t exp);
extern TYPE *FUNCTION(NAME, div10)(TYPE *cthis, const cgraph_size_t exp);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_BIGNUM_H__ */
