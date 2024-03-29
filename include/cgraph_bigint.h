/**
 * @file cgraph_bigint.h
 * @brief the apis of DATA TYPE cgraph_bigint_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_BIGINT_H__
#define __CGRAPH_BIGINT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_BIGINT
#include "cgraph_template.h"

/** data details: if needs another data memory, define Macro TYPE_WITH_DATA */
#define TYPE_WITH_DATA
#define DATA_NAME int8
#define DATA_UNAME uint8
#define DATA_TYPE TYPE_T(DATA_UNAME)
#define DATA_UTYPE TYPE_T(DATA_UNAME)
#define DATA_ID ID_T(UINT8)
#define DATA_BITS CGRAPH_UINT8_BITS
#define DATA_L2BITS CGRAPH_UINT8_L2BITS
#define DATA_BYTES(x) FUNCTION(NAME, ubitceil)((x))
#define DATA_END (0)
#define DATA_ZERO UINT8_C(0)
#define DATA_ONE UINT8_C(1)
#define DATA_ONES CGRAPH_UINT8_MAX
#define DATA_MIN CGRAPH_UINT8_MIN
#define DATA_MAX CGRAPH_UINT8_MAX
#define DATA_MASK CGRAPH_UINT8_MASK
#define DATA_EPSILON CGRAPH_UINT8_EPSILON
#define DATA_LSB CGRAPH_UINT8_LSB
#define DATA_MSB CGRAPH_UINT8_MSB

/** type details: */
#define NAME bigint
#define TYPE TYPE_T(NAME)
#define ID ID_T(BIGINT)
#define BITS (8 * sizeof(TYPE))
#define OUT_FMT "%s"
#define ZERO(x) FUNCTION(NAME, zero)((x))
#define ONE(x) FUNCTION(NAME, one)((x))
#define ONES(x) FUNCTION(NAME, ones)((x))
#define MIN(x) FUNCTION(NAME, min)((x))
#define MAX(x) FUNCTION(NAME, max)((x))

/**
 * @struct cgraph_bigint_t
 * @brief the object of big integer
 */
typedef struct {
  CGRAPH_BASE
  cgraph_bool_t postive;
  CGRAPH_DATA_ROOT
} cgraph_bigint_t;

/** template module */
#define CGRAPH_BIGINT_CBUF_SIZE CGRAPH_CBUF_SIZE5
#include "cgraph_template_cbuf.ht"
#include "cgraph_template_data.ht"

extern cgraph_size_t FUNCTION(NAME, fprintb)(FILE *fp, const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, fprinth)(FILE *fp, const TYPE *cthis);
extern TYPE *FUNCTION(NAME, add1)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, sub1)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, mul2)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, div2)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, fact)(const TYPE *x, TYPE *y);
extern TYPE *FUNCTION(NAME, initc)(TYPE *cthis, cgraph_char_t *cbuf,
                                   const cgraph_char_t *data,
                                   const cgraph_size_t len);
extern TYPE *FUNCTION(NAME, atoi)(const cgraph_char_t *data);

extern TYPE *FUNCTION(NAME, swapbit1)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, swapbit8)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, swapbit16)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, swapbit32)(TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, abitlen)(const TYPE *cthis);

extern cgraph_size_t FUNCTION(NAME, cntones)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, cntzeros)(const TYPE *cthis);

extern TYPE *FUNCTION(NAME, ipv4)(TYPE *cthis, const cgraph_char_t *ipv4);
extern TYPE *FUNCTION(NAME, ipv6)(TYPE *cthis, const cgraph_char_t *ipv6);

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_BIGINT_H__ */
