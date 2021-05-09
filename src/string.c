#include <ctype.h>
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

cgraph_size_t FUNCTION(NAME, snprint)(cgraph_char_t *buffer,
                                      const cgraph_size_t size,
                                      const TYPE *cthis) {
  cgraph_size_t len = 0;
  if ((NULL != buffer) && (NULL != cthis)) {
    len = CGRAPH_MIN(size, cthis->len);
    cgraph_memcpy(buffer, cthis->data, len);
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
  return CGRAPH_TEST((NULL != cthis) && (0 < cthis->len));
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

/** package of ctype.h */
cgraph_bool_t FUNCTION(NAME, isalnum)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      if (!isalnum(cthis->data[i])) {
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
      if (!isalpha(cthis->data[i])) {
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
#if __STDC_VERSION__ >= 199901L
      if (isblank(cthis->data[i])) {
#else
      if ((' ' != cthis->data[i]) && ('\t' != cthis->data[i])) {
#endif
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
      if (!isdigit(cthis->data[i])) {
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
      if (!islower(cthis->data[i])) {
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
      if (!isprint(cthis->data[i])) {
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
      if (!isspace(cthis->data[i])) {
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
      if (!isupper(cthis->data[i])) {
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
      if (__PLAT_PSPLIT_C != cthis->data[i]) {
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
#ifdef __PLAT_WINDOWS
      if (('\r' != cthis->data[i]) && ('\n' != cthis->data[i + 1])) {
#else
      if (__PLAT_NLINE_C != cthis->data[i]) {
#endif
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }
  return flag;
}

TYPE *FUNCTION(NAME, tolower)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      cthis->data[i] = tolower(cthis->data[i]);
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, toupper)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      cthis->data[i] = toupper(cthis->data[i]);
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, initf)(TYPE *cthis, const cgraph_char_t *format, ...) {
  cgraph_size_t len;
  if ((NULL != cthis) && (NULL != format)) {
    va_list args;
    va_start(args, format);
    len = cgraph_file_snprintf(cthis->data, cthis->size, format, args);
    va_end(args);
    if (0 < len) {
      cthis->len = len;
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t _size = CGRAPH_SIZE(z), size = (x->len + y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    FUNCTION(NAME, realloc)
    (z, DATA_ID, _size, size, &error);
    if (CGRAPH_FALSE == error) {
      cgraph_memcpy(z->data, x->data, x->len);
      cgraph_memcpy(z->data + x->len, y->data, y->len);
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t _size = CGRAPH_SIZE(z), size = x->len;
    cgraph_bool_t error = CGRAPH_FALSE;
    FUNCTION(NAME, realloc)
    (z, DATA_ID, _size, size, &error);
    if (CGRAPH_FALSE == error) {
      cgraph_size_t i = 0;
      cgraph_memcpy(z->data, x->data, x->len);
      for (; i < x->len; i++) {
      }
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
  }

  return z;
}

TYPE *FUNCTION(NAME, muli)(const TYPE *x, const cgraph_size_t y, TYPE *z) {
  if ((NULL != x) && (0 < y)) {
    cgraph_bool_t error = CGRAPH_FALSE;
    cgraph_size_t _len = y * x->len;
    _len = (_len >= 0) ? _len : CGRAPH_SIZE_MAX;
    z = FUNCTION(NAME, realloc)(z, CGRAPH_CHAR_T, x->len, _len, &error);
    if (CGRAPH_FALSE == error) {
      DATA_TYPE *zd = &(z->data[0]);
      cgraph_size_t i = 0;
      for (i = 0; i < y; i++) {
        zd = cgraph_memcpy(zd, x->data, x->len);
        zd += x->len;
      }
    }
  }
  return z;
}

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z) { return z; }

TYPE *FUNCTION(NAME, mod)(const TYPE *x, const TYPE *y, TYPE *z) { return z; }

TYPE *FUNCTION(NAME, format)(TYPE *cthis) { return cthis; }

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y) && (x->len == y->len)) {
    cgraph_size_t i = 0;
    for (flag = CGRAPH_TRUE; i < x->len; i++) {
      if (x->data[i] != y->data[i]) {
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
  if (NULL != x && NULL != y) {
    if (x->len == y->len) {
      cgraph_size_t i = 0;
      for (flag = CGRAPH_TRUE; i < x->len; i++) {
        if (x->data[i] <= y->data[i]) {
          flag = CGRAPH_FALSE;
          break;
        }
      }
    } else if (x->len > y->len) {
      flag = CGRAPH_TRUE;
    }
  } else if (NULL != x && NULL == y) {
    flag = CGRAPH_TRUE;
  }

  return flag;
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

#include "cgraph_template_off.h"
