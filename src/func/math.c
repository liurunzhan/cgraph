#include <ctype.h>

#include "cgraph_math.h"

cgraph_size_t cgraph_math_subc(cgraph_char_t *x, const cgraph_size_t len,
                               const cgraph_char_t ch) {
  cgraph_size_t _len = len;
  if (NULL != x) {
    cgraph_char_t *p1 = x, *p2 = x;
    cgraph_size_t i = 0;
    for (; i < len; p1++, i++) {
      if (ch != *p1) {
        *(p2++) = *p1;
      } else {
        _len -= 1;
      }
    }
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
    cgraph_size_t k = next[0] = 0, q = 1;
    for (; q < len; q++) {
      while ((0 < k) && (y[k] != y[q])) {
        k = next[k - 1];
      }
      if (y[k] == y[q]) {
        k += 1;
      }
      next[q] = k;
    }
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
    cgraph_size_t i = 0, q = 0;
    for (; i < size; i++) {
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
    }
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
    cgraph_size_t i = 0, q = 0, start = 0;
    for (; i < size; i++) {
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
    }
    for (; start < size; start++, _len++) {
      z[_len] = x[start];
    }
    z[_len] = '\0';
  }

  return _len;
}

__INLINE cgraph_bool_t cgraph_math_isnum(const cgraph_char_t data) {
  return CGRAPH_TEST(isdigit(data));
}

__INLINE cgraph_bool_t cgraph_math_isalnum(const cgraph_char_t data) {
  return CGRAPH_TEST(isalnum(data));
}

__INLINE cgraph_bool_t cgraph_math_isalpha(const cgraph_char_t data) {
  return CGRAPH_TEST(isalpha(data));
}

__INLINE cgraph_bool_t cgraph_math_isblank(const cgraph_char_t data) {
#if __STDC_VERSION__ >= 199901L
  return CGRAPH_TEST(isblank(data));
#else
  return CGRAPH_TEST((' ' == data) || ('\t' == data));
#endif
}

__INLINE cgraph_bool_t cgraph_math_islower(const cgraph_char_t data) {
  return CGRAPH_TEST(islower(data));
}

__INLINE cgraph_bool_t cgraph_math_isprint(const cgraph_char_t data) {
  return CGRAPH_TEST(isprint(data));
}

__INLINE cgraph_bool_t cgraph_math_isspace(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data));
}

__INLINE cgraph_bool_t cgraph_math_isupper(const cgraph_char_t data) {
  return CGRAPH_TEST(isupper(data));
}

__INLINE cgraph_char_t cgraph_math_toupper(const cgraph_char_t data) {
  return toupper(data);
}

__INLINE cgraph_char_t cgraph_math_tolower(const cgraph_char_t data) {
  return tolower(data);
}

__INLINE cgraph_bool_t cgraph_math_ispsplit(const cgraph_char_t data) {
  return CGRAPH_TEST(__PLAT_PSPLIT_C == data);
}

__INLINE cgraph_bool_t cgraph_math_isnline(const cgraph_char_t datax,
                                           const cgraph_char_t datay) {
#ifdef __CGRAPH_PLAT_WINDOWS
  return CGRAPH_TEST((__PLAT_LEND_C0 != datax) && (__PLAT_LEND_C1 != datay));
#else
  return CGRAPH_TEST(__PLAT_LEND_C != datax);
#endif
}

__INLINE cgraph_bool_t cgraph_math_isbin(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' == data) || ('1' == data));
}

__INLINE cgraph_bool_t cgraph_math_isdec(const cgraph_char_t data) {
  return CGRAPH_TEST(isdigit(data));
}

__INLINE cgraph_bool_t cgraph_math_ishex(const cgraph_char_t data) {
  return CGRAPH_TEST(isxdigit(data));
}

__INLINE cgraph_bool_t cgraph_math_isbinhd(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data) || ('0' == data));
}

__INLINE cgraph_bool_t cgraph_math_isbinst(const cgraph_char_t data) {
  return CGRAPH_TEST('1' == data);
}

__INLINE cgraph_bool_t cgraph_math_isbinmd(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' == data) || ('1' == data));
}

__INLINE cgraph_bool_t cgraph_math_isbined(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' == data) || ('1' == data));
}

__INLINE cgraph_bool_t cgraph_math_isbintl(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data));
}

__INLINE cgraph_bool_t cgraph_math_isdechd(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data) || ('0' == data));
}

__INLINE cgraph_bool_t cgraph_math_isdecst(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' != data) && isdigit(data));
}

__INLINE cgraph_bool_t cgraph_math_isdecmd(const cgraph_char_t data) {
  return CGRAPH_TEST(isdigit(data));
}

__INLINE cgraph_bool_t cgraph_math_isdeced(const cgraph_char_t data) {
  return CGRAPH_TEST(isdigit(data));
}

__INLINE cgraph_bool_t cgraph_math_isdectl(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data));
}

__INLINE cgraph_bool_t cgraph_math_ishexhd(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data) || ('0' == data));
}

__INLINE cgraph_bool_t cgraph_math_ishexst(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' != data) && isxdigit(data));
}

__INLINE cgraph_bool_t cgraph_math_ishexmd(const cgraph_char_t data) {
  return CGRAPH_TEST(isxdigit(data));
}

__INLINE cgraph_bool_t cgraph_math_ishexed(const cgraph_char_t data) {
  return CGRAPH_TEST(isxdigit(data));
}

__INLINE cgraph_bool_t cgraph_math_ishextl(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data));
}

__INLINE cgraph_bool_t cgraph_math_isnumhd(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data) || ('0' == data));
}

__INLINE cgraph_bool_t cgraph_math_isnumst(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' != data) && isdigit(data));
}

__INLINE cgraph_bool_t cgraph_math_isnummd(const cgraph_char_t data) {
  return CGRAPH_TEST(isdigit(data) || ('.' == data));
}

__INLINE cgraph_bool_t cgraph_math_isnumed(const cgraph_char_t data) {
  return CGRAPH_TEST(('0' != data) && isdigit(data));
}

__INLINE cgraph_bool_t cgraph_math_isnumtl(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data) || ('0' == data));
}

__INLINE cgraph_bool_t cgraph_math_isnamhd(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data));
}

__INLINE cgraph_bool_t cgraph_math_isnamst(const cgraph_char_t data) {
  return CGRAPH_TEST(isalpha(data) || ('_' == data));
}

__INLINE cgraph_bool_t cgraph_math_isnammd(const cgraph_char_t data) {
  return CGRAPH_TEST(isalnum(data) || ('_' == data));
}

__INLINE cgraph_bool_t cgraph_math_isnamed(const cgraph_char_t data) {
  return CGRAPH_TEST(isalnum(data) || ('_' == data));
}

__INLINE cgraph_bool_t cgraph_math_isnamtl(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data));
}

__INLINE cgraph_int_t cgraph_math_bin2dec(const cgraph_char_t data) {
  return ('0' == data) ? 0 : 1;
}

__INLINE cgraph_char_t cgraph_math_dec2bin(const cgraph_int_t data) {
  return (0 == data) ? '0' : '1';
}

__INLINE cgraph_int_t cgraph_math_dec2dec(const cgraph_char_t data) {
  return (('0' <= data) && ('9' >= data)) ? (data - '0') : MATH_ERROR;
}

__INLINE cgraph_int_t cgraph_math_hex2dec(const cgraph_char_t data) {
  cgraph_int_t res = MATH_ERROR;
  switch (data) {
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9': {
    res = data - '0';
    break;
  }
  case 'A':
  case 'B':
  case 'C':
  case 'D':
  case 'E':
  case 'F': {
    res = data - 'A' + 10;
    break;
  }
  case 'a':
  case 'b':
  case 'c':
  case 'd':
  case 'e':
  case 'f': {
    res = data - 'a' + 10;
    break;
  }
  default: {
    break;
  }
  }

  return res;
}

static const cgraph_char_t __cgraph_math_dec2hex_upper__[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

__INLINE cgraph_char_t cgraph_math_dec2uhex(const cgraph_int_t data) {
  return (data >= 0 && data < 16) ? __cgraph_math_dec2hex_upper__[data] : '\0';
}

static const cgraph_char_t __cgraph_math_dec2hex_lower__[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

__INLINE cgraph_char_t cgraph_math_dec2lhex(const cgraph_int_t data) {
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

cgraph_int_t cgraph_math_chgbas(cgraph_int_t *old, const cgraph_size_t old_len,
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

cgraph_uint64_t cgraph_math_crc(const cgraph_uint64_t predata,
                                const cgraph_uint64_t data,
                                const cgraph_uint64_t poly) {
  cgraph_uint64_t res = predata, temp = (data & res), ones = CGRAPH_UINT64_MAX,
                  msb = 0;
  cgraph_size_t i = 0, bits = CGRAPH_UINT64_BITS;
  for (i = 0; i < bits; i++) {
    msb = ((res ^ temp) >> (bits - 1) & 1);
    if (msb == 1) {
      res = (((res << 1) ^ ones) & poly);
    } else {
      res = (res << 1);
    }
    temp = (temp << 1);
  }

  return res;
}

cgraph_bool_t cgraph_math_prime(const cgraph_int_t data) {
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
  if ((NULL != primes) && (NULL != isprime) && (data > 1)) {
    cgraph_size_t i, j;
    for (i = 0; i < data; i++) {
      primes[i] = 0;
      isprime[i] = CGRAPH_TRUE;
    }
    for (i = 2; i < data; i++) {
      if (isprime[i] == CGRAPH_TRUE) {
        primes[counter++] = i;
      }
      for (j = 0; j < counter && i * primes[j] < data; j++) {
        isprime[i * primes[j]] = CGRAPH_FALSE;
        if (i % primes[j] == 0) {
          break;
        }
      }
    }
  }

  return counter;
}

/** 32-bit integer random functions  */
static cgraph_rand32_intptr_t __cgraph_rand32_intptr = cgraph_rand32_miller;

void cgraph_rand32_intptr(cgraph_rand32_intptr_t ptr) {
  __cgraph_rand32_intptr = ptr;
}

static cgraph_int32_t __cgraph_rand32_seed = 1;

void cgraph_rand32_seed(const cgraph_int32_t seed) {
  __cgraph_rand32_seed = seed;
}

cgraph_int32_t cgraph_rand32(void) { return __cgraph_rand32_intptr(); }

/**
  Author  : Park,  Miller
  Methode : X(n+1) <- (a * X(n) + b) % m
  a = 16807 or 48271
  b = 0
  m = 2147483647 (MATH_CONST_RAND32_MAX, 2^31 - 1 or 2 << 31 - 1)
  returning a 32-bit integer [1, 2147483647]
  X(0) = 1
*/
cgraph_int32_t cgraph_rand32_miller(void) {
  const cgraph_int32_t a = 48271, m = MATH_CONST_RAND32_MAX;
  const cgraph_int32_t m_div_a = m / a, m_mod_a = m % a;
  cgraph_int32_t hi = __cgraph_rand32_seed / m_div_a,
                 lo = __cgraph_rand32_seed % m_div_a;
  __cgraph_rand32_seed = (a * lo - m_mod_a * hi);

  return __cgraph_rand32_seed;
}

/**
 * 32-bit Mersenne Twister Algorithm
 *  @brief mt19937-32
 */
cgraph_int32_t cgraph_rand32_mt19937(void) { return __cgraph_rand32_seed; }

cgraph_int32_t cgraph_rand32_uniform(const cgraph_int32_t min,
                                     const cgraph_int32_t max) {
  return __cgraph_rand32_intptr() % (max - min) + min;
}

/*
        Authors : Box and Muller
        mu      : the average value of the normal distribution
        sigma   : the variance of the normal distribution
*/
cgraph_float32_t cgraph_rand32_normal(const cgraph_float32_t mu,
                                      const cgraph_float32_t sigma) {
  static cgraph_float32_t U, V, Z;
  static cgraph_bool_t phase = CGRAPH_FALSE;
  if (CGRAPH_TRUE == phase) {
    U = (1.0 * __cgraph_rand32_intptr() + 1.0) / (MATH_CONST_RAND32_MAX + 2.0);
    V = 1.0 * __cgraph_rand32_intptr() / (MATH_CONST_RAND32_MAX + 1.0);
    Z = sqrt(-2.0 * log(U)) * sin(2.0 * MATH_CONST_PI * V);
  } else {
    Z = sqrt(-2.0 * log(U)) * cos(2.0 * MATH_CONST_PI * V);
  }
  phase ^= CGRAPH_TRUE;

  return Z * sigma + mu;
}

/** 64-bit integer random functions  */
static cgraph_rand64_intptr_t __cgraph_rand64_intptr = cgraph_rand64_mmix;

void cgraph_rand64_intptr(cgraph_rand64_intptr_t ptr) {
  __cgraph_rand64_intptr = ptr;
}

static cgraph_int64_t __cgraph_rand64_seed = 0;

void cgraph_rand64_seed(const cgraph_int64_t seed) {
  __cgraph_rand64_seed = seed;
}

cgraph_int64_t cgraph_rand64(void) { return __cgraph_rand64_intptr(); }

/**
  Author  : MMIX by Donald Knuth
  Methode : X(n+1) <- (a * X(n) + b) % m
  a = 6364136223846793005LL
  b = 1442695040888963407LL
  m = 18446744073709551615LL
  returning a 64-bit integer [1, 18446744073709551615]
  X(0) = 1
*/
cgraph_int64_t cgraph_rand64_mmix(void) {
  const cgraph_int64_t a = __RAND64_A, b = __RAND64_B, m = __RAND64_M;
  const cgraph_int64_t a_mod_m = a % m, b_mod_m = b % m;
  cgraph_int64_t seed_mod_m = __cgraph_rand64_seed % m;
  __cgraph_rand64_seed = ((a_mod_m * seed_mod_m) % m + b_mod_m) % m;

  return __cgraph_rand64_seed;
}

/**
 * 64-bit Mersenne Twister Algorithm
 *  @brief mt19937-64
 */
cgraph_int64_t cgraph_rand64_mt19937(void) { return __cgraph_rand64_seed; }

cgraph_int64_t cgraph_rand64_uniform(const cgraph_int64_t min,
                                     const cgraph_int64_t max) {
  return __cgraph_rand64_intptr() % (max - min) + min;
}

/*
        Authors : Box and Muller
        mu      : the average value of the normal distribution
        sigma   : the variance of the normal distribution
*/
cgraph_float64_t cgraph_rand64_normal(const cgraph_float64_t mu,
                                      const cgraph_float64_t sigma) {
  static cgraph_float64_t U, V, Z;
  static cgraph_bool_t phase = CGRAPH_FALSE;
  if (CGRAPH_TRUE == phase) {
    U = (1.0 * __cgraph_rand64_intptr() + 1.0) / (MATH_CONST_RAND64_MAX + 2.0);
    V = 1.0 * __cgraph_rand64_intptr() / (MATH_CONST_RAND64_MAX + 1.0);
    Z = sqrt(-2.0 * log(U)) * sin(2.0 * MATH_CONST_PI * V);
  } else {
    Z = sqrt(-2.0 * log(U)) * cos(2.0 * MATH_CONST_PI * V);
  }
  phase ^= CGRAPH_TRUE;

  return Z * sigma + mu;
}

cgraph_bool_t cgraph_rand_bool(void) {
  return __cgraph_rand32_intptr() & CGRAPH_BOOL_EPS;
}

cgraph_logic_t cgraph_rand_logic(void) {
  return __cgraph_rand32_intptr() & CGRAPH_LOGIC_EPS;
}

/** random size */
cgraph_size_t cgraph_rand_size(const cgraph_size_t size) {
#if __WORDSIZE == 64
  return __cgraph_rand64_intptr() % size;
#else
  return __cgraph_rand32_intptr() % size;
#endif
}

cgraph_float64_t cgraph_math_logn(const cgraph_float64_t n,
                                  const cgraph_float64_t x) {
  return log(x) / log(n);
}

__INLINE cgraph_int_t cgraph_math_pow2(const cgraph_int_t n) {
  return (n >= 0) ? (1 << n) : 0;
}

cgraph_int_t cgraph_math_log2(const cgraph_int_t x) {
  cgraph_int_t res = 0, num = x;
  while (num > 1) {
    num = num >> 1;
    res++;
  }

  return res;
}

__INLINE cgraph_int_t cgraph_math_mod2(const cgraph_int_t x) {
  return (x > 0) ? (x & 0x01) : 0;
}

__INLINE cgraph_int_t cgraph_math_mod2n(const cgraph_int_t x,
                                        const cgraph_int_t n) {
  return (x & (~(CGRAPH_INT_MIN << n)));
}

__INLINE cgraph_int_t cgraph_math_bin2gray(const cgraph_int_t data) {
  return (data ^ (data >> 1));
}

__INLINE cgraph_int_t cgraph_math_gray2bin(const cgraph_int_t data) {
  return (data ^ (data << 1));
}

__INLINE cgraph_int_t cgraph_math_ceil(const cgraph_int_t x,
                                       const cgraph_int_t y) {
  return (x + y - 1) / y;
}

__INLINE cgraph_int_t cgraph_math_floor(const cgraph_int_t x,
                                        const cgraph_int_t y) {
  return x / y;
}

cgraph_int_t cgraph_math_pow(const cgraph_int_t x, const cgraph_int_t n) {
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

cgraph_int_t cgraph_math_pow_mod(const cgraph_int_t x, const cgraph_int_t n,
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

cgraph_int_t cgraph_math_mul(const cgraph_int_t x, const cgraph_int_t y) {
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

cgraph_int_t cgraph_math_mul_mod(const cgraph_int_t x, const cgraph_int_t y,
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
