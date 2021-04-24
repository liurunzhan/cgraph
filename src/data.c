#include "cgraph_data.h"

static const cgraph_char_t *__cgraph_true__ = CGRAPH_BOOL_TRUE;
static const cgraph_size_t __cgraph_true_len__ = CGRAPH_BOOL_TRUE_LEN;
static const cgraph_size_t __cgraph_true_size__ = (__cgraph_true_len__ + 1);
static const cgraph_char_t *__cgraph_false__ = CGRAPH_BOOL_FALSE;
static const cgraph_size_t __cgraph_false_len__ = CGRAPH_BOOL_FALSE_LEN;
static const cgraph_size_t __cgraph_false_size__ = (__cgraph_false_len__ + 1);

cgraph_string_t *cgraph_bool_to_string(const cgraph_bool_t x) {
  cgraph_string_t *cthis = NULL;
  if (CGRAPH_TRUE == x) {
    cthis = cgraph_string_calloc(CGRAPH_CHAR_T, __cgraph_true_size__);
    if (NULL != cthis) {
      cgraph_string_initd(cthis, __cgraph_true__, __cgraph_true_size__);
      cthis->len = __cgraph_true_len__;
    }
  } else if (CGRAPH_FALSE == x) {
    cthis = cgraph_string_calloc(CGRAPH_CHAR_T, __cgraph_false_size__);
    if (NULL != cthis) {
      cgraph_string_initd(cthis, __cgraph_false__, __cgraph_false_size__);
      cthis->len = __cgraph_false_len__;
    }
  }

  return cthis;
}

cgraph_bool_t cgraph_string_to_bool(const cgraph_string_t *cthis) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if (NULL != cthis) {
    res = cgraph_bool_str2bool(cthis->data, cthis->len);
  }

  return res;
}

cgraph_string_t *cgraph_bigint_to_string(const cgraph_bigint_t *cthis) {
  cgraph_string_t *string = NULL;
  if (NULL != cthis) {
    cgraph_size_t size = cthis->len * 3 + 2;
    string = cgraph_string_calloc(CGRAPH_CHAR_T, size);
    if (NULL != string) {
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
    bigint = cgraph_bigint_calloc(CGRAPH_INT8_T, size);
    if ((NULL != tmp) && (NULL != bigint)) {
      bigint = cgraph_bigint_initc(bigint, tmp->data, tmp->size, cthis->data);
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
