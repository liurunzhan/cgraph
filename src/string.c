#include <stdarg.h>
#include "cgraph_memory.h"
#include "cgraph_string.h"

#define TYPE_STRING
#include "templete.h"
#include "data.templete"

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
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t hash = 0, i;
  for(i=0; i<object->len; i++)
  { hash += (hash << 5) + object->data[i]; }
  
  return hash;
}

cgraph_boolean_t FUNCTION(NAME, equal)(const void *x, const void *y)
{
  TYPE *object_x = (TYPE *)x, *object_y = (TYPE *)y;
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if((NULL != object_x) && (NULL != object_y))
  {
    flag = cgraph_strcmp(object_x->data, object_y->data);
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
    len = vsnprintf(cthis->data, cthis->size, format, args);
    va_end(args);
    if(0 < len)
    { cthis->len = len; }
  }

  return cthis;
}

#include "templete_off.h"
