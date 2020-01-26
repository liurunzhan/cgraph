#include "cgraph_long.h"
#include "cgraph_memory.h"

#define TYPE_LONG
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;
  return ABS(object);
}

#include "templete_off.h"