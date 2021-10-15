/**
 * @file cgraph_bitset.h
 * @brief the apis of DATA TYPE cgraph_bitset_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_BITSET_H__
#define __CGRAPH_BITSET_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_BITSET
#include "cgraph_template.h"

typedef struct {
  CGRAPH_BASE
  struct {
    cgraph_uint32_t pos : 3;
    cgraph_uint32_t : 5;
    cgraph_uint32_t num : 4;
    cgraph_uint32_t : 4;
    cgraph_uint32_t half : 4;
    cgraph_uint32_t : 4;
    cgraph_uint32_t : 7;
    cgraph_uint32_t grhalf : 1;
  } firstbyte;
  CGRAPH_DATA_ROOT
} cgraph_bitset_t;

#define BITSET_BIT(x) ((x)->firstbyte)
#define BITSET_BITNUM(x) (BITSET_BIT(x).num)
#define BITSET_BITPOS(x) (BITSET_BIT(x).pos)
#define BITSET_HALF(x) (BITSET_BIT(x).half)
#define BITSET_GRHALF(x) (BITSET_BIT(x).grhalf)
#define BITSET_BITS_NUM(x)                                                     \
  ((((x)->len - 1) << DATA_BITS_LOG2) + BITSET_BITNUM((x)))
#define BITSET_BITNUM_GRHALF(x) BITSET_GRHALF(x)
#define BITSET_BYTE_POSTION(postion) FUNCTION(DATA_NAME, bitsfloor)((postion))
#define BITSET_BIT_POSTION(postion) FUNCTION(DATA_NAME, bitsmod)((postion))
#define BITSET_POS2POS(x, bits) CGRAPH_POS((x), (bits))
#define BITSET_POS2NUM(x) ((0 == (x)) ? DATA_BITS : (x))
#define BITSET_GET_BIT(x, postion)                                             \
  ((((x)->data[BITSET_BYTE_POSTION(postion)]) >>                               \
    BITSET_BIT_POSTION(postion)) ^                                             \
   0x1)

/** template module */
#include "cgraph_template_data.ht"

extern cgraph_size_t FUNCTION(NAME, fprintb)(FILE *fp, const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, fprinth)(FILE *fp, const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, snprintb)(cgraph_char_t *cbuffer,
                                              const cgraph_size_t size,
                                              const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, snprinth)(cgraph_char_t *cbuffer,
                                              const cgraph_size_t size,
                                              const TYPE *cthis);

extern TYPE *FUNCTION(NAME, updatepos)(TYPE *cthis, const cgraph_size_t pos);
extern TYPE *FUNCTION(NAME, updatenum)(TYPE *cthis, const cgraph_size_t num);

extern TYPE *FUNCTION(NAME, bitscalloc)(const cgraph_size_t len_bits,
                                        const cgraph_size_t size_bits);
extern DATA_TYPE FUNCTION(NAME, bit)(const TYPE *cthis,
                                     const cgraph_size_t postion);
extern TYPE *FUNCTION(NAME, set)(TYPE *cthis, const cgraph_size_t postion);
extern TYPE *FUNCTION(NAME, bits)(const TYPE *cthis, const cgraph_size_t min,
                                  const cgraph_size_t max);
extern TYPE *FUNCTION(NAME, sets)(TYPE *cthis, const cgraph_size_t min,
                                  const cgraph_size_t max);
extern TYPE *FUNCTION(NAME, clr)(TYPE *cthis, const cgraph_size_t pos);
extern TYPE *FUNCTION(NAME, clrs)(TYPE *cthis, const cgraph_size_t min,
                                  const cgraph_size_t max);
extern TYPE *FUNCTION(NAME, shl)(TYPE *cthis, const cgraph_size_t bits);
extern TYPE *FUNCTION(NAME, shr)(TYPE *cthis, const cgraph_size_t bits);
extern TYPE *FUNCTION(NAME, swapbit)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, swapbyte)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, swaphfwd)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, swapword)(TYPE *cthis);

extern TYPE *FUNCTION(NAME, and)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, or)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, xor)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, xnor)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, not )(const TYPE *x, TYPE *y);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_BITSET_H__ */
