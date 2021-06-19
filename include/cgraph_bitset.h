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
  cgraph_size_t bits_num;
  CGRAPH_DATA_ROOT
} cgraph_bitset_t;

#define BITSET_BITS_NUM(x) ((0 == (x)->bits_num) ? 8 : (x)->bits_num)
#define BITSET_BITS_NUM_TOHALF(x) (BITSET_BITS_NUM(x) - 4)
#define BITSET_BITS_NUM_GRHALF(x) ((0 == (x)->bits_num) || (4 < (x)->bits_num))
#define BITSET_BITS_STPOS(x)                                                   \
  ((0 == (x)->bits_num) ? 0 : DATA_BITS - (x)->bits_num)
#define BITSET_DATA(x) ((x)->data)
#define BITSET_BYTE_POSTION(postion) ((postion) >> DATA_BITS_LOG2)
#define BITSET_BIT_POSTION(postion) ((postion)&DATA_EPSILON)
#define BITSET_GET_BIT(cthis, postion)                                         \
  ((((cthis)->data[BITSET_BYTE_POSTION(postion)]) >>                           \
    BITSET_BIT_POSTION(postion)) ^                                             \
   0x1)

/** template module */
#include "cgraph_template_data.ht"

extern cgraph_size_t FUNCTION(NAME, fprintb)(FILE *fp, const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, fprinth)(FILE *fp, const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, snprintb)(cgraph_char_t *buffer,
                                              const cgraph_size_t size,
                                              const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, snprinth)(cgraph_char_t *buffer,
                                              const cgraph_size_t size,
                                              const TYPE *cthis);

extern TYPE *FUNCTION(NAME, bit)(const TYPE *cthis,
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
