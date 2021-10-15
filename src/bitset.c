#include "cgraph_base.h"
#include "cgraph_bitset.h"
#include "cgraph_int8.h"

#define TYPE_BITSET
#include "cgraph_template.h"

/** private apis  */
#define BITSET_BIT_EPS1(pos) (__bitset_bit_eps1__[BITSET_BIT_POSTION(pos)])
#define BITSET_BIT_EPS0(pos) (__bitset_bit_eps0__[BITSET_BIT_POSTION(pos)])
#define BITSET_BIT_REPS1(pos) (__bitset_bit_reps1__[BITSET_BIT_POSTION(pos)])
#define BITSET_BIT_LEPS1(pos) (__bitset_bit_leps1__[BITSET_BIT_POSTION(pos)])

#define BITSET_GET_REPS1(x) BITSET_BIT_REPS1(BITSET_BITNUM(x))
#define BITSET_GET_RHALFEPS1(x) BITSET_BIT_REPS1(BITSET_HALF(x))
#define BITSET_GET_LEPS1(x) BITSET_BIT_LEPS1(BITSET_BITNUM(x))
#define BITSET_GET_LHALFEPS1(x) BITSET_BIT_LEPS1(BITSET_HALF(x))

#define BITSET_BITPOS_UPDATE(x, pos)                                           \
  do {                                                                         \
    BITSET_BITPOS(x) = (pos)&0x07U;                                            \
    BITSET_BITNUM(x) = BITSET_POS2NUM(BITSET_BITPOS(x));                       \
    BITSET_HALF(x) = (BITSET_BITNUM(x) - 4);                                   \
    BITSET_GRHALF(x) = (4 < BITSET_BITNUM(x)) ? CGRAPH_TRUE : CGRAPH_FALSE;    \
    (x)->data[(x)->len - 1] &= BITSET_GET_REPS1(x);                            \
  } while (0)
#define BITSET_BITNUM_UPDATE(x, num)                                           \
  do {                                                                         \
    BITSET_BITPOS(x) = (num)&0x07U;                                            \
    BITSET_BITNUM(x) = (num);                                                  \
    BITSET_HALF(x) = (BITSET_BITNUM(x) - 4);                                   \
    BITSET_GRHALF(x) = (4 < BITSET_BITNUM(x)) ? CGRAPH_TRUE : CGRAPH_FALSE;    \
    (x)->data[(x)->len - 1] &= BITSET_GET_REPS1(x);                            \
  } while (0)

static const DATA_TYPE __bitset_bit_eps1__[DATA_BITS] = {
    0x80U, 0x01U, 0x02U, 0x04U, 0x08U, 0x10U, 0x20U, 0x40U};
static const DATA_TYPE __bitset_bit_eps0__[DATA_BITS] = {
    0x7FU, 0xFEU, 0xFDU, 0xFBU, 0xF7U, 0xEFU, 0xDFU, 0xBFU};
static const DATA_TYPE __bitset_bit_reps1__[DATA_BITS] = {
    0xFFU, 0x01U, 0x03U, 0x07U, 0x0FU, 0x1FU, 0x3FU, 0x7FU};
static const DATA_TYPE __bitset_bit_leps1__[DATA_BITS] = {
    0x00U, 0xFEU, 0xFCU, 0xF8U, 0xF0U, 0xE0U, 0xC0U, 0x80U};

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
    len = 2 + BITSET_BITS_NUM(cthis);
#ifdef DEBUG
    cgraph_file_fprintfln(stdout, "pos %d num %d grhalf %d bits num %ld",
                          BITSET_BITPOS(cthis), BITSET_BITNUM(cthis),
                          BITSET_GRHALF(cthis), BITSET_BITS_NUM(cthis));
#endif
    fputs("0b", fp);
    for (j = BITSET_BITNUM(cthis); j > 0; j--) {
      fputc(cgraph_math_dec2bin(*data & BITSET_BIT_EPS1(j)), fp);
    }
    for (i = 1, data--; i < cthis->len; i++, data--) {
      for (j = DATA_BITS; j > 0; j--) {
        fputc(cgraph_math_dec2bin(*data & BITSET_BIT_EPS1(j)), fp);
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
    if (BITSET_GRHALF(cthis)) {
      fputc(cgraph_math_dec2uhex((*data >> 4) & BITSET_GET_RHALFEPS1(cthis)),
            fp);
      fputc(cgraph_math_dec2uhex((*(data)) & 0xFU), fp);
    } else {
      fputc(cgraph_math_dec2uhex(*(data)&BITSET_GET_REPS1(cthis)), fp);
    }
    for (i = 1, data--; i < cthis->len; i++, data--) {
      fputc(cgraph_math_dec2uhex((*data >> 4) & 0xFU), fp);
      fputc(cgraph_math_dec2uhex((*data) & 0xFU), fp);
    }
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, snprint)(cgraph_char_t *cbuffer,
                                      const cgraph_size_t size,
                                      const TYPE *cthis) {
  return FUNCTION(NAME, snprinth)(cbuffer, size, cthis);
}

cgraph_size_t FUNCTION(NAME, snprintb)(cgraph_char_t *cbuffer,
                                       const cgraph_size_t size,
                                       const TYPE *cthis) {
  cgraph_size_t len = 0;
  if ((NULL != cbuffer) && (2 < size) && (NULL != cthis)) {
    cgraph_size_t i, j, _size = size - 1;
    DATA_TYPE *data = &(cthis->data[cthis->len - 1]);
    cbuffer[len++] = '0';
    cbuffer[len++] = 'b';
    for (j = BITSET_BITNUM(cthis); j > DATA_BITS; j--) {
      cbuffer[len++] = cgraph_math_dec2bin(*data & BITSET_BIT_EPS1(j));
    }
    for (i = 1, data--; i < cthis->len; data--, i++) {
      for (j = DATA_BITS; (len < _size) && (0 < j); j--) {
        cbuffer[len++] = cgraph_math_dec2bin(*data & BITSET_BIT_EPS1(j));
      }
    }
    cbuffer[len] = '\0';
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, snprinth)(cgraph_char_t *cbuffer,
                                       const cgraph_size_t size,
                                       const TYPE *cthis) {
  cgraph_size_t len = 0;
  if ((NULL != cbuffer) && (2 < size) && (NULL != cthis)) {
    cgraph_size_t i = 0, _size = size - 1;
    DATA_TYPE *data = &(cthis->data[cthis->len - 1]);
    cbuffer[len++] = '0';
    cbuffer[len++] = 'x';
    if (BITSET_GRHALF(cthis)) {
      cbuffer[len++] =
          cgraph_math_dec2uhex((*data >> 4) & BITSET_GET_RHALFEPS1(cthis));
      cbuffer[len++] = cgraph_math_dec2uhex((*(data) >> 4) & 0xFU);
    } else {
      cbuffer[len++] =
          cgraph_math_dec2uhex((*(data) >> 4) & BITSET_GET_REPS1(cthis));
    }
    for (i = 1, data--; i < cthis->len; data--, i++) {
      if (len > _size) {
        break;
      }
      cbuffer[len++] = cgraph_math_dec2uhex((*data >> 4) & 0xFU);
      if (len > _size) {
        break;
      }
      cbuffer[len++] = cgraph_math_dec2uhex(*data & 0xFU);
    }
    cbuffer[len] = '\0';
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, hash)(const TYPE *cthis) {
  cgraph_size_t hash = 0;
  if (NULL != cthis) {
    cgraph_size_t i = cthis->len - 1;
    hash =
        (hash << 4) ^ (hash >> 28) ^ (cthis->data[i] & BITSET_GET_REPS1(cthis));
    for (i--; i >= 0; i--) {
      hash = (hash << 4) ^ (hash >> 28) ^ cthis->data[i];
    }
  }

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis) {
  return CGRAPH_TEST((NULL != cthis) && (0 < cthis->len) &&
                     (0 <= BITSET_BITNUM(cthis)) && (8 > BITSET_BITNUM(cthis)));
}

__INLINE cgraph_int_t FUNCTION(NAME, signbit)(const TYPE *cthis) {
  return CGRAPH_TEST(NULL != cthis);
}

extern TYPE *FUNCTION(NAME, updatepos)(TYPE *cthis, const cgraph_size_t pos) {
  if (NULL != cthis) {
    BITSET_BITPOS_UPDATE(cthis, pos);
  }

  return cthis;
}

TYPE *FUNCTION(NAME, updatenum)(TYPE *cthis, const cgraph_size_t num) {
  if (NULL != cthis) {
    BITSET_BITNUM_UPDATE(cthis, num);
  }

  return cthis;
}

TYPE *FUNCTION(NAME, bitscalloc)(const cgraph_size_t len_bits,
                                 const cgraph_size_t size_bits) {
  cgraph_size_t size = (0 < size_bits) ? size_bits : len_bits;
  TYPE *cthis =
      FUNCTION(NAME, calloc)(DATA_ID, FUNCTION(DATA_NAME, ubitsceil)(size));
  if (NULL != cthis) {
    cthis->len =
        (0 < size_bits) ? FUNCTION(DATA_NAME, ubitsceil)(len_bits) : size;
    BITSET_BITNUM(cthis) = BITSET_BIT_POSTION(len_bits);
  }

  return cthis;
}

DATA_TYPE FUNCTION(NAME, bit)(const TYPE *cthis, const cgraph_size_t postion) {
  DATA_TYPE bit = 0;
  if (NULL != cthis) {
    cgraph_size_t bits = BITSET_BITS_NUM(cthis),
                  _postion = BITSET_POS2POS(postion, bits);
    if (_postion <= bits) {
      bit = BITSET_GET_BIT(cthis, _postion);
    }
  }

  return bit;
}

TYPE *FUNCTION(NAME, set)(TYPE *cthis, const cgraph_size_t postion) {
  if (NULL != cthis) {
    cgraph_size_t bits = BITSET_BITS_NUM(cthis),
                  _postion = BITSET_POS2POS(postion, bits);
    if (_postion <= bits) {
      cthis->data[BITSET_BYTE_POSTION(_postion)] |= BITSET_BIT_EPS1(_postion);
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, clr)(TYPE *cthis, const cgraph_size_t postion) {
  if (NULL != cthis) {
    cgraph_size_t bits = BITSET_BITS_NUM(cthis),
                  _postion = BITSET_POS2POS(postion, bits);
    if (_postion <= bits) {
      cthis->data[BITSET_BYTE_POSTION(_postion)] &= BITSET_BIT_EPS0(_postion);
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, bits)(const TYPE *cthis, const cgraph_size_t min,
                           const cgraph_size_t max) {
  TYPE *res = NULL;
  if (NULL != cthis) {
    cgraph_size_t bits = BITSET_BITS_NUM(cthis),
                  _min = BITSET_POS2POS(min, bits),
                  _min_byte = BITSET_BYTE_POSTION(_min),
                  _min_bit = BITSET_BIT_POSTION(_min),
                  _max = BITSET_POS2POS(max, bits),
                  _max_byte = BITSET_BYTE_POSTION(_max),
                  _max_bit = BITSET_BIT_POSTION(_max);
  }

  return res;
}

TYPE *FUNCTION(NAME, sets)(TYPE *cthis, const cgraph_size_t min,
                           const cgraph_size_t max) {
  if (NULL != cthis) {
    cgraph_size_t bits = BITSET_BITS_NUM(cthis),
                  _min = BITSET_POS2POS(min, bits),
                  _min_byte = BITSET_BYTE_POSTION(_min),
                  _min_bit = BITSET_BIT_POSTION(_min),
                  _max = BITSET_POS2POS(max, bits),
                  _max_byte = BITSET_BYTE_POSTION(_max),
                  _max_bit = BITSET_BIT_POSTION(_max);
    cgraph_file_fprintfln(stdout, "min : %ld %ld max : %ld %ld", _min_byte,
                          _min_bit, _max_byte, _max_bit);
    if (_min_byte > _max_byte) {
      cgraph_size_t i = _min_byte + 1;
      cthis->data[_max_byte] |= (DATA_ONES << _max_bit);
      cthis->data[_min_byte] |= ~(DATA_ONES << _min_bit);
      for (; i > _max_byte; i--) {
        cthis->data[i] = DATA_ONES;
      }
    } else if (_min_byte < _max_byte) {
      cgraph_size_t i = _min_byte + 1;
      cthis->data[_min_byte] |= (DATA_ONES << _min_bit);
      cthis->data[_max_byte] |= ~(DATA_ONES << _max_bit);
      for (; i < _max_byte; i++) {
        cthis->data[i] = DATA_ONES;
      }
    } else {
      if (_min_bit > _max_bit) {
        cthis->data[_min_byte] |=
            ((~(DATA_ONES << ((_min_bit) - (_max_bit)))) << _max_bit);
      } else if (_min_bit < _max_bit) {
        cthis->data[_min_byte] |=
            ((~(DATA_ONES << ((_max_bit) - (_min_bit)))) << _min_bit);
      }
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, clrs)(TYPE *cthis, const cgraph_size_t min,
                           const cgraph_size_t max) {
  if (NULL != cthis) {
    cgraph_size_t bits = BITSET_BITS_NUM(cthis),
                  _min = BITSET_POS2POS(min, bits),
                  _min_byte = BITSET_BYTE_POSTION(_min),
                  _min_bit = BITSET_BIT_POSTION(_min),
                  _max = BITSET_POS2POS(max, bits),
                  _max_byte = BITSET_BYTE_POSTION(_max),
                  _max_bit = BITSET_BIT_POSTION(_max);
    cgraph_file_fprintfln(stdout, "min : %ld %ld max : %ld %ld", _min_byte,
                          _min_bit, _max_byte, _max_bit);
    if (_min_byte > _max_byte) {
      cgraph_size_t i = _min_byte + 1;
      cthis->data[_max_byte] &= ~(DATA_ONES << _max_bit);
      cthis->data[_min_byte] &= (DATA_ONES << _min_bit);
      for (; i > _max_byte; i--) {
        cthis->data[i] = DATA_ZERO;
      }
    } else if (_min_byte < _max_byte) {
      cgraph_size_t i = _min_byte + 1;
      cthis->data[_min_byte] &= ~(DATA_ONES << _min_bit);
      cthis->data[_max_byte] &= (DATA_ONES << _max_bit);
      for (; i < _max_byte; i++) {
        cthis->data[i] = DATA_ZERO;
      }
    } else {
      if (_min_bit > _max_bit) {
        cthis->data[_min_byte] &=
            ((DATA_ONES << (_min_bit)) | (~(DATA_ONES << (_max_bit))));
      } else if (_min_bit < _max_bit) {
        cthis->data[_min_byte] &=
            ((DATA_ONES << (_max_bit)) | (~(DATA_ONES << (_min_bit))));
      }
    }
  }

  return cthis;
}

/** need check  */
TYPE *FUNCTION(NAME, shl)(TYPE *cthis, const cgraph_size_t bits) {
  if ((NULL != cthis) && (0 < bits)) {
    cgraph_bool_t flag = CGRAPH_FALSE;
    cgraph_size_t bytes = FUNCTION(DATA_NAME, bitsfloor)(bits),
                  byte = FUNCTION(DATA_NAME, bitsmod)(bits),
                  byte_right = DATA_BITS - byte;
    cthis = FUNCTION(NAME, realloc)(cthis, DATA_ID, cthis->size,
                                    cthis->len + bytes + 1, &flag);
    if (CGRAPH_FALSE == flag) {
      cgraph_size_t j = cthis->len - 1, i = cthis->len + bytes;
      cgraph_int_t sum = BITSET_BITNUM(cthis) - BITSET_POS2NUM(byte);
      DATA_TYPE msk = ~(-1U << byte);
      cthis->data[i] = cthis->data[j] >> byte_right;
      if (0 > sum) {
        sum += DATA_BITS;
        cthis->len += 1;
      }
      BITSET_BITNUM_UPDATE(cthis, sum);
      for (i--; j > 0; i--, j--) {
        cthis->data[i] =
            (cthis->data[j] << byte) | (cthis->data[j - 1] >> byte_right);
      }
      cthis->data[i] = cthis->data[j] << byte;
      cgraph_memset(&cthis->data[0], DATA_ZERO, i);
      cthis->len += bytes;
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, shr)(TYPE *cthis, const cgraph_size_t bits) {
  if ((NULL != cthis) && (0 < cthis->len) && (0 < bits)) {
    cgraph_size_t bytes = FUNCTION(DATA_NAME, bitsfloor)(bits),
                  byte = FUNCTION(DATA_NAME, bitsmod)(bits),
                  byte_left = DATA_BITS - byte;
    cgraph_size_t i = 0, j = bytes, _len = cthis->len - 1;
    cgraph_int_t sum = BITSET_BITNUM(cthis) - BITSET_POS2NUM(byte);
    DATA_TYPE msk = ~(-1U << byte);
    for (; j < _len; i++, j++) {
      cthis->data[i] =
          (cthis->data[j] >> byte) | ((cthis->data[j + 1] & msk) << byte_left);
    }
    cthis->data[i] = cthis->data[j] >> byte;
    if (DATA_ZERO == cthis->data[i]) {
      cthis->len -= 1;
    }
    cthis->len -= bytes;
    if (0 >= cthis->len) {
      cthis->len = 1;
      cthis->data[0] = 0;
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, swapbit)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i, j;
    DATA_TYPE byte;
    if (DATA_BITS == BITSET_BITNUM(cthis)) {
      for (i = 0, j = cthis->len - 1; i < j; i++, j--) {
        byte = cthis->data[i];
        cthis->data[i] = FUNCTION(DATA_NAME, swapbit)(cthis->data[j]);
        cthis->data[j] = FUNCTION(DATA_NAME, swapbit)(byte);
      }
      if (i == j) {
        cthis->data[i] = FUNCTION(DATA_NAME, swapbit)(cthis->data[i]);
      }
    } else {
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, swapbyte)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i, j;
    if (DATA_BITS == BITSET_BITNUM(cthis)) {
      for (i = 0, j = cthis->len - 1; i < j; i++, j--) {
        DATA_SWAP(cthis->data[i], cthis->data[j]);
      }
    } else {
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, swaphfwd)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i, j;
    if (DATA_BITS == BITSET_BITNUM(cthis)) {
      for (i = 0, j = cthis->len - 1; i < j; i += 2, j -= 2) {
        DATA_SWAP(cthis->data[i], cthis->data[j - 1]);
        DATA_SWAP(cthis->data[i + 1], cthis->data[j]);
      }
    } else {
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, swapword)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i, j;
    if (DATA_BITS == BITSET_BITNUM(cthis)) {
      for (i = 0, j = cthis->len - 1; i < j; i += 4, j -= 4) {
        DATA_SWAP(cthis->data[i], cthis->data[j - 3]);
        DATA_SWAP(cthis->data[i + 1], cthis->data[j - 2]);
        DATA_SWAP(cthis->data[i + 2], cthis->data[j - 1]);
        DATA_SWAP(cthis->data[i + 3], cthis->data[j]);
      }
    } else {
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
      (BITSET_BITNUM(x) == BITSET_BITNUM(y))) {
    DATA_TYPE *xd = &(x->data[x->len - 1]), *yd = &(y->data[y->len - 1]);
    DATA_TYPE xd_bits = *xd & BITSET_GET_REPS1(x),
              yd_bits = *yd & BITSET_GET_REPS1(y);
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
      if (BITSET_BITNUM(x) == BITSET_BITNUM(y)) {
        DATA_TYPE *xd = &(x->data[x->len - 1]), *yd = &(y->data[y->len - 1]);
        DATA_TYPE xd_bits = *xd & BITSET_GET_REPS1(x),
                  yd_bits = *yd & BITSET_GET_REPS1(y);
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
      } else if (BITSET_BITNUM(x) > BITSET_BITNUM(y)) {
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
    cgraph_size_t num = BITSET_BITNUM(cthis);
    BITSET_BITNUM_UPDATE(cthis, num);
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
      cgraph_memset(zd, DATA_ZERO, max_len - i);
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
    cgraph_memset(cthis->data, DATA_MAX, cthis->len);
    cthis->data[cthis->len - 1] &= BITSET_GET_REPS1(cthis);
  }

  return cthis;
}

TYPE *FUNCTION(NAME, unit_inv)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_memset(cthis->data, DATA_MIN, cthis->len);
    cthis->data[cthis->len - 1] &= BITSET_GET_REPS1(cthis);
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

#ifdef BITSET_BIT_EPS1
#undef BITSET_BIT_EPS1
#endif

#ifdef BITSET_BIT_EPS0
#undef BITSET_BIT_EPS0
#endif

#ifdef BITSET_BIT_REPS1
#undef BITSET_BIT_REPS1
#endif

#ifdef BITSET_BIT_LEPS1
#undef BITSET_BIT_LEPS1
#endif

#ifdef BITSET_GET_REPS1
#undef BITSET_GET_REPS1
#endif

#ifdef BITSET_GET_RHALFEPS1
#undef BITSET_GET_RHALFEPS1
#endif

#ifdef BITSET_GET_LEPS1
#undef BITSET_GET_LEPS1
#endif

#ifdef BITSET_GET_LHALFEPS1
#undef BITSET_GET_LHALFEPS1
#endif

#include "cgraph_template_off.h"
