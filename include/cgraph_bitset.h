/**
 * @file cgraph_bitset.h
 * @brief the apis of DATA TYPE cgraph_bitset_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_BITSET_H__
#define __CGRAPH_BITSET_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_BITSET
#include "cgraph_template.h"

#define TYPE_WITH_DATA
#define DATA_NAME int8
#define DATA_UNAME uint8
#define DATA_TYPE TYPE_T(DATA_UNAME)
#define DATA_UTYPE TYPE_T(DATA_UNAME)
#define DATA_ID ID_T(UINT8)
#define DATA_BITS CGRAPH_UINT8_BITS
#define DATA_L2BITS CGRAPH_UINT8_L2BITS
#define DATA_BYTES(x) FUNCTION(DATA_NAME, ubitceil)((x))
#define DATA_END (0)
#define DATA_ZERO (0)
#define DATA_ONE (1)
#define DATA_ONES CGRAPH_UINT8_MAX
#define DATA_MIN CGRAPH_UINT8_MIN
#define DATA_MAX CGRAPH_UINT8_MAX
#define DATA_MASK CGRAPH_UINT8_MASK
#define DATA_EPSILON CGRAPH_UINT8_EPSILON
#define DATA_LSB CGRAPH_UINT8_LSB
#define DATA_MSB CGRAPH_UINT8_MSB

#define NAME bitset
#define TYPE TYPE_T(NAME)
#define ID ID_T(BITSET)
#define BITS (8 * sizeof(TYPE))
#define OUT_FMT "%s"
#define ZERO(x) FUNCTION(NAME, zero)((x))
#define ONE(x) FUNCTION(NAME, one)((x))
#define ONES(x) FUNCTION(NAME, ones)((x))
#define MIN(x) FUNCTION(NAME, min)((x))
#define MAX(x) FUNCTION(NAME, max)((x))

/**
 * @struct cgraph_bitset_t
 * @brief the object of bit set
 */
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
  ((((x)->len - 1) << DATA_L2BITS) + BITSET_BITNUM((x)))
#define BITSET_BITNUM_GRHALF(x) BITSET_GRHALF(x)
#define BITSET_BYTE_POSTION(postion) FUNCTION(DATA_NAME, bitfloor)((postion))
#define BITSET_BIT_POSTION(postion) FUNCTION(DATA_NAME, bitmod)((postion))
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
extern cgraph_size_t FUNCTION(NAME, snprintb)(cgraph_char_t *cbuf,
                                              const cgraph_size_t size,
                                              const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, snprinth)(cgraph_char_t *cbuf,
                                              const cgraph_size_t size,
                                              const TYPE *cthis);

extern TYPE *FUNCTION(NAME, updatepos)(TYPE *cthis, const cgraph_size_t pos);
extern TYPE *FUNCTION(NAME, updatenum)(TYPE *cthis, const cgraph_size_t num);

extern TYPE *FUNCTION(NAME, bitcalloc)(const cgraph_size_t len_bits,
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

extern TYPE *FUNCTION(NAME, swapbit)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, swapbyte)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, swaphfwd)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, swapword)(TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, abitlen)(const TYPE *cthis);

extern cgraph_size_t FUNCTION(NAME, cntones)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, cntzeros)(const TYPE *cthis);

extern TYPE *FUNCTION(NAME, and)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, or)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, xor)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, xnor)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, not )(const TYPE *x, TYPE *y);

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_BITSET_H__ */
