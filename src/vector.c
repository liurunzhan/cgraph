#include "cgraph_object.h"
#include "cgraph_math.h"
#include "cgraph_memory.h"
#include "cgraph_vector.h"

#define TYPE_VECTOR
#include "templete.h"
#include "struct_base.ct"

void *FUNCTION(NAME, add)(const void *x, const void *y)
{
  TYPE *_x = (TYPE *)x, *_y = (TYPE *)y;
  TYPE *_z = NULL;
  if(CGRAPH_DTYPE_TYPE(_x) == CGRAPH_DTYPE_TYPE(_y))
  {
    cgraph_size_t i, len = CGRAPH_MIN(_x->len, _y->len);
    if(NULL != (_z = FUNCTION(NAME, calloc)(CGRAPH_DTYPE_TYPE(_x), len)))
    {
      for(i=0; i<_z->len; i++)
      {
        
      }
    }
  }

  return _z;
}

void *FUNCTION(NAME, sub)(const void *x, const void *y)
{
  TYPE *_x = (TYPE *)x, *_y = (TYPE *)y;
  TYPE *_z = NULL;
  if(CGRAPH_DTYPE_TYPE(_x) == CGRAPH_DTYPE_TYPE(_y))
  {
    cgraph_size_t i, len = CGRAPH_MIN(_x->len, _y->len);
    if(NULL != (_z = FUNCTION(NAME, calloc)(CGRAPH_DTYPE_TYPE(_x), len)))
    {
      for(i=0; i<_z->len; i++)
      {
        
      }
    }
  }

  return _z;
}

void *FUNCTION(NAME, mul)(const void *x, const void *y)
{
  TYPE *_x = (TYPE *)x, *_y = (TYPE *)y;
  TYPE *_z = NULL;
  if(CGRAPH_DTYPE_TYPE(_x) == CGRAPH_DTYPE_TYPE(_y))
  {
    cgraph_size_t i, len = CGRAPH_MIN(_x->len, _y->len);
    if(NULL != (_z = FUNCTION(NAME, calloc)(CGRAPH_DTYPE_TYPE(_x), len)))
    {
      for(i=0; i<_z->len; i++)
      {
        
      }
    }
  }

  return _z;
}

void *FUNCTION(NAME, div)(const void *x, const void *y)
{
  TYPE *_x = (TYPE *)x, *_y = (TYPE *)y;
  TYPE *_z = NULL;
  if(CGRAPH_DTYPE_TYPE(_x) == CGRAPH_DTYPE_TYPE(_y))
  {
    cgraph_size_t i, len = CGRAPH_MIN(_x->len, _y->len);
    if(NULL != (_z = FUNCTION(NAME, calloc)(CGRAPH_DTYPE_TYPE(_x), len)))
    {
      for(i=0; i<_z->len; i++)
      {
        
      }
    }
  }

  return _z;
}

void *FUNCTION(NAME, iterator2)(const void *x, cgraph_pfunc2_t opt)
{
  TYPE *_x = (TYPE *)x, *_y = NULL;
  if(NULL != _x)
  {
    _y = FUNCTION(NAME, calloc)(CGRAPH_DTYPE_TYPE(_x), _x->size);
    opt(_x, _y);
  }

  return _y;
}

void *FUNCTION(NAME, iterator3)(const void *x, const void *y, cgraph_pfunc3_t opt)
{
  TYPE *_x = (TYPE *)x, *_y = (TYPE *)y, *_z = NULL;
  if(NULL != _x && NULL != _y)
  {
    if(_x->len == _y->len && CGRAPH_DTYPE_TYPE(_x) == CGRAPH_DTYPE_TYPE(_y))
    {
      _z = FUNCTION(NAME, calloc)(CGRAPH_DTYPE_TYPE(_x), _x->len);
      opt(_x, _y, _z);
    }
  }

  return _z;
}

cgraph_vector_t *FUNCTION(NAME, primes)(const cgraph_int_t data)
{
  cgraph_vector_t *primes = FUNCTION(NAME, calloc)(CGRAPH_INT_T, data);
  cgraph_vector_t *isprime = FUNCTION(NAME, calloc)(CGRAPH_INT_T, data);
  if(NULL != isprime)
  {
    if(NULL != primes)
    { primes->len = cgraph_math_primes(primes->data, isprime->data, data); }
    cgraph_vector_free(isprime);
  }

  return primes;
}

void FUNCTION(NAME, test)(void)
{
#ifdef DEBUG

#endif
}

#include "templete_off.h"
