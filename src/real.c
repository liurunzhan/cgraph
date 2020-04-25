#include <math.h>
#include "cgraph_real.h"
#include "cgraph_memory.h"

#define TYPE_REAL
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;
  cgraph_size_t hash = (cgraph_size_t)(object * 1.0 / DATA_EPSILON);

  return hash;
}

#include "templete_off.h"