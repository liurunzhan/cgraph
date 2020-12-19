#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "cgraph_memory.h"
#include "cgraph_time.h"

#define TYPE_TIME
#include "templete.h"
#include "data_base.ct"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE _cthis = *(TYPE *)cthis;
  cgraph_size_t hash = (TIME_YEAR(_cthis) << 13) + (TIME_MONTH(_cthis) << 7) + TIME_DAY(_cthis);
  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const void *cthis)
{
  TYPE _cthis = *(TYPE *)cthis;
  cgraph_bool_t flag = CGRAPH_TRUE;
  if(0 == TIME_YEAR(_cthis))
  { flag = CGRAPH_FALSE; }
  else if((0 > TIME_MONTH(_cthis)) || (12 < TIME_MONTH(_cthis)))
  { flag = CGRAPH_FALSE; }
  else if((0 > TIME_DAY(_cthis)) || (31 < TIME_DAY(_cthis)))
  { flag = CGRAPH_FALSE; }
  else if((0 > TIME_HOUR(_cthis)) || (24 < TIME_HOUR(_cthis)))
  { flag = CGRAPH_FALSE; }
  else if((0 > TIME_MINUTE(_cthis)) || (60 < TIME_MINUTE(_cthis)))
  { flag = CGRAPH_FALSE; }
  else if((0 > TIME_SECOND(_cthis)) || (60 < TIME_SECOND(_cthis)))
  { flag = CGRAPH_FALSE; }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, equal)(const void *x, const void *y)
{
  TYPE object_x = *(TYPE *)x, object_y = *(TYPE *)y;

  return FUNCTION(NAME, eq)(object_x, object_y);
}

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE x, const TYPE y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((TIME_VALUE0(x) == TIME_VALUE0(y)) && (TIME_VALUE1(x) == TIME_VALUE1(y)))
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ne)(const TYPE x, const TYPE y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((TIME_VALUE0(x) != TIME_VALUE0(y)) || (TIME_VALUE1(x) != TIME_VALUE1(y)))
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, gr)(const TYPE x, const TYPE y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((TIME_VALUE0(x) > TIME_VALUE0(y)) || (TIME_VALUE1(x) > TIME_VALUE1(y)))
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ge)(const TYPE x, const TYPE y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((TIME_VALUE0(x) >= TIME_VALUE0(y)) || (TIME_VALUE1(x) >= TIME_VALUE1(y)))
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ls)(const TYPE x, const TYPE y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((TIME_VALUE0(x) < TIME_VALUE0(y)) || (TIME_VALUE1(x) < TIME_VALUE1(y)))
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, le)(const TYPE x, const TYPE y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((TIME_VALUE0(x) <= TIME_VALUE0(y)) || (TIME_VALUE1(x) <= TIME_VALUE1(y)))
  { flag = CGRAPH_TRUE; }

  return flag;
}

TYPE FUNCTION(NAME, initc)(const cgraph_char_t *cthis, const cgraph_char_t *sep)
{
  TYPE res;
  cgraph_size_t i = 0;
  DATA_TYPE res_tmp[TYPE1_ELEMENTS] = {0};
  if((NULL != cthis) && (NULL != sep))
  {
    char *buffer = cgraph_calloc(strlen(cthis)+1);
    if(NULL != buffer)
    {
      char *p = NULL;
      buffer = cgraph_strcpy(buffer, cthis);
      while((NULL != (p = strtok(buffer, sep))) && (TYPE1_ELEMENTS > i))
      { res_tmp[i++] = atoi(p); }
      cgraph_free(buffer);
    }
  }
  TIME_YEAR(res) = res_tmp[0];
  TIME_MONTH(res) = res_tmp[1];
  TIME_DAY(res) = res_tmp[2];
  TIME_HOUR(res) = res_tmp[3];
  TIME_MINUTE(res) = res_tmp[4];
  TIME_SECOND(res) = res_tmp[5];

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

TYPE FUNCTION(NAME, initt0t1)(const DATA_TYPE time0, const DATA_TYPE time1)
{
  TYPE res;
  TIME_TYPE(res)   = CGRAPH_TIME_TYPE1;
  TIME_VALUE0(res) = time0;
  TIME_VALUE1(res) = time1;
  
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

TYPE FUNCTION(NAME, add0i)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  DATA_TYPE tmp = TIME_VALUE0(x) + y;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = tmp;
  if((0 < TIME_VALUE0(x)) && (0 < y))
  {
    if(tmp < 0)
    {
      TIME_VALUE0(res) = TIME_VALUE0(x) - DATA_MAX + y;
      tmp = 1;
    } 
    else
    { tmp = 0; }
  }
  else if((0 > TIME_VALUE0(x)) && (0 > y))
  {
    if(tmp > 0)
    {
      TIME_VALUE0(res) = TIME_VALUE0(x) + DATA_MAX - y;
      tmp = -1;
    }
    else
    { tmp = 0; }
  }
  else
  { tmp = 0; }
  TIME_VALUE1(res) = TIME_VALUE1(x) + tmp;
  
  return res;
}

TYPE FUNCTION(NAME, sub0i)(const TYPE x, const DATA_TYPE y)
{
  return FUNCTION(NAME, add0i)(x, -y);
}

TYPE FUNCTION(NAME, mul0i)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  TIME_TYPE(res)  = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = TIME_VALUE0(x) * y;
  TIME_VALUE1(res) = TIME_VALUE1(x) * y;

  return res;
}

TYPE FUNCTION(NAME, div0i)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = TIME_VALUE0(x) / y;
  TIME_VALUE1(res) = TIME_VALUE1(x) / y;

  return res;
}

TYPE FUNCTION(NAME, mul0I)(const TYPE x)
{
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = -TIME_VALUE0(x);
  TIME_VALUE1(res) = -TIME_VALUE1(x);

  return res;
}

TYPE FUNCTION(NAME, add0t)(const TYPE x, const TYPE y)
{
  TYPE res;
  DATA_TYPE tmp = TIME_VALUE0(x) + TIME_VALUE0(y);
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = tmp;
  if((0 < TIME_VALUE0(x)) && (0 < TIME_VALUE0(y)))
  {
    if(tmp < 0)
    {
      TIME_VALUE0(res) = TIME_VALUE0(x) - DATA_MAX + TIME_VALUE0(y);
      tmp = 1;
    } 
    else
    { tmp = 0; }
  }
  else if((0 > TIME_VALUE0(x)) && (0 > TIME_VALUE0(y)))
  {
    if(tmp > 0)
    {
      TIME_VALUE0(res) = TIME_VALUE0(x) + DATA_MAX - TIME_VALUE0(y);
      tmp = -1;
    }
    else
    { tmp = 0; }
  }
  else
  { tmp = 0; }
  TIME_VALUE1(res) = TIME_VALUE1(x) + TIME_VALUE1(y) + tmp;

  return res;
}

TYPE FUNCTION(NAME, sub0t)(const TYPE x, const TYPE y)
{
  return FUNCTION(NAME, add0t)(x, FUNCTION(NAME, mul0I)(y));
}

TYPE FUNCTION(NAME, mul0t)(const TYPE x, const TYPE y)
{
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = TIME_VALUE0(x) * TIME_VALUE0(y);
  TIME_VALUE1(res) = TIME_VALUE1(x) * TIME_VALUE1(y);

  return res;
}

TYPE FUNCTION(NAME, div0t)(const TYPE x, const TYPE y)
{
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = TIME_VALUE0(x) / TIME_VALUE0(y);
  TIME_VALUE1(res) = TIME_VALUE1(x) / TIME_VALUE1(y);

  return res;
}

TYPE FUNCTION(NAME, add1i)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  
  return res;
}

TYPE FUNCTION(NAME, sub1i)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;

  return res;
}

TYPE FUNCTION(NAME, mul1i)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;

  return res;
}

TYPE FUNCTION(NAME, div1i)(const TYPE x, const DATA_TYPE y)
{
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;

  return res;
}

TYPE FUNCTION(NAME, mul1I)(const TYPE x)
{
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  TIME_WEEK(res) = -TIME_WEEK(x);
  TIME_DAYS(res) = -TIME_DAYS(x);
  TIME_YEAR(res) = -TIME_YEAR(x);
  TIME_MONTH(res) = -TIME_MONTH(x);
  TIME_DAY(res) = -TIME_DAY(x);
  TIME_HOUR(res) = -TIME_HOUR(x);
  TIME_MINUTE(res) = -TIME_MINUTE(x);
  TIME_SECOND(res) = -TIME_SECOND(x);

  return res;
}

TYPE FUNCTION(NAME, add1t)(const TYPE x, const TYPE y)
{
  TYPE res;
  DATA_TYPE tmp = 0;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  if(59 < (TIME_SECOND(res) = TIME_SECOND(x) + TIME_SECOND(y)))
  {
    TIME_SECOND(res) -= 59;
    tmp = 1;
  }
  else
  { tmp = 0; }
  if(59 < (TIME_MINUTE(res) = tmp + TIME_MINUTE(x) + TIME_MINUTE(y)))
  {
    TIME_MINUTE(res) -= 59;
    tmp = 1;
  }
  else
  { tmp = 0; }
  if(23 < (TIME_HOUR(res) = tmp + TIME_HOUR(x) + TIME_HOUR(y)))
  {
    TIME_MINUTE(res) -= 23;
    tmp = 1;
  }
  else
  { tmp = 0; }
  if(23 < (TIME_HOUR(res) = tmp + TIME_HOUR(x) + TIME_HOUR(y)))
  {
    TIME_MINUTE(res) -= 23;
    tmp = 1;
  }
  else
  { tmp = 0; }


  return res;
}

TYPE FUNCTION(NAME, sub1t)(const TYPE x, const TYPE y)
{
  return FUNCTION(NAME, add1t)(x, FUNCTION(NAME, mul1I)(y));
}

TYPE FUNCTION(NAME, mul1t)(const TYPE x, const TYPE y)
{
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;

  return res;
}

TYPE FUNCTION(NAME, div1t)(const TYPE x, const TYPE y)
{
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;

  return res;
}

void FUNCTION(NAME, test)(void)
{
#ifdef DEBUG
  
#endif
}

#include "templete_off.h"
