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

__INLINE__ cgraph_int_t FUNCTION(NAME, signbit)(const TYPE x) {
  return DATA_GT(0.0, POINT3D_X(x)) + DATA_GT(0.0, POINT3D_Y(x)) + 1;
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

DATA_TYPE FUNCTION(NAME, dmin)(const TYPE x) {
  DATA_TYPE min =
      DATA_LT(POINT3D_X(x), POINT3D_Y(x)) ? POINT3D_X(x) : POINT3D_Y(x);

  return DATA_LT(min, POINT3D_Z(x)) ? min : POINT3D_Z(x);
}

DATA_TYPE FUNCTION(NAME, dmax)(const TYPE x) {
  DATA_TYPE max =
      DATA_GT(POINT3D_X(x), POINT3D_Y(x)) ? POINT3D_X(x) : POINT3D_Y(x);

  return DATA_GT(max, POINT3D_Z(x)) ? max : POINT3D_Z(x);
}

DATA_TYPE FUNCTION(NAME, dsum)(const TYPE x) {
  return POINT3D_X(x) + POINT3D_Y(x) + POINT3D_Z(x);
}

TYPE FUNCTION(NAME, initpx)(const TYPE x) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = DATA_ZERO;
  POINT3D_Z(res) = DATA_ZERO;

  return res;
}

TYPE FUNCTION(NAME, initpy)(const TYPE x) {
  TYPE res;
  POINT3D_X(res) = DATA_ZERO;
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = DATA_ZERO;

  return res;
}

TYPE FUNCTION(NAME, initpz)(const TYPE x) {
  TYPE res;
  POINT3D_X(res) = DATA_ZERO;
  POINT3D_Y(res) = DATA_ZERO;
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, initpxy)(const TYPE x) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = DATA_ZERO;

  return res;
}

TYPE FUNCTION(NAME, initpxz)(const TYPE x) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = DATA_ZERO;
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, initpyz)(const TYPE x) {
  TYPE res;
  POINT3D_X(res) = DATA_ZERO;
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
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

__INLINE__ TYPE FUNCTION(NAME, rev)(const TYPE x) {
  TYPE res;
  POINT3D_X(res) = POINT3D_Z(x);
  POINT3D_Y(res) = POINT3D_X(x);
  POINT3D_Z(res) = POINT3D_Y(x);

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, rev2)(const TYPE x) {
  TYPE res;
  POINT3D_X(res) = POINT3D_Y(x);
  POINT3D_Y(res) = POINT3D_Z(x);
  POINT3D_Z(res) = POINT3D_X(x);

  return res;
}

__INLINE__ TYPE FUNCTION(NAME, trans)(const TYPE x) {
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

TYPE FUNCTION(NAME, abs)(const TYPE x) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, abs)(POINT3D_X(x));
  POINT3D_Y(res) = FUNCTION(DATA_NAME, abs)(POINT3D_Y(x));
  POINT3D_Z(res) = FUNCTION(DATA_NAME, abs)(POINT3D_Z(x));

  return res;
}

TYPE FUNCTION(NAME, inv)(const TYPE x) {
  const DATA_TYPE mag2_inv = FUNCTION(NAME, mag2_inv)(x);
  TYPE res;
  POINT3D_X(res) = mag2_inv * POINT3D_X(x);
  POINT3D_Y(res) = mag2_inv * POINT3D_Y(x);
  POINT3D_Z(res) = mag2_inv * POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, std)(const TYPE x) {
  const DATA_TYPE mag_inv = FUNCTION(NAME, mag_inv)(x);
  TYPE res;
  POINT3D_X(res) = mag_inv * POINT3D_X(x);
  POINT3D_Y(res) = mag_inv * POINT3D_Y(x);
  POINT3D_Z(res) = mag_inv * POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, pow2)(const TYPE x) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) * POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) * POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) * POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, pow3)(const TYPE x) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) * POINT3D_X(x) * POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) * POINT3D_Y(x) * POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) * POINT3D_Z(x) * POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, sqrt)(const TYPE x) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, sqrt)(POINT3D_X(x));
  POINT3D_Y(res) = FUNCTION(DATA_NAME, sqrt)(POINT3D_Y(x));
  POINT3D_Z(res) = FUNCTION(DATA_NAME, sqrt)(POINT3D_Z(x));

  return res;
}

TYPE FUNCTION(NAME, cube)(const TYPE x) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, cube)(POINT3D_X(x));
  POINT3D_Y(res) = FUNCTION(DATA_NAME, cube)(POINT3D_Y(x));
  POINT3D_Z(res) = FUNCTION(DATA_NAME, cube)(POINT3D_Z(x));

  return res;
}

TYPE FUNCTION(NAME, shl)(const TYPE x, const cgraph_size_t len) {
  TYPE res = x;
  if (1 == len) {
    POINT3D_X(res) = DATA_ZERO;
    POINT3D_Y(res) = POINT3D_X(x);
    POINT3D_Z(res) = POINT3D_Y(x);
  } else if (2 == len) {
    POINT3D_X(res) = DATA_ZERO;
    POINT3D_Y(res) = DATA_ZERO;
    POINT3D_Z(res) = POINT3D_X(x);
  } else if (-1 == len) {
    POINT3D_X(res) = POINT3D_Y(x);
    POINT3D_Y(res) = POINT3D_Z(x);
    POINT3D_Z(res) = DATA_ZERO;
  } else if (-2 == len) {
    POINT3D_X(res) = POINT3D_Z(x);
    POINT3D_Y(res) = DATA_ZERO;
    POINT3D_Z(res) = DATA_ZERO;
  } else if (0 != len) {
    POINT3D_X(res) = DATA_ZERO;
    POINT3D_Y(res) = DATA_ZERO;
  }

  return res;
}

TYPE FUNCTION(NAME, rol)(const TYPE x, const cgraph_size_t len) {
  cgraph_size_t len_mod = cgraph_math_mod3(len);
  TYPE res = x;
  if (1 == len_mod) {
    POINT3D_X(res) = POINT3D_Z(x);
    POINT3D_Y(res) = POINT3D_X(x);
    POINT3D_Z(res) = POINT3D_Y(x);
  } else if (2 == len_mod) {
    POINT3D_X(res) = POINT3D_Z(x);
    POINT3D_Y(res) = POINT3D_Y(x);
    POINT3D_Z(res) = POINT3D_X(x);
  } else if (-1 == len_mod) {
    POINT3D_X(res) = POINT3D_Y(x);
    POINT3D_Y(res) = POINT3D_Z(x);
    POINT3D_Z(res) = POINT3D_X(x);
  } else if (-2 == len_mod) {
    POINT3D_X(res) = POINT3D_Z(x);
    POINT3D_Y(res) = POINT3D_Y(x);
    POINT3D_Z(res) = POINT3D_X(x);
  }

  return res;
}

/**
 * det(x, y, z) = |[[x1, y1, z1], [x2, y2, z2], [x3, y3, z3]]| =
 * x1*(y2*z3-z2*y3) - y1*(x1*z3-x3*z1) + z1*(x1*y2-x2*y1)
 */
DATA_TYPE FUNCTION(NAME, det)(const TYPE x, const TYPE y, const TYPE z) {
  return POINT3D_X(x) *
             (POINT3D_Y(y) * POINT3D_Z(z) - POINT3D_Y(z) * POINT3D_Z(y)) -
         POINT3D_Y(x) *
             (POINT3D_X(x) * POINT3D_Z(z) - POINT3D_X(z) * POINT3D_Z(x)) +
         POINT3D_Z(x) *
             (POINT3D_X(x) * POINT3D_Y(y) - POINT3D_X(y) * POINT3D_Y(x));
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
 * x * y = [x1, y1, z1] * [x2, y2, z2] =
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

TYPE FUNCTION(NAME, saxpy)(const TYPE x, const TYPE y, const DATA_TYPE a) {
  TYPE res;
  POINT3D_X(res) = a * POINT3D_X(x) + POINT3D_X(y);
  POINT3D_Y(res) = a * POINT3D_Y(x) + POINT3D_Y(y);
  POINT3D_Z(res) = a * POINT3D_Z(x) + POINT3D_Z(y);

  return res;
}

__INLINE__ DATA_TYPE FUNCTION(NAME, fdot)(const TYPE x, const TYPE y) {
  return (POINT3D_X(x) * POINT3D_X(y)) + (POINT3D_Y(x) * POINT3D_Y(y)) +
         (POINT3D_Z(x) * POINT3D_Z(y));
}

TYPE FUNCTION(NAME, mixed)(const TYPE x, const TYPE y, const TYPE z) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(NAME, fmixed)(x, y, z);
  POINT3D_Y(res) = DATA_ZERO;
  POINT3D_Z(res) = DATA_ZERO;

  return res;
}

/**
 * mixed(x, y, z) = x <x> y * z = |[[x1, y1, z1], [x2, y2, z2], [x3, y3, z3]]|
 */
DATA_TYPE FUNCTION(NAME, fmixed)(const TYPE x, const TYPE y, const TYPE z) {
  return FUNCTION(NAME, fdot)(FUNCTION(NAME, mul)(x, y), z);
}

TYPE FUNCTION(NAME, triple)(const TYPE x, const TYPE y, const TYPE z) {
  return FUNCTION(NAME, mul)(FUNCTION(NAME, mul)(x, y), z);
}

/** res = x / y = x (x) y / (y (x) y)  */
TYPE FUNCTION(NAME, div)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, divf)(FUNCTION(NAME, mul)(x, y),
                              FUNCTION(NAME, mag2)(y));
}

TYPE FUNCTION(NAME, xdadd)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) + POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, xdsub)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) - POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, xdmul)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) * POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, xddiv)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) / POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, xdmod)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, mod)(POINT3D_X(x), POINT3D_X(y));
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, xdpow)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, pow)(POINT3D_X(x), POINT3D_X(y));
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, ydadd)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) + POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, ydsub)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) - POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, ydmul)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) * POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, yddiv)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) / POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, ydmod)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = FUNCTION(DATA_NAME, mod)(POINT3D_Y(x), POINT3D_Y(y));
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, ydpow)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = FUNCTION(DATA_NAME, pow)(POINT3D_Y(x), POINT3D_Y(y));
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, zdadd)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) + POINT3D_Z(y);

  return res;
}

TYPE FUNCTION(NAME, zdsub)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) - POINT3D_Z(y);

  return res;
}

TYPE FUNCTION(NAME, zdmul)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) * POINT3D_Z(y);

  return res;
}

TYPE FUNCTION(NAME, zddiv)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) / POINT3D_Z(y);

  return res;
}

TYPE FUNCTION(NAME, zdmod)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = FUNCTION(DATA_NAME, mod)(POINT3D_Z(x), POINT3D_Z(y));

  return res;
}

TYPE FUNCTION(NAME, zdpow)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = FUNCTION(DATA_NAME, pow)(POINT3D_Z(x), POINT3D_Z(y));

  return res;
}

TYPE FUNCTION(NAME, xydadd)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) + POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x) + POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, xydsub)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) - POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x) - POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, xydmul)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) * POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x) * POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, xyddiv)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) / POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x) / POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, xydmod)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, mod)(POINT3D_X(x), POINT3D_X(y));
  POINT3D_Y(res) = FUNCTION(DATA_NAME, mod)(POINT3D_Y(x), POINT3D_Y(y));
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, xydpow)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, pow)(POINT3D_X(x), POINT3D_X(y));
  POINT3D_Y(res) = FUNCTION(DATA_NAME, pow)(POINT3D_Y(x), POINT3D_Y(y));
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, xzdadd)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) + POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) + POINT3D_Z(y);

  return res;
}

TYPE FUNCTION(NAME, xzdsub)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) - POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) - POINT3D_Z(y);

  return res;
}

TYPE FUNCTION(NAME, xzdmul)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) * POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) * POINT3D_Z(y);

  return res;
}

TYPE FUNCTION(NAME, xzddiv)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) / POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) / POINT3D_Z(y);

  return res;
}

TYPE FUNCTION(NAME, xzdmod)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, mod)(POINT3D_X(x), POINT3D_X(y));
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = FUNCTION(DATA_NAME, mod)(POINT3D_Z(x), POINT3D_Z(y));

  return res;
}

TYPE FUNCTION(NAME, xzdpow)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, pow)(POINT3D_X(x), POINT3D_X(y));
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = FUNCTION(DATA_NAME, pow)(POINT3D_Z(x), POINT3D_Z(y));

  return res;
}

TYPE FUNCTION(NAME, yzdadd)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) + POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x) + POINT3D_Z(y);

  return res;
}

TYPE FUNCTION(NAME, yzdsub)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) - POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x) - POINT3D_Z(y);

  return res;
}

TYPE FUNCTION(NAME, yzdmul)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) * POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x) * POINT3D_Z(y);

  return res;
}

TYPE FUNCTION(NAME, yzddiv)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) / POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x) / POINT3D_Z(y);

  return res;
}

TYPE FUNCTION(NAME, yzdmod)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = FUNCTION(DATA_NAME, mod)(POINT3D_Y(x), POINT3D_Y(y));
  POINT3D_Z(res) = FUNCTION(DATA_NAME, mod)(POINT3D_Z(x), POINT3D_Z(y));

  return res;
}

TYPE FUNCTION(NAME, yzdpow)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = FUNCTION(DATA_NAME, pow)(POINT3D_Y(x), POINT3D_Y(y));
  POINT3D_Z(res) = FUNCTION(DATA_NAME, pow)(POINT3D_Z(x), POINT3D_Z(y));

  return res;
}

TYPE FUNCTION(NAME, dmul)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) * POINT3D_X(y);
  POINT3D_Y(res) = POINT3D_Y(x) * POINT3D_Y(y);
  POINT3D_Z(res) = POINT3D_Z(x) * POINT3D_Z(y);

  return res;
}

TYPE FUNCTION(NAME, ddiv)(const TYPE x, const TYPE y) {
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
  const DATA_TYPE y_inv = 1.0 / y;
  TYPE res;
  POINT3D_X(res) = y_inv * POINT3D_X(x);
  POINT3D_Y(res) = y_inv * POINT3D_Y(x);
  POINT3D_Z(res) = y_inv * POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, modf)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, mod)(POINT3D_X(x), y);
  POINT3D_Y(res) = FUNCTION(DATA_NAME, mod)(POINT3D_Y(x), y);
  POINT3D_Z(res) = FUNCTION(DATA_NAME, mod)(POINT3D_Z(x), y);

  return res;
}

TYPE FUNCTION(NAME, powf)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, pow)(POINT3D_X(x), y);
  POINT3D_Y(res) = FUNCTION(DATA_NAME, pow)(POINT3D_Y(x), y);
  POINT3D_Z(res) = FUNCTION(DATA_NAME, pow)(POINT3D_Z(x), y);

  return res;
}

TYPE FUNCTION(NAME, addx)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) + y;
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, subx)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) - y;
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, mulx)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) * y;
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, divx)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) / y;
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, modx)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, mod)(POINT3D_X(x), y);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, powx)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, pow)(POINT3D_X(x), y);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, addy)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) + y;
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, suby)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) - y;
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, muly)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) * y;
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, divy)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) / y;
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, mody)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = FUNCTION(DATA_NAME, mod)(POINT3D_Y(x), y);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, powy)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = FUNCTION(DATA_NAME, pow)(POINT3D_Y(x), y);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, addz)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) + y;

  return res;
}

TYPE FUNCTION(NAME, subz)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) - y;

  return res;
}

TYPE FUNCTION(NAME, mulz)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) * y;

  return res;
}

TYPE FUNCTION(NAME, divz)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) / y;

  return res;
}

TYPE FUNCTION(NAME, modz)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = FUNCTION(DATA_NAME, mod)(POINT3D_Z(x), y);

  return res;
}

TYPE FUNCTION(NAME, powz)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = FUNCTION(DATA_NAME, pow)(POINT3D_Z(x), y);

  return res;
}

TYPE FUNCTION(NAME, addxy)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) + y;
  POINT3D_Y(res) = POINT3D_Y(x) + y;
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, subxy)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) - y;
  POINT3D_Y(res) = POINT3D_Y(x) - y;
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, mulxy)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) * y;
  POINT3D_Y(res) = POINT3D_Y(x) * y;
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, divxy)(const TYPE x, const DATA_TYPE y) {
  const DATA_TYPE y_inv = 1.0 / y;
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) * y_inv;
  POINT3D_Y(res) = POINT3D_Y(x) * y_inv;
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, modxy)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, mod)(POINT3D_X(x), y);
  POINT3D_Y(res) = FUNCTION(DATA_NAME, mod)(POINT3D_Y(x), y);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, powxy)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, pow)(POINT3D_X(x), y);
  POINT3D_Y(res) = FUNCTION(DATA_NAME, pow)(POINT3D_Y(x), y);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, addxz)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) + y;
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) + y;

  return res;
}

TYPE FUNCTION(NAME, subxz)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) - y;
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) - y;

  return res;
}

TYPE FUNCTION(NAME, mulxz)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) * y;
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) * y;

  return res;
}

TYPE FUNCTION(NAME, divxz)(const TYPE x, const DATA_TYPE y) {
  const DATA_TYPE y_inv = 1.0 / y;
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) * y_inv;
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x) * y_inv;

  return res;
}

TYPE FUNCTION(NAME, modxz)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, mod)(POINT3D_X(x), y);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = FUNCTION(DATA_NAME, mod)(POINT3D_Z(x), y);

  return res;
}

TYPE FUNCTION(NAME, powxz)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, pow)(POINT3D_X(x), y);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = FUNCTION(DATA_NAME, pow)(POINT3D_Z(x), y);

  return res;
}

TYPE FUNCTION(NAME, addyz)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) + y;
  POINT3D_Z(res) = POINT3D_Z(x) + y;

  return res;
}

TYPE FUNCTION(NAME, subyz)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) - y;
  POINT3D_Z(res) = POINT3D_Z(x) - y;

  return res;
}

TYPE FUNCTION(NAME, mulyz)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) * y;
  POINT3D_Z(res) = POINT3D_Z(x) * y;

  return res;
}

TYPE FUNCTION(NAME, divyz)(const TYPE x, const DATA_TYPE y) {
  const DATA_TYPE y_inv = 1.0 / y;
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = POINT3D_Y(x) * y_inv;
  POINT3D_Z(res) = POINT3D_Z(x) * y_inv;

  return res;
}

TYPE FUNCTION(NAME, modyz)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = FUNCTION(DATA_NAME, mod)(POINT3D_Y(x), y);
  POINT3D_Z(res) = FUNCTION(DATA_NAME, mod)(POINT3D_Z(x), y);

  return res;
}

TYPE FUNCTION(NAME, powyz)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = FUNCTION(DATA_NAME, pow)(POINT3D_Y(x), y);
  POINT3D_Z(res) = FUNCTION(DATA_NAME, pow)(POINT3D_Z(x), y);

  return res;
}

TYPE FUNCTION(NAME, rotr)(const TYPE x, const DATA_TYPE angle) {
  return FUNCTION(NAME, xrotr)(x, angle);
}

TYPE FUNCTION(NAME, rotl)(const TYPE x, const DATA_TYPE angle) {
  return FUNCTION(NAME, xrotl)(x, angle);
}

/* res = [[1, 0, 0], [0, cosy, -siny], [0, siny, cosy]] x */
TYPE FUNCTION(NAME, xrotl)(const TYPE x, const DATA_TYPE angle) {
  const DATA_TYPE cos_angle = cos(angle), sin_angle = sin(angle);
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x);
  POINT3D_Y(res) = cos_angle * POINT3D_Y(x) - sin_angle * POINT3D_Z(x);
  POINT3D_Z(res) = sin_angle * POINT3D_Y(x) + cos_angle * POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, xrotr)(const TYPE x, const DATA_TYPE angle) {
  return FUNCTION(NAME, xrotl)(x, -angle);
}

/* res = [[cosy, 0, siny], [0, 1, 0], [-siny, 0, cosy]] x */
TYPE FUNCTION(NAME, yrotl)(const TYPE x, const DATA_TYPE angle) {
  const DATA_TYPE cos_angle = cos(angle), sin_angle = sin(angle);
  TYPE res;
  POINT3D_X(res) = cos_angle * POINT3D_X(x) + sin_angle * POINT3D_Z(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = -sin_angle * POINT3D_X(x) + cos_angle * POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, yrotr)(const TYPE x, const DATA_TYPE angle) {
  return FUNCTION(NAME, yrotl)(x, -angle);
}

/* res = [[cosy, -siny, 0], [siny, cosy, 0], [0, 0, 1]] x */
TYPE FUNCTION(NAME, zrotl)(const TYPE x, const DATA_TYPE angle) {
  const DATA_TYPE cos_angle = cos(angle), sin_angle = sin(angle);
  TYPE res;
  POINT3D_X(res) = cos_angle * POINT3D_X(x) - sin_angle * POINT3D_Y(x);
  POINT3D_Y(res) = sin_angle * POINT3D_X(x) + cos_angle * POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, zrotr)(const TYPE x, const DATA_TYPE angle) {
  return FUNCTION(NAME, zrotl)(x, -angle);
}

TYPE FUNCTION(NAME, arol)(const TYPE x, const TYPE r, const DATA_TYPE angle) {
  const DATA_TYPE cos_angle = cos(angle), cos_angle1 = 1 - cos_angle,
                  sin_angle = sin(angle);
  const DATA_TYPE r_x = POINT3D_X(r) * sin_angle,
                  r_y = POINT3D_Y(r) * sin_angle,
                  r_z = POINT3D_Z(r) * sin_angle,
                  r_xy = POINT3D_X(r) * POINT3D_Y(r) * cos_angle1,
                  r_xz = POINT3D_X(r) * POINT3D_Z(r) * cos_angle1,
                  r_yz = POINT3D_Y(r) * POINT3D_Z(r) * cos_angle1;
  TYPE res;
  POINT3D_X(res) =
      POINT3D_X(x) * (cos_angle + POINT3D_X(r) * POINT3D_X(r) * cos_angle1) +
      POINT3D_Y(x) * (r_xy - r_z) + POINT3D_Z(x) * (r_xz + r_y);
  POINT3D_Y(res) =
      POINT3D_X(x) * (r_xy + r_z) +
      POINT3D_Y(x) * (cos_angle + POINT3D_Y(r) * POINT3D_Y(r) * cos_angle1) +
      POINT3D_Z(x) * (r_yz - r_x);
  POINT3D_Z(res) =
      POINT3D_X(x) * (r_xz - r_y) + POINT3D_Y(x) * (r_yz + r_x) +
      POINT3D_Z(x) * (cos_angle + POINT3D_Z(r) * POINT3D_Z(r) * cos_angle1);

  return res;
}

TYPE FUNCTION(NAME, aror)(const TYPE x, const TYPE r, const DATA_TYPE angle) {
  return FUNCTION(NAME, arol)(x, r, -angle);
}

/** res = sin(angle) * [[0, -rz, ry], [rz, 0, -rx], [-ry, rx, 0]] * x */
TYPE FUNCTION(NAME, arol_inv)(const TYPE x, const TYPE r,
                              const DATA_TYPE angle) {
  const DATA_TYPE sin_angle = sin(angle), rs_x = POINT3D_X(r) * sin_angle,
                  rs_y = POINT3D_Y(r) * sin_angle,
                  rs_z = POINT3D_Z(r) * sin_angle;
  TYPE res;
  POINT3D_X(res) = -rs_z * POINT3D_Y(x) + rs_y * POINT3D_Z(x);
  POINT3D_Y(res) = rs_z * POINT3D_X(x) - rs_x * POINT3D_Z(x);
  POINT3D_Z(res) = -rs_y * POINT3D_X(x) + rs_x * POINT3D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, aror_inv)(const TYPE x, const TYPE r,
                              const DATA_TYPE angle) {
  return FUNCTION(NAME, arol_inv)(x, r, -angle);
}

TYPE FUNCTION(NAME, scale)(const TYPE x, const TYPE rate) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) * POINT3D_X(rate);
  POINT3D_Y(res) = POINT3D_Y(x) * POINT3D_Y(rate);
  POINT3D_Z(res) = POINT3D_Z(x) * POINT3D_Z(rate);

  return res;
}

/**
 * LookAt = [[Rx, Ry, Rz, 0], [Ux, Uy, Uz, 0], [Dx, Dy, Dz, 0], [0, 0, 0, 1]] *
 * [[1, 0, 0, -Px], [0, 1, 0, -Py], [0, 0, 1, -Pz], [0, 0, 0, 1]] =
 * [[Rx, Ry, Rz, -Rx*Px-Ry*Py-Rz*Pz], [Ux, Uy, Uz, -Ux*Px-Uy*Py-Uz*Pz], [Dx, Dy,
 * Dz, -Dx*Px-Dy*Py-Dz*Pz], [0, 0, 0, 1]]
 */
#define LOOKAT_XxP(x, p)                                                       \
  (POINT3D_X((x)) * POINT3D_X((p)) + POINT3D_Y((x)) * POINT3D_Y((p)) +         \
   POINT3D_Z((x)) * POINT3D_Z((p)))
TYPE FUNCTION(NAME, lookat)(const TYPE x, const TYPE r, const TYPE u,
                            const TYPE d, const TYPE p) {
  TYPE res;
  POINT3D_X(res) = POINT3D_X(r) * POINT3D_X(x) + POINT3D_Y(r) * POINT3D_Y(x) +
                   POINT3D_Z(r) * POINT3D_Z(x) - LOOKAT_XxP(r, p);
  POINT3D_Y(res) = POINT3D_X(u) * POINT3D_X(x) + POINT3D_Y(u) * POINT3D_Y(x) +
                   POINT3D_Z(u) * POINT3D_Z(x) - LOOKAT_XxP(u, p);
  POINT3D_Z(res) = POINT3D_X(d) * POINT3D_X(x) + POINT3D_Y(d) * POINT3D_Y(x) +
                   POINT3D_Z(d) * POINT3D_Z(x) - LOOKAT_XxP(d, p);

  return res;
}
#undef LOOKAT_XxP

/**
 * @brief Perspective Frustum and Normalized Device Coordinates(NDC)
 * For x belongs to (r, l), y belongs to (t, b) and z belongs to (f, n):
 * GL_PROKECTION = [[2n/(r-l), 0, (r+l)/(r-l), 0], [0, 2n/(t-b), (t+b)/(t-b),
 * 0], [0, 0, -(f+n)/(f-n), -2fn/(f-n)], [0, 0, -1, 0]]
 * where
 * r = POINT3D_X(max), l = POINT3D_X(min),
 * t = POINT3D_Y(max), b = POINT3D_Y(min),
 * f = POINT3D_Z(max), n = POINT3D_Z(min)
 */
TYPE FUNCTION(NAME, glfrustum)(const TYPE x, const TYPE min, const TYPE max) {
  const DATA_TYPE sx = POINT3D_X(max) + POINT3D_X(min),
                  sy = POINT3D_Y(max) + POINT3D_Y(min),
                  sz = POINT3D_Z(max) + POINT3D_Z(min),
                  dx_1 = 1.0 / (POINT3D_X(max) - POINT3D_X(min)),
                  dy_1 = 1.0 / (POINT3D_Y(max) - POINT3D_Y(min)),
                  dz_1 = 1.0 / (POINT3D_Z(max) - POINT3D_Z(min)),
                  z_2min = 2.0 * POINT3D_Z(min);
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) * (z_2min * dx_1) + POINT3D_Z(x) * (sx * dx_1);
  POINT3D_Y(res) = POINT3D_Y(x) * (z_2min * dy_1) + POINT3D_Z(x) * (sy * dy_1);
  POINT3D_Z(res) =
      POINT3D_Z(x) * (-sz * dz_1) - (POINT3D_Z(max) * z_2min * dz_1);

  return res;
}

/**
 * @brief Orthographic Volume and Normalized Device Coordinates(NDC)
 * For x belongs to (r, l), y belongs to (t, b) and z belongs to (f, n):
 * GL_PROKECTION = [[2/(r-l), 0, 0, -(r+l)/(r-l)], [0, 2/(t-b), 0,
 * -(t+b)/(t-b)], [0, 0, -2/(f-n), -(f+n)/(f-n)], [0, 0, 0, 1]]
 * where
 * r = POINT3D_X(max), l = POINT3D_X(min),
 * t = POINT3D_Y(max), b = POINT3D_Y(min),
 * f = POINT3D_Z(max), n = POINT3D_Z(min)
 */
TYPE FUNCTION(NAME, glvolume)(const TYPE x, const TYPE min, const TYPE max) {
  const DATA_TYPE sx = POINT3D_X(max) + POINT3D_X(min),
                  sy = POINT3D_Y(max) + POINT3D_Y(min),
                  sz = POINT3D_Z(max) + POINT3D_Z(min),
                  dx_1 = 1.0 / (POINT3D_X(max) - POINT3D_X(min)),
                  dy_1 = 1.0 / (POINT3D_Y(max) - POINT3D_Y(min)),
                  dz_1 = 1.0 / (POINT3D_Z(max) - POINT3D_Z(min));
  TYPE res;
  POINT3D_X(res) = POINT3D_X(x) * (2.0 * dx_1) - (sx * dx_1);
  POINT3D_Y(res) = POINT3D_Y(x) * (2.0 * dy_1) - (sy * dy_1);
  POINT3D_Z(res) = -POINT3D_Z(x) * (2.0 * dz_1) - (sz * dz_1);

  return res;
}

/**
 * @brief Line Equation
 * Given P1(x1, y1, z1), P2(x2, y2, z2) and P3(x3, y3, z3), the line between P1
 * and P2 can be defined as
 * (x - x1) / (x2 - x1) = (y - y1) / (y2 - y1) = (z - z1) / (z2 - z1) = t
 * x = x1 + mt = x1 + (x2 - x1)t
 * y = y1 + nt = y1 + (y2 - y1)t
 * z = z1 - pt = z1 + (z2 - z1)t
 */
TYPE FUNCTION(NAME, line)(const TYPE x, const TYPE y, TYPE *p) {
  TYPE res = FUNCTION(NAME, sub)(y, x);
  if (NULL != p) {
    *p = x;
  }

  return res;
}