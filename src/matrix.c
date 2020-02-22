#include "cgraph_matrix.h"
#include "cgraph_memory.h"

#define TYPE_MATRIX
#include "templete.h"
#include "struct.templete"

void *FUNCTION(NAME, calloc)(const cgraph_type_t type, const cgraph_size_t size)
{
  TYPE *cthis = (TYPE *)cgraph_calloc(1, sizeof(TYPE));
  if(NULL != cthis)
  {
    cthis->data = CGRAPH_OBJECT(type, calloc)(type, size);
    if(NULL != cthis->data)
    { cthis->size = size; }
    else
    { cgraph_free(cthis); }
  }

  return cthis;
}

void *FUNCTION(NAME, realloc)(void *cthis, const cgraph_size_t old_size, cgraph_size_t new_size, cgraph_boolean_t *error)
{
  TYPE *new_cthis = (TYPE *)cthis;
  if(NULL != new_cthis && NULL != error)
  {
    *error = CGRAPH_FALSE;
    new_cthis->data = cgraph_realloc(new_cthis->data, new_cthis->size, new_size, 1, error);
    new_cthis->size = CGRAPH_TRUE != *error ? new_size : new_cthis->size;
  }

  return new_cthis;
}

void *FUNCTION(NAME, copy)(const void *cthis, const cgraph_size_t size)
{
  TYPE *new_cthis = NULL;

  return new_cthis;
}

void FUNCTION(NAME, free)(void *cthis)
{
   TYPE *new_cthis = (TYPE *)cthis;
   cgraph_size_t i;
   for(i=0; i<new_cthis->size; i++)
   {

   }
   
   cgraph_free(new_cthis);
}

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  return 0;
}

#include "templete_off.h"