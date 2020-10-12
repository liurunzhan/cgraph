#include "cgraph_matrix.h"
#include "cgraph_memory.h"

#define TYPE_MATRIX
#include "templete.h"
#include "struct_base.ct"

void *FUNCTION(NAME, calloc)(const cgraph_type_t type, const cgraph_size_t size)
{
  TYPE *cthis = (TYPE *)cgraph_calloc(1, sizeof(TYPE));
  if(NULL != cthis)
  {
    cthis->data = cgraph_calloc(size, CGRAPH_OBJECT(type, dsize)());
    if(NULL != cthis->data)
    {
      cthis->size = size; 
      cthis->type = type;
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
  if(NULL != object)
  {
    cgraph_size_t i;
    for(i=0; i<object->size; i++)
    {  }
    cgraph_free(object->data);
    cgraph_free(object);
  }
}

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t i, hash;
  

  return hash;
}

void FUNCTION(TYPE, test)(void)
{
#ifdef DEBUG

#endif
}

#include "templete_off.h"
