#include "cgraph_bitset.h"
#include "cgraph_memory.h"

#define TYPE_BITSET
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t i, hash = 0;
  for(i=0; i<(object->len>>3); i++)
  {
    hash = (hash << 4) ^ (hash >> 28) ^ object->data[i];
  }
  hash = (hash << 4) ^ (hash >> 28) ^ object->data[i];

  return hash;
}

cgraph_boolean_t FUNCTION(NAME, equal)(const void *x, const void *y)
{
  TYPE *object_x = (TYPE *)x, *object_y = (TYPE *)y;
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if((NULL != object_x) && (NULL != object_y))
  {
    if((object_x->len == object_y->len) && (CGRAPH_TRUE == cgraph_memcmp(object_x->data, object_y->data, object_x->len, FUNCTION(NAME, dsize)())))
    { flag = CGRAPH_TRUE; }
  }

  return flag;
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