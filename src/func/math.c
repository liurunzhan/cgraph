#include <ctype.h>

#include "cgraph_math.h"
#include "cgraph_memory.h"

cgraph_size_t cgraph_math_subc(cgraph_char_t *x, const cgraph_size_t len,
                               const cgraph_char_t ch) {
  cgraph_size_t _len = len;
  if (NULL != x) {
    cgraph_char_t *p1 = x, *p2 = x;
    CGRAPH_LOOP(i, 0, len)
    if (ch != *p1) {
      *(p2++) = *p1;
    } else {
      _len -= 1;
    }
    p1++;
    CGRAPH_LOOP_END
    *p2 = '\0';
  }

  return _len;
}

/*
  calculate KMP next function
*/
cgraph_size_t *cgraph_math_kmpnext(const cgraph_char_t *y, cgraph_size_t *next,
                                   const cgraph_size_t len) {
  if ((NULL != y) && (NULL != next)) {
    cgraph_size_t k = next[0] = 0;
    CGRAPH_LOOP(q, 1, len)
    while ((0 < k) && (y[k] != y[q])) {
      k = next[k - 1];
    }
    if (y[k] == y[q]) {
      k += 1;
    }
    next[q] = k;
    CGRAPH_LOOP_END
  }

  return next;
}

cgraph_size_t cgraph_math_kmpcnt(const cgraph_char_t *x,
                                 const cgraph_size_t size,
                                 const cgraph_char_t *y,
                                 const cgraph_size_t *next,
                                 const cgraph_size_t len) {
  cgraph_size_t cnt = 0;
  if ((NULL != x) && (NULL != y) && (NULL != next) && (0 < len)) {
    cgraph_size_t q = 0;
    CGRAPH_LOOP(i, 0, size)
    while ((0 < q) && (y[q] != x[i])) {
      q = next[q - 1];
    }
    if (y[q] == x[i]) {
      q += 1;
    }
    if (q == len) {
      q = next[q - 1];
      cnt += 1;
    }
    CGRAPH_LOOP_END
  }

  return cnt;
}

cgraph_size_t cgraph_math_kmpsub(const cgraph_char_t *x, cgraph_char_t *z,
                                 const cgraph_size_t size,
                                 const cgraph_char_t *y,
                                 const cgraph_size_t *next,
                                 const cgraph_size_t len) {
  cgraph_size_t _len = 0;
  if ((NULL != x) && (NULL != y) && (NULL != next) && (0 < len)) {
    cgraph_size_t q = 0, start = 0;
    CGRAPH_LOOP(i, 0, size)
    while ((0 < q) && (y[q] != x[i])) {
      q = next[q - 1];
    }
    if (y[q] == x[i]) {
      q += 1;
    }
    if (q == len) {
      cgraph_size_t end = i - len;
      q = next[q - 1];
      for (; start <= end; start++, _len++) {
        z[_len] = x[start];
      }
      start = i + 1;
    }
    CGRAPH_LOOP_END
    CGRAPH_LOOP(i, start, size)
    z[_len++] = x[i];
    CGRAPH_LOOP_END
    z[_len] = '\0';
  }

  return _len;
}

__INLINE__ cgraph_bool_t cgraph_math_isnum(const cgraph_char_t data) {
  return CGRAPH_TEST(isdigit(data));
}

__INLINE__ cgraph_bool_t cgraph_math_isalnum(const cgraph_char_t data) {
  return CGRAPH_TEST(isalnum(data));
}

__INLINE__ cgraph_bool_t cgraph_math_isalpha(const cgraph_char_t data) {
  return CGRAPH_TEST(isalpha(data));
}

__INLINE__ cgraph_bool_t cgraph_math_isblank(const cgraph_char_t data) {
#if __STDC_VERSION__ >= 199901L
  return CGRAPH_TEST(isblank(data));
#else
  return CGRAPH_TEST((' ' == data) || ('\t' == data));
#endif
}

__INLINE__ cgraph_bool_t cgraph_math_islower(const cgraph_char_t data) {
  return CGRAPH_TEST(islower(data));
}

__INLINE__ cgraph_bool_t cgraph_math_isprint(const cgraph_char_t data) {
  return CGRAPH_TEST(isprint(data));
}

__INLINE__ cgraph_bool_t cgraph_math_isspace(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data));
}

__INLINE__ cgraph_bool_t cgraph_math_isupper(const cgraph_char_t data) {
  return CGRAPH_TEST(isupper(data));
}

__INLINE__ cgraph_char_t cgraph_math_toupper(const cgraph_char_t data) {
  return toupper(data);
}

__INLINE__ cgraph_char_t cgraph_math_tolower(const cgraph_char_t data) {
  return tolower(data);
}

__INLINE__ cgraph_bool_t cgraph_math_ispsplit(const cgraph_char_t data) {
  return CGRAPH_TEST(__PLAT_PSPLIT_C == data);
}

__INLINE__ cgraph_int_t cgraph_math_isnline(const cgraph_char_t datax,
                                            const cgraph_char_t datay) {
#ifdef __CGRAPH_PLAT_WINDOWS
  return ((__PLAT_LEND_C0 == datax) && (__PLAT_LEND_C1 == datay)) ? 2 : 0;
#else
  return __PLAT_LEND_C == datax;
#endif
}

__INLINE__ cgraph_int_t cgraph_math_isnliney(const cgraph_char_t datax,
                                             const cgraph_char_t datay) {
#ifdef __CGRAPH_PLAT_WINDOWS
  return ((__PLAT_LEND_C0 == datax) && (__PLAT_LEND_C1 == datay)) ? 2 : 0;
#else
  return __PLAT_LEND_C == datay;
#endif
}

__INLINE__ cgraph_bool_t cgraph_math_isbin(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' == data) || ('1' == data));
}

__INLINE__ extern cgraph_bool_t cgraph_math_isoct(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' <= data) && ('7' >= data));
}

__INLINE__ cgraph_bool_t cgraph_math_isdec(const cgraph_char_t data) {
  return CGRAPH_TEST(isdigit(data));
}

__INLINE__ cgraph_bool_t cgraph_math_ishex(const cgraph_char_t data) {
  return CGRAPH_TEST(isxdigit(data));
}

__INLINE__ cgraph_bool_t cgraph_math_isbinhd(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data) || ('0' == data));
}

__INLINE__ cgraph_bool_t cgraph_math_isbinst(const cgraph_char_t data) {
  return CGRAPH_TEST('1' == data);
}

__INLINE__ cgraph_bool_t cgraph_math_isbinmd(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' == data) || ('1' == data));
}

__INLINE__ cgraph_bool_t cgraph_math_isbined(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' == data) || ('1' == data));
}

__INLINE__ cgraph_bool_t cgraph_math_isbintl(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data));
}

__INLINE__ cgraph_bool_t cgraph_math_isocthd(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data) || ('0' == data));
}

__INLINE__ cgraph_bool_t cgraph_math_isoctst(const cgraph_char_t data) {
  return CGRAPH_TEST(('1' <= data) && ('7' >= data));
}

__INLINE__ cgraph_bool_t cgraph_math_isoctmd(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' <= data) && ('7' >= data));
}

__INLINE__ cgraph_bool_t cgraph_math_isocted(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' <= data) && ('7' >= data));
}

__INLINE__ cgraph_bool_t cgraph_math_isocttl(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data));
}

__INLINE__ cgraph_bool_t cgraph_math_isdechd(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data) || ('0' == data));
}

__INLINE__ cgraph_bool_t cgraph_math_isdecst(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' != data) && isdigit(data));
}

__INLINE__ cgraph_bool_t cgraph_math_isdecmd(const cgraph_char_t data) {
  return CGRAPH_TEST(isdigit(data));
}

__INLINE__ cgraph_bool_t cgraph_math_isdeced(const cgraph_char_t data) {
  return CGRAPH_TEST(isdigit(data));
}

__INLINE__ cgraph_bool_t cgraph_math_isdectl(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data));
}

__INLINE__ cgraph_bool_t cgraph_math_ishexhd(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data) || ('0' == data));
}

__INLINE__ cgraph_bool_t cgraph_math_ishexst(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' != data) && isxdigit(data));
}

__INLINE__ cgraph_bool_t cgraph_math_ishexmd(const cgraph_char_t data) {
  return CGRAPH_TEST(isxdigit(data));
}

__INLINE__ cgraph_bool_t cgraph_math_ishexed(const cgraph_char_t data) {
  return CGRAPH_TEST(isxdigit(data));
}

__INLINE__ cgraph_bool_t cgraph_math_ishextl(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data));
}

__INLINE__ cgraph_bool_t cgraph_math_isnumhd(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data) || ('0' == data));
}

__INLINE__ cgraph_bool_t cgraph_math_isnumst(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' != data) && isdigit(data));
}

__INLINE__ cgraph_bool_t cgraph_math_isnummd(const cgraph_char_t data) {
  return CGRAPH_TEST(isdigit(data) || ('.' == data));
}

__INLINE__ cgraph_bool_t cgraph_math_isnumed(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' != data) && isdigit(data));
}

__INLINE__ cgraph_bool_t cgraph_math_isnumtl(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data) || ('0' == data));
}

__INLINE__ cgraph_bool_t cgraph_math_isnamhd(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data));
}

__INLINE__ cgraph_bool_t cgraph_math_isnamst(const cgraph_char_t data) {
  return CGRAPH_TEST(isalpha(data) || ('_' == data));
}

__INLINE__ cgraph_bool_t cgraph_math_isnammd(const cgraph_char_t data) {
  return CGRAPH_TEST(isalnum(data) || ('_' == data));
}

__INLINE__ cgraph_bool_t cgraph_math_isnamed(const cgraph_char_t data) {
  return CGRAPH_TEST(isalnum(data) || ('_' == data));
}

__INLINE__ cgraph_bool_t cgraph_math_isnamtl(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data));
}

__INLINE__ cgraph_bool_t cgraph_math_iscopt(const cgraph_char_t data) {
  return cgraph_math_isnamst(data) ? CGRAPH_FALSE : cgraph_math_isnumst(data);
}

__INLINE__ cgraph_bool_t cgraph_math_iscdoc(const cgraph_char_t datax,
                                            const cgraph_char_t datay) {
  return CGRAPH_TEST((('/' == datax) && (('/' == datay) || ('*' == datay))) ||
                     (('*' == datax) && ('/' == datay)));
}

__INLINE__ cgraph_bool_t cgraph_math_isclpair(const cgraph_char_t data) {
  return CGRAPH_TEST(('(' == data) || ('[' == data) || ('{' == data) ||
                     ('\'' == data) || ('\"' == data));
}

__INLINE__ cgraph_bool_t cgraph_math_iscrpair(const cgraph_char_t data) {
  return CGRAPH_TEST((')' == data) || (']' == data) || ('}' == data) ||
                     ('\'' == data) || ('\"' == data));
}

__INLINE__ cgraph_bool_t cgraph_math_iscpair(const cgraph_char_t data) {
  return cgraph_math_isclpair(data) ? CGRAPH_TRUE : cgraph_math_iscrpair(data);
}

__INLINE__ cgraph_int_t cgraph_math_bin2dec(const cgraph_char_t data) {
  return ('0' == data) ? 0 : 1;
}

__INLINE__ cgraph_char_t cgraph_math_dec2bin(const cgraph_int_t data) {
  return (0 == data) ? '0' : '1';
}

__INLINE__ cgraph_int_t cgraph_math_dec2dec(const cgraph_char_t data) {
  return (('0' <= data) && ('9' >= data)) ? (data - '0') : MATH_ERROR;
}

__INLINE__ cgraph_int_t cgraph_math_hex2dec(const cgraph_char_t data) {
  cgraph_int_t res = MATH_ERROR;
  if (('0' <= data) && ('9' >= data)) {
    res = data - '0';
    goto SUCCESS;
  }
  if (('A' <= data) && ('F' >= data)) {
    res = data - 'A' + 10;
    goto SUCCESS;
  }
  if (('a' <= data) && ('f' >= data)) {
    res = data - 'a' + 10;
    goto SUCCESS;
  }

SUCCESS:
  return res;
}

static const cgraph_char_t __cgraph_math_dec2hex_upper__[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

__INLINE__ cgraph_char_t cgraph_math_dec2uhex(const cgraph_int_t data) {
  return (data >= 0 && data < 16) ? __cgraph_math_dec2hex_upper__[data] : '\0';
}

static const cgraph_char_t __cgraph_math_dec2hex_lower__[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

__INLINE__ cgraph_char_t cgraph_math_dec2lhex(const cgraph_int_t data) {
  return (data >= 0 && data < 16) ? __cgraph_math_dec2hex_lower__[data] : '\0';
}

cgraph_size_t cgraph_math_binlen(const cgraph_char_t *data,
                                 const cgraph_size_t len,
                                 cgraph_char_t **start) {
  cgraph_size_t _len = 0;
  if (NULL != data) {
    cgraph_size_t i = 0;
    cgraph_char_t *_data = (cgraph_char_t *)data;
    for (; cgraph_math_isbinhd(*_data) && (i < len); _data++, i++) {
    }
    if (cgraph_math_isbinst(*_data)) {
      if (NULL != start) {
        *start = _data;
      }
      for (_data++, i++, _len++; cgraph_math_isbinmd(*_data) && (i < len);
           _data++, i++, _len++) {
      }
    }
  }

  return _len;
}

cgraph_size_t cgraph_math_declen(const cgraph_char_t *data,
                                 const cgraph_size_t len,
                                 cgraph_char_t **start) {
  cgraph_size_t _len = 0;
  if (NULL != data) {
    cgraph_size_t i = 0;
    cgraph_char_t *_data = (cgraph_char_t *)data;
    for (; cgraph_math_isdechd(*_data) && (i < len); _data++, i++) {
    }
    if (cgraph_math_isdecst(*_data)) {
      if (NULL != start) {
        *start = _data;
      }
      for (_data++, i++, _len++; cgraph_math_isdecmd(*_data) && (i < len);
           _data++, i++, _len++) {
      }
    }
  }

  return _len;
}

cgraph_size_t cgraph_math_hexlen(const cgraph_char_t *data,
                                 const cgraph_size_t len,
                                 cgraph_char_t **start) {
  cgraph_size_t _len = 0;
  if (NULL != data) {
    cgraph_size_t i = 0;
    cgraph_char_t *_data = (cgraph_char_t *)data;
    for (; cgraph_math_ishexhd(*_data) && (i < len); _data++, i++) {
    }
    if (cgraph_math_ishexst(*_data)) {
      if (NULL != start) {
        *start = _data;
      }
      for (_data++, i++, _len++; cgraph_math_ishexmd(*_data) && (i < len);
           _data++, i++, _len++) {
      }
    }
  }

  return _len;
}

cgraph_size_t cgraph_math_numlen(const cgraph_char_t *data,
                                 const cgraph_size_t len,
                                 cgraph_char_t **start) {
  cgraph_size_t _len = 0;
  if (NULL != data) {
    cgraph_size_t i = 0;
    cgraph_char_t *_data = (cgraph_char_t *)data;
    for (; cgraph_math_isnumhd(*_data) && (i < len); _data++, i++) {
    }
    if (cgraph_math_isnumst(*_data)) {
      if (NULL != start) {
        *start = _data;
      }
      for (_data++, i++, _len++; cgraph_math_isnummd(*_data) && (i < len);
           _data++, i++, _len++) {
      }
    }
  }

  return _len;
}

cgraph_size_t cgraph_math_namlen(const cgraph_char_t *data,
                                 const cgraph_size_t len,
                                 cgraph_char_t **start) {
  cgraph_size_t _len = 0;
  if (NULL != data) {
    cgraph_size_t i = 0;
    cgraph_char_t *_data = (cgraph_char_t *)data;
    for (; cgraph_math_isnamhd(*_data) && (i < len); _data++, i++) {
    }
    if (cgraph_math_isnamst(*_data)) {
      if (NULL != start) {
        *start = _data;
      }
      for (_data++, i++, _len++; cgraph_math_isnammd(*_data) && (i < len);
           _data++, i++, _len++) {
      }
    }
  }

  return _len;
}

cgraph_size_t cgraph_math_baslen(const cgraph_int_t data,
                                 const cgraph_int_t base) {
  cgraph_size_t len = 0;
  cgraph_int_t new_data = data;
  while (0 != new_data) {
    new_data = new_data / base;
    len += 1;
  }

  return len;
}

cgraph_int_t cgraph_math_chbase(cgraph_int_t *old, const cgraph_size_t old_len,
                                cgraph_int_t old_base, cgraph_int_t *new,
                                const cgraph_size_t new_len,
                                cgraph_int_t new_base) {
  cgraph_size_t len = 0;
  if ((NULL != old) && (NULL != new)) {
    cgraph_size_t start = 0, i;
    cgraph_int_t num, res;
    while ((start < old_len) && (len < new_len)) {
      for (res = 0, i = start; i < old_len; i++) {
        num = old[i] + res * old_base;
        res = num % new_base;
        old[i] = num / new_base;
      }
      new[len++] = res;
      while (0 == old[start]) {
        start++;
      }
    }
  }

  return len;
}

__INLINE__ cgraph_size_t cgraph_math_mod2(const cgraph_size_t x) {
  return (0 <= x) ? (x & USIZE_C(1)) : (-(x & USIZE_C(1)));
}

__INLINE__ cgraph_size_t cgraph_math_mod3(const cgraph_size_t x) {
  return (x % 3);
}

cgraph_uint64_t cgraph_math_gcd(const cgraph_uint64_t x,
                                const cgraph_uint64_t y) {
  cgraph_uint64_t _x = x, _y = y;
  if (0 == _y) {
    _x = 0;
  } else {
    cgraph_uint64_t tmp;
    while (0 != _y) {
      tmp = _x;
      _x = _y;
      _y = tmp % _y;
    }
  }

  return _x;
}

cgraph_uint64_t cgraph_math_lcm(const cgraph_uint64_t x,
                                const cgraph_uint64_t y) {
  cgraph_uint64_t gcd = cgraph_math_gcd(x, y);
  return (0 == gcd) ? 0 : ((1 == gcd) ? (x * y) : (x / gcd * y));
}

cgraph_uint64_t cgraph_math_crc(const cgraph_uint64_t predata,
                                const cgraph_uint64_t data,
                                const cgraph_uint64_t poly) {
  cgraph_uint64_t res = predata, temp = (data & res);
  CGRAPH_LOOP(i, 0, CGRAPH_UINT64_BITS)
  cgraph_uint64_t msb = (((res ^ temp) >> (CGRAPH_UINT64_BITS - 1)) & 0x01U);
  if (msb == 1) {
    res = (((res << 1) ^ CGRAPH_UINT64_MAX) & poly);
  } else {
    res = (res << 1);
  }
  temp = (temp << 1);
  CGRAPH_LOOP_END

  return res;
}

cgraph_bool_t cgraph_math_isprime(const cgraph_int_t data) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  cgraph_int_t tmp;
  if (2 > data) {
    flag = CGRAPH_FALSE;
  } else if ((2 == data) || (3 == data)) {
    flag = CGRAPH_TRUE;
  } else if ((1 != (tmp = (data % 6))) && (5 != tmp)) {
    flag = CGRAPH_FALSE;
  } else {
    cgraph_int_t root = sqrt(data), i;
    for (i = 5; i <= root; i += 6) {
      if ((0 == (data % i)) || (0 == (data % (i + 2)))) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }

  return flag;
}

cgraph_size_t cgraph_math_primes(cgraph_int_t *primes, cgraph_int_t *isprime,
                                 const cgraph_int_t data) {
  cgraph_size_t counter = 0;
  cgraph_size_t j;
  if ((NULL == primes) || (NULL == isprime) || (0 >= data)) {
    goto CERROR;
  }
  CGRAPH_LOOP(i, 0, data)
  primes[i] = 0;
  isprime[i] = CGRAPH_TRUE;
  CGRAPH_LOOP_END
  CGRAPH_LOOP(i, 2, data)
  if (isprime[i] == CGRAPH_TRUE) {
    primes[counter++] = i;
  }
  for (j = 0; (j < counter) && (i * primes[j] < data); j++) {
    isprime[i * primes[j]] = CGRAPH_FALSE;
    if (i % primes[j] == 0) {
      break;
    }
  }
  CGRAPH_LOOP_END

  return counter;
CERROR:
  return 0;
}

__INLINE__ cgraph_float64_t cgraph_math_ang2rad(const cgraph_float64_t angle) {
  return M_PI / 180.0 * angle;
}

__INLINE__ cgraph_float64_t cgraph_math_rad2ang(const cgraph_float64_t radian) {
  return 180.0 * M_1_PI * radian;
}

__INLINE__ cgraph_float64_t cgraph_math_ceil(const cgraph_float64_t x) {
  return ceil(x);
}

__INLINE__ cgraph_float64_t cgraph_math_floor(const cgraph_float64_t x) {
  return floor(x);
}

__INLINE__ cgraph_float64_t cgraph_math_log2(const cgraph_float64_t x) {
  return M_INVLN2 * log(x);
}

cgraph_float64_t cgraph_math_logn(const cgraph_float64_t n,
                                  const cgraph_float64_t x) {
  return log(x) / log(n);
}

cgraph_float64_t cgraph_math_atan2(const cgraph_float64_t x,
                                   const cgraph_float64_t y) {
  return atan2(x, y);
}

cgraph_float64_t cgraph_math_2_pi_atan2(const cgraph_float64_t x,
                                        const cgraph_float64_t y) {
  return M_2_PI * atan2(x, y);
}

cgraph_size_t cgraph_math_deccnt(const cgraph_int_t x, const cgraph_int_t n) {
  cgraph_size_t cnt = 0;
  if ((0 < x) && ((0 <= n) && (9 >= n))) {
    cgraph_int_t _x = x;
    for (; 0 < _x; _x /= 10) {
      if (n == (_x % 10)) {
        cnt += 1;
      }
    }
  }

  return cnt;
}

cgraph_size_t cgraph_math_rdeccnt(const cgraph_int_t x, const cgraph_int_t n) {
  cgraph_size_t cnt = 0;
  if ((0 < x) && ((0 <= n) && (9 >= n))) {
    cgraph_int_t _x = x, base = 1;
    for (; 0 < _x; base *= 10) {
      cgraph_int_t weight = _x % 10;
      _x /= 10;
      cnt += _x * base;
      if (n == weight) {
        cnt += (n % base) + 1;
      } else if (n < weight) {
        cnt += base;
      }
    }
  }

  return cnt;
}

cgraph_int_t cgraph_math_abitlen(const cgraph_uint_t data) {
  cgraph_int_t res = 0, num = data;
  while (0 != num) {
    num = num >> 1;
    res++;
  }

  return (0 == res) ? 1 : res;
}

__INLINE__ cgraph_int_t cgraph_math_pow2i(const cgraph_int_t n) {
  return (n >= 0) ? (1 << n) : 0;
}

cgraph_int_t cgraph_math_log2i(const cgraph_int_t x) {
  cgraph_int_t res = 0, num = x;
  while (num > 1) {
    num = num >> 1;
    res++;
  }

  return res;
}

__INLINE__ cgraph_int_t cgraph_math_mod2i(const cgraph_int_t x) {
  return (x & 0x01U);
}

__INLINE__ cgraph_int_t cgraph_math_rmod2i(const cgraph_int_t x,
                                           const cgraph_int_t n) {
  return (x & (~(CGRAPH_INT_MIN << n)));
}

__INLINE__ cgraph_uint_t cgraph_math_bin2gray(const cgraph_uint_t data) {
  return (data ^ (data >> 1));
}

__INLINE__ cgraph_uint_t cgraph_math_gray2bin(const cgraph_uint_t data) {
  return (data ^ (data << 1));
}

__INLINE__ cgraph_int_t cgraph_math_ceili(const cgraph_int_t x,
                                          const cgraph_int_t y) {
  return (x + y - 1) / y;
}

__INLINE__ cgraph_int_t cgraph_math_floori(const cgraph_int_t x,
                                           const cgraph_int_t y) {
  return x / y;
}

cgraph_int_t cgraph_math_powi(const cgraph_int_t x, const cgraph_int_t n) {
  cgraph_int_t res = 1, _x = x, _n = n;
  while (_n > 0) {
    if (_n & 1) {
      res *= _x;
    }
    _n >>= 1;
    _x *= _x;
  }

  return res;
}

cgraph_int_t cgraph_math_powi_mod(const cgraph_int_t x, const cgraph_int_t n,
                                  const cgraph_int_t mod) {
  cgraph_int_t res = 1, _x = x, _n = n;
  while (_n > 0) {
    if (_n & 1) {
      res = (res * _x) % mod;
    }
    _n >>= 1;
    _x = (_x * _x) % mod;
  }

  return res % mod;
}

cgraph_int_t cgraph_math_muli(const cgraph_int_t x, const cgraph_int_t y) {
  cgraph_int_t res = 0, _x = x, _y = y;
  while (_y > 0) {
    if (_y & 1) {
      res += _x;
    }
    _x <<= 1;
    _y >>= 1;
  }

  return res;
}

cgraph_int_t cgraph_math_muli_mod(const cgraph_int_t x, const cgraph_int_t y,
                                  const cgraph_int_t mod) {
  cgraph_int_t res = 0, _x = x, _y = y;
  while (_y > 0) {
    if (_y & 1) {
      res = (res + _x) % mod;
    }
    _x = (_x << 1) % mod;
    _y >>= 1;
  }

  return res % mod;
}

/**
 * Function : sigmoid
 * Express  : f(x) = 1.0 / (1.0 + exp(-x))
 */
cgraph_float64_t cgraph_math_sigmoid(const cgraph_float64_t x) {
  return 1.0 / (1.0 + exp(-1.0 * x));
}

/**
 * Function : tanh
 * Express  : f(x) = tanh(x)
 *                 = (exp(x) - exp(-x)) / (exp(x) + exp(-x)))
 *                 = 2.0 / (1.0 + exp(-2.0*x)) - 1.0
 */
cgraph_float64_t cgraph_math_tanh(const cgraph_float64_t x) {
  return (2.0 / (1.0 + exp(-2.0 * x)) - 1.0);
}

/**
 * Function : ReLU
 * Express  : f(x) = max{x, 0.0}
 */
cgraph_float64_t cgraph_math_relu(const cgraph_float64_t x) {
  return ((0.0 < x) ? x : 0.0);
}

/**
 * Function : Leaky ReLU
 * Express  : f(x) = x, if x > 0.0
 *                 = a * x, if x <= 0.0
 */
cgraph_float64_t cgraph_math_leaky_relu(const cgraph_float64_t x,
                                        const cgraph_float64_t a) {
  return ((0.0 < x) ? x : (a * x));
}

/**
 * Function : ELU
 * Express  : f(x) = x, if x > 0.0
 *                 = a * (exp(x) - 1.0), if x <= 0.0
 */
cgraph_float64_t cgraph_math_elu(const cgraph_float64_t x,
                                 const cgraph_float64_t a) {
  return ((0.0 < x) ? x : (a * (exp(x) - 1.0)));
}

/**
 * Function : PReLU
 * Express  : f(x) = x, if x > 0.0
 *                 = a * x, if x <= 0.0
 */
cgraph_float64_t cgraph_math_prelu(const cgraph_float64_t x,
                                   const cgraph_float64_t a) {
  return ((0.0 < x) ? x : (a * x));
}

/**
 * Function : Swish
 * Express  : f(x) = x * sigmoid(x)
 */
cgraph_float64_t cgraph_math_swish(const cgraph_float64_t x) {
  return x * cgraph_math_sigmoid(x);
}

/**
 * Function : Softplus
 * Express : f(x) = ln(1.0 + exp(x))
 */
cgraph_float64_t cgraph_math_softplus(const cgraph_float64_t x) {
  return log(1.0 + exp(x));
}

/* 0xFFFFFF = 16581375 */
#define CGRAPH_MATH_RGB_MASK UINT32_C(0xFFFFFF)
#define CGRAPH_MATH_RGB_IMASK UINT32_C(0xFF)
#define CGRAPH_MATH_RGB_MIN UINT32_C(0)
#define CGRAPH_MATH_RGB_MAX CGRAPH_MATH_RGB_MASK
#define CGRAPH_MATH_RGB_DECLEN (8)
#define CGRAPH_MATH_RGB_HEXLEN (6)
__INLINE__ cgraph_bool_t cgraph_math_colchk(const cgraph_uint32_t color) {
  return CGRAPH_TEST((~CGRAPH_MATH_RGB_MASK) & color);
}

__INLINE__ cgraph_uint32_t cgraph_math_colfmt(const cgraph_uint32_t color) {
  return (CGRAPH_MATH_RGB_MASK & color);
}

__INLINE__ cgraph_uint32_t cgraph_math_col2r(const cgraph_uint32_t color) {
  return (CGRAPH_MATH_RGB_IMASK & (color));
}

__INLINE__ cgraph_uint32_t cgraph_math_col2g(const cgraph_uint32_t color) {
  return (CGRAPH_MATH_RGB_IMASK & (color >> 8));
}

__INLINE__ cgraph_uint32_t cgraph_math_col2b(const cgraph_uint32_t color) {
  return (CGRAPH_MATH_RGB_IMASK & (color >> 16));
}

cgraph_char_t *cgraph_math_col2dec(const cgraph_uint32_t color,
                                   cgraph_char_t *cstr) {
  if (NULL != cstr) {
    cgraph_uint32_t res = color;
    cgraph_char_t *c = cstr + CGRAPH_MATH_RGB_DECLEN;
    *c = '\0';
    CGRAPH_LOOP(i, 0, CGRAPH_MATH_RGB_DECLEN)
    *(--c) = cgraph_math_dec2hex(color % 10);
    res /= 10;
    CGRAPH_LOOP_END
  }

  return cstr;
}

cgraph_char_t *cgraph_math_col2hex(const cgraph_uint32_t color,
                                   cgraph_char_t *cstr) {
  if (NULL != cstr) {
    cgraph_uint32_t res = color;
    cgraph_char_t *c = cstr + CGRAPH_MATH_RGB_HEXLEN;
    *c = '\0';
    CGRAPH_LOOP(i, 0, CGRAPH_MATH_RGB_HEXLEN)
    *(--c) = cgraph_math_dec2hex(color & UINT32_C(0xF));
    res >>= 4;
    CGRAPH_LOOP_END
  }

  return cstr;
}

cgraph_uint32_t cgraph_math_dec2col(const cgraph_char_t *color) {
  cgraph_uint32_t res = CGRAPH_MATH_RGB_MIN;
  if (CGRAPH_ISSTR(color)) {
    cgraph_size_t i = 0;
    cgraph_char_t *c = (cgraph_char_t *)color;
    if ('#' == *c) {
      c += 1;
    }
    for (; i < CGRAPH_MATH_RGB_DECLEN; i++) {
      if (CGRAPH_FALSE == cgraph_math_isdec(c[i])) {
        break;
      }
      res = (res * 10) + cgraph_math_dec2dec(c[i]);
    }
    if ((CGRAPH_MATH_RGB_MAX < res) || ('\0' != c[i])) {
      res = CGRAPH_MATH_RGB_MIN;
    }
  }

  return res;
}

cgraph_uint32_t cgraph_math_hex2col(const cgraph_char_t *color) {
  cgraph_uint32_t res = CGRAPH_MATH_RGB_MIN;
  if (CGRAPH_ISSTR(color)) {
    cgraph_size_t i = 0;
    cgraph_char_t *c = (cgraph_char_t *)color;
    if ('#' == *c) {
      c += 1;
    }
    for (; i < CGRAPH_MATH_RGB_HEXLEN; i++) {
      if (CGRAPH_FALSE == cgraph_math_ishex(c[i])) {
        break;
      }
      res = (res << 4) + cgraph_math_hex2dec(c[i]);
    }
    if ((CGRAPH_MATH_RGB_HEXLEN < i) || ('\0' != c[i])) {
      res = CGRAPH_MATH_RGB_MIN;
    }
  }

  return res;
}
