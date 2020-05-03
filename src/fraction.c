#include <math.h>
#include "cgraph_fraction.h"
#include "cgraph_memory.h"

#define TYPE_FRACTION
#include "templete.h"
#include "data.templete"

/*                                public apis                                 */
/*
  fnv-1a hash function (Fowler-Noll-Vo hash function, proposed by Glenn Fowler，Landon Curt Noll and Phong Vo in 1991):
  begin_of_algorithm
    hash = offset_basis
    for byte_of_data in data
    begin
      hash = hash ^ byte_of_data
      hash = hash * fnv_prime
    end
    return hash
  end_of_algorithm
  32-bit offset_basis : 2166136261
  32-bit fnv_prime : 16777619 = 2^24 + 2^8 + 0x93
  64-bit offset_basis : 14695981039346656037
  64-bit fnv_prime : 1099511628211 = 2^40 + 2^8 + 0xb3
*/
cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;
  cgraph_size_t hash = 2166136261, i;
  char *tmp = (char *)(&FRACTION_NUM(object));
  for(i=0; i<sizeof(DATA_TYPE); i++)
  { hash = (hash ^ tmp[i]) * 16777619; }
  tmp = (char *)(&FRACTION_DEN(object));
  for(i=0; i<sizeof(DATA_TYPE); i++)
  { hash = (hash ^ tmp[i]) * 16777619; }

  return hash;
}

cgraph_boolean_t FUNCTION(NAME, test)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;

  return CGRAPH_TEST((0 != FRACTION_DEN(object)));
}

cgraph_boolean_t FUNCTION(NAME, isnan)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;

  return CGRAPH_TEST((0 == FRACTION_NUM(object) && (0 == FRACTION_DEN(object))));
}

cgraph_boolean_t FUNCTION(NAME, isinf)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;

  return CGRAPH_TEST((0 != FRACTION_NUM(object) && (0 == FRACTION_DEN(object))));
}

/*                               private apis                                 */
TYPE FUNCTION(NAME, add)(const TYPE x, const TYPE y)
{
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_DEN(y) + FRACTION_DEN(x) * FRACTION_NUM(y);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y); 

  return res;
}

TYPE FUNCTION(NAME, sub)(const TYPE x, const TYPE y)
{
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_DEN(y) - FRACTION_DEN(x) * FRACTION_NUM(y);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y); 

  return res;
}

TYPE FUNCTION(NAME, mul)(const TYPE x, const TYPE y)
{
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_NUM(y);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y); 

  return res;
}

TYPE FUNCTION(NAME, div)(const TYPE x, const TYPE y)
{
  TYPE res; 
  FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_DEN(y);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_NUM(y);
  
  return res;
}

TYPE FUNCTION(NAME, pow)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  FRACTION_NUM(res) = (FRACTION_NUM(x) == 0 || FRACTION_NUM(x) == 1) ? FRACTION_NUM(x) : (DATA_TYPE)pow(FRACTION_DEN(x), y);
  FRACTION_DEN(res) = FRACTION_DEN(x) == 1 ? FRACTION_DEN(x) : (DATA_TYPE)pow(FRACTION_DEN(x), y);

  return res;
}

TYPE FUNCTION(NAME, abs)(const TYPE x)
{
  TYPE res;
  FRACTION_NUM(res) = ((FRACTION_NUM(x) > 0) ? FRACTION_NUM(x) : (-FRACTION_NUM(x)));
  FRACTION_DEN(res) = ((FRACTION_DEN(x) > 0) ? FRACTION_DEN(x) : (-FRACTION_DEN(x))); 

  return res;
}

cgraph_boolean_t FUNCTION(NAME, iszero)(const TYPE x)
{
  return CGRAPH_TEST((FRACTION_NUM(x) == 0) && (FRACTION_DEN(x) != 0));
}

cgraph_boolean_t FUNCTION(NAME, ispos)(const TYPE x)
{
  return CGRAPH_TEST(((FRACTION_NUM(x) > 0) && (FRACTION_DEN(x) > 0)) || ((FRACTION_NUM(x) < 0) && (FRACTION_DEN(x) < 0)));
}

cgraph_boolean_t FUNCTION(NAME, isneg)(const TYPE x)
{
  return CGRAPH_TEST(((FRACTION_NUM(x) < 0) && (FRACTION_DEN(x) > 0)) || ((FRACTION_NUM(x) > 0) && (FRACTION_DEN(x) < 0)));
}

#include "templete_off.h"