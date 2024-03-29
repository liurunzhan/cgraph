#include "cgraph_base.h"
#include "cgraph_float64.h"

/** object cgraph_complex_t header */
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
      hit = sscanf(cstr, IN_FMT_IMAG, &(COMPLEX_IMAG(res)));
      if (1 == hit) {
        COMPLEX_REAL(res) = DATA_ZERO;
      } else {
        _error = CGRAPH_TRUE;
      }
    } else if (1 == hit) {
      COMPLEX_IMAG(res) = DATA_ZERO;
    }
  }
  if (NULL != error) {
    *error = _error;
  }

  return res;
}

cgraph_size_t FUNCTION(NAME, fprint)(FILE *fp, const TYPE cthis) {
  cgraph_size_t len = 0;
  if (FUNCTION(NAME, isreal)(cthis)) {
    len = cgraph_file_fprintf(fp, OUT_FMT_REAL, COMPLEX_REAL(cthis));
  } else if (FUNCTION(NAME, isimag)(cthis)) {
    len = cgraph_file_fprintf(fp, OUT_FMT_IMAG, COMPLEX_IMAG(cthis));
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
  if (FUNCTION(NAME, isreal)(cthis)) {
    len = cgraph_file_snprintf(cbuf, size, OUT_FMT_REAL, COMPLEX_REAL(cthis));
  } else if (FUNCTION(NAME, isimag)(cthis)) {
    len = cgraph_file_snprintf(cbuf, size, OUT_FMT_IMAG, COMPLEX_IMAG(cthis));
  } else {
    len = cgraph_file_snprintf(cbuf, size, OUT_FMT, COMPLEX_REAL(cthis),
                               COMPLEX_IMAG(cthis));
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, hash)(const TYPE cthis) {
  cgraph_size_t hash = USIZE_C(142857);
  hash *= COMPLEX_REAL(cthis);
  hash += hash * COMPLEX_IMAG(cthis);

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (DATA_TEST(cthis)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

__INLINE__ cgraph_int_t FUNCTION(NAME, signbit)(const TYPE x) {
  return DATA_GT(0.0, COMPLEX_REAL(x)) + DATA_GT(0.0, COMPLEX_IMAG(x)) + 1;
}

/** initial function */
__INLINE__ TYPE FUNCTION(NAME, zero)(void) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_ZERO;
  COMPLEX_IMAG(res) = DATA_ZERO;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, one)(void) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_ONE;
  COMPLEX_IMAG(res) = DATA_ZERO;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, ones)(void) {
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

__INLINE__ TYPE FUNCTION(NAME, min)(void) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_MIN;
  COMPLEX_IMAG(res) = DATA_MIN;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, max)(void) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_MAX;
  COMPLEX_IMAG(res) = DATA_MAX;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, nan)(void) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_NAN;
  COMPLEX_IMAG(res) = DATA_NAN;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, inf)(void) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_INF;
  COMPLEX_IMAG(res) = DATA_INF;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, pinf)(void) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_PINF;
  COMPLEX_IMAG(res) = DATA_PINF;

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, ninf)(void) {
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
  const DATA_TYPE angle = DATA_ONE * M_TWOPI * i / n;
  TYPE res;
  COMPLEX_REAL(res) = cos(angle);
  COMPLEX_IMAG(res) = sin(angle);

  return res;
}

TYPE FUNCTION(NAME, unit_inv)(const cgraph_int_t n, const cgraph_int_t i) {
  const DATA_TYPE angle = DATA_ONE * M_TWOPI * i / n;
  TYPE res;
  COMPLEX_REAL(res) = cos(angle);
  COMPLEX_IMAG(res) = -sin(angle);

  return res;
}

TYPE FUNCTION(NAME, initcri)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, initcr)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = DATA_ZERO;

  return res;
}

TYPE FUNCTION(NAME, initci)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = DATA_ZERO;
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x);

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
#if __STDC_VERSION__ >= 199901L
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

DATA_TYPE FUNCTION(NAME, inagl)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, angle)(FUNCTION(NAME, div)(x, y));
}

DATA_TYPE FUNCTION(NAME, dist)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, mag)(FUNCTION(NAME, sub)(x, y));
}

DATA_TYPE FUNCTION(NAME, dmin)(const TYPE x) {
  return DATA_LT(COMPLEX_REAL(x), COMPLEX_IMAG(x)) ? COMPLEX_REAL(x)
                                                   : COMPLEX_IMAG(x);
}

DATA_TYPE FUNCTION(NAME, dmax)(const TYPE x) {
  return DATA_GT(COMPLEX_REAL(x), COMPLEX_IMAG(x)) ? COMPLEX_REAL(x)
                                                   : COMPLEX_IMAG(x);
}

DATA_TYPE FUNCTION(NAME, dsum)(const TYPE x) {
  return COMPLEX_REAL(x) + COMPLEX_IMAG(x);
}

TYPE FUNCTION(NAME, rev)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_IMAG(x);
  COMPLEX_IMAG(res) = COMPLEX_REAL(x);

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, trans)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_IMAG(x);
  COMPLEX_IMAG(res) = COMPLEX_REAL(x);

  return res;
}

TYPE FUNCTION(NAME, opp)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = -COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x);

  return res;
}

DATA_TYPE FUNCTION(NAME, fabs)(const TYPE x) { return FUNCTION(NAME, mag)(x); }

TYPE FUNCTION(NAME, abs)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = FUNCTION(NAME, mag)(x);
  COMPLEX_IMAG(res) = 0.0;

  return res;
}

TYPE FUNCTION(NAME, inv)(const TYPE x) {
  const DATA_TYPE mag2_inv = FUNCTION(NAME, mag2_inv)(x);
  TYPE res;
  COMPLEX_REAL(res) = mag2_inv * COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = -mag2_inv * COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, std)(const TYPE x) {
  const DATA_TYPE mag_inv = FUNCTION(NAME, mag_inv)(x);
  TYPE res;
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

TYPE FUNCTION(NAME, iconj)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = -COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x);

  return res;
}

/**
 * @brief power 2 function :
 * (a+ib)^2 = (a^2-b^2) + i2ab
 */
TYPE FUNCTION(NAME, pow2)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) =
      (COMPLEX_REAL(x) * COMPLEX_REAL(x)) - (COMPLEX_IMAG(x) * COMPLEX_IMAG(x));
  COMPLEX_IMAG(res) = 2.0 * COMPLEX_REAL(x) * COMPLEX_IMAG(x);

  return res;
}

/**
 * @brief power 3 function :
 *  (a+ib)^3 = a^3+i3a^2b-3ab^2-ib3 = a(a^2-3b^2) + ib(3a^2-b^2)
 */
TYPE FUNCTION(NAME, pow3)(const TYPE x) {
  DATA_TYPE real2 = COMPLEX_REAL(x) * COMPLEX_REAL(x),
            imag2 = COMPLEX_IMAG(x) * COMPLEX_IMAG(x);
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) * (real2 - 3.0 * imag2);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) * (3.0 * real2 - imag2);

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

TYPE FUNCTION(NAME, abssub)(const TYPE x, const TYPE y) {
  TYPE res = FUNCTION(NAME, sub)(x, y);
  COMPLEX_REAL(res) = FUNCTION(DATA_NAME, abs)(COMPLEX_REAL(res));
  COMPLEX_IMAG(res) = FUNCTION(DATA_NAME, abs)(COMPLEX_IMAG(res));

  return res;
}

TYPE FUNCTION(NAME, mul)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) =
      (COMPLEX_REAL(x) * COMPLEX_REAL(y)) - (COMPLEX_IMAG(x) * COMPLEX_IMAG(y));
  COMPLEX_IMAG(res) =
      (COMPLEX_REAL(x) * COMPLEX_IMAG(y)) + (COMPLEX_IMAG(x) * COMPLEX_REAL(y));

  return res;
}

TYPE FUNCTION(NAME, div)(const TYPE x, const TYPE y) {
  const DATA_TYPE mag2_inv = FUNCTION(NAME, mag2_inv)(y);
  TYPE res;
  COMPLEX_REAL(res) = mag2_inv * ((COMPLEX_REAL(x) * COMPLEX_REAL(y)) +
                                  (COMPLEX_IMAG(x) * COMPLEX_IMAG(y)));
  COMPLEX_IMAG(res) = mag2_inv * ((COMPLEX_IMAG(x) * COMPLEX_REAL(y)) -
                                  (COMPLEX_REAL(x) * COMPLEX_IMAG(y)));

  return res;
}

TYPE FUNCTION(NAME, dot)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, mul)(x, FUNCTION(NAME, conj)(y));
}

TYPE FUNCTION(NAME, dotconj)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, mul)(FUNCTION(NAME, conj)(x), y);
}

TYPE FUNCTION(NAME, oxads)(const TYPE x) {
  return FUNCTION(NAME, div)(FUNCTION(NAME, rxadd)(DATA_ONE, x),
                             FUNCTION(NAME, rxsub)(DATA_ONE, x));
}

TYPE FUNCTION(NAME, adsxo)(const TYPE x) {
  return FUNCTION(NAME, div)(FUNCTION(NAME, addr)(x, DATA_ONE),
                             FUNCTION(NAME, subr)(x, DATA_ONE));
}

TYPE FUNCTION(NAME, rdadd)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) + COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, rdsub)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) - COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, rdmul)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) * COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, rddiv)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) / COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, rdmod)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) =
      FUNCTION(DATA_NAME, mod)(COMPLEX_REAL(x), COMPLEX_REAL(y));
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, rdpow)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) =
      FUNCTION(DATA_NAME, pow)(COMPLEX_REAL(x), COMPLEX_REAL(y));
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x);

  return res;
}

TYPE FUNCTION(NAME, idadd)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) + COMPLEX_IMAG(y);

  return res;
}

TYPE FUNCTION(NAME, idsub)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) - COMPLEX_IMAG(y);

  return res;
}

TYPE FUNCTION(NAME, idmul)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) * COMPLEX_IMAG(y);

  return res;
}

TYPE FUNCTION(NAME, iddiv)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) / COMPLEX_IMAG(y);

  return res;
}

TYPE FUNCTION(NAME, idmod)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x);
  COMPLEX_IMAG(res) =
      FUNCTION(DATA_NAME, mod)(COMPLEX_IMAG(x), COMPLEX_IMAG(y));

  return res;
}

TYPE FUNCTION(NAME, idpow)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x);
  COMPLEX_IMAG(res) =
      FUNCTION(DATA_NAME, pow)(COMPLEX_IMAG(x), COMPLEX_IMAG(y));

  return res;
}

TYPE FUNCTION(NAME, dmul)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) * COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) * COMPLEX_IMAG(y);

  return res;
}

TYPE FUNCTION(NAME, ddiv)(const TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) / COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) / COMPLEX_IMAG(y);

  return res;
}

TYPE FUNCTION(NAME, log)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = log(FUNCTION(NAME, mag)(x));
  COMPLEX_IMAG(res) = FUNCTION(NAME, angle)(x);

  return res;
}

TYPE FUNCTION(NAME, log2)(const TYPE x) {
  TYPE res = FUNCTION(NAME, log)(x);
  COMPLEX_REAL(res) = COMPLEX_REAL(res) / M_LN2;
  COMPLEX_IMAG(res) = COMPLEX_IMAG(res) / M_LN2;

  return res;
}

TYPE FUNCTION(NAME, log10)(const TYPE x) {
  TYPE res = FUNCTION(NAME, log)(x);
  COMPLEX_REAL(res) = M_IVLN10 * COMPLEX_REAL(res);
  COMPLEX_IMAG(res) = M_IVLN10 * COMPLEX_IMAG(res);

  return res;
}

TYPE FUNCTION(NAME, exp)(const TYPE x) {
  const DATA_TYPE mag = exp(COMPLEX_REAL(x));
  TYPE res;
  COMPLEX_REAL(res) = mag * cos(COMPLEX_IMAG(x));
  COMPLEX_IMAG(res) = mag * sin(COMPLEX_IMAG(x));

  return res;
}

TYPE FUNCTION(NAME, sqrt)(const TYPE x) {
  const DATA_TYPE mag = sqrt(FUNCTION(NAME, mag)(x)),
                  angle = 0.5 * FUNCTION(NAME, angle)(x);
  TYPE res;
  COMPLEX_REAL(res) = mag * cos(angle);
  COMPLEX_IMAG(res) = mag * sin(angle);

  return res;
}

TYPE FUNCTION(NAME, pow)(const TYPE x, const TYPE y) {
  TYPE res = FUNCTION(NAME, log)(x);

  return FUNCTION(NAME, exp)(FUNCTION(NAME, mul)(y, res));
}

TYPE FUNCTION(NAME, int)(const TYPE x) {
  TYPE res;
  COMPLEX_REAL(res) = FUNCTION(DATA_NAME, int)(COMPLEX_REAL(x));
  COMPLEX_IMAG(res) = FUNCTION(DATA_NAME, int)(COMPLEX_IMAG(x));

  return res;
}

TYPE FUNCTION(NAME, mod)(const TYPE x, const TYPE y) {
  TYPE res = FUNCTION(NAME, div)(x, y);
  COMPLEX_REAL(res) = COMPLEX_REAL(x) - COMPLEX_REAL(y) * COMPLEX_REAL(res);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) - COMPLEX_IMAG(y) * COMPLEX_REAL(res);

  return res;
}

TYPE FUNCTION(NAME, mean)(const TYPE x, const TYPE y) {
  TYPE res = FUNCTION(NAME, add)(x, y);
  COMPLEX_REAL(res) = 0.5 * COMPLEX_REAL(res);
  COMPLEX_IMAG(res) = 0.5 * COMPLEX_IMAG(res);

  return res;
}

/** hmean(x, y) = 1/(1/x+1/y) = (xy)/(x+y) */
TYPE FUNCTION(NAME, hmean)(const TYPE x, const TYPE y) {
  TYPE mul = FUNCTION(NAME, mul)(x, y);
  TYPE sum = FUNCTION(NAME, add)(x, y);

  return FUNCTION(NAME, div)(mul, sum);
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
  return FUNCTION(NAME, div)(FUNCTION(NAME, sin)(x), FUNCTION(NAME, cos)(x));
}

TYPE FUNCTION(NAME, cot)(const TYPE x) {
  return FUNCTION(NAME, div)(FUNCTION(NAME, cos)(x), FUNCTION(NAME, sin)(x));
}

TYPE FUNCTION(NAME, sec)(const TYPE x) {
  return FUNCTION(NAME, inv)(FUNCTION(NAME, cos)(x));
}

TYPE FUNCTION(NAME, csc)(const TYPE x) {
  return FUNCTION(NAME, inv)(FUNCTION(NAME, sin)(x));
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
  return FUNCTION(NAME, div)(FUNCTION(NAME, sinh)(x), FUNCTION(NAME, cosh)(x));
}

TYPE FUNCTION(NAME, coth)(const TYPE x) {
  return FUNCTION(NAME, div)(FUNCTION(NAME, cosh)(x), FUNCTION(NAME, sinh)(x));
}

TYPE FUNCTION(NAME, sech)(const TYPE x) {
  return FUNCTION(NAME, inv)(FUNCTION(NAME, cosh)(x));
}

TYPE FUNCTION(NAME, csch)(const TYPE x) {
  return FUNCTION(NAME, inv)(FUNCTION(NAME, sinh)(x));
}

TYPE FUNCTION(NAME, asin)(const TYPE x) {
  TYPE x2 = FUNCTION(NAME, mul)(x, x), ix = FUNCTION(NAME, mul1i)(x);
  TYPE x2_1 = FUNCTION(NAME, subr)(x2, DATA_ONE),
       s_1_x2 = FUNCTION(NAME, sqrt)(FUNCTION(NAME, opp)(x2_1)),
       ix_s_1_x2 = FUNCTION(NAME, add)(ix, s_1_x2);
  TYPE ln_ix_s_1_x2 = FUNCTION(NAME, log)(ix_s_1_x2);
  TYPE res;
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
  COMPLEX_REAL(res) = 0.5 * (M_PI + COMPLEX_IMAG(log_log));
  COMPLEX_IMAG(res) = -0.5 * COMPLEX_REAL(log_log);

  return res;
}

TYPE FUNCTION(NAME, asinh)(const TYPE x) {
  return FUNCTION(NAME, log)(
      FUNCTION(NAME, add)(x, FUNCTION(NAME, sqrt)(FUNCTION(NAME, addr)(
                                 FUNCTION(NAME, pow2)(x), DATA_ONE))));
}

TYPE FUNCTION(NAME, acosh)(const TYPE x) {
  return FUNCTION(NAME, log)(
      FUNCTION(NAME, add)(x, FUNCTION(NAME, sqrt)(FUNCTION(NAME, subr)(
                                 FUNCTION(NAME, pow2)(x), DATA_ONE))));
}

TYPE FUNCTION(NAME, atanh)(const TYPE x) {
  return FUNCTION(NAME, mulr)(FUNCTION(NAME, log)(FUNCTION(NAME, oxads)(x)),
                              0.5);
}

TYPE FUNCTION(NAME, acoth)(const TYPE x) {
  return FUNCTION(NAME, mulr)(FUNCTION(NAME, log)(FUNCTION(NAME, adsxo)(x)),
                              0.5);
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, isreal)(const TYPE x) {
  return CGRAPH_TEST(DATA_EQ(COMPLEX_IMAG(x), 0.0));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, isimag)(const TYPE x) {
  return CGRAPH_TEST(DATA_EQ(COMPLEX_REAL(x), 0.0));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, ispos)(const TYPE x) {
  return CGRAPH_TEST(DATA_ISPOS(x));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, isneg)(const TYPE x) {
  return CGRAPH_TEST(DATA_ISNEG(x));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, iszero)(const TYPE x) {
  return EQ(x, ZERO);
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

__INLINE__ cgraph_bool_t FUNCTION(NAME, mgt)(const TYPE x, const TYPE y) {
  DATA_TYPE mag_x = FUNCTION(NAME, mag)(x), mag_y = FUNCTION(NAME, mag)(y);

  if (DATA_GT(mag_x, mag_y) ||
      (DATA_EQ(mag_x, mag_y) &&
       (DATA_GT(COMPLEX_REAL(x), COMPLEX_REAL(y)) ||
        (DATA_EQ(COMPLEX_REAL(x), COMPLEX_REAL(y)) &&
         DATA_GT(COMPLEX_IMAG(x), COMPLEX_IMAG(y)))))) {
    return CGRAPH_TRUE;
  }

  return CGRAPH_FALSE;
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, mge)(const TYPE x, const TYPE y) {
  DATA_TYPE mag_x = FUNCTION(NAME, mag)(x), mag_y = FUNCTION(NAME, mag)(y);

  if (DATA_GT(mag_x, mag_y) ||
      (DATA_EQ(mag_x, mag_y) &&
       (DATA_GT(COMPLEX_REAL(x), COMPLEX_REAL(y)) ||
        (DATA_EQ(COMPLEX_REAL(x), COMPLEX_REAL(y)) &&
         DATA_GE(COMPLEX_IMAG(x), COMPLEX_IMAG(y)))))) {
    return CGRAPH_TRUE;
  }

  return CGRAPH_FALSE;
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, mlt)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, mgt)(y, x);
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, mle)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, mge)(y, x);
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, dgt)(const TYPE x, const TYPE y) {
  return CGRAPH_TEST(DATA_GT(COMPLEX_REAL(x), COMPLEX_IMAG(x)) ||
                     (DATA_GT(COMPLEX_IMAG(x), COMPLEX_IMAG(y))));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, dge)(const TYPE x, const TYPE y) {
  return CGRAPH_TEST(DATA_GE(COMPLEX_REAL(x), COMPLEX_IMAG(x)) ||
                     (DATA_GE(COMPLEX_IMAG(x), COMPLEX_IMAG(y))));
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, dlt)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, dgt)(y, x);
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, dle)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, dge)(y, x);
}

__INLINE__ cgraph_bool_t FUNCTION(NAME, gt)(const TYPE x, const TYPE y) {
  return GT(x, y);
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
  const DATA_TYPE y_inv = DATA_ONE / y;
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(x) * y_inv;
  COMPLEX_IMAG(res) = COMPLEX_IMAG(x) * y_inv;

  return res;
}

TYPE FUNCTION(NAME, powr)(const TYPE x, const DATA_TYPE y) {
  const DATA_TYPE mag = pow(FUNCTION(NAME, mag)(x), y),
                  angle = FUNCTION(NAME, angle)(x) * y;
  TYPE res;
  COMPLEX_REAL(res) = mag * cos(angle);
  COMPLEX_IMAG(res) = mag * sin(angle);

  return res;
}

TYPE FUNCTION(NAME, rxadd)(const DATA_TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = x + COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = COMPLEX_IMAG(y);

  return res;
}

TYPE FUNCTION(NAME, rxsub)(const DATA_TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = x - COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = -COMPLEX_IMAG(y);

  return res;
}

TYPE FUNCTION(NAME, rxmul)(const DATA_TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = x * COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = x * COMPLEX_IMAG(y);

  return res;
}

TYPE FUNCTION(NAME, rxdiv)(const DATA_TYPE x, const TYPE y) {
  const DATA_TYPE x_inv = DATA_ONE / x;
  TYPE res;
  COMPLEX_REAL(res) = x_inv * COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = x_inv * COMPLEX_IMAG(y);

  return res;
}

TYPE FUNCTION(NAME, rxmod)(const DATA_TYPE x, const TYPE y) {
  TYPE res;

  return res;
}

TYPE FUNCTION(NAME, rxpow)(const DATA_TYPE x, const TYPE y) {
  TYPE res;

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
  const DATA_TYPE y_inv = DATA_ONE / y;
  TYPE res;
  COMPLEX_REAL(res) = y_inv * COMPLEX_IMAG(x);
  COMPLEX_IMAG(res) = -y_inv * COMPLEX_REAL(x);

  return res;
}

TYPE FUNCTION(NAME, powi)(const TYPE x, const DATA_TYPE y) {
  return FUNCTION(NAME, exp)(FUNCTION(NAME, muli)(FUNCTION(NAME, log)(x), y));
}

TYPE FUNCTION(NAME, ixadd)(const DATA_TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = x + COMPLEX_IMAG(y);

  return res;
}

TYPE FUNCTION(NAME, ixsub)(const DATA_TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = -COMPLEX_REAL(y);
  COMPLEX_IMAG(res) = x - COMPLEX_IMAG(y);

  return res;
}

TYPE FUNCTION(NAME, ixmul)(const DATA_TYPE x, const TYPE y) {
  TYPE res;
  COMPLEX_REAL(res) = -x * COMPLEX_IMAG(y);
  COMPLEX_IMAG(res) = x * COMPLEX_REAL(y);

  return res;
}

TYPE FUNCTION(NAME, ixdiv)(const DATA_TYPE x, const TYPE y) {
  const DATA_TYPE x_inv = DATA_ONE / x;
  TYPE res;
  COMPLEX_REAL(res) = x_inv * COMPLEX_IMAG(y);
  COMPLEX_IMAG(res) = -x_inv * COMPLEX_REAL(y);

  return res;
}

TYPE FUNCTION(NAME, ixmod)(const DATA_TYPE x, const TYPE y) {
  TYPE res;

  return res;
}

TYPE FUNCTION(NAME, ixpow)(const DATA_TYPE x, const TYPE y) {
  TYPE res;

  return res;
}

/** @brief Fast Fourier Transform (fft) */
TYPE *FUNCTION(NAME, fft)(TYPE *cthis, const cgraph_size_t len) {
  if ((NULL != cthis) && (0 < len) && (0 == (len & 0x01))) {
    cgraph_size_t i, j, k, times = cgraph_math_log2i(len);
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
      cgraph_size_t group0 = cgraph_math_pow2i(i), group1 = group0 / 2;
      for (j = 0; j < group1; j++) {
        cgraph_size_t n = j * cgraph_math_pow2i(len - times);
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
    CGRAPH_LOOP(i, 0, len)
    cthis[i] = FUNCTION(NAME, conj)(cthis[i]);
    CGRAPH_LOOP_END
    cthis = FUNCTION(NAME, fft)(cthis, len);
    CGRAPH_LOOP(i, 0, len)
    cthis[i] = FUNCTION(NAME, conj)(cthis[i]);
    CGRAPH_LOOP_END
    CGRAPH_LOOP(i, 0, len)
    cthis[i] = FUNCTION(NAME, divr)(cthis[i], len);
    CGRAPH_LOOP_END
  }

  return cthis;
}
