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
  TYPE *object = (TYPE *)cthis;
  TYPE *res = FUNCTION(NAME, calloc)(DATA_ID, 1);
  if(NULL != res)
  {
    res->data[0] = BITSET_GET_BIT(object, pos);
    res->len = 1;
  }

  return res;
}

void *FUNCTION(NAME, set)(void *cthis, const cgraph_size_t pos)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t i = pos / DATA_BITS, j = pos % DATA_BITS;
  DATA_TYPE tmp = object->data[i], left_bits = ((tmp >> (j+1)) << (j+1)), right_bits = ((j == 0) ? 0 : (tmp ^ (~((DATA_ONES >> j) << j))));
  object->data[i] = left_bits + right_bits + 1 << j;

  return object;
}

void *FUNCTION(NAME, clr)(void *cthis, const cgraph_size_t pos)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t i = pos / DATA_BITS, j = pos % DATA_BITS;
  DATA_TYPE tmp = object->data[i], left_bits = ((tmp >> (j+1)) << (j+1)), right_bits = ((j == 0) ? 0 : (tmp ^ (~((DATA_ONES >> j) << j))));
  object->data[i] = left_bits + right_bits;
  
  return object;
}

void *FUNCTION(NAME, bits)(const void *cthis, const cgraph_size_t min, const cgraph_size_t max)
{
  TYPE *object = (TYPE *)cthis, *res = NULL;

  return res;
}

void *FUNCTION(NAME, sets)(void *cthis, const cgraph_size_t min, const cgraph_size_t max)
{

}

void *FUNCTION(NAME, clrs)(void *cthis, const cgraph_size_t min, const cgraph_size_t max)
{

}

#include "templete_off.h"