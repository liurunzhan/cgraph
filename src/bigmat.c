#include "cgraph_memory.h"
#include "cgraph_object.h"
#include "cgraph_bigmat.h"

#define TYPE_BIGMAT
#include "templete.h"
#include "struct_base.ct"

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

}

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t hash = 0;

  return hash;
}

#include "templete_off.h"
