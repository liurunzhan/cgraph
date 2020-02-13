#include "cgraph_bignum.h"
#include "cgraph_memory.h"

#define TYPE_BIGNUM
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *new_cthis = (TYPE *)cthis;
  cgraph_size_t hash = 0, i;
  for(i=0; i<new_cthis->len; i++)
  { hash += (hash << 5) + new_cthis->data[i]; }

  return hash;
}

void *FUNCTION(NAME, abs)(void *cthis)
{
  TYPE *new_cthis = (TYPE *)(cthis);
  cgraph_size_t i = 0;
  while((new_cthis->data[i] != ' ') && (i<new_cthis->len)) 
  { i++; }
  if(new_cthis->data[i] == '-')
  { new_cthis->data[i] = '+'; }

  return new_cthis;
}

#include "templete_off.h"