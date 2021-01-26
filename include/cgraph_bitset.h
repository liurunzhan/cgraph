#ifndef _CGRAPH_BITSET_H_
#define _CGRAPH_BITSET_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_BITSET
#include "template.h"

typedef struct {
    CGRAPH_DATA_BASE
    CGRAPH_DATA_ROOT
} cgraph_bitset_t;

#define BITSET_BYTE_POSTION(postion) ((postion) / DATA_BITS)
#define BITSET_BIT_POSTION(postion)  ((postion) % DATA_BITS)
#define BITSET_GET_BIT(cthis, postion)                                         \
    ((((cthis)->data[BITSET_BYTE_POSTION(postion)]) >>                         \
      BITSET_BIT_POSTION(postion)) ^                                           \
     0x1)

#include "data_base.ht"

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

extern TYPE *FUNCTION(NAME, and)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, or)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, xor)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, xnor)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, not )(const TYPE *x, TYPE *y);

#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_BITSET_H_ */
