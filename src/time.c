#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cgraph_file.h"
#include "cgraph_int.h"
#include "cgraph_memory.h"
#include "cgraph_time.h"

#define TYPE_TIME
#include "template.h"

/**/

#include "data_base.ct"

cgraph_int_t FUNCTION(NAME, printf)(const TYPE cthis) {
  if (TIME_ISTYPE1(cthis)) {
    return fprintf(stdout, OUT_FORMAT1, TIME_YEAR(cthis), TIME_MONTH(cthis),
                   TIME_DAY(cthis), TIME_HOUR(cthis), TIME_MINUTE(cthis),
                   TIME_SECOND(cthis));
  } else {
    return fprintf(stdout, OUT_FORMAT0, TIME_VALUE1(cthis), TIME_VALUE0(cthis));
  }
}

cgraph_int_t FUNCTION(NAME, fprintf)(FILE *fp, const TYPE cthis) {
  if (TIME_ISTYPE1(cthis)) {
    return fprintf(fp, OUT_FORMAT1, TIME_YEAR(cthis), TIME_MONTH(cthis),
                   TIME_DAY(cthis), TIME_HOUR(cthis), TIME_MINUTE(cthis),
                   TIME_SECOND(cthis));
  } else {
    return fprintf(fp, OUT_FORMAT0, TIME_VALUE1(cthis), TIME_VALUE0(cthis));
  }
}

cgraph_int_t FUNCTION(NAME, snprintf)(cgraph_char_t *buffer,
                                      const cgraph_size_t size,
                                      const TYPE cthis) {
  if (TIME_ISTYPE1(cthis)) {
    return cgraph_file_snprintf(buffer, size, OUT_FORMAT1, TIME_YEAR(cthis),
                                TIME_MONTH(cthis), TIME_DAY(cthis),
                                TIME_HOUR(cthis), TIME_MINUTE(cthis),
                                TIME_SECOND(cthis));
  } else {
    return cgraph_file_snprintf(buffer, size, OUT_FORMAT0, TIME_VALUE1(cthis),
                                TIME_VALUE0(cthis));
  }
}

cgraph_size_t FUNCTION(NAME, hash)(const TYPE cthis) {
  cgraph_size_t hash = 0;
  hash = (TIME_YEAR(cthis) << 13) + (TIME_MONTH(cthis) << 7) + TIME_DAY(cthis);

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE cthis) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if (TIME_ISTYPE1(cthis)) {
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
  } else {
    if ((TIME_VALUE0(cthis) | (TIME_VALUE0(cthis) >> 31)) !=
        (TIME_VALUE1(cthis) | (TIME_VALUE1(cthis) >> 30))) {
      flag = CGRAPH_FALSE;
    }
  }

  return flag;
}

CGRAPH_INLINE cgraph_int_t FUNCTION(NAME, signbit)(const TYPE x) {
  cgraph_int_t flag;
  if (TIME_ISTYPE1(x)) {
    flag = TIME_VALUE0(x) | (TIME_VALUE0(x) >> 31);
  } else {
    flag = TIME_SECOND(x) | (TIME_SECOND(x) >> 6);
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE x, const TYPE y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((TIME_TYPE(x) == TIME_TYPE(y)) && (TIME_VALUE0(x) == TIME_VALUE0(y)) &&
      (TIME_VALUE1(x) == TIME_VALUE1(y))) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ne)(const TYPE x, const TYPE y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((TIME_TYPE(x) == TIME_TYPE(y)) || (TIME_VALUE0(x) != TIME_VALUE0(y)) ||
      (TIME_VALUE1(x) != TIME_VALUE1(y))) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, gr)(const TYPE x, const TYPE y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((TIME_VALUE0(x) > TIME_VALUE0(y)) || (TIME_VALUE1(x) > TIME_VALUE1(y))) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ge)(const TYPE x, const TYPE y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((TIME_VALUE0(x) >= TIME_VALUE0(y)) ||
      (TIME_VALUE1(x) >= TIME_VALUE1(y))) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ls)(const TYPE x, const TYPE y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((TIME_VALUE0(x) < TIME_VALUE0(y)) || (TIME_VALUE1(x) < TIME_VALUE1(y))) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, le)(const TYPE x, const TYPE y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((TIME_VALUE0(x) <= TIME_VALUE0(y)) ||
      (TIME_VALUE1(x) <= TIME_VALUE1(y))) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

TYPE FUNCTION(NAME, init0)(const DATA_TYPE time0, const DATA_TYPE time1) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE0;
  TIME_VALUE0(res) = time0;
  TIME_VALUE1(res) = time1;

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

TYPE FUNCTION(NAME, localtime)(void) {
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

  return res;
}

TYPE FUNCTION(NAME, initc)(cgraph_char_t *cthis, const cgraph_char_t *sep) {
  TYPE res;
  cgraph_size_t i = 0;
  DATA_TYPE res_tmp[6] = {0};
  if ((NULL != cthis) && (NULL != sep)) {
    char *p = NULL;
    while ((NULL != (p = strtok(cthis, sep))) && (6 > i)) {
      res_tmp[i++] = atoi(p);
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
  TIME_VALUE0(res) = DATA_MIN >> 1;
  TIME_VALUE1(res) = DATA_MIN;

  return res;
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
  TIME_HOUR(res) = 24;
  TIME_MINUTE(res) = 60;
  TIME_SECOND(res) = 60;

  return res;
}

TYPE FUNCTION(NAME, add1i)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;

  return res;
}

TYPE FUNCTION(NAME, sub1i)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;

  return res;
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
  TIME_YEAR(res) = -TIME_YEAR(x);
  TIME_MONTH(res) = -TIME_MONTH(x);
  TIME_DAY(res) = -TIME_DAY(x);
  TIME_HOUR(res) = -TIME_HOUR(x);
  TIME_MINUTE(res) = -TIME_MINUTE(x);
  TIME_SECOND(res) = -TIME_SECOND(x);

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

  return res;
}

TYPE FUNCTION(NAME, div1)(const TYPE x, const TYPE y) {
  TYPE res;
  TIME_TYPE(res) = CGRAPH_TIME_TYPE1;

  return res;
}

#include "template_off.h"
