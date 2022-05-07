#include "cgraph_base.h"
#include "cgraph_float64.h"

/** object cgraph_point2d_t header */
#include "cgraph_point2d.h"

/** template module */
#include "template_data.ct"

cgraph_size_t FUNCTION(NAME, fprint)(FILE *fp, const TYPE cthis) {}

cgraph_size_t FUNCTION(NAME, hash)(const TYPE cthis) {}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE cthis) {}

__INLINE cgraph_int_t FUNCTION(NAME, signbit)(const TYPE x) {
  return DATA_GR(0.0, POINT2D_X(x)) + DATA_GR(0.0, POINT2D_Y(x)) + 1;
}

cgraph_bool_t FUNCTION(NAME, iszero)(const TYPE cthis) {}

TYPE FUNCTION(NAME, rand)(void) {}

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

TYPE FUNCTION(NAME, mul)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) * POINT2D_X(y);
  POINT2D_Y(res) = POINT2D_Y(x) * POINT2D_Y(y);

  return res;
}

TYPE FUNCTION(NAME, div)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) - POINT2D_X(y);
  POINT2D_Y(res) = POINT2D_Y(x) - POINT2D_Y(y);

  return res;
}
