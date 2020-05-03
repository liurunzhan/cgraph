#include <math.h>
#include "cgraph_real.h"
#include "cgraph_memory.h"

#define TYPE_REAL
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;
  cgraph_size_t hash;
  if(object != object)
  { hash = 1234567891; }
  else
  { hash = (cgraph_size_t)(object * 1.0 / DATA_EPSILON); }

  return hash;
}

#include "float.templete"

#include "templete_off.h"