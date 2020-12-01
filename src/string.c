#include <stdio.h>
#include <string.h>
#include "cgraph_memory.h"
#include "cgraph_string.h"

#define TYPE_STRING
#include "templete.h"
#include "data_base.ct"

/* 
  times 33 hash algorithm proposed by Daniel J. Bernstein  
  hash = hash * 33 + cthis->data[i]
  or
  hash = hash + hash << 5 + cthis->data[i]
  or
  hash += hash << 5 + cthis->data[i]
*/
cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *_cthis = (TYPE *)cthis;
  cgraph_size_t hash = 0, i;
  for(i=0; i<_cthis->len; i++)
  { hash += (hash << 5) + _cthis->data[i]; }
  
  return hash;
}

cgraph_bool_t FUNCTION(NAME, equal)(const void *x, const void *y)
{
  TYPE *_x = (TYPE *)x, *_y = (TYPE *)y;
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((NULL != _x) && (NULL != _y))
  {
    flag = cgraph_strcmp(_x->data, _y->data);
  }

  return flag;
}

/*                           string hash functions                            */
cgraph_size_t FUNCTION(NAME, jshash)(const TYPE *cthis)
{
  cgraph_size_t hash = 1315423911, i;
  for(i=0; i<cthis->len; i++)
  { hash ^= ((hash << 5) + (hash >> 2) + cthis->data[i]); }

  return hash;
}

cgraph_size_t FUNCTION(NAME, sdbmhash)(const TYPE *cthis)
{
  cgraph_size_t hash = 0, i;
  for(i=0; i<cthis->len; i++)
  { hash = ((hash << 6) + (hash << 16) + cthis->data[i] - hash); }
  return hash;
}

cgraph_size_t FUNCTION(NAME, rshash)(const TYPE *cthis)
{
  cgraph_size_t hash = 0, a = 63689, b = 378551, i;
  for(i=0; i<cthis->len; i++)
  {
    hash = hash * a + cthis->data[i];
    a *= b;
  }

  return hash;
}

cgraph_size_t FUNCTION(NAME, elfhash)(const TYPE *cthis)
{
  cgraph_size_t hash = 0, x =0, i;
  for(i=0; i<cthis->len; i++)
  {
    hash = (hash << 4) + cthis->data[i];
    if ((x = hash & 0xF0000000) != 0)
    {
      hash ^= (x >> 24);
      hash &= ~x;
    }
  }

  return hash;
}

cgraph_size_t FUNCTION(NAME, bkdrhash)(const TYPE *cthis)
{
  cgraph_size_t hash = 0, i;
  for(i=0; i<cthis->len; i++)
  { hash = hash * 131 + cthis->data[i]; }

  return CGRAPH_ABS(hash);
}

TYPE *FUNCTION(NAME, initf)(TYPE *cthis, const cgraph_char_t *format, ...)
{
  cgraph_size_t len;
  if((NULL != cthis) && (NULL != format))
  {
    va_list args;
    va_start(args, format);
  #if (CGRAPH_STDC_VERSION >= 199901L)
    len = vsnprintf(cthis->data, cthis->size, format, args);
  #else
    len = vsprintf(cthis->data, format, args);
  #endif
    va_end(args);
    if(0 < len)
    { cthis->len = len; }
  }

  return cthis;
}


TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z)
{
  return z;
}

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z)
{
  return z;
}

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z)
{
  return z;
}

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z)
{
  return z;
}

TYPE *FUNCTION(NAME, abs)(TYPE *cthis)
{
  return cthis;
}

TYPE *FUNCTION(NAME, format)(TYPE *cthis)
{
  return cthis;
}

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if(NULL != x && NULL != y)
  {
    if(x->len == y->len)
    {
      cgraph_size_t i;
      for(i=0; i<x->len; i++)
      {
        if(x->data[i] != y->data[i])
        { break; }
      }
      if(i >= x->len)
      { flag = CGRAPH_TRUE; }
    }
  }
  else if(NULL == x && NULL == y)
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ne)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if(NULL != x && NULL != y)
  {
    if(x->len == y->len)
    {
      cgraph_size_t i;
      for(i=0; i<x->len; i++)
      {
        if(x->data[i] == y->data[i])
        { break; }
      }
      if(i >= x->len)
      { flag = CGRAPH_TRUE; }
    }
  }
  else if(NULL == x && NULL == y)
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, gr)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if(NULL != x && NULL != y)
  {
    if(x->len == y->len)
    {
      cgraph_size_t i;
      for(i=0; i<x->len; i++)
      {
        if(x->data[i] <= y->data[i])
        { break; }
      }
      if(i >= x->len)
      { flag = CGRAPH_TRUE; }
    }
  }
  else if(NULL != x && NULL == y)
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ge)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if(NULL != x && NULL != y)
  {
    if(x->len == y->len)
    {
      cgraph_size_t i;
      for(i=0; i<x->len; i++)
      {
        if(x->data[i] < y->data[i])
        { break; }
      }
      if(i >= x->len)
      { flag = CGRAPH_TRUE; }
    }
  }
  else if(NULL == y)
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ls)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if(NULL != x && NULL != y)
  {
    if(x->len == y->len)
    {
      cgraph_size_t i;
      for(i=0; i<x->len; i++)
      {
        if(x->data[i] >= y->data[i])
        { break; }
      }
      if(i >= x->len)
      { flag = CGRAPH_TRUE; }
    }
  }
  else if(NULL == y)
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, le)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if(NULL != x && NULL != y)
  {
    if(x->len == y->len)
    {
      cgraph_size_t i;
      for(i=0; i<x->len; i++)
      {
        if(x->data[i] > y->data[i])
        { break; }
      }
      if(i >= x->len)
      { flag = CGRAPH_TRUE; }
    }
  }
  else if(NULL == y)
  { flag = CGRAPH_TRUE; }

  return flag;
}

void FUNCTION(NAME, test)(void)
{
#ifdef DEBUG
  TYPE *string = FUNCTION(NAME, calloc)(ID, 10000);
  char *str = "hello world!";
  fprintf(stdout, "test %s\n", STRING(NAME));
  if(NULL != string)
  { printf("hello!\n"); }
  FUNCTION(NAME, initd)(string, str, strlen(str)+1);
  fprintf(stdout, "%s\n", string->data);

  FUNCTION(NAME, free)(string);
#endif
}

#include "templete_off.h"
