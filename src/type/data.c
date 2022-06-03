#include "cgraph_data.h"
#include "cgraph_math.h"
#include "cgraph_memory.h"

cgraph_logic_t cgraph_bool_to_logic(const cgraph_bool_t x) { return x; }

cgraph_bool_t cgraph_logic_to_bool(const cgraph_logic_t x) {
  return (CGRAPH_L1 == x) ? CGRAPH_TRUE : CGRAPH_FALSE;
}

cgraph_string_t *cgraph_bool_to_string(const cgraph_bool_t x) {

  cgraph_char_t *data = cgraph_bool_encode(x);
  cgraph_size_t len = cgraph_strlen(data);
  cgraph_string_t *cthis = cgraph_string_calloc(CGRAPH_CHAR_T, len);
  if (NULL != cthis) {
    cgraph_string_initdt(cthis, data, len);
    cthis->len = len;
  }

  return cthis;
}

cgraph_bool_t cgraph_string_to_bool(const cgraph_string_t *cthis) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if (NULL != cthis) {
    res = cgraph_bool_decode(cthis->data, cthis->len, NULL);
  }

  return res;
}

cgraph_string_t *cgraph_bigint_to_string(const cgraph_bigint_t *cthis) {
  cgraph_string_t *string = NULL;
  if (NULL != cthis) {
    cgraph_size_t size = cthis->len * 3 + 2;
    if (NULL != (string = cgraph_string_calloc(CGRAPH_CHAR_T, size))) {
      string->len = cgraph_bigint_snprint(string->data, string->size, cthis);
    }
  }

  return string;
}

cgraph_bigint_t *cgraph_string_to_bigint(const cgraph_string_t *cthis) {
  cgraph_bigint_t *bigint = NULL;
  if (NULL != cthis) {
    cgraph_string_t *tmp = cgraph_string_copy(cthis, cthis->len);
    cgraph_size_t size = cthis->len / 3 + 2;
    if ((NULL != tmp) &&
        (NULL != (bigint = cgraph_bigint_calloc(CGRAPH_UINT8_T, size)))) {
      bigint = cgraph_bigint_initc(bigint, tmp->data, cthis->data, cthis->len);
    }
    cgraph_string_free(tmp);
  }

  return bigint;
}

const cgraph_char_t _cgraph_base64_array_[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

cgraph_string_t *cgraph_bitset_to_string_base64_encode(const cgraph_bitset_t *x,
                                                       cgraph_string_t *y) {
  return y;
}

cgraph_bignum_t *cgraph_bigint_to_bignum(const cgraph_bigint_t *cthis) {
  cgraph_bignum_t *bignum = NULL;
  if (NULL != cthis) {
    cgraph_size_t len = cthis->len / 3 + 2;
    if (NULL != (bignum = cgraph_bignum_calloc(CGRAPH_UINT8_T, len))) {
      bignum->postive = cthis->postive;
      bignum->point = 0;
    }
  }

  return bignum;
}

cgraph_bigint_t *cgraph_bignum_to_bigint(const cgraph_bignum_t *cthis) {
  cgraph_bigint_t *bigint = NULL;
  if (NULL != cthis) {
    cgraph_size_t len = cthis->len * 3 + 1;
    if (NULL != (bigint = cgraph_bigint_calloc(CGRAPH_UINT8_T, len))) {
      bigint->postive = cthis->postive;
    }
  }

  return bigint;
}

cgraph_bitset_t *cgraph_bigint_to_bitset(const cgraph_bigint_t *cthis) {
  cgraph_bitset_t *bitset = NULL;
  if ((NULL != cthis) &&
      (NULL != (bitset = cgraph_bitset_calloc(CGRAPH_UINT8_T, cthis->len)))) {
    cgraph_memcpy(bitset->data, cthis->data, cthis->len);
    bitset->len = cthis->len;
  }

  return bitset;
}

cgraph_bigint_t *cgraph_bitset_to_bigint(const cgraph_bitset_t *cthis) {
  cgraph_bigint_t *bigint = NULL;
  if ((NULL != cthis) &&
      (NULL != (bigint = cgraph_bigint_calloc(CGRAPH_UINT8_T, cthis->len)))) {
    cgraph_memcpy(bigint->data, cthis->data, cthis->len);
    bigint->len = cthis->len;
  }

  return bigint;
}

cgraph_bigint_t *cgraph_string_md5(const cgraph_string_t *cthis) {
#define MD5_A UINT32_C(0x67452301)
#define MD5_B UINT32_C(0xEFCDAB89)
#define MD5_C UINT32_C(0x98BADCFE)
#define MD5_D UINT32_C(0x10325476)
#define MD5_F(x, y, z) (((x) & (y)) | ((~(x)) & (z)))
#define MD5_G(x, y, z) (((x) & (z)) | ((y) & (~(z))))
#define MD5_H(x, y, z) ((x) ^ (y) ^ (z))
#define MD5_I(x, y, z) ((y) ^ ((x) | (~(z))))
#define MD5_BITS (32)
#define MD5_ROTL(x, bits) CGRAPH_ROTL(x, MD5_BITS, bits)
#define MD5_FF(a, b, c, d, x, s, ac)                                           \
  do {                                                                         \
    (a) += F(b, c, d) + (x) + (cgraph_uint32_t)(ac);                           \
    (a) = MD5_ROTL(a, s);                                                      \
    (a) += (b);                                                                \
  } while (0)
#define MD5_GG(a, b, c, d, x, s, ac)                                           \
  do {                                                                         \
    (a) += G(b, c, d) + (x) + (cgraph_uint32_t)(ac);                           \
    (a) = MD5_ROTL(a, s);                                                      \
    (a) += (b);                                                                \
  } while (0)
#define MD5_HH(a, b, c, d, x, s, ac)                                           \
  do {                                                                         \
    (a) += H(b, c, d) + (x) + (cgraph_uint32_t)(ac);                           \
    (a) = MD5_ROTL(a, s);                                                      \
    (a) += (b);                                                                \
  } while (0)
#define MD5_II(a, b, c, d, x, s, ac)                                           \
  do {                                                                         \
    (a) += I(b, c, d) + (x) + (cgraph_uint32_t)(ac);                           \
    (a) = MD5_ROTL(a, s);                                                      \
    (a) += (b);                                                                \
  } while (0)
  cgraph_bigint_t *bigint = NULL;
  if ((NULL != cthis) &&
      (NULL != (bigint = cgraph_bigint_calloc(CGRAPH_UINT8_T, 16)))) {
  }

  return bigint;
#undef MD5_A
#undef MD5_B
#undef MD5_C
#undef MD5_D
#undef MD5_F
#undef MD5_G
#undef MD5_H
#undef MD5_I
#undef MD5_BITS
#undef MD5_ROTL
#undef MD5_FF
#undef MD5_GG
#undef MD5_HH
#undef MD5_II
}

cgraph_bigint_t *cgraph_string_sha1(const cgraph_string_t *cthis) {
#define SHA1_K_0_19 UINT32_C(0x5A827999)
#define SHA1_K_20_39 UINT32_C(0x6ED9EBA1)
#define SHA1_K_40_59 UINT32_C(0x8F1BBCDC)
#define SHA1_K_60_79 UINT32_C(0xCA62C1D6)
#define SHA1_F_0_19(b, c, d) (((b) & (c)) | ((~(b)) & (d)))
#define SHA1_F_20_39(b, c, d) ((b) ^ (c) ^ (d))
#define SHA1_F_40_59(b, c, d) (((b) & (c)) | ((b) & (d)) | ((c) & (d)))
#define SHA1_F_60_79(b, c, d) ((b) ^ (c) ^ (d))
  cgraph_bigint_t *bigint = NULL;
  if ((NULL != cthis) &&
      (NULL != (bigint = cgraph_bigint_calloc(CGRAPH_UINT8_T, 20)))) {
  }

  return bigint;
#undef SHA1_K_0_19
#undef SHA1_K_20_39
#undef SHA1_K_40_59
#undef SHA1_K_60_79
#undef SHA1_F_0_19
#undef SHA1_F_20_39
#undef SHA1_F_40_59
#undef SHA1_F_60_79
}

cgraph_float16_t cgraph_float8_to_float16(const cgraph_float8_t x) {
  cgraph_float16_t res;

  return res;
}

cgraph_float32_t cgraph_float8_to_float32(const cgraph_float8_t x) {
  cgraph_float32_t res;

  return res;
}

cgraph_float64_t cgraph_float8_to_float64(const cgraph_float8_t x) {
  cgraph_float64_t res;

  return res;
}

cgraph_float128_t cgraph_float8_to_float128(const cgraph_float8_t x) {
  cgraph_float128_t res;

  return res;
}

cgraph_float8_t cgraph_float16_to_float8(const cgraph_float16_t x) {
  cgraph_float8_t res;

  return res;
}

cgraph_float32_t cgraph_float16_to_float32(const cgraph_float16_t x) {
  cgraph_float32_t res;

  return res;
}

cgraph_float64_t cgraph_float16_to_float64(const cgraph_float16_t x) {
  cgraph_float64_t res;

  return res;
}

cgraph_float128_t cgraph_float16_to_float128(const cgraph_float16_t x) {
  cgraph_float128_t res;

  return res;
}

cgraph_float8_t cgraph_float32_to_float8(const cgraph_float32_t x) {
  cgraph_float8_t res;

  return res;
}

cgraph_float16_t cgraph_float32_to_float16(const cgraph_float32_t x) {
  cgraph_float16_t res;

  return res;
}

cgraph_float64_t cgraph_float32_to_float64(const cgraph_float32_t x) {
  cgraph_float64_t res;

  return res;
}

cgraph_float128_t cgraph_float32_to_float128(const cgraph_float32_t x) {
  cgraph_float128_t res;

  return res;
}

cgraph_float8_t cgraph_float64_to_float8(const cgraph_float64_t x) {
  cgraph_float8_t res;

  return res;
}

cgraph_float16_t cgraph_float64_to_float16(const cgraph_float64_t x) {
  cgraph_float16_t res;

  return res;
}

cgraph_float32_t cgraph_float64_to_float32(const cgraph_float64_t x) {
  cgraph_float32_t res;

  return res;
}

cgraph_float128_t cgraph_float64_to_float128(const cgraph_float64_t x) {
  cgraph_float128_t res;

  return res;
}

cgraph_point3d_t cgraph_point2d_xmul(const cgraph_point2d_t x,
                                     const cgraph_point2d_t y) {
  cgraph_point3d_t res = cgraph_point3d_zero();
  POINT3D_Z(res) = cgraph_point2d_fdot(x, y);

  return res;
}

cgraph_point3d_t cgraph_point2d_to_point3d(const cgraph_point2d_t x) {
  cgraph_point3d_t res = cgraph_point3d_zero();
  POINT3D_X(res) = POINT2D_X(x);
  POINT3D_Y(res) = POINT2D_Y(x);

  return res;
}

cgraph_point2d_t cgraph_point3d_to_point2d(const cgraph_point3d_t x) {
  const cgraph_float64_t z_1 = -1.0 * POINT3D_Z(x);
  cgraph_point2d_t res;
  POINT2D_X(res) = POINT3D_X(x) * z_1;
  POINT2D_Y(res) = POINT3D_Y(x) * z_1;

  return res;
}

/**
 * @brief Clarke Transfer
 * [ua, ub] = [[1, -1/2, -1/2], [0, sqrt(3)/2, -sqrt(3)/2]] * [ua, ub, uc]
 */
cgraph_point2d_t cgraph_point3d_to_point2d_clarke(const cgraph_point3d_t x,
                                                  const cgraph_float64_t m) {
  cgraph_point2d_t res;
  POINT2D_X(res) = m * (POINT3D_X(x) - 0.5 * POINT3D_Y(x) - 0.5 * POINT3D_Z(x));
  POINT2D_Y(res) =
      m * (0.5 * M_SQRT3 * POINT3D_Y(x) - 0.5 * M_SQRT3 * POINT3D_Z(x));

  return res;
}

/**
 * @brief Clarke Inverse Transfer
 * [ua, ub, uc] = m * [[1, 0], [-1/2, sqrt(3)/2], [-1/2, -sqrt(3)/2]] * [ua, ub]
 */
cgraph_point3d_t
cgraph_point2d_to_point3d_clarke_inv(const cgraph_point2d_t x,
                                     const cgraph_float64_t m) {
  cgraph_point3d_t res;
  POINT3D_X(res) = m * (POINT2D_X(x));
  POINT3D_Y(res) = m * (-0.5 * POINT2D_X(x) + 0.5 * M_SQRT3 * POINT2D_Y(x));
  POINT3D_Z(res) = m * (-0.5 * POINT2D_X(x) - 0.5 * M_SQRT3 * POINT2D_Y(x));

  return res;
}
