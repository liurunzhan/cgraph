#include "cgraph_dict.h"
#include "cgraph_memory.h"

#define TYPE_DICT
#include "templete.h"
#include "struct.templete"

void *FUNCTION(NAME, calloc)(const cgraph_type_t type, const cgraph_size_t size)
{
  TYPE *cthis = (TYPE *)cgraph_calloc(1, sizeof(TYPE));
  if(NULL != cthis)
  {
    cthis->table = cgraph_calloc(size, sizeof(cgraph_dobject_t));
    if(NULL != cthis->table)
    { cthis->size = size; }
    else
    { cgraph_free(cthis); }
  }

  return cthis;
}

void *FUNCTION(NAME, realloc)(void *cthis, const cgraph_size_t old_size, cgraph_size_t new_size, cgraph_boolean_t *error)
{
  TYPE *object = (TYPE *)cthis;
  if((NULL != object) && (NULL != error))
  {
    object->table = cgraph_realloc(object->table, object->size, new_size, sizeof(cgraph_dobject_t), error);
    if(CGRAPH_FALSE == error)
    { object->size = new_size; }
  }

  return object;
}

void *FUNCTION(NAME, copy)(const void *cthis, const cgraph_size_t size)
{
  TYPE *object = (TYPE *)cthis;
  TYPE *copy_cthis = NULL;
  if(NULL != cthis)
  {
    copy_cthis = FUNCTION(NAME, calloc)(1, object->size);
    if(NULL != copy_cthis)
    {
      
    }
  }

  return copy_cthis;
}

void FUNCTION(NAME, free)(void *cthis)
{

}

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  return 0;
}

#include "templete_off.h"