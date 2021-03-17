#ifndef _CGRAPH_TIME_H_
#define _CGRAPH_TIME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_TIME
#include "cgraph_template.h"

/*
 */

#define CGRAPH_TIME_TYPE0 (0)
#define CGRAPH_TIME_TYPE1 (1)

typedef struct {
  DATA_UTYPE type : 1;
  union {
    struct __CGRAPH_TYPE_BEGIN(time_type0_t) {
      DATA_TYPE time1 : 31;
      DATA_TYPE time0 : 32;
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

#define TIME_TYPE(x) ((x).type)
#define TIME_ISTYPE0(x) (CGRAPH_TIME_TYPE0 == TIME_TYPE(x))
#define TIME_ISTYPE1(x) (CGRAPH_TIME_TYPE1 == TIME_TYPE(x))

#define TIME_VALUE0(x) (TIME_TYPE0(x).time0)
#define TIME_VALUE1(x) (TIME_TYPE0(x).time1)
#define TIME_VALUE(x) (((cgraph_int64_t)TIME_VALUE1(x) << 30) + TIME_VALUE0(x))
#define TIME_YEAR(x) (TIME_TYPE1(x).year)
#define TIME_MONTH(x) (TIME_TYPE1(x).month)
#define TIME_DAY(x) (TIME_TYPE1(x).day)
#define TIME_HOUR(x) (TIME_TYPE1(x).hour)
#define TIME_MINUTE(x) (TIME_TYPE1(x).minute)
#define TIME_SECOND(x) (TIME_TYPE1(x).second)

#include "cgraph_template_data.ht"

/** apis of TYPE 0 in cgraph_time_t */
extern cgraph_int_t FUNCTION(NAME, printf0)(const TYPE x);
extern cgraph_int_t FUNCTION(NAME, fprintf0)(FILE *fp, const TYPE x);
extern cgraph_int_t FUNCTION(NAME, snprintf0)(cgraph_char_t *buffer,
                                              const cgraph_size_t size,
                                              const TYPE x);

extern TYPE FUNCTION(NAME, init0)(const DATA_TYPE time0, const DATA_TYPE time1);

extern TYPE FUNCTION(NAME, unit0)(void);
extern TYPE FUNCTION(NAME, zero0)(void);
extern TYPE FUNCTION(NAME, one0)(void);
extern TYPE FUNCTION(NAME, ones0)(void);

extern cgraph_int_t FUNCTION(NAME, signbit0)(const TYPE x);

extern cgraph_bool_t FUNCTION(NAME, check0)(const TYPE cthis);
extern cgraph_bool_t FUNCTION(NAME, iszero0)(const TYPE cthis);
extern cgraph_bool_t FUNCTION(NAME, isone0)(const TYPE cthis);

extern cgraph_bool_t FUNCTION(NAME, eq0)(const TYPE x, const TYPE y);
extern cgraph_bool_t FUNCTION(NAME, ne0)(const TYPE x, const TYPE y);
extern cgraph_bool_t FUNCTION(NAME, gr0)(const TYPE x, const TYPE y);
extern cgraph_bool_t FUNCTION(NAME, ge0)(const TYPE x, const TYPE y);
extern cgraph_bool_t FUNCTION(NAME, ls0)(const TYPE x, const TYPE y);
extern cgraph_bool_t FUNCTION(NAME, le0)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, add0i)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, sub0i)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, mul0i)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, div0i)(const TYPE x, const DATA_TYPE y);

extern TYPE FUNCTION(NAME, opp0)(const TYPE x);
extern TYPE FUNCTION(NAME, add0)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, sub0)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, mul0)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, div0)(const TYPE x, const TYPE y);

/** apis of TYPE 1 in cgraph_time_t */
extern cgraph_int_t FUNCTION(NAME, printf1)(const TYPE x);
extern cgraph_int_t FUNCTION(NAME, fprintf1)(FILE *fp, const TYPE x);
extern cgraph_int_t FUNCTION(NAME, snprintf1)(cgraph_char_t *buffer,
                                              const cgraph_size_t size,
                                              const TYPE x);
extern TYPE FUNCTION(NAME, init1)(const DATA_TYPE year, const DATA_TYPE month,
                                  const DATA_TYPE day, const DATA_TYPE hour,
                                  const DATA_TYPE minute,
                                  const DATA_TYPE second);

extern TYPE FUNCTION(NAME, unit1)(void);
extern TYPE FUNCTION(NAME, zero1)(void);
extern TYPE FUNCTION(NAME, one1)(void);
extern TYPE FUNCTION(NAME, ones1)(void);

extern cgraph_int_t FUNCTION(NAME, signbit1)(const TYPE x);

extern cgraph_bool_t FUNCTION(NAME, check1)(const TYPE cthis);
extern cgraph_bool_t FUNCTION(NAME, iszero1)(const TYPE cthis);
extern cgraph_bool_t FUNCTION(NAME, isone1)(const TYPE cthis);

extern cgraph_bool_t FUNCTION(NAME, eq1)(const TYPE x, const TYPE y);
extern cgraph_bool_t FUNCTION(NAME, ne1)(const TYPE x, const TYPE y);
extern cgraph_bool_t FUNCTION(NAME, gr1)(const TYPE x, const TYPE y);
extern cgraph_bool_t FUNCTION(NAME, ge1)(const TYPE x, const TYPE y);
extern cgraph_bool_t FUNCTION(NAME, ls1)(const TYPE x, const TYPE y);
extern cgraph_bool_t FUNCTION(NAME, le1)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, add1i)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, sub1i)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, mul1i)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, div1i)(const TYPE x, const DATA_TYPE y);

extern TYPE FUNCTION(NAME, opp1)(const TYPE x);
extern TYPE FUNCTION(NAME, add1)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, sub1)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, mul1)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, div1)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, localtime)(void);
extern TYPE FUNCTION(NAME, initc)(cgraph_char_t *cthis,
                                  const cgraph_char_t *sep);

extern cgraph_bool_t FUNCTION(NAME, iszero)(const TYPE cthis);
extern cgraph_bool_t FUNCTION(NAME, isone)(const TYPE cthis);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_TIME_H_ */
