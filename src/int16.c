#include "cgraph_int16.h"
#include "cgraph_memory.h"

#define TYPE_INT16
#include "templete.h"
#include "integer_base.ct"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t hash = 0;
  if(NULL != object)
  { hash = *object; }
  
  return hash;
}

#include "templete_off.h"
