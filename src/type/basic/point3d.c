#include "cgraph_base.h"
#include "cgraph_float64.h"

/** object cgraph_point3d_t header */
#include "cgraph_point3d.h"

/** template module */
#include "template_data.ct"

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

/*
        x (x) y = [a1, b1, c1] x [a2, b2, c2] = [
                 i  j  k
                a1 b1 c1
                a2 b2 c2
        ] = (b1*c2-b2*c1)i - (a1*c2-a2*c1)j + (a1*b2-a2*b1)k
*/
TYPE FUNCTION(NAME, mul)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) * POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x) * POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x) * POINT3D_Z(y);

  return res;
}

TYPE FUNCTION(NAME, dot)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(NAME, rdot)(x, y);
  POINT3D_Y(res) = DATA_ZERO;
  POINT3D_Z(res) = DATA_ZERO;

  return res;
}

__INLINE DATA_TYPE FUNCTION(NAME, rdot)(const TYPE x, const TYPE y) {
  return POINT3D_X(x) * POINT3D_X(y) + POINT3D_Y(x) * POINT3D_Y(y) +
         POINT3D_Z(x) * POINT3D_Z(y);
}

TYPE FUNCTION(NAME, div)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) - POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x) - POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x) - POINT3D_Z(y);

  return res;
}

DATA_TYPE FUNCTION(NAME, dist)(const TYPE x, const TYPE y) {
  return sqrt((POINT3D_X(x) - POINT3D_X(y)) * (POINT3D_X(x) - POINT3D_X(y)) +
              (POINT3D_Y(x) - POINT3D_Y(y)) * (POINT3D_Y(x) - POINT3D_Y(y)) +
              (POINT3D_Z(x) - POINT3D_Z(y)) * (POINT3D_Z(x) - POINT3D_Z(y)));
}