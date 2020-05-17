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

TYPE *FUNCTION(NAME, abs)(TYPE *cthis)
{
  if('-' == cthis->data[0])
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
  cgraph_size_t i= 0;
  while((' ' == cthis->data[i]) && (i < cthis->len))
  { i++; }
  cthis->data = &(cthis->data[i]);
  cthis->len -= i;

  return cthis;
}



#include "templete_off.h"