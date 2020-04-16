#include <stdio.h>
#include "cgraph_bigint.h"
#include "cgraph_memory.h"
#include "cgraph_math.h"

#define TYPE_BIGINT
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t hash = object->pos, i;
  for(i=0; i<object->len; i++)
  { hash += (hash << 5) + object->data[i]; }

  return hash;
}

void *FUNCTION(NAME, abs)(void *cthis)
{
  TYPE *object = (TYPE *)(cthis);
  object->pos = ((object->pos == CGRAPH_FALSE) ? CGRAPH_TRUE : CGRAPH_TRUE);
  
  return object;
}

void *FUNCTION(NAME, add)(const void *x, const void *y)
{
  TYPE *new_x = (TYPE *)x, *new_y = (TYPE *)y, *res;
  cgraph_size_t len = CGRAPH_MAX(new_x->len, new_y->len);
  res = FUNCTION(NAME, calloc)(CGRAPH_INTEGER_T, len+1);
  if(NULL != res)
  {
    if(new_x->pos == new_y->pos)
    {
      cgraph_size_t i;
      for(i=1; i<len; i++)
      { res->data[res->len-i] = new_x->data[new_x->len-i] + new_y->data[new_y->len-i]; }
      res->pos = new_x->pos;
    }
  }

  return res;
}

cgraph_string_t *FUNCTION(NAME, tostr)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t dec_len = cgraph_math_baseoflen(DATA_MAX, 10);
  cgraph_string_t *buffer = cgraph_string_calloc(1, object->len*dec_len);
  if(NULL != buffer)
  {
    cgraph_size_t i, j;
    DATA_TYPE tmp;
    for(i=object->len-1; i>=0; i--)
    {
      tmp = object->data[i];
      for(j=dec_len-1; j>=0; j--)
      {
        buffer->data[i*dec_len+j] = '0' + tmp % 10;
        tmp /= 10;
      }
    }
  }

  return buffer;
}

#include "templete_off.h"