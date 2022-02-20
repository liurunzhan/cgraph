/**
 * @file cgraph_time.h
 * @brief the apis of DATA TYPE cgraph_time_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_TIME_H__
#define __CGRAPH_TIME_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_TIME
#include "cgraph_template.h"

#define DATA_NAME int32
#define DATA_UNAME uint32
#define DATA_TYPE TYPE_T(DATA_UNAME)
#define DATA_ID ID_T(UINT32)
#define DATA_BITS CGRAPH_UINT32_BITS
#define DATA_ZERO (0U)
#define DATA_ONE (1U)
#define DATA_ONES (1U)
#define DATA_MIN CGRAPH_UINT32_MIN
#define DATA_MAX CGRAPH_UINT32_MAX
#define DATA_MASK CGRAPH_UINT32_MASK
#define DATA_EPSILON CGRAPH_UINT32_EPSILON
#define DATA_BIAS1 (DATA_MAX & CGRAPH_TIME_TYPE0_BIAS_MASK1)
#define DATA_MIN1 (DATA_MIN & CGRAPH_TIME_TYPE0_MASK1)
#define DATA_MAX1 (DATA_MAX & CGRAPH_TIME_TYPE0_MASK1)
#define DATA_MSB (DATA_ONE << (DATA_BITS - 1))
#define DATA_LSB (DATA_ONE)

#define NAME time
#define TYPE TYPE_T(NAME)
#define ID ID_T(TIME)
#define BITS (8 * sizeof(TYPE))
#define OUT_FMT0 "%u%u"
#if __STDC_VERSION__ >= 199901L
#define ZERO0 ((TYPE){0, {{0, 0}}})
#define ONE0 ((TYPE){0, {{0, 1}}})
#define ONES0 ((TYPE){1, {{1, 1}}})
#else
#define ZERO0 FUNCTION(NAME, zero0)()
#define ONE0 FUNCTION(NAME, one0)()
#define ONES0 FUNCTION(NAME, ones0)()
#endif
#define OUT_FMT1 "%u-%u-%u %u:%u:%u"
#if __STDC_VERSION__ >= 199901L
#define ZERO1 ((TYPE){0, {{0, 0, 0, 0, 0, 0}}})
#define ONE1 ((TYPE){0, {{0, 0, 0, 0, 0, 1}}})
#define ONES1 ((TYPE){1, {{1, 1, 1, 1, 1, 1}}})
#else
#define ZERO1 FUNCTION(NAME, zero1)()
#define ONE1 FUNCTION(NAME, one1)()
#define ONES1 FUNCTION(NAME, ones1)()
#endif
#define ZERO ZERO0
#define ONE ONE0
#define ONES ONE0
#define MIN (0)
#define MAX (1)

/** macro parameters defined in TYPE 0 */
#define CGRAPH_TIME_TYPE0 (0)
#define CGRAPH_TIME_TYPE0_BITS0 (32)
#define CGRAPH_TIME_TYPE0_MASK0 (0xFFFFFFFFU)
#define CGRAPH_TIME_TYPE0_BIAS0 (0xFFFFFFFFU)
#define CGRAPH_TIME_TYPE0_BITS1 (31)
#define CGRAPH_TIME_TYPE0_MASK1 (0x7FFFFFFFU)
#define CGRAPH_TIME_TYPE0_BIAS1 (0x3FFFFFFFU)

/** macro parameters defined in TYPE 1 */
#define CGRAPH_TIME_TYPE1 (1)
#define CGRAPH_TIME_TYPE1_SECOND_BITS (7)
#define CGRAPH_TIME_TYPE1_SECOND_MASK (0x7FU)
#define CGRAPH_TIME_TYPE1_SECOND_BIAS (60U)
#define CGRAPH_TIME_TYPE1_SECOND_MIN (0U)
#define CGRAPH_TIME_TYPE1_SECOND_MAX (119U)
#define CGRAPH_TIME_TYPE1_MINUTE_BITS (7)
#define CGRAPH_TIME_TYPE1_MINUTE_MASK (0x7FU)
#define CGRAPH_TIME_TYPE1_MINUTE_BIAS (60U)
#define CGRAPH_TIME_TYPE1_MINUTE_MIN (0U)
#define CGRAPH_TIME_TYPE1_MINUTE_MAX (119U)
#define CGRAPH_TIME_TYPE1_HOUR_BITS (6)
#define CGRAPH_TIME_TYPE1_HOUR_MASK (0x3FU)
#define CGRAPH_TIME_TYPE1_HOUR_BIAS (24U)
#define CGRAPH_TIME_TYPE1_HOUR_MIN (0U)
#define CGRAPH_TIME_TYPE1_HOUR_MAX (47U)
#define CGRAPH_TIME_TYPE1_DAY_BITS (6)
#define CGRAPH_TIME_TYPE1_DAY_MASK (0x3FU)
#define CGRAPH_TIME_TYPE1_DAY_BIAS (31U)
#define CGRAPH_TIME_TYPE1_DAY_MIN (0U)
#define CGRAPH_TIME_TYPE1_DAY_MAX (61U)
#define CGRAPH_TIME_TYPE1_MONTH_BITS (5)
#define CGRAPH_TIME_TYPE1_MONTH_MASK (0x1FU)
#define CGRAPH_TIME_TYPE1_MONTH_BIAS (12U)
#define CGRAPH_TIME_TYPE1_MONTH_MIN (0U)
#define CGRAPH_TIME_TYPE1_MONTH_MAX (23U)
#define CGRAPH_TIME_TYPE1_YEAR_BITS (32)
#define CGRAPH_TIME_TYPE1_YEAR_MASK (0xFFFFFFFFU)
#define CGRAPH_TIME_TYPE1_YEAR_BIAS (0x7FFFFFFFFU)
#define CGRAPH_TIME_TYPE1_YEAR_MIN (0U)
#define CGRAPH_TIME_TYPE1_YEAR_MAX (0xFFFFFFFFU)

/**
 * @struct cgraph_time_t
 * @brief the object of time
 */
typedef struct {
  DATA_TYPE type : 1;
  union {
    struct __TYPE_BEGIN(time_type0_t) {
      DATA_TYPE time1 : CGRAPH_TIME_TYPE0_BITS1;
      DATA_TYPE time0 : CGRAPH_TIME_TYPE0_BITS0;
    } __TYPE_END(type0);
    struct __TYPE_BEGIN(time_type1_t) {
      DATA_TYPE year
          : CGRAPH_TIME_TYPE1_YEAR_BITS; /** 0 ~ 2^31 : -2^31-1 ~ 2^31 */
      DATA_TYPE month
          : CGRAPH_TIME_TYPE1_MONTH_BITS; /** 0 ~ 24   :    -12 ~   12 */
      DATA_TYPE day
          : CGRAPH_TIME_TYPE1_DAY_BITS; /** 0 ~ 62   :    -31 ~   31 */
      DATA_TYPE hour
          : CGRAPH_TIME_TYPE1_HOUR_BITS; /** 0 ~ 48   :    -24 ~   24 */
      DATA_TYPE minute
          : CGRAPH_TIME_TYPE1_MINUTE_BITS; /** 0 ~ 120  :    -60 ~   60 */
      DATA_TYPE second
          : CGRAPH_TIME_TYPE1_SECOND_BITS; /** 0 ~ 120  :    -60 ~   60 */
    } __TYPE_END(type1);
  } __TYPE_END(data);
} cgraph_time_t;

#define TIME_TYPE0(x) __TYPE_ELEMENT((x), data.type0)
#define TIME_TYPE1(x) __TYPE_ELEMENT((x), data.type1)

#define TIME_TYPE(x) ((x).type)
#define TIME_ISTYPE0(x) (CGRAPH_TIME_TYPE0 == TIME_TYPE(x))
#define TIME_ISTYPE1(x) (CGRAPH_TIME_TYPE1 == TIME_TYPE(x))

#define TIME_VALUE0(x) (TIME_TYPE0(x).time0)
#define TIME_VALUE1(x) (TIME_TYPE0(x).time1)
#define TIME_VALUE(x)                                                          \
  ((((cgraph_int64_t)TIME_VALUE1(x)) << 30) + TIME_VALUE0(x))

#define TIME_YEAR(x) (TIME_TYPE1(x).year)
#define TIME_MONTH(x) (TIME_TYPE1(x).month)
#define TIME_DAY(x) (TIME_TYPE1(x).day)
#define TIME_HOUR(x) (TIME_TYPE1(x).hour)
#define TIME_MINUTE(x) (TIME_TYPE1(x).minute)
#define TIME_SECOND(x) (TIME_TYPE1(x).second)

/** template module */

#include "cgraph_template_data.ht"

/** apis of TYPE 0 in cgraph_time_t */
extern cgraph_size_t FUNCTION(NAME, hash0)(const TYPE cthis);
extern cgraph_size_t FUNCTION(NAME, fprint0)(FILE *fp, const TYPE cthis);
extern cgraph_size_t FUNCTION(NAME, print0)(const TYPE cthis);
extern cgraph_size_t FUNCTION(NAME, fprintln0)(FILE *fp, const TYPE cthis);
extern cgraph_size_t FUNCTION(NAME, println0)(const TYPE cthis);
extern cgraph_size_t FUNCTION(NAME, snprint0)(cgraph_char_t *cbuf,
                                              const cgraph_size_t size,
                                              const TYPE cthis);

extern TYPE FUNCTION(NAME, init0)(const DATA_TYPE time0, const DATA_TYPE time1);

extern TYPE FUNCTION(NAME, unit0)(void);
extern TYPE FUNCTION(NAME, zero0)(void);
extern TYPE FUNCTION(NAME, one0)(void);
extern TYPE FUNCTION(NAME, ones0)(void);
extern TYPE FUNCTION(NAME, rand0)(void);

extern cgraph_int_t FUNCTION(NAME, signbit0)(const TYPE cthis);

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
extern cgraph_size_t FUNCTION(NAME, hash1)(const TYPE cthis);
extern cgraph_size_t FUNCTION(NAME, fprint1)(FILE *fp, const TYPE cthis);
extern cgraph_size_t FUNCTION(NAME, print1)(const TYPE cthis);
extern cgraph_size_t FUNCTION(NAME, fprintln1)(FILE *fp, const TYPE cthis);
extern cgraph_size_t FUNCTION(NAME, println1)(const TYPE cthis);
extern cgraph_size_t FUNCTION(NAME, snprint1)(cgraph_char_t *cbuf,
                                              const cgraph_size_t size,
                                              const TYPE cthisx);
extern TYPE FUNCTION(NAME, init1)(const DATA_TYPE year, const DATA_TYPE month,
                                  const DATA_TYPE day, const DATA_TYPE hour,
                                  const DATA_TYPE minute,
                                  const DATA_TYPE second);

extern TYPE FUNCTION(NAME, unit1)(void);
extern TYPE FUNCTION(NAME, zero1)(void);
extern TYPE FUNCTION(NAME, one1)(void);
extern TYPE FUNCTION(NAME, ones1)(void);
extern TYPE FUNCTION(NAME, rand1)(void);

extern cgraph_int_t FUNCTION(NAME, signbit1)(const TYPE cthis);

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

#define EQ(a, b)                                                               \
  FUNCTION(NAME, eq)                                                           \
  ((a), (b))
#define NE(a, b) CGRAPH_NTEST(FUNCTION(NAME, eq)((a), (b)))
#define GR(a, b)                                                               \
  FUNCTION(NAME, gr)                                                           \
  ((a), (b))
#define GE(a, b) CGRAPH_NTEST(FUNCTION(NAME, gr)((b), (a)))
#define LS(a, b)                                                               \
  FUNCTION(NAME, gr)                                                           \
  ((b), (a))
#define LE(a, b) CGRAPH_NTEST(FUNCTION(NAME, gr)((a), (b)))

#define ADD(a, b, c)                                                           \
  FUNCTION(NAME, add1)                                                         \
  ((a), (b))
#define SUB(a, b, c)                                                           \
  FUNCTION(NAME, sub1)                                                         \
  ((a), (b))
#define MUL(a, b, c)                                                           \
  FUNCTION(NAME, mul1)                                                         \
  ((a), (b))
#define DIV(a, b, c)                                                           \
  FUNCTION(NAME, div1)                                                         \
  ((a), (b))
#define DIVF(a, b, c) __UNDEFINED
#define INT(a, b, c) __UNDEFINED
#define MOD(a, b, c) __UNDEFINED

#define ABS(a) FUNCTION(NAME, abs)((a))
#define CEIL(a, b) FUNCTION(NAME, ceil)((a), (b))
#define FLOOR(a, b) FUNCTION(NAME, floor)((a), (b))
#define POW(a, b) FUNCTION(NAME, pow)((a), (b))
#define SIN(a, b) FUNCTION(NAME, sin)((a), (b))
#define COS(a, b) FUNCTION(NAME, cos)((a), (b))
#define TAN(a, b) FUNCTION(NAME, tan)((a), (b))
#define ASIN(a, b) FUNCTION(NAME, asin)((a), (b))
#define ACOS(a, b) FUNCTION(NAME, acos)((a), (b))
#define ATAN(a, b) FUNCTION(NAME, atan)((a), (b))
#define SINH(a, b) FUNCTION(NAME, sinh)((a), (b))
#define COSH(a, b) FUNCTION(NAME, cosh)((a), (b))
#define TANH(a, b) FUNCTION(NAME, tanh)((a), (b))
#define LOG(a, b) FUNCTION(NAME, log)((a), (b))
#define LOG2(a, b) FUNCTION(NAME, log2)((a), (b))
#define LOG10(a, b) FUNCTION(NAME, log10)((a), (b))
#define EXP(a, b) FUNCTION(NAME, exp)((a), (b))
#define SQRT(a, b) FUNCTION(NAME, sqrt)((a), (b))

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_TIME_H__ */
