#include <stdio.h>
#include "cgraph_bigint.h"
#include "cgraph_memory.h"
#include "cgraph_math.h"

#define TYPE_BIGINT
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  
  return 0;
}

void *FUNCTION(NAME, abs)(void *cthis)
{
  TYPE *new_cthis = (TYPE *)(cthis);
  new_cthis->pos = ((new_cthis->pos == CGRAPH_FALSE) ? CGRAPH_TRUE : CGRAPH_TRUE);
  
  return new_cthis;
}

void *FUNCTION(NAME, add)(const void *x, const void *y)
{
  TYPE *a = (TYPE *)x, *b = (TYPE *)y, *res;
  cgraph_size_t len = a->len > b->len ? a->len : b->len;
  res = FUNCTION(NAME, calloc)(CGRAPH_INTEGER_T, len+1);
  if(NULL != res)
  {
    if(a->pos == b->pos)
    {
      cgraph_size_t i;
      for(i=1; i<len; i++)
      { res->data[res->len-i] = a->data[a->len-i] + b->data[b->len-i]; }
      res->pos = a->pos;
    }
  }

  return res;
}

cgraph_string_t *FUNCTION(NAME, tostr)(const void *cthis)
{
  TYPE *new_cthis = (TYPE *)cthis;
  cgraph_size_t dec_len = cgraph_math_baseoflen(DATA_MAX, 10);
  cgraph_string_t *buffer = cgraph_string_calloc(1, new_cthis->len*dec_len);
  if(NULL != buffer)
  {
    cgraph_size_t i, j;
    DATA_TYPE tmp;
    for(i=new_cthis->len-1; i>=0; i--)
    {
      tmp = new_cthis->data[i];
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