#include <string.h>
#include <time.h>
#include "cgraph_memory.h"
#include "cgraph_time.h"

#define TYPE_TIME
#include "templete.h"
#include "data_base.ct"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;
  cgraph_size_t hash = (CGRAPH_YEAR(object) << 13) + (CGRAPH_MONTH(object) << 7) + CGRAPH_DAY(object);
  return CGRAPH_ABS(hash);
}

cgraph_boolean_t FUNCTION(NAME, check)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;
  cgraph_boolean_t flag = CGRAPH_TRUE;
  if((0 > CGRAPH_MONTH(object)) || (12 < CGRAPH_MONTH(object)))
  { flag = CGRAPH_FALSE; }
  else if((0 > CGRAPH_DAY(object)) || (31 < CGRAPH_DAY(object)))
  { flag = CGRAPH_FALSE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, equal)(const void *x, const void *y)
{
  TYPE *object_x = (TYPE *)x, *object_y = (TYPE *)y;
  cgraph_boolean_t flag = CGRAPH_TRUE;
  if(object_x != object_y)
  { flag = CGRAPH_FALSE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, eq)(const TYPE x, const TYPE y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(CGRAPH_TIME(x) == CGRAPH_TIME(y))
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, gr)(const TYPE x, const TYPE y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(CGRAPH_TIME(x) > CGRAPH_TIME(y))
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, ge)(const TYPE x, const TYPE y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(CGRAPH_TIME(x) >= CGRAPH_TIME(y))
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, ls)(const TYPE x, const TYPE y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(CGRAPH_TIME(x) < CGRAPH_TIME(y))
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, le)(const TYPE x, const TYPE y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(CGRAPH_TIME(x) <= CGRAPH_TIME(y))
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
  CGRAPH_YEAR(res) = pt->tm_year + 1900;
  CGRAPH_MONTH(res) = pt->tm_mon;
  CGRAPH_DAY(res) = pt->tm_mday;
  CGRAPH_HOUR(res) = pt->tm_hour;
  CGRAPH_MINUTE(res) = pt->tm_min;
  CGRAPH_SECOND(res) = pt->tm_sec;
  CGRAPH_WEEK(res) = pt->tm_wday;
  CGRAPH_DAYS(res) = pt->tm_yday;

  return res;
}

TYPE FUNCTION(NAME, addi)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  
  return res;
}

TYPE FUNCTION(NAME, subi)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;

  return res;
}

TYPE FUNCTION(NAME, muli)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;

  return res;
}

TYPE FUNCTION(NAME, divi)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;

  return res;
}

TYPE FUNCTION(NAME, addt)(const TYPE x, const TYPE y)
{
  TYPE res;

  return res;
}

TYPE FUNCTION(NAME, subt)(const TYPE x, const TYPE y)
{
  TYPE res;

  return res;
}

TYPE FUNCTION(NAME, mult)(const TYPE x, const TYPE y)
{
  TYPE res;

  return res;
}

TYPE FUNCTION(NAME, divt)(const TYPE x, const TYPE y)
{
  TYPE res;

  return res;
}

void FUNCTION(NAME, test)(void)
{
#ifdef DEBUG

#endif
}

#include "templete_off.h"
