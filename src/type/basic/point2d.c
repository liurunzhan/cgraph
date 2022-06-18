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

DATA_TYPE FUNCTION(NAME, dmin)(const TYPE x) {
  return DATA_LS(POINT2D_X(x), POINT2D_Y(x)) ? POINT2D_X(x) : POINT2D_Y(x);
}

DATA_TYPE FUNCTION(NAME, dmax)(const TYPE x) {
  return DATA_GR(POINT2D_X(x), POINT2D_Y(x)) ? POINT2D_X(x) : POINT2D_Y(x);
}

DATA_TYPE FUNCTION(NAME, dsum)(const TYPE x) {
  return POINT2D_X(x) + POINT2D_Y(x);
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

TYPE FUNCTION(NAME, rev)(const TYPE x) {
  TYPE res;
  POINT2D_X(res) = POINT2D_Y(x);
  POINT2D_Y(res) = POINT2D_X(x);

  return res;
}

__INLINE TYPE FUNCTION(NAME, trans)(const TYPE x) {
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

TYPE FUNCTION(NAME, abs)(const TYPE x) {
  TYPE res;
  POINT2D_X(res) = FUNCTION(DATA_NAME, abs)(POINT2D_X(x));
  POINT2D_Y(res) = FUNCTION(DATA_NAME, abs)(POINT2D_Y(x));

  return res;
}

TYPE FUNCTION(NAME, inv)(const TYPE x) {
  const DATA_TYPE mag2_inv = FUNCTION(NAME, mag2_inv)(x);
  TYPE res;
  POINT2D_X(res) = mag2_inv * POINT2D_X(x);
  POINT2D_Y(res) = mag2_inv * POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, std)(const TYPE x) {
  const DATA_TYPE mag_inv = FUNCTION(NAME, mag_inv)(x);
  TYPE res;
  POINT2D_X(res) = mag_inv * POINT2D_X(x);
  POINT2D_Y(res) = mag_inv * POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, shl)(const TYPE x, const cgraph_size_t bits) {
  TYPE res = x;
  if (1 == bits) {
    POINT2D_X(res) = DATA_ZERO;
    POINT2D_Y(res) = POINT2D_X(x);
  } else if (-1 == bits) {
    POINT2D_X(res) = POINT2D_Y(x);
    POINT2D_Y(res) = DATA_ZERO;
  } else if (0 != bits) {
    POINT2D_X(res) = DATA_ZERO;
    POINT2D_Y(res) = DATA_ZERO;
  }

  return res;
}

TYPE FUNCTION(NAME, shr)(const TYPE x, const cgraph_size_t bits) {
  return FUNCTION(NAME, shl)(x, -bits);
}

TYPE FUNCTION(NAME, rol)(const TYPE x, const cgraph_size_t bits) {
  TYPE res = x;
  if (1 == cgraph_math_mod2(bits)) {
    POINT2D_X(res) = POINT2D_Y(x);
    POINT2D_Y(res) = POINT2D_X(x);
  }

  return res;
}

TYPE FUNCTION(NAME, ror)(const TYPE x, const cgraph_size_t bits) {
  return FUNCTION(NAME, rol)(x, -bits);
}

DATA_TYPE FUNCTION(NAME, mahadist)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, dsum)(FUNCTION(NAME, absub)(x, y));
}

DATA_TYPE FUNCTION(NAME, chebdist)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, dmax)(FUNCTION(NAME, absub)(x, y));
}

DATA_TYPE FUNCTION(NAME, cosidist)(const TYPE x, const TYPE y) {
  return FUNCTION(NAME, fdot)(x, y) / FUNCTION(NAME, mag)(x) /
         FUNCTION(NAME, mag)(y);
}

/**
 * d = 2d*argsin( sqrt( sin((lat2-lat1)/2)^2 +
 * cos(lat2)cos(lat1)sin((lon2-lon1)/2)^2 ) )
 */
DATA_TYPE FUNCTION(NAME, havedist)(const TYPE x, const TYPE y) {
  const DATA_TYPE dx = 0.5 * (POINT2D_X(y) - POINT2D_X(x)), sindx = sin(dx),
                  dy = 0.5 * (POINT2D_Y(y) - POINT2D_Y(x)), sindy = sin(dy);
  DATA_TYPE dist =
      (sindy * sindy) + (cos(POINT2D_Y(y)) * cos(POINT2D_Y(x)) * sindx * sindx);
  return 2 * 6378 * 1000 * asin(sqrt(dist));
}

/** det(x, y) = |[[x1, y1], [x2, y2]]| = x1*y2 - x2*y1 */
DATA_TYPE FUNCTION(NAME, det)(const TYPE x, const TYPE y) {
  return POINT2D_X(x) * POINT2D_Y(y) - POINT2D_X(y) * POINT2D_Y(x);
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

TYPE FUNCTION(NAME, absub)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = FUNCTION(DATA_NAME, abs)(POINT2D_X(x) - POINT2D_X(y));
  POINT2D_Y(res) = FUNCTION(DATA_NAME, abs)(POINT2D_Y(x) - POINT2D_Y(y));

  return res;
}

TYPE FUNCTION(NAME, mul)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = FUNCTION(NAME, fmul)(x, y);
  POINT2D_Y(res) = DATA_ZERO;

  return res;
}

/* |x (x) y| = |[x1, y1] x [x2, y2]|= x1*y2 - x2*y1 */
DATA_TYPE FUNCTION(NAME, fmul)(const TYPE x, const TYPE y) {
  return (POINT2D_X(x) * POINT2D_Y(y)) - (POINT2D_X(y) * POINT2D_Y(x));
}

TYPE FUNCTION(NAME, dot)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = FUNCTION(NAME, fdot)(x, y);
  POINT2D_Y(res) = DATA_ZERO;

  return res;
}

/* x * y = [x1, y1] * [x2, y2] = x1*y1 + x2*y2 */
__INLINE DATA_TYPE FUNCTION(NAME, fdot)(const TYPE x, const TYPE y) {
  return (POINT2D_X(x) * POINT2D_X(y)) + (POINT2D_Y(x) * POINT2D_Y(y));
}

/*
 * res = x / y = x (x) y / (y (x) y) =
 * [(x1*x2+y1*y2)/(x2*x2+y2*y2), (x2*y1-x1*y2)/(x2*x2+y2*y2)]
 */
TYPE FUNCTION(NAME, div)(const TYPE x, const TYPE y) {
  const DATA_TYPE mag2_inv = FUNCTION(NAME, mag2_inv)(x);
  TYPE res;
  POINT2D_X(res) =
      mag2_inv * (POINT2D_X(x) * POINT2D_X(y) + POINT2D_Y(x) * POINT2D_Y(y));
  POINT2D_Y(res) =
      mag2_inv * (POINT2D_X(y) * POINT2D_Y(x) - POINT2D_X(x) * POINT2D_Y(y));

  return res;
}

TYPE FUNCTION(NAME, xdadd)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) + POINT2D_X(y);
  POINT2D_Y(res) = POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, xdsub)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) - POINT2D_X(y);
  POINT2D_Y(res) = POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, xdmul)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) * POINT2D_X(y);
  POINT2D_Y(res) = POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, xddiv)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) / POINT2D_X(y);
  POINT2D_Y(res) = POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, xdmod)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = FUNCTION(DATA_NAME, mod)(POINT2D_X(x), POINT2D_X(y));
  POINT2D_Y(res) = POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, xdpow)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = FUNCTION(DATA_NAME, pow)(POINT2D_X(x), POINT2D_X(y));
  POINT2D_Y(res) = POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, ydadd)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x);
  POINT2D_Y(res) = POINT2D_Y(x) + POINT2D_Y(y);

  return res;
}

TYPE FUNCTION(NAME, ydsub)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x);
  POINT2D_Y(res) = POINT2D_Y(x) - POINT2D_Y(y);

  return res;
}

TYPE FUNCTION(NAME, ydmul)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x);
  POINT2D_Y(res) = POINT2D_Y(x) * POINT2D_Y(y);

  return res;
}

TYPE FUNCTION(NAME, yddiv)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x);
  POINT2D_Y(res) = POINT2D_Y(x) / POINT2D_Y(y);

  return res;
}

TYPE FUNCTION(NAME, ydmod)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x);
  POINT2D_Y(res) = FUNCTION(DATA_NAME, mod)(POINT2D_Y(x), POINT2D_Y(y));

  return res;
}

TYPE FUNCTION(NAME, ydpow)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x);
  POINT2D_Y(res) = FUNCTION(DATA_NAME, pow)(POINT2D_Y(x), POINT2D_Y(y));

  return res;
}

TYPE FUNCTION(NAME, dmul)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) * POINT2D_X(y);
  POINT2D_Y(res) = POINT2D_Y(x) * POINT2D_Y(y);

  return res;
}

TYPE FUNCTION(NAME, ddiv)(const TYPE x, const TYPE y) {
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
  const DATA_TYPE y_inv = 1.0 / y;
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) * y_inv;
  POINT2D_Y(res) = POINT2D_Y(x) * y_inv;

  return res;
}

TYPE FUNCTION(NAME, modf)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = FUNCTION(DATA_NAME, mod)(POINT2D_X(x), y);
  POINT2D_Y(res) = FUNCTION(DATA_NAME, mod)(POINT2D_Y(x), y);

  return res;
}

TYPE FUNCTION(NAME, powf)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = FUNCTION(DATA_NAME, pow)(POINT2D_X(x), y);
  POINT2D_Y(res) = FUNCTION(DATA_NAME, pow)(POINT2D_Y(x), y);

  return res;
}

TYPE FUNCTION(NAME, addx)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) + y;
  POINT2D_Y(res) = POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, subx)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) - y;
  POINT2D_Y(res) = POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, mulx)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) * y;
  POINT2D_Y(res) = POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, divx)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x) / y;
  POINT2D_Y(res) = POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, modx)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = FUNCTION(DATA_NAME, mod)(POINT2D_X(x), y);
  POINT2D_Y(res) = POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, powx)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = FUNCTION(DATA_NAME, pow)(POINT2D_X(x), y);
  POINT2D_Y(res) = POINT2D_Y(x);

  return res;
}

TYPE FUNCTION(NAME, addy)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x);
  POINT2D_Y(res) = POINT2D_Y(x) + y;

  return res;
}

TYPE FUNCTION(NAME, suby)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x);
  POINT2D_Y(res) = POINT2D_Y(x) - y;

  return res;
}

TYPE FUNCTION(NAME, muly)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x);
  POINT2D_Y(res) = POINT2D_Y(x) * y;

  return res;
}

TYPE FUNCTION(NAME, divy)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x);
  POINT2D_Y(res) = POINT2D_Y(x) / y;

  return res;
}

TYPE FUNCTION(NAME, mody)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x);
  POINT2D_Y(res) = FUNCTION(DATA_NAME, mod)(POINT2D_Y(x), y);

  return res;
}

TYPE FUNCTION(NAME, powy)(const TYPE x, const DATA_TYPE y) {
  TYPE res;
  POINT2D_X(res) = POINT2D_X(x);
  POINT2D_Y(res) = FUNCTION(DATA_NAME, pow)(POINT2D_Y(x), y);

  return res;
}

/* res = [[cosy -siny], [siny cosy]] x */
TYPE FUNCTION(NAME, rotl)(const TYPE x, const DATA_TYPE angle) {
  const DATA_TYPE sin_angle = sin(angle), cos_angle = cos(angle);
  TYPE res;
  POINT2D_X(res) = cos_angle * POINT2D_X(x) - sin_angle * POINT2D_Y(x);
  POINT2D_Y(res) = sin_angle * POINT2D_X(x) + cos_angle * POINT2D_Y(x);

  return res;
}

/* res = [[cosy -siny], [siny cosy]] x */
TYPE FUNCTION(NAME, rotr)(const TYPE x, const DATA_TYPE angle) {
  return FUNCTION(NAME, rotl)(x, -angle);
}

cgraph_bool_t FUNCTION(NAME, istriangle)(const TYPE a, const TYPE b,
                                         const TYPE c) {
  const DATA_TYPE mul0 = (POINT2D_X(b) - POINT2D_X(a)) *
                         (POINT2D_Y(c) - POINT2D_Y(a)),
                  mul1 = (POINT2D_X(c) - POINT2D_X(a)) *
                         (POINT2D_Y(b) - POINT2D_Y(a));

  return DATA_NE(mul0, mul1);
}

/* three point concurrent fofmula (x2-x1)(y3-y1)=(x3-x1)(y2-y1) */
cgraph_bool_t FUNCTION(NAME, isconcurrent)(const TYPE a, const TYPE b,
                                           const TYPE c) {
  const DATA_TYPE mul0 = (POINT2D_X(b) - POINT2D_X(a)) *
                         (POINT2D_Y(c) - POINT2D_Y(a)),
                  mul1 = (POINT2D_X(c) - POINT2D_X(a)) *
                         (POINT2D_Y(b) - POINT2D_Y(a));

  return DATA_EQ(mul0, mul1);
}

cgraph_bool_t FUNCTION(NAME, iscoplanar)(const TYPE a, const TYPE b,
                                         const TYPE c) {
  return CGRAPH_TRUE;
}

/* triangle size fofmula S = 0.5 * |(x2-x1)(y3-y1)-(x3-x1)(y2-y1)| */
DATA_TYPE FUNCTION(NAME, triangle_size)(const TYPE a, const TYPE b,
                                        const TYPE c) {
  const DATA_TYPE mul0 = (POINT2D_X(b) - POINT2D_X(a)) *
                         (POINT2D_Y(c) - POINT2D_Y(a)),
                  mul1 = (POINT2D_X(c) - POINT2D_X(a)) *
                         (POINT2D_Y(b) - POINT2D_Y(a));

  return 0.5 * FUNCTION(DATA_NAME, abs)(mul0 - mul1);
}

TYPE FUNCTION(NAME, triangle_gcenter)(const TYPE a, const TYPE b,
                                      const TYPE c) {
  TYPE res = FUNCTION(NAME, add)(FUNCTION(NAME, add)(a, b), c);

  return FUNCTION(NAME, divf)(res, 3.0);
}

/**
 * Given P1(x1, y1), P2(x2, y2) and P3(x3, y3), the circle among them is defined
 * as AX2 + Ay2 + Bx + Cy + D = 0
 * where
 * A = x1*(y2 - y3) - y1*(x2 - x3) + x2*y3 - x3*y2
 * B = (x1*x1 + y1*y1)*(y3 - y2) + (x2*x2 + y2*y2)*(y1 - y3) + (x3*x3 + y3*y3) *
 * (y2 - y1)
 * C = (x1*x1 + y1*y1)*(x2 - x3) + (x2*x2 + y2*y2)*(x3 - x1) + (x3*x3 + y3*y3) *
 * (x1 - x2)
 * D = (x1*x1 + y1*y1)*(x3*y2 - x2*y3) + (x2*x2 + y2*y2)*(x1*y3 -
 * x3*y1) + (x3*x3 + y3*y3)*(x2*y1 - x1*y2)
 * The circle details is
 * x = -B/2A
 * y = -C/2A
 * r = sqrt((B*B+C*C-4*A*D)/(4*A*A))
 */
TYPE FUNCTION(NAME, circle_center)(const TYPE x, const TYPE y, const TYPE z) {
  const DATA_TYPE sx2 =
                      POINT2D_X(x) * POINT2D_X(x) + POINT2D_Y(x) * POINT2D_Y(x),
                  sy2 =
                      POINT2D_X(y) * POINT2D_X(y) + POINT2D_Y(y) * POINT2D_Y(y),
                  sz2 =
                      POINT2D_X(z) * POINT2D_X(z) + POINT2D_Y(z) * POINT2D_Y(z),
                  dx_yz = POINT2D_X(y) - POINT2D_X(z),
                  dy_yz = POINT2D_Y(y) - POINT2D_Y(z);

  const DATA_TYPE A = POINT2D_X(x) * dy_yz - POINT2D_Y(x) * dx_yz +
                      POINT2D_X(y) * POINT2D_Y(z) - POINT2D_X(z) * POINT2D_Y(y),
                  B = sx2 * (-dy_yz) + sy2 * (POINT2D_Y(x) - POINT2D_Y(z)) +
                      sz2 * (POINT2D_Y(y) - POINT2D_Y(x)),
                  C = sx2 * dx_yz + sy2 * (POINT2D_X(z) - POINT2D_X(x)) +
                      sz2 * (POINT2D_X(x) - POINT2D_X(y));
  const DATA_TYPE A_1_half = 0.5 / A;
  TYPE res;
  POINT2D_X(res) = -B * A_1_half;
  POINT2D_Y(res) = -C * A_1_half;

  return res;
}

DATA_TYPE FUNCTION(NAME, circle_radius)(const TYPE x, const TYPE y,
                                        const TYPE z) {
  const DATA_TYPE sx2 =
                      POINT2D_X(x) * POINT2D_X(x) + POINT2D_Y(x) * POINT2D_Y(x),
                  sy2 =
                      POINT2D_X(y) * POINT2D_X(y) + POINT2D_Y(y) * POINT2D_Y(y),
                  sz2 =
                      POINT2D_X(z) * POINT2D_X(z) + POINT2D_Y(z) * POINT2D_Y(z),
                  dx_yz = POINT2D_X(y) - POINT2D_X(z),
                  dy_yz = POINT2D_Y(y) - POINT2D_Y(z);

  const DATA_TYPE A = POINT2D_X(x) * dy_yz - POINT2D_Y(x) * dx_yz +
                      POINT2D_X(y) * POINT2D_Y(z) - POINT2D_X(z) * POINT2D_Y(y),
                  B = sx2 * (-dy_yz) + sy2 * (POINT2D_Y(x) - POINT2D_Y(z)) +
                      sz2 * (POINT2D_Y(y) - POINT2D_Y(x)),
                  C = sx2 * dx_yz + sy2 * (POINT2D_X(z) - POINT2D_X(x)) +
                      sz2 * (POINT2D_X(x) - POINT2D_X(y)),
                  D = sx2 * (POINT2D_X(z) * POINT2D_Y(y) -
                             POINT2D_X(y) * POINT2D_Y(z)) +
                      sy2 * (POINT2D_X(x) * POINT2D_Y(z) -
                             POINT2D_X(z) * POINT2D_Y(x)) +
                      sz2 * (POINT2D_X(y) * POINT2D_Y(x) -
                             POINT2D_X(x) * POINT2D_Y(y));

  return sqrt((B * B + C * C - 4.0 * A * D) / (4 * A * A));
}

/**
 * @brief Park Transfer: alpha-beta to d-q
 * [ud, uq] = m*[[cos(angle), sin(angle)], [-sin(angle), cos(angle)]] * [ua, ub]
 */
TYPE FUNCTION(NAME, park)(const TYPE x, const DATA_TYPE m,
                          const DATA_TYPE angle) {
  const DATA_TYPE cos_angle = cos(angle), sin_angle = sin(angle);
  TYPE res;
  POINT2D_X(res) = m * (POINT2D_X(x) * cos_angle + POINT2D_Y(x) * sin_angle);
  POINT2D_Y(res) = m * (-POINT2D_X(x) * sin_angle + POINT2D_Y(x) * cos_angle);

  return res;
}

/**
 * @brief Park Inverse Transfer: d-q to alpha-beta
 * [ua, ub] = m*[[cos(angle), -sin(angle)], [sin(angle), cos(angle)]] * [ud, uq]
 */
TYPE FUNCTION(NAME, park_inv)(const TYPE x, const DATA_TYPE m,
                              const DATA_TYPE angle) {
  const DATA_TYPE cos_angle = cos(angle), sin_angle = sin(angle);
  TYPE res;
  POINT2D_X(res) = m * (POINT2D_X(x) * cos_angle - POINT2D_Y(x) * sin_angle);
  POINT2D_Y(res) = m * (POINT2D_X(x) * sin_angle + POINT2D_Y(x) * cos_angle);

  return res;
}

/**
 * @brief Line Equation
 * Given P1(x1, y1) and P2(x2, y2), the line between P1 and P2 can be defined as
 * Ax + By + C = 0
 * where
 * A = y2 - y1
 * B = x1 - x2
 * C = x2*y1 - x1*y2
 */
TYPE FUNCTION(NAME, line)(const TYPE x, const TYPE y, DATA_TYPE *z) {
  TYPE res;
  POINT2D_X(res) = POINT2D_Y(y) - POINT2D_Y(x);
  POINT2D_Y(res) = POINT2D_X(x) - POINT2D_X(y);
  if (NULL != z) {
    *z = POINT2D_X(y) * POINT2D_Y(x) - POINT2D_X(x) * POINT2D_Y(y);
  }

  return res;
}