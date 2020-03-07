#include "cgraph_bitset.h"
#include "cgraph_memory.h"

#define TYPE_BITSET
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  
  return 0;
}

void *FUNCTION(NAME, bit)(const void *cthis, const cgraph_size_t pos)
{
  TYPE *new_cthis = (TYPE *)cthis;
  TYPE *res = FUNCTION(NAME, calloc)(DATA_ID, 1);
  if(NULL != res)
  {
    res->data[0] = BITSET_GET_BIT(new_cthis, pos);
    res->len = 1;
  }

  return res;
}

void *FUNCTION(NAME, set)(const void *cthis, const cgraph_size_t pos)
{
  TYPE *new_cthis = (TYPE *)cthis;
  cgraph_size_t i = pos / DATA_BITS, j = pos % DATA_BITS;
  DATA_TYPE tmp = new_cthis->data[i], left_bits = ((tmp >> (j+1)) << (j+1)), right_bits = ((j == 0) ? 0 : (tmp ^ (~((DATA_ONES >> j) << j))));
  new_cthis->data[i] = left_bits + right_bits + 1 << j;

  return new_cthis;
}

void *FUNCTION(NAME, bits)(const void *cthis, const cgraph_size_t min, const cgraph_size_t max)
{
  TYPE *new_cthis = (TYPE *)cthis;

}

void *FUNCTION(NAME, sets)(const void *cthis, const cgraph_size_t min, const cgraph_size_t max)
{

}

void *FUNCTION(NAME, clr)(const void *cthis, const cgraph_size_t pos)
{
  TYPE *new_cthis = (TYPE *)cthis;
  cgraph_size_t i = pos / DATA_BITS, j = pos % DATA_BITS;
  DATA_TYPE tmp = new_cthis->data[i], left_bits = ((tmp >> (j+1)) << (j+1)), right_bits = ((j == 0) ? 0 : (tmp ^ (~((DATA_ONES >> j) << j))));
  new_cthis->data[i] = left_bits + right_bits;
  
  return new_cthis;
}

void *FUNCTION(NAME, clrs)(const void *cthis, const cgraph_size_t min, const cgraph_size_t max)
{

}

#include "templete_off.h"