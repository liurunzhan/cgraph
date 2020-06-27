#include "cgraph_memory.h"
#include "cgraph_vector.h"

#define TYPE_VECTOR
#include "templete.h"
#include "struct.templete"

void *FUNCTION(NAME, calloc)(const cgraph_type_t type, const cgraph_size_t size)
{
  TYPE *cthis = (TYPE *)cgraph_calloc(1, sizeof(TYPE));
  if(NULL != cthis)
  {
    cthis->root = cgraph_calloc(size, CGRAPH_OBJECT(type, dsize)());
    if(NULL != cthis->data)
    {
      cthis->size = size;
      cthis->len = size;
      cthis->type = type;
      cthis->data = cthis->root;
    }
    else
    { cgraph_free(cthis); }
  }

  return cthis;
}

void *FUNCTION(NAME, realloc)(void *cthis, const cgraph_size_t old_size, cgraph_size_t new_size, cgraph_boolean_t *error)
{
  TYPE *object = (TYPE *)cthis;
  if(NULL != object && NULL != error)
  {
    *error = CGRAPH_FALSE;
    object->data = cgraph_realloc(object->data, object->size, new_size, CGRAPH_OBJECT(object->type, dsize)(), error);
    if(CGRAPH_FALSE == *error)
    { object->size = new_size; }
  }

  return object;
}

void *FUNCTION(NAME, copy)(const void *cthis, const cgraph_size_t size)
{
  TYPE *object = (TYPE *)cthis;
  TYPE *copy_cthis = NULL;
  void *copy_data = NULL;
  if(NULL != object)
  {
    copy_cthis = FUNCTION(NAME, calloc)(object->type, object->size);
    if(NULL != copy_cthis)
    {
      copy_data = copy_cthis->data;
      copy_cthis = cgraph_memcpy(copy_cthis, object, 1, sizeof(TYPE));
      copy_cthis->data = cgraph_memcpy(copy_data, object->data, object->size, CGRAPH_OBJECT(object->type, dsize)());
    }
  }

  return copy_cthis;
}

void FUNCTION(NAME, free)(void *cthis)
{
   TYPE *object = (TYPE *)cthis;
   cgraph_size_t i;
   for(i=0; i<object->size; i++)
   {
     CGRAPH_OBJECT(object->type, free)(object->root);
   }
   cgraph_free(object->root);
   cgraph_free(object);
}

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t i, hash = 0;
  if(NULL != object)
  {
    for(i=0; i<object->len; i++)
    {
      hash += i * CGRAPH_OBJECT(object->type, hash)(object->data);
    }
  }

  return hash;
}

void *FUNCTION(NAME, add)(const void *x, const void *y)
{
  TYPE *object_x = (TYPE *)x, *object_y = (TYPE *)y;
  cgraph_size_t i, len = CGRAPH_MIN(object_x->len, object_y->len);
  TYPE *res = FUNCTION(NAME, calloc)(object_x->type, len);
  if(NULL != res)
  {
    for(i=0; i<res->len; i++)
    {
      
    }
  }

  return res;
}

void *FUNCTION(NAME, iterator2)(void *cthis, cgraph_func2_t opt)
{
  TYPE *object = (TYPE *)cthis, *result = FUNCTION(NAME, calloc)(object->type, object->size);

  return result;
}

void *FUNCTION(NAME, iterator3)(const void *x, const void *y, cgraph_func3_t opt)
{
  TYPE *object_x = (TYPE *)x, *object_y = (TYPE *)y, *result = NULL;

  return result;
}

cgraph_vector_t *FUNCTION(NAME, primes)(const cgraph_integer_t data)
{
  cgraph_vector_t *primes = FUNCTION(NAME, calloc)(CGRAPH_INTEGER_T, data);
  cgraph_vector_t *isprime = FUNCTION(NAME, calloc)(CGRAPH_INTEGER_T, data);
  if(NULL != isprime)
  {
    if(NULL != primes)
    { primes->len = cgraph_math_primes(primes->data, isprime->data, data); }
    cgraph_vector_free(isprime);
  }

  return primes;
}

#include "templete_off.h"
