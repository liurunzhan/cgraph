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

void *FUNCTION(NAME, abs)(void *cthis)
{
  TYPE *object = (TYPE *)(cthis);
  cgraph_size_t i = 0;
  while((' ' != object->data[i]) && ('0' != object->data[i]) && (i<object->len)) 
  { i++; }
  if(object->data[i] == '-')
  { object->data[i] = '+'; }

  return object;
}

cgraph_boolean_t FUNCTION(NAME, test)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_boolean_t flag = CGRAPH_TRUE;
  cgraph_size_t i;
  for(i=0; i<object->len; i++)
  {
    if(!isdigit(object->data[i]))
    {
      flag = CGRAPH_FALSE;
      break;
    }
  }

  return flag;
}

#include "templete_off.h"