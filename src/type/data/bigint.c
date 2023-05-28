#include "cgraph_base.h"
#include "cgraph_int8.h"

/** object cgraph_bigint_t header */
#include "cgraph_bigint.h"

#define CGRAPH_CBUF_SIZE CGRAPH_BIGINT_CBUF_SIZE
#define CGRAPH_CBUF_PTR cgraph_cbuf_ptr
#include "template_cbuf.ct"

/** functions that users should keep  */
static cgraph_bool_t FUNCTION(NAME, _datgt)(DATA_TYPE *xd, DATA_TYPE *yd,
                                            const cgraph_size_t len);
static cgraph_bool_t FUNCTION(NAME, _datge)(DATA_TYPE *xd, DATA_TYPE *yd,
                                            const cgraph_size_t len);
static DATA_TYPE *FUNCTION(NAME, _datmul)(DATA_TYPE *xd, DATA_TYPE y,
                                          DATA_TYPE *zd,
                                          const cgraph_size_t len);
static TYPE *FUNCTION(NAME, _datadd)(TYPE *x, TYPE *y, TYPE *z);
static TYPE *FUNCTION(NAME, _datsub)(TYPE *x, TYPE *y, TYPE *z);
static TYPE *FUNCTION(NAME, _datadd1)(TYPE *cthis);
static TYPE *FUNCTION(NAME, _datsub1)(TYPE *cthis);

static cgraph_bool_t FUNCTION(NAME, _datgt)(DATA_TYPE *xd, DATA_TYPE *yd,
                                            const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  cgraph_size_t i = 0;
  for (; (i < len) && (*xd == *yd); i++, xd--, yd--) {
  }
  if (*xd > *yd) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

static cgraph_bool_t FUNCTION(NAME, _datge)(DATA_TYPE *xd, DATA_TYPE *yd,
                                            const cgraph_size_t len) {
  return CGRAPH_NTEST(FUNCTION(NAME, _datgt)(yd, xd, len));
}

static DATA_TYPE *FUNCTION(NAME, _datmul)(DATA_TYPE *xd, DATA_TYPE y,
                                          DATA_TYPE *zd,
                                          const cgraph_size_t len) {
  DATA_TYPE *xd_end = xd + len, *zd_end = zd + len + 1;
  cgraph_int32_t sum, carry = 0;
  CGRAPH_LOOP(i, 0, len)
  sum = carry + *(xd_end--) * y;
  *(zd_end--) = sum & DATA_MAX;
  carry = sum >> DATA_BITS;
  CGRAPH_LOOP_END
  *zd_end = carry;

  return zd;
}

static TYPE *FUNCTION(NAME, _datadd)(TYPE *x, TYPE *y, TYPE *z) {
  cgraph_size_t i, len = CGRAPH_MIN(x->len, y->len);
  DATA_TYPE carry = 0, *xd = CGRAPH_DATA_HADDR(x), *yd = CGRAPH_DATA_HADDR(y),
            *zd = CGRAPH_DATA_HADDR(z);
  cgraph_int_t sum;
  for (i = 0; i < len; i++, xd++, yd++, zd++) {
    sum = (*xd + *yd + carry);
    *zd = sum & DATA_MASK;
    carry = sum >> DATA_BITS;
  }
  for (; i < x->len; i++, xd++, zd++) {
    sum = (*xd + carry);
    *zd = sum & DATA_MASK;
    carry = sum >> DATA_BITS;
  }
  for (; i < y->len; i++, yd++, zd++) {
    sum = (*yd + carry);
    *zd = sum & DATA_MASK;
    carry = sum >> DATA_BITS;
  }
  if (0 != carry) {
    *zd = carry;
    z->len = i + 1;
  } else {
    z->len = i;
  }

  return z;
}

static TYPE *FUNCTION(NAME, _datsub)(TYPE *x, TYPE *y, TYPE *z) {
  cgraph_size_t i, len = CGRAPH_MIN(x->len, y->len);
  DATA_TYPE carry = 0, *xd = CGRAPH_DATA_HADDR(x), *yd = CGRAPH_DATA_HADDR(y),
            *zd = CGRAPH_DATA_HADDR(z);
  cgraph_int_t sum;
  DATA_TYPE *_xd = xd, *_yd = yd;
  if ((x->len < y->len) ||
      ((x->len == y->len) && FUNCTION(NAME, _datgt)(yd, xd, x->len))) {
    _xd = yd;
    _yd = xd;
    z->postive = y->postive;
  }
  for (i = 0; i < len; i++, _xd++, _yd++, zd++) {
    sum = *_xd - carry - *_yd;
    if (0 > sum) {
      *zd = DATA_MAX + 1 + sum;
      carry = 1;
    } else {
      *zd = sum;
      carry = 0;
    }
  }
  for (z->size--; i < z->size; i++, _xd++, zd++) {
    sum = *_xd - carry;
    if (0 > sum) {
      *zd = DATA_MAX + 1 + sum;
      carry = 1;
    } else {
      *zd = sum;
      carry = 0;
    }
  }
  z->len = i;
  while ((DATA_ZERO == *(--zd)) && (1 < z->len)) {
    z->len -= 1;
  }

  return z;
}

static TYPE *FUNCTION(NAME, _datadd1)(TYPE *cthis) {
  cgraph_int_t carry = 1, sum;
  DATA_TYPE *xd = CGRAPH_DATA_HADDR(cthis);
  CGRAPH_LOOP(i, 0, cthis->len)
  sum = *xd + carry;
  *(xd++) = sum & DATA_MASK;
  carry = sum >> DATA_BITS;
  CGRAPH_LOOP_END
  if (0 != carry) {
    *xd = carry;
    cthis->len += 1;
  }

  return cthis;
}

static TYPE *FUNCTION(NAME, _datsub1)(TYPE *cthis) {
  cgraph_int_t carry = -1, sum;
  DATA_TYPE *xd = CGRAPH_DATA_HADDR(cthis);
  CGRAPH_LOOP(i, 0, cthis->len)
  sum = *xd + carry;
  if (0 > sum) {
    *(xd++) = DATA_MAX + sum + 1;
    carry = -1;
  } else {
    *(xd++) = sum;
    carry = 0;
  }
  CGRAPH_LOOP_END
  if ((DATA_ZERO == *xd) && (1 < cthis->len)) {
    cthis->len -= 1;
  }

  return cthis;
}

/** template module */
#include "template_data.ct"

cgraph_size_t FUNCTION(NAME, fprint)(FILE *fp, const TYPE *cthis) {
  cgraph_size_t len = 0;
  if (CGRAPH_HASDATA(cthis)) {
    cgraph_size_t size = (cthis->len << 2) + cthis->len +
                         ((CGRAPH_FALSE == cthis->postive) ? 2 : 1);
    FUNCTION(NAME, bufmem)(size);
    len = FUNCTION(NAME, snprint)(CGRAPH_CBUF_PTR, size, cthis);
    cgraph_file_fputs(CGRAPH_CBUF_PTR, len, fp);
    FUNCTION(NAME, bufdel)();
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, fprintb)(FILE *fp, const TYPE *cthis) {
  cgraph_size_t len = 0;
  if (CGRAPH_HASDATA(cthis)) {
    DATA_TYPE *data = CGRAPH_DATA_TADDR(cthis);
    fputs("0b", fp);
    CGRAPH_LOOP(i, 0, cthis->len)
    CGRAPH_RLOOP(j, DATA_BITS - 1, -1)
    fputc(cgraph_math_dec2hex(0x1U & (*data >> j)), fp);
    CGRAPH_LOOP_END
    data--;
    CGRAPH_LOOP_END
    len = 2 + (cthis->len << DATA_L2BITS);
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, fprinth)(FILE *fp, const TYPE *cthis) {
  cgraph_size_t len = 0;
  if (CGRAPH_HASDATA(cthis)) {
    DATA_TYPE *data = CGRAPH_DATA_TADDR(cthis);
    fputs("0x", fp);
    CGRAPH_LOOP(i, 1, cthis->len)
    fputc(cgraph_math_dec2hex(0xFU & (*data >> 4)), fp);
    fputc(cgraph_math_dec2hex(0xFU & *data), fp);
    data--;
    CGRAPH_LOOP_END
    len = 2 + (cthis->len << 1);
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, snprint)(cgraph_char_t *cbuf,
                                      const cgraph_size_t size,
                                      const TYPE *cthis) {
  cgraph_size_t len = 0, _size = size - 1;
  if (CGRAPH_ISBUF(cbuf, _size) && CGRAPH_HASDATA(cthis)) {
    TYPE *copy = FUNCTION(NAME, copy)(cthis, cthis->len);
    if (CGRAPH_HASDATA(copy)) {
      cgraph_size_t i, start = cthis->len - 1;
      cgraph_int_t num, res;
      if (CGRAPH_FALSE == cthis->postive) {
        _size -= 1;
      }
      while ((0 <= start) && (len < _size)) {
        for (res = 0, i = start; i >= 0; i--) {
          num = copy->data[i] + (res << DATA_BITS);
          res = num % 10;
          copy->data[i] = num / 10;
        }
        cbuf[len++] = res + '0';
        while (0 == copy->data[start]) {
          start--;
        }
      }
      if (0 >= cthis->len) {
        cbuf[len++] = '0';
      }
      if (CGRAPH_FALSE == cthis->postive) {
        cbuf[len++] = '-';
      }
      cbuf[len] = '\0';
      cgraph_strnrev(cbuf, len);
    }
    FUNCTION(NAME, free)(copy);
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, snprintb)(cgraph_char_t *cbuf,
                                       const cgraph_size_t size,
                                       const TYPE *cthis) {
  cgraph_size_t len = 0, _size = size - 1;
  if (CGRAPH_ISBUF(cbuf, _size) && CGRAPH_HASDATA(cthis)) {
    DATA_TYPE *data = CGRAPH_DATA_TADDR(cthis);
    cbuf[len++] = '0';
    cbuf[len++] = 'b';
    CGRAPH_LOOP(i, 0, cthis->len)
    CGRAPH_RLOOP(j, DATA_BITS - 1, -1)
    cbuf[len++] = cgraph_math_dec2hex(0x1U & (*data >> j));
    if (len >= _size) {
      break;
    }
    CGRAPH_LOOP_END
    if (len >= _size) {
      break;
    }
    data--;
    CGRAPH_LOOP_END
    cbuf[len] = '\0';
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, snprinth)(cgraph_char_t *cbuf,
                                       const cgraph_size_t size,
                                       const TYPE *cthis) {
  cgraph_size_t len = 0, _size = size - 1;
  if (CGRAPH_ISBUF(cbuf, _size) && CGRAPH_HASDATA(cthis)) {
    DATA_TYPE *data = CGRAPH_DATA_TADDR(cthis);
    cbuf[len++] = '0';
    cbuf[len++] = 'x';
    CGRAPH_LOOP(i, 1, cthis->len)
    cbuf[len++] = cgraph_math_dec2hex(0xFU & (*data >> 4));
    if (len >= _size) {
      break;
    }
    cbuf[len++] = cgraph_math_dec2hex(0xFU & *data);
    if (len >= _size) {
      break;
    }
    data--;
    CGRAPH_LOOP_END
    cbuf[len] = '\0';
  }

  return len;
}

TYPE *FUNCTION(NAME, initc)(TYPE *cthis, cgraph_char_t *cbuf,
                            const cgraph_char_t *data,
                            const cgraph_size_t len) {
  if ((NULL != cthis) && (NULL != cbuf) && (NULL != data) && (0 < len)) {
    cgraph_size_t i = 0, j = 0, start = 0;
    cgraph_int_t num, res;
    if ('-' == data[i]) {
      cthis->postive = CGRAPH_FALSE;
      i = 1;
    } else {
      cthis->postive = CGRAPH_TRUE;
      if ('+' == data[i]) {
        i = 1;
      }
    }
    for (; i < len; i++, j++) {
      cbuf[j] = data[i] - '0';
    }
    cthis->len = 0;
    while ((start < len) && (cthis->len < cthis->size)) {
      for (res = 0, i = start; i < j; i++) {
        num = cbuf[i] + res * 10;
        res = num & DATA_MAX;
        cbuf[i] = num >> DATA_BITS;
      }
      cthis->data[cthis->len++] = res;
      while (0 == cbuf[start]) {
        start++;
      }
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, atoi)(const cgraph_char_t *data) {
  cgraph_size_t len = cgraph_strlen(data), size = len / 3 + 2;
  TYPE *cthis = FUNCTION(NAME, calloc)(DATA_ID, size);
  FUNCTION(NAME, bufmem)(len);
  cthis = FUNCTION(NAME, initc)(cthis, CGRAPH_CBUF_PTR, data, len);
  FUNCTION(NAME, bufdel)();

  return cthis;
}

/**
  @brief BKDR Hash Algorithm
  @brief hash = (hash * 31) + cthis->data[i]
*/
cgraph_size_t FUNCTION(NAME, hash)(const TYPE *cthis) {
  cgraph_size_t hash = USIZE_C(0);
  if (NULL != cthis) {
    cgraph_size_t i = cthis->len - 1;
    hash = cthis->postive;
    for (; i >= 0; i--) {
      hash = hash * 31 + cthis->data[i];
    }
  }

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis) {
  return CGRAPH_TEST(CGRAPH_HASDATA(cthis) && (cthis->len <= cthis->size));
}

__INLINE__ cgraph_int_t FUNCTION(NAME, signbit)(const TYPE *cthis) {
  return ((NULL != cthis) ? cthis->postive : CGRAPH_FALSE);
}

TYPE *FUNCTION(NAME, abs)(TYPE *cthis) {
  if (NULL != cthis) {
    cthis->postive = CGRAPH_TRUE;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, opp)(TYPE *cthis) {
  if (NULL != cthis) {
    cthis->postive = CGRAPH_NTEST(cthis->postive);
  }

  return cthis;
}

cgraph_bool_t FUNCTION(NAME, ispos)(const TYPE *cthis) {
  return ((NULL != cthis) ? cthis->postive : CGRAPH_FALSE);
}

cgraph_bool_t FUNCTION(NAME, isneg)(const TYPE *cthis) {
  return ((NULL != cthis) ? CGRAPH_NTEST(cthis->postive) : CGRAPH_FALSE);
}

TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t size = CGRAPH_MAX(x->len, y->len) + 1;
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, CGRAPH_SIZE(z), size, &error);
    if (CGRAPH_FALSE == error) {
      z->postive = x->postive;
      if (x->postive == y->postive) {

      } else {
      }
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, add1)(TYPE *cthis) {
  if (NULL != cthis) {
    DATA_TYPE *xd = CGRAPH_DATA_HADDR(cthis), carry = 1;
    cgraph_int_t sum = 0;
    if (CGRAPH_TRUE == cthis->postive) {

    } else {
      CGRAPH_LOOP(i, 0, cthis->len)
      sum = *xd - carry;
      if (0 > sum) {
        *(xd++) = DATA_MAX + sum + 1;
        carry = 1;
      } else {
        *(xd++) = sum;
        carry = 0;
      }
      CGRAPH_LOOP_END
      if ((DATA_ZERO == *xd) && (1 < cthis->len)) {
        cthis->len -= 1;
      }
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z) {
  FUNCTION(NAME, opp)((TYPE *)y);
  FUNCTION(NAME, add)(x, y, z);
  FUNCTION(NAME, opp)((TYPE *)y);

  return z;
}

TYPE *FUNCTION(NAME, sub1)(TYPE *cthis) {
  if (NULL != cthis) {
    DATA_TYPE *xd = CGRAPH_DATA_HADDR(cthis), carry = 0;
    cgraph_int_t sum = 0;
    cgraph_size_t i = 0;
    if (CGRAPH_TRUE == cthis->postive) {

    } else {
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t _len = x->len + y->len;
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, CGRAPH_SIZE(z), _len, &error);
    if (CGRAPH_FALSE == error) {
      cgraph_size_t i = 0, j;
      cgraph_int32_t sum, carry;
      DATA_TYPE *xd = CGRAPH_DATA_HADDR(x), *yd, *zd;
      z->postive = CGRAPH_TEST(x->postive == y->postive);
      z->len = _len;
      cgraph_memset(z->data, DATA_ZERO, z->len);
      for (; i < x->len; i++, xd++) {
        for (carry = 0, j = 0, yd = CGRAPH_DATA_HADDR(y), zd = &(z->data[i]);
             j < y->len; j++, yd++, zd++) {
          sum = *zd + (*xd) * (*yd) + carry;
          *zd = sum & DATA_MASK;
          carry = sum >> DATA_BITS;
        }
        *zd = carry;
      }
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, mul2)(TYPE *cthis) {
  return FUNCTION(NAME, shl)(cthis, 1);
}

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    if ((x->len < y->len) ||
        ((x->len == y->len) &&
         FUNCTION(NAME, _datgt)(&y->data[y->len - 1], &x->data[x->len - 1],
                                x->len))) {
      cgraph_bool_t error = CGRAPH_FALSE;
      z = FUNCTION(NAME, realloc)(z, DATA_ID, CGRAPH_SIZE(z), 1, &error);
      if (CGRAPH_FALSE == error) {
        z->data[0] = 0;
        z->len = 1;
        z->postive = CGRAPH_TRUE;
      }
    } else {
      DATA_TYPE *xd = CGRAPH_DATA_TADDR(x), *yd = CGRAPH_DATA_TADDR(y);
      cgraph_bool_t error = CGRAPH_FALSE;
      cgraph_size_t len = x->len - y->len + 1;
      z = FUNCTION(NAME, realloc)(z, DATA_ID, CGRAPH_SIZE(z), len, &error);
      if (CGRAPH_FALSE == error) {
        DATA_TYPE *zd = &(z->data[len - 1]);
        z->postive = CGRAPH_TEST(x->postive == y->postive);
        z->len = len;
      }
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, div2)(TYPE *cthis) {
  return FUNCTION(NAME, shr)(cthis, 1);
}

TYPE *FUNCTION(NAME, mod)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, CGRAPH_SIZE(z), x->len, &error);
    if (CGRAPH_FALSE == error) {
      z->postive = CGRAPH_TEST(x->postive == y->postive);
      cgraph_memcpy(z->data, x->data, x->len);
      z->len = x->len;
      if ((x->len > y->len) ||
          ((x->len == y->len) &&
           FUNCTION(NAME, _datgt)(&x->data[x->len - 1], &y->data[y->len - 1],
                                  x->len))) {
      }
    }
  }

  return z;
}

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y) && (x->postive == y->postive)) {
    cgraph_size_t len = CGRAPH_MIN(x->len, y->len), i;
    DATA_TYPE *xd = CGRAPH_DATA_TADDR(x), *yd = CGRAPH_DATA_TADDR(y);
    for (flag = CGRAPH_TRUE, i = x->len; i > len; i--, xd--) {
      if (DATA_ZERO != *xd) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
    if (CGRAPH_TRUE == flag) {
      for (i = y->len; i > len; i--, yd--) {
        if (DATA_ZERO != *yd) {
          flag = CGRAPH_FALSE;
          break;
        }
      }
      if (CGRAPH_TRUE == flag) {
        for (; i > 0; i--, xd--, yd--) {
          if (*xd != *yd) {
            flag = CGRAPH_FALSE;
            break;
          }
        }
      }
    }
  } else if ((NULL == x) && (NULL == y)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, gt)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    if (x->postive == y->postive) {
      cgraph_size_t len = CGRAPH_MIN(x->len, y->len), i;
      DATA_TYPE *xd = CGRAPH_DATA_TADDR(x), *yd = CGRAPH_DATA_TADDR(y);
      for (i = x->len; i > len; i--, xd--) {
        if (DATA_ZERO != *xd) {
          flag = CGRAPH_TRUE;
          break;
        }
      }
      if (CGRAPH_FALSE == flag) {
        for (i = y->len; i > len; i--, yd--) {
          if (DATA_ZERO != *yd) {
            break;
          }
        }
        if (i <= len) {
          for (; (*xd == *yd) && (i >= 0); i--, xd--, yd--) {
          }
          if (*xd > *yd) {
            flag = CGRAPH_TRUE;
          } else if ((*xd == *yd) && (i < 0)) {
            flag = CGRAPH_LX;
          }
        }
      }
      if (CGRAPH_FALSE == x->postive) {
        flag = (CGRAPH_LX == flag) ? CGRAPH_FALSE : CGRAPH_NTEST(flag);
      }
    } else if (CGRAPH_TRUE == x->postive) {
      flag = CGRAPH_TRUE;
    }
  } else if ((NULL != x) && (NULL == y)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

TYPE *FUNCTION(NAME, fmt)(TYPE *cthis) {
  if (NULL != cthis) {
    DATA_TYPE *data = CGRAPH_DATA_TADDR(cthis);
    for (; (DATA_ZERO == *data) && (1 < cthis->len); data--, cthis->len--) {
    }
    if (DATA_ZERO == *data) {
      cthis->postive = CGRAPH_TRUE;
    }
  }

  return cthis;
}

/**
 * @brief
 */
TYPE *FUNCTION(NAME, unit)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DATA(cthis, 0) = DATA_ONE;
    cthis->len = 1;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, unit_inv)(TYPE *cthis) {
  return FUNCTION(NAME, unit)(cthis);
}

TYPE *FUNCTION(NAME, shl)(TYPE *cthis, const cgraph_size_t len) {
  if ((NULL != cthis) && (0 < len)) {
    cgraph_bool_t flag = CGRAPH_FALSE;
    cgraph_size_t bytes = FUNCTION(DATA_NAME, bitfloor)(len),
                  byte = FUNCTION(DATA_NAME, bitmod)(len),
                  byte_right = DATA_BITS - byte;
    cthis = FUNCTION(NAME, realloc)(cthis, DATA_ID, cthis->size,
                                    cthis->len + bytes + 1, &flag);
    if (CGRAPH_FALSE == flag) {
      cgraph_size_t j = cthis->len - 1, i = cthis->len + bytes;
      cthis->data[i] = cthis->data[j] >> byte_right;
      if (DATA_ZERO != cthis->data[i]) {
        cthis->len += 1;
      }
      for (i--; j > 0; i--, j--) {
        cthis->data[i] =
            (cthis->data[j] << byte) | (cthis->data[j - 1] >> byte_right);
      }
      cthis->data[i] = cthis->data[j] << byte;
      cgraph_memset(CGRAPH_DATA_HADDR(cthis), DATA_ZERO, i);
      cthis->len += bytes;
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, shr)(TYPE *cthis, const cgraph_size_t len) {
  if (CGRAPH_HASDATA(cthis) && (0 < len)) {
    cgraph_size_t bytes = FUNCTION(DATA_NAME, bitfloor)(len),
                  byte = FUNCTION(DATA_NAME, bitmod)(len),
                  byte_left = DATA_BITS - byte;
    cgraph_size_t i = 0, j = bytes, _len = cthis->len - 1;
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
      CGRAPH_DATA(cthis, 0) = 0;
      cthis->postive = CGRAPH_TRUE;
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, swapbit1)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i, j;
    DATA_TYPE byte;
    for (i = 0, j = cthis->len - 1; i < j; i++, j--) {
      byte = cthis->data[i];
      cthis->data[i] = cgraph_int8_swapbit1(cthis->data[j]);
      cthis->data[j] = cgraph_int8_swapbit1(byte);
    }
    if (i == j) {
      cthis->data[i] = cgraph_int8_swapbit1(cthis->data[i]);
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, swapbit8)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i, j;
    for (i = 0, j = cthis->len - 1; i < j; i++, j--) {
      DATA_SWAP(cthis->data[i], cthis->data[j]);
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, swapbit16)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i, j;
    for (i = 0, j = cthis->len - 1; i < j; i += 2, j -= 2) {
      DATA_SWAP(cthis->data[i], cthis->data[j - 1]);
      DATA_SWAP(cthis->data[i + 1], cthis->data[j]);
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, swapbit32)(TYPE *cthis) {
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

cgraph_size_t FUNCTION(NAME, abitlen)(const TYPE *cthis) {
  cgraph_size_t len = 0;
  if (NULL != cthis) {
    len = (2 < cthis->len)
              ? (((cthis->len - 1) * DATA_BITS) +
                 cgraph_math_abitlen(CGRAPH_DATA(cthis, cthis->len - 1)))
              : ((1 == cthis->len) ? cgraph_math_abitlen(CGRAPH_DATA(cthis, 0))
                                   : 0);
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, cntones)(const TYPE *cthis) {
  cgraph_size_t cnt = 0;
  if (NULL != cthis) {
    CGRAPH_LOOP(i, 0, cthis->len)
    cnt += FUNCTION(DATA_NAME, cntones)(cthis->data[i]);
    CGRAPH_LOOP_END
  }

  return cnt;
}

cgraph_size_t FUNCTION(NAME, cntzeros)(const TYPE *cthis) {
  cgraph_size_t cnt = 0;
  if (NULL != cthis) {
    cgraph_size_t i, len = cthis->len - 1;
    cnt = len * DATA_BITS;
    for (i = 0; i < len; i++) {
      cnt -= FUNCTION(DATA_NAME, cntones)(cthis->data[i]);
    }
    cnt += FUNCTION(DATA_NAME, cntzeros)(cthis->data[i]);
  }

  return cnt;
}

TYPE *FUNCTION(NAME, fact)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
  }

  return y;
}

TYPE *FUNCTION(NAME, ceil)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, CGRAPH_MIN(CGRAPH_LEN(x), CGRAPH_SIZE(y)));
}

TYPE *FUNCTION(NAME, floor)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, CGRAPH_MIN(CGRAPH_LEN(x), CGRAPH_SIZE(y)));
}

TYPE *FUNCTION(NAME, pow)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y) && (NULL != z)) {
  }

  return z;
}

TYPE *FUNCTION(NAME, sin)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
  }

  return y;
}

TYPE *FUNCTION(NAME, cos)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
  }

  return y;
}

TYPE *FUNCTION(NAME, tan)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
  }

  return y;
}

TYPE *FUNCTION(NAME, asin)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
  }

  return y;
}

TYPE *FUNCTION(NAME, acos)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
  }

  return y;
}

TYPE *FUNCTION(NAME, atan)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
  }

  return y;
}

TYPE *FUNCTION(NAME, sinh)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
  }

  return y;
}

TYPE *FUNCTION(NAME, cosh)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
  }

  return y;
}

TYPE *FUNCTION(NAME, tanh)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
  }

  return y;
}

TYPE *FUNCTION(NAME, log)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
  }

  return y;
}

TYPE *FUNCTION(NAME, log2)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
  }

  return y;
}

TYPE *FUNCTION(NAME, log10)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
  }

  return y;
}

TYPE *FUNCTION(NAME, exp)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
  }

  return y;
}

TYPE *FUNCTION(NAME, sqrt)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
  }

  return y;
}

TYPE *FUNCTION(NAME, ipv4)(TYPE *cthis, const cgraph_char_t *ipv4) {
  TYPE *res = NULL;
  if (CGRAPH_ISSTR(ipv4) && CGRAPH_DATA_BITCHK(cthis, 32)) {
    cgraph_char_t *_ipv4 = (cgraph_char_t *)ipv4;
    cgraph_uint_t split_cnt = 4, byte = 0;
    cthis->len = 32 / DATA_BITS;
    cthis->postive = CGRAPH_TRUE;
    CGRAPH_LOOP(i, 0, 4)
    CGRAPH_DATA(cthis, i) = DATA_ZERO;
    CGRAPH_LOOP_END
    for (; '\0' != *_ipv4; _ipv4++) {
      if ('.' == *_ipv4) {
        cthis->data[split_cnt--] = (byte & DATA_MASK);
        byte = 0;
        continue;
      }
      byte = byte * 10 + (*_ipv4 - '0');
    }
    cthis->data[split_cnt--] = (byte & DATA_MASK);
    if (0 != split_cnt) {
      cthis->len = 1;
      CGRAPH_DATA(cthis, 0) = DATA_ZERO;
    }
  }

  return res;
}

TYPE *FUNCTION(NAME, ipv6)(TYPE *cthis, const cgraph_char_t *ipv6) {
  TYPE *res = NULL;
  if (CGRAPH_ISSTR(ipv6) && CGRAPH_DATA_BITCHK(cthis, 128)) {
    cgraph_char_t *_ipv6 = (cgraph_char_t *)ipv6;
    cgraph_uint_t split_cnt = 0, byte = 0, len = 128 / DATA_BITS;
    cthis->len = len;
    cthis->postive = CGRAPH_TRUE;
    for (; '\0' != *_ipv6; _ipv6++) {
      if (':' == *_ipv6) {
        if (':' == *(_ipv6 + 1)) {
          _ipv6 += 1;
          break;
        }
#if DATA_BITS == 8
        cthis->data[--len] = ((byte >> DATA_BITS) & DATA_MASK);
#endif
        cthis->data[--len] = (byte & DATA_MASK);
        byte = 0;
        split_cnt += 1;
        continue;
      }
      byte = byte * 16 + cgraph_math_hex2dec(*_ipv6);
    }
    if ('\0' != *_ipv6) {
      cgraph_char_t *_ipv6_end = cgraph_strend(_ipv6);
      cgraph_uint_t _byte = 1;
      len = 0;
      for (; _ipv6 != _ipv6_end; _ipv6_end--) {
        if (':' == *_ipv6_end) {
          if (':' == *(_ipv6_end - 1)) {
            break;
          }
          cthis->data[len++] = (byte & DATA_MASK);
#if DATA_BITS == 8
          cthis->data[len++] = ((byte >> DATA_BITS) & DATA_MASK);
#endif
          byte = 0;
          _byte = 1;
          split_cnt += 1;
          continue;
        }
        byte = byte + cgraph_math_hex2dec(*_ipv6) * _byte;
        _byte *= 16;
      }
      if (_ipv6_end != _ipv6) {
        split_cnt = 0;
      }
    }
    if ((split_cnt < 2) && (split_cnt > 7)) {
      cthis->len = 1;
      CGRAPH_DATA(cthis, 0) = 0;
    }
  }

  return res;
}
