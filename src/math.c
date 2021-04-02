#include <ctype.h>

#include "cgraph_math.h"

CGRAPH_INLINE cgraph_bool_t cgraph_math_isalnum(const cgraph_char_t data) {
  return CGRAPH_TEST(isalnum(data));
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_isalpha(const cgraph_char_t data) {
  return CGRAPH_TEST(isalpha(data));
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_isblank(const cgraph_char_t data) {
#if CGRAPH_STDC_VERSION >= 199901L
  return CGRAPH_TEST(isblank(data));
#else
  return CGRAPH_TEST((' ' == data) || ('\t' == data));
#endif
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_isnumst(const cgraph_char_t data) {
  return CGRAPH_TEST((' ' == data) || ('\t' == data) || ('0' == data));
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_islower(const cgraph_char_t data) {
  return CGRAPH_TEST(islower(data));
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_isprint(const cgraph_char_t data) {
  return CGRAPH_TEST(isprint(data));
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_isspace(const cgraph_char_t data) {
  return CGRAPH_TEST(isspace(data));
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_isupper(const cgraph_char_t data) {
  return CGRAPH_TEST(isupper(data));
}

CGRAPH_INLINE cgraph_char_t cgraph_math_toupper(const cgraph_char_t data) {
  return toupper(data);
}

CGRAPH_INLINE cgraph_char_t cgraph_math_tolower(const cgraph_char_t data) {
  return tolower(data);
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_ispsplit(const cgraph_char_t data) {
  return CGRAPH_TEST(CGRAPH_PLAT_PSPLIT_C == data);
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_isnline(const cgraph_char_t data) {
  return CGRAPH_TEST(CGRAPH_PLAT_NLINE_C == data);
}

cgraph_size_t cgraph_math_lenofname(const cgraph_char_t *data,
                                    cgraph_bool_t *flag) {
  cgraph_size_t len = 0;
  if (NULL != data) {
    cgraph_char_t *name = (cgraph_char_t *)data;
    cgraph_bool_t bracket_flag = CGRAPH_FALSE;
    if (NULL != flag) {
      *flag = CGRAPH_TRUE;
    }
    if (!isalpha(*name)) {
      if (NULL != flag) {
        *flag = CGRAPH_FALSE;
      }
      if (!isdigit(*name)) {
        return len;
      }
    }
    for (name++, len++; '\0' != *name; name++, len++) {
      if (!isalnum(*name) && ('_' != *name) && ('.' != *name) &&
          (CGRAPH_FALSE == bracket_flag)) {
        if ('[' == *name) {
          bracket_flag = CGRAPH_TRUE;
        } else if (('-' == *name) && ('>' == *(name + 1))) {
          name++;
          len++;
        } else {
          break;
        }
      } else if (']' == *name) {
        bracket_flag = CGRAPH_FALSE;
      }
    }
  }

  return len;
}

cgraph_bool_t cgraph_math_isname(const cgraph_char_t *data) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  cgraph_math_lenofname(data, &flag);

  return flag;
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_isdec(const cgraph_char_t data) {
  return CGRAPH_TEST(isdigit(data));
}

CGRAPH_INLINE cgraph_bool_t cgraph_math_ishex(const cgraph_char_t data) {
  return CGRAPH_TEST(isxdigit(data));
}

cgraph_int_t cgraph_math_hex2dec(cgraph_char_t data, cgraph_bool_t *error) {
  cgraph_int_t res = 0;
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
    if (NULL != error) {
      *error = CGRAPH_TRUE;
    }
    break;
  }
  }

  return res;
}

static const cgraph_char_t __cgraph_math_dec2hex_upper__[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

cgraph_char_t cgraph_math_dec2uhex(const cgraph_int_t data,
                                   cgraph_bool_t *error) {
  cgraph_char_t ch = 0;
  if (data >= 0 && data < 16) {
    ch = __cgraph_math_dec2hex_upper__[data];
    if (NULL != error) {
      *error = CGRAPH_FALSE;
    }
  }

  return ch;
}

static const cgraph_char_t __cgraph_math_dec2hex_lower__[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

cgraph_char_t cgraph_math_dec2lhex(const cgraph_int_t data,
                                   cgraph_bool_t *error) {
  cgraph_char_t ch = 0;
  if (data >= 0 && data < 16) {
    ch = __cgraph_math_dec2hex_lower__[data];
    if (NULL != error) {
      *error = CGRAPH_FALSE;
    }
  }

  return ch;
}

cgraph_size_t cgraph_math_lenofdec(const cgraph_char_t *data,
                                   cgraph_char_t **res) {
  cgraph_size_t len = 0;
  if ((NULL != data)) {
    cgraph_char_t *cthis = (cgraph_char_t *)data;
    for (; ('\t' == *cthis) || (' ' == *cthis) || ('0' == *cthis); cthis++) {
    }
    if (NULL != res) {
      *res = cthis;
    }
    if (('-' == *cthis) || ('+' == *cthis)) {
      cthis++;
    }
    for (; ('\0' != *cthis) && isdigit(*cthis); cthis++, len++) {
    }
  }

  return len;
}

cgraph_size_t cgraph_math_lenofbase(const cgraph_int_t data,
                                    const cgraph_int_t base) {
  cgraph_size_t len = 0;
  cgraph_int_t new_data = data;
  while (0 != new_data) {
    new_data = new_data / base;
    len += 1;
  }

  return len;
}

cgraph_int_t cgraph_math_chgbase(cgraph_int_t *old, const cgraph_size_t old_len,
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
static cgraph_random32_intptr_t __cgraph_random32_intptr = cgraph_random32;

void cgraph_random32_intptr(cgraph_random32_intptr_t ptr) {
  __cgraph_random32_intptr = ptr;
}

static cgraph_int32_t __cgraph_random32_seed = 1;

void cgraph_random32_seed(const cgraph_int32_t seed) {
  __cgraph_random32_seed = seed;
}

/**
  Author  : Park,  Miller
  Methode : X(n+1) <- (a * X(n) + b) % m
  a = 16807 or 48271
  b = 0
  m = 2147483647 (MATH_CONST_RANDOM32_MAX, 2^31 - 1 or 2 << 31 - 1)
  returning a 32-bit integer [1, 2147483647]
  X(0) = 1
*/
cgraph_int32_t cgraph_random32(void) {
  const cgraph_int32_t a = 48271, m = MATH_CONST_RANDOM32_MAX;
  const cgraph_int32_t m_div_a = m / a, m_mod_a = m % a;
  cgraph_int32_t hi = __cgraph_random32_seed / m_div_a,
                 lo = __cgraph_random32_seed % m_div_a;
  __cgraph_random32_seed = (a * lo - m_mod_a * hi);

  return __cgraph_random32_seed;
}

/**
 * 32-bit Mersenne Twister Algorithm
 *  @brief mt19937-32
 */
cgraph_int32_t cgraph_random_mt19937_32(void) { return __cgraph_random32_seed; }

cgraph_int32_t cgraph_random32_uniform(const cgraph_int32_t min,
                                       const cgraph_int32_t max) {
  return __cgraph_random32_intptr() % (max - min) + min;
}

/** 64-bit integer random functions  */
static cgraph_random64_intptr_t __cgraph_random64_intptr = cgraph_random64;

void cgraph_random64_intptr(cgraph_random64_intptr_t ptr) {
  __cgraph_random64_intptr = ptr;
}

static cgraph_int64_t __cgraph_random64_seed = 0;

void cgraph_random64_seed(const cgraph_int64_t seed) {
  __cgraph_random64_seed = seed;
}

/**
  Author  : MMIX by Donald Knuth
  Methode : X(n+1) <- (a * X(n) + b) % m
  a = 6364136223846793005
  b = 1442695040888963407
  m = 18446744073709551615
  returning a 64-bit integer [1, 18446744073709551615]
  X(0) = 1
*/
cgraph_int64_t cgraph_random64(void) {
  const cgraph_int64_t a = __CGRAPH_RANDOM64_A, b = __CGRAPH_RANDOM64_B,
                       m = __CGRAPH_RANDOM64_M;
  const cgraph_int64_t a_mod_m = a % m, b_mod_m = b % m;
  cgraph_int64_t seed_mod_m = __cgraph_random64_seed % m;
  __cgraph_random64_seed = ((a_mod_m * seed_mod_m) % m + b_mod_m) % m;

  return __cgraph_random64_seed;
}

/**
 * 64-bit Mersenne Twister Algorithm
 *  @brief mt19937-64
 */
cgraph_int64_t cgraph_random64_mt19937(void) { return __cgraph_random64_seed; }

cgraph_int64_t cgraph_random64_uniform(const cgraph_int64_t min,
                                       const cgraph_int64_t max) {
  return __cgraph_random64_intptr() % (max - min) + min;
}

/*
        Authors : Box and Muller
        mu      : the average value of the normal distribution
        sigma   : the variance of the normal distribution
*/
cgraph_float64_t cgraph_random64_normal(const cgraph_float64_t mu,
                                        const cgraph_float64_t sigma) {
  static cgraph_float64_t U, V, Z;
  static cgraph_bool_t phase = CGRAPH_FALSE;
  if (!phase) {
    U = (1.0 * __cgraph_random32_intptr() + 1.0) /
        (MATH_CONST_RANDOM32_MAX + 2.0);
    V = 1.0 * __cgraph_random32_intptr() / (MATH_CONST_RANDOM32_MAX + 1.0);
    Z = sqrt(-2.0 * log(U)) * sin(2.0 * MATH_CONST_PI * V);
  } else {
    Z = sqrt(-2.0 * log(U)) * cos(2.0 * MATH_CONST_PI * V);
  }
  phase = CGRAPH_TRUE - phase;

  return Z * sigma + mu;
}

cgraph_float64_t cgraph_math_logn(const cgraph_float64_t n,
                                  const cgraph_float64_t x) {
  return log(x) / log(n);
}

CGRAPH_INLINE cgraph_int_t cgraph_math_pow2(const cgraph_int_t n) {
  return (1 << n);
}

cgraph_int_t cgraph_math_log2(const cgraph_int_t x) {
  cgraph_int_t res = 0, num = x;
  while (num > 1) {
    num = num >> 1;
    res++;
  }

  return res;
}

CGRAPH_INLINE cgraph_int_t cgraph_math_mod2(const cgraph_int_t x) {
  return (x & 1);
}

CGRAPH_INLINE cgraph_int_t cgraph_math_bin2gray(const cgraph_int_t data) {
  return (data ^ (data >> 1));
}

CGRAPH_INLINE cgraph_int_t cgraph_math_gray2bin(const cgraph_int_t data) {
  return (data ^ (data << 1));
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
