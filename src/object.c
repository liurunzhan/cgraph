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
  &STRUCT(complex),
  &STRUCT(fraction),
  &STRUCT(bigint),
  &STRUCT(bignum),
  &STRUCT(string),
  &STRUCT(vector),
  &STRUCT(matrix),
  &STRUCT(bigmat),
  &STRUCT(dframe),
  &STRUCT(htable),
  &STRUCT(list),
  NULL
};

CGVTable STRUCT(NAME) = 
{
/*private:*/
#ifndef DATA_WITH_POINTER
  ID,                     /* cgraph_integer_t __type__; */
  sizeof(TYPE),           /* cgraph_size_t __size__;    */
  sizeof(TYPE),           /* cgraph_size_t __msize__;   */
  sizeof(TYPE),           /* cgraph_size_t __dsize__;   */
  STRING(TYPE),           /* cgraph_char_t *__name__;   */
#else
  ID,                     /* cgraph_integer_t __type__; */
  sizeof(TYPE),           /* cgraph_size_t __size__;    */
  sizeof(TYPE *),         /* cgraph_size_t __msize__;   */
  sizeof(DATA_TYPE),      /* cgraph_size_t __dsize__;   */
  STRING(TYPE),           /* cgraph_char_t *__name__;   */
#endif

/*public:*/
  FUNCTION(NAME, type),   /* cgraph_integer_t (*type)(void); */
  FUNCTION(NAME, size),   /* cgraph_size_t (*size)(void); */
  FUNCTION(NAME, msize),  /* cgraph_size_t (*msize)(void); */
  FUNCTION(NAME, dsize),  /* cgraph_size_t (*dsize)(void); */
  FUNCTION(NAME, name),   /* cgraph_char_t *(*name)(void); */
  FUNCTION(NAME, calloc), /* void *(*calloc)(const cgraph_type_t type, const cgraph_size_t size); */
  FUNCTION(NAME, free),   /* void *(*free)(void *gthis); */
  FUNCTION(NAME, copy),   /* void *(*copy)(const void *cthis, const cgraph_size_t size); */
  FUNCTION(NAME, hash)    /* cgraph_size_t (*hash)(const void *cthis); */
};

cgraph_type_t FUNCTION(NAME, type)(void)
{
  return STRUCT(NAME).__type__;
}

cgraph_size_t FUNCTION(NAME, size)(void)
{
  return STRUCT(NAME).__size__;
}

cgraph_size_t FUNCTION(NAME, msize)(void)
{
  return STRUCT(NAME).__msize__;
}

cgraph_size_t FUNCTION(NAME, dsize)(void)
{
  return STRUCT(NAME).__dsize__;;
}

cgraph_char_t *FUNCTION(NAME, name)(void)
{
  return STRUCT(NAME).__name__;
}

void *FUNCTION(NAME, calloc)(const cgraph_type_t type, const cgraph_size_t size)
{
  TYPE *cthis = NULL;
  cthis = (TYPE *)cgraph_calloc(size, sizeof(TYPE));
  if((CGRAPH_OBJECT_T != type) && (NULL != cthis))
  {
    if(type < CGRAPH_VECTOR_T)
    { cthis->data = CGRAPH_OBJECT(type)->calloc(type, 1); }
    else
    { cthis->data = CGRAPH_OBJECT(type)->calloc(CGRAPH_OBJECT_T, size); }
    if(NULL != cthis->data)
    { cthis->type = type;
      fprintf(stdout, "CALLOC OBJECT TYPE : %d\n", type);
    }
    else
    { cgraph_free(cthis); }
  }
  
  return cthis;
}

void *FUNCTION(NAME, realloc)(void *cthis, const cgraph_size_t old_size, cgraph_size_t new_size, cgraph_boolean_t *error)
{
  TYPE *new_cthis = (TYPE *)cthis;

  return new_cthis;
}

void *FUNCTION(NAME, copy)(const void *cthis, const cgraph_size_t size)
{
  TYPE *new_cthis = (TYPE *)cthis;

  return new_cthis;
}

void FUNCTION(NAME, free)(void *cthis)
{
  TYPE *new_this = (TYPE *)cthis;
  if(NULL != new_this)
  {
    CGRAPH_OBJECT(new_this->type)->free(new_this->data);
    fprintf(stdout, "FREE OBJECT TYPE : %d\n", new_this->type);
    cgraph_free(new_this);
  }
}

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *new_this = (TYPE *)cthis;
  return CGRAPH_OBJECT(new_this->type)->hash(new_this->data);
}

void *FUNCTION(NAME, data)(void *cthis)
{
  TYPE *new_cthis = (TYPE *)cthis;
  return new_cthis->data;
}

#include "templete_off.h"