#ifndef _CGRAPH_BITSET_H_
#define _CGRAPH_BITSET_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_BITSET
#include "templete.h"

typedef struct 
{
  CGRAPH_DATA_BASE
}cgraph_bitset_t;

#define BITSET_GET_BIT(cthis, pos) (((cthis->data[pos / DATA_BITS]) >> (pos % DATA_BITS)) ^ 1)

#include "data_templete.h"

extern TYPE *FUNCTION(NAME, bit)(const TYPE *cthis, const cgraph_size_t pos);
extern TYPE *FUNCTION(NAME, set)(TYPE *cthis, const cgraph_size_t pos);
extern TYPE *FUNCTION(NAME, bits)(const TYPE *cthis, const cgraph_size_t min, const cgraph_size_t max);
extern TYPE *FUNCTION(NAME, sets)(TYPE *cthis, const cgraph_size_t min, const cgraph_size_t max);
extern TYPE *FUNCTION(NAME, clr)(TYPE *cthis, const cgraph_size_t pos);
extern TYPE *FUNCTION(NAME, clrs)(TYPE *cthis, const cgraph_size_t min, const cgraph_size_t max);

extern TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y);
extern TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y);
extern TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y);
extern TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_BITSET_H_ */
