#include <ctype.h>

#include "cgraph_base.h"

#include "cgraph_float32.h"
#include "cgraph_float64.h"

/** object cgraph_bignum_t header */
#include "cgraph_bignum.h"

#define CGRAPH_CBUF_SIZE CGRAPH_BIGNUM_CBUF_SIZE
#define CGRAPH_CBUF_PTR cgraph_cbuf_ptr
#include "template_cbuf.ct"

static cgraph_bool_t FUNCTION(NAME, _datgr)(DATA_TYPE *xd, DATA_TYPE *yd,
                                            const cgraph_size_t len);
static cgraph_bool_t FUNCTION(NAME, _datge)(DATA_TYPE *xd, DATA_TYPE *yd,
                                            const cgraph_size_t len);
static DATA_TYPE *FUNCTION(NAME, _datmul)(DATA_TYPE *xd, DATA_TYPE y,
                                          DATA_TYPE *zd,
                                          const cgraph_size_t len);

static cgraph_bool_t FUNCTION(NAME, _datgr)(DATA_TYPE *xd, DATA_TYPE *yd,
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
  return CGRAPH_NTEST(FUNCTION(NAME, _datgr)(yd, xd, len));
}

static DATA_TYPE *FUNCTION(NAME, _datmul)(DATA_TYPE *xd, DATA_TYPE y,
                                          DATA_TYPE *zd,
                                          const cgraph_size_t len) {
  DATA_TYPE *xd_end = xd + len, *zd_end = zd + len + 1;
  cgraph_size_t i = 0;
  DATA_TYPE sum, carry = 0;
  for (; i < len; i++, xd_end--, zd_end--) {
    sum = carry + *xd_end * y;
    *zd_end = sum % (DATA_MAX + 1);
    carry = sum / (DATA_MAX + 1);
  }
  *zd_end = carry;

  return zd;
}

/** template module */
#include "template_data.ct"

cgraph_size_t FUNCTION(NAME, fprint)(FILE *fp, const TYPE *cthis) {
  return FUNCTION(NAME, fprintn)(fp, cthis);
}

cgraph_size_t FUNCTION(NAME, fprintn)(FILE *fp, const TYPE *cthis) {
  cgraph_size_t len = 0;
  if (CGRAPH_HASDATA(cthis)) {
    cgraph_size_t i = cthis->len - 1;
    DATA_TYPE *data = &cthis->data[i];
    if (CGRAPH_FALSE == cthis->postive) {
      fputc('-', fp);
      len++;
    }
    len += cthis->len + 1;
    for (; i >= cthis->point; i--, data--) {
      fputc('0' + *data, fp);
    }
    fputc('.', fp);
    for (; i >= 0; i--, data--) {
      fputc('0' + *data, fp);
    }
    if (0 == cthis->point) {
      fputc('0', fp);
    }
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, fprinte)(FILE *fp, const TYPE *cthis) {
  cgraph_size_t len = 0;
  if (CGRAPH_HASDATA(cthis)) {
    cgraph_size_t i = cthis->len - 1, j, point, exp;
    DATA_TYPE *data = &(cthis->data[i]), *data_end = &(cthis->data[0]);
    if (CGRAPH_FALSE == cthis->postive) {
      fputc('-', fp);
      len++;
    }
    for (; (DATA_ZERO == *data) && (i > 0); i--, data--) {
    }
    point = i;
    exp = i - cthis->point;
    for (j = 0; (DATA_ZERO == *data_end) && (j < point); j++, data_end++) {
    }
    len += i - j + 1;
    for (; i >= point; i--, data--) {
      fputc('0' + *data, fp);
    }
    fputc('.', fp);
    for (; i >= j; i--, data--) {
      fputc('0' + *data, fp);
    }
    if (0 == point) {
      fputc('0', fp);
    }
    if (0 != exp) {
      len += cgraph_file_fprintf(fp, "e%ld", exp);
    }
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, snprint)(cgraph_char_t *cbuf,
                                      const cgraph_size_t size,
                                      const TYPE *cthis) {
  return FUNCTION(NAME, snprintn)(cbuf, size, cthis);
}

cgraph_size_t FUNCTION(NAME, snprintn)(cgraph_char_t *cbuf,
                                       const cgraph_size_t size,
                                       const TYPE *cthis) {
  cgraph_size_t _size = size - 1, len = 0;
  if (CGRAPH_ISBUF(cbuf, _size) && CGRAPH_HASDATA(cthis)) {
    cgraph_size_t i = cthis->len - 1;
    DATA_TYPE *data = &cthis->data[cthis->len - 1];
    if (CGRAPH_FALSE == cthis->postive) {
      *(cbuf++) = '-';
      _size--;
      len++;
    }
    len += (_size = CGRAPH_MIN(_size, cthis->len));
    for (; i >= cthis->point; i--, data--, cbuf++) {
      *cbuf = '0' + *data;
    }
    *(cbuf++) = '.';
    for (; i >= 0; i--, data--, cbuf++) {
      *cbuf = '0' + *data;
    }
    if (0 == cthis->point) {
      *(cbuf++) = '0';
    }
    *cbuf = '\0';
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, snprinte)(cgraph_char_t *cbuf,
                                       const cgraph_size_t size,
                                       const TYPE *cthis) {
  cgraph_size_t _size = size - 1, len = 0;
  if (CGRAPH_ISBUF(cbuf, _size) && CGRAPH_HASDATA(cthis)) {
    cgraph_size_t i = cthis->len - 1, j, point, exp;
    DATA_TYPE *data = &cthis->data[i], *data_end = &(cthis->data[0]);
    if (CGRAPH_FALSE == cthis->postive) {
      *(cbuf++) = '-';
      _size--;
      len++;
    }
    for (; (0 == *data) && (i > 0); i--, data--) {
    }
    point = i;
    exp = i - cthis->point;
    for (j = 0; (0 == *data_end) && (j < point); j++, data_end++) {
    }
    len += (_size = CGRAPH_MIN(_size, i - j + 1));
    for (; i >= point; i--, data--, cbuf++) {
      *cbuf = '0' + *data;
    }
    *(cbuf++) = '.';
    for (; i >= j; i--, data--, cbuf++) {
      *cbuf = '0' + *data;
    }
    if (0 == point) {
      *(cbuf++) = '0';
    }
    if (exp != 0) {
      len += cgraph_file_snprintf(cbuf, _size - len, "e%ld", exp);
      cbuf[len] = '\0';
    } else {
      *cbuf = '\0';
    }
  }

  return len;
}

/*
  BKDR Hash Algorithm
  hash = (hash * 31) + (cthis->data[i] - DATA_MIN)
*/
cgraph_size_t FUNCTION(NAME, hash)(const TYPE *cthis) {
  cgraph_size_t hash = 0;
  if (NULL != cthis) {
    cgraph_size_t i = cthis->len - 1;
    hash = (cthis->postive ? cthis->point : -cthis->point);
    for (; i >= 0; i--) {
      hash = (hash * 31) + cthis->data[i];
    }
  }

  return CGRAPH_ABS(hash);
}

__INLINE cgraph_int_t FUNCTION(NAME, signbit)(const TYPE *cthis) {
  return ((NULL != cthis) ? cthis->postive : CGRAPH_FALSE);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != cthis) && (0 <= cthis->point) && (cthis->point < cthis->len)) {
    cgraph_size_t i;
    for (i = 0, flag = CGRAPH_TRUE; i < cthis->len; i++) {
      if ((DATA_MIN > cthis->data[i]) || (DATA_MAX < cthis->data[i])) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }

  return flag;
}

TYPE *FUNCTION(NAME, initc)(TYPE *cthis, const cgraph_char_t *data,
                            const cgraph_size_t len) {
  if ((NULL != cthis) && (len < cthis->size)) {
    cgraph_size_t _len = CGRAPH_MIN(cthis->size, len), position = 0, exp = 0, i;
    cgraph_char_t *xd = (cgraph_char_t *)&(data[len - 1]);
    cgraph_bool_t isexp = CGRAPH_FALSE, isexp_pos;
    if ('-' == *data) {
      cthis->postive = CGRAPH_FALSE;
      _len -= 1;
    } else {
      cthis->postive = CGRAPH_TRUE;
      if ('+' == *data) {
        _len -= 1;
      }
    }
    for (; cgraph_math_isnumtl(*xd); xd--, _len--) {
    }
    for (cthis->len = 0, cthis->point = 0; cthis->len < _len; xd--) {
      if (('e' == *xd) || ('E' == *xd)) {
        xd--;
        isexp = CGRAPH_TRUE;
        i = cthis->len + 1;
        break;
      } else if ('.' == *xd) {
        cthis->point = cthis->len;
        _len -= 1;
      } else {
        cthis->data[cthis->len++] = *xd - '0';
        if ((cthis->len > cthis->point) && (cgraph_math_isnumst(*xd))) {
          position = cthis->len;
        }
      }
    }
    cthis->len = (position > cthis->point) ? position : cthis->len;
    if (cthis->len == cthis->point) {
      cthis->data[cthis->len++] = 0;
    }
    if (CGRAPH_TRUE == isexp) {
      for (; cgraph_math_isdechd(*xd) && (i < len); xd--, i++) {
      }
      if ('-' == *xd) {
        isexp_pos = CGRAPH_TRUE;
        xd--;
        i++;
      } else {
        if ('+' == *xd) {
          xd--;
          i++;
        }
        isexp_pos = CGRAPH_FALSE;
      }
      for (; cgraph_math_isdecmd(*xd) && (i < len); xd--, i++) {
        exp = 10 * exp + *xd - '0';
      }
      cthis = (CGRAPH_TRUE == isexp_pos) ? FUNCTION(NAME, mul10)(cthis, exp)
                                         : FUNCTION(NAME, div10)(cthis, exp);
    }
  }

  return FUNCTION(NAME, format)(cthis);
}

TYPE *FUNCTION(NAME, initf32)(TYPE *cthis, const cgraph_float32_t data) {
  if (NULL != cthis) {
    cgraph_size_t len =
        cgraph_file_snprintf(CGRAPH_CBUF_PTR, CGRAPH_CBUF_SIZE, "%g", data);
    cthis = FUNCTION(NAME, initc)(cthis, CGRAPH_CBUF_PTR, len);
  }

  return cthis;
}

TYPE *FUNCTION(NAME, initf64)(TYPE *cthis, const cgraph_float64_t data) {
  if (NULL != cthis) {
    cgraph_size_t len =
        cgraph_file_snprintf(CGRAPH_CBUF_PTR, CGRAPH_CBUF_SIZE, "%g", data);
    cthis = FUNCTION(NAME, initc)(cthis, CGRAPH_CBUF_PTR, len);
  }

  return cthis;
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

TYPE *FUNCTION(NAME, format)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i, j, point = cthis->point + 1;
    DATA_TYPE *data = &(cthis->data[cthis->len - 1]);
    for (; (DATA_ZERO == *data) && (cthis->len > point); data--, cthis->len--) {
    }
    for (data = &(cthis->data[0]), i = 0;
         (DATA_ZERO == *data) && (i < cthis->point); data++, i++) {
    }
    if (0 < i) {
      cthis->len -= i;
      cthis->point -= i;
      for (j = i, i = 0; i < cthis->len; j++, i++) {
        cthis->data[i] = cthis->data[j];
      }
      if ((1 == cthis->len) && (0 == cthis->data[0])) {
        cthis->postive = CGRAPH_TRUE;
      }
    }
    cgraph_memset(&(cthis->data[cthis->len]), DATA_ZERO,
                  cthis->size - cthis->len);
  }

  return cthis;
}

TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t floatx_len = x->point, intx_len = x->len - floatx_len,
                  floaty_len = y->point, inty_len = y->len - floaty_len;
    cgraph_size_t float_min = CGRAPH_MIN(floatx_len, floaty_len),
                  float_max = CGRAPH_MAX(floatx_len, floaty_len),
                  int_min = CGRAPH_MIN(intx_len, inty_len),
                  int_max = CGRAPH_MAX(intx_len, inty_len), i, j;
    DATA_TYPE carry = 0;
    DATA_TYPE *floatx = &(x->data[0]), *intx = &(x->data[x->point]),
              *floaty = &(y->data[0]), *inty = &(y->data[y->point]),
              *zd = &(z->data[0]);
    z->len = float_max + int_max;
    z->point = float_max;
    if (x->postive == y->postive) {
      z->postive = x->postive;
      for (i = float_max; i > floaty_len; i--, zd++, floatx++) {
        *zd = *floatx;
      }
      for (; i > floatx_len; i--, zd++, floaty++) {
        *zd = *floaty;
      }
      for (; i > 0; i--, zd++, floatx++, floaty++) {
        *zd = *floatx + *floaty + carry;
        if (*zd > DATA_MAX) {
          carry = 1;
          *zd = *zd - 10;
        } else {
          carry = 0;
        }
      }
      for (i = 0; i < int_min; i++, intx++, inty++, zd++) {
        *zd = *intx + *inty + carry;
        if (*zd > DATA_MAX) {
          carry = 1;
          *zd = *zd - 10;
        } else {
          carry = 0;
        }
      }
      for (; i < intx_len; i++, intx++, zd++) {
        *zd = *intx + carry;
        if (*zd > DATA_MAX) {
          carry = 1;
          *zd = DATA_MIN;
        } else {
          carry = 0;
        }
      }
      for (; i < inty_len; i++, inty++, zd++) {
        *zd = *inty + carry;
        if (*zd > DATA_MAX) {
          carry = 1;
          *zd = DATA_MIN;
        } else {
          carry = 0;
        }
      }
      if (0 < carry) {
        *zd = carry;
        z->len += 1;
      }
    } else {
      cgraph_size_t _intx_len = intx_len, _floatx_len = floatx_len,
                    _inty_len = inty_len, _floaty_len = floaty_len;
      DATA_TYPE *_intx = intx, *_floatx = floatx, *_inty = inty,
                *_floaty = floaty;
      z->postive = x->postive;
      if ((intx_len < inty_len) ||
          ((intx_len == inty_len) &&
           FUNCTION(NAME, _datgr)(_inty, _intx, intx_len + float_min))) {
        _intx = inty;
        _intx_len = inty_len;
        _floatx = floaty;
        _floatx_len = floaty_len;
        _inty = intx;
        _inty_len = intx_len;
        _floaty = floatx;
        _floaty_len = floaty_len;
        z->postive = y->postive;
      }
      for (i = float_max; i > _floatx_len; i--, zd++, _floaty++, carry = 1) {
        *zd = DATA_MAX - *_floaty - carry;
      }
      for (; i > _floaty_len; i--, zd++, _floatx++) {
        *zd = *_floatx;
      }
      for (; i > 0; i--, zd++, _floatx++, _floaty++) {
        *zd = *_floatx - carry;
        if (*zd >= *_floaty) {
          *zd -= *_floaty;
          carry = 0;
        } else {
          *zd += DATA_MAX - *_floaty + 1;
        }
      }
      for (i = 0; i < int_min; i++, _intx++, _inty++, zd++) {
        *zd = *_intx - carry;
        if (*zd >= *_inty) {
          *zd -= *_inty;
          carry = 0;
        } else {
          *zd += DATA_MAX - *_inty + 1;
          carry = 1;
        }
      }
      for (; i < _intx_len; i++, _intx++, zd++) {
        *zd = *_intx;
        if (*zd > carry) {
          *zd -= carry;
          carry = 0;
        } else {
          *zd += DATA_MAX - carry + 1;
        }
      }
    }
  }

  return FUNCTION(NAME, format)(z);
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
      cgraph_size_t i = 0, j;
      DATA_TYPE sum, carry, *xd = &(x->data[0]), *yd, *zd;
      z->point = x->point + y->point;
      z->postive = CGRAPH_TEST(x->postive == y->postive);
      z->len = _len;
      cgraph_memset(z->data, DATA_ZERO, z->len);
      for (; i < x->len; i++, xd++) {
        for (carry = 0, j = 0, yd = &(y->data[0]), zd = &(z->data[i]);
             j < y->len; j++, yd++, zd++) {
          sum = *zd + (*xd) * (*yd) + carry;
          *zd = sum % (DATA_MAX + 1);
          carry = sum / (DATA_MAX + 1);
        }
        *zd = carry;
      }
    }
  }

  return FUNCTION(NAME, format)(z);
}

TYPE *FUNCTION(NAME, mul10)(TYPE *cthis, const cgraph_size_t exp) {
  if ((NULL != cthis) && (0 < exp)) {
    if (cthis->point >= exp) {
      cthis->point -= exp;
    } else {
      cgraph_size_t offset = exp - cthis->point, _len = cthis->len + offset;
      cgraph_bool_t error = CGRAPH_FALSE;
      cthis =
          FUNCTION(NAME, realloc)(cthis, DATA_ID, cthis->size, _len, &error);
      if (CGRAPH_FALSE == error) {
        cgraph_size_t i, j;
        cthis->point = 0;
        cthis->len = _len;
        for (i = _len - 1, j = i - offset; j >= 0; i--, j--) {
          cthis->data[i] = cthis->data[j];
        }
        cgraph_memset(&(cthis->data[0]), DATA_ZERO, offset);
      }
    }
  }

  return FUNCTION(NAME, format)(cthis);
}

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t floatx_len = x->point, intx_len = x->len - floatx_len,
                  floaty_len = y->point, inty_len = y->len - floaty_len;
    DATA_TYPE *intx = &(x->data[x->len - 1]), *floatx = &(x->data[x->point]),
              *inty = &(x->data[x->len - 1]), *floaty = &(y->data[y->point]);
    cgraph_size_t float_min = CGRAPH_MIN(floatx_len, floaty_len),
                  float_max = CGRAPH_MAX(floatx_len, floaty_len),
                  int_min = CGRAPH_MIN(intx_len, inty_len),
                  int_max = CGRAPH_MAX(intx_len, inty_len);
    z->postive = x->postive;
    if ((intx_len > inty_len) ||
        ((intx_len == inty_len) &&
         FUNCTION(NAME, _datgr)(inty, intx, intx_len + float_min))) {
    }
  }

  return FUNCTION(NAME, format)(z);
}

TYPE *FUNCTION(NAME, div10)(TYPE *cthis, const cgraph_size_t exp) {
  if ((NULL != cthis) && (0 < exp)) {
    cgraph_size_t _len = cthis->len + exp, _size = cthis->size;
    cgraph_bool_t error = CGRAPH_FALSE;
    cthis = FUNCTION(NAME, realloc)(cthis, DATA_ID, _size, _len, &error);
    if (CGRAPH_FALSE == error) {
      cthis->point += exp;
      cthis->len = _len;
    }
  }

  return FUNCTION(NAME, format)(cthis);
}

TYPE *FUNCTION(NAME, idiv)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
  }

  return z;
}

TYPE *FUNCTION(NAME, int)(const TYPE *x, TYPE *y) {
  if (NULL != x) {
    cgraph_size_t int_len = x->len - x->point;
    cgraph_bool_t error = CGRAPH_FALSE;
    y = FUNCTION(NAME, realloc)(y, DATA_ID, CGRAPH_SIZE(y), int_len, &error);
    if (CGRAPH_FALSE == error) {
      cgraph_memcpy(&(x->data[x->point]), &(y->data[0]), int_len);
      y->point = 0;
      y->len = int_len;
      y->postive = x->postive;
    }
  }

  return y;
}

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y) && (x->postive == y->postive)) {
    cgraph_size_t floatx_len = x->point, intx_len = x->len - floatx_len,
                  floaty_len = y->point, inty_len = y->len - floaty_len;
    cgraph_size_t float_min = CGRAPH_MIN(floatx_len, floaty_len),
                  int_min = CGRAPH_MIN(intx_len, inty_len), i;
    DATA_TYPE *xd = &(x->data[x->len - 1]), *yd = &(y->data[y->len - 1]);
    for (i = intx_len, flag = CGRAPH_TRUE; i > int_min; i--, xd--) {
      if (DATA_ZERO != *xd) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
    if (CGRAPH_TRUE == flag) {
      for (i = inty_len; i > int_min; i--, yd--) {
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
        if (CGRAPH_TRUE == flag) {
          for (i = 0; i < float_min; i++, xd--, yd--) {
            if (*xd != *yd) {
              flag = CGRAPH_FALSE;
              break;
            }
          }
          if (CGRAPH_TRUE == flag) {
            for (; i < floatx_len; i++, xd--) {
              if (DATA_ZERO != *xd) {
                flag = CGRAPH_FALSE;
                break;
              }
            }
            if (CGRAPH_TRUE == flag) {
              for (; i < floaty_len; i++, yd--) {
                if (DATA_ZERO != *yd) {
                  flag = CGRAPH_FALSE;
                  break;
                }
              }
            }
          }
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
      cgraph_size_t floatx_len = x->point, intx_len = x->len - floatx_len,
                    floaty_len = y->point, inty_len = y->len - floaty_len;
      cgraph_size_t float_min = CGRAPH_MIN(floatx_len, floaty_len),
                    int_min = CGRAPH_MIN(x->point, y->point), i;
      DATA_TYPE *xd = &(x->data[x->len - 1]), *yd = &(y->data[y->len - 1]);
      for (i = intx_len; i > int_min; i--, xd--) {
        if (DATA_ZERO != *xd) {
          flag = CGRAPH_TRUE;
          break;
        }
      }
      if (CGRAPH_FALSE == flag) {
        for (i = inty_len; i > int_min; i--, yd--) {
          if (DATA_ZERO != *yd) {
            break;
          }
        }
        if (i <= int_min) {
          for (; (*xd == *yd) && (i > 0); i--, xd--, yd--) {
          }
          if (*xd > *yd) {
            flag = CGRAPH_TRUE;
          } else if ((*xd == *yd) && (0 >= i)) {
            for (; (*xd == *yd) && (i < float_min); i++, xd--, yd--) {
            }
            if (*xd > *yd) {
              flag = CGRAPH_TRUE;
            } else if (*xd == *yd) {
              cgraph_size_t float_max = CGRAPH_MAX(floatx_len, floaty_len);
              if (i < float_max) {
                for (; i < floatx_len; i++, xd--) {
                  if (DATA_ZERO != *xd) {
                    flag = CGRAPH_TRUE;
                    break;
                  }
                }
                if (i >= floatx_len) {
                  flag = CGRAPH_LX;
                }
                if ((CGRAPH_FALSE == flag) || (CGRAPH_LX == flag)) {
                  for (; i < floaty_len; i++, yd--) {
                    if (DATA_ZERO != *yd) {
                      break;
                    }
                  }
                  if (i >= floaty_len) {
                    flag = CGRAPH_LX;
                  }
                }
              } else if (i == float_max) {
                flag = CGRAPH_LX;
              }
            }
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

cgraph_bool_t FUNCTION(NAME, isnan)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != cthis) && (CGRAPH_CSTR_NAN_SIZE == cthis->len)) {
    if (cgraph_memcmp(cthis->data, CGRAPH_CSTR_NAN, CGRAPH_CSTR_NAN_SIZE)) {
      flag = CGRAPH_TRUE;
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isinf)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != cthis) && (CGRAPH_CSTR_INFR_SIZE == cthis->len)) {
    if (cgraph_memcmp(cthis->data, CGRAPH_CSTR_INFR, CGRAPH_CSTR_INFR_SIZE)) {
      flag = CGRAPH_TRUE;
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ispinf)(const TYPE *cthis) {
  cgraph_bool_t flag = FUNCTION(NAME, isinf)(cthis);
  if ((CGRAPH_TRUE == flag) && (CGRAPH_TRUE == cthis->postive)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isninf)(const TYPE *cthis) {
  cgraph_bool_t flag = FUNCTION(NAME, isinf)(cthis);
  if ((CGRAPH_TRUE == flag) && (CGRAPH_FALSE == cthis->postive)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

TYPE *FUNCTION(NAME, unit)(TYPE *cthis) {
  if (NULL != cthis) {
    cthis->len = 1;
    cthis->point = 0;
    cthis->data[0] = DATA_ONE;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, unit_inv)(TYPE *cthis) {
  if (NULL != cthis) {
    cthis->len = 2;
    cthis->point = 1;
    cthis->data[0] = DATA_ONE;
    cthis->data[1] = DATA_ZERO;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, pi)(const cgraph_size_t size) {
  TYPE *cthis = FUNCTION(NAME, calloc)(DATA_ID, size);
  if (NULL != cthis) {
  }

  return cthis;
}

TYPE *FUNCTION(NAME, ceil)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t i = x->point, len = CGRAPH_MIN(x->len, y->size);
    DATA_TYPE carry = (((CGRAPH_TRUE == x->postive) && (0 < x->point)) ? 1 : 0);
    y->postive = x->postive;
    y->point = 0;
    for (y->len = 0; i < len; i++, y->len++) {
      y->data[y->len] = x->data[i] + carry;
      if (y->data[y->len] > DATA_MAX) {
        y->data[y->len] = DATA_MIN;
        carry = 1;
      } else {
        carry = 0;
      }
    }
    if (0 < carry) {
      y->data[y->len++] = carry;
    }
    if ((y->len == 1) && (0 == y->data[0])) {
      y->postive = CGRAPH_TRUE;
    }
  }

  return y;
}

TYPE *FUNCTION(NAME, floor)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t i = x->point, len = CGRAPH_MIN(x->len, y->size);
    DATA_TYPE carry =
        (((CGRAPH_FALSE == x->postive) && (0 < x->point)) ? 1 : 0);
    y->postive = x->postive;
    y->point = 0;
    for (y->len = 0; i < len; i++, y->len++) {
      y->data[y->len] = x->data[i] + carry;
      if (y->data[y->len] > DATA_MAX) {
        y->data[y->len] = DATA_MIN;
        carry = 1;
      } else {
        carry = 0;
      }
    }
    if (0 < carry) {
      y->data[y->len++] = carry;
    }
    if ((y->len == 1) && (0 == y->data[0])) {
      y->postive = CGRAPH_TRUE;
    }
  }

  return y;
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
