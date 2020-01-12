#include <float.h>
#include <math.h>
#include "cgraph_complex.h"
#include "cgraph_memory.h"

#define TYPE_COMPLEX
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;
  cgraph_size_t hash = 123;
  return hash;
}

/*
  mathematical operations of complex numbers
*/
/*                           res = (a*a+b*b)^(1/2)                            */
cgraph_real_t FUNCTION(NAME, mod)(const TYPE x)
{
  return sqrt(COMPLEX_MOD2(x));
}

cgraph_real_t FUNCTION(NAME, arg)(const TYPE x)
{
  return atan2(COMPLEX_IMAG(x), COMPLEX_REAL(x));
}

#include "templete_off.h"