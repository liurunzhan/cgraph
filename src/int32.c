#include "cgraph_int32.h"
#include "cgraph_memory.h"

#define TYPE_INT32
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t hash = 0;
  if(NULL != object)
  {
    hash = ((*object >> 16) ^ *object) * 0x45d9f3b;
    hash = ((hash >> 16) ^ hash) * 0x45d9f3b;
    hash = (hash >> 16) ^ hash;
  }

  
  return hash;
}

#include "integer.templete"

#include "templete_off.h"
