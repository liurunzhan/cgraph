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
  cgraph_size_t len, size;
  DATA_TYPE *data;
}cgraph_bitset_t;

#define BITSET_GET_BIT(cthis, pos) (((cthis->data[pos / DATA_BITS]) >> (pos % DATA_BITS)) ^ 1)

#include "data_templete.h"

extern void *FUNCTION(NAME, bit)(const void *cthis, const cgraph_size_t pos);
extern void *FUNCTION(NAME, set)(const void *cthis, const cgraph_size_t pos);
extern void *FUNCTION(NAME, bits)(const void *cthis, const cgraph_size_t min, const cgraph_size_t max);
extern void *FUNCTION(NAME, sets)(const void *cthis, const cgraph_size_t min, const cgraph_size_t max);
extern void *FUNCTION(NAME, clr)(const void *cthis, const cgraph_size_t pos);
extern void *FUNCTION(NAME, clrs)(const void *cthis, const cgraph_size_t min, const cgraph_size_t max);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_BITSET_H_ */