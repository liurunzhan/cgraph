#include <string.h>
#include "cgraph_memory.h"
#include "cgraph_time.h"

#define TYPE_TIME
#include "templete.h"
/* #include "data.templete" */

TYPE FUNCTION(NAME, initc)(cgraph_char_t *cthis, const cgraph_char_t *sep)
{
  TYPE res;
  if((NULL != cthis) && (NULL != sep))
  {
    char *object = cgraph_calloc(strlen(cthis), sizeof(char));
    if(NULL != object)
    {
      
    }
  }

  return res;
}

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;
  cgraph_size_t hash1, hash2;
  hash1 = (CGRAPH_YEAR(object) << 13) + (CGRAPH_MONTH(object) << 7) + CGRAPH_DAY(object);
  hash2 = (CGRAPH_HOUR(object) << 12) + (CGRAPH_MINUTE(object) << 4) + CGRAPH_SECOND(object);
  return hash1 ^ hash2;
}

cgraph_boolean_t FUNCTION(NAME, test)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;
  cgraph_boolean_t flag = CGRAPH_TRUE;
  if((0 > CGRAPH_MONTH(object)) || (12 < CGRAPH_MONTH(object)))
  { flag = CGRAPH_FALSE; }
  else if((0 > CGRAPH_DAY(object)) || (31 < CGRAPH_DAY(object)))
  { flag = CGRAPH_FALSE; }
  else if((0 > CGRAPH_HOUR(object)) || (24 < CGRAPH_HOUR(object)))
  { flag = CGRAPH_FALSE; }
  else if((0 > CGRAPH_MINUTE(object)) || (60 < CGRAPH_MINUTE(object)))
  { flag = CGRAPH_FALSE; }
  else if((0 > CGRAPH_SECOND(object)) || (60 < CGRAPH_SECOND(object)))
  { flag = CGRAPH_FALSE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, equal)(const void *x, const void *y)
{
  TYPE *object_x = (TYPE *)x, *object_y = (TYPE *)y;
  cgraph_boolean_t flag = CGRAPH_TRUE;
  cgraph_integer_t i;
  for(i=0; i<6; i++)
  {
    if(object_x->data[i] != object_y->data[i])
    {
      flag = CGRAPH_FALSE;
      break;
    }
  }

  return flag;
}

#include "templete_off.h"