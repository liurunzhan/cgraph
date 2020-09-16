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
typedef struct {
  DATA_TYPE flag:1;
  DATA_TYPE type:1;
  union {
    struct time_type0_t {
      DATA_TYPE week:3;   /* maximum is 7      */
      DATA_TYPE days:9;   /* maximum is 366    */
      DATA_TYPE year:24;  /* maximum is 2^24-1 */
      DATA_TYPE month:4;  /* maximum is 12     */
      DATA_TYPE day:5;    /* maximum is 31     */
      DATA_TYPE hour:5;   /* maximum is 24     */
      DATA_TYPE minute:6; /* maximum is 60     */
      DATA_TYPE second:6; /* maximum is 60     */
    } type0;
    struct time_type1_t {
      DATA_TYPE time:62;
    } type1;
  } data;
}cgraph_time_t;

#define CGRAPH_TIME_TYPE(x) ((x).type)
#define CGRAPH_TIME(x)      ((x).data.type1.time)
#define CGRAPH_YEAR(x)      ((x).data.type0.year)
#define CGRAPH_MONTH(x)     ((x).data.type0.month)
#define CGRAPH_DAY(x)       ((x).data.type0.day)
#define CGRAPH_HOUR(x)      ((x).data.type0.hour)
#define CGRAPH_MINUTE(x)    ((x).data.type0.minute)
#define CGRAPH_SECOND(x)    ((x).data.type0.second)
#define CGRAPH_WEEK(x)      ((x).data.type0.week)
#define CGRAPH_DAYS(x)      ((x).data.type0.days)


#include "data_templete.h"

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
