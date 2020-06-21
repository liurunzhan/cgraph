#include "cgraph_int64.h"
#include "cgraph_memory.h"

#define TYPE_INT64
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;
  
  return CGRAPH_ABS(object);
}

#include "integer.templete"

#include "templete_off.h"
