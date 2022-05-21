#include "cgraph_base.h"
#include "cgraph_float64.h"

/** object cgraph_point2d_t header */
#include "cgraph_point2d.h"

/** template module */
#include "template_point.ct"

cgraph_size_t FUNCTION(NAME, fprint)(FILE *fp, const TYPE cthis) {
  return cgraph_file_fprintf(fp, OUT_FMT, POINT2D_X(cthis), POINT2D_Y(cthis));
}

cgraph_size_t FUNCTION(NAME, hash)(const TYPE cthis) {
  cgraph_size_t hash = 58979323UL;
  hash *= POINT2D_X(cthis);
  hash += hash * POINT2D_Y(cthis);

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE cthis) {
  return CGRAPH_NTEST(DATA_ISNAN(cthis));
}

__INLINE cgraph_int_t FUNCTION(NAME, signbit)(const TYPE x) {
  return DATA_GR(0.0, POINT2D_X(x)) + DATA_GR(0.0, POINT2D_Y(x)) + 1;
}

cgraph_bool_t FUNCTION(NAME, iszero)(const TYPE cthis) {
  return CGRAPH_TEST(DATA_EQ(0.0, POINT2D_X(cthis)) &&
                     DATA_EQ(0.0, POINT2D_Y(cthis)));
}

DATA_TYPE FUNCTION(NAME, mag2)(const TYPE x) { return POINT2D_MAG2(x); }

DATA_TYPE FUNCTION(NAME, mag2_inv)(const TYPE x) {
  return DATA_ONE / POINT2D_MAG2(x);
}

DATA_TYPE FUNCTION(NAME, mag)(const TYPE x) {
#if __STDC_VERSION__ >= 199901L
  return hypot(POINT2D_X(x), POINT2D_Y(x));
#else
  return sqrt(POINT2D_MAG2(x));
#endif
}

DATA_TYPE FUNCTION(NAME, mag_inv)(const TYPE x) {
  return DATA_ONE / FUNCTION(NAME, mag)(x);
}

DATA_TYPE FUNCTION(NAME, angle)(const TYPE x) {
  return FUNCTION(NAME, xangle)(x);
}

DATA_TYPE FUNCTION(NAME, xangle)(const TYPE x) {
  return atan2(POINT2D_Y(x), POINT2D_X(x));
}

DATA_TYPE FUNCTION(NAME, yangle)(const TYPE x) {
  return atan2(POINT2D_X(x), POINT2D_Y(x));
}

TYPE FUNCTION(NAME, zero)(void) {
  TYPE res;
  POINT2D_X(res) = DATA_ZERO;
  POINT2D_Y(res) = DATA_ZERO;

  return res;
}

TYPE FUNCTION(NAME, one)(void) {
  TYPE res;
  POINT2D_X(res) = DATA_ONE;
  POINT2D_Y(res) = DATA_ZERO;

  return res;
}

TYPE FUNCTION(NAME, ones)(void) {
  TYPE res;
  POINT2D_X(res) = DATA_ONE;
  POINT2D_Y(res) = DATA_ONE;

  return res;
}

TYPE FUNCTION(NAME, rand)(void) {
  TYPE res;
  POINT2D_X(res) = FUNCTION(DATA_NAME, rand)();
  POINT2D_Y(res) = FUNCTION(DATA_NAME, rand)();

  return res;
}

TYPE FUNCTION(NAME, min)(void) {
  TYPE res;
  POINT2D_X(res) = DATA_MIN;
  POINT2D_Y(res) = DATA_MIN;

  return res;
}

TYPE FUNCTION(NAME, max)(void) {
  TYPE res;
  POINT2D_X(res) = DATA_MAX;
  POINT2D_Y(res) = DATA_MAX;

  return res;
}

TYPE FUNCTION(NAME, nan)(void) {
  TYPE res;
  POINT2D_X(res) = DATA_NAN;
  POINT2D_Y(res) = DATA_NAN;

  return res;
}

TYPE FUNCTION(NAME, inf)(void) {
  TYPE res;
  POINT2D_X(res) = DATA_INF;
  POINT2D_Y(res) = DATA_INF;

  return res;
}

TYPE FUNCTION(NAME, pinf)(void) {
  TYPE res;
  POINT2D_X(res) = DATA_PINF;
  POINT2D_Y(res) = DATA_PINF;

  return res;
}

TYPE FUNCTION(NAME, ninf)(void) {
  TYPE res;
  POINT2D_X(res) = DATA_NINF;
  POINT2D_Y(res) = DATA_NINF;

  return res;
}

TYPE FUNCTION(NAME, trans)(const TYPE x) {
  TYPE res;
  POINT2D_X(res) = POINT2D_Y(x);
  POINT2D_Y(res) = POINT2D_X(x);

  return res;
}

TYPE FUNCTION(NAME, opp)(const TYPE x) {
  TYPE res;
  POINT2D_X(res) = -POINT2D_X(x);
  POINT2D_Y(res) = -POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, inv)(const TYPE x) {
  DATA_TYPE mag2_inv = FUNCTION(NAME, mag2_inv)(x);
  TYPE res;
  POINT2D_X(res) = mag2_inv * POINT2D_X(x);
  POINT2D_Y(res) = mag2_inv * POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, std)(const TYPE x) {
  DATA_TYPE mag_inv = FUNCTION(NAME, mag_inv)(x);
  TYPE res;
  POINT2D_X(res) = mag_inv * POINT2D_X(x);
  POINT2D_Y(res) = mag_inv * POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, add)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) + POINT2D_X(y);
  POINT2D_Y(res) = POINT2D_Y(x) + POINT2D_Y(y);

  return res;
}

TYPE FUNCTION(NAME, sub)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) - POINT2D_X(y);
  POINT2D_Y(res) = POINT2D_Y(x) - POINT2D_Y(y);

  return res;
}

/* x (x) y = [x1, y1] x [x2, y2] = [ [x1 y1], [x2 y2] ] = x1*y2 - x2*y1 */
TYPE FUNCTION(NAME, mul)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = FUNCTION(NAME, fmul)(x, y);
  POINT2D_Y(res) = DATA_ZERO;

  return res;
}

DATA_TYPE FUNCTION(NAME, fmul)(const TYPE x, const TYPE y) {
  return (POINT2D_X(x) * POINT2D_Y(y)) - (POINT2D_X(y) * POINT2D_Y(x));
}

TYPE FUNCTION(NAME, dot)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = FUNCTION(NAME, fdot)(x, y);
  POINT2D_Y(res) = DATA_ZERO;

  return res;
}

__INLINE DATA_TYPE FUNCTION(NAME, fdot)(const TYPE x, const TYPE y) {
  return (POINT2D_X(x) * POINT2D_X(y)) + (POINT2D_Y(x) * POINT2D_Y(y));
}

TYPE FUNCTION(NAME, div)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) / POINT2D_X(y);
  POINT2D_Y(res) = POINT2D_Y(x) / POINT2D_Y(y);

  return res;
}

TYPE FUNCTION(NAME, addf)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) + y;
  POINT2D_Y(res) = POINT2D_Y(x) + y;

  return res;
}

TYPE FUNCTION(NAME, subf)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) - y;
  POINT2D_Y(res) = POINT2D_Y(x) - y;

  return res;
}

TYPE FUNCTION(NAME, mulf)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) * y;
  POINT2D_Y(res) = POINT2D_Y(x) * y;

  return res;
}

TYPE FUNCTION(NAME, divf)(const TYPE x, const DATA_TYPE y) {
  DATA_TYPE inv_y = 1.0 / y;
  TYPE res;
  POINT2D_X(res) = inv_y * POINT2D_X(x);
  POINT2D_Y(res) = inv_y * POINT2D_Y(x);

  return res;
}

/* res = [[cosy -siny], [siny cosy]] x */
TYPE FUNCTION(NAME, rol)(const TYPE x, const DATA_TYPE angle) {
  DATA_TYPE sin_angle = sin(angle), cos_angle = cos(angle);
  TYPE res;
  POINT2D_X(res) = cos_angle * POINT2D_X(x) - sin_angle * POINT2D_Y(x);
  POINT2D_Y(res) = sin_angle * POINT2D_X(x) + cos_angle * POINT2D_Y(x);

  return res;
}

/* res = [[cosy -siny], [siny cosy]] x */
TYPE FUNCTION(NAME, ror)(const TYPE x, const DATA_TYPE angle) {
  return FUNCTION(NAME, rol)(x, -angle);
}

cgraph_bool_t FUNCTION(NAME, istriangle)(const TYPE a, const TYPE b,
                                         const TYPE c) {
  DATA_TYPE mul0 =
                (POINT2D_X(b) - POINT2D_X(a)) * (POINT2D_Y(c) - POINT2D_Y(a)),
            mul1 =
                (POINT2D_X(c) - POINT2D_X(a)) * (POINT2D_Y(b) - POINT2D_Y(a));

  return DATA_NE(mul0, mul1);
}

/* three point concurrent fofmula (x2-x1)(y3-y1)=(x3-x1)(y2-y1) */
cgraph_bool_t FUNCTION(NAME, isconcurrent)(const TYPE a, const TYPE b,
                                           const TYPE c) {
  DATA_TYPE mul0 =
                (POINT2D_X(b) - POINT2D_X(a)) * (POINT2D_Y(c) - POINT2D_Y(a)),
            mul1 =
                (POINT2D_X(c) - POINT2D_X(a)) * (POINT2D_Y(b) - POINT2D_Y(a));

  return DATA_EQ(mul0, mul1);
}

cgraph_bool_t FUNCTION(NAME, iscoplanar)(const TYPE a, const TYPE b,
                                         const TYPE c) {
  return CGRAPH_TRUE;
}

/* triangle size fofmula S = 0.5 * |(x2-x1)(y3-y1)-(x3-x1)(y2-y1)| */
DATA_TYPE FUNCTION(NAME, triangle_size)(const TYPE a, const TYPE b,
                                        const TYPE c) {
  DATA_TYPE mul0 =
                (POINT2D_X(b) - POINT2D_X(a)) * (POINT2D_Y(c) - POINT2D_Y(a)),
            mul1 =
                (POINT2D_X(c) - POINT2D_X(a)) * (POINT2D_Y(b) - POINT2D_Y(a));

  return 0.5 * fabs(mul0 - mul1);
}

TYPE FUNCTION(NAME, triangle_gcenter)(const TYPE a, const TYPE b,
                                      const TYPE c) {
  TYPE res = FUNCTION(NAME, add)(FUNCTION(NAME, add)(a, b), c);

  return FUNCTION(NAME, divf)(res, 3.0);
}