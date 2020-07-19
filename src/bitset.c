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

  return CGRAPH_ABS(hash);
}

cgraph_boolean_t FUNCTION(NAME, equal)(const void *x, const void *y)
{
  TYPE *object_x = (TYPE *)x, *object_y = (TYPE *)y;
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if((NULL != object_x) && (NULL != object_y))
  {
    if(object_x->len == object_y->len)
    {
      flag = cgraph_memcmp(object_x->data, object_y->data, object_x->len, FUNCTION(NAME, dsize)());
    }
  }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, test)(const void *cthis)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  TYPE *object = (TYPE *)cthis;
  if(NULL != object)
  { flag = CGRAPH_TRUE; }

  return flag;
}

TYPE *FUNCTION(NAME, bit)(const TYPE *cthis, const cgraph_size_t pos)
{
  TYPE *res = FUNCTION(NAME, calloc)(DATA_ID, 1);
  if(NULL != res)
  {
    res->data[0] = BITSET_GET_BIT(cthis, pos);
    res->len = 1;
  }

  return res;
}

TYPE *FUNCTION(NAME, set)(TYPE *cthis, const cgraph_size_t pos)
{
  cgraph_size_t i = pos / DATA_BITS, j = pos % DATA_BITS;
  DATA_TYPE tmp = cthis->data[i], left_bits = ((tmp >> (j+1)) << (j+1)), right_bits = ((j == 0) ? 0 : (tmp ^ (~((DATA_ONES >> j) << j))));
  cthis->data[i] = left_bits + right_bits + 1 << j;

  return cthis;
}

TYPE *FUNCTION(NAME, clr)(TYPE *cthis, const cgraph_size_t pos)
{
  cgraph_size_t i = pos / DATA_BITS, j = pos % DATA_BITS;
  DATA_TYPE tmp = cthis->data[i], left_bits = ((tmp >> (j+1)) << (j+1)), right_bits = ((j == 0) ? 0 : (tmp ^ (~((DATA_ONES >> j) << j))));
  cthis->data[i] = left_bits + right_bits;
  
  return cthis;
}

TYPE *FUNCTION(NAME, bits)(const TYPE *cthis, const cgraph_size_t min, const cgraph_size_t max)
{
  TYPE *res = NULL;

  return res;
}

TYPE *FUNCTION(NAME, sets)(TYPE *cthis, const cgraph_size_t min, const cgraph_size_t max)
{

  return cthis;
}

TYPE *FUNCTION(NAME, clrs)(TYPE *cthis, const cgraph_size_t min, const cgraph_size_t max)
{

  return cthis;
}

TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y)
{

}

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y)
{
  
}

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y)
{
  
}

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y)
{
  
}

cgraph_boolean_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y)
{
  
}

cgraph_boolean_t FUNCTION(NAME, gr)(const TYPE *x, const TYPE *y)
{
  
}

cgraph_boolean_t FUNCTION(NAME, ge)(const TYPE *x, const TYPE *y)
{
  
}

cgraph_boolean_t FUNCTION(NAME, ls)(const TYPE *x, const TYPE *y)
{
  
}

cgraph_boolean_t FUNCTION(NAME, le)(const TYPE *x, const TYPE *y)
{
  
}

#include "templete_off.h"
