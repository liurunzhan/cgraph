#ifndef _CGRAPH_TIME_H_
#define _CGRAPH_TIME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_TIME
#include "template.h"

/*
 */

#define CGRAPH_TIME_TYPE0 (0)
#define CGRAPH_TIME_TYPE1 (1)

typedef struct {
    DATA_UTYPE type : 1;
    union {
        struct __CGRAPH_TYPE_BEGIN(time_type0_t) {
            DATA_TYPE time1 : 32;
            DATA_TYPE time0 : 31;
        } __CGRAPH_TYPE_END(type0);
        struct __CGRAPH_TYPE_BEGIN(time_type1_t) {
            DATA_TYPE year : 32;  /** -2^31-1 ~ 2^31 */
            DATA_TYPE month : 5;  /**     -12 ~   12 */
            DATA_TYPE day : 6;    /**     -31 ~   31 */
            DATA_TYPE hour : 6;   /**     -24 ~   24 */
            DATA_TYPE minute : 7; /**     -60 ~   60 */
            DATA_TYPE second : 7; /**     -60 ~   60 */
        } __CGRAPH_TYPE_END(type1);
    } __CGRAPH_TYPE_END(data);
} cgraph_time_t;

#define TIME_TYPE0(x) __CGRAPH_TYPE_ELEMENT((x), data.type0)
#define TIME_TYPE1(x) __CGRAPH_TYPE_ELEMENT((x), data.type1)

#define TIME_TYPE(x)    ((x).type)
#define TIME_ISTYPE0(x) ((x).type == 0)
#define TIME_ISTYPE1(x) ((x).type != 0)

#define TIME_VALUE0(x) (TIME_TYPE0(x).time0)
#define TIME_VALUE1(x) (TIME_TYPE0(x).time1)
#define TIME_VALUE(x)  (((cgraph_int64_t)TIME_VALUE1(x) << 30) + TIME_VALUE0(x))
#define TIME_YEAR(x)   (TIME_TYPE1(x).year)
#define TIME_MONTH(x)  (TIME_TYPE1(x).month)
#define TIME_DAY(x)    (TIME_TYPE1(x).day)
#define TIME_HOUR(x)   (TIME_TYPE1(x).hour)
#define TIME_MINUTE(x) (TIME_TYPE1(x).minute)
#define TIME_SECOND(x) (TIME_TYPE1(x).second)

#include "data_base.ht"

extern TYPE FUNCTION(NAME, add0i)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, sub0i)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, mul0i)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, div0i)(const TYPE x, const DATA_TYPE y);

extern TYPE FUNCTION(NAME, opp0)(const TYPE x);
extern TYPE FUNCTION(NAME, add0)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, sub0)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, mul0)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, div0)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, add1i)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, sub1i)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, mul1i)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, div1i)(const TYPE x, const DATA_TYPE y);

extern TYPE FUNCTION(NAME, opp1)(const TYPE x);
extern TYPE FUNCTION(NAME, add1)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, sub1)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, mul1)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, div1)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, init0)(const DATA_TYPE time0,
                                  const DATA_TYPE time1);
extern TYPE FUNCTION(NAME, init1)(const DATA_TYPE year, const DATA_TYPE month,
                                  const DATA_TYPE day, const DATA_TYPE hour,
                                  const DATA_TYPE minute,
                                  const DATA_TYPE second);
extern TYPE FUNCTION(NAME, localtime)(void);
extern TYPE FUNCTION(NAME, initc)(cgraph_char_t *cthis, const cgraph_char_t *sep);

#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_TIME_H_ */
