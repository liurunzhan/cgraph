#include "cgraph_memory.h"
#include "cgraph_int16.h"

#define TYPE_INT16
#include "template.h"
#include "int_base.ct"

cgraph_size_t FUNCTION(NAME, hash)(const TYPE *cthis)
{
  cgraph_size_t hash = 0;
  if(NULL != cthis)
  { hash = *cthis; }
  
  return hash;
}

#include "template_off.h"
