#include "cgraph_long.h"
#include "cgraph_memory.h"

#define TYPE_LONG
#include "templete.h"
#include "integer_base.tc"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t hash = 0;
  if(NULL != object)
  { hash = *object; }
  
  return hash;
}

#include "templete_off.h"
