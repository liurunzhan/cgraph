#include "cgraph_base.h"
#include "cgraph_float64.h"

/** object cgraph_point3d_t header */
#include "cgraph_point3d.h"

/** template module */
#include "template_point.ct"

cgraph_size_t FUNCTION(NAME, fprint)(FILE *fp, const TYPE cthis) {
  return cgraph_file_fprintf(fp, OUT_FMT, POINT3D_X(cthis), POINT3D_Y(cthis),
                             POINT3D_Z(cthis));
}

cgraph_size_t FUNCTION(NAME, hash)(const TYPE cthis) {
  cgraph_size_t hash = 314159UL;
  hash *= POINT3D_X(cthis);
  hash += hash * POINT3D_Y(cthis);
  hash += hash * POINT3D_Z(cthis);

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE cthis) {
  return CGRAPH_NTEST(DATA_ISNAN(cthis));
}

__INLINE cgraph_int_t FUNCTION(NAME, signbit)(const TYPE x) {
  return DATA_GR(0.0, POINT3D_X(x)) + DATA_GR(0.0, POINT3D_Y(x)) + 1;
}

cgraph_bool_t FUNCTION(NAME, iszero)(const TYPE cthis) {
  return CGRAPH_TEST(DATA_EQ(0.0, POINT3D_X(cthis)) &&
                     DATA_EQ(0.0, POINT3D_Y(cthis)) &&
                     DATA_EQ(0.0, POINT3D_Z(cthis)));
}

DATA_TYPE FUNCTION(NAME, mag2)(const TYPE x) { return POINT3D_MAG2(x); }

DATA_TYPE FUNCTION(NAME, mag2_inv)(const TYPE x) {
  return DATA_ONE / POINT3D_MAG2(x);
}

DATA_TYPE FUNCTION(NAME, mag)(const TYPE x) { return sqrt(POINT3D_MAG2(x)); }

DATA_TYPE FUNCTION(NAME, mag_inv)(const TYPE x) {
  return DATA_ONE / FUNCTION(NAME, mag)(x);
}

DATA_TYPE FUNCTION(NAME, angle)(const TYPE x) {
  return FUNCTION(NAME, xangle)(x);
}

DATA_TYPE FUNCTION(NAME, xangle)(const TYPE x) {
  return acos(POINT3D_X(x) / FUNCTION(NAME, mag)(x));
}

DATA_TYPE FUNCTION(NAME, yangle)(const TYPE x) {
  return acos(POINT3D_Y(x) / FUNCTION(NAME, mag)(x));
}

DATA_TYPE FUNCTION(NAME, zangle)(const TYPE x) {
  return acos(POINT3D_Z(x) / FUNCTION(NAME, mag)(x));
}

TYPE FUNCTION(NAME, zero)(void) {
  TYPE res;
  POINT3D_X(res) = DATA_ZERO;
  POINT3D_Y(res) = DATA_ZERO;
  POINT3D_Z(res) = DATA_ZERO;

  return res;
}

TYPE FUNCTION(NAME, one)(void) {
  TYPE res;
  POINT3D_X(res) = DATA_ONE;
  POINT3D_Y(res) = DATA_ZERO;
  POINT3D_Z(res) = DATA_ZERO;

  return res;
}

TYPE FUNCTION(NAME, ones)(void) {
  TYPE res;
  POINT3D_X(res) = DATA_ONE;
  POINT3D_Y(res) = DATA_ONE;
  POINT3D_Z(res) = DATA_ONE;

  return res;
}

TYPE FUNCTION(NAME, rand)(void) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, rand)();
  POINT3D_Y(res) = FUNCTION(DATA_NAME, rand)();
  POINT3D_Z(res) = FUNCTION(DATA_NAME, rand)();

  return res;
}

TYPE FUNCTION(NAME, min)(void) {
  TYPE res;
  POINT3D_X(res) = DATA_MIN;
  POINT3D_Y(res) = DATA_MIN;
  POINT3D_Z(res) = DATA_MIN;

  return res;
}

TYPE FUNCTION(NAME, max)(void) {
  TYPE res;
  POINT3D_X(res) = DATA_MAX;
  POINT3D_Y(res) = DATA_MAX;
  POINT3D_Z(res) = DATA_MAX;

  return res;
}

TYPE FUNCTION(NAME, nan)(void) {
  TYPE res;
  POINT3D_X(res) = DATA_NAN;
  POINT3D_Y(res) = DATA_NAN;
  POINT3D_Z(res) = DATA_NAN;

  return res;
}

TYPE FUNCTION(NAME, inf)(void) {
  TYPE res;
  POINT3D_X(res) = DATA_INF;
  POINT3D_Y(res) = DATA_INF;
  POINT3D_Z(res) = DATA_INF;

  return res;
}

TYPE FUNCTION(NAME, pinf)(void) {
  TYPE res;
  POINT3D_X(res) = DATA_PINF;
  POINT3D_Y(res) = DATA_PINF;
  POINT3D_Z(res) = DATA_PINF;

  return res;
}

TYPE FUNCTION(NAME, ninf)(void) {
  TYPE res;
  POINT3D_X(res) = DATA_NINF;
  POINT3D_Y(res) = DATA_NINF;
  POINT3D_Z(res) = DATA_NINF;

  return res;
}

TYPE FUNCTION(NAME, trans)(const TYPE x) {
  TYPE res;
  POINT3D_X(res) = POINT3D_Z(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_X(x);

  return res;
}

TYPE FUNCTION(NAME, opp)(const TYPE x) {
  TYPE res;
  POINT3D_X(res) = -POINT3D_X(x);
  POINT3D_Y(res) = -POINT3D_Y(x);
  POINT3D_Z(res) = -POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, inv)(const TYPE x) {
  DATA_TYPE mag2_inv = FUNCTION(NAME, mag2_inv)(x);
  TYPE res;
  POINT3D_X(res) = mag2_inv * POINT3D_X(x);
  POINT3D_Y(res) = mag2_inv * POINT3D_Y(x);
  POINT3D_Z(res) = mag2_inv * POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, std)(const TYPE x) {
  DATA_TYPE mag_inv = FUNCTION(NAME, mag_inv)(x);
  TYPE res;
  POINT3D_X(res) = mag_inv * POINT3D_X(x);
  POINT3D_Y(res) = mag_inv * POINT3D_Y(x);
  POINT3D_Z(res) = mag_inv * POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, add)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) + POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x) + POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x) + POINT3D_Z(y);

  return res;
}

TYPE FUNCTION(NAME, sub)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) - POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x) - POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x) - POINT3D_Z(y);

  return res;
}

/**
 * x (x) y = [x1, y1, z1] x [x2, y2, z2] =
 * [ [i, j, k], [x1, y1, z1], [x2, y2, z2] ] =
 * i(y1*z2-y2*z1) - j(x1*z2-x2*z1) + k(x1*y2-x2*y1)
 */
TYPE FUNCTION(NAME, mul)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) =
      (POINT3D_Y(x) * POINT3D_Z(y)) - (POINT3D_Y(y) * POINT3D_Z(x));
  POINT3D_Y(res) =
      -(POINT3D_X(x) * POINT3D_Z(y)) + (POINT3D_X(y) * POINT3D_Z(x));
  POINT3D_Z(res) =
      (POINT3D_X(x) * POINT3D_Y(y)) - (POINT3D_X(y) * POINT3D_Y(x));

  return res;
}

DATA_TYPE FUNCTION(NAME, fmul)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, mag)(FUNCTION(NAME, mul)(x, y));
}

TYPE FUNCTION(NAME, dot)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(NAME, fdot)(x, y);
  POINT3D_Y(res) = DATA_ZERO;
  POINT3D_Z(res) = DATA_ZERO;

  return res;
}

__INLINE DATA_TYPE FUNCTION(NAME, fdot)(const TYPE x, const TYPE y) {
  return (POINT3D_X(x) * POINT3D_X(y)) + (POINT3D_Y(x) * POINT3D_Y(y)) +
         (POINT3D_Z(x) * POINT3D_Z(y));
}

TYPE FUNCTION(NAME, div)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) / POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x) / POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x) / POINT3D_Z(y);

  return res;
}

TYPE FUNCTION(NAME, addf)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) + y;
  POINT3D_Y(res) = POINT3D_Y(x) + y;
  POINT3D_Z(res) = POINT3D_Z(x) + y;

  return res;
}

TYPE FUNCTION(NAME, subf)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) - y;
  POINT3D_Y(res) = POINT3D_Y(x) - y;
  POINT3D_Z(res) = POINT3D_Z(x) - y;

  return res;
}

TYPE FUNCTION(NAME, mulf)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) * y;
  POINT3D_Y(res) = POINT3D_Y(x) * y;
  POINT3D_Z(res) = POINT3D_Z(x) * y;

  return res;
}

TYPE FUNCTION(NAME, divf)(const TYPE x, const DATA_TYPE y) {
  DATA_TYPE inv_y = 1.0 / y;
  TYPE res;
  POINT3D_X(res) = inv_y * POINT3D_X(x);
  POINT3D_Y(res) = inv_y * POINT3D_Y(x);
  POINT3D_Z(res) = inv_y * POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, ror)(const TYPE x, const DATA_TYPE angle) {
  return FUNCTION(NAME, xror)(x, angle);
}

TYPE FUNCTION(NAME, rol)(const TYPE x, const DATA_TYPE angle) {
  return FUNCTION(NAME, xrol)(x, angle);
}

/* res = [[1, 0, 0], [0, cosy, -siny], [0, siny, cosy]] x */
TYPE FUNCTION(NAME, xrol)(const TYPE x, const DATA_TYPE angle) {
  DATA_TYPE cos_angle = cos(angle), sin_angle = sin(angle);
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = cos_angle * POINT3D_Y(x) - sin_angle * POINT3D_Z(x);
  POINT3D_Z(res) = sin_angle * POINT3D_Y(x) + cos_angle * POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, xror)(const TYPE x, const DATA_TYPE angle) {
  return FUNCTION(NAME, xrol)(x, -angle);
}

/* res = [[cosy, 0, siny], [0, 1, 0], [-siny, 0, cosy]] x */
TYPE FUNCTION(NAME, yrol)(const TYPE x, const DATA_TYPE angle) {
  DATA_TYPE cos_angle = cos(angle), sin_angle = sin(angle);
  TYPE res;
  POINT3D_X(res) = cos_angle * POINT3D_X(x) + sin_angle * POINT3D_Z(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = -sin_angle * POINT3D_X(x) + cos_angle * POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, yror)(const TYPE x, const DATA_TYPE angle) {
  return FUNCTION(NAME, yrol)(x, -angle);
}

/* res = [[cosy, -siny, 0], [siny, cosy, 0], [0, 0, 1]] x */
TYPE FUNCTION(NAME, zrol)(const TYPE x, const DATA_TYPE angle) {
  DATA_TYPE cos_angle = cos(angle), sin_angle = sin(angle);
  TYPE res;
  POINT3D_X(res) = cos_angle * POINT3D_X(x) - sin_angle * POINT3D_Y(x);
  POINT3D_Y(res) = sin_angle * POINT3D_X(x) + cos_angle * POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, zror)(const TYPE x, const DATA_TYPE angle) {
  return FUNCTION(NAME, zrol)(x, -angle);
}