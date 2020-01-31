#include "cgraph_bigint.h"
#include "cgraph_memory.h"

#define TYPE_BIGINT
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  
  return 0;
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

#include "templete_off.h"