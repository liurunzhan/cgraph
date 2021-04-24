#include "cgraph_base.h"
#include "cgraph_bitset.h"
#include "cgraph_int8.h"

#define TYPE_BITSET
#include "cgraph_template.h"

/** template module */
#include "template_data.ct"

cgraph_size_t FUNCTION(NAME, fprint)(FILE *fp, const TYPE *cthis) {
  cgraph_size_t len = 0;
  if (NULL != cthis) {
    cgraph_size_t i;
    DATA_TYPE *data = &(cthis->data[0]);
    for (i = 0; i < cthis->len; i++, data++) {
      fputc(cgraph_math_dec2lhex((*data >> 4) & 0xF, NULL), fp);
      fputc(cgraph_math_dec2lhex(*data & 0xF, NULL), fp);
    }
    len = cthis->len;
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, snprint)(cgraph_char_t *buffer,
                                      const cgraph_size_t size,
                                      const TYPE *cthis) {
  cgraph_size_t len = 0;
  if ((NULL != buffer) && (NULL != cthis)) {
    cgraph_size_t i = 0, _len = CGRAPH_MIN(size >> 1, cthis->len);
    DATA_TYPE *data = &(cthis->data[0]);
    for (i = 0; i < _len; data++) {
      buffer[i++] = cgraph_math_dec2lhex((*data >> 4) & 0xF, NULL);
      buffer[i++] = cgraph_math_dec2lhex(*data & 0xF, NULL);
    }
  }

  return len;
}

static const cgraph_uint8_t cgraph_uint8_bits[8] = {0x01, 0x02, 0x04, 0x08,
                                                    0x10, 0x20, 0x40, 0x80};

cgraph_size_t FUNCTION(NAME, hash)(const TYPE *cthis) {
  cgraph_size_t hash = 0;
  if (NULL != cthis) {
    cgraph_size_t i;
    DATA_TYPE *data = &(cthis->data[0]);
    for (i = 0; i < cthis->len; i++, data++) {
      hash = (hash << 4) ^ (hash >> 28) ^ *data;
    }
  }

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis) {
  return CGRAPH_TEST((NULL != cthis) && (0 < cthis->len));
}

CGRAPH_INLINE cgraph_int_t FUNCTION(NAME, signbit)(const TYPE *cthis) {
  return CGRAPH_TEST(NULL != cthis);
}

TYPE *FUNCTION(NAME, bit)(const TYPE *cthis, const cgraph_size_t postion) {
  TYPE *res = FUNCTION(NAME, calloc)(DATA_ID, 1);
  if (NULL != res) {
    res->data[0] = BITSET_GET_BIT(cthis, postion);
    res->len = 1;
  }

  return res;
}

TYPE *FUNCTION(NAME, set)(TYPE *cthis, const cgraph_size_t postion) {
  if (NULL != cthis) {
    cgraph_size_t i = BITSET_BYTE_POSTION(postion),
                  j = BITSET_BIT_POSTION(postion);
    DATA_TYPE tmp = cthis->data[i], left_bits = ((tmp >> (j + 1)) << (j + 1)),
              right_bits = ((j == 0) ? 0 : (tmp ^ (~((DATA_ONES >> j) << j))));
    cthis->data[i] = left_bits + right_bits + (1 << j);
  }

  return cthis;
}

TYPE *FUNCTION(NAME, clr)(TYPE *cthis, const cgraph_size_t pos) {
  if (NULL != cthis) {
    cgraph_size_t i = pos / DATA_BITS, j = pos % DATA_BITS;
    DATA_TYPE tmp = cthis->data[i], left_bits = ((tmp >> (j + 1)) << (j + 1)),
              right_bits = ((j == 0) ? 0 : (tmp ^ (~((DATA_ONES >> j) << j))));
    cthis->data[i] = left_bits + right_bits;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, bits)(const TYPE *cthis, const cgraph_size_t min,
                           const cgraph_size_t max) {
  TYPE *res = NULL;
  if (NULL != cthis) {
  }

  return res;
}

TYPE *FUNCTION(NAME, sets)(TYPE *cthis, const cgraph_size_t min,
                           const cgraph_size_t max) {
  return cthis;
}

TYPE *FUNCTION(NAME, clrs)(TYPE *cthis, const cgraph_size_t min,
                           const cgraph_size_t max) {
  return cthis;
}

TYPE *FUNCTION(NAME, swapbit)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i, j;
    DATA_TYPE byte;
    for (i = 0, j = cthis->len - 1; i < j; i++, j--) {
      byte = cthis->data[i];
      cthis->data[i] = cgraph_int8_swapbit(cthis->data[j]);
      cthis->data[j] = cgraph_int8_swapbit(byte);
    }
    if (i == j) {
      cthis->data[i] = cgraph_int8_swapbit(cthis->data[i]);
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, swapbyte)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i, j;
    for (i = 0, j = cthis->len - 1; i < j; i++, j--) {
      DATA_SWAP(cthis->data[i], cthis->data[j]);
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, swaphfwd)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i, j;
    for (i = 0, j = cthis->len - 1; i < j; i += 2, j -= 2) {
      DATA_SWAP(cthis->data[i], cthis->data[j - 1]);
      DATA_SWAP(cthis->data[i + 1], cthis->data[j]);
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, swapword)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i, j;
    for (i = 0, j = cthis->len - 1; i < j; i += 4, j -= 4) {
      DATA_SWAP(cthis->data[i], cthis->data[j - 3]);
      DATA_SWAP(cthis->data[i + 1], cthis->data[j - 2]);
      DATA_SWAP(cthis->data[i + 2], cthis->data[j - 1]);
      DATA_SWAP(cthis->data[i + 3], cthis->data[j]);
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
    if (CGRAPH_FALSE == error) {
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
      cgraph_size_t i = 0;
      z->len = len;
      for (i = 0; i < len; i++, xd++, yd++, zd++) {
        *zd = CGRAPH_XOR(*xd, *yd);
      }
      for (; i < x->len; xd++, zd++) {
        *zd = CGRAPH_NOT(*xd);
      }
      for (; i < y->len; yd++, zd++) {
        *zd = CGRAPH_NOT(*yd);
      }
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z) {
  return FUNCTION(NAME, add)(x, y, z);
}

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z) {
  return FUNCTION(NAME, and)(x, y, z);
}

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z) {
  return FUNCTION(NAME, or)(x, y, z);
}

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y) && (x->len == y->len)) {
    DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]);
    cgraph_size_t i;
    for (flag = CGRAPH_TRUE, i = 0; i < x->len; i++, xd++, yd++) {
      if (*xd != *yd) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  } else if ((NULL == x) && (NULL == y)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ne)(const TYPE *x, const TYPE *y) {
  return CGRAPH_NTEST(FUNCTION(NAME, eq)(x, y));
}

cgraph_bool_t FUNCTION(NAME, gr)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    if (x->len > y->len) {
      flag = CGRAPH_TRUE;
    } else if (x->len == y->len) {
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ge)(const TYPE *x, const TYPE *y) {
  return CGRAPH_NTEST(FUNCTION(NAME, ls)(x, y));
}

cgraph_bool_t FUNCTION(NAME, ls)(const TYPE *x, const TYPE *y) {
  return FUNCTION(NAME, gr)(y, x);
}

cgraph_bool_t FUNCTION(NAME, le)(const TYPE *x, const TYPE *y) {
  return CGRAPH_NTEST(FUNCTION(NAME, gr)(x, y));
}

TYPE *FUNCTION(NAME, and)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
    if (CGRAPH_FALSE == error) {
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
      cgraph_size_t i = 0;
      for (i = 0; i < len; i++, xd++, yd++, zd++) {
        *zd = CGRAPH_AND(*xd, *yd);
      }
      cgraph_memset(zd, x->len - i, 0);
      cgraph_memset(zd, y->len - i, 0);
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, or)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
    if (CGRAPH_FALSE == error) {
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
      cgraph_size_t i = 0;
      for (i = 0; i < len; i++, xd++, yd++, zd++) {
        *zd = CGRAPH_OR(*xd, *yd);
      }
      cgraph_memcpy(zd, xd, x->len - i);
      cgraph_memcpy(zd, yd, y->len - i);
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, xor)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
    if (CGRAPH_FALSE == error) {
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
      cgraph_size_t i = 0;
      for (i = 0; i < len; i++, xd++, yd++, zd++) {
        *zd = CGRAPH_XOR(*xd, *yd);
      }
      for (i = 0; i < x->len; i++, xd++, zd++) {
        *zd = CGRAPH_NOT(*xd);
      }
      for (i = 0; i < y->len; i++, yd++, zd++) {
        *zd = CGRAPH_NOT(*yd);
      }
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, xnor)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
    if (CGRAPH_FALSE == error) {
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
      cgraph_size_t i = 0;
      for (i = 0; i < len; i++, xd++, yd++, zd++) {
        *zd = CGRAPH_XNOR(*xd, *yd);
      }
      cgraph_memcpy(zd, xd, x->len - i);
      cgraph_memcpy(zd, yd, y->len - i);
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, not )(const TYPE *x, TYPE *y) {
  if (NULL != x) {
    cgraph_size_t len = x->len;
    cgraph_bool_t error = CGRAPH_FALSE;
    y = FUNCTION(NAME, realloc)(y, DATA_ID, 0, len, &error);
    if (CGRAPH_FALSE == error) {
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]);
      cgraph_size_t i = 0;
      for (i = 0; i < len; i++, xd++, yd++) {
        *yd = CGRAPH_NOT(*xd);
      }
    }
  }

  return y;
}

TYPE *FUNCTION(NAME, abs)(TYPE *cthis) { return cthis; }

TYPE *FUNCTION(NAME, opp)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i;
    DATA_TYPE *data = &(cthis->data[0]);
    for (i = 0; i < cthis->len; i++, data++) {
      *data = CGRAPH_NOT(*data);
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, unit)(TYPE *cthis, const cgraph_size_t len) {
  if (NULL != cthis) {
    cgraph_size_t _len = CGRAPH_MIN(cthis->len, len);
    cgraph_memset(cthis->data, DATA_MAX, _len);
    cthis->len = _len;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, unit_inv)(TYPE *cthis, const cgraph_size_t len) {
  return FUNCTION(NAME, unit)(cthis, len);
}

TYPE *FUNCTION(NAME, ceil)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, 0);
}

TYPE *FUNCTION(NAME, floor)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, 0);
}

TYPE *FUNCTION(NAME, pow)(const TYPE *x, const TYPE *y, TYPE *z) {
  return FUNCTION(NAME, init)(z, x, 0);
}

TYPE *FUNCTION(NAME, sin)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, 0);
}

TYPE *FUNCTION(NAME, cos)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, 0);
}

TYPE *FUNCTION(NAME, tan)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, 0);
}

TYPE *FUNCTION(NAME, asin)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, 0);
}

TYPE *FUNCTION(NAME, acos)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, 0);
}

TYPE *FUNCTION(NAME, atan)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, 0);
}

TYPE *FUNCTION(NAME, sinh)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, 0);
}

TYPE *FUNCTION(NAME, cosh)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, 0);
}

TYPE *FUNCTION(NAME, tanh)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, 0);
}

TYPE *FUNCTION(NAME, log)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, 0);
}

TYPE *FUNCTION(NAME, log2)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, 0);
}

TYPE *FUNCTION(NAME, log10)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, 0);
}

TYPE *FUNCTION(NAME, exp)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, 0);
}

TYPE *FUNCTION(NAME, sqrt)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, 0);
}

#include "cgraph_template_off.h"
