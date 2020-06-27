#include <string.h>
#include <time.h>
#include "cgraph_memory.h"
#include "cgraph_time.h"

#define TYPE_TIME
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;
  cgraph_size_t hash1, hash2;
  hash1 = (CGRAPH_YEAR(object) << 13) + (CGRAPH_MONTH(object) << 7) + CGRAPH_DAY(object);
  hash2 = (CGRAPH_HOUR(object) << 12) + (CGRAPH_MINUTE(object) << 4) + CGRAPH_SECOND(object);
  return CGRAPH_ABS(hash1 ^ hash2);
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

cgraph_boolean_t FUNCTION(NAME, eq)(const TYPE x, const TYPE y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(
      (CGRAPH_YEAR(x) == CGRAPH_YEAR(y)) && 
      (CGRAPH_MONTH(x) == CGRAPH_MONTH(y)) && 
      (CGRAPH_DAY(x) == CGRAPH_DAY(y)) && 
      (CGRAPH_HOUR(x) == CGRAPH_HOUR(y)) && 
      (CGRAPH_MINUTE(x) == CGRAPH_MINUTE(y)) && 
      (CGRAPH_SECOND(x) == CGRAPH_SECOND(y))
    )
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, gr)(const TYPE x, const TYPE y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(
    (CGRAPH_YEAR(x) > CGRAPH_YEAR(y)) || 
    (CGRAPH_MONTH(x) > CGRAPH_MONTH(y)) || 
    (CGRAPH_DAY(x) > CGRAPH_DAY(y)) || 
    (CGRAPH_HOUR(x) > CGRAPH_HOUR(y)) || 
    (CGRAPH_MINUTE(x) > CGRAPH_MINUTE(y)) || 
    (CGRAPH_SECOND(x) > CGRAPH_SECOND(y))
  )
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, ge)(const TYPE x, const TYPE y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(
    (CGRAPH_YEAR(x) >= CGRAPH_YEAR(y)) || 
    (CGRAPH_MONTH(x) >= CGRAPH_MONTH(y)) || 
    (CGRAPH_DAY(x) >= CGRAPH_DAY(y)) || 
    (CGRAPH_HOUR(x) >= CGRAPH_HOUR(y)) || 
    (CGRAPH_MINUTE(x) >= CGRAPH_MINUTE(y)) || 
    (CGRAPH_SECOND(x) >= CGRAPH_SECOND(y))
    )
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, ls)(const TYPE x, const TYPE y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(
    (CGRAPH_YEAR(x) < CGRAPH_YEAR(y)) || 
    (CGRAPH_MONTH(x) < CGRAPH_MONTH(y)) || 
    (CGRAPH_DAY(x) < CGRAPH_DAY(y)) || 
    (CGRAPH_HOUR(x) < CGRAPH_HOUR(y)) || 
    (CGRAPH_MINUTE(x) < CGRAPH_MINUTE(y)) || 
    (CGRAPH_SECOND(x) < CGRAPH_SECOND(y))
    )
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, le)(const TYPE x, const TYPE y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(
    (CGRAPH_YEAR(x) <= CGRAPH_YEAR(y)) || 
    (CGRAPH_MONTH(x) <= CGRAPH_MONTH(y)) || 
    (CGRAPH_DAY(x) <= CGRAPH_DAY(y)) || 
    (CGRAPH_HOUR(x) <= CGRAPH_HOUR(y)) || 
    (CGRAPH_MINUTE(x) <= CGRAPH_MINUTE(y)) || 
    (CGRAPH_SECOND(x) <= CGRAPH_SECOND(y))
    )
  { flag = CGRAPH_TRUE; }

  return flag;
}

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

TYPE FUNCTION(NAME, localtime)(void)
{
  TYPE res;
  time_t current_time;
  struct tm *pt;
  time(&current_time);
  pt = localtime(&current_time);
  CGRAPH_YEAR(res) = pt->tm_year;
  CGRAPH_MONTH(res) = pt->tm_mon;
  CGRAPH_DAY(res) = pt->tm_mday;
  CGRAPH_HOUR(res) = pt->tm_hour;
  CGRAPH_MINUTE(res) = pt->tm_min;
  CGRAPH_SECOND(res) = pt->tm_sec;

  return res;
}

TYPE FUNCTION(NAME, addi)(const TYPE x, const DATA_TYPE y)
{

}

TYPE FUNCTION(NAME, subi)(const TYPE x, const DATA_TYPE y)
{
  
}

TYPE FUNCTION(NAME, muli)(const TYPE x, const DATA_TYPE y)
{
  
}

TYPE FUNCTION(NAME, divi)(const TYPE x, const DATA_TYPE y)
{
  
}

TYPE FUNCTION(NAME, addt)(const TYPE x, const TYPE y)
{

}

TYPE FUNCTION(NAME, subt)(const TYPE x, const TYPE y)
{
  
}

TYPE FUNCTION(NAME, mult)(const TYPE x, const TYPE y)
{
  
}

TYPE FUNCTION(NAME, divt)(const TYPE x, const TYPE y)
{
  
}

#include "templete_off.h"
