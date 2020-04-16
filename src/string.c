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

/*                           string hash functions                            */
cgraph_size_t FUNCTION(NAME, jshash)(cgraph_string_t *str)
{
  cgraph_size_t hash = 1315423911, i;
  for(i=0; i<str->len; i++)
  { hash ^= ((hash << 5) + (hash >> 2) + str->data[i]); }

  return hash;
}

cgraph_size_t FUNCTION(NAME, sdbmhash)(cgraph_string_t *str)
{
  cgraph_size_t hash = 0, i;
  for(i=0; i<str->len; i++)
  { hash = ((hash << 6) + (hash << 16) + str->data[i] - hash); }
  return hash;
}

cgraph_size_t FUNCTION(NAME, rshash)(cgraph_string_t *str)
{
  cgraph_size_t hash = 0, a = 63689, b = 378551, i;
  for(i=0; i<str->len; i++)
  {
    hash = hash * a + str->data[i];
    a *= b;
  }

  return hash;
}

cgraph_size_t FUNCTION(NAME, elfhash)(cgraph_string_t *str)
{
  cgraph_size_t hash = 0, x =0, i;
  for(i=0; i<str->len; i++)
  {
    hash = (hash << 4) + str->data[i];
    if ((x = hash & 0xF0000000) != 0)
    {
      hash ^= (x >> 24);
      hash &= ~x;
    }
  }

  return hash;
}

cgraph_size_t FUNCTION(NAME, bkdrhash)(cgraph_string_t *str)
{
  cgraph_size_t hash = 0, i;
  for(i=0; i<str->len; i++)
  { hash = hash * 131 + str->data[i]; }

  return hash;
}

#include "templete_off.h"