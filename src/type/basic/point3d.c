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

DATA_TYPE FUNCTION(NAME, dmin)(const TYPE x) {
  DATA_TYPE min =
      DATA_LS(POINT3D_X(x), POINT3D_Y(x)) ? POINT3D_X(x) : POINT3D_Y(x);

  return DATA_LS(min, POINT3D_Z(x)) ? min : POINT3D_Z(x);
}

DATA_TYPE FUNCTION(NAME, dmax)(const TYPE x) {
  DATA_TYPE max =
      DATA_GR(POINT3D_X(x), POINT3D_Y(x)) ? POINT3D_X(x) : POINT3D_Y(x);

  return DATA_GR(max, POINT3D_Z(x)) ? max : POINT3D_Z(x);
}

DATA_TYPE FUNCTION(NAME, dsum)(const TYPE x) {
  return POINT3D_X(x) + POINT3D_Y(x) + POINT3D_Z(x);
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

TYPE FUNCTION(NAME, rev)(const TYPE x) {
  TYPE res;
  POINT3D_X(res) = POINT3D_Z(x);
  POINT3D_Y(res) = POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_X(x);

  return res;
}

TYPE FUNCTION(NAME, trans)(const TYPE x) { return x; }

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

TYPE FUNCTION(NAME, absub)(const TYPE x, const TYPE y) {
  TYPE res;
  POINT3D_X(res) = FUNCTION(DATA_NAME, abs)(POINT3D_X(x) - POINT3D_X(y));
  POINT3D_Y(res) = FUNCTION(DATA_NAME, abs)(POINT3D_Y(x) - POINT3D_Y(y));
  POINT3D_Z(res) = FUNCTION(DATA_NAME, abs)(POINT3D_Z(x) - POINT3D_Z(y));

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

__INLINE DATA_TYPE FUNCTION(NAME, fdot)(const TYPE x, const TYPE y) {
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
  const DATA_TYPE inv_y = 1.0 / y;
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
  const DATA_TYPE cos_angle = cos(angle), sin_angle = sin(angle);
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
  const DATA_TYPE cos_angle = cos(angle), sin_angle = sin(angle);
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
  const DATA_TYPE cos_angle = cos(angle), sin_angle = sin(angle);
  TYPE res;
  POINT3D_X(res) = cos_angle * POINT3D_X(x) - sin_angle * POINT3D_Y(x);
  POINT3D_Y(res) = sin_angle * POINT3D_X(x) + cos_angle * POINT3D_Y(x);
  POINT3D_Z(res) = POINT3D_Z(x);

  return res;
}

TYPE FUNCTION(NAME, zror)(const TYPE x, const DATA_TYPE angle) {
  return FUNCTION(NAME, zrol)(x, -angle);
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