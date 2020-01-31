#include <math.h>
#include "cgraph_real.h"
#include "cgraph_memory.h"

#define TYPE_REAL
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis, integer_number = floor(object), float_number = object - integer_number;
  cgraph_size_t hash = 1234567891;

  return hash;
}

#include "templete_off.h"