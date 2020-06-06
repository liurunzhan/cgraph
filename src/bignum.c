#include <ctype.h>
#include "cgraph_bignum.h"
#include "cgraph_memory.h"

#define TYPE_BIGNUM
#include "templete.h"
#include "data.templete"

/*
  BKDR Hash Algorithm
  hash = (hash * 31) + (cthis->data[i] - '0')
*/
cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t hash = 0, i;
  for(i=0; i<object->len; i++)
  { hash = (hash * 31) + (object->data[i] - '0'); }

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

TYPE *FUNCTION(NAME, abs)(TYPE *cthis)
{
  if((NULL != cthis) && ('-' == cthis->data[0]))
  {
    cthis->data = &(cthis->data[1]);
    cthis->len -= 1;
  }

  return cthis;
}

cgraph_boolean_t FUNCTION(NAME, test)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_boolean_t flag = CGRAPH_TRUE;
  cgraph_size_t i = 0;
  if(('+' == object->data[i]) || ('-' == object->data[i]))
  { i++; }
  else
  {
    for(; i<object->len; i++)
    {
      if(!isdigit(object->data[i]))
      {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }

  return flag;
}

TYPE *FUNCTION(NAME, format)(TYPE *cthis)
{
  if(NULL != cthis)
  {
    DATA_TYPE *data = cthis->data;
    while(((' ' == *data) || ('0' == *data)) && (0 < cthis->len))
    {
      cthis->len -= 1;
      data++;
    }
    cthis->data = data;
  }

  return cthis;
}



#include "templete_off.h"