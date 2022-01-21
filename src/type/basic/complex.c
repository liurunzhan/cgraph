
#include "cgraph_base.h"
#include "cgraph_float64.h"

/***/
#include "cgraph_complex.h"

/** template module */
#include "template_data.ct"

#define CGRAPH_CBUF_SIZE CGRAPH_COMPLEX_CBUF_SIZE
#define CGRAPH_CBUF_PTR cgraph_cbuf_ptr
#include "template_cbuf.ct"

cgraph_char_t *FUNCTION(NAME, encode)(const TYPE cthis) {
  if (DATA_EQ(0.0, COMPLEX_IMAG(cthis))) {
    cgraph_file_snprintf(CGRAPH_CBUF_PTR, CGRAPH_CBUF_SIZE, OUT_FMT_REAL,
                         COMPLEX_REAL(cthis));
  } else {
    cgraph_file_snprintf(CGRAPH_CBUF_PTR, CGRAPH_CBUF_SIZE, OUT_FMT,
                         COMPLEX_REAL(cthis), COMPLEX_IMAG(cthis));
  }

  return CGRAPH_CBUF_PTR;
}

TYPE FUNCTION(NAME, decode)(const cgraph_char_t *cstr, const cgraph_size_t len,
                            cgraph_bool_t *error) {
  TYPE res = FUNCTION(NAME, zero)();
  cgraph_bool_t _error = CGRAPH_FALSE;
  if (CGRAPH_ISSTR(cstr)) {
    cgraph_int_t hit =
        sscanf(cstr, IN_FMT, &(COMPLEX_REAL(res)), &(COMPLEX_IMAG(res)));
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
  if (DATA_EQ(0.0, COMPLEX_IMAG(cthis))) {
    len = cgraph_file_fprintf(fp, OUT_FMT_REAL, COMPLEX_REAL(cthis));
  } else {
    len = cgraph_file_fprintf(fp, OUT_FMT, COMPLEX_REAL(cthis),
                              COMPLEX_IMAG(cthis));
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, snprint)(cgraph_char_t *cbuf,
                                      const cgraph_size_t size,
                                      const TYPE cthis) {
  cgraph_size_t len = 0;
  if (DATA_EQ(0.0, COMPLEX_IMAG(cthis))) {
    len = cgraph_file_snprintf(cbuf, size, OUT_FMT_REAL, COMPLEX_REAL(cthis));
  } else {
    len = cgraph_file_snprintf(cbuf, size, OUT_FMT, COMPLEX_REAL(cthis),
                               COMPLEX_IMAG(cthis));
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, hash)(const TYPE cthis) {
  cgraph_size_t hash = 142857UL;
  hash = hash * COMPLEX_REAL(cthis);
  hash = hash * COMPLEX_IMAG(cthis);

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (DATA_TEST(cthis)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

__INLINE cgraph_int_t FUNCTION(NAME, signbit)(const TYPE x) {
  return DATA_ISPOS(x);
}

/**                         initial function */
__INLINE TYPE FUNCTION(NAME, zero)(void) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_ZERO;
  COMPLEX_IMAG(res) = DATA_ZERO;

  return res;
}

__INLINE TYPE FUNCTION(NAME, one)(void) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_ONE;
  COMPLEX_IMAG(res) = DATA_ZERO;

  return res;
}

__INLINE TYPE FUNCTION(NAME, ones)(void) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_ONE;
  COMPLEX_IMAG(res) = DATA_ONE;

  return res;
}

TYPE FUNCTION(NAME, rand)(void) {
  TYPE res;
  COMPLEX_REAL(res) = FUNCTION(DATA_NAME, rand)();
  COMPLEX_IMAG(res) = FUNCTION(DATA_NAME, rand)();

  return res;
}

__INLINE TYPE FUNCTION(NAME, min)(void) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_MIN;
  COMPLEX_IMAG(res) = DATA_MIN;

  return res;
}

__INLINE TYPE FUNCTION(NAME, max)(void) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_MAX;
  COMPLEX_IMAG(res) = DATA_MAX;

  return res;
}

__INLINE TYPE FUNCTION(NAME, nan)(void) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_NAN;
  COMPLEX_IMAG(res) = DATA_NAN;

  return res;
}

__INLINE TYPE FUNCTION(NAME, inf)(void) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_INF;
  COMPLEX_IMAG(res) = DATA_INF;

  return res;
}

__INLINE TYPE FUNCTION(NAME, pinf)(void) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_PINF;
  COMPLEX_IMAG(res) = DATA_PINF;

  return res;
}

__INLINE TYPE FUNCTION(NAME, ninf)(void) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_NINF;
  COMPLEX_IMAG(res) = DATA_NINF;

  return res;
}

TYPE FUNCTION(NAME, initma)(const DATA_TYPE mag, const DATA_TYPE angle) {
  TYPE res;
  COMPLEX_REAL(res) = mag * cos(angle);
  COMPLEX_IMAG(res) = mag * sin(angle);

  return res;
}

/**
 * The definitions make the following equation established:
 * FUNCTION(NAME, initma)(mag, angle) = FUNCTION(NAME, initm)(mag) *
 * FUNCTION(NAME, inita)(angle)
 */
TYPE FUNCTION(NAME, initm)(const DATA_TYPE mag) {
  TYPE res;
  COMPLEX_REAL(res) = mag;
  COMPLEX_IMAG(res) = DATA_ZERO;

  return res;
}

TYPE FUNCTION(NAME, inita)(const DATA_TYPE angle) {
  TYPE res;
  COMPLEX_REAL(res) = cos(angle);
  COMPLEX_IMAG(res) = sin(angle);

  return res;
}

TYPE FUNCTION(NAME, initri)(const DATA_TYPE real, const DATA_TYPE imag) {
  TYPE res;
  COMPLEX_REAL(res) = real;
  COMPLEX_IMAG(res) = imag;

  return res;
}

/**
 * The definitions make the following equation established:
 * FUNCTION(NAME, initri)(real, imag) = FUNCTION(NAME, initr)(real) +
 * FUNCTION(NAME, initi)(imag)
 */
TYPE FUNCTION(NAME, initr)(const DATA_TYPE real) {
  TYPE res;
  COMPLEX_REAL(res) = real;
  COMPLEX_IMAG(res) = DATA_ZERO;

  return res;
}

TYPE FUNCTION(NAME, initi)(const DATA_TYPE imag) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_ZERO;
  COMPLEX_IMAG(res) = imag;

  return res;
}

TYPE FUNCTION(NAME, unit)(const cgraph_int_t n, const cgraph_int_t i) {
  DATA_TYPE angle = DATA_ONE * MATH_CONST_2PI * i / n;
  TYPE res;
  COMPLEX_REAL(res) = cos(angle);
  COMPLEX_IMAG(res) = sin(angle);

  return res;
}

TYPE FUNCTION(NAME, unit_inv)(const cgraph_int_t n, const cgraph_int_t i) {
  DATA_TYPE angle = DATA_ONE * MATH_CONST_2PI * i / n;
  TYPE res;
  COMPLEX_REAL(res) = cos(angle);
  COMPLEX_IMAG(res) = -sin(angle);

  return res;
}

/**            functions of complex numbers with one complex number */
DATA_TYPE FUNCTION(NAME, real)(const TYPE x) { return COMPLEX_REAL(x); }

DATA_TYPE FUNCTION(NAME, imag)(const TYPE x) { return COMPLEX_IMAG(x); }

DATA_TYPE FUNCTION(NAME, mag2)(const TYPE x) { return COMPLEX_MAG2(x); }

DATA_TYPE FUNCTION(NAME, mag2_inv)(const TYPE x) {
  return DATA_ONE / COMPLEX_MAG2(x);
}

DATA_TYPE FUNCTION(NAME, mag)(const TYPE x) {
#if __STDC_VERSION__ >= 199901L && defined(_MATH_H__)
  return hypot(COMPLEX_REAL(x), COMPLEX_IMAG(x));
#else
  return sqrt(COMPLEX_MAG2(x));
#endif
}

DATA_TYPE FUNCTION(NAME, mag_inv)(const TYPE x) {
  return DATA_ONE / FUNCTION(NAME, mag)(x);
}

DATA_TYPE FUNCTION(NAME, angle)(const TYPE x) {
  return atan2(COMPLEX_IMAG(x), COMPLEX_REAL(x));
}

DATA_TYPE FUNCTION(NAME, dist)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, mag)(FUNCTION(NAME, sub)(x, y));
}

TYPE FUNCTION(NAME, abs)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = fabs(COMPLEX_REAL(x));
  COMPLEX_IMAG(res) = fabs(COMPLEX_IMAG(x));

  return res;
}

TYPE FUNCTION(NAME, std)(const TYPE x) {
  TYPE res;
  DATA_TYPE mag_inv = FUNCTION(NAME, mag_inv)(x);
  COMPLEX_REAL(res) = mag_inv * COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = mag_inv * COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, conj)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = -COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, opp)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = -COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = -COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, inv)(const TYPE x) {
  DATA_TYPE mag2_inv = FUNCTION(NAME, mag2_inv)(x);
  TYPE res;
  COMPLEX_REAL(res) = mag2_inv * COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = -mag2_inv * COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, mul1i)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = -COMPLEX_IMAG(x);
  COMPLEX_IMAG(res) = COMPLEX_REAL(x);

  return res;
}

TYPE FUNCTION(NAME, mul2i)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = -COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = -COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, mul3i)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_IMAG(x);
  COMPLEX_IMAG(res) = -COMPLEX_REAL(x);

  return res;
}
TYPE FUNCTION(NAME, mul4i)(const TYPE x) { return x; }

TYPE FUNCTION(NAME, revert)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_IMAG(x);
  COMPLEX_IMAG(res) = COMPLEX_REAL(x);

  return res;
}

/**                 one complex number and one complex number */
TYPE FUNCTION(NAME, add)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) + COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) + COMPLEX_IMAG(y);

  return res;
}

TYPE FUNCTION(NAME, sub)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) - COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) - COMPLEX_IMAG(y);

  return res;
}

TYPE FUNCTION(NAME, mul)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) =
      COMPLEX_REAL(x) * COMPLEX_REAL(y) - COMPLEX_IMAG(x) * COMPLEX_IMAG(y);
  COMPLEX_IMAG(res) =
      COMPLEX_REAL(x) * COMPLEX_IMAG(y) + COMPLEX_IMAG(x) * COMPLEX_REAL(y);

  return res;
}

TYPE FUNCTION(NAME, div)(const TYPE x, const TYPE y) {
  DATA_TYPE mag2_inv = FUNCTION(NAME, mag2_inv)(y);
  TYPE res;
  COMPLEX_REAL(res) =
      (COMPLEX_REAL(x) * COMPLEX_REAL(y) + COMPLEX_IMAG(x) * COMPLEX_IMAG(y)) *
      mag2_inv;
  COMPLEX_IMAG(res) =
      (COMPLEX_IMAG(x) * COMPLEX_REAL(y) - COMPLEX_REAL(x) * COMPLEX_IMAG(y)) *
      mag2_inv;

  return res;
}

TYPE FUNCTION(NAME, dot)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, mul)(x, FUNCTION(NAME, conj)(y));
}

TYPE FUNCTION(NAME, dot_conj)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, mul)(FUNCTION(NAME, conj)(x), y);
}

TYPE FUNCTION(NAME, log)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = log(FUNCTION(NAME, mag)(x));
  COMPLEX_IMAG(res) = FUNCTION(NAME, angle)(x);

  return res;
}

TYPE FUNCTION(NAME, log2)(const TYPE x) {
  TYPE res = FUNCTION(NAME, log)(x);
  COMPLEX_REAL(res) = COMPLEX_REAL(res) / MATH_CONST_LOG2;
  COMPLEX_IMAG(res) = COMPLEX_IMAG(res) / MATH_CONST_LOG2;

  return res;
}

TYPE FUNCTION(NAME, log10)(const TYPE x) {
  TYPE res = FUNCTION(NAME, log)(x);
  COMPLEX_REAL(res) = COMPLEX_REAL(res) / MATH_CONST_LOG10;
  COMPLEX_IMAG(res) = COMPLEX_IMAG(res) / MATH_CONST_LOG10;

  return res;
}

TYPE FUNCTION(NAME, exp)(const TYPE x) {
  DATA_TYPE mag = exp(COMPLEX_REAL(x));
  TYPE res;
  COMPLEX_REAL(res) = mag * cos(COMPLEX_IMAG(x));
  COMPLEX_IMAG(res) = mag * sin(COMPLEX_IMAG(x));

  return res;
}

TYPE FUNCTION(NAME, sqrt)(const TYPE x) {
  DATA_TYPE mag = sqrt(FUNCTION(NAME, mag)(x)),
            angle = 0.5 * FUNCTION(NAME, angle)(x);
  TYPE res;
  COMPLEX_REAL(res) = mag * cos(angle);
  COMPLEX_IMAG(res) = mag * sin(angle);

  return res;
}

TYPE FUNCTION(NAME, pow)(const TYPE x, const TYPE y) {
  TYPE res = FUNCTION(NAME, log)(x);
  res = FUNCTION(NAME, mul)(y, res);

  return FUNCTION(NAME, exp)(res);
}

TYPE FUNCTION(NAME, int)(const TYPE x, const TYPE y) {
  TYPE res;
  DATA_TYPE res_real =
                FUNCTION(DATA_NAME, idiv)(COMPLEX_REAL(x), COMPLEX_REAL(y)),
            res_imag =
                FUNCTION(DATA_NAME, idiv)(COMPLEX_IMAG(x), COMPLEX_IMAG(y));
  COMPLEX_REAL(res) = CGRAPH_MIN(res_real, res_imag);
  COMPLEX_IMAG(res) = DATA_ZERO;

  return res;
}

TYPE FUNCTION(NAME, mod)(const TYPE x, const TYPE y) {
  TYPE res = FUNCTION(NAME, int)(x, y);
  COMPLEX_REAL(res) = COMPLEX_REAL(x) - COMPLEX_REAL(y) * COMPLEX_REAL(res);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) - COMPLEX_IMAG(y) * COMPLEX_REAL(res);

  return res;
}

TYPE FUNCTION(NAME, sin)(const TYPE x) {
  TYPE ix = FUNCTION(NAME, mul1i)(x), _ix = FUNCTION(NAME, mul3i)(x);
  TYPE expix = FUNCTION(NAME, exp)(ix), exp_ix = FUNCTION(NAME, exp)(_ix);
  TYPE res;
  COMPLEX_REAL(res) = 0.5 * (COMPLEX_IMAG(expix) - COMPLEX_IMAG(exp_ix));
  COMPLEX_IMAG(res) = -0.5 * (COMPLEX_REAL(expix) - COMPLEX_REAL(exp_ix));

  return res;
}

TYPE FUNCTION(NAME, cos)(const TYPE x) {
  TYPE ix = FUNCTION(NAME, mul1i)(x), _ix = FUNCTION(NAME, mul3i)(x);
  TYPE expix = FUNCTION(NAME, exp)(ix), exp_ix = FUNCTION(NAME, exp)(_ix);
  TYPE res;
  COMPLEX_REAL(res) = 0.5 * (COMPLEX_REAL(expix) + COMPLEX_REAL(exp_ix));
  COMPLEX_IMAG(res) = 0.5 * (COMPLEX_IMAG(expix) + COMPLEX_IMAG(exp_ix));

  return res;
}

TYPE FUNCTION(NAME, tan)(const TYPE x) {
  TYPE sinx = FUNCTION(NAME, sin)(x), cosx = FUNCTION(NAME, cos)(x);

  return FUNCTION(NAME, div)(sinx, cosx);
}

TYPE FUNCTION(NAME, cot)(const TYPE x) {
  TYPE sinx = FUNCTION(NAME, sin)(x), cosx = FUNCTION(NAME, cos)(x);

  return FUNCTION(NAME, div)(cosx, sinx);
}

TYPE FUNCTION(NAME, sec)(const TYPE x) {
  TYPE cosx = FUNCTION(NAME, cos)(x);

  return FUNCTION(NAME, inv)(cosx);
}

TYPE FUNCTION(NAME, csc)(const TYPE x) {
  TYPE sinx = FUNCTION(NAME, sin)(x);

  return FUNCTION(NAME, inv)(sinx);
}

TYPE FUNCTION(NAME, sinh)(const TYPE x) {
  TYPE expx = FUNCTION(NAME, exp)(x),
       exp_x = FUNCTION(NAME, exp)(FUNCTION(NAME, mul2i)(x));
  TYPE res;
  COMPLEX_REAL(res) = 0.5 * (COMPLEX_REAL(expx) - COMPLEX_REAL(exp_x));
  COMPLEX_IMAG(res) = 0.5 * (COMPLEX_IMAG(expx) - COMPLEX_IMAG(exp_x));

  return res;
}

TYPE FUNCTION(NAME, cosh)(const TYPE x) {
  TYPE expx = FUNCTION(NAME, exp)(x),
       exp_x = FUNCTION(NAME, exp)(FUNCTION(NAME, mul2i)(x));
  TYPE res;
  COMPLEX_REAL(res) = 0.5 * (COMPLEX_REAL(expx) + COMPLEX_REAL(exp_x));
  COMPLEX_IMAG(res) = 0.5 * (COMPLEX_IMAG(expx) + COMPLEX_IMAG(exp_x));

  return res;
}

TYPE FUNCTION(NAME, tanh)(const TYPE x) {
  TYPE sinhx = FUNCTION(NAME, sinh)(x), coshx = FUNCTION(NAME, cosh)(x);

  return FUNCTION(NAME, div)(sinhx, coshx);
}

TYPE FUNCTION(NAME, coth)(const TYPE x) {
  TYPE sinhx = FUNCTION(NAME, sinh)(x), coshx = FUNCTION(NAME, cosh)(x);

  return FUNCTION(NAME, div)(coshx, sinhx);
}

TYPE FUNCTION(NAME, sech)(const TYPE x) {
  TYPE coshx = FUNCTION(NAME, cosh)(x);

  return FUNCTION(NAME, inv)(coshx);
}

TYPE FUNCTION(NAME, csch)(const TYPE x) {
  TYPE sinhx = FUNCTION(NAME, sinh)(x);

  return FUNCTION(NAME, inv)(sinhx);
}

TYPE FUNCTION(NAME, asin)(const TYPE x) {
  TYPE x2 = FUNCTION(NAME, mul)(x, x), ix = FUNCTION(NAME, mul1i)(x);
  TYPE x2_1 = FUNCTION(NAME, subr)(x2, DATA_ONE),
       s_1_x2 = FUNCTION(NAME, sqrt)(FUNCTION(NAME, opp)(x2_1)),
       ix_s_1_x2 = FUNCTION(NAME, add)(ix, s_1_x2);
  TYPE ln_ix_s_1_x2 = FUNCTION(NAME, log)(ix_s_1_x2), res;
  COMPLEX_REAL(res) = COMPLEX_IMAG(ln_ix_s_1_x2);
  COMPLEX_IMAG(res) = -COMPLEX_REAL(ln_ix_s_1_x2);

  return res;
}

TYPE FUNCTION(NAME, acos)(const TYPE x) {
  TYPE x2 = FUNCTION(NAME, mul)(x, x),
       x2_1 = FUNCTION(NAME, subr)(x2, DATA_ONE);
  TYPE s_1_x2 = FUNCTION(NAME, sqrt)(FUNCTION(NAME, opp)(x2_1));
  TYPE x_is_1_x2 = FUNCTION(NAME, add)(x, FUNCTION(NAME, mul1i)(s_1_x2));
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_IMAG(x_is_1_x2);
  COMPLEX_IMAG(res) = -COMPLEX_REAL(x_is_1_x2);

  return res;
}

TYPE FUNCTION(NAME, atan)(const TYPE x) {
  TYPE x_i = FUNCTION(NAME, subi)(x, DATA_ONE),
       x__i = FUNCTION(NAME, addi)(x, DATA_ONE),
       log_log = FUNCTION(NAME, sub)(FUNCTION(NAME, log)(x_i),
                                     FUNCTION(NAME, log)(x__i));
  TYPE res;
  COMPLEX_REAL(res) = 0.5 * (MATH_CONST_PI + COMPLEX_IMAG(log_log));
  COMPLEX_IMAG(res) = -0.5 * COMPLEX_REAL(log_log);

  return res;
}

__INLINE cgraph_bool_t FUNCTION(NAME, ispos)(const TYPE x) {
  return CGRAPH_TEST(DATA_ISPOS(x));
}

__INLINE cgraph_bool_t FUNCTION(NAME, isneg)(const TYPE x) {
  return CGRAPH_TEST(DATA_ISNEG(x));
}

__INLINE cgraph_bool_t FUNCTION(NAME, iszero)(const TYPE x) {
  return EQ(x, ZERO);
}

__INLINE cgraph_bool_t FUNCTION(NAME, ismax)(const TYPE x) {
  return EQ(x, MAX);
}

__INLINE cgraph_bool_t FUNCTION(NAME, ismin)(const TYPE x) {
  return EQ(x, MIN);
}

__INLINE cgraph_bool_t FUNCTION(NAME, isnan)(const TYPE x) {
  return CGRAPH_TEST(DATA_ISNAN(x));
}

__INLINE cgraph_bool_t FUNCTION(NAME, isinf)(const TYPE x) {
  return CGRAPH_TEST(DATA_ISINF(x));
}

__INLINE cgraph_bool_t FUNCTION(NAME, ispinf)(const TYPE x) {
  return CGRAPH_TEST(DATA_ISPINF(x));
}

__INLINE cgraph_bool_t FUNCTION(NAME, isninf)(const TYPE x) {
  return CGRAPH_TEST(DATA_ISNINF(x));
}

__INLINE cgraph_bool_t FUNCTION(NAME, eq)(const TYPE x, const TYPE y) {
  return EQ(x, y);
}

__INLINE cgraph_bool_t FUNCTION(NAME, gr)(const TYPE x, const TYPE y) {
  return GR(x, y);
}

/**
 * @brief functions of complex numbers with one complex number and one data
 types one complex number and one real part of one complex number
 */
TYPE FUNCTION(NAME, addr)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) + y;
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, subr)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) - y;
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, mulr)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) * y;
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) * y;

  return res;
}

TYPE FUNCTION(NAME, divr)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) / y;
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) / y;

  return res;
}

TYPE FUNCTION(NAME, powr)(const TYPE x, const DATA_TYPE y) {
  DATA_TYPE mag = pow(FUNCTION(NAME, mag)(x), y),
            angle = FUNCTION(NAME, angle)(x) * y;
  TYPE res;
  COMPLEX_REAL(res) = mag * cos(angle);
  COMPLEX_IMAG(res) = mag * sin(angle);

  return res;
}

/**        one complex number and one image part of one complex number */
TYPE FUNCTION(NAME, addi)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) + y;

  return res;
}

TYPE FUNCTION(NAME, subi)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) - y;

  return res;
}

TYPE FUNCTION(NAME, muli)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = -DATA_ONE * COMPLEX_IMAG(x) * y;
  COMPLEX_IMAG(res) = COMPLEX_REAL(x) * y;

  return res;
}

TYPE FUNCTION(NAME, divi)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_IMAG(x) / y;
  COMPLEX_IMAG(res) = -DATA_ONE * COMPLEX_REAL(x) / y;

  return res;
}

TYPE FUNCTION(NAME, powi)(const TYPE x, const DATA_TYPE y) {
  TYPE res = FUNCTION(NAME, log)(x);

  return FUNCTION(NAME, exp)(FUNCTION(NAME, muli)(res, y));
}

/** @brief Fast Fourier Transform (fft) */
TYPE *FUNCTION(NAME, fft)(TYPE *cthis, const cgraph_size_t len) {
  if ((NULL != cthis) && (0 < len) && (0 == (len & 0x01))) {
    cgraph_size_t i, j, k, times = cgraph_math_log2(len);
    for (i = 0, j = len / 2; i < (len - 2); i++) {
      cgraph_size_t k = len / 2;
      if (i < j) {
        SWAP(cthis[i], cthis[j]);
      }
      while (k <= j) {
        j = j - k;
        k /= 2;
      }
      j += k;
    }
    for (i = 0; i < times; i++) {
      cgraph_size_t group0 = cgraph_math_pow2(i), group1 = group0 / 2;
      for (j = 0; j < group1; j++) {
        cgraph_size_t n = j * cgraph_math_pow2(len - times);
        for (k = i; k < len; j += group0) {
          cgraph_size_t group2 = k + group1;
          TYPE wn = FUNCTION(NAME, unit)(len, n),
               xwn = FUNCTION(NAME, mul)(cthis[group2], wn);
          cthis[group2] = FUNCTION(NAME, sub)(cthis[k], xwn);
          cthis[k] = FUNCTION(NAME, add)(cthis[k], xwn);
        }
      }
    }
  }

  return cthis;
}

/** @brief Inverse Fast Fourier Transform */
TYPE *FUNCTION(NAME, ifft)(TYPE *cthis, const cgraph_size_t len) {
  if ((NULL != cthis) && (0 < len) && (0 == (len & 0x01))) {
    cgraph_size_t i;
    for (i = 0; i < len; i++) {
      cthis[i] = FUNCTION(NAME, conj)(cthis[i]);
    }
    cthis = FUNCTION(NAME, fft)(cthis, len);
    for (i = 0; i < len; i++) {
      cthis[i] = FUNCTION(NAME, conj)(cthis[i]);
    }
    for (i = 0; i < len; i++) {
      cthis[i] = FUNCTION(NAME, divr)(cthis[i], len);
    }
  }

  return cthis;
}
