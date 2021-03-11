#include <ctype.h>
#include <string.h>

#include "cgraph_file.h"
#include "cgraph_memory.h"
#include "cgraph_string.h"

#define TYPE_STRING
#include "template.h"

/**/
#include "data_base.ct"

cgraph_int_t FUNCTION(NAME, printf)(const TYPE *cthis) {
  return fprintf(stdout, OUT_FORMAT, cthis->data);
}

cgraph_int_t FUNCTION(NAME, fprintf)(FILE *fp, const TYPE *cthis) {
  return fprintf(fp, OUT_FORMAT, cthis->data);
}

cgraph_int_t FUNCTION(NAME, snprintf)(cgraph_char_t *buffer,
                                      const cgraph_size_t size,
                                      const TYPE *cthis) {
  return cgraph_file_snprintf(buffer, size, OUT_FORMAT, cthis->data);
}

/**
  times 33 hash algorithm proposed by Daniel J. Bernstein
  hash = hash * 33 + cthis->data[i] or
  hash += hash << 5 + cthis->data[i]
*/
cgraph_size_t FUNCTION(NAME, hash)(const TYPE *cthis) {
  cgraph_size_t hash = 0;
  if (NULL != cthis) {
    cgraph_size_t i;
    for (i = 0; i < cthis->len; i++) {
      hash += (hash << 5) + cthis->data[i];
    }
  }

  return hash;
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != cthis) && ('\0' == cthis->data[cthis->len])) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

/**                          string hash functions */
cgraph_size_t FUNCTION(NAME, jshash)(const TYPE *cthis) {
  cgraph_size_t hash = 1315423911L, i;
  for (i = 0; i < cthis->len; i++) {
    hash ^= ((hash << 5) + (hash >> 2) + cthis->data[i]);
  }

  return hash;
}

cgraph_size_t FUNCTION(NAME, sdbmhash)(const TYPE *cthis) {
  cgraph_size_t hash = 0, i;
  for (i = 0; i < cthis->len; i++) {
    hash = ((hash << 6) - hash + (hash << 16) + cthis->data[i]);
  }
  return hash;
}

cgraph_size_t FUNCTION(NAME, rshash)(const TYPE *cthis) {
  cgraph_size_t hash = 0, a = 63689, b = 378551, i;
  for (i = 0; i < cthis->len; i++) {
    hash = hash * a + cthis->data[i];
    a *= b;
  }

  return hash;
}

cgraph_size_t FUNCTION(NAME, elfhash)(const TYPE *cthis) {
  cgraph_size_t hash = 0, hbyte = 0, i;

  for (i = 0; i < cthis->len; i++) {
    hash = (hash << (CGRAPH_SIZE_BIT / 8)) + cthis->data[i];
    if (0 != (hbyte = hash & (0xFUL << (7 * CGRAPH_SIZE_BIT / 8)))) {
      hash ^= (hbyte >> (3 * CGRAPH_SIZE_BIT / 4));
      hash &= ~hbyte;
    }
  }

  return hash;
}

cgraph_size_t FUNCTION(NAME, bkdrhash)(const TYPE *cthis) {
  cgraph_size_t hash = 0, i;
  for (i = 0; i < cthis->len; i++) {
    hash = hash * 131 + cthis->data[i];
  }

  return CGRAPH_ABS(hash);
}

/** package of ctype.h */
cgraph_bool_t FUNCTION(NAME, isalnum)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if (NULL != cthis) {
    cgraph_size_t i;
    for (i = 0; i < cthis->len; i++) {
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
    cgraph_size_t i;
    for (i = 0; i < cthis->len; i++) {
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
    cgraph_size_t i;
    for (i = 0; i < cthis->len; i++) {
#if CGRAPH_STDC_VERSION >= 199901L
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
    cgraph_size_t i;
    for (i = 0; i < cthis->len; i++) {
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
    cgraph_size_t i;
    for (i = 0; i < cthis->len; i++) {
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
    cgraph_size_t i;
    for (i = 0; i < cthis->len; i++) {
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
    cgraph_size_t i;
    for (i = 0; i < cthis->len; i++) {
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
    cgraph_size_t i;
    for (i = 0; i < cthis->len; i++) {
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
    cgraph_size_t i;
    for (i = 0; i < cthis->len; i++) {
      if (CGRAPH_PLAT_PSPLIT_C != cthis->data[i]) {
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
    for (i = 0; i < cthis->len; i++) {
#ifdef __CGRAPH_PLAT_WINDOWS
      if (('\r' != cthis->data[i]) && ('\n' != cthis->data[i + 1])) {
#else
      if (CGRAPH_PLAT_NLINE_C != cthis->data[i]) {
#endif
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }
  return flag;
}

/**
 * @brief
 *       cthis == NULL : size > 0 ? size : 1
 *       cthis != NULL : size <= 0 ? cthis->size : min{cthis->size, size}
 */
TYPE *FUNCTION(NAME, zero)(TYPE *cthis, const cgraph_size_t size) {
  cgraph_size_t _size = 0;
  if (NULL == cthis) {
    _size = (size > 0 ? size : 1);
    cthis = FUNCTION(NAME, calloc)(DATA_ID, _size);
  } else {
    _size = (size <= 0 ? cthis->size : CGRAPH_MIN(cthis->size, size));
  }
  if (NULL != cthis) {
    cgraph_memset(cthis->data, _size, '0');
    cthis->len = size;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, one)(TYPE *cthis, const cgraph_size_t size) {
  cgraph_size_t _size = 0;
  if (NULL == cthis) {
    _size = (size > 0 ? size : 1);
    cthis = FUNCTION(NAME, calloc)(DATA_ID, _size);
  } else {
    _size = (size <= 0 ? cthis->size : CGRAPH_MIN(cthis->size, size));
  }
  if (NULL != cthis) {
    cgraph_memset(cthis->data, _size, '1');
    cthis->len = size;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, initf)(TYPE *cthis, const cgraph_char_t *format, ...) {
  cgraph_size_t len;
  if ((NULL != cthis) && (NULL != format)) {
    va_list args;
    va_start(args, format);
    len = __cgraph_vsnprintf(cthis->data, cthis->size, format, args);
    va_end(args);
    if (0 < len) {
      cthis->len = len;
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t _size = CGRAPH_SIZE(z);
    cgraph_size_t len = CGRAPH_MIN(x->len, y->len),
                  size = CGRAPH_MAX(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    FUNCTION(NAME, realloc)
    (z, DATA_ID, _size, size, &error);
    if (CGRAPH_FALSE == error) {
      cgraph_size_t i;
      DATA_TYPE *xd = &(x->data[x->len - 1]), *yd = &(y->data[y->len - 1]),
                *zd = &(z->data[size - 1]);
      for (i = 0; i < len; i++, xd--, yd--, zd--) {
        *zd = *xd + *yd;
      }
      for (i = len; i < x->len; i++, xd--, zd--) {
        *zd = *xd;
      }
      for (i = len; i < y->len; i++, yd--, zd--) {
        *zd = *yd;
      }
      z->len = size;
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z) { return z; }

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z) { return z; }

TYPE *FUNCTION(NAME, muli)(const TYPE *x, const cgraph_int_t y, TYPE *z) {
  if ((NULL != x) && (0 < y)) {
    cgraph_bool_t error = CGRAPH_FALSE;
    cgraph_size_t _len = y * x->len;
    _len = (_len >= 0) ? _len : CGRAPH_SIZE_MAX;
    z = FUNCTION(NAME, realloc)(z, CGRAPH_CHAR_T, x->len, _len, &error);
    if (CGRAPH_FALSE == error) {
      DATA_TYPE *zd = z->data;
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

TYPE *FUNCTION(NAME, abs)(TYPE *cthis) { return cthis; }

TYPE *FUNCTION(NAME, format)(TYPE *cthis) { return cthis; }

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y) && (x->len == y->len)) {
    cgraph_size_t i;
    for (i = 0; i < x->len; i++) {
      if (x->data[i] != y->data[i]) {
        break;
      }
    }
    if (i >= x->len) {
      flag = CGRAPH_TRUE;
    }
  } else if (NULL == x && NULL == y) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ne)(const TYPE *x, const TYPE *y) {
  return CGRAPH_TEST(CGRAPH_FALSE == FUNCTION(NAME, eq)(x, y));
}

cgraph_bool_t FUNCTION(NAME, gr)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (NULL != x && NULL != y) {
    if (x->len == y->len) {
      cgraph_size_t i;
      for (i = 0; i < x->len; i++) {
        if (x->data[i] <= y->data[i]) {
          break;
        }
      }
      if (i >= x->len) {
        flag = CGRAPH_TRUE;
      }
    } else if (x->len > y->len) {
      flag = CGRAPH_TRUE;
    }
  } else if (NULL != x && NULL == y) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ge)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (NULL != x && NULL != y) {
    if (x->len == y->len) {
      cgraph_size_t i;
      for (i = 0; i < x->len; i++) {
        if (x->data[i] < y->data[i]) {
          break;
        }
      }
      if (i >= x->len) {
        flag = CGRAPH_TRUE;
      }
    }
  } else if (NULL == y) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ls)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (NULL != x && NULL != y) {
    if (x->len == y->len) {
      cgraph_size_t i;
      for (i = 0; i < x->len; i++) {
        if (x->data[i] >= y->data[i]) {
          break;
        }
      }
      if (i >= x->len) {
        flag = CGRAPH_TRUE;
      }
    }
  } else if (NULL == y) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, le)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (NULL != x && NULL != y) {
    if (x->len == y->len) {
      cgraph_size_t i;
      for (i = 0; i < x->len; i++) {
        if (x->data[i] > y->data[i]) {
          break;
        }
      }
      if (i >= x->len) {
        flag = CGRAPH_TRUE;
      }
    }
  } else if (NULL == y) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

#include "template_off.h"
