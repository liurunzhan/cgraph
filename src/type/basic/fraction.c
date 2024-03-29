#include "cgraph_base.h"
#include "cgraph_int.h"

/** object cgraph_fraction_t header */
#include "cgraph_fraction.h"

/** template module */
#include "template_data.ct"

#define CGRAPH_CBUF_SIZE CGRAPH_FRACTION_CBUF_SIZE
#define CGRAPH_CBUF_PTR cgraph_cbuf_ptr
#include "template_cbuf.ct"

cgraph_char_t *FUNCTION(NAME, encode)(const TYPE cthis) {
  if (1 == FRACTION_DEN(cthis)) {
    cgraph_file_snprintf(CGRAPH_CBUF_PTR, CGRAPH_CBUF_SIZE, OUT_FMT_NUM,
                         FRACTION_NUM(cthis));
  } else {
    cgraph_file_snprintf(CGRAPH_CBUF_PTR, CGRAPH_CBUF_SIZE, OUT_FMT,
                         FRACTION_NUM(cthis), FRACTION_DEN(cthis));
  }

  return CGRAPH_CBUF_PTR;
}

TYPE FUNCTION(NAME, decode)(const cgraph_char_t *cstr, const cgraph_size_t len,
                            cgraph_bool_t *error) {
  TYPE res = FUNCTION(NAME, zero)();
  cgraph_bool_t _error = CGRAPH_FALSE;
  if (CGRAPH_ISSTR(cstr)) {
    cgraph_int_t hit =
        sscanf(cstr, IN_FMT, &(FRACTION_NUM(res)), &(FRACTION_DEN(res)));
    if ((0 == hit) || (EOF == hit)) {
      _error = CGRAPH_TRUE;
    }
  }
  if (NULL != error) {
    *error = _error;
  }

  return res;
}

cgraph_size_t FUNCTION(NAME, fprint)(FILE *fp, const TYPE cthis) {
  cgraph_size_t len = 0;
  if (1 == FRACTION_DEN(cthis)) {
    len = cgraph_file_fprintf(fp, OUT_FMT_NUM, FRACTION_NUM(cthis));
  } else {
    len = cgraph_file_fprintf(fp, OUT_FMT, FRACTION_NUM(cthis),
                              FRACTION_DEN(cthis));
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, snprint)(cgraph_char_t *cbuf,
                                      const cgraph_size_t size,
                                      const TYPE cthis) {
  cgraph_size_t len = 0;
  if (1 == FRACTION_DEN(cthis)) {
    len = cgraph_file_snprintf(cbuf, size, OUT_FMT_NUM, FRACTION_NUM(cthis));
  } else {
    len = cgraph_file_snprintf(cbuf, size, OUT_FMT, FRACTION_NUM(cthis),
                               FRACTION_DEN(cthis));
  }

  return len;
}

/** @brief public apis */
/*
  fnv-1a hash function (Fowler-Noll-Vo hash function, proposed by Glenn
  Fowler，Landon Curt Noll and Phong Vo in 1991): begin_of_algorithm hash =
  offset_basis for byte_of_data in data begin hash = hash ^ byte_of_data
  hash = hash * fnv_prime end return hash end_of_algorithm 32-bit
  offset_basis : 2166136261 32-bit fnv_prime : 16777619 = 2^24 + 2^8 + 0x93
  64-bit offset_basis : 14695981039346656037 64-bit fnv_prime :
  1099511628211 = 2^40 + 2^8 + 0xb3
*/
cgraph_size_t FUNCTION(NAME, hash)(const TYPE cthis) {
  cgraph_size_t hash = USIZE_C(2166136261);
  hash = (hash ^ FRACTION_NUM(cthis)) * USIZE_C(16777619);
  hash = ((hash >> 8) ^ FRACTION_DEN(cthis)) * USIZE_C(16777619);

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE cthis) {
  return CGRAPH_TEST(DATA_ZERO != FRACTION_DEN(cthis));
}

TYPE FUNCTION(NAME, fmt)(const TYPE cthis) {
  TYPE res = cthis;
  DATA_TYPE gcd = FRACTION_GCD(cthis);
  if ((1 < gcd)) {
    FRACTION_NUM(res) /= gcd;
    FRACTION_DEN(res) /= gcd;
  }
  if (0 > FRACTION_DEN(res)) {
    FRACTION_NUM(res) = -FRACTION_NUM(res);
    FRACTION_DEN(res) = -FRACTION_DEN(res);
  }

  return res;
}

/**                              private apis                                 */
__INLINE__ TYPE FUNCTION(NAME, zero)(void) {
  TYPE res;
  FRACTION_NUM(res) = DATA_ZERO;
  FRACTION_DEN(res) = DATA_ONE;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, one)(void) {
  TYPE res;
  FRACTION_NUM(res) = DATA_ONE;
  FRACTION_DEN(res) = DATA_ONE;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, ones)(void) {
  TYPE res;
  FRACTION_NUM(res) = DATA_ONES;
  FRACTION_DEN(res) = DATA_ONE;

  return res;
}

TYPE FUNCTION(NAME, rand)(void) {
  TYPE res;
  FRACTION_NUM(res) = FUNCTION(DATA_NAME, rand)();
  FRACTION_DEN(res) = FUNCTION(DATA_NAME, rand)();

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, min)(void) {
  TYPE res;
  FRACTION_NUM(res) = DATA_ONE;
  FRACTION_DEN(res) = DATA_MIN;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, max)(void) {
  TYPE res;
  FRACTION_NUM(res) = DATA_MAX;
  FRACTION_DEN(res) = DATA_ONE;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, nan)(void) {
  TYPE res;
  FRACTION_NUM(res) = DATA_ZERO;
  FRACTION_DEN(res) = DATA_ZERO;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, inf)(void) {
  TYPE res;
  FRACTION_NUM(res) = DATA_ONE;
  FRACTION_DEN(res) = DATA_ZERO;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, pinf)(void) {
  TYPE res;
  FRACTION_NUM(res) = DATA_ONE;
  FRACTION_DEN(res) = DATA_ZERO;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, ninf)(void) {
  TYPE res;
  FRACTION_NUM(res) = -DATA_ONE;
  FRACTION_DEN(res) = DATA_ZERO;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, mask)(void) {
  TYPE res;
  FRACTION_NUM(res) = DATA_MASK;
  FRACTION_DEN(res) = DATA_MASK;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, epsilon)(void) {
  TYPE res;
  FRACTION_NUM(res) = 1;
  FRACTION_DEN(res) = DATA_MAX;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, acc)(void) {
  TYPE res;
  FRACTION_NUM(res) = DATA_ONE;
  FRACTION_DEN(res) = DATA_MIN;

  return res;
}

TYPE FUNCTION(NAME, initf32)(const cgraph_float32_t data) {
  TYPE res = FUNCTION(NAME, zero)();
  DATA_TYPE int_part = floor(data), gcd;
  cgraph_float32_t float_part = data - int_part;
  cgraph_size_t i;
  for (i = 0; i < CGRAPH_FLOAT32_DIG; i++) {
    float_part *= 10;
    gcd = floor(float_part);
    float_part -= gcd;
    FRACTION_NUM(res) = FRACTION_NUM(res) * 10 + gcd;
    FRACTION_DEN(res) *= 10;
  }
  gcd = cgraph_int_gcd(FRACTION_NUM(res), FRACTION_DEN(res));
  FRACTION_NUM(res) /= gcd;
  FRACTION_DEN(res) /= gcd;
  FRACTION_NUM(res) += int_part * FRACTION_DEN(res);

  return res;
}

TYPE FUNCTION(NAME, initf64)(const cgraph_float64_t data) {
  TYPE res = FUNCTION(NAME, zero)();
  DATA_TYPE int_part = floor(data), gcd;
  cgraph_float64_t float_part = data - int_part;
  cgraph_size_t i;
  for (i = 0; i < CGRAPH_FLOAT64_DIG; i++) {
    float_part *= 10;
    gcd = floor(float_part);
    float_part -= gcd;
    FRACTION_NUM(res) = FRACTION_NUM(res) * 10 + gcd;
    FRACTION_DEN(res) *= 10;
  }
  gcd = cgraph_int_gcd(FRACTION_NUM(res), FRACTION_DEN(res));
  FRACTION_NUM(res) /= gcd;
  FRACTION_DEN(res) /= gcd;
  FRACTION_NUM(res) += int_part * FRACTION_DEN(res);

  return res;
}

TYPE FUNCTION(NAME, initnd)(const DATA_TYPE num, const DATA_TYPE den) {
  TYPE res;
  FRACTION_NUM(res) = num;
  FRACTION_DEN(res) = den;

  return res;
}

TYPE FUNCTION(NAME, initn)(const DATA_TYPE num) {
  TYPE res;
  FRACTION_NUM(res) = num;
  FRACTION_DEN(res) = 1;

  return res;
}

TYPE FUNCTION(NAME, initd)(const DATA_TYPE den) {
  TYPE res;
  FRACTION_NUM(res) = 1;
  FRACTION_DEN(res) = den;

  return res;
}

__INLINE__ cgraph_int_t FUNCTION(NAME, signbit)(const TYPE x) {
  const cgraph_int_t num_flag = CGRAPH_BFLAG(FRACTION_NUM(x), DATA_BITS),
                     den_flag = CGRAPH_BFLAG(FRACTION_DEN(x), DATA_BITS);
  cgraph_int_t flag = -1;
  if ((0 == num_flag) || (0 == den_flag)) {
    flag = 0;
  } else if (num_flag == den_flag) {
    flag = 1;
  }

  return flag;
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, isint)(const TYPE x) {
  return CGRAPH_TEST(1 == FRACTION_DEN(x));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, iszero)(const TYPE x) {
  return CGRAPH_TEST((!FRACTION_NUM(x)) && FRACTION_DEN(x));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, isodd)(const TYPE x) {
  return CGRAPH_TEST((1 == FRACTION_DEN(x)) && (FRACTION_NUM(x) & DATA_LSB));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, iseven)(const TYPE x) {
  return CGRAPH_TEST((1 == FRACTION_DEN(x)) && ((~FRACTION_NUM(x)) & DATA_LSB));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, ispow2)(const TYPE x) {
  return CGRAPH_TEST(
      ((0 < FRACTION_NUM(x)) && (!(FRACTION_NUM(x) & (FRACTION_NUM(x) - 1)))) &&
      ((0 < FRACTION_DEN(x)) && (!(FRACTION_DEN(x) & (FRACTION_DEN(x) - 1)))));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, ispos)(const TYPE x) {
  return CGRAPH_TEST(1 == FUNCTION(NAME, signbit)(x));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, isneg)(const TYPE x) {
  return CGRAPH_TEST(-1 == FUNCTION(NAME, signbit)(x));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, ismax)(const TYPE x) {
  return EQ(x, MAX);
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, ismin)(const TYPE x) {
  return EQ(x, MIN);
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, isnan)(const TYPE x) {
  return CGRAPH_TEST(DATA_ISNAN(x));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, isinf)(const TYPE x) {
  return CGRAPH_TEST(DATA_ISINF(x));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, ispinf)(const TYPE x) {
  return CGRAPH_TEST(DATA_ISPINF(x));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, isninf)(const TYPE x) {
  return CGRAPH_TEST(DATA_ISNINF(x));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, eq)(const TYPE x, const TYPE y) {
  return EQ(x, y);
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, gt)(const TYPE x, const TYPE y) {
  return GT(x, y);
}

__INLINE__ TYPE FUNCTION(NAME, opp)(const TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = -FRACTION_NUM(x);
  FRACTION_DEN(res) = FRACTION_DEN(x);

  return res;
}

TYPE FUNCTION(NAME, modf)(const TYPE x, TYPE *y) {
  TYPE res = x;
  if (NULL != y) {
    *y = x;
  }
  if (DATA_TEST(x)) {
    const DATA_TYPE frac_div = FRACTION_NUM(x) / FRACTION_DEN(x),
                    frac_mod = FRACTION_NUM(x) % FRACTION_DEN(x);
    FRACTION_NUM(res) = frac_mod;
    FRACTION_DEN(res) = FRACTION_DEN(x);
    if (NULL != y) {
      FRACTION_NUM(*y) = frac_div;
      FRACTION_DEN(*y) = DATA_ONE;
    }
  }

  return res;
}

TYPE FUNCTION(NAME, frexp)(const TYPE x, DATA_TYPE *y) {
  TYPE exp, res = FUNCTION(NAME, modf)(x, &exp);
  if (NULL != y) {
    *y = FRACTION_NUM(exp);
  }

  return res;
}

TYPE FUNCTION(NAME, ldexp)(const TYPE x, const DATA_TYPE y) {
  TYPE res;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, trans)(const TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x);
  FRACTION_DEN(res) = FRACTION_DEN(x);

  return res;
}

DATA_TYPE FUNCTION(NAME, fabs)(const TYPE x) { return fabs(FRACTION_VALUE(x)); }

__INLINE__ TYPE FUNCTION(NAME, abs)(const TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = CGRAPH_ABS(FRACTION_NUM(x));
  FRACTION_DEN(res) = CGRAPH_ABS(FRACTION_DEN(x));

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, inv)(const TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_DEN(x);
  FRACTION_DEN(res) = FRACTION_NUM(x);

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, rev)(const TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_DEN(x);
  FRACTION_DEN(res) = FRACTION_NUM(x);

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, pow2)(const TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_NUM(x);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(x);

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, pow3)(const TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_NUM(x) * FRACTION_NUM(x);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(x) * FRACTION_DEN(x);

  return res;
}

DATA_TYPE FUNCTION(NAME, dmin)(const TYPE x) {
  return DATA_LT(FRACTION_NUM(x), FRACTION_DEN(x)) ? FRACTION_NUM(x)
                                                   : FRACTION_DEN(x);
}

DATA_TYPE FUNCTION(NAME, dmax)(const TYPE x) {
  return DATA_GT(FRACTION_NUM(x), FRACTION_DEN(x)) ? FRACTION_NUM(x)
                                                   : FRACTION_DEN(x);
}

DATA_TYPE FUNCTION(NAME, dsum)(const TYPE x) {
  return FRACTION_NUM(x) + FRACTION_DEN(x);
}

DATA_TYPE FUNCTION(NAME, dgcd)(const TYPE x) { return FRACTION_GCD(x); }

DATA_TYPE FUNCTION(NAME, dlcm)(const TYPE x) { return FRACTION_LCM(x); }

TYPE FUNCTION(NAME, add)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) =
      (FRACTION_NUM(x) * FRACTION_DEN(y)) + (FRACTION_DEN(x) * FRACTION_NUM(y));
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y);

  return FUNCTION(NAME, fmt)(res);
}

TYPE FUNCTION(NAME, sub)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) =
      (FRACTION_NUM(x) * FRACTION_DEN(y)) - (FRACTION_DEN(x) * FRACTION_NUM(y));
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y);

  return FUNCTION(NAME, fmt)(res);
}

TYPE FUNCTION(NAME, abssub)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, abs)(FUNCTION(NAME, sub)(x, y));
}

TYPE FUNCTION(NAME, mul)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_NUM(y);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y);

  return FUNCTION(NAME, fmt)(res);
}

TYPE FUNCTION(NAME, div)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_DEN(y);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_NUM(y);

  return FUNCTION(NAME, fmt)(res);
}

TYPE FUNCTION(NAME, idiv)(const TYPE x, const TYPE y) {
  TYPE res;
  FUNCTION(NAME, modf)(FUNCTION(NAME, div)(x, y), &res);

  return res;
}

TYPE FUNCTION(NAME, ndadd)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) + FRACTION_NUM(y);
  FRACTION_DEN(res) = FRACTION_DEN(x);

  return res;
}

TYPE FUNCTION(NAME, ndsub)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) - FRACTION_NUM(y);
  FRACTION_DEN(res) = FRACTION_DEN(x);

  return res;
}

TYPE FUNCTION(NAME, ndmul)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_NUM(y);
  FRACTION_DEN(res) = FRACTION_DEN(x);

  return res;
}

TYPE FUNCTION(NAME, nddiv)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) / FRACTION_NUM(y);
  FRACTION_DEN(res) = FRACTION_DEN(x);

  return res;
}

TYPE FUNCTION(NAME, ndmod)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) =
      FUNCTION(DATA_NAME, mod)(FRACTION_NUM(x), FRACTION_NUM(y));
  FRACTION_DEN(res) = FRACTION_DEN(x);

  return res;
}

TYPE FUNCTION(NAME, ndpow)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) =
      FUNCTION(DATA_NAME, pow)(FRACTION_NUM(x), FRACTION_NUM(y));
  FRACTION_DEN(res) = FRACTION_DEN(x);

  return res;
}

TYPE FUNCTION(NAME, ddadd)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x);
  FRACTION_DEN(res) = FRACTION_DEN(x) + FRACTION_DEN(y);

  return res;
}

TYPE FUNCTION(NAME, ddsub)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x);
  FRACTION_DEN(res) = FRACTION_DEN(x) - FRACTION_DEN(y);

  return res;
}

TYPE FUNCTION(NAME, ddmul)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y);

  return res;
}

TYPE FUNCTION(NAME, dddiv)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x);
  FRACTION_DEN(res) = FRACTION_DEN(x) / FRACTION_DEN(y);

  return res;
}

TYPE FUNCTION(NAME, ddmod)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x);
  FRACTION_DEN(res) =
      FUNCTION(DATA_NAME, mod)(FRACTION_DEN(x), FRACTION_DEN(y));

  return res;
}

TYPE FUNCTION(NAME, ddpow)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x);
  FRACTION_DEN(res) =
      FUNCTION(DATA_NAME, pow)(FRACTION_DEN(x), FRACTION_DEN(y));

  return res;
}

TYPE FUNCTION(NAME, dmul)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_NUM(y);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y);

  return res;
}

TYPE FUNCTION(NAME, ddiv)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) / FRACTION_NUM(y);
  FRACTION_DEN(res) = FRACTION_DEN(x) / FRACTION_DEN(y);

  return res;
}

TYPE FUNCTION(NAME, dpow)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) =
      FUNCTION(DATA_NAME, pow)(FRACTION_NUM(x), FRACTION_NUM(y));
  FRACTION_DEN(res) =
      FUNCTION(DATA_NAME, pow)(FRACTION_DEN(x), FRACTION_DEN(y));

  return res;
}

TYPE FUNCTION(NAME, pow)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = (FRACTION_NUM(x) == 0 || FRACTION_NUM(x) == 1)
                          ? FRACTION_NUM(x)
                          : (DATA_TYPE)pow(FRACTION_DEN(x), FRACTION_VALUE(y));
  FRACTION_DEN(res) = (FRACTION_DEN(x) == 0 || FRACTION_DEN(x) == 1)
                          ? FRACTION_DEN(x)
                          : (DATA_TYPE)pow(FRACTION_DEN(x), FRACTION_VALUE(y));

  return FUNCTION(NAME, fmt)(res);
}

TYPE FUNCTION(NAME, mod)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, modf)(FUNCTION(NAME, div)(x, y), NULL);
}

TYPE FUNCTION(NAME, mean)(const TYPE x, const TYPE y) {
  TYPE res = FUNCTION(NAME, add)(x, y);
  if (FUNCTION(DATA_NAME, isodd)(FRACTION_NUM(res))) {
    FRACTION_DEN(res) = 2 * FRACTION_DEN(res);
  } else {
    FRACTION_DEN(res) = FRACTION_DEN(res) / 2;
  }

  return res;
}

/** hmean(x, y) = 1/(1/x+1/y) = (xy)/(x+y) */
TYPE FUNCTION(NAME, hmean)(const TYPE x, const TYPE y) {
  TYPE mul = FUNCTION(NAME, mul)(x, y), sum = FUNCTION(NAME, add)(x, y);

  return FUNCTION(NAME, fmt)(FUNCTION(NAME, div)(mul, sum));
}

TYPE FUNCTION(NAME, ceil)(const TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = (FRACTION_NUM(x) / FRACTION_DEN(x)) * FRACTION_DEN(x);
  if (FRACTION_NUM(res) != FRACTION_NUM(x)) {
    FRACTION_NUM(res) += FRACTION_DEN(x);
  }
  FRACTION_DEN(res) = FRACTION_DEN(x);

  return res;
}

TYPE FUNCTION(NAME, floor)(const TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = (FRACTION_NUM(x) / FRACTION_DEN(x)) * FRACTION_DEN(x);
  FRACTION_DEN(res) = FRACTION_DEN(x);

  return res;
}

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

TYPE FUNCTION(NAME, sqrt)(const TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = FUNCTION(DATA_NAME, usqrt_s)(FRACTION_NUM(x));
  FRACTION_DEN(res) = FUNCTION(DATA_NAME, usqrt_s)(FRACTION_DEN(x));

  return res;
}

TYPE FUNCTION(NAME, sqrt_inv)(const TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = FUNCTION(DATA_NAME, usqrt_s)(FRACTION_DEN(x));
  FRACTION_DEN(res) = FUNCTION(DATA_NAME, usqrt_s)(FRACTION_NUM(x));

  return res;
}

TYPE FUNCTION(NAME, unit)(const DATA_TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = x;
  FRACTION_DEN(res) = DATA_ONE;

  return res;
}

TYPE FUNCTION(NAME, unit_inv)(const DATA_TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = DATA_ONE;
  FRACTION_DEN(res) = x;

  return res;
}

TYPE FUNCTION(NAME, addn)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) + FRACTION_DEN(x) * y;
  FRACTION_DEN(res) = FRACTION_DEN(x);

  return res;
}

TYPE FUNCTION(NAME, subn)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) - FRACTION_DEN(x) * y;
  FRACTION_DEN(res) = FRACTION_DEN(x);

  return res;
}

TYPE FUNCTION(NAME, muln)(const TYPE x, const DATA_TYPE y) {
  const DATA_TYPE gcd = FUNCTION(DATA_NAME, gcd)(FRACTION_DEN(x), y);
  TYPE res;
  if (1 < gcd) {
    FRACTION_NUM(res) = FRACTION_NUM(x) * (y / gcd);
    FRACTION_DEN(res) = FRACTION_DEN(x) / gcd;
  } else {
    FRACTION_NUM(res) = FRACTION_NUM(x) * y;
    FRACTION_DEN(res) = FRACTION_DEN(x);
  }

  return res;
}

TYPE FUNCTION(NAME, divn)(const TYPE x, const DATA_TYPE y) {
  const DATA_TYPE gcd = FUNCTION(DATA_NAME, gcd)(FRACTION_NUM(x), y);
  TYPE res;
  if (1 < gcd) {
    FRACTION_NUM(res) = FRACTION_NUM(x) / gcd;
    FRACTION_DEN(res) = FRACTION_DEN(x) * (y / gcd);
  } else {
    FRACTION_NUM(res) = FRACTION_NUM(x);
    FRACTION_DEN(res) = FRACTION_DEN(x) * y;
  }

  return res;
}

/** mod(x, y) = (a/b) % y = (a * b^(-1)) % y = (a * b^(y-2)) % y */
TYPE FUNCTION(NAME, modn)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  FRACTION_NUM(res) =
      FUNCTION(DATA_NAME, div_mod_s)(FRACTION_NUM(x), FRACTION_DEN(res), y);
  FRACTION_DEN(res) = DATA_ONE;

  return res;
}

TYPE FUNCTION(NAME, pown)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = (FRACTION_NUM(x) == 0 || FRACTION_NUM(x) == 1)
                          ? FRACTION_NUM(x)
                          : (DATA_TYPE)pow(FRACTION_DEN(x), y);
  FRACTION_DEN(res) = FRACTION_DEN(x) == 1 ? FRACTION_DEN(x)
                                           : (DATA_TYPE)pow(FRACTION_DEN(x), y);

  return res;
}

TYPE FUNCTION(NAME, addd)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = (FRACTION_NUM(x) * y) + FRACTION_DEN(x);
  FRACTION_DEN(res) = FRACTION_DEN(x) * y;

  return FUNCTION(NAME, fmt)(res);
}

TYPE FUNCTION(NAME, subd)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = (FRACTION_NUM(x) * y) - FRACTION_DEN(x);
  FRACTION_DEN(res) = FRACTION_DEN(x) * y;

  return FUNCTION(NAME, fmt)(res);
}

TYPE FUNCTION(NAME, muld)(const TYPE x, const DATA_TYPE y) {
  const DATA_TYPE gcd = FUNCTION(DATA_NAME, gcd)(FRACTION_NUM(x), y);
  TYPE res;
  if (1 < gcd) {
    FRACTION_NUM(res) = FRACTION_NUM(x) / gcd;
    FRACTION_DEN(res) = FRACTION_DEN(x) * (y / gcd);
  } else {
    FRACTION_NUM(res) = FRACTION_NUM(x);
    FRACTION_DEN(res) = FRACTION_DEN(x) * y;
  }

  return res;
}

TYPE FUNCTION(NAME, divd)(const TYPE x, const DATA_TYPE y) {
  const DATA_TYPE gcd = FUNCTION(DATA_NAME, gcd)(FRACTION_DEN(x), y);
  TYPE res;
  if (1 < gcd) {
    FRACTION_NUM(res) = FRACTION_NUM(x) * (y / gcd);
    FRACTION_DEN(res) = FRACTION_DEN(x) / gcd;
  } else {
    FRACTION_NUM(res) = FRACTION_NUM(x) * y;
    FRACTION_DEN(res) = FRACTION_DEN(x);
  }

  return res;
}

TYPE FUNCTION(NAME, modd)(const TYPE x, const DATA_TYPE y) {
  TYPE res;

  return res;
}

TYPE FUNCTION(NAME, powd)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = (FRACTION_NUM(x) == 0 || FRACTION_NUM(x) == 1)
                          ? FRACTION_NUM(x)
                          : (DATA_TYPE)pow(FRACTION_DEN(x), 1.0 / y);
  FRACTION_DEN(res) = FRACTION_DEN(x) == 1
                          ? FRACTION_DEN(x)
                          : (DATA_TYPE)pow(FRACTION_DEN(x), 1.0 / y);

  return res;
}
