#include "cgraph_memory.h"
#include "cgraph_int32.h"

#define TYPE_INT32
#include "template.h"
#include "int_base.ct"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *_cthis = (TYPE *)cthis;
  cgraph_size_t hash = 0;
  if(NULL != _cthis)
  {
    hash = ((*_cthis >> 16) ^ *_cthis) * 0x45d9f3b;
    hash = ((hash >> 16) ^ hash) * 0x45d9f3b;
    hash = (hash >> 16) ^ hash;
  }
  
  return hash;
}

#include "template_off.h"
