#include "cgraph_sobject.h"
#include "cgraph_memory.h"
#include "cgraph_error.h"

#include "cgraph_data.h"

#define TYPE_SOBJECT
#include "templete.h"

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

#include "object_base.ct"

void FUNCTION(TYPE, test)(void)
{
#ifdef DEBUG

#endif
}

#include "templete_off.h"