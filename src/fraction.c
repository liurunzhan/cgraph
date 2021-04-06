#include "cgraph_base.h"
#include "cgraph_int.h"

#include "cgraph_fraction.h"

#define TYPE_FRACTION
#include "cgraph_template.h"

/** template module */
#include "template_data.ct"

cgraph_size_t FUNCTION(NAME, printf)(const TYPE x) {
  return fprintf(stdout, OUT_FORMAT, FRACTION_NUM(x), FRACTION_DEN(x));
}

cgraph_size_t FUNCTION(NAME, fprintf)(FILE *fp, const TYPE x) {
  return fprintf(fp, OUT_FORMAT, FRACTION_NUM(x), FRACTION_DEN(x));
}

cgraph_size_t FUNCTION(NAME, snprintf)(cgraph_char_t *buffer,
                                       const cgraph_size_t size, const TYPE x) {
  return cgraph_file_snprintf(buffer, size, OUT_FORMAT, FRACTION_NUM(x),
                              FRACTION_DEN(x));
}

/**                               public apis */
/*
  fnv-1a hash function (Fowler-Noll-Vo hash function, proposed by Glenn
  Fowler，Landon Curt Noll and Phong Vo in 1991): begin_of_algorithm hash =
  offset_basis for byte_of_data in data begin hash = hash ^ byte_of_data hash =
  hash * fnv_prime end return hash end_of_algorithm 32-bit offset_basis :
  2166136261 32-bit fnv_prime : 16777619 = 2^24 + 2^8 + 0x93 64-bit offset_basis
  : 14695981039346656037 64-bit fnv_prime : 1099511628211 = 2^40 + 2^8 + 0xb3
*/
cgraph_size_t FUNCTION(NAME, hash)(const TYPE cthis) {
  cgraph_size_t hash = 2166136261UL;
  hash = (hash ^ FRACTION_NUM(cthis)) * 16777619UL;
  hash = ((hash >> 8) ^ FRACTION_DEN(cthis)) * 16777619UL;

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE cthis) {
  return CGRAPH_TEST(0 != FRACTION_DEN(cthis));
}

TYPE FUNCTION(NAME, format)(const TYPE cthis) {
  DATA_TYPE gcd =
      FUNCTION(DATA_NAME, gcd)(FRACTION_NUM(cthis), FRACTION_DEN(cthis));
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(cthis);
  FRACTION_DEN(res) = FRACTION_DEN(cthis);
  if (gcd != 1) {
    FRACTION_NUM(res) = FRACTION_NUM(res) / gcd;
    FRACTION_DEN(res) = FRACTION_DEN(res) / gcd;
  }

  return res;
}

/**                              private apis                                 */
TYPE FUNCTION(NAME, zero)(void) {
  TYPE res;
  FRACTION_NUM(res) = 0;
  FRACTION_DEN(res) = 1;

  return res;
}

TYPE FUNCTION(NAME, one)(void) {
  TYPE res;
  FRACTION_NUM(res) = 1;
  FRACTION_DEN(res) = 1;

  return res;
}

TYPE FUNCTION(NAME, ones)(void) {
  TYPE res;
  FRACTION_NUM(res) = DATA_MIN;
  FRACTION_DEN(res) = 1;

  return res;
}

TYPE FUNCTION(NAME, random)(void) {
  TYPE res;
  FRACTION_NUM(res) = cgraph_random32();
  FRACTION_DEN(res) = cgraph_random32();
  return res;
}

TYPE FUNCTION(NAME, initf32)(const cgraph_float32_t data) {
  TYPE res;
  DATA_TYPE int_part = floor(data), gcd;
  cgraph_float32_t float_part = data - int_part;
  cgraph_size_t i;
  FRACTION_NUM(res) = 0;
  FRACTION_DEN(res) = 1;
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
  TYPE res;
  DATA_TYPE int_part = floor(data), gcd;
  cgraph_float64_t float_part = data - int_part;
  cgraph_size_t i;
  FRACTION_NUM(res) = 0;
  FRACTION_DEN(res) = 1;
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

TYPE FUNCTION(NAME, initwnd)(const DATA_TYPE num, const DATA_TYPE den) {
  TYPE res;
  FRACTION_NUM(res) = num;
  FRACTION_DEN(res) = den;

  return res;
}

TYPE FUNCTION(NAME, initwn)(const DATA_TYPE num) {
  TYPE res;
  FRACTION_NUM(res) = num;
  FRACTION_DEN(res) = 1;

  return res;
}

TYPE FUNCTION(NAME, initwd)(const DATA_TYPE den) {
  TYPE res;
  FRACTION_NUM(res) = 1;
  FRACTION_DEN(res) = den;

  return res;
}

CGRAPH_INLINE cgraph_int_t FUNCTION(NAME, signbit)(const TYPE x) {
  cgraph_int_t flag = -1,
               num_flag =
                   (FRACTION_NUM(x) | (FRACTION_NUM(x) >> (DATA_BITS - 1))),
               den_flag =
                   (FRACTION_NUM(x) | (FRACTION_NUM(x) >> (DATA_BITS - 1)));
  if ((0 == num_flag) || (0 == den_flag)) {
    flag = 0;
  } else if (num_flag == den_flag) {
    flag = 1;
  }

  return flag;
}

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, iszero)(const TYPE x) {
  return CGRAPH_TEST((!FRACTION_NUM(x)) && FRACTION_DEN(x));
}

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, isodd)(const TYPE x) {
  return CGRAPH_TEST((1 == FRACTION_DEN(x)) && (FRACTION_NUM(x) & 1));
}

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, iseven)(const TYPE x) {
  return CGRAPH_TEST((1 == FRACTION_DEN(x)) && ((~FRACTION_NUM(x)) & 1));
}

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, ispow2)(const TYPE x) {
  return CGRAPH_TEST(
      ((0 < FRACTION_NUM(x)) && (!(FRACTION_NUM(x) & (FRACTION_NUM(x) - 1)))) &&
      ((0 < FRACTION_DEN(x)) && (!(FRACTION_DEN(x) & (FRACTION_DEN(x) - 1)))));
}

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, ispos)(const TYPE x) {
  return CGRAPH_TEST(1 == FUNCTION(NAME, signbit)(x));
}

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, isneg)(const TYPE x) {
  return CGRAPH_TEST(-1 == FUNCTION(NAME, signbit)(x));
}

static const TYPE cgraph_fraction_min = MIN;

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, ismin)(const TYPE x) {
  return CGRAPH_TEST(EQ(x, cgraph_fraction_min));
}

static const TYPE cgraph_fraction_max = MAX;

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, ismax)(const TYPE x) {
  return CGRAPH_TEST(EQ(x, cgraph_fraction_max));
}

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, isnan)(const TYPE x) {
  return CGRAPH_TEST((!FRACTION_NUM(x)) && (!FRACTION_DEN(x)));
}

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, isinf)(const TYPE x) {
  return CGRAPH_TEST(FRACTION_NUM(x) && (!FRACTION_DEN(x)));
}

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, ispinf)(const TYPE x) {
  return CGRAPH_TEST((1 == FUNCTION(NAME, signbit)(x)) && (!FRACTION_DEN(x)));
}

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, isninf)(const TYPE x) {
  return CGRAPH_TEST((-1 == FUNCTION(NAME, signbit)(x)) && (!FRACTION_DEN(x)));
}

TYPE FUNCTION(NAME, abs)(const TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = CGRAPH_ABS(FRACTION_NUM(x));
  FRACTION_DEN(res) = CGRAPH_ABS(FRACTION_DEN(x));

  return res;
}

TYPE FUNCTION(NAME, opp)(const TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = -FRACTION_NUM(x);
  FRACTION_DEN(res) = -FRACTION_DEN(x);

  return res;
}

TYPE FUNCTION(NAME, inv)(const TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_DEN(x);
  FRACTION_DEN(res) = FRACTION_NUM(x);

  return res;
}

TYPE FUNCTION(NAME, add)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) =
      FRACTION_NUM(x) * FRACTION_DEN(y) + FRACTION_DEN(x) * FRACTION_NUM(y);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y);

  return res;
}

TYPE FUNCTION(NAME, sub)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) =
      FRACTION_NUM(x) * FRACTION_DEN(y) - FRACTION_DEN(x) * FRACTION_NUM(y);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y);

  return res;
}

TYPE FUNCTION(NAME, mul)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_NUM(y);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y);

  return res;
}

TYPE FUNCTION(NAME, div)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * FRACTION_DEN(y);
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_NUM(y);

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

  return res;
}

TYPE FUNCTION(NAME, mod)(const TYPE x, const TYPE y) {
  TYPE res;
  FRACTION_DEN(res) = FRACTION_DEN(x) * FRACTION_DEN(y);
  FRACTION_NUM(res) =
      (FRACTION_DEN(y) * FRACTION_NUM(x)) % (FRACTION_DEN(x) * FRACTION_NUM(y));

  return res;
}

TYPE FUNCTION(NAME, ceil)(const TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) / FRACTION_DEN(x) * FRACTION_DEN(x);
  if (FRACTION_NUM(res) != FRACTION_NUM(x)) {
    FRACTION_NUM(res) += FRACTION_DEN(x);
  }
  FRACTION_DEN(res) = FRACTION_DEN(x);

  return res;
}

TYPE FUNCTION(NAME, floor)(const TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) / FRACTION_DEN(x) * FRACTION_DEN(x);
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

TYPE FUNCTION(NAME, sqrt)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, unit)(const DATA_TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = x;
  FRACTION_DEN(res) = 1;

  return res;
}

TYPE FUNCTION(NAME, unit_inv)(const DATA_TYPE x) {
  TYPE res;
  FRACTION_NUM(res) = 1;
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
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * y;
  FRACTION_DEN(res) = FRACTION_DEN(x);

  return res;
}

TYPE FUNCTION(NAME, divn)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x);
  FRACTION_DEN(res) = FRACTION_DEN(x) * y;

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
  FRACTION_NUM(res) = FRACTION_NUM(x) * y + FRACTION_DEN(x);
  FRACTION_DEN(res) = FRACTION_DEN(x) * y;

  return res;
}

TYPE FUNCTION(NAME, subd)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * y - FRACTION_DEN(x);
  FRACTION_DEN(res) = FRACTION_DEN(x) * y;

  return res;
}

TYPE FUNCTION(NAME, muld)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x);
  FRACTION_DEN(res) = FRACTION_DEN(x) * y;

  return res;
}

TYPE FUNCTION(NAME, divd)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  FRACTION_NUM(res) = FRACTION_NUM(x) * y;
  FRACTION_DEN(res) = FRACTION_DEN(x);

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

#include "cgraph_template_off.h"
