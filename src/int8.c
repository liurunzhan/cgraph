#include "cgraph_memory.h"
#include "cgraph_int8.h"

#define TYPE_INT8
#include "templete.h"
#include "integer_base.ct"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *_cthis = (TYPE *)cthis;
  cgraph_size_t hash = 0;
  if(NULL != _cthis)
  { hash = *_cthis; }
  
  return hash;
}

#include "templete_off.h"
