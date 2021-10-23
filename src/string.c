#include <string.h>

#include "cgraph_base.h"
#include "cgraph_string.h"

#define TYPE_STRING
#include "cgraph_template.h"

/** template module */
#include "template_data.ct"

cgraph_size_t FUNCTION(NAME, fprint)(FILE *fp, const TYPE *cthis) {
  cgraph_size_t len = 0;
  if (NULL != cthis) {
    cgraph_size_t i;
    for (i = 0; i < cthis->len; i++) {
      fputc(cthis->data[i], fp);
    }
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, snprint)(cgraph_char_t *cbuf,
                                      const cgraph_size_t size,
                                      const TYPE *cthis) {
  cgraph_size_t len = 0;
  if ((NULL != cbuf) && (NULL != cthis)) {
    len = CGRAPH_MIN(size, cthis->len);
    cgraph_memcpy(cbuf, cthis->data, len);
  }

  return len;
}

/**
  times 33 hash algorithm proposed by Daniel J. Bernstein
  hash = hash * 33 + cthis->data[i] or
  hash += hash << 5 + cthis->data[i]
*/
cgraph_size_t FUNCTION(NAME, hash)(const TYPE *cthis) {
  cgraph_size_t hash = 0;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      hash += (hash << 5) + cthis->data[i];
    }
  }

  return hash;
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis) {
  return CGRAPH_TEST(CGRAPH_ISNEMPTY(cthis) && (cthis->len <= cthis->size));
}

__INLINE cgraph_int_t FUNCTION(NAME, signbit)(const TYPE *cthis) {
  return CGRAPH_TEST(NULL != cthis);
}

/**                          string hash functions */
cgraph_size_t FUNCTION(NAME, jshash)(const TYPE *cthis) {
  cgraph_size_t hash = 1315423911L;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      hash ^= ((hash << 5) + (hash >> 2) + cthis->data[i]);
    }
  }

  return hash;
}

cgraph_size_t FUNCTION(NAME, sdbmhash)(const TYPE *cthis) {
  cgraph_size_t hash = 0;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      hash = ((hash << 6) - hash + (hash << 16) + cthis->data[i]);
    }
  }

  return hash;
}

cgraph_size_t FUNCTION(NAME, rshash)(const TYPE *cthis) {
  cgraph_size_t hash = 0;
  if (NULL != cthis) {
    cgraph_size_t i = 0, a = 63689, b = 378551;
    for (; i < cthis->len; i++) {
      hash = hash * a + cthis->data[i];
      a *= b;
    }
  }

  return hash;
}

cgraph_size_t FUNCTION(NAME, elfhash)(const TYPE *cthis) {
  cgraph_size_t hash = 0;
  if (NULL != cthis) {
    cgraph_size_t i = 0, hbyte = 0;
    for (; i < cthis->len; i++) {
      hash = (hash << (CGRAPH_SIZE_BITS / 8)) + cthis->data[i];
      if (0 != (hbyte = hash & (0xFUL << (7 * CGRAPH_SIZE_BITS / 8)))) {
        hash ^= (hbyte >> (3 * CGRAPH_SIZE_BITS / 4));
        hash &= ~hbyte;
      }
    }
  }

  return hash;
}

cgraph_size_t FUNCTION(NAME, bkdrhash)(const TYPE *cthis) {
  cgraph_size_t hash = 0;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      hash = hash * 131 + cthis->data[i];
    }
  }

  return CGRAPH_ABS(hash);
}

/** package of <ctype.h> */
cgraph_bool_t FUNCTION(NAME, isalnum)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      if (!cgraph_math_isalnum(cthis->data[i])) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isalpha)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      if (!cgraph_math_isalpha(cthis->data[i])) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isblank)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      if (!cgraph_math_isblank(cthis->data[i])) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isdigit)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      if (!cgraph_math_isdec(cthis->data[i])) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, islower)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      if (!cgraph_math_islower(cthis->data[i])) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isprint)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      if (!cgraph_math_isprint(cthis->data[i])) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isspace)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      if (!cgraph_math_isspace(cthis->data[i])) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isupper)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      if (!cgraph_math_isupper(cthis->data[i])) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ispsplit)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      if (!cgraph_math_ispsplit(cthis->data[i])) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isnline)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      if (!cgraph_math_isnline(cthis->data[i], cthis->data[i + 1])) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }
  return flag;
}

TYPE *FUNCTION(NAME, lower)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      cthis->data[i] = cgraph_math_tolower(cthis->data[i]);
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, upper)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      cthis->data[i] = cgraph_math_toupper(cthis->data[i]);
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, initc)(TYPE *cthis, const cgraph_char_t *data,
                            const cgraph_size_t len) {
  if ((NULL != cthis) && (NULL != data)) {
    cgraph_size_t _len = CGRAPH_MIN(len, cthis->size);
    cgraph_strncpy(cthis->data, data, _len);
    cthis->len = _len;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, initf)(TYPE *cthis, const cgraph_char_t *format, ...) {
  if (NULL != cthis) {
    va_list args;
    va_start(args, format);
    cthis->len = cgraph_file_vsnprintf(cthis->data, cthis->size, format, args);
    va_end(args);
  }

  return cthis;
}

TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t _size = CGRAPH_SIZE(z), len = (x->len + y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, _size, len, &error);
    if (CGRAPH_FALSE == error) {
      cgraph_memcpy(z->data, x->data, x->len);
      cgraph_memcpy(&(z->data[x->len]), y->data, y->len);
      z->data[len] = '\0';
      z->len = len;
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z) {
  if (NULL != x) {
    cgraph_bool_t error = CGRAPH_FALSE;
    cgraph_size_t _len = x->len;
    DATA_TYPE *xd = &(x->data[x->len - 1]), *yd = &(y->data[y->len - 1]);
    if (x->len >= y->len) {
      cgraph_size_t i = y->len;
      for (error = CGRAPH_TRUE; i > 0; i--, xd--, yd--) {
        if (*xd != *yd) {
          error = CGRAPH_FALSE;
          break;
        }
      }
      if (CGRAPH_TRUE == error) {
        _len -= y->len;
        error = CGRAPH_FALSE;
      }
    }
    z = FUNCTION(NAME, realloc)(z, DATA_ID, CGRAPH_SIZE(z), _len, &error);
    if (CGRAPH_FALSE == error) {
      cgraph_strncpy(z->data, x->data, _len);
      z->len = _len;
      z->data[_len] = '\0';
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, subc)(const TYPE *x, const DATA_TYPE y, TYPE *z) {
  if (NULL != x) {
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, CGRAPH_SIZE(z), x->len, &error);
    if (CGRAPH_FALSE == error) {
      cgraph_size_t _len = z->len = (x->len - 1);
      cgraph_strncpy(z->data, x->data, _len);
      if (y != x->data[_len]) {
        z->data[_len] = x->data[_len];
        z->len += 1;
      }
      z->data[z->len - 1] = '\0';
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t len = x->len + y->len;
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, CGRAPH_SIZE(z), len, &error);
    if (CGRAPH_FALSE == error) {
      cgraph_size_t i, j;
      DATA_UTYPE *zd = (DATA_UTYPE *)&(z->data[0]);
      z->len = len;
      cgraph_memset(zd, 0, len + 1);
      if (cgraph_math_isnum(x->data[0]) && cgraph_math_isnum(y->data[0])) {
        DATA_TYPE *xd = &(x->data[x->len - 1]), *yd, *zd;
        DATA_UTYPE carry, sum;
        for (i = x->len - 1; i >= 0; i--, xd--) {
          for (carry = 0, j = 0, yd = &(y->data[y->len - 1]),
              zd = &(z->data[--len]);
               j < y->len; j++, yd--, zd--) {
            sum = *zd + (*xd - '0') * (*yd - '0') + carry;
            *zd = sum % 10;
            carry = sum / 10;
          }
          *zd = carry;
        }
        for (i = 0; i < z->len; i++) {
          z->data[i] += '0';
        }
      } else {
        for (i = 0; i < x->len; i++) {
          for (j = 0; j < y->len; j++) {
            z->data[i + j] += x->data[i] * y->data[j];
          }
        }
      }
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, muli)(const TYPE *x, const cgraph_size_t y, TYPE *z) {
  if ((NULL != x) && (0 < y)) {
    cgraph_bool_t error = CGRAPH_FALSE;
    cgraph_size_t _len = y * x->len;
    z = FUNCTION(NAME, realloc)(z, CGRAPH_CHAR_T, CGRAPH_SIZE(z), _len, &error);
    if (CGRAPH_FALSE == error) {
      DATA_TYPE *zd = &(z->data[0]);
      cgraph_size_t i = 0;
      for (; i < y; i++, zd += x->len) {
        zd = cgraph_memcpy(zd, x->data, x->len);
      }
      z->len = _len;
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_bool_t error = CGRAPH_FALSE;
    cgraph_size_t *next =
        (cgraph_size_t *)cgraph_calloc(y->len * sizeof(cgraph_size_t));
    next = cgraph_math_kmpnext(y->data, next, y->len);
    z->len = cgraph_math_kmpcnt(x->data, x->len, y->data, next, y->len);
    cgraph_free(next);
    z = FUNCTION(NAME, realloc)(z, DATA_ID, CGRAPH_SIZE(z), CGRAPH_CBUF_SIZE0,
                                &error);
    if (CGRAPH_FALSE == error) {
      z->len = cgraph_file_snprintf(z->data, z->size, "%ld", z->len);
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, divc)(const TYPE *x, const DATA_TYPE y, TYPE *z) {
  if (NULL != x) {
    cgraph_bool_t error = CGRAPH_FALSE;
    cgraph_size_t i = 0;
    for (z->len = 0; i < x->len; i++) {
      if (y == x->data[i]) {
        z->len += 1;
      }
    }
    z = FUNCTION(NAME, realloc)(z, DATA_ID, CGRAPH_SIZE(z), CGRAPH_CBUF_SIZE0,
                                &error);
    if (CGRAPH_FALSE == error) {
      z->len = cgraph_file_snprintf(z->data, z->size, "%ld", z->len);
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, mod)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, CGRAPH_SIZE(z), x->len, &error);
    if (CGRAPH_FALSE == error) {
      cgraph_size_t *next =
          (cgraph_size_t *)cgraph_calloc(y->len * sizeof(cgraph_size_t));
      next = cgraph_math_kmpnext(y->data, next, y->len);
      z->len =
          cgraph_math_kmpsub(x->data, z->data, x->len, y->data, next, y->len);
      cgraph_free(next);
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, modc)(const TYPE *x, const DATA_TYPE y, TYPE *z) {
  if (NULL != x) {
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, CGRAPH_SIZE(z), x->len, &error);
    if (CGRAPH_FALSE == error) {
      cgraph_size_t i = 0;
      for (z->len = 0; i < x->len; i++) {
        if (y != x->data[i]) {
          z->data[z->len++] = x->data[i];
        }
      }
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, format)(TYPE *cthis) { return cthis; }

cgraph_bool_t FUNCTION(NAME, match)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y) && (x->len == y->len)) {
    cgraph_size_t i = 0;
    for (flag = CGRAPH_TRUE; i < x->len; i++) {
      if (cgraph_math_toupper(x->data[i]) != cgraph_math_toupper(y->data[i])) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  } else if ((NULL == x) && (NULL == y)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y) && (x->len == y->len)) {
    cgraph_size_t i = 0;
    DATA_TYPE *xd = &(x->data[x->len - 1]), *yd = &(y->data[y->len - 1]);
    for (flag = CGRAPH_TRUE; i < x->len; i++, xd--, yd--) {
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

cgraph_bool_t FUNCTION(NAME, gr)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    if (x->len == y->len) {
      cgraph_size_t i = 0;
      DATA_TYPE *xd = &(x->data[x->len - 1]), *yd = &(y->data[y->len - 1]);
      for (; (*xd == *yd) && (i < x->len); i++, xd--, yd--) {
      }
      if (*xd > *yd) {
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

TYPE *FUNCTION(NAME, chomp)(TYPE *cthis) {
#ifdef __PLAT_WINDOWS
  if ((NULL != cthis) && (1 < cthis->len)) {
    if ((__PLAT_LEND_C0 == cthis->data[cthis->len - 2]) &&
        (__PLAT_LEND_C1 == cthis->data[cthis->len - 1])) {
      cthis->len -= 2;
      cthis->data[cthis->len] = '\0';
    }
  }
#else
  if (CGRAPH_ISNEMPTY(cthis)) {
    if (__PLAT_LEND_C == cthis->data[cthis->len - 1]) {
      cthis->len -= 1;
      cthis->data[cthis->len] = '\0';
    }
  }
#endif

  return cthis;
}

TYPE *FUNCTION(NAME, abs)(TYPE *cthis) { return cthis; }

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

cgraph_bool_t FUNCTION(NAME, startswith)(const TYPE *cthis,
                                         const DATA_TYPE *cstr,
                                         const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != cthis) && (NULL != cstr) && (len <= cthis->len)) {
    cgraph_size_t i = 0;
    for (flag = CGRAPH_TRUE; i < len; i++) {
      if (cstr[i] != cthis->data[i]) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, endswith)(const TYPE *cthis, const DATA_TYPE *cstr,
                                       const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != cthis) && (NULL != cstr) && (len <= cthis->len)) {
    DATA_TYPE *data = &(cthis->data[cthis->len - len]);
    cgraph_size_t i = 0;
    for (flag = CGRAPH_TRUE; i < len; i++) {
      if (cstr[i] != data[i]) {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }

  return flag;
}

#include "cgraph_template_off.h"
