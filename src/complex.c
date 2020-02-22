#include <float.h>
#include <math.h>
#include "cgraph_memory.h"
#include "cgraph_complex.h"

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
TYPE FUNCTION(NAME, initma)(const DATA_TYPE mod, const DATA_TYPE arg)
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

TYPE FUNCTION(NAME, muli)(const TYPE x)
{
  TYPE res; 
  COMPLEX_REAL(res) = -COMPLEX_IMAG(x);
  COMPLEX_IMAG(res) = COMPLEX_REAL(x);

  return res;
}

TYPE FUNCTION(NAME, muli2)(const TYPE x)
{
  TYPE res;
  COMPLEX_REAL(res) = -COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = -COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, muli3)(const TYPE x)
{
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_IMAG(x);
  COMPLEX_IMAG(res) = -COMPLEX_REAL(x);

  return res;
}
TYPE FUNCTION(NAME, muli4)(const TYPE x)
{
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, addr)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) + y;
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, subr)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) - y;
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, mulr)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) * y;
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) * y;

  return res;
}

TYPE FUNCTION(NAME, divr)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) / y;
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) / y;

  return res;
}

TYPE FUNCTION(NAME, powr)(const TYPE x, const cgraph_real_t y)
{
  DATA_TYPE mod = pow(FUNCTION(NAME, mod)(x), y), arg = FUNCTION(NAME, arg)(x) * y;
  TYPE res;
  COMPLEX_REAL(res) = mod * cos(arg);
  COMPLEX_IMAG(res) = mod * sin(arg);

  return res;
}

TYPE FUNCTION(NAME, addc)(const TYPE x, const TYPE y)
{
  TYPE res; 
  COMPLEX_REAL(res) = COMPLEX_REAL(x) + COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) + COMPLEX_IMAG(y);

  return res;
}

TYPE FUNCTION(NAME, subc)(const TYPE x, const TYPE y)
{
  TYPE res; 
  COMPLEX_REAL(res) = COMPLEX_REAL(x) - COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) - COMPLEX_IMAG(y);

  return res;
}

TYPE FUNCTION(NAME, mulc)(const TYPE x, const TYPE y)
{
  TYPE res; 
  COMPLEX_REAL(res) = COMPLEX_REAL(x) * COMPLEX_REAL(y) - COMPLEX_IMAG(x) * COMPLEX_IMAG(y); 
  COMPLEX_IMAG(res) = COMPLEX_REAL(x) * COMPLEX_IMAG(y) + COMPLEX_IMAG(x) * COMPLEX_REAL(y); 
  
  return res;
}

TYPE FUNCTION(NAME, divc)(const TYPE x, const TYPE y)
{
  DATA_TYPE mod = COMPLEX_MOD2(y);
  TYPE res;
  if(mod > DATA_EPSILON)
  {
    COMPLEX_REAL(res) = (COMPLEX_REAL(x) * COMPLEX_REAL(y) + COMPLEX_IMAG(x) * COMPLEX_IMAG(y)) / mod; 
    COMPLEX_IMAG(res) = (COMPLEX_IMAG(x) * COMPLEX_REAL(y) - COMPLEX_REAL(x) * COMPLEX_IMAG(y)) / mod;
  }
  else
  {
    COMPLEX_REAL(res) = 1.0 / 0.0;
    COMPLEX_IMAG(res) = 1.0 / 0.0;
  }
  
  return res;
}

TYPE FUNCTION(NAME, powc)(const TYPE x, const TYPE y)
{
  TYPE res = FUNCTION(NAME, log)(x);
  res = FUNCTION(NAME, mulc)(y, res);

  return FUNCTION(NAME, exp)(res); 
}

TYPE FUNCTION(NAME, opp)(const TYPE x)
{
  TYPE res;
  COMPLEX_REAL(res) = -COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = -COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, abs)(const TYPE x)
{
  TYPE res;
  COMPLEX_REAL(res) = fabs(COMPLEX_REAL(x));
  COMPLEX_IMAG(res) = fabs(COMPLEX_IMAG(x));

  return res;
}

TYPE FUNCTION(NAME, sin)(const TYPE x)
{
  TYPE ix = FUNCTION(NAME, muli)(x), _ix = FUNCTION(NAME, muli3)(x);
  TYPE expix = FUNCTION(NAME, exp)(ix), exp_ix = FUNCTION(NAME, exp)(_ix);
  TYPE res;
  COMPLEX_REAL(res) = 0.5 * (COMPLEX_IMAG(expix) - COMPLEX_IMAG(exp_ix));
  COMPLEX_IMAG(res) = -0.5 * (COMPLEX_REAL(expix) - COMPLEX_REAL(exp_ix));

  return res;
}

TYPE FUNCTION(NAME, cos)(const TYPE x)
{
  TYPE ix = FUNCTION(NAME, muli)(x), _ix = FUNCTION(NAME, muli3)(x);
  TYPE expix = FUNCTION(NAME, exp)(ix), exp_ix = FUNCTION(NAME, exp)(_ix);
  TYPE res;
  COMPLEX_REAL(res) = 0.5 * (COMPLEX_REAL(expix) + COMPLEX_REAL(exp_ix));
  COMPLEX_IMAG(res) = 0.5 * (COMPLEX_IMAG(expix) + COMPLEX_IMAG(exp_ix));

  return res;
}

TYPE FUNCTION(NAME, tan)(const TYPE x)
{
  TYPE sinx = FUNCTION(NAME, sin)(x), cosx = FUNCTION(NAME, cos)(x);
  TYPE res = FUNCTION(NAME, divc)(sinx, cosx);

  return res;
}

TYPE FUNCTION(NAME, sinh)(const TYPE x)
{
  TYPE expx = FUNCTION(NAME, exp)(x), _x = FUNCTION(NAME, muli2)(x), exp_x = FUNCTION(NAME, exp)(_x);
  TYPE res;
  COMPLEX_REAL(res) = 0.5 * (COMPLEX_REAL(expx) - COMPLEX_REAL(exp_x));
  COMPLEX_IMAG(res) = 0.5 * (COMPLEX_IMAG(expx) - COMPLEX_IMAG(exp_x));

  return res;
}

TYPE FUNCTION(NAME, cosh)(const TYPE x)
{
  TYPE expx = FUNCTION(NAME, exp)(x), _x = FUNCTION(NAME, muli2)(x), exp_x = FUNCTION(NAME, exp)(_x);
  TYPE res;
  COMPLEX_REAL(res) = 0.5 * (COMPLEX_REAL(expx) + COMPLEX_REAL(exp_x));
  COMPLEX_IMAG(res) = 0.5 * (COMPLEX_IMAG(expx) + COMPLEX_IMAG(exp_x));

  return res;
}

TYPE FUNCTION(NAME, tanh)(const TYPE x)
{
  TYPE sinhx = FUNCTION(NAME, sinh)(x), coshx = FUNCTION(NAME, cosh)(x);
  TYPE res = FUNCTION(NAME, divc)(sinhx, coshx);

  return res;
}

TYPE FUNCTION(NAME, log)(const TYPE x)
{
  TYPE res;
  COMPLEX_REAL(res) = log(FUNCTION(NAME, mod)(x));
  COMPLEX_IMAG(res) = FUNCTION(NAME, arg)(x);

  return res;
}

TYPE FUNCTION(NAME, log2)(const TYPE x)
{
  TYPE res = FUNCTION(NAME, log)(x);
  DATA_TYPE log2 = log(2);
  COMPLEX_REAL(res) = COMPLEX_REAL(res) / log2;
  COMPLEX_IMAG(res) = COMPLEX_IMAG(res) / log2;

  return res;
}

TYPE FUNCTION(NAME, log10)(const TYPE x)
{
  TYPE res = FUNCTION(NAME, log)(x);
  DATA_TYPE log10 = log(10);
  COMPLEX_REAL(res) = COMPLEX_REAL(res) / log10;
  COMPLEX_IMAG(res) = COMPLEX_IMAG(res) / log10;

  return res;
}

TYPE FUNCTION(NAME, exp)(const TYPE x)
{
  DATA_TYPE mod = exp(COMPLEX_REAL(x));
  TYPE res;
  COMPLEX_REAL(res) = mod * cos(COMPLEX_IMAG(x));
  COMPLEX_IMAG(res) = mod * sin(COMPLEX_IMAG(x));

  return res;
}

TYPE FUNCTION(NAME, sqrt)(const TYPE x)
{
  DATA_TYPE mod = sqrt(FUNCTION(NAME, mod)(x)), arg = 0.5 * FUNCTION(NAME, arg)(x);
  TYPE res;
  COMPLEX_REAL(res) = mod * cos(arg);
  COMPLEX_IMAG(res) = mod * sin(arg);

  return res;
}

#include "templete_off.h"