/**
 * @file cgraph_bigint.h
 * @brief the apis of DATA TYPE cgraph_bigint_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_BIGINT_H__
#define __CGRAPH_BIGINT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define CGRAPH_BIGINT_CBUFFER_SIZE CGRAPH_CBUFFER_SIZE5

#define TYPE_BIGINT
#include "cgraph_template.h"

typedef struct {
  CGRAPH_BASE
  cgraph_bool_t postive;
  CGRAPH_DATA_ROOT
} cgraph_bigint_t;

/** template module */
#include "cgraph_template_cbuffer.ht"

#include "cgraph_template_data.ht"

extern cgraph_size_t FUNCTION(NAME, fprintb)(FILE *fp, const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, fprinth)(FILE *fp, const TYPE *cthis);
extern TYPE *FUNCTION(NAME, add1)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, sub1)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, mul2)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, div2)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, fact)(const TYPE *x, TYPE *y);
extern TYPE *FUNCTION(NAME, initc)(TYPE *cthis, cgraph_char_t *cbuffer,
                                   const cgraph_char_t *data,
                                   const cgraph_size_t len);
extern TYPE *FUNCTION(NAME, atoi)(const cgraph_char_t *data);

extern TYPE *FUNCTION(NAME, shl)(TYPE *cthis, const cgraph_size_t bits);
extern TYPE *FUNCTION(NAME, shr)(TYPE *cthis, const cgraph_size_t bits);
extern TYPE *FUNCTION(NAME, swapbit)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, swapbyte)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, swaphfwd)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, swapword)(TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, cntones)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, cntzeros)(const TYPE *cthis);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_BIGINT_H__ */
