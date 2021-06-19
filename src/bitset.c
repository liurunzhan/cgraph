#include "cgraph_base.h"
#include "cgraph_bitset.h"
#include "cgraph_int8.h"

#define TYPE_BITSET
#include "cgraph_template.h"

/**   */
static const DATA_TYPE __bitset_bit_eps__[DATA_BITS] = {0x80, 0x01, 0x02, 0x04,
                                                        0x08, 0x10, 0x20, 0x40};
static const DATA_TYPE __bitset_bit_reps__[DATA_BITS] = {
    0xFF, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F};
static const DATA_TYPE __bitset_bit_leps__[DATA_BITS] = {
    0xFF, 0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80};

/** template module */
#include "template_data.ct"

cgraph_size_t FUNCTION(NAME, fprint)(FILE *fp, const TYPE *cthis) {
  return FUNCTION(NAME, fprinth)(fp, cthis);
}

cgraph_size_t FUNCTION(NAME, fprintb)(FILE *fp, const TYPE *cthis) {
  cgraph_size_t len = 0;
  if (NULL != cthis) {
    cgraph_size_t i, j;
    DATA_TYPE *data = &(cthis->data[cthis->len - 1]);
    len = 2 + ((0 < cthis->bits_num) ? (8 * (cthis->len - 1) + cthis->bits_num)
                                     : (8 * cthis->len));
    fputs("0b", fp);
    for (j = BITSET_BITS_STPOS(cthis); j < DATA_BITS; j++) {
      fputc(cgraph_math_dec2bin(*data & __bitset_bit_eps__[j]), fp);
    }
    for (i = 1, data--; i < cthis->len; i++, data--) {
      for (j = 0; j < DATA_BITS; j++) {
        fputc(cgraph_math_dec2bin(*data & __bitset_bit_eps__[j]), fp);
      }
    }
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, fprinth)(FILE *fp, const TYPE *cthis) {
  cgraph_size_t len = 0;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    DATA_TYPE *data = &(cthis->data[cthis->len - 1]);
    len = 2 + cthis->len * 2;
    fputs("0x", fp);
    if (BITSET_BITS_NUM_GRHALF(cthis)) {
      fputc(cgraph_math_dec2uhex(
                (*data >> 4) &
                __bitset_bit_reps__[BITSET_BITS_NUM_TOHALF(cthis)]),
            fp);
      fputc(cgraph_math_dec2uhex((*(data)) & 0xF), fp);
    } else {
      fputc(cgraph_math_dec2uhex(*(data)&__bitset_bit_reps__[cthis->bits_num]),
            fp);
    }
    for (i = 1, data--; i < cthis->len; i++, data--) {
      fputc(cgraph_math_dec2uhex((*data >> 4) & 0xF), fp);
      fputc(cgraph_math_dec2uhex((*data) & 0xF), fp);
    }
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, snprint)(cgraph_char_t *buffer,
                                      const cgraph_size_t size,
                                      const TYPE *cthis) {
  return FUNCTION(NAME, snprinth)(buffer, size, cthis);
}

cgraph_size_t FUNCTION(NAME, snprintb)(cgraph_char_t *buffer,
                                       const cgraph_size_t size,
                                       const TYPE *cthis) {
  cgraph_size_t len = 0;
  if ((NULL != buffer) && (NULL != cthis)) {
    cgraph_size_t i, j, _size = size - 1;
    DATA_TYPE *data = &(cthis->data[cthis->len - 1]);
    buffer[len++] = '0';
    buffer[len++] = 'b';
    for (j = BITSET_BITS_STPOS(cthis); j < DATA_BITS; j++) {
      buffer[len++] = cgraph_math_dec2bin(*data & __bitset_bit_eps__[j]);
    }
    for (i = 1, data--; (len < _size) && (i < cthis->len); data--, i++) {
      for (j = 0; j < DATA_BITS; j++) {
        buffer[len++] = cgraph_math_dec2bin(*data & __bitset_bit_eps__[j]);
      }
    }
    buffer[len] = '\0';
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, snprinth)(cgraph_char_t *buffer,
                                       const cgraph_size_t size,
                                       const TYPE *cthis) {
  cgraph_size_t len = 0;
  if ((NULL != buffer) && (NULL != cthis)) {
    cgraph_size_t i = 0, _size = size - 1;
    DATA_TYPE *data = &(cthis->data[cthis->len - 1]);
    buffer[len++] = '0';
    buffer[len++] = 'x';
    if (BITSET_BITS_NUM_GRHALF(cthis)) {
      buffer[len++] = cgraph_math_dec2uhex(
          (*data >> 4) & __bitset_bit_reps__[BITSET_BITS_NUM_TOHALF(cthis)]);
      buffer[len++] = cgraph_math_dec2uhex((*(data) >> 4) & 0xF);
    } else {
      buffer[len++] = cgraph_math_dec2uhex(
          (*(data) >> 4) & __bitset_bit_reps__[cthis->bits_num]);
    }
    for (i = 1, data--; (len < _size) && (i < cthis->len); data--, i++) {
      buffer[len++] = cgraph_math_dec2uhex((*data >> 4) & 0xF);
      buffer[len++] = cgraph_math_dec2uhex(*data & 0xF);
    }
    buffer[len] = '\0';
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, hash)(const TYPE *cthis) {
  cgraph_size_t hash = 0;
  if (NULL != cthis) {
    cgraph_size_t i;
    DATA_TYPE *data = &(cthis->data[cthis->len - 1]);
    hash = (hash << 4) ^ (hash >> 28) ^
           (*(data--) & __bitset_bit_reps__[cthis->bits_num]);
    for (i = 1; i < cthis->len; i++, data--) {
      hash = (hash << 4) ^ (hash >> 28) ^ *data;
    }
  }

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis) {
  return CGRAPH_TEST((NULL != cthis) && (0 < cthis->len) &&
                     (0 <= cthis->bits_num) && (8 > cthis->bits_num));
}

__INLINE cgraph_int_t FUNCTION(NAME, signbit)(const TYPE *cthis) {
  return CGRAPH_TEST(NULL != cthis);
}

TYPE *FUNCTION(NAME, bit)(const TYPE *cthis, const cgraph_size_t postion) {
  TYPE *res = FUNCTION(NAME, calloc)(DATA_ID, 1);
  if (NULL != res) {
    res->data[0] = BITSET_GET_BIT(cthis, postion);
    res->len = 1;
    res->bits_num = 1;
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

TYPE *FUNCTION(NAME, clr)(TYPE *cthis, const cgraph_size_t postion) {
  if (NULL != cthis) {
    cgraph_size_t i = postion / DATA_BITS, j = postion % DATA_BITS;
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
  if (NULL != cthis) {
  }

  return cthis;
}

TYPE *FUNCTION(NAME, clrs)(TYPE *cthis, const cgraph_size_t min,
                           const cgraph_size_t max) {
  if (NULL != cthis) {
  }

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
    cgraph_size_t max_len = CGRAPH_MAX(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, max_len, &error);
    if (CGRAPH_FALSE == error) {
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
      cgraph_size_t i = 0, min_len = CGRAPH_MIN(x->len, y->len);
      z->len = max_len;
      for (; i < min_len; i++, xd++, yd++, zd++) {
        *zd = CGRAPH_XOR(*xd, *yd);
      }
      for (; i < x->len; i++, xd++, zd++) {
        *zd = CGRAPH_NOT(*xd);
      }
      for (; i < y->len; i++, yd++, zd++) {
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
  if ((NULL != x) && (NULL != y) && (x->len == y->len) &&
      (x->bits_num == y->bits_num)) {
    DATA_TYPE *xd = &(x->data[x->len - 1]), *yd = &(y->data[y->len - 1]);
    DATA_TYPE xd_bits = *xd & __bitset_bit_reps__[x->bits_num],
              yd_bits = *yd & __bitset_bit_reps__[x->bits_num];
    if (xd_bits == yd_bits) {
      cgraph_size_t i = 1;
      for (xd--, yd--, flag = CGRAPH_TRUE; i < x->len; i++, xd--, yd--) {
        if (*xd != *yd) {
          flag = CGRAPH_FALSE;
          break;
        }
      }
    }
  } else if ((NULL == x) && (NULL == y)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, gr)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    if (x->len == y->len) {
      if (x->bits_num == y->bits_num) {
        DATA_TYPE *xd = &(x->data[x->len - 1]), *yd = &(y->data[y->len - 1]);
        DATA_TYPE xd_bits = *xd & __bitset_bit_reps__[x->bits_num],
                  yd_bits = *yd & __bitset_bit_reps__[x->bits_num];
        if (xd_bits == yd_bits) {
          cgraph_size_t i = 1;
          for (xd--, yd--; (*xd == *yd) && (i < x->len); i++, xd--, yd--) {
          }
          if (*xd > *yd) {
            flag = CGRAPH_TRUE;
          }
        } else if (xd_bits > yd_bits) {
          flag = CGRAPH_TRUE;
        }
      } else if (x->bits_num > y->bits_num) {
        flag = CGRAPH_TRUE;
      }
    } else if (x->len > y->len) {
      flag = CGRAPH_TRUE;
    }
  } else if ((NULL != x) && (NULL == y)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

TYPE *FUNCTION(NAME, format)(TYPE *cthis) {
  if (NULL != cthis) {
    cthis->bits_num &= (DATA_BITS - 1);
    cthis->data[cthis->len - 1] &= __bitset_bit_reps__[cthis->bits_num];
  }

  return cthis;
}

TYPE *FUNCTION(NAME, and)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t max_len = CGRAPH_MAX(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, max_len, &error);
    if (CGRAPH_FALSE == error) {
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
      cgraph_size_t i = 0, min_len = CGRAPH_MIN(x->len, y->len);
      z->len = max_len;
      for (; i < min_len; i++, xd++, yd++, zd++) {
        *zd = CGRAPH_AND(*xd, *yd);
      }
      cgraph_memset(zd, max_len - i, 0);
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, or)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t max_len = CGRAPH_MAX(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, max_len, &error);
    if (CGRAPH_FALSE == error) {
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
      cgraph_size_t i = 0, min_len = CGRAPH_MIN(x->len, y->len);
      z->len = max_len;
      for (; i < min_len; i++, xd++, yd++, zd++) {
        *zd = CGRAPH_OR(*xd, *yd);
      }
      cgraph_memcpy(zd, (i < x->len) ? xd : yd, max_len - i);
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, xor)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t max_len = CGRAPH_MAX(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, max_len, &error);
    if (CGRAPH_FALSE == error) {
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
      cgraph_size_t i = 0, min_len = CGRAPH_MIN(x->len, y->len);
      z->len = max_len;
      for (i = 0; i < min_len; i++, xd++, yd++, zd++) {
        *zd = CGRAPH_XOR(*xd, *yd);
      }
      cgraph_memcpy(zd, (i < x->len) ? xd : yd, max_len - i);
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, xnor)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t max_len = CGRAPH_MAX(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, max_len, &error);
    if (CGRAPH_FALSE == error) {
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
      cgraph_size_t i = 0, min_len = CGRAPH_MIN(x->len, y->len);
      z->len = max_len;
      for (i = 0; i < min_len; i++, xd++, yd++, zd++) {
        *zd = CGRAPH_XNOR(*xd, *yd);
      }
      for (; i < x->len; i++, xd++, zd++) {
        *zd = CGRAPH_NOT(*xd);
      }
      for (; i < y->len; i++, yd++, zd++) {
        *zd = CGRAPH_NOT(*yd);
      }
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
      for (; i < len; i++, xd++, yd++) {
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

TYPE *FUNCTION(NAME, unit)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_memset(cthis->data, cthis->len, DATA_MAX);
    cthis->data[cthis->len - 1] &= __bitset_bit_reps__[cthis->bits_num];
  }

  return cthis;
}

TYPE *FUNCTION(NAME, unit_inv)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_memset(cthis->data, cthis->len, DATA_MIN);
    cthis->data[cthis->len - 1] &= __bitset_bit_reps__[cthis->bits_num];
  }

  return cthis;
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
