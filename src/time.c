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
  cgraph_size_t hash = (TIME_YEAR(object) << 13) + (TIME_MONTH(object) << 7) + TIME_DAY(object);
  return CGRAPH_ABS(hash);
}

cgraph_boolean_t FUNCTION(NAME, check)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;
  cgraph_boolean_t flag = CGRAPH_TRUE;
  if(0 == TIME_YEAR(object))
  { flag = CGRAPH_FALSE; }
  else if((0 > TIME_MONTH(object)) || (12 < TIME_MONTH(object)))
  { flag = CGRAPH_FALSE; }
  else if((0 > TIME_DAY(object)) || (31 < TIME_DAY(object)))
  { flag = CGRAPH_FALSE; }
  else if((0 > TIME_HOUR(object)) || (24 < TIME_HOUR(object)))
  { flag = CGRAPH_FALSE; }
  else if((0 > TIME_MINUTE(object)) || (60 < TIME_MINUTE(object)))
  { flag = CGRAPH_FALSE; }
  else if((0 > TIME_SECOND(object)) || (60 < TIME_SECOND(object)))
  { flag = CGRAPH_FALSE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, equal)(const void *x, const void *y)
{
  TYPE object_x = *(TYPE *)x, object_y = *(TYPE *)y;
  return FUNCTION(NAME, eq)(object_x, object_y);
}

cgraph_boolean_t FUNCTION(NAME, eq)(const TYPE x, const TYPE y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(TIME_VALUE(x) == TIME_VALUE(y))
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, ne)(const TYPE x, const TYPE y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(TIME_VALUE(x) != TIME_VALUE(y))
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, gr)(const TYPE x, const TYPE y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(TIME_VALUE(x) > TIME_VALUE(y))
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, ge)(const TYPE x, const TYPE y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(TIME_VALUE(x) >= TIME_VALUE(y))
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, ls)(const TYPE x, const TYPE y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(TIME_VALUE(x) < TIME_VALUE(y))
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, le)(const TYPE x, const TYPE y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(TIME_VALUE(x) <= TIME_VALUE(y))
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

      cgraph_free(object);
    }
  }

  return res;
}

TYPE FUNCTION(NAME, initwymdhms)(const DATA_TYPE year, const DATA_TYPE month, const DATA_TYPE day, const DATA_TYPE hour, const DATA_TYPE minute, const DATA_TYPE second)
{
  TYPE res;
  TIME_TYPE(res)   = CGRAPH_TIME_TYPE0;
  TIME_YEAR(res)   = year;
  TIME_MONTH(res)  = month;
  TIME_DAY(res)    = day;
  TIME_HOUR(res)   = hour;
  TIME_MINUTE(res) = minute;
  TIME_SECOND(res) = second;
  
  return res;
}

TYPE FUNCTION(NAME, initwt01)(const DATA_TYPE time0, const DATA_TYPE time1)
{
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  TIME0(res) = time0;
  TIME1(res) = time1;
  
  return res;
}

TYPE FUNCTION(NAME, localtime)(void)
{
  TYPE res;
  time_t current_time;
  struct tm *pt;
  time(&current_time);
  pt = localtime(&current_time);
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_YEAR(res) = pt->tm_year + 1900;
  TIME_MONTH(res) = pt->tm_mon;
  TIME_DAY(res) = pt->tm_mday;
  TIME_HOUR(res) = pt->tm_hour;
  TIME_MINUTE(res) = pt->tm_min;
  TIME_SECOND(res) = pt->tm_sec;
  TIME_WEEK(res) = pt->tm_wday;
  TIME_DAYS(res) = pt->tm_yday;

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
