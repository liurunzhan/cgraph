#include "cgraph_base.h"
#include "cgraph_float64.h"

/** object cgraph_point2d_t header */
#include "cgraph_point2d.h"

/** template module */
#include "template_data.ct"

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

/*
        x (x) y = [a1, b1] x [a2, b2] = [
                a1 b1
                a2 b2
        ] = a1*b2 - a2*b1
*/
TYPE FUNCTION(NAME, mul)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = FUNCTION(NAME, rmul)(x, y);
  POINT2D_Y(res) = DATA_ZERO;

  return res;
}

DATA_TYPE FUNCTION(NAME, rmul)(const TYPE x, const TYPE y) {
  return POINT2D_X(x) * POINT2D_Y(y) - POINT2D_X(y) * POINT2D_Y(x);
}

TYPE FUNCTION(NAME, dot)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = FUNCTION(NAME, rdot)(x, y);
  POINT2D_Y(res) = DATA_ZERO;

  return res;
}

__INLINE DATA_TYPE FUNCTION(NAME, rdot)(const TYPE x, const TYPE y) {
  return POINT2D_X(x) * POINT2D_X(y) + POINT2D_Y(x) * POINT2D_Y(y);
}

TYPE FUNCTION(NAME, div)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) - POINT2D_X(y);
  POINT2D_Y(res) = POINT2D_Y(x) - POINT2D_Y(y);

  return res;
}

DATA_TYPE FUNCTION(NAME, dist)(const TYPE x, const TYPE y) {
  return sqrt((POINT2D_X(x) - POINT2D_X(y)) * (POINT2D_X(x) - POINT2D_X(y)) +
              (POINT2D_Y(x) - POINT2D_Y(y)) * (POINT2D_Y(x) - POINT2D_Y(y)));
}

cgraph_bool_t FUNCTION(NAME, istriangle)(const TYPE a, const TYPE b,
                                         const TYPE c) {
  DATA_TYPE mul0 =
                (POINT2D_X(b) - POINT2D_X(a)) * (POINT2D_Y(c) - POINT2D_Y(a)),
            mul1 =
                (POINT2D_X(c) - POINT2D_X(a)) * (POINT2D_Y(b) - POINT2D_Y(a));

  return DATA_NE(mul0, mul1);
}

/* three point concurrent formula (x2-x1)(y3-y1)=(x3-x1)(y2-y1) */
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