#include "cgraph_bignum.h"
#include "cgraph_memory.h"

#define TYPE_BIGNUM
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t hash = 0, i;
  for(i=0; i<object->len; i++)
  { hash += (hash << 5) + object->data[i]; }

  return hash;
}

void *FUNCTION(NAME, abs)(void *cthis)
{
  TYPE *object = (TYPE *)(cthis);
  cgraph_size_t i = 0;
  while((object->data[i] != ' ') && (i<object->len)) 
  { i++; }
  if(object->data[i] == '-')
  { object->data[i] = '+'; }

  return object;
}

#include "templete_off.h"