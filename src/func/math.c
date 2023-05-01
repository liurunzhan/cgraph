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

__INLINE__ cgraph_bool_t cgraph_math_ispsep(const cgraph_char_t data) {
  return CGRAPH_TEST(__PLAT_PSEP_C == data);
}

__INLINE__ cgraph_int_t cgraph_math_isendlx(const cgraph_char_t datax,
                                            const cgraph_char_t datay) {
#ifdef __CGRAPH_PLAT_WINDOWS
  return ((__PLAT_ENDL_C0 == datax) && (__PLAT_ENDL_C1 == datay)) ? 2 : 0;
#else
  return __PLAT_ENDL_C == datax;
#endif
}

__INLINE__ cgraph_int_t cgraph_math_isendly(const cgraph_char_t datax,
                                            const cgraph_char_t datay) {
#ifdef __CGRAPH_PLAT_WINDOWS
  return ((__PLAT_ENDL_C0 == datax) && (__PLAT_ENDL_C1 == datay))
             ? 2
             : ((__PLAT_ENDL_C1 == datay) ? 1 : 0);
#else
  return __PLAT_ENDL_C == datay;
#endif
}

__INLINE__ cgraph_bool_t cgraph_math_casematch(const cgraph_char_t datax,
                                               const cgraph_char_t datay) {
  cgraph_int_t delta = datax - datay;

  return CGRAPH_TEST(
      0 == delta || (cgraph_math_isalpha(datax) && cgraph_math_isalpha(datay) &&
                     (('a' - 'A') == delta || ('A' - 'a') == delta)));
}

__INLINE__ cgraph_bool_t cgraph_math_islogic(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' == data) || ('1' == data) || ('x' == data) ||
                     ('X' == data) || ('z' == data) || ('Z' == data));
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

/**
 * number = number,      number >= 0
 *          -number + 1, number < 0
 * for example, 1 = 0b00000001
 *             -1 = ~(0b00000001) + 1 = 0b11111111
 */
__INLINE__ cgraph_size_t cgraph_math_mod2(const cgraph_size_t x) {
  return ((cgraph_usize_t)x) & USIZE_C(1);
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

cgraph_uint64_t cgraph_math_crc(const cgraph_int_t bits,
                                const cgraph_uint64_t init,
                                const cgraph_uint64_t data,
                                const cgraph_uint64_t poly) {
  const cgraph_uint64_t mask = ~(UINT64_MASK << bits), msb = 1 << (bits - 1);
  cgraph_uint64_t res = init, temp = (data & res);

  CGRAPH_LOOP(i, 0, bits)
  res = ((res << 1) & mask) ^ (((res ^ temp) & msb) ? poly : UINT64_C(0));
  temp <<= 1;
  CGRAPH_LOOP_END

  return res & mask;
}

__INLINE__ cgraph_uint64_t cgraph_math_rotr(const cgraph_int_t bits,
                                            const cgraph_uint64_t data) {
  return (data >> bits) | (data << (UINT64_BITS - bits));
}

__INLINE__ cgraph_uint64_t cgraph_math_rotl(const cgraph_int_t bits,
                                            const cgraph_uint64_t data) {
  return (data << bits) | (data >> (UINT64_BITS - bits));
}

__INLINE__ cgraph_uint64_t cgraph_math_roundr(const cgraph_int_t bits,
                                              const cgraph_uint64_t data) {
  return (~(UINT64_MASK << bits)) & ((data >> 1) | ((~data) << (bits - 1)));
}

__INLINE__ cgraph_uint64_t cgraph_math_roundl(const cgraph_int_t bits,
                                              const cgraph_uint64_t data) {
  return (~(UINT64_MASK << bits)) & ((data << 1) | ((~data) >> (bits - 1)));
}

cgraph_uint64_t cgraph_math_lsfrr(const cgraph_int_t bits,
                                  const cgraph_uint64_t data) {
  return UINT64_C(0);
}

cgraph_uint64_t cgraph_math_lsfrl(const cgraph_int_t bits,
                                  const cgraph_uint64_t data) {
  return UINT64_C(0);
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

cgraph_size_t cgraph_math_primes(const cgraph_int_t data, cgraph_int_t *primes,
                                 cgraph_int_t *isprime) {
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

/**
 * Collatz Conjecture:
 * x[i+1] = x[i] / 2, if x[i] % 2 == 0
 *          3 * x[i] + 1, if x[i] % 2 == 1
 */
#define CGRAPH_MATH_COLLATZ(x)                                                 \
  ((x)&UINT64_C(1) ? (UINT64_C(3) * (x) + UINT64_C(1)) : ((x) >> 1))

cgraph_bool_t cgraph_math_iscollatz(const cgraph_uint64_t data,
                                    const cgraph_size_t iter) {
  const cgraph_size_t _iter =
      (SIZE_C(0) < iter) ? iter : CGRAPH_MATH_COLLATZ_MAX;
  cgraph_uint64_t _data = data;
  cgraph_size_t i = 0;
  for (; (1 < _data) && (i < _iter); i++) {
    _data = CGRAPH_MATH_COLLATZ(_data);
  }

  return (UINT64_C(1) == _data);
}

cgraph_uint64_t *cgraph_math_collatz(const cgraph_uint64_t data,
                                     cgraph_uint64_t *buffer,
                                     const cgraph_size_t bsize) {
  cgraph_size_t i = 0;
  if (NULL != buffer && (SIZE_C(0) < bsize)) {
    cgraph_uint64_t _data = data;
    for (*buffer = _data; (1 < _data) && (i < bsize); i++) {
      _data = CGRAPH_MATH_COLLATZ(_data);
      *(++buffer) = _data;
    }
  }

  return buffer;
}
#undef CGRAPH_MATH_COLLATZ

__INLINE__ cgraph_float64_t cgraph_math_agl2rad(const cgraph_float64_t angle) {
  return M_PI / 180.0 * angle;
}

__INLINE__ cgraph_float64_t cgraph_math_rad2agl(const cgraph_float64_t radian) {
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

cgraph_float64_t cgraph_math_2pixatan2(const cgraph_float64_t x,
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
  cgraph_int_t res = 0, _data = data;
  while (_data) {
    _data >>= 1;
    res++;
  }

  return (0 == res) ? 1 : res;
}

__INLINE__ cgraph_bool_t cgraph_math_ispow2i(const cgraph_int_t x) {
  return CGRAPH_TEST(x & (x - 1));
}

__INLINE__ cgraph_int_t cgraph_math_pow2i(const cgraph_int_t n) {
  return (0 <= n) ? (1 << n) : 0;
}

cgraph_int_t cgraph_math_log2i(const cgraph_int_t x) {
  cgraph_int_t res = 0, _x = x;
  while (1 < _x) {
    _x >>= 1;
    res++;
  }

  return res;
}

__INLINE__ cgraph_int_t cgraph_math_mod2i(const cgraph_int_t x) {
  return (x & 0x01U);
}

__INLINE__ cgraph_int_t cgraph_math_rmod2i(const cgraph_int_t x,
                                           const cgraph_int_t n) {
  return (x & (~(CGRAPH_INT_MASK << n)));
}

__INLINE__ cgraph_uint_t cgraph_math_bin2gray(const cgraph_uint_t data) {
  return (data ^ (data >> 1));
}

__INLINE__ cgraph_uint_t cgraph_math_gray2bin(const cgraph_uint_t data) {
  return (data ^ (data << 1));
}

cgraph_int_t cgraph_math_ceili_pow2(const cgraph_int_t x) {
  cgraph_int_t temp, res = x;
  while (temp = (res & (res - 1))) {
    res = temp;
  }

  return res << 1;
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
  while (0 < _n) {
    if (1 & _n) {
      res *= _x;
    }
    _n >>= 1;
    _x *= _x;
  }

  return res;
}

cgraph_int_t cgraph_math_powi_modi(const cgraph_int_t x, const cgraph_int_t n,
                                   const cgraph_int_t mod) {
  cgraph_int_t res = 1, _x = x, _n = n;
  while (0 < _n) {
    if (1 & _n) {
      res = (res * _x) % mod;
    }
    _n >>= 1;
    _x = (_x * _x) % mod;
  }

  return res % mod;
}

cgraph_int_t cgraph_math_muli(const cgraph_int_t x, const cgraph_int_t y) {
  cgraph_int_t res = 0, _x = x, _y = y;
  while (0 < _y) {
    if (1 & _y) {
      res += _x;
    }
    _x <<= 1;
    _y >>= 1;
  }

  return res;
}

cgraph_int_t cgraph_math_muli_modi(const cgraph_int_t x, const cgraph_int_t y,
                                   const cgraph_int_t mod) {
  cgraph_int_t res = 0, _x = x, _y = y;
  while (0 < _y) {
    if (1 & _y) {
      res = (res + _x) % mod;
    }
    _x = (_x << 1) % mod;
    _y >>= 1;
  }

  return res % mod;
}

void cgraph_math_addnan(const cgraph_char_t *str) {}

void cgraph_math_delnan(void) {}

cgraph_bool_t cgraph_math_isnan(const cgraph_char_t *str) {

  return CGRAPH_FALSE;
}

void cgraph_math_addinf(const cgraph_char_t *str) {}

void cgraph_math_delinf(void) {}

cgraph_bool_t cgraph_math_isinf(const cgraph_char_t *str) {
  return CGRAPH_FALSE;
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

/**
 * | type | A bits | R bits | G bits | B bits | mask | maximum |
 * | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
 * | RGB555 | 0 | 5 | 5 | 5 | 0x7FFF | 32767 |
 * | RGB565 | 0 | 5 | 6 | 5 | 0xFFFF | 65535 |
 * | RGB24 | 0 | 8 | 8 | 8 | 0xFFFFFF | 16581375 |
 * | RGB32 | 8 | 8 | 8 | 8 | 0xFFFFFFFF | 4294967295 |
 * | RGB2101010 | 2 | 10 | 10 | 10 | 0xFFFFFFFF | 4294967295 |
 **/

#define RGB_MASK UINT32_C(0xFFFFFF)
#define RGB_IMASK UINT32_C(0xFF)
#define RGB_MIN UINT32_C(0x00)
#define RGB_MAX RGB_MASK
#define RGB_DECLEN (8)
#define RGB_HEXLEN (6)

#define RGB555_MASK UINT32_C(0x7FFF)
#define RGB565_MASK UINT32_C(0xFFFF)
#define RGB24_MASK UINT32_C(0xFFFFFF)
#define RGB32_MASK UINT32_C(0xFFFFFFFF)
#define RGB2TTT_MASK UINT32_C(0xFFFFFFFF)

typedef union {
  cgraph_color_t data;
  struct {
    cgraph_color_t b : 8;
    cgraph_color_t g : 8;
    cgraph_color_t r : 8;
    cgraph_color_t a : 8;
  } rgb32;
  struct {
    cgraph_color_t b : 10;
    cgraph_color_t g : 10;
    cgraph_color_t r : 10;
    cgraph_color_t a : 2;
  } rgb2ttt;
  struct {
    cgraph_color_t b : 5;
    cgraph_color_t g : 6;
    cgraph_color_t r : 5;
  } rgb565;
  struct {
    cgraph_color_t b : 4;
    cgraph_color_t g : 4;
    cgraph_color_t r : 4;
    cgraph_color_t a : 4;
  } rgb4444;
  struct {
    cgraph_color_t b : 5;
    cgraph_color_t g : 5;
    cgraph_color_t r : 5;
    cgraph_color_t a : 1;
  } rgb1555;
} cgraph_rgb_t;

#define UINT2RGB(x) (*(cgraph_rgb_t *)&(x))
#define RGB2UINT(x) (x).data

#define RGB32(x) UINT2RGB(x).rgb32
#define RGB32_B(x) RGB32(x).b
#define RGB32_G(x) RGB32(x).g
#define RGB32_R(x) RGB32(x).r
#define RGB32_A(x) RGB32(x).a

#define RGB24(x) RGB32(x)
#define RGB24_B(x) RGB24(x).b
#define RGB24_G(x) RGB24(x).g
#define RGB24_R(x) RGB24(x).r

#define RGB2TTT(x) UINT2RGB(x).rgb2ttt
#define RGB2TTT_B(x) RGB2TTT(x).b
#define RGB2TTT_G(x) RGB2TTT(x).g
#define RGB2TTT_R(x) RGB2TTT(x).r
#define RGB2TTT_A(x) RGB2TTT(x).a

#define RGB4444(x) UINT2RGB(x).rgb4444
#define RGB4444_B(x) RGB4444(x).b
#define RGB4444_G(x) RGB4444(x).g
#define RGB4444_R(x) RGB4444(x).r
#define RGB4444_A(x) RGB4444(x).a

#define RGB565(x) UINT2RGB(x).rgb565
#define RGB565_B(x) RGB565(x).b
#define RGB565_G(x) RGB565(x).g
#define RGB565_R(x) RGB565(x).r

#define RGB1555(x) UINT2RGB(x).rgb1555
#define RGB1555_B(x) RGB1555(x).b
#define RGB1555_G(x) RGB1555(x).g
#define RGB1555_R(x) RGB1555(x).r
#define RGB1555_A(x) RGB1555(x).a

#define RGB555(x) RGB1555(x)
#define RGB555_B(x) RGB555(x).b
#define RGB555_G(x) RGB555(x).g
#define RGB555_R(x) RGB555(x).r

#ifdef RGB_R2A
#define RGB2A(rgb, a)                                                          \
  ((RGB_R2A * RGB32_R((rgb)) + RGB_G2A * RGB32_G((rgb)) +                      \
    RGB_B2A * RGB32_B((rgb)) + RGB_HAW) /                                      \
   RGB_AW)
#else
#define RGB2A(rgb, a) (a)
#endif

#define RGB2RGB32(rgb, a, r, g, b)                                             \
  do {                                                                         \
    RGB32_B((rgb)) = (b);                                                      \
    RGB32_G((rgb)) = (g);                                                      \
    RGB32_R((rgb)) = (r);                                                      \
    RGB32_R((rgb)) = RGB2A((rgb), (a));                                        \
  } while (0)

static struct {
  cgraph_char_t _s[1];
  cgraph_char_t a[2];
  cgraph_char_t r[4];
  cgraph_char_t g[4];
  cgraph_char_t b[4];
  cgraph_char_t _t[1];
} cgraph_rgb_hex = {{'#'},
                    {'0', '0'},
                    {'0', '0', '0', '0'},
                    {'0', '0', '0', '0'},
                    {'0', '0', '0', '0'},
                    {'\0'}};
#define CGRAPH_RGB_BUFFER ((cgraph_char_t *)&cgraph_rgb_hex)

__INLINE__ cgraph_bool_t cgraph_math_colchk(const cgraph_color_t color,
                                            const cgraph_int_t rgb_type) {
  return CGRAPH_TEST((~RGB_MASK) & color);
}

__INLINE__ cgraph_color_t cgraph_math_colfmt(const cgraph_color_t color,
                                             const cgraph_int_t rgb_type) {
  return (RGB_MASK & color);
}

__INLINE__ cgraph_color_t cgraph_math_rgb2col(const cgraph_color_t r,
                                              const cgraph_color_t g,
                                              const cgraph_color_t b) {
  cgraph_rgb_t rgb;
  RGB2RGB32(rgb, RGB_MIN, r, g, b);

  return rgb.data;
}

__INLINE__ cgraph_color_t cgraph_math_argb2col(const cgraph_color_t a,
                                               const cgraph_color_t r,
                                               const cgraph_color_t g,
                                               const cgraph_color_t b) {
  cgraph_rgb_t rgb;
  RGB2RGB32(rgb, a, r, g, b);

  return RGB2UINT(rgb);
}

__INLINE__ cgraph_color_t cgraph_math_rgb2argb(const cgraph_color_t r,
                                               const cgraph_color_t g,
                                               const cgraph_color_t b) {
  const cgraph_color_t a = (r + g + b) / 3;
  cgraph_rgb_t rgb;
  RGB2RGB32(rgb, a, r, g, b);

  return RGB2UINT(rgb);
}

__INLINE__ cgraph_color_t cgraph_math_rgb2argb_min(const cgraph_color_t r,
                                                   const cgraph_color_t g,
                                                   const cgraph_color_t b) {
  const cgraph_color_t a = CGRAPH_MIN3V(r, g, b);
  cgraph_rgb_t rgb;
  RGB2RGB32(rgb, a, r, g, b);

  return RGB2UINT(rgb);
}

__INLINE__ cgraph_color_t cgraph_math_rgb2argb_max(const cgraph_color_t r,
                                                   const cgraph_color_t g,
                                                   const cgraph_color_t b) {
  const cgraph_color_t a = CGRAPH_MAX3V(r, g, b);
  cgraph_rgb_t rgb;
  RGB2RGB32(rgb, a, r, g, b);

  return RGB2UINT(rgb);
}

/** alpha = 0.299r + 0.587g + 0.114b */
__INLINE__ cgraph_color_t cgraph_math_rgb2argb_gray(const cgraph_color_t r,
                                                    const cgraph_color_t g,
                                                    const cgraph_color_t b) {
#define RGB_R2A (299)
#define RGB_G2A (587)
#define RGB_B2A (114)
#define RGB_AW (1000)
#define RGB_HAW (RGB_AW >> 1)
  cgraph_rgb_t rgb;
  RGB2RGB32(rgb, RGB_MIN, r, g, b);

  return RGB2UINT(rgb);
#undef RGB_R2A
#undef RGB_G2A
#undef RGB_B2A
#undef RGB_AW
#undef RGB_HAW
}

/** alpha = 0.3r + 0.59g + 0.11b */
__INLINE__ cgraph_color_t cgraph_math_rgb2argb_y(const cgraph_color_t r,
                                                 const cgraph_color_t g,
                                                 const cgraph_color_t b) {
#define RGB_R2A (30)
#define RGB_G2A (59)
#define RGB_B2A (11)
#define RGB_AW (100)
#define RGB_HAW (RGB_AW >> 1)
  cgraph_rgb_t rgb;
  RGB2RGB32(rgb, RGB_MIN, r, g, b);

  return RGB2UINT(rgb);
#undef RGB_R2A
#undef RGB_G2A
#undef RGB_B2A
#undef RGB_AW
#undef RGB_HAW
}

__INLINE__ cgraph_color_t cgraph_math_col2a(const cgraph_color_t color) {
  return RGB32_A(color);
}

__INLINE__ cgraph_color_t cgraph_math_col2r(const cgraph_color_t color) {
  return RGB32_R(color);
}

__INLINE__ cgraph_color_t cgraph_math_col2g(const cgraph_color_t color) {
  return RGB32_G(color);
}

__INLINE__ cgraph_color_t cgraph_math_col2b(const cgraph_color_t color) {
  return RGB32_B(color);
}

const cgraph_char_t *cgraph_math_col2dec(const cgraph_color_t color) {
  cgraph_char_t *cstr = CGRAPH_RGB_BUFFER;
  cgraph_color_t res = color;
  cgraph_char_t *c = cstr + RGB_DECLEN;
  *c = '\0';
  CGRAPH_LOOP(i, 0, RGB_DECLEN)
  *(--c) = cgraph_math_dec2hex(color % 10);
  res /= 10;
  CGRAPH_LOOP_END

  return CGRAPH_RGB_BUFFER;
}

const cgraph_char_t *cgraph_math_col2hex(const cgraph_color_t color) {
  cgraph_char_t *cstr = CGRAPH_RGB_BUFFER;
  cgraph_color_t res = color;
  cgraph_char_t *c = cstr + RGB_HEXLEN;
  *c = '\0';
  CGRAPH_LOOP(i, 0, RGB_HEXLEN)
  *(--c) = cgraph_math_dec2hex(color & UINT32_C(0xF));
  res >>= 4;
  CGRAPH_LOOP_END

  return CGRAPH_RGB_BUFFER;
}

cgraph_color_t cgraph_math_dec2col(const cgraph_char_t *color) {
  cgraph_color_t res = RGB_MIN;
  if (CGRAPH_ISSTR(color)) {
    cgraph_size_t i = 0;
    cgraph_char_t *c = (cgraph_char_t *)color;
    if ('#' == *c) {
      c += 1;
    }
    for (; i < RGB_DECLEN; i++) {
      if (CGRAPH_FALSE == cgraph_math_isdec(c[i])) {
        break;
      }
      res = (res * 10) + cgraph_math_dec2dec(c[i]);
    }
    if ((RGB_MAX < res) || ('\0' != c[i])) {
      res = RGB_MIN;
    }
  }

  return res;
}

cgraph_color_t cgraph_math_hex2col(const cgraph_char_t *color) {
  cgraph_color_t res = RGB_MIN;
  if (CGRAPH_ISSTR(color)) {
    cgraph_size_t i = 0;
    cgraph_char_t *c = (cgraph_char_t *)color;
    if ('#' == *c) {
      c += 1;
    }
    for (; i < RGB_HEXLEN; i++) {
      if (CGRAPH_FALSE == cgraph_math_ishex(c[i])) {
        break;
      }
      res = (res << 4) + cgraph_math_hex2dec(c[i]);
    }
    if ((RGB_HEXLEN < i) || ('\0' != c[i])) {
      res = RGB_MIN;
    }
  }

  return res;
}
