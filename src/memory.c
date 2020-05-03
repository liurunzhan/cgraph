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
  void *object = NULL;
  if(NULL != error && NULL != cthis)
  {
    *error = CGRAPH_FALSE;
    if(old_len > 0 && data_size > 0)
    {
      if(new_len > old_len)
      {
        object = realloc(cthis, (new_len+1)*data_size);
        if(NULL != object)
        {
          object = memset((char *)object+(old_len+1)*data_size, 0, (new_len-old_len)*data_size);
        }
        else
        {
          *error = CGRAPH_TRUE;
          object = cthis;
        }
      }
    }
    else
    { *error = CGRAPH_TRUE; }
  }

  return object;
}

void *cgraph_memcpy(void *object, const void *cthis, const cgraph_size_t len, const cgraph_size_t data_size)
{
  return (NULL != object && NULL != cthis && len > 0 && data_size > 0) ? memcpy(object, cthis, len*data_size) : object;
}

void cgraph_free(void *cthis)
{
  if(NULL != cthis)
  {
    free(cthis);
    cthis = NULL;
  }
}