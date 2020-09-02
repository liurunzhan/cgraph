#include "cgraph_object.h"
#include "cgraph_memory.h"
#include "cgraph_error.h"

#include "cgraph_data.h"
#include "cgraph_struct.h"

#define TYPE_OBJECT
#include "templete.h"

CGVTable *_cgraph_objects_[] = 
{
  &STRUCT(object),
  &STRUCT(integer),
  &STRUCT(real),
  &STRUCT(boolean),
  &STRUCT(float),
  &STRUCT(long),
  &STRUCT(int8),
  &STRUCT(int16),
  &STRUCT(int32),
  &STRUCT(int64),
  NULL,
  /* &STRUCT(time), */
  &STRUCT(complex),
  &STRUCT(fraction),
  &STRUCT(bigint),
  &STRUCT(bignum),
  &STRUCT(string),
  &STRUCT(bitset),
  &STRUCT(vector),
  &STRUCT(matrix),
  &STRUCT(bigmat),
  &STRUCT(dframe),
  &STRUCT(dict),
  &STRUCT(list),
  NULL
};

CGVTable STRUCT(NAME) = 
{
/*private:*/
#ifndef DATA_WITH_POINTER
  ID,                     /* cgraph_integer_t __type__; */
  sizeof(TYPE),           /* cgraph_size_t __size__;    */
  sizeof(TYPE *),         /* cgraph_size_t __psize__;   */
  sizeof(TYPE),           /* cgraph_size_t __msize__;   */
  sizeof(TYPE),           /* cgraph_size_t __dsize__;   */
  STRING(TYPE),           /* cgraph_char_t *__name__;   */
#else
  ID,                     /* cgraph_integer_t __type__; */
  sizeof(TYPE),           /* cgraph_size_t __size__;    */
  sizeof(TYPE *),         /* cgraph_size_t __psize__;   */
  sizeof(TYPE *),         /* cgraph_size_t __msize__;   */
  sizeof(DATA_TYPE),      /* cgraph_size_t __dsize__;   */
  STRING(TYPE),           /* cgraph_char_t *__name__;   */
#endif

/*public:*/
  FUNCTION(NAME, type),    /* cgraph_integer_t (*type)(void); */
  FUNCTION(NAME, size),    /* cgraph_size_t (*size)(void); */
  FUNCTION(NAME, psize),   /* cgraph_size_t (*psize)(void); */
  FUNCTION(NAME, msize),   /* cgraph_size_t (*msize)(void); */
  FUNCTION(NAME, dsize),   /* cgraph_size_t (*dsize)(void); */
  FUNCTION(NAME, name),    /* cgraph_char_t *(*name)(void); */
  FUNCTION(NAME, hasdata), /* cgraph_boolean_t (*hasdata)(void); */
  FUNCTION(NAME, calloc),  /* void *(*calloc)(const cgraph_type_t type, const cgraph_size_t size); */
  FUNCTION(NAME, realloc), /* void *FUNCTION(NAME, realloc)(void *cthis, const cgraph_size_t old_size, cgraph_size_t new_size, cgraph_boolean_t *error) */
  FUNCTION(NAME, free),    /* void *(*free)(void *cthis); */
  FUNCTION(NAME, copy),    /* void *(*copy)(const void *cthis, const cgraph_size_t size); */
  FUNCTION(NAME, hash)     /* cgraph_size_t (*hash)(const void *cthis); */
};

cgraph_type_t FUNCTION(NAME, type)(void)
{ return STRUCT(NAME).__type__; }

cgraph_size_t FUNCTION(NAME, size)(void)
{ return STRUCT(NAME).__size__; }

cgraph_size_t FUNCTION(NAME, psize)(void)
{ return STRUCT(NAME).__psize__; }

cgraph_size_t FUNCTION(NAME, msize)(void)
{ return STRUCT(NAME).__msize__; }

cgraph_size_t FUNCTION(NAME, dsize)(void)
{ return STRUCT(NAME).__dsize__; }

cgraph_char_t *FUNCTION(NAME, name)(void)
{ return STRUCT(NAME).__name__; }

cgraph_boolean_t FUNCTION(NAME, hasdata)(void)
{ return CGRAPH_TRUE; }

void *FUNCTION(NAME, calloc)(const cgraph_type_t type, const cgraph_size_t size)
{
  TYPE *cthis = (TYPE *)cgraph_calloc(1, sizeof(TYPE));
  if((CGRAPH_OBJECT_T != type) && (NULL != cthis))
  {
    if(type < CGRAPH_VECTOR_T)
    { cthis->data = CGRAPH_OBJECT(type, calloc)(type, size); }
    else
    { cthis->data = CGRAPH_OBJECT(type, calloc)(CGRAPH_OBJECT_T, size); }
    if(NULL != cthis->data)
    {
      cthis->type = type;
      #ifdef DEBUG
      fprintf(stdout, "CALLOC OBJECT TYPE : %d\n", type);
      #endif
    }
    else
    { cgraph_free(cthis); }
  }
  
  return cthis;
}

void *FUNCTION(NAME, realloc)(void *cthis, const cgraph_size_t old_size, cgraph_size_t new_size, cgraph_boolean_t *error)
{
  TYPE *object = (TYPE *)cthis;

  return object;
}

void *FUNCTION(NAME, copy)(const void *cthis, const cgraph_size_t size)
{
  TYPE *object = (TYPE *)cthis;

  return object;
}

void FUNCTION(NAME, free)(void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  if(NULL != object)
  {
    CGRAPH_OBJECT(object->type, free)(object->data);
    fprintf(stdout, "FREE OBJECT TYPE : %d\n", object->type);
    cgraph_free(object);
  }
}

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  return CGRAPH_OBJECT(object->type, hash)(object->data);
}

void *FUNCTION(NAME, data)(void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  return object->data;
}

void FUNCTION(TYPE, test)(void)
{
#ifdef DEBUG

#endif
}

#include "templete_off.h"
