#include "cgraph_memory.h"
#include "cgraph_int64.h"

#define TYPE_INT64
#include "template.h"
#include "data_base.ct"

cgraph_size_t FUNCTION(NAME, hash)(const TYPE *cthis)
{
  cgraph_size_t hash = 0;
  if(NULL != cthis)
  { hash = *cthis; }
  
  return hash;
}

#include "template_off.h"
