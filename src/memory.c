#include <stdlib.h>
#include <string.h>
#include "cgraph_error.h"
#include "cgraph_memory.h"

void *cgraph_calloc(const cgraph_size_t len, const cgraph_size_t data_size)
{
  void *object = NULL;
  if((0 < len) && (0 < data_size))
  { object = calloc(len+1, data_size); }
#ifdef DEBUG
  else
  {
    fflush(stdout);
    if(0 >= len)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "memory length %ld is a negative number or equal to zero", len); }
    if(0 >= data_size)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "data size %ld is a negative number or equal to zero", data_size); }
    fflush(stderr);
  }
#endif
  
  return object;
}

void *cgraph_realloc(void *cthis, const cgraph_size_t old_len, const cgraph_size_t new_len, const cgraph_size_t data_size, cgraph_boolean_t *error)
{
  void *object = cthis;
  if(NULL != error && NULL != cthis)
  {
    *error = CGRAPH_FALSE;
    if((0 < old_len) && (0 < data_size))
    {
      if(new_len > old_len)
      {
        object = realloc(cthis, (new_len+1)*data_size);
        if(NULL != object)
        { object = memset((char *)object+(old_len*data_size), 0, (new_len-old_len+1)*data_size); }
        else
        {
        #ifdef DEBUG
          fflush(stdout);
          cgraph_error_log(stderr, __FILE__, __LINE__, "memory is re-allocated error, and the pointer is kept to the old one");
          fflush(stderr);
        #endif
          *error = CGRAPH_TRUE;
        }
      }
    }
    else
    {
    #ifdef DEBUG
      fflush(stdout);
      if(0 >= old_len)
      { cgraph_error_log(stderr, __FILE__, __LINE__, "old length %ld is a negative number or equal to zero", old_len); }
      if(0 >= data_size)
      { cgraph_error_log(stderr, __FILE__, __LINE__, "data size %ld is a negative number or equal to zero", data_size); }
      fflush(stderr);
    #endif
      *error = CGRAPH_TRUE;
    }
  }
  else
  {
  #ifdef DEBUG
    fflush(stdout);
    if(NULL == error)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "error flag pointer is empty"); }
    if(NULL == cthis)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "object pointer is empty"); }
    fflush(stderr);
  #endif
    if(NULL != error)
    { *error = CGRAPH_TRUE; }
  }

  return object;
}

void *cgraph_memcpy(void *object, const void *cthis, const cgraph_size_t len, const cgraph_size_t data_size)
{
  void *result = object;
  if((NULL != object) && (NULL != cthis) && (0 < len) && (0 < data_size))
  {
    cgraph_size_t mem_len = len * data_size;
    if(0 < mem_len)
    { result = memcpy(object, cthis, mem_len); }
  #ifdef DEBUG
    else
    {
      fflush(stdout);
      cgraph_error_log(stderr, __FILE__, __LINE__, "copy %ldx%ld memory error", len, data_size);
      fflush(stderr);
    }
  #endif
  }
#ifdef DEBUG
  else
  {
    fflush(stdout);
    if(NULL == object)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "target pointer is empty"); }
    if(NULL == cthis)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "source pointer is empty"); }
    if(0 >= len)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "length %ld is a negative number or equal to zero", len); }
    if(0 >= data_size)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "data size %ld is a negative number or equal to zero", data_size); }
    fflush(stderr);
  }
#endif
  
  return result;
}

void *cgraph_strcpy(void *object, const void *cthis)
{
  void *result = object;
  if((NULL != object) && (NULL != cthis))
  { result = strcpy(object, cthis); }
#ifdef DEBUG
  else
  {
    fflush(stdout);
    if(NULL == object)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "target pointer is empty"); }
    if(NULL == cthis)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "source pointer is empty"); }
    fflush(stderr);
  }
#endif
  
  return result;
}

void cgraph_free(void *cthis)
{
  if(NULL != cthis)
  {
    free(cthis);
    cthis = NULL;
  }
#ifdef DEBUG
  else
  {
    fflush(stdout);
    cgraph_error_log(stderr, __FILE__, __LINE__, "empty pointer is freed");
    fflush(stderr);
  }
#endif
}

cgraph_boolean_t cgraph_memcmp(const void *x, const void *y, const cgraph_size_t len, const cgraph_size_t data_size)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(x == y)
  { flag = CGRAPH_TRUE; }
  else if((NULL != x) && (NULL != y) && (0 < len) && (0 < data_size))
  {
    cgraph_size_t mem_len = len * data_size;
    if((0 < mem_len) && (0 == memcmp(x, y, mem_len)))
    { flag = CGRAPH_TRUE; }
  }
#ifdef DEBUG
  else
  {
    fflush(stdout);
    if(NULL == x)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "target pointer is empty"); }
    if(NULL == y)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "source pointer is empty"); }
    if(0 >= len)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "length %ld is a negative number or equal to zero", len); }
    if(0 >= data_size)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "data size %ld is a negative number or equal to zero", data_size); }
    fflush(stderr);
  }
#endif
  
  return flag;
}

cgraph_boolean_t cgraph_strcmp(const char *x, const char *y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if(0 == strcmp(x, y))
    { flag = CGRAPH_TRUE; }
  }
#ifdef DEBUG
  else
  {
    fflush(stdout);
    if(NULL == x)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "target pointer is empty\n"); }
    if(NULL == y)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "source pointer is empty"); }
    fflush(stderr);
  }
#endif
  
  return flag;
}
