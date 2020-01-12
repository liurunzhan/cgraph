#include "cgraph_int32.h"
#include "cgraph_memory.h"

#define TYPE_INT32
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;
  cgraph_size_t hash = object == CGRAPH_FALSE ? 0 : (object == CGRAPH_TRUE ? 1 : 2);
  return hash;
}

#include "templete_off.h"