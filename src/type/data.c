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
