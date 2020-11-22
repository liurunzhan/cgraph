#include "cgraph_memory.h"
#include "cgraph_long.h"

#define TYPE_LONG
#include "templete.h"
#include "int_base.ct"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *_cthis = (TYPE *)cthis;
  cgraph_size_t hash = 0;
  if(NULL != _cthis)
  { hash = *_cthis; }
  
  return hash;
}

#include "templete_off.h"
