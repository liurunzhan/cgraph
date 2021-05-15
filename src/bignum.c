#include <ctype.h>

#include "cgraph_base.h"
#include "cgraph_bignum.h"
#include "cgraph_float32.h"
#include "cgraph_float64.h"

#define TYPE_BIGNUM
#include "cgraph_template.h"

/** template module */
#include "template_data.ct"

cgraph_size_t FUNCTION(NAME, fprint)(FILE *fp, const TYPE *cthis) {
  cgraph_size_t len = 0;
  if (NULL != cthis) {
    cgraph_size_t i;
    DATA_TYPE *data = &cthis->data[cthis->len - 1];
    if (CGRAPH_FALSE == cthis->postive) {
      fputc('-', fp);
      len++;
    }
    len += cthis->len;
    for (i = 0; i < cthis->len; i++, data--) {
      fputc(*data, fp);
    }
    if (0 == cthis->point) {
      fputc('0', fp);
    }
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, snprint)(cgraph_char_t *buffer,
                                      const cgraph_size_t size,
                                      const TYPE *cthis) {
  cgraph_size_t _size = size, len = 0;
  if ((NULL != buffer) && (0 < _size) && (NULL != cthis)) {
    cgraph_size_t i;
    DATA_TYPE *data = &cthis->data[cthis->len - 1];
    if (CGRAPH_FALSE == cthis->postive) {
      *(buffer++) = '-';
      _size--;
      len++;
    }
    if (0 == cthis->point) {
      _size--;
    }
    len += (_size = CGRAPH_MIN(_size, cthis->len));
    for (i = 0; i < _size; i++, data--, buffer++) {
      *buffer = *data;
    }
    if (0 == cthis->point) {
      *buffer = '0';
    }
  }

  return len;
}

/*
  BKDR Hash Algorithm
  hash = (hash * 31) + (cthis->data[i] - '0')
*/
cgraph_size_t FUNCTION(NAME, hash)(const TYPE *cthis) {
  cgraph_size_t hash = cthis->postive, i;
  if (NULL != cthis) {
    for (i = 0; i < cthis->len; i++) {
      hash = (hash * 31) + (cthis->data[i] - '0');
    }
  }

  return CGRAPH_ABS(hash);
}

__INLINE cgraph_int_t FUNCTION(NAME, signbit)(const TYPE *cthis) {
  return ((NULL != cthis) ? cthis->postive : CGRAPH_FALSE);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (NULL != cthis) {
    cgraph_size_t i;
    for (i = 0, flag = CGRAPH_TRUE; i < cthis->len; i++) {
      if ('0' > cthis->data[i] || '9' < cthis->data[i]) {
        if (('.' == cthis->data[i]) && (i == cthis->point)) {
          continue;
        }
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }

  return flag;
}

TYPE *FUNCTION(NAME, initc)(TYPE *cthis, const cgraph_char_t *data,
                            const cgraph_size_t len) {
  if (NULL != cthis) {
    cgraph_size_t _len = CGRAPH_MIN(cthis->size, len), position = 0;
    cgraph_char_t *xd = (cgraph_char_t *)&(data[len - 1]);
    if ('-' == *data) {
      cthis->postive = CGRAPH_FALSE;
      _len -= 1;
    } else {
      cthis->postive = CGRAPH_TRUE;
      if ('+' == *data) {
        _len -= 1;
      }
    }
    for (cthis->len = 0; cthis->len < _len; cthis->len++, xd--) {
      cthis->data[cthis->len] = *xd;
      if ('.' == *xd) {
        cthis->point = cthis->len;
      } else if (!cgraph_math_isnumst(*xd)) {
        position = cthis->len;
      }
    }
    cthis->len = position + 1;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, initf32)(TYPE *cthis, const cgraph_float32_t data) {
  if (NULL != cthis) {
    cgraph_size_t i, j;
    DATA_TYPE tmp;
    if (0.0 > data) {
      cthis->postive = CGRAPH_FALSE;
      cthis->len = cgraph_file_snprintf(cthis->data, cthis->size, "%g",
                                        cgraph_float32_abs(data));
    } else {
      cthis->postive = CGRAPH_TRUE;
      cthis->len = cgraph_file_snprintf(cthis->data, cthis->size, "%g", data);
    }
    for (i = 0, j = cthis->len - 1; i < (cthis->len >> 1); i++, j--) {
      tmp = cthis->data[i];
      cthis->data[i] = cthis->data[j];
      cthis->data[j] = tmp;
      if ('.' == cthis->data[i]) {
        cthis->point = i;
      }
      if ('.' == cthis->data[j]) {
        cthis->point = j;
      }
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, initf64)(TYPE *cthis, const cgraph_float64_t data) {
  if (NULL != cthis) {
    cgraph_size_t i, j;
    DATA_TYPE tmp;
    if (0.0 > data) {
      cthis->postive = CGRAPH_FALSE;
      cthis->len = cgraph_file_snprintf(cthis->data, cthis->size, "%g",
                                        cgraph_float64_abs(data));
    } else {
      cthis->postive = CGRAPH_TRUE;
      cthis->len = cgraph_file_snprintf(cthis->data, cthis->size, "%g", data);
    }
    for (i = 0, j = cthis->len - 1; i < (cthis->len >> 1); i++, j--) {
      tmp = cthis->data[i];
      cthis->data[i] = cthis->data[j];
      cthis->data[j] = tmp;
      if ('.' == cthis->data[i]) {
        cthis->point = i;
      }
      if ('.' == cthis->data[j]) {
        cthis->point = j;
      }
    }
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
    DATA_TYPE *data = &(cthis->data[cthis->len - 1]);
    for (; cgraph_math_isnumst(*data) && (0 < cthis->len);
         data--, cthis->len--) {
    }
    cthis->data = data;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t floatx_len = x->point, intx_len = x->len - x->point - 1,
                  floaty_len = y->point, inty_len = y->len - y->point - 1;
    cgraph_size_t float_max = CGRAPH_MAX(floatx_len, floaty_len),
                  int_min = CGRAPH_MIN(intx_len, inty_len), i;
    DATA_TYPE carry;
    DATA_TYPE *floatx = &(x->data[0]), *intx = &(x->data[x->point + 1]),
              *floaty = &(y->data[0]), *inty = &(y->data[y->point + 1]),
              *zd = &(z->data[0]);
    z->len = float_max + 1 + CGRAPH_MAX(intx_len, inty_len);
    z->point = float_max;
    if (x->postive == y->postive) {
      z->postive = x->postive;
      for (i = float_max; i > floaty_len; i--, zd++, floatx++) {
        *zd = *floatx;
      }
      for (; i > floatx_len; i--, zd++, floaty++) {
        *zd = *floaty;
      }
      for (carry = 0; i > 0; i--, zd++, floatx++, floaty++) {
        *zd = *floatx - '0' + *floaty + carry;
        if (*zd > '9') {
          carry = 1;
          *zd = *zd - 10;
        } else {
          carry = 0;
        }
      }
      for (*(zd++) = '.', i = 0; i < int_min; i++, intx++, inty++, zd++) {
        *zd = *intx - '0' + *inty + carry;
        if (*zd > '9') {
          carry = 1;
          *zd = *zd - 10;
        } else {
          carry = 0;
        }
      }
      for (; i < intx_len; i++, intx++, zd++) {
        *zd = *intx + carry;
        if (*zd > '9') {
          carry = 1;
          *zd = '0';
        } else {
          carry = 0;
        }
      }
      for (; i < inty_len; i++, inty++, zd++) {
        *zd = *inty + carry;
        if (*zd > '9') {
          carry = 1;
          *zd = '0';
        } else {
          carry = 0;
        }
      }
      if (1 == carry) {
        *zd = '1';
        z->len += 1;
      }
    } else {
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
  }

  return z;
}

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
  }

  return z;
}

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t intx_len = x->point - 1, floatx_len = x->len - intx_len,
                  inty_len = y->point - 1, floaty_len = y->len - inty_len;
    cgraph_size_t float_min = CGRAPH_MIN(floatx_len, floaty_len),
                  int_min = CGRAPH_MIN(x->point, y->point), i;
    DATA_TYPE *floatx = &(x->data[x->point + 1]), *intx = &(x->data[intx_len]),
              *floaty = &(y->data[y->point + 1]), *inty = &(y->data[inty_len]);
    if (x->postive != y->postive) {
      return flag;
    }
    for (flag = CGRAPH_TRUE, i = 0; i <= float_min; i++, floatx++, floaty++) {
      if (*floatx != *floaty) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
    if (CGRAPH_TRUE == flag) {
      for (; i < floatx_len; i++, floatx++) {
        if ('0' != *floatx) {
          flag = CGRAPH_FALSE;
          break;
        }
      }
      for (; i < floaty_len; i++, floaty++) {
        if ('0' != *floaty) {
          flag = CGRAPH_FALSE;
          break;
        }
      }
    }
    if (CGRAPH_TRUE == flag) {
      for (i = 0; i <= int_min; i++, intx--, inty--) {
        if (*intx != *inty) {
          flag = CGRAPH_FALSE;
          break;
        }
      }
      if (CGRAPH_TRUE == flag) {
        for (; i < intx_len; i++, intx--) {
          if ('0' != *intx) {
            flag = CGRAPH_FALSE;
            break;
          }
        }
        for (; i < inty_len; i++, inty--) {
          if ('0' != *inty) {
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

cgraph_bool_t FUNCTION(NAME, gr)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t intx_len = x->point - 1, floatx_len = x->len - intx_len,
                  inty_len = y->point - 1, floaty_len = y->len - inty_len;
    cgraph_size_t float_min = CGRAPH_MIN(floatx_len, floaty_len),
                  int_min = CGRAPH_MIN(x->point, y->point), i;
    DATA_TYPE *floatx = &(x->data[x->point + 1]), *intx = &(x->data[intx_len]),
              *floaty = &(y->data[y->point + 1]), *inty = &(y->data[inty_len]);
  } else if (NULL != x && NULL == y) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isnan)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != cthis) && (3 == cthis->len)) {
    if ('N' == cthis->data[2] || 'n' == cthis->data[2]) {
      if ('A' == cthis->data[1] || 'a' == cthis->data[1]) {
        if (('N' == cthis->data[0] || 'n' == cthis->data[0])) {
          flag = CGRAPH_TRUE;
        }
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isinf)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != cthis) && (3 == cthis->len)) {
    if ('I' == cthis->data[2] || 'i' == cthis->data[2]) {
      if ('N' == cthis->data[1] || 'n' == cthis->data[1]) {
        if (('F' == cthis->data[0] || 'f' == cthis->data[0])) {
          flag = CGRAPH_TRUE;
        }
      }
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

TYPE *FUNCTION(NAME, unit)(TYPE *cthis, const cgraph_size_t len) {
  cgraph_size_t _len = FUNCTION(NAME, minoflen)(cthis, len);
  if (NULL != cthis) {
    cgraph_size_t i;
    cthis->len = _len;
    cthis->point = 1;
    cthis->data[0] = '0';
    cthis->data[1] = '.';
    cthis->data[2] = '1';
    cthis->postive = CGRAPH_TRUE;
    for (i = 2; i < _len; i++) {
      cthis->data[i] = '0';
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, unit_inv)(TYPE *cthis, const cgraph_size_t len) {
  return FUNCTION(NAME, unit)(cthis, len);
}

TYPE *FUNCTION(NAME, pi)(const cgraph_size_t size) {
  TYPE *cthis = FUNCTION(NAME, calloc)(DATA_ID, size);
  if (NULL != cthis) {
  }

  return cthis;
}

TYPE *FUNCTION(NAME, ceil)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t i, len = CGRAPH_MIN(x->len, y->size - 1);
    cgraph_bool_t flag;
    DATA_TYPE carry;
    y->postive = x->postive;
    for (i = 0, flag = CGRAPH_FALSE; (i < x->len) && ('.' != x->data[i]); i++) {
      if ('0' != x->data[i]) {
        flag = CGRAPH_TRUE;
      }
    }
    if (CGRAPH_TRUE == flag) {
      carry = ((CGRAPH_TRUE == x->postive) ? 1 : 0);
      y->data[0] = '0';
      y->data[1] = '.';
      y->point = 1;
      for (y->len = 2, i++; i < len; i++, y->len++) {
        y->data[y->len] = x->data[i] + carry;
        if (y->data[y->len] > '9') {
          y->data[y->len] = '0';
          carry = 1;
        } else {
          carry = 0;
        }
      }
      if (carry == 1) {
        y->data[y->len++] = '1';
      }
    }
  }

  return y;
}

TYPE *FUNCTION(NAME, floor)(const TYPE *x, TYPE *y) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t i, len = CGRAPH_MIN(x->len, y->size - 1);
    cgraph_bool_t flag;
    DATA_TYPE carry;
    y->postive = x->postive;
    for (i = 0, flag = CGRAPH_FALSE; (i < x->len) && ('.' != x->data[i]); i++) {
      if ('0' != x->data[i]) {
        flag = CGRAPH_TRUE;
      }
    }
    if (CGRAPH_TRUE == flag) {
      carry = ((CGRAPH_FALSE == x->postive) ? 1 : 0);
      y->data[0] = '0';
      y->data[1] = '.';
      y->point = 1;
      for (y->len = 2, i++; i < len; i++, y->len++) {
        y->data[y->len] = x->data[i] + carry;
        if (y->data[y->len] > '9') {
          y->data[y->len] = '0';
          carry = 1;
        } else {
          carry = 0;
        }
      }
      if (carry == 1) {
        y->data[y->len++] = '1';
      }
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

#include "cgraph_template_off.h"
