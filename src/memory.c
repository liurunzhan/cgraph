#include <stdlib.h>
#include <string.h>
#include "cgraph_error.h"
#include "cgraph_memory.h"

void *cgraph_calloc(const cgraph_size_t len, const cgraph_size_t data_size)
{
  return len > 0 && data_size > 0 ? calloc(len+1, data_size) : NULL;
}

void *cgraph_realloc(void *cthis, const cgraph_size_t old_len, const cgraph_size_t new_len, const cgraph_size_t data_size, cgraph_boolean_t *error)
{
  void *new_cthis = NULL;
  if(NULL != error && NULL != cthis)
  {
    *error = CGRAPH_FALSE;
    if(old_len > 0 && data_size > 0)
    {
      if(new_len > old_len)
      {
        new_cthis = realloc(cthis, (new_len+1)*data_size);
        new_cthis = NULL == new_cthis ? (*error = CGRAPH_TRUE, cthis) : memset((char *)new_cthis+(old_len+1)*data_size, 0, (new_len-old_len)*data_size);
      }
    }
    else
    { *error = CGRAPH_TRUE; }
  }

  return new_cthis;
}

void *cgraph_memcpy(void *new_cthis, const void *cthis, const cgraph_size_t len, const cgraph_size_t data_size)
{
  return (NULL != new_cthis && NULL != cthis && len > 0 && data_size > 0) ? memcpy(new_cthis, cthis, len*data_size) : new_cthis;
}

void cgraph_free(void *cthis)
{
  if(NULL != cthis)
  {
    free(cthis);
    cthis = NULL;
  }
}