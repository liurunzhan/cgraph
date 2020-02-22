#include "cgraph_htable.h"
#include "cgraph_memory.h"

#define TYPE_HTABLE
#include "templete.h"
#include "struct.templete"

void *FUNCTION(NAME, calloc)(const cgraph_type_t type, const cgraph_size_t size)
{

}

void *FUNCTION(NAME, realloc)(void *cthis, const cgraph_size_t old_size, cgraph_size_t new_size, cgraph_boolean_t *error)
{

}

void *FUNCTION(NAME, copy)(const void *cthis, const cgraph_size_t size)
{

}

void FUNCTION(NAME, free)(void *cthis)
{

}

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  return 0;
}

#include "templete_off.h"