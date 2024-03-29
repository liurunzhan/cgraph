#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cgraph_base.h"
#include "cgraph_int32.h"

/** object cgraph_time_t header */
#include "cgraph_time.h"

/** @brief template module */
#include "template_data.ct"

/** @brief common apis */
cgraph_size_t FUNCTION(NAME, fprint)(FILE *fp, const TYPE cthis) {
  if (TIME_ISTYPE0(cthis)) {
    return FUNCTION(NAME, fprint0)(fp, cthis);
  } else {
    return FUNCTION(NAME, fprint1)(fp, cthis);
  }
}

cgraph_size_t FUNCTION(NAME, snprint)(cgraph_char_t *cbuf,
                                      const cgraph_size_t size,
                                      const TYPE cthis) {
  if (TIME_ISTYPE0(cthis)) {
    return FUNCTION(NAME, snprint0)(cbuf, size, cthis);
  } else {
    return FUNCTION(NAME, snprint1)(cbuf, size, cthis);
  }
}

cgraph_size_t FUNCTION(NAME, hash)(const TYPE cthis) {
  cgraph_size_t hash = USIZE_C(0);
  if (TIME_ISTYPE0(cthis)) {
    hash = FUNCTION(NAME, hash0)(cthis);
  } else {
    hash = FUNCTION(NAME, hash1)(cthis);
  }

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE cthis) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if (TIME_ISTYPE0(cthis)) {
    flag = FUNCTION(NAME, check0)(cthis);
  } else {
    flag = FUNCTION(NAME, check1)(cthis);
  }

  return flag;
}

TYPE FUNCTION(NAME, zero)(void) { return FUNCTION(NAME, zero0)(); }

TYPE FUNCTION(NAME, one)(void) { return FUNCTION(NAME, one0)(); }

TYPE FUNCTION(NAME, ones)(void) { return FUNCTION(NAME, ones0)(); }

TYPE FUNCTION(NAME, rand)(void) { return FUNCTION(NAME, rand0)(); }

cgraph_bool_t FUNCTION(NAME, iszero)(const TYPE cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (TIME_ISTYPE0(cthis)) {
    flag = FUNCTION(NAME, iszero0)(cthis);
  } else {
    flag = FUNCTION(NAME, iszero1)(cthis);
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isone)(const TYPE cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (TIME_ISTYPE0(cthis)) {
    flag = FUNCTION(NAME, isone0)(cthis);
  } else {
    flag = FUNCTION(NAME, isone1)(cthis);
  }

  return flag;
}

__INLINE__ cgraph_int_t FUNCTION(NAME, signbit)(const TYPE cthis) {
  cgraph_int_t flag;
  if (TIME_ISTYPE0(cthis)) {
    flag = FUNCTION(NAME, signbit0)(cthis);
  } else {
    flag = FUNCTION(NAME, signbit1)(cthis);
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE x, const TYPE y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (TIME_TYPE(x) == TIME_TYPE(y)) {
    if (TIME_ISTYPE0(x)) {
      flag = FUNCTION(NAME, eq0)(x, y);
    } else {
      flag = FUNCTION(NAME, eq1)(x, y);
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, gt)(const TYPE x, const TYPE y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (TIME_TYPE(x) == TIME_TYPE(y)) {
    if (TIME_ISTYPE0(x)) {
      flag = FUNCTION(NAME, gr0)(x, y);
    } else {
      flag = FUNCTION(NAME, gr1)(x, y);
    }
  }

  return flag;
}

TYPE FUNCTION(NAME, ceil)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, floor)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, pow)(const TYPE x, const TYPE y) { return x; }

TYPE FUNCTION(NAME, sin)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, cos)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, tan)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, asin)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, acos)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, atan)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, sinh)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, cosh)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, tanh)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, log)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, log2)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, log10)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, exp)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, sqrt)(const TYPE x) { return x; }

/** apis of TYPE 0 in cgraph_time_t  */
cgraph_size_t FUNCTION(NAME, hash0)(const TYPE cthis) {
  cgraph_size_t hash = TIME_TYPE(cthis);
  hash += (TIME_VALUE0(cthis) << 13) + (TIME_VALUE1(cthis) << 7);

  return CGRAPH_ABS(hash);
}

cgraph_size_t FUNCTION(NAME, fprint0)(FILE *fp, const TYPE cthis) {
  return fprintf(fp, OUT_FMT0, TIME_VALUE1(cthis), TIME_VALUE0(cthis));
}

cgraph_size_t FUNCTION(NAME, print0)(const TYPE cthis) {
  return FUNCTION(NAME, fprint0)(stdout, cthis);
}

cgraph_size_t FUNCTION(NAME, fprintln0)(FILE *fp, const TYPE cthis) {
  cgraph_size_t len = FUNCTION(NAME, fprint0)(fp, cthis);
  if (0 < len) {
    len += cgraph_file_fprintln(fp);
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, println0)(const TYPE cthis) {
  return FUNCTION(NAME, fprintln0)(stdout, cthis);
}

cgraph_size_t FUNCTION(NAME, snprint0)(cgraph_char_t *cbuf,
                                       const cgraph_size_t size,
                                       const TYPE cthis) {
  return cgraph_file_snprintf(cbuf, size, OUT_FMT0, TIME_VALUE1(cthis),
                              TIME_VALUE0(cthis));
}

TYPE FUNCTION(NAME, localtime0)(void) {
  TYPE res;
  time_t current_time;
  time(&current_time);
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = current_time;
  TIME_VALUE1(res) = current_time >> 31;

  return res;
}

TYPE FUNCTION(NAME, initc0)(cgraph_char_t *cthis, const cgraph_char_t *sep) {
  TYPE res;
  cgraph_size_t i = 0;
  DATA_TYPE res_tmp[2] = {0};
  if ((NULL != cthis) && (NULL != sep)) {
    char *p = NULL;
    while ((NULL != (p = strtok(cthis, sep))) && (2 > i)) {
      res_tmp[i++] = atoi(p);
    }
  }
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = res_tmp[0];
  TIME_VALUE1(res) = res_tmp[1];

  return res;
}

TYPE FUNCTION(NAME, init0)(const DATA_TYPE time0, const DATA_TYPE time1) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = time0;
  TIME_VALUE1(res) = time1;

  return res;
}

TYPE FUNCTION(NAME, unit0)(void) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = 1;
  TIME_VALUE1(res) = 0;

  return res;
}

TYPE FUNCTION(NAME, zero0)(void) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = 0;
  TIME_VALUE1(res) = 0;

  return res;
}

TYPE FUNCTION(NAME, one0)(void) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = 0;
  TIME_VALUE1(res) = 1;

  return res;
}

TYPE FUNCTION(NAME, ones0)(void) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = DATA_MIN;
  TIME_VALUE1(res) = DATA_MIN1;

  return res;
}

TYPE FUNCTION(NAME, min0)(void) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = DATA_MIN;
  TIME_VALUE1(res) = DATA_MIN1;

  return res;
}

TYPE FUNCTION(NAME, max0)(void) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = DATA_MAX;
  TIME_VALUE1(res) = DATA_MAX1;

  return res;
}

TYPE FUNCTION(NAME, rand0)(void) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = DATA_MIN & FUNCTION(DATA_NAME, urand)();
  TIME_VALUE1(res) = DATA_MIN1 & FUNCTION(DATA_NAME, urand)();

  return res;
}

__INLINE__ cgraph_int_t FUNCTION(NAME, signbit0)(const TYPE cthis) {
  return TIME_VALUE0(cthis) | (TIME_VALUE0(cthis) >> 31);
}

cgraph_bool_t FUNCTION(NAME, check0)(const TYPE cthis) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if ((TIME_VALUE0(cthis) | (TIME_VALUE0(cthis) >> 31)) !=
      (TIME_VALUE1(cthis) | (TIME_VALUE1(cthis) >> 30))) {
    flag = CGRAPH_FALSE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, iszero0)(const TYPE cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((0 == TIME_SECOND(cthis)) && (0 == TIME_MINUTE(cthis))) {
    if ((0 == TIME_HOUR(cthis)) && (0 == TIME_DAY(cthis))) {
      if ((0 == TIME_MONTH(cthis)) && (0 == TIME_YEAR(cthis))) {
        flag = CGRAPH_TRUE;
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isone0)(const TYPE cthis) {
  cgraph_bool_t flag;
  if ((1 == TIME_SECOND(cthis)) && (0 == TIME_MINUTE(cthis))) {
    if ((0 == TIME_HOUR(cthis)) && (0 == TIME_DAY(cthis))) {
      if ((0 == TIME_MONTH(cthis)) && (0 == TIME_YEAR(cthis))) {
        flag = CGRAPH_TRUE;
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, eq0)(const TYPE x, const TYPE y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((TIME_VALUE0(x) == TIME_VALUE0(y)) &&
      (TIME_VALUE1(x) == TIME_VALUE1(y))) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ne0)(const TYPE x, const TYPE y) {
  return CGRAPH_NTEST(FUNCTION(NAME, eq0)(x, y));
}

cgraph_bool_t FUNCTION(NAME, gr0)(const TYPE x, const TYPE y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (TIME_VALUE1(x) > TIME_VALUE1(y)) {
    flag = CGRAPH_TRUE;
  } else if ((TIME_VALUE1(x) == TIME_VALUE1(y)) &&
             (TIME_VALUE0(x) > TIME_VALUE0(y))) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ge0)(const TYPE x, const TYPE y) {
  return CGRAPH_NTEST(FUNCTION(NAME, ls0)(x, y));
}

cgraph_bool_t FUNCTION(NAME, ls0)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, gr0)(y, x);
}

cgraph_bool_t FUNCTION(NAME, le0)(const TYPE x, const TYPE y) {
  return CGRAPH_NTEST(FUNCTION(NAME, gr0)(x, y));
}

TYPE FUNCTION(NAME, add0i)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  DATA_TYPE tmp = TIME_VALUE0(x) + y;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = tmp;
  if ((0 < TIME_VALUE0(x)) && (0 < y)) {
    if (tmp < 0) {
      TIME_VALUE0(res) = TIME_VALUE0(x) - DATA_MAX + y;
      tmp = 1;
    } else {
      tmp = 0;
    }
  } else if ((0 > TIME_VALUE0(x)) && (0 > y)) {
    if (tmp > 0) {
      TIME_VALUE0(res) = TIME_VALUE0(x) + DATA_MAX - y;
      tmp = -1;
    } else {
      tmp = 0;
    }
  } else {
    tmp = 0;
  }
  TIME_VALUE1(res) = TIME_VALUE1(x) + tmp;

  return res;
}

TYPE FUNCTION(NAME, sub0i)(const TYPE x, const DATA_TYPE y) {
  return FUNCTION(NAME, add0i)(x, -y);
}

TYPE FUNCTION(NAME, mul0i)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = TIME_VALUE0(x) * y;
  TIME_VALUE1(res) = TIME_VALUE1(x) * y;

  return res;
}

TYPE FUNCTION(NAME, div0i)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = TIME_VALUE0(x) / y;
  TIME_VALUE1(res) = TIME_VALUE1(x) / y;

  return res;
}

TYPE FUNCTION(NAME, opp0)(const TYPE x) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = -TIME_VALUE0(x);
  TIME_VALUE1(res) = -TIME_VALUE1(x);

  return res;
}

TYPE FUNCTION(NAME, add0)(const TYPE x, const TYPE y) {
  TYPE res;
  DATA_TYPE tmp = TIME_VALUE0(x) + TIME_VALUE0(y);
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = tmp;
  if ((0 < TIME_VALUE0(x)) && (0 < TIME_VALUE0(y))) {
    if (tmp < 0) {
      TIME_VALUE0(res) = TIME_VALUE0(x) - DATA_MAX + TIME_VALUE0(y);
      tmp = 1;
    } else {
      tmp = 0;
    }
  } else if ((0 > TIME_VALUE0(x)) && (0 > TIME_VALUE0(y))) {
    if (tmp > 0) {
      TIME_VALUE0(res) = TIME_VALUE0(x) + DATA_MAX - TIME_VALUE0(y);
      tmp = -1;
    } else {
      tmp = 0;
    }
  } else {
    tmp = 0;
  }
  TIME_VALUE1(res) = TIME_VALUE1(x) + TIME_VALUE1(y) + tmp;

  return res;
}

TYPE FUNCTION(NAME, sub0)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, add0)(x, FUNCTION(NAME, opp0)(y));
}

TYPE FUNCTION(NAME, mul0)(const TYPE x, const TYPE y) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = TIME_VALUE0(x) * TIME_VALUE0(y);
  TIME_VALUE1(res) = TIME_VALUE1(x) * TIME_VALUE1(y);

  return res;
}

TYPE FUNCTION(NAME, div0)(const TYPE x, const TYPE y) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = TIME_VALUE0(x) / TIME_VALUE0(y);
  TIME_VALUE1(res) = TIME_VALUE1(x) / TIME_VALUE1(y);

  return res;
}

/** apis of TYPE 1 in cgraph_time_t */
cgraph_size_t FUNCTION(NAME, hash1)(const TYPE cthis) {
  cgraph_size_t hash = TIME_TYPE(cthis);
  hash += (TIME_YEAR(cthis) << 13) + (TIME_MONTH(cthis) << 7) + TIME_DAY(cthis);
  hash += TIME_HOUR(cthis) + TIME_MINUTE(cthis) + TIME_SECOND(cthis);

  return CGRAPH_ABS(hash);
}

cgraph_size_t FUNCTION(NAME, fprint1)(FILE *fp, const TYPE cthis) {
  return fprintf(fp, OUT_FMT1, TIME_YEAR(cthis), TIME_MONTH(cthis),
                 TIME_DAY(cthis), TIME_HOUR(cthis), TIME_MINUTE(cthis),
                 TIME_SECOND(cthis));
}

cgraph_size_t FUNCTION(NAME, print1)(const TYPE cthis) {
  return FUNCTION(NAME, fprint1)(stdout, cthis);
}

cgraph_size_t FUNCTION(NAME, fprintln1)(FILE *fp, const TYPE cthis) {
  cgraph_size_t len = FUNCTION(NAME, fprint1)(fp, cthis);
  if (0 < len) {
    len += cgraph_file_fprintln(fp);
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, println1)(const TYPE cthis) {
  return FUNCTION(NAME, fprintln1)(stdout, cthis);
}

cgraph_size_t FUNCTION(NAME, snprint1)(cgraph_char_t *cbuf,
                                       const cgraph_size_t size,
                                       const TYPE cthis) {
  return cgraph_file_snprintf(cbuf, size, OUT_FMT1, TIME_YEAR(cthis),
                              TIME_MONTH(cthis), TIME_DAY(cthis),
                              TIME_HOUR(cthis), TIME_MINUTE(cthis),
                              TIME_SECOND(cthis));
}

TYPE FUNCTION(NAME, localtime1)(void) {
  TYPE res;
  time_t current_time;
  struct tm *pt;
  time(&current_time);
  pt = localtime(&current_time);
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  TIME_YEAR(res) = pt->tm_year + 1900;
  TIME_MONTH(res) = pt->tm_mon;
  TIME_DAY(res) = pt->tm_mday;
  TIME_HOUR(res) = pt->tm_hour;
  TIME_MINUTE(res) = pt->tm_min;
  TIME_SECOND(res) = pt->tm_sec;

  return res;
}

TYPE FUNCTION(NAME, initc1)(cgraph_char_t *cthis, const cgraph_char_t *sep) {
  TYPE res;
  cgraph_size_t i = 0;
  DATA_TYPE res_tmp[6] = {0};
  if ((NULL != cthis) && (NULL != sep)) {
    char *p = NULL;
    while ((NULL != (p = strtok(cthis, sep))) && (6 > i)) {
      res_tmp[i++] = atoi(p);
    }
  }
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  TIME_YEAR(res) = res_tmp[0];
  TIME_MONTH(res) = res_tmp[1];
  TIME_DAY(res) = res_tmp[2];
  TIME_HOUR(res) = res_tmp[3];
  TIME_MINUTE(res) = res_tmp[4];
  TIME_SECOND(res) = res_tmp[5];

  return res;
}

TYPE FUNCTION(NAME, init1)(const DATA_TYPE year, const DATA_TYPE month,
                           const DATA_TYPE day, const DATA_TYPE hour,
                           const DATA_TYPE minute, const DATA_TYPE second) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  TIME_YEAR(res) = year;
  TIME_MONTH(res) = month;
  TIME_DAY(res) = day;
  TIME_HOUR(res) = hour;
  TIME_MINUTE(res) = minute;
  TIME_SECOND(res) = second;

  return res;
}

TYPE FUNCTION(NAME, unit1)(void) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  TIME_YEAR(res) = 0;
  TIME_MONTH(res) = 0;
  TIME_DAY(res) = 0;
  TIME_HOUR(res) = 0;
  TIME_MINUTE(res) = 0;
  TIME_SECOND(res) = 1;

  return res;
}

TYPE FUNCTION(NAME, zero1)(void) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  TIME_YEAR(res) = 0;
  TIME_MONTH(res) = 0;
  TIME_DAY(res) = 0;
  TIME_HOUR(res) = 0;
  TIME_MINUTE(res) = 0;
  TIME_SECOND(res) = 0;

  return res;
}

TYPE FUNCTION(NAME, one1)(void) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  TIME_YEAR(res) = 0;
  TIME_MONTH(res) = 0;
  TIME_DAY(res) = 0;
  TIME_HOUR(res) = 0;
  TIME_MINUTE(res) = 0;
  TIME_SECOND(res) = 1;

  return res;
}

TYPE FUNCTION(NAME, ones1)(void) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  TIME_YEAR(res) = DATA_MAX;
  TIME_MONTH(res) = 12;
  TIME_DAY(res) = 31;
  TIME_HOUR(res) = 23;
  TIME_MINUTE(res) = 59;
  TIME_SECOND(res) = 59;

  return res;
}

TYPE FUNCTION(NAME, min1)(void) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  TIME_YEAR(res) = DATA_MIN;
  TIME_MONTH(res) = 1;
  TIME_DAY(res) = 1;
  TIME_HOUR(res) = 0;
  TIME_MINUTE(res) = 0;
  TIME_SECOND(res) = 0;

  return res;
}

TYPE FUNCTION(NAME, max1)(void) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  TIME_YEAR(res) = DATA_MAX;
  TIME_MONTH(res) = 12;
  TIME_DAY(res) = 31;
  TIME_HOUR(res) = 23;
  TIME_MINUTE(res) = 59;
  TIME_SECOND(res) = 59;

  return res;
}

TYPE FUNCTION(NAME, rand1)(void) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  TIME_YEAR(res) = DATA_MAX & FUNCTION(DATA_NAME, rand)();
  TIME_MONTH(res) = cgraph_rand32_uniform(-12, 12);
  TIME_DAY(res) = cgraph_rand32_uniform(-31, 31);
  TIME_HOUR(res) = cgraph_rand32_uniform(-23, 23);
  TIME_MINUTE(res) = cgraph_rand32_uniform(-59, 59);
  TIME_SECOND(res) = cgraph_rand32_uniform(-59, 59);

  return res;
}

__INLINE__ cgraph_int_t FUNCTION(NAME, signbit1)(const TYPE cthis) {
  return TIME_SECOND(cthis) | (TIME_SECOND(cthis) >> 6);
}

cgraph_bool_t FUNCTION(NAME, check1)(const TYPE cthis) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if (0 == TIME_YEAR(cthis)) {
    flag = CGRAPH_FALSE;
  } else if ((-12 > TIME_MONTH(cthis)) || (12 < TIME_MONTH(cthis))) {
    flag = CGRAPH_FALSE;
  } else if (-31 > TIME_DAY(cthis)) {
    flag = CGRAPH_FALSE;
  } else if ((-24 > TIME_HOUR(cthis)) || (24 < TIME_HOUR(cthis))) {
    flag = CGRAPH_FALSE;
  } else if ((-60 > TIME_MINUTE(cthis)) || (60 < TIME_MINUTE(cthis))) {
    flag = CGRAPH_FALSE;
  } else if ((-60 > TIME_SECOND(cthis)) || (60 < TIME_SECOND(cthis))) {
    flag = CGRAPH_FALSE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, iszero1)(const TYPE cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((0 == TIME_SECOND(cthis)) && (0 == TIME_MINUTE(cthis))) {
    if ((0 == TIME_HOUR(cthis)) && (0 == TIME_DAY(cthis))) {
      if ((0 == TIME_MONTH(cthis)) && (0 == TIME_YEAR(cthis))) {
        flag = CGRAPH_TRUE;
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isone1)(const TYPE cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((1 == TIME_SECOND(cthis)) && (0 == TIME_MINUTE(cthis))) {
    if ((0 == TIME_HOUR(cthis)) && (0 == TIME_DAY(cthis))) {
      if ((0 == TIME_MONTH(cthis)) && (0 == TIME_YEAR(cthis))) {
        flag = CGRAPH_TRUE;
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ismin0)(const TYPE cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((0 == TIME_SECOND(cthis)) && (0 == TIME_MINUTE(cthis))) {
    if ((0 == TIME_HOUR(cthis)) && (1 == TIME_DAY(cthis))) {
      if ((1 == TIME_MONTH(cthis)) && (DATA_MIN == TIME_YEAR(cthis))) {
        flag = CGRAPH_TRUE;
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ismax0)(const TYPE cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((59 == TIME_SECOND(cthis)) && (59 == TIME_MINUTE(cthis))) {
    if ((23 == TIME_HOUR(cthis)) && (31 == TIME_DAY(cthis))) {
      if ((12 == TIME_MONTH(cthis)) && (DATA_MAX == TIME_YEAR(cthis))) {
        flag = CGRAPH_TRUE;
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, eq1)(const TYPE x, const TYPE y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((TIME_TYPE(x) == TIME_TYPE(y)) && (TIME_VALUE0(x) == TIME_VALUE0(y)) &&
      (TIME_VALUE1(x) == TIME_VALUE1(y))) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ne1)(const TYPE x, const TYPE y) {
  return CGRAPH_NTEST(FUNCTION(NAME, eq1)(x, y));
}

cgraph_bool_t FUNCTION(NAME, gr1)(const TYPE x, const TYPE y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((TIME_VALUE0(x) > TIME_VALUE0(y)) || (TIME_VALUE1(x) > TIME_VALUE1(y))) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ge1)(const TYPE x, const TYPE y) {
  return CGRAPH_NTEST(FUNCTION(NAME, ls1)(x, y));
}

cgraph_bool_t FUNCTION(NAME, ls1)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, gr1)(y, x);
}

cgraph_bool_t FUNCTION(NAME, le1)(const TYPE x, const TYPE y) {
  return CGRAPH_NTEST(FUNCTION(NAME, gr1)(x, y));
}

TYPE FUNCTION(NAME, add1i)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  TIME_SECOND(res) = TIME_SECOND(x) + y;
  TIME_MINUTE(res) = TIME_MINUTE(x);
  TIME_HOUR(res) = TIME_HOUR(x);
  TIME_DAY(res) = TIME_DAY(x);
  TIME_MONTH(res) = TIME_MONTH(x);
  TIME_YEAR(res) = TIME_YEAR(x);

  return res;
}

TYPE FUNCTION(NAME, sub1i)(const TYPE x, const DATA_TYPE y) {
  return FUNCTION(NAME, add1i)(x, -y);
}

TYPE FUNCTION(NAME, mul1i)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;

  return res;
}

TYPE FUNCTION(NAME, div1i)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;

  return res;
}

TYPE FUNCTION(NAME, opp1)(const TYPE x) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  TIME_SECOND(res) = -TIME_SECOND(x);
  TIME_MINUTE(res) = -TIME_MINUTE(x);
  TIME_HOUR(res) = -TIME_HOUR(x);
  TIME_DAY(res) = -TIME_DAY(x);
  TIME_MONTH(res) = -TIME_MONTH(x);
  TIME_YEAR(res) = -TIME_YEAR(x);

  return res;
}

TYPE FUNCTION(NAME, add1)(const TYPE x, const TYPE y) {
  TYPE res;
  DATA_TYPE tmp = 0;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  if (59 < (TIME_SECOND(res) = TIME_SECOND(x) + TIME_SECOND(y))) {
    TIME_SECOND(res) = TIME_SECOND(x) - 60 + TIME_SECOND(y);
    tmp = 1;
  } else {
    tmp = 0;
  }
  if (59 < (TIME_MINUTE(res) = tmp + TIME_MINUTE(x) + TIME_MINUTE(y))) {
    TIME_MINUTE(res) = TIME_MINUTE(x) - 60 + TIME_MINUTE(y) + tmp;
    tmp = 1;
  } else {
    tmp = 0;
  }
  if (23 < (TIME_HOUR(res) = tmp + TIME_HOUR(x) + TIME_HOUR(y))) {
    TIME_HOUR(res) = TIME_HOUR(x) - 24 + TIME_HOUR(y) + tmp;
    tmp = 1;
  } else {
    tmp = 0;
  }
  if (31 < (TIME_DAY(res) = tmp + TIME_DAY(x) + TIME_DAY(y))) {
    TIME_DAY(res) = TIME_DAY(x) - 31 + TIME_DAY(y) + tmp;
    tmp = 1;
  } else {
    tmp = 0;
  }
  if (12 < (TIME_MONTH(res) = tmp + TIME_MONTH(x) + TIME_MONTH(y))) {
    TIME_MONTH(res) = TIME_MONTH(x) - 12 + TIME_MONTH(y) + tmp;
    tmp = 1;
  } else {
    tmp = 0;
  }
  if (DATA_MAX < (TIME_YEAR(res) = tmp + TIME_YEAR(x) + TIME_YEAR(y))) {
    TIME_YEAR(res) = TIME_YEAR(x) - 12 + TIME_YEAR(y) + tmp;
    tmp = 1;
  } else {
    tmp = 0;
  }

  return res;
}

TYPE FUNCTION(NAME, sub1)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, add1)(x, FUNCTION(NAME, opp1)(y));
}

TYPE FUNCTION(NAME, mul1)(const TYPE x, const TYPE y) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  TIME_SECOND(res) = TIME_SECOND(x);
  TIME_MINUTE(res) = TIME_MINUTE(x);
  TIME_HOUR(res) = TIME_HOUR(x);
  TIME_DAY(res) = TIME_DAY(x);
  TIME_MONTH(res) = TIME_MONTH(x);
  TIME_YEAR(res) = TIME_YEAR(x);

  return res;
}

TYPE FUNCTION(NAME, div1)(const TYPE x, const TYPE y) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;
  TIME_SECOND(res) = TIME_SECOND(x);
  TIME_MINUTE(res) = TIME_MINUTE(x);
  TIME_HOUR(res) = TIME_HOUR(x);
  TIME_DAY(res) = TIME_DAY(x);
  TIME_MONTH(res) = TIME_MONTH(x);
  TIME_YEAR(res) = TIME_YEAR(x);

  return res;
}
