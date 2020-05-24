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
    { fprintf(stderr, "FILE %s of LINE %d : memory length %ld is a negative number or equal to zero!\n", __FILE__, __LINE__, len); }
    if(0 >= data_size)
    { fprintf(stderr, "FILE %s of LINE %d : data size %ld is a negative number or equal to zero!\n", __FILE__, __LINE__, data_size); }
    fflush(stderr);
  }
#endif
  
  return object;
}

void *cgraph_realloc(void *cthis, const cgraph_size_t old_len, const cgraph_size_t new_len, const cgraph_size_t data_size, cgraph_boolean_t *error)
{
  void *object = NULL;
  if(NULL != error && NULL != cthis)
  {
    *error = CGRAPH_FALSE;
    if((0 < old_len) && (0 < data_size))
    {
      if(new_len > old_len)
      {
        object = realloc(cthis, (new_len+1)*data_size);
        if(NULL != object)
        {
          object = memset((char *)object+(old_len+1)*data_size, 0, (new_len-old_len)*data_size);
        }
      #ifdef DEBUG
        else
        {
          fflush(stdout);
          fprintf(stderr, "FILE %s of LINE %d : memory is re-allocated error, and the pointer is kept to the old one!\n", __FILE__, __LINE__);
          fflush(stderr);
          *error = CGRAPH_TRUE;
          object = cthis;
        }
      #endif
      }
    }
  #ifdef DEBUG
    else
    {
      fflush(stdout);
      if(0 >= old_len)
      { fprintf(stderr, "FILE %s of LINE %d : old length %ld is a negative number or equal to zero", __FILE__, __LINE__, old_len); }
      if(0 >= data_size)
      { fprintf(stderr, "FILE %s of LINE %d : data size %ld is a negative number or equal to zero", __FILE__, __LINE__, data_size); }
      fflush(stderr);
      *error = CGRAPH_TRUE;
    }
  #endif
  }
#ifdef DEBUG
  else
  {
    fflush(stdout);
    if(NULL == error)
    { fprintf(stderr, "FILE %s of LINE %d : error flag pointer is empty", __FILE__, __LINE__); }
    if(NULL == cthis)
    { fprintf(stderr, "FILE %s of LINE %d : object pointer is empty", __FILE__, __LINE__); }
    fflush(stderr);
    *error = CGRAPH_TRUE;
  }
#endif

  return object;
}

void *cgraph_memcpy(void *object, const void *cthis, const cgraph_size_t len, const cgraph_size_t data_size)
{
  void *result = NULL;
  if((NULL != object) && (NULL != cthis) && (0 < len) && (0 < data_size))
  {
    cgraph_size_t mem_len = len * data_size;
    if(0 < mem_len)
    { result = memcpy(object, cthis, mem_len); }
  }
#ifdef DEBUG
  else
  {
    fflush(stdout);
    if(NULL == object)
    { fprintf(stderr, "FILE %s of LINE %d : target pointer is empty\n", __FILE__, __LINE__); }
    if(NULL == cthis)
    { fprintf(stderr, "FILE %s of LINE %d : source pointer is empty;\n", __FILE__, __LINE__); }
    if(0 >= len)
    { fprintf(stderr, "FILE %s of LINE %d : length %ld is a negative number or equal to zero!\n", __FILE__, __LINE__, len); }
    if(0 >= data_size)
    { fprintf(stderr, "FILE %s of LINE %d : data size %ld is a negative number or equal to zero!\n", __FILE__, __LINE__, data_size); }
    fflush(stderr);
    result = object;
  }
#endif
  
  return result;
}

void *cgraph_strcpy(void *object, const void *cthis)
{
  void *result = NULL;
  if((NULL != object) && (NULL != cthis))
  { result = strcpy(object, cthis); }
#ifdef DEBUG
  else
  {
    fflush(stdout);
    if(NULL == object)
    { fprintf(stderr, "FILE %s of LINE %d : target pointer is empty\n", __FILE__, __LINE__); }
    if(NULL == cthis)
    { fprintf(stderr, "FILE %s of LINE %d : source pointer is empty;\n", __FILE__, __LINE__); }
    fflush(stderr);
    result = object;
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
    fprintf(stderr, "FILE %s of LINE %d : empty pointer is freed!\n", __FILE__, __LINE__);
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
    { fprintf(stderr, "FILE %s of LINE %d : target pointer is empty\n", __FILE__, __LINE__); }
    if(NULL == y)
    { fprintf(stderr, "FILE %s of LINE %d : source pointer is empty;\n", __FILE__, __LINE__); }
    if(0 >= len)
    { fprintf(stderr, "FILE %s of LINE %d : length %ld is a negative number or equal to zero!\n", __FILE__, __LINE__, len); }
    if(0 >= data_size)
    { fprintf(stderr, "FILE %s of LINE %d : data size %ld is a negative number or equal to zero!\n", __FILE__, __LINE__, data_size); }
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
    { fprintf(stderr, "FILE %s of LINE %d : target pointer is empty\n", __FILE__, __LINE__); }
    if(NULL == y)
    { fprintf(stderr, "FILE %s of LINE %d : source pointer is empty;\n", __FILE__, __LINE__); }
    fflush(stderr);
  }
#endif
  
  return flag;
}