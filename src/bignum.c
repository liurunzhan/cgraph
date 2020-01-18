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

#include "templete_off.h"