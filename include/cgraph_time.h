#ifndef _CGRAPH_TIME_H_
#define _CGRAPH_TIME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_TIME
#include "templete.h"

/*
*/

#define CGRAPH_TIME_TYPE0  (0)
#define CGRAPH_TIME_TYPE1 (-1)

typedef struct
{
  DATA_UTYPE type:1;
  union 
  {
    struct time_type0_t 
    {
      DATA_TYPE week:4;   /* maximum is 7      */
      DATA_TYPE days:10;  /* maximum is 366    */
      DATA_TYPE year:18;  /* maximum is 2^17-1 */
      DATA_TYPE month:5;  /* maximum is 12     */
      DATA_TYPE day:6;    /* maximum is 31     */
      DATA_TYPE hour:6;   /* maximum is 24     */
      DATA_TYPE minute:7; /* maximum is 60     */
      DATA_TYPE second:7; /* maximum is 60     */
    }type0;
    struct time_type1_t
    {
      DATA_TYPE time1:31;
      DATA_TYPE time0:32;
    }type1;
  }data;
}cgraph_time_t;

#define TIME_TYPE(x)    ((x).type)
#define TIME_ISTYPE0(x) ((x).type == 0)
#define TIME_ISTYPE1(x) ((x).type != 0)

#define TIME_TYPE1(x) ((x).data.type1)
#define TIME1(x)      (TIME_TYPE1(x).time1)
#define TIME0(x)      (TIME_TYPE1(x).time0)
#define TIME_VALUE(x) (((cgraph_int64_t)TIME1(x)) << 31 | (cgraph_int64_t)TIME0(x))

#define TIME_TYPE0(x)  ((x).data.type0)
#define TIME_YEAR(x)   (TIME_TYPE0(x).year)
#define TIME_MONTH(x)  (TIME_TYPE0(x).month)
#define TIME_DAY(x)    (TIME_TYPE0(x).day)
#define TIME_HOUR(x)   (TIME_TYPE0(x).hour)
#define TIME_MINUTE(x) (TIME_TYPE0(x).minute)
#define TIME_SECOND(x) (TIME_TYPE0(x).second)
#define TIME_WEEK(x)   (TIME_TYPE0(x).week)
#define TIME_DAYS(x)   (TIME_TYPE0(x).days)


#include "data_base.ht"

extern TYPE FUNCTION(NAME, initwymdhms)(const DATA_TYPE year, const DATA_TYPE month, const DATA_TYPE day, const DATA_TYPE hour, const DATA_TYPE minute, const DATA_TYPE second);

extern cgraph_boolean_t FUNCTION(NAME, eq)(const TYPE x, const TYPE y);
extern cgraph_boolean_t FUNCTION(NAME, ne)(const TYPE x, const TYPE y);
extern cgraph_boolean_t FUNCTION(NAME, gr)(const TYPE x, const TYPE y);
extern cgraph_boolean_t FUNCTION(NAME, ge)(const TYPE x, const TYPE y);
extern cgraph_boolean_t FUNCTION(NAME, ls)(const TYPE x, const TYPE y);
extern cgraph_boolean_t FUNCTION(NAME, le)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, addi)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, subi)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, muli)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, divi)(const TYPE x, const DATA_TYPE y);

extern TYPE FUNCTION(NAME, addt)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, subt)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, mult)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, divt)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, initc)(cgraph_char_t *cthis, const cgraph_char_t *sep);
extern TYPE FUNCTION(NAME, localtime)(void);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_TIME_H_ */
