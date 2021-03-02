#include "cgraph_complex.h"
#include "cgraph_file.h"
#include "cgraph_float64.h"
#include "cgraph_math.h"
#include "cgraph_memory.h"

#define TYPE_COMPLEX
#include "template.h"

/**/
#include "data_base.ct"

cgraph_int_t FUNCTION(NAME, printf)(const TYPE x, const cgraph_char_t *sep) {
  return fprintf(stdout, OUT_FORMAT "%s" OUT_FORMAT, COMPLEX_REAL(x), sep,
                 COMPLEX_IMAG(x));
}

cgraph_int_t FUNCTION(NAME, fprintf)(FILE *fp, const TYPE x,
                                     const cgraph_char_t *sep) {
  return fprintf(fp, OUT_FORMAT "%s" OUT_FORMAT, COMPLEX_REAL(x), sep,
                 COMPLEX_IMAG(x));
}

cgraph_int_t FUNCTION(NAME, snprintf)(cgraph_char_t *buffer,
                                      const cgraph_size_t size, const TYPE x,
                                      const cgraph_char_t *sep) {
  return cgraph_file_snprintf(buffer, size, OUT_FORMAT "%s" OUT_FORMAT,
                              COMPLEX_REAL(x), sep, COMPLEX_IMAG(x));
}

cgraph_size_t FUNCTION(NAME, hash)(const TYPE cthis) {
  cgraph_size_t hash = 142857UL;
  hash = hash * COMPLEX_REAL(cthis);
  hash = hash * COMPLEX_IMAG(cthis);

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (DATA_TEST(COMPLEX_REAL(cthis)) && DATA_TEST(COMPLEX_IMAG(cthis))) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

/**                         initial function */
TYPE FUNCTION(NAME, initwma)(const DATA_TYPE abs, const DATA_TYPE angle) {
  TYPE res;
  COMPLEX_REAL(res) = abs * cos(angle);
  COMPLEX_IMAG(res) = abs * sin(angle);

  return res;
}

TYPE FUNCTION(NAME, initwm)(const DATA_TYPE abs) {
  TYPE res;
  COMPLEX_REAL(res) = abs;
  COMPLEX_IMAG(res) = 0.0;

  return res;
}

TYPE FUNCTION(NAME, initwa)(const DATA_TYPE angle) {
  TYPE res;
  COMPLEX_REAL(res) = cos(angle);
  COMPLEX_IMAG(res) = sin(angle);

  return res;
}

TYPE FUNCTION(NAME, initwri)(const DATA_TYPE real, const DATA_TYPE imag) {
  TYPE res;
  COMPLEX_REAL(res) = real;
  COMPLEX_IMAG(res) = imag;

  return res;
}

TYPE FUNCTION(NAME, initwr)(const DATA_TYPE real) {
  TYPE res;
  COMPLEX_REAL(res) = real;
  COMPLEX_IMAG(res) = 0.0;

  return res;
}

TYPE FUNCTION(NAME, initwi)(const DATA_TYPE imag) {
  TYPE res;
  COMPLEX_REAL(res) = 0.0;
  COMPLEX_IMAG(res) = imag;

  return res;
}

TYPE FUNCTION(NAME, unit)(const cgraph_int_t n, const cgraph_int_t i) {
  DATA_TYPE angle = 1.0 * MATH_CONST_2PI * i / n;
  TYPE res;
  COMPLEX_REAL(res) = cos(angle);
  COMPLEX_IMAG(res) = sin(angle);

  return res;
}

TYPE FUNCTION(NAME, unit_inv)(const cgraph_int_t n, const cgraph_int_t i) {
  DATA_TYPE angle = 1.0 * MATH_CONST_2PI * i / n;
  TYPE res;
  COMPLEX_REAL(res) = cos(angle);
  COMPLEX_IMAG(res) = -sin(angle);

  return res;
}

/**            functions of complex numbers with one complex number */
DATA_TYPE FUNCTION(NAME, real)(const TYPE x) { return COMPLEX_REAL(x); }

DATA_TYPE FUNCTION(NAME, imag)(const TYPE x) { return COMPLEX_IMAG(x); }

DATA_TYPE FUNCTION(NAME, abs)(const TYPE x) {
#if CGRAPH_STDC_VERSION >= 199901L && defined(_MATH_H_)
  return hypot(COMPLEX_REAL(x), COMPLEX_IMAG(x));
#else
  return sqrt(COMPLEX_MOD2(x));
#endif
}

DATA_TYPE FUNCTION(NAME, angle)(const TYPE x) {
  return atan2(COMPLEX_IMAG(x), COMPLEX_REAL(x));
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
  TYPE res = FUNCTION(NAME, conj)(x);
  DATA_TYPE abs_inv = 1.0 / FUNCTION(NAME, abs)(x);
  COMPLEX_REAL(res) = abs_inv * COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = abs_inv * COMPLEX_IMAG(x);

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
TYPE FUNCTION(NAME, mul4i)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x);

  return res;
}

/**                 one complex number and one complex number */
TYPE FUNCTION(NAME, add)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) + COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) + COMPLEX_IMAG(y);
  * /

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
  DATA_TYPE mod_1 = 1.0 / COMPLEX_MOD2(y);
  TYPE res;
  COMPLEX_REAL(res) =
      (COMPLEX_REAL(x) * COMPLEX_REAL(y) + COMPLEX_IMAG(x) * COMPLEX_IMAG(y)) *
      mod_1;
  COMPLEX_IMAG(res) =
      (COMPLEX_IMAG(x) * COMPLEX_REAL(y) - COMPLEX_REAL(x) * COMPLEX_IMAG(y)) *
      mod_1;

  return res;
}

TYPE FUNCTION(NAME, log)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = log(FUNCTION(NAME, abs)(x));
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
  DATA_TYPE abs = exp(COMPLEX_REAL(x));
  TYPE res;
  COMPLEX_REAL(res) = abs * cos(COMPLEX_IMAG(x));
  COMPLEX_IMAG(res) = abs * sin(COMPLEX_IMAG(x));

  return res;
}

TYPE FUNCTION(NAME, sqrt)(const TYPE x) {
  DATA_TYPE abs = sqrt(FUNCTION(NAME, abs)(x)),
            angle = 0.5 * FUNCTION(NAME, angle)(x);
  TYPE res;
  COMPLEX_REAL(res) = abs * cos(angle);
  COMPLEX_IMAG(res) = abs * sin(angle);

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
                FUNCTION(DATA_NAME, int)(COMPLEX_REAL(x), COMPLEX_REAL(y)),
            res_imag =
                FUNCTION(DATA_NAME, int)(COMPLEX_IMAG(x), COMPLEX_IMAG(y));
  COMPLEX_REAL(res) = CGRAPH_MIN(res_real, res_imag);
  COMPLEX_IMAG(res) = 0.0;

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
  TYPE res = FUNCTION(NAME, div)(sinx, cosx);

  return res;
}

TYPE FUNCTION(NAME, cot)(const TYPE x) {
  TYPE sinx = FUNCTION(NAME, sin)(x), cosx = FUNCTION(NAME, cos)(x);
  TYPE res = FUNCTION(NAME, div)(cosx, sinx);

  return res;
}

TYPE FUNCTION(NAME, sec)(const TYPE x) {
  TYPE cosx = FUNCTION(NAME, cos)(x);
  TYPE res = FUNCTION(NAME, inv)(cosx);

  return res;
}

TYPE FUNCTION(NAME, csc)(const TYPE x) {
  TYPE sinx = FUNCTION(NAME, sin)(x);
  TYPE res = FUNCTION(NAME, inv)(sinx);

  return res;
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
  TYPE res = FUNCTION(NAME, div)(sinhx, coshx);

  return res;
}

TYPE FUNCTION(NAME, coth)(const TYPE x) {
  TYPE sinhx = FUNCTION(NAME, sinh)(x), coshx = FUNCTION(NAME, cosh)(x);
  TYPE res = FUNCTION(NAME, div)(coshx, sinhx);

  return res;
}

TYPE FUNCTION(NAME, sech)(const TYPE x) {
  TYPE coshx = FUNCTION(NAME, cosh)(x);
  TYPE res = FUNCTION(NAME, inv)(coshx);

  return res;
}

TYPE FUNCTION(NAME, csch)(const TYPE x) {
  TYPE sinhx = FUNCTION(NAME, sinh)(x);
  TYPE res = FUNCTION(NAME, inv)(sinhx);

  return res;
}

TYPE FUNCTION(NAME, asin)(const TYPE x) {
  TYPE x2 = FUNCTION(NAME, mul)(x, x), ix = FUNCTION(NAME, mul1i)(x);
  TYPE x2_1 = FUNCTION(NAME, subr)(x2, 1.0),
       s_1_x2 = FUNCTION(NAME, sqrt)(FUNCTION(NAME, opp)(x2_1)),
       ix_s_1_x2 = FUNCTION(NAME, add)(ix, s_1_x2);
  TYPE ln_ix_s_1_x2 = FUNCTION(NAME, log)(ix_s_1_x2), res;
  COMPLEX_REAL(res) = COMPLEX_IMAG(ln_ix_s_1_x2);
  COMPLEX_IMAG(res) = -COMPLEX_REAL(ln_ix_s_1_x2);

  return res;
}

TYPE FUNCTION(NAME, acos)(const TYPE x) {
  TYPE x2 = FUNCTION(NAME, mul)(x, x), x2_1 = FUNCTION(NAME, subr)(x2, 1.0);
  TYPE s_1_x2 = FUNCTION(NAME, sqrt)(FUNCTION(NAME, opp)(x2_1));
  TYPE x_is_1_x2 = FUNCTION(NAME, add)(x, FUNCTION(NAME, mul1i)(s_1_x2));
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_IMAG(x_is_1_x2);
  COMPLEX_IMAG(res) = -COMPLEX_REAL(x_is_1_x2);

  return res;
}

TYPE FUNCTION(NAME, atan)(const TYPE x) {
  TYPE x_i = FUNCTION(NAME, subi)(x, 1.0), x__i = FUNCTION(NAME, addi)(x, 1.0),
       log_log = FUNCTION(NAME, sub)(FUNCTION(NAME, log)(x_i),
                                     FUNCTION(NAME, log)(x__i));
  TYPE res;
  COMPLEX_REAL(res) = 0.5 * (MATH_CONST_PI + COMPLEX_IMAG(log_log));
  COMPLEX_IMAG(res) = -0.5 * COMPLEX_REAL(log_log);

  return res;
}

cgraph_bool_t FUNCTION(NAME, isnan)(const TYPE x) {
  return CGRAPH_TEST(DATA_ISNAN(COMPLEX_REAL(x)) ||
                     DATA_ISNAN(COMPLEX_IMAG(x)));
}

cgraph_bool_t FUNCTION(NAME, isinf)(const TYPE x) {
  return CGRAPH_TEST(DATA_ISINF(COMPLEX_REAL(x)) ||
                     DATA_ISINF(COMPLEX_IMAG(x)));
}

cgraph_bool_t FUNCTION(NAME, ispinf)(const TYPE x) {
  return CGRAPH_TEST(DATA_ISPINF(COMPLEX_REAL(x)) ||
                     DATA_ISPINF(COMPLEX_IMAG(x)));
}

cgraph_bool_t FUNCTION(NAME, isninf)(const TYPE x) {
  return CGRAPH_TEST(DATA_ISNINF(COMPLEX_REAL(x)) ||
                     DATA_ISPINF(COMPLEX_IMAG(x)));
}

static const TYPE _cgraph_complex_zero = ZERO;

cgraph_bool_t FUNCTION(NAME, iszero)(const TYPE x) {
  return EQ(x, _cgraph_complex_zero);
}

static const TYPE _cgraph_complex_max = MAX;

cgraph_bool_t FUNCTION(NAME, ismax)(const TYPE x) {
  return EQ(x, _cgraph_complex_max);
}

static const TYPE _cgraph_complex_min = MIN;

cgraph_bool_t FUNCTION(NAME, ismin)(const TYPE x) {
  return EQ(x, _cgraph_complex_min);
}

/** functions of complex numbers with one complex number and one data types */
/**        one complex number and one real part of one complex number */
TYPE FUNCTION(NAME, addr)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) + y;
  * / COMPLEX_IMAG(res) = COMPLEX_IMAG(x);
  * /

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
  DATA_TYPE abs = pow(FUNCTION(NAME, abs)(x), y),
            angle = FUNCTION(NAME, angle)(x) * y;
  TYPE res;
  COMPLEX_REAL(res) = abs * cos(angle);
  COMPLEX_IMAG(res) = abs * sin(angle);

  return res;
}

/**        one complex number and one image part of one complex number */
TYPE FUNCTION(NAME, addi)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) + y;
  * /

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
  COMPLEX_REAL(res) = -1.0 * COMPLEX_IMAG(x) * y;
  COMPLEX_IMAG(res) = COMPLEX_REAL(x) * y;

  return res;
}

TYPE FUNCTION(NAME, divi)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_IMAG(x) / y;
  COMPLEX_IMAG(res) = -1.0 * COMPLEX_REAL(x) / y;

  return res;
}

TYPE FUNCTION(NAME, powi)(const TYPE x, const DATA_TYPE y) {
  TYPE res = FUNCTION(NAME, log)(x);
  res = FUNCTION(NAME, muli)(res, y);

  return FUNCTION(NAME, exp)(res);

  return res;
}

TYPE *FUNCTION(NAME, fft)(TYPE *x, const cgraph_size_t len) {
  cgraph_size_t i, j, k, times = cgraph_math_log2(len);
  for (i = 0, j = len / 2; i < (len - 2); i++) {
    cgraph_size_t k = len / 2;
    if (i < j) {
      SWAP(x[i], x[j]);
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
             xwn = FUNCTION(NAME, mul)(x[group2], wn);
        x[group2] = FUNCTION(NAME, sub)(x[k], xwn);
        x[k] = FUNCTION(NAME, add)(x[k], xwn);
      }
    }
  }
  return x;
}

TYPE *FUNCTION(NAME, ifft)(TYPE *x, const cgraph_size_t len) {
  cgraph_size_t i = 0;
  for (i = 0; i < len; i++) {
    x[i] = FUNCTION(NAME, conj)(x[i]);
  }
  x = FUNCTION(NAME, fft)(x, len);
  for (i = 0; i < len; i++) {
    x[i] = FUNCTION(NAME, conj)(x[i]);
  }
  for (i = 0; i < len; i++) {
    COMPLEX_REAL(x[i]) = COMPLEX_REAL(x[i]) / len;
    COMPLEX_IMAG(x[i]) = COMPLEX_IMAG(x[i]) / len;
  }

  return x;
}

#include "template_off.h"
