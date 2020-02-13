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

/* initial function */
TYPE FUNCTION(NAME, initam)(const DATA_TYPE arg, const DATA_TYPE mod)
{
  TYPE res;
  COMPLEX_REAL(res) = mod * cos(arg);
  COMPLEX_IMAG(res) = mod * sin(arg);

  return res;
}

TYPE FUNCTION(NAME, initri)(const DATA_TYPE real, const DATA_TYPE imag)
{
  TYPE res;
  COMPLEX_REAL(res) = real;
  COMPLEX_IMAG(res) = imag;

  return res;
}

/*                 mathematical operations of complex numbers                 */
/*                           res = (a*a+b*b)^(1/2)                            */
DATA_TYPE FUNCTION(NAME, mod)(const TYPE x)
{
  return sqrt(COMPLEX_MOD2(x));
}

DATA_TYPE FUNCTION(NAME, arg)(const TYPE x)
{
  return atan2(COMPLEX_IMAG(x), COMPLEX_REAL(x));
}

TYPE FUNCTION(NAME, conj)(const TYPE x)
{
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = -COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, powr)(const TYPE x, const cgraph_real_t y)
{
  DATA_TYPE arg = FUNCTION(NAME, arg)(x) * y, mod = pow(FUNCTION(NAME, mod)(x), y);

  return FUNCTION(NAME, initam)(arg, mod);
}

TYPE FUNCTION(NAME, powc)(const TYPE x, const TYPE y)
{
  TYPE res;
  DATA_TYPE arg = FUNCTION(NAME, arg)(x), mod = FUNCTION(NAME, mod)(x);

  return res;
}

#include "templete_off.h"