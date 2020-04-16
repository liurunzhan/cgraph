#include "cgraph_memory.h"
#include "cgraph_time.h"

#define TYPE_TIME
#include "templete.h"
// #include "data.templete"

TYPE FUNCTION(NAME, initc)(cgraph_char_t *cthis, const cgraph_char_t *sep)
{
  TYPE res;

  return res;
}

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t hash1, hash2;
  hash1 = object->data[0] << 13 + object->data[1] << 7 + object->data[2];
  hash2 = object->data[3] << 12 + object->data[4] << 4 + object->data[5];
  return hash1 ^ hash2;
}

#include "templete_off.h"