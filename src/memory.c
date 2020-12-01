#include <stdlib.h>
#include <string.h>
#include "cgraph_error.h"
#include "cgraph_memory.h"

void *cgraph_calloc(const cgraph_size_t size)
{
  void *cthis = NULL;
  if(0 < size)
  { cthis = calloc(size, 1); }
#ifdef DEBUG
  else
  {
    fflush(stdout);
    if(0 >= size)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "memory size %ld is a negative number or equal to zero", size); }
    fflush(stderr);
  }
#endif
  
  return cthis;
}

void *cgraph_realloc(void *cthis, const cgraph_size_t old_size, const cgraph_size_t new_size, cgraph_bool_t *error)
{
  void *_cthis = cthis;
  if(NULL != error)
  {
    *error = CGRAPH_FALSE;
    /** memory lazy release */
    if(new_size > old_size)
    {
      _cthis = realloc(cthis, new_size);
      if(NULL != _cthis)
      { _cthis = memset((cgraph_addr8_t *)_cthis+old_size, 0, (new_size-old_size)); }
      else
      {
      #ifdef DEBUG
        fflush(stdout);
        cgraph_error_log(stderr, __FILE__, __LINE__, "memory is re-allocated error, and the pointer is kept to the old one");
        fflush(stderr);
      #endif
        _cthis = cthis;
        *error = CGRAPH_TRUE;
      }
    }
  }
#ifdef DEBUG
  else
  {
    fflush(stdout);
    cgraph_error_log(stderr, __FILE__, __LINE__, "error flag pointer is empty");
    fflush(stderr);
  }
 #endif

  return _cthis;
}

void *cgraph_memcpy(void *object, const void *cthis, const cgraph_size_t size)
{
  void *_object = object;
  if((NULL != object) && (NULL != cthis) && (object != cthis) && (0 < size))
  { _object = memcpy(object, cthis, size); }
#ifdef DEBUG
  else
  {
    fflush(stdout);
    if(NULL == object)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "target pointer is empty"); }
    if(NULL == cthis)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "source pointer is empty"); }
    if(object == cthis)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "source pointer is equal to target pointer"); }
    if(0 >= size)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "memory size %ld is a negative number or equal to zero", size); }
    fflush(stderr);
  }
#endif
  
  return _object;
}

void *cgraph_strcpy(void *object, const void *cthis)
{
  void *_object = object;
  if((NULL != object) && (NULL != cthis) && (object != cthis))
  { _object = strcpy(object, cthis); }
#ifdef DEBUG
  else
  {
    fflush(stdout);
    if(NULL == object)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "target pointer is empty"); }
    if(NULL == cthis)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "source pointer is empty"); }
    if(object == cthis)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "source pointer is equal to target pointer"); }
    fflush(stderr);
  }
#endif
  
  return _object;
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

cgraph_bool_t cgraph_memcmp(const void *x, const void *y, const cgraph_size_t size)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if(x == y)
  { flag = CGRAPH_TRUE; }
  else if((NULL != x) && (NULL != y) && (0 < size))
  {
    if(0 == memcmp(x, y, size))
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
    if(0 >= size)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "length %ld is a negative number or equal to zero", size); }
    fflush(stderr);
  }
#endif
  
  return flag;
}

cgraph_bool_t cgraph_strcmp(const char *x, const char *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
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
