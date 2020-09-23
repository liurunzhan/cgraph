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

#define CGRAPH_TIME_ZERO  (0)
#define CGRAPH_TIME_ONE   (-1)

typedef struct
{
  DATA_TYPE type:1;
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

#define CGRAPH_TIME_TYPE(x)    ((x).type)
#define CGRAPH_TIME_ISTYPE0(x) ((x).type == 0)
#define CGRAPH_TIME_ISTYPE1(x) ((x).type != 0)


#define CGRAPH_TIME_TYPE1(x) ((x).data.type1)
#define CGRAPH_TIME1(x)      (CGRAPH_TIME_TYPE1(x).time1)
#define CGRAPH_TIME0(x)      (CGRAPH_TIME_TYPE1(x).time0)
#define CGRAPH_TIME(x)       (((cgraph_int64_t)CGRAPH_TIME1(x)) << 31 | (cgraph_int64_t)CGRAPH_TIME0(x))

#define CGRAPH_TIME_TYPE0(x) ((x).data.type0)
#define CGRAPH_YEAR(x)       (CGRAPH_TIME_TYPE0(x).year)
#define CGRAPH_MONTH(x)      (CGRAPH_TIME_TYPE0(x).month)
#define CGRAPH_DAY(x)        (CGRAPH_TIME_TYPE0(x).day)
#define CGRAPH_HOUR(x)       (CGRAPH_TIME_TYPE0(x).hour)
#define CGRAPH_MINUTE(x)     (CGRAPH_TIME_TYPE0(x).minute)
#define CGRAPH_SECOND(x)     (CGRAPH_TIME_TYPE0(x).second)
#define CGRAPH_WEEK(x)       (CGRAPH_TIME_TYPE0(x).week)
#define CGRAPH_DAYS(x)       (CGRAPH_TIME_TYPE0(x).days)


#include "data_base.ht"

extern cgraph_boolean_t FUNCTION(NAME, eq)(const TYPE x, const TYPE y);
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
