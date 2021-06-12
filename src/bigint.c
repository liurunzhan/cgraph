#include "cgraph_base.h"
#include "cgraph_bigint.h"
#include "cgraph_int8.h"

#define TYPE_BIGINT
#include "cgraph_template.h"

static cgraph_bool_t FUNCTION(NAME, _datgr)(DATA_TYPE *xd, DATA_TYPE *yd,
                                            const cgraph_size_t len);
static cgraph_bool_t FUNCTION(NAME, _datge)(DATA_TYPE *xd, DATA_TYPE *yd,
                                            const cgraph_size_t len);

static cgraph_bool_t FUNCTION(NAME, _datgr)(DATA_TYPE *xd, DATA_TYPE *yd,
                                            const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  cgraph_size_t i = 0;
  for (; (i < len) && (*xd == *yd); i++, xd--, yd--) {
  }
  if (*xd <= *yd) {
    flag = CGRAPH_FALSE;
  }

  return flag;
}

static cgraph_bool_t FUNCTION(NAME, _datge)(DATA_TYPE *xd, DATA_TYPE *yd,
                                            const cgraph_size_t len) {
  return CGRAPH_NTEST(FUNCTION(NAME, _datgr)(yd, xd, len));
}

/** template module */
#include "template_data.ct"

static cgraph_char_t __bigint_buffer__[CGRAPH_BIGINT_BUFFER_SIZE];

void FUNCTION(NAME, clrbuffer)(void) {
  cgraph_memset(__bigint_buffer__, CGRAPH_BIGINT_BUFFER_SIZE, 0);
}

__INLINE cgraph_size_t FUNCTION(NAME, lenofbuffer)(void) {
  return CGRAPH_BIGINT_BUFFER_SIZE;
}

cgraph_size_t FUNCTION(NAME, fprint)(FILE *fp, const TYPE *cthis) {
  cgraph_size_t len = 0;
  if ((NULL != cthis) && (0 < cthis->len)) {
    cgraph_size_t size = cthis->len * 3 + 1;
    if (CGRAPH_FALSE == cthis->postive) {
      size += 1;
    }
    if (size <= CGRAPH_BIGINT_BUFFER_SIZE) {
      len = FUNCTION(NAME, snprint)(__bigint_buffer__, size, cthis);
      cgraph_file_putc(fp, __bigint_buffer__, len);
    }
#ifdef DEBUG
    else {
      fprintf(stderr, "out of %s buffer size %ld\n", FUNCTION(NAME, tname)(),
              CGRAPH_BIGINT_BUFFER_SIZE);
    }
#endif
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, snprint)(cgraph_char_t *buffer,
                                      const cgraph_size_t size,
                                      const TYPE *cthis) {
  cgraph_size_t len = 0, _size = size - 1;
  if ((NULL != buffer) && (0 < _size) && (NULL != cthis) && (0 < cthis->len)) {
    TYPE *copy = FUNCTION(NAME, copy)(cthis, cthis->len);
    if (NULL != copy) {
      cgraph_size_t i, start = copy->len - 1;
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
        buffer[len++] = res + '0';
        while (0 == copy->data[start]) {
          start--;
        }
      }
      if (0 >= cthis->len) {
        buffer[len++] = '0';
      }
      if (CGRAPH_FALSE == cthis->postive) {
        buffer[len++] = '-';
      }
      buffer[len] = '\0';
      cgraph_strrev(buffer, len);
    }
    FUNCTION(NAME, free)(copy);
  }

  return len;
}

TYPE *FUNCTION(NAME, initc)(TYPE *cthis, cgraph_char_t *buffer,
                            const cgraph_size_t size,
                            const cgraph_char_t *data) {
  cgraph_size_t len = cgraph_math_lenofdec(data, NULL);
  if ((NULL != cthis) && (NULL != buffer) && (len <= size)) {
    cgraph_size_t i = 0, j = 0, start = 0;
    cgraph_int_t num, res;
    if ('-' == data[i]) {
      cthis->postive = CGRAPH_FALSE;
      i++;
    } else {
      cthis->postive = CGRAPH_TRUE;
      if ('+' == data[i]) {
        i++;
      }
    }
    for (; j < len; i++, j++) {
      buffer[j] = data[i] - '0';
    }
    while ((start < len) && (cthis->len < cthis->size)) {
      for (res = 0, i = start; i < len; i++) {
        num = buffer[i] + res * 10;
        res = num & DATA_MAX;
        buffer[i] = num >> DATA_BITS;
      }
      cthis->data[cthis->len++] = res;
      while (0 == buffer[start]) {
        start++;
      }
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, atoi)(const cgraph_char_t *data) {
  cgraph_char_t *digit = NULL;
  cgraph_size_t len = cgraph_math_lenofdec(data, &digit);
  TYPE *cthis = FUNCTION(NAME, calloc)(DATA_ID, len / 3 + 1);
  cthis = FUNCTION(NAME, initc)(cthis, __bigint_buffer__,
                                CGRAPH_BIGINT_BUFFER_SIZE, digit);

  return cthis;
}

/**
  @brief BKDR Hash Algorithm
  @brief hash = (hash * 31) + cthis->data[i]
*/
cgraph_size_t FUNCTION(NAME, hash)(const TYPE *cthis) {
  cgraph_size_t hash = 0;
  if (NULL != cthis) {
    cgraph_size_t i;
    DATA_TYPE *data = &(cthis->data[0]);
    hash = cthis->postive;
    for (i = 0; i < cthis->len; i++, data++) {
      hash = hash * 31 + *data;
    }
  }

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis) {
  return CGRAPH_TEST((NULL != cthis) && (0 < cthis->len));
}

__INLINE cgraph_int_t FUNCTION(NAME, signbit)(const TYPE *cthis) {
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
    cgraph_size_t len = CGRAPH_MIN(x->len, y->len),
                  size = CGRAPH_MAX(x->len, y->len) + 1;
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, CGRAPH_SIZE(z), size, &error);
    if (CGRAPH_FALSE == error) {
      cgraph_size_t i;
      DATA_TYPE carry = 0, *xd = &(x->data[0]), *yd = &(y->data[0]),
                *zd = &(z->data[0]);
      if (x->postive == y->postive) {
        z->postive = x->postive;
        for (i = 0; i < len; i++, xd++, yd++, zd++) {
          *zd = (*xd + *yd + carry);
          carry = (((*zd < *xd) || (*zd < *yd)) ? 1 : 0);
        }
        for (; i < x->len; i++, xd++, zd++) {
          *zd = (*xd + carry);
          carry = ((*zd < *xd) ? 1 : 0);
        }
        for (; i < y->len; i++, yd++, zd++) {
          *zd = (*yd + carry);
          carry = ((*zd < *yd) ? 1 : 0);
        }
        if (0 != carry) {
          *zd = carry;
          z->len = ++i;
        } else {
          ++z->data;
          z->len = i;
        }
      } else {
        DATA_TYPE *_xd = xd, *_yd = yd;
        if ((x->len < y->len) ||
            ((x->len == y->len) &&
             FUNCTION(NAME, _datgr)(&y->data[y->len - 1], &x->data[x->len - 1],
                                    x->len))) {
          _xd = yd;
          _yd = xd;
        }
        for (i = 0; i < len; i++, _xd++, _yd++, zd++) {
          *zd = *_xd - carry;
          if (*zd >= *_yd) {
            *zd -= *_yd;
            carry = 0;
          } else {
            *zd = (DATA_MAX - *yd + 1 + *_xd);
            carry = 1;
          }
        }
        if (i == x->len) {
          z->postive = y->postive;
        } else {
          z->postive = x->postive;
        }
        for (size--; i < size; i++, _xd++, zd++) {
          *zd = *_xd - carry;
          carry = ((*zd < *_xd) ? 1 : 0);
        }
        z->len = i;
        while (0 == *(--zd)) {
          z->len -= 1;
        }
      }
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z) {
  FUNCTION(NAME, opp)((TYPE *)y);
  FUNCTION(NAME, add)(x, y, z);
  FUNCTION(NAME, opp)((TYPE *)y);

  return z;
}

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t _len = x->len + y->len;
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, CGRAPH_SIZE(z), _len, &error);
    if (CGRAPH_FALSE == error) {
      cgraph_size_t i, j;
      cgraph_int_t tmp, carry;
      DATA_TYPE *xd = &(x->data[0]), *yd, *zd;
      z->postive = CGRAPH_TEST(x->postive == y->postive);
      z->len = _len;
      cgraph_memset(z->data, z->len, 0);
      for (i = 0, carry = 0; i < x->len; i++, xd++) {
        for (j = 0, yd = &(y->data[0]), zd = &(z->data[i]); j < y->len;
             j++, yd++, zd++) {
          tmp = *zd + (*xd) * (*yd) + carry;
          *zd = tmp & DATA_MAX;
          carry = tmp >> DATA_BITS;
        }
        for (; 0 != carry; zd++) {
          *zd = carry & DATA_MAX;
          carry = carry >> DATA_BITS;
        }
      }
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t _size = CGRAPH_SIZE(z), size = x->len;
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, _size, size, &error);
    if (CGRAPH_FALSE == error) {
      z->postive = CGRAPH_TEST(x->postive == y->postive);
      if (x->len >= y->len) {
        cgraph_size_t i;
        DATA_TYPE *xd = &(x->data[x->len - 1]), *yd = &(y->data[y->len - 1]),
                  *zd = &(z->data[x->len - 1]);
        z->postive = CGRAPH_TEST(x->postive == y->postive);
        cgraph_memcpy(z->data, x->data, size);
      } else {
        z->data[0] = 0;
        z->len = 1;
      }
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, mod)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t _size = CGRAPH_SIZE(z), size = x->len;
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, _size, size, &error);
    if (CGRAPH_FALSE == error) {
      z->postive = CGRAPH_TEST(x->postive == y->postive);
      cgraph_memcpy(z->data, x->data, size);
      z->len = size;
      if (x->len >= y->len) {
      }
    }
  }

  return z;
}

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y) && (x->postive == y->postive)) {
    cgraph_size_t len = CGRAPH_MIN(x->len, y->len), i;
    DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]);
    for (flag = CGRAPH_TRUE, i = 0; i < len; i++, xd++, yd++) {
      if (*xd != *yd) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
    if (CGRAPH_TRUE == flag) {
      for (; i < x->len; i++, xd++) {
        if (DATA_ZERO != *xd) {
          flag = CGRAPH_FALSE;
          break;
        }
      }
    }
    if (CGRAPH_TRUE == flag) {
      for (; i < y->len; i++, yd++) {
        if (DATA_ZERO != *yd) {
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
    if (x->postive == y->postive) {
      cgraph_size_t len = CGRAPH_MIN(x->len, y->len), i;
      DATA_TYPE *xd = &(x->data[x->len - 1]), *yd = &(y->data[y->len - 1]);
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
          for (flag = CGRAPH_TRUE; (i >= 0) && (*xd == *yd); i--, xd--, yd--) {
          }
          if (*xd <= *yd) {
            flag = CGRAPH_FALSE;
          }
        }
      }
      if (CGRAPH_FALSE == x->postive) {
        flag = CGRAPH_NTEST(flag);
      }
    } else if (CGRAPH_TRUE == x->postive) {
      flag = CGRAPH_TRUE;
    }
  } else if ((NULL != x) && (NULL == y)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

TYPE *FUNCTION(NAME, format)(TYPE *cthis) {
  if (NULL != cthis) {
    DATA_TYPE *data = &(cthis->data[cthis->len - 1]);
    for (; (DATA_ZERO == *data) && (0 < cthis->len); data--, cthis->len--) {
    }
    if ((1 == cthis->len) && (0 == cthis->data[0])) {
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
    cthis->data[0] = DATA_ONE;
    cthis->len = 1;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, unit_inv)(TYPE *cthis) {
  return FUNCTION(NAME, unit)(cthis);
}

TYPE *FUNCTION(NAME, shl)(TYPE *cthis, const cgraph_size_t bits) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  cgraph_size_t _len = CGRAPH_LEN(cthis);
  TYPE *res = FUNCTION(NAME, realloc)(cthis, DATA_ID, _len, _len + bits, &flag);
  if (CGRAPH_FALSE == flag) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      cthis->data[i + bits] = cthis->data[i];
    }
    cgraph_memset(&cthis->data[bits - 1], bits, 0);
    cthis->len += bits;
  }

  return res;
}

TYPE *FUNCTION(NAME, shr)(TYPE *cthis, const cgraph_size_t bits) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  cgraph_size_t _len = CGRAPH_LEN(cthis);
  TYPE *res = FUNCTION(NAME, realloc)(cthis, DATA_ID, _len, _len - bits, &flag);
  if (CGRAPH_FALSE == flag) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      cthis->data[i] = cthis->data[i + bits];
    }
    cthis->len -= bits;
  }

  return res;
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

cgraph_size_t FUNCTION(NAME, cntones)(const TYPE *cthis) {
  cgraph_size_t cnt = 0;
  if (NULL != cthis) {
    cgraph_size_t i;
    for (i = 0; i < cthis->len; i++) {
      cnt += cgraph_int8_cntones(cthis->data[i]);
    }
  }

  return cnt;
}

cgraph_size_t FUNCTION(NAME, cntzeros)(const TYPE *cthis) {
  cgraph_size_t cnt = 0;
  if (NULL != cthis) {
    cgraph_size_t i;
    for (i = 0; i < cthis->len; i++) {
      cnt += cgraph_int8_cntzeros(cthis->data[i]);
    }
  }

  return cnt;
}

TYPE *FUNCTION(NAME, fact)(const TYPE *x, TYPE *y) {
  if (NULL != x) {
  }

  return y;
}

TYPE *FUNCTION(NAME, ceil)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, CGRAPH_MIN(CGRAPH_LEN(x), CGRAPH_SIZE(y)));
}

TYPE *FUNCTION(NAME, floor)(const TYPE *x, TYPE *y) {
  return FUNCTION(NAME, init)(y, x, CGRAPH_MIN(CGRAPH_LEN(x), CGRAPH_SIZE(y)));
}

TYPE *FUNCTION(NAME, pow)(const TYPE *x, const TYPE *y, TYPE *z) { return z; }

TYPE *FUNCTION(NAME, sin)(const TYPE *x, TYPE *y) { return y; }

TYPE *FUNCTION(NAME, cos)(const TYPE *x, TYPE *y) { return y; }

TYPE *FUNCTION(NAME, tan)(const TYPE *x, TYPE *y) { return y; }

TYPE *FUNCTION(NAME, asin)(const TYPE *x, TYPE *y) { return y; }

TYPE *FUNCTION(NAME, acos)(const TYPE *x, TYPE *y) { return y; }

TYPE *FUNCTION(NAME, atan)(const TYPE *x, TYPE *y) { return y; }

TYPE *FUNCTION(NAME, sinh)(const TYPE *x, TYPE *y) { return y; }

TYPE *FUNCTION(NAME, cosh)(const TYPE *x, TYPE *y) { return y; }

TYPE *FUNCTION(NAME, tanh)(const TYPE *x, TYPE *y) { return y; }

TYPE *FUNCTION(NAME, log)(const TYPE *x, TYPE *y) { return y; }

TYPE *FUNCTION(NAME, log2)(const TYPE *x, TYPE *y) { return y; }

TYPE *FUNCTION(NAME, log10)(const TYPE *x, TYPE *y) { return y; }

TYPE *FUNCTION(NAME, exp)(const TYPE *x, TYPE *y) { return y; }

TYPE *FUNCTION(NAME, sqrt)(const TYPE *x, TYPE *y) { return y; }

#include "cgraph_template_off.h"
