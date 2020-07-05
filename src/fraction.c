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
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t hash = 2166136261UL;
  if(NULL != object)
  {
    TYPE tmp = *object;
    hash = (hash ^ FRACTION_NUM(tmp)) * 16777619UL;
    hash = ((hash >> 8) ^ FRACTION_DEN(tmp)) * 16777619UL;
  }

  return CGRAPH_ABS(hash);
}

cgraph_boolean_t FUNCTION(NAME, test)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(NULL != object)
  {
    TYPE tmp = *object;
    if(0 != FRACTION_DEN(tmp))
    { flag = CGRAPH_TRUE; }
  }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, equal)(const void *x, const void *y)
{
  TYPE *object_x = (TYPE *)x, *object_y = (TYPE *)y;
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(NULL != object_x && NULL != object_y)
  {
    TYPE tmp_x = *object_x, tmp_y = *object_y;
    if(EQ(tmp_x, tmp_y))
    { flag = CGRAPH_TRUE; }
  }
  else if(NULL == object_x && NULL == object_y)
  { flag = CGRAPH_TRUE; }

  return flag;
}

/*                               private apis                                 */
cgraph_boolean_t FUNCTION(NAME, isnan)(const TYPE x)
{
  return CGRAPH_TEST((0 == FRACTION_NUM(x) && (0 == FRACTION_DEN(x))));
}

cgraph_boolean_t FUNCTION(NAME, isinf)(const TYPE x)
{
  return CGRAPH_TEST((0 != FRACTION_NUM(x) && (0 == FRACTION_DEN(x))));
}

cgraph_boolean_t FUNCTION(NAME, ispinf)(const TYPE x)
{
  return CGRAPH_TEST((0 < FRACTION_NUM(x) && (0 == FRACTION_DEN(x))));
}

cgraph_boolean_t FUNCTION(NAME, isninf)(const TYPE x)
{
  return CGRAPH_TEST((0 > FRACTION_NUM(x) && (0 == FRACTION_DEN(x))));
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

cgraph_boolean_t FUNCTION(NAME, ismin)(const TYPE x)
{
  TYPE min = MIN;

  return CGRAPH_TEST(EQ(x, min));
}

cgraph_boolean_t FUNCTION(NAME, ismax)(const TYPE x)
{
  TYPE max = MAX;

  return CGRAPH_TEST(EQ(x, max));
}

TYPE FUNCTION(NAME, addn)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) + FRACTION_DEN(x) * y;
  FRACTION_DEN(res) = FRACTION_DEN(x); 

  return res;
}

TYPE FUNCTION(NAME, subn)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) - FRACTION_DEN(x) * y;
  FRACTION_DEN(res) = FRACTION_DEN(x); 

  return res;
}

TYPE FUNCTION(NAME, muln)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * y;
  FRACTION_DEN(res) = FRACTION_DEN(x); 

  return res;
}

TYPE FUNCTION(NAME, divn)(const TYPE x, const DATA_TYPE y)
{
  TYPE res; 
  FRACTION_NUM(res) = FRACTION_NUM(x);
  FRACTION_DEN(res) = FRACTION_DEN(x) * y;
  
  return res;
}

TYPE FUNCTION(NAME, pown)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  FRACTION_NUM(res) = (FRACTION_NUM(x) == 0 || FRACTION_NUM(x) == 1) ? FRACTION_NUM(x) : (DATA_TYPE)pow(FRACTION_DEN(x), y);
  FRACTION_DEN(res) = FRACTION_DEN(x) == 1 ? FRACTION_DEN(x) : (DATA_TYPE)pow(FRACTION_DEN(x), y);

  return res;
}

TYPE FUNCTION(NAME, addd)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * y + FRACTION_DEN(x);
  FRACTION_DEN(res) = FRACTION_DEN(x) * y; 

  return res;
}

TYPE FUNCTION(NAME, subd)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * y - FRACTION_DEN(x);
  FRACTION_DEN(res) = FRACTION_DEN(x) * y;

  return res;
}

TYPE FUNCTION(NAME, muld)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x);
  FRACTION_DEN(res) = FRACTION_DEN(x) * y; 

  return res;
}

TYPE FUNCTION(NAME, divd)(const TYPE x, const DATA_TYPE y)
{
  TYPE res; 
  FRACTION_NUM(res) = FRACTION_NUM(x) * y;
  FRACTION_DEN(res) = FRACTION_DEN(x);
  
  return res;
}

TYPE FUNCTION(NAME, powd)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  FRACTION_NUM(res) = (FRACTION_NUM(x) == 0 || FRACTION_NUM(x) == 1) ? FRACTION_NUM(x) : (DATA_TYPE)pow(FRACTION_DEN(x), y);
  FRACTION_DEN(res) = FRACTION_DEN(x) == 1 ? FRACTION_DEN(x) : (DATA_TYPE)pow(FRACTION_DEN(x), y);

  return res;
}

TYPE FUNCTION(NAME, addf)(const TYPE x, const TYPE y)
{
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_DEN(y) + FRACTION_DEN(x) * FRACTION_NUM(y);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y); 

  return res;
}

TYPE FUNCTION(NAME, subf)(const TYPE x, const TYPE y)
{
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_DEN(y) - FRACTION_DEN(x) * FRACTION_NUM(y);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y); 

  return res;
}

TYPE FUNCTION(NAME, mulf)(const TYPE x, const TYPE y)
{
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_NUM(y);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y); 

  return res;
}

TYPE FUNCTION(NAME, divf)(const TYPE x, const TYPE y)
{
  TYPE res; 
  FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_DEN(y);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_NUM(y);
  
  return res;
}

TYPE FUNCTION(NAME, powf)(const TYPE x, const TYPE y)
{
  TYPE res;

  return res;
}

TYPE FUNCTION(NAME, abs)(const TYPE x)
{
  TYPE res;
  FRACTION_NUM(res) = ((FRACTION_NUM(x) > 0) ? FRACTION_NUM(x) : (-FRACTION_NUM(x)));
  FRACTION_DEN(res) = ((FRACTION_DEN(x) > 0) ? FRACTION_DEN(x) : (-FRACTION_DEN(x))); 

  return res;
}

#include "templete_off.h"
