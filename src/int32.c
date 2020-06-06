#include "cgraph_int32.h"
#include "cgraph_memory.h"

#define TYPE_INT32
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;
  object = ((object >> 16) ^ object) * 0x45d9f3b;
  object = ((object >> 16) ^ object) * 0x45d9f3b;
  object = (object >> 16) ^ object;
  
  return CGRAPH_ABS(object);
}

#include "integer.templete"

#include "templete_off.h"