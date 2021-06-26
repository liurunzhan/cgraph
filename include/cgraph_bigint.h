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

#ifndef CGRAPH_BIGINT_BUFFER_SIZE
#define CGRAPH_BIGINT_BUFFER_SIZE __CGRAPH_BUFFER_SIZE5
#endif

#define TYPE_BIGINT
#include "cgraph_template.h"

typedef struct {
  CGRAPH_BASE
  cgraph_bool_t postive;
  CGRAPH_DATA_ROOT
} cgraph_bigint_t;

/** template module */
#include "cgraph_template_buffer.ht"
#include "cgraph_template_data.ht"

extern TYPE *FUNCTION(NAME, fact)(const TYPE *x, TYPE *y);
extern TYPE *FUNCTION(NAME, initc)(TYPE *cthis, cgraph_char_t *buffer,
                                   const cgraph_size_t size,
                                   const cgraph_char_t *data);
extern TYPE *FUNCTION(NAME, atoi)(const cgraph_char_t *data);

extern TYPE *FUNCTION(NAME, shl)(TYPE *cthis, const cgraph_size_t bits);
extern TYPE *FUNCTION(NAME, shr)(TYPE *cthis, const cgraph_size_t bits);
extern TYPE *FUNCTION(NAME, swapbit)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, swapbyte)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, swaphfwd)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, swapword)(TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, cntones)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, cntzeros)(const TYPE *cthis);

extern TYPE *FUNCTION(NAME, mul2)(TYPE *cthis, const cgraph_size_t exp);
extern TYPE *FUNCTION(NAME, div2)(TYPE *cthis, const cgraph_size_t exp);
extern TYPE *FUNCTION(NAME, mul10)(TYPE *cthis, const cgraph_size_t exp);
extern TYPE *FUNCTION(NAME, div10)(TYPE *cthis, const cgraph_size_t exp);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_BIGINT_H__ */
