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
  TYPE *object = (TYPE *)cthis;
  if(NULL != object && NULL != error)
  {
    *error = CGRAPH_FALSE;
    object->data = CGRAPH_OBJECT(object->type, realloc)(object->data, object->size, new_size, error);
    object->size = CGRAPH_TRUE != *error ? new_size : object->size;
  }

  return object;
}

void *FUNCTION(NAME, copy)(const void *cthis, const cgraph_size_t size)
{
  TYPE *object = (TYPE *)cthis;
  TYPE *copy_cthis;
  if(NULL != object)
  {
    copy_cthis = cgraph_calloc(1, sizeof(TYPE));
    if(NULL != copy_cthis)
    {
      copy_cthis->data = CGRAPH_OBJECT(object->type, copy)(object->data, object->size);
      if(NULL != copy_cthis->data)
      {
        copy_cthis->len = object->len;
        copy_cthis->size = object->size;
        copy_cthis->type = object->type;
        copy_cthis->with_hash = object->with_hash;
      }
      else
      { cgraph_free(copy_cthis); }
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
     CGRAPH_OBJECT(object->type, free)(object->data);
   }
   
   cgraph_free(object);
}

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  return 0;
}

void *FUNCTION(NAME, add)(const void *x, const void *y)
{

}

#include "templete_off.h"