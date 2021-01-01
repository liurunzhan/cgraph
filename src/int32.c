#include "cgraph_memory.h"
#include "cgraph_int32.h"

#define TYPE_INT32
#include "template.h"
#include "int_base.ct"

cgraph_size_t FUNCTION(NAME, hash)(const TYPE *cthis)
{
  cgraph_size_t hash = 0;
  if(NULL != cthis)
  {
    hash = ((*cthis >> 16) ^ *cthis) * 0x45d9f3b;
    hash = ((hash >> 16) ^ hash) * 0x45d9f3b;
    hash = (hash >> 16) ^ hash;
  }
  
  return hash;
}

#include "template_off.h"
