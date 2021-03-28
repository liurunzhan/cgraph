#include "cgraph_base.h"
#include "cgraph_int8.h"

#include "cgraph_bigint.h"

#define TYPE_BIGINT
#include "cgraph_template.h"

/** template module */
#include "template_data.ct"

static cgraph_char_t __buffer__[CGRAPH_FILE_BUFFER_SIZE];

void FUNCTION(NAME, clrbuffer)(void) {
  cgraph_memset(__buffer__, CGRAPH_FILE_BUFFER_SIZE, 0);
}

CGRAPH_INLINE cgraph_size_t FUNCTION(NAME, lenofbuffer)(void) {
  return CGRAPH_FILE_BUFFER_SIZE;
}

cgraph_size_t FUNCTION(NAME, printf)(const TYPE *cthis) {
  return FUNCTION(NAME, fprintf)(stdout, cthis);
}

cgraph_size_t FUNCTION(NAME, fprintf)(FILE *fp, const TYPE *cthis) {
  cgraph_size_t len = 0;
  if (NULL != cthis) {
    cgraph_size_t size = cthis->len * 3 + 1;
    if (size <= CGRAPH_FILE_BUFFER_SIZE) {
      len = FUNCTION(NAME, snprintf)(__buffer__, size, cthis);
      cgraph_file_rputc(fp, __buffer__, len);
    }
#ifdef DEBUG
    else {
      fprintf(stderr, "out of %s buffer size %ld\n", FUNCTION(NAME, tname)(),
              CGRAPH_FILE_BUFFER_SIZE);
    }
#endif
  }

  return len;
}

cgraph_size_t FUNCTION(NAME, snprintf)(cgraph_char_t *buffer,
                                       const cgraph_size_t size,
                                       const TYPE *cthis) {
  cgraph_size_t len = 0, _size = size;
  if ((NULL != buffer) && (0 < _size) && (NULL != cthis)) {
    TYPE *copy = FUNCTION(NAME, copy)(cthis, cthis->len);
    if (NULL != copy) {
      cgraph_size_t i, start = copy->len - 1;
      cgraph_int_t num, res;
      if (CGRAPH_FALSE == cthis->postive) {
        _size -= 1;
      }
      while ((0 <= start) && (len < _size)) {
        for (res = 0, i = start; i >= 0; i--) {
          num = copy->data[i] + res * (DATA_MAX + 1);
          res = num % 10;
          copy->data[i] = num / 10;
        }
        buffer[len++] = res + '0';
        while (0 == copy->data[start]) {
          start--;
        }
      }
      if (CGRAPH_FALSE == cthis->postive) {
        buffer[len++] = '-';
      }
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
    while (start < len) {
      for (res = 0, i = start; i < len; i++) {
        num = buffer[i] + res * 10;
        res = num % (DATA_MAX + 1);
        buffer[i] = num / (DATA_MAX + 1);
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
  cgraph_char_t *digit;
  cgraph_size_t len = cgraph_math_lenofdec(data, &digit);
  TYPE *cthis = FUNCTION(NAME, calloc)(DATA_ID, len / 3 + 1);
  cgraph_char_t *buffer = cgraph_calloc(len);
  cthis = FUNCTION(NAME, initc)(cthis, buffer, len, digit);
  cgraph_free(buffer);

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

CGRAPH_INLINE cgraph_int_t FUNCTION(NAME, signbit)(const TYPE *cthis) {
  return cthis->postive;
}

TYPE *FUNCTION(NAME, abs)(TYPE *cthis) {
  if (NULL != cthis) {
    cthis->postive = CGRAPH_TRUE;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, opp)(TYPE *cthis) {
  if (NULL != cthis) {
    cthis->postive =
        ((CGRAPH_TRUE == cthis->postive) ? CGRAPH_FALSE : CGRAPH_TRUE);
  }

  return cthis;
}

cgraph_bool_t FUNCTION(NAME, ispos)(const TYPE *cthis) {
  return ((NULL != cthis) ? cthis->postive : CGRAPH_FALSE);
}

cgraph_bool_t FUNCTION(NAME, isneg)(const TYPE *cthis) {
  return ((NULL != cthis) ? CGRAPH_TEST(cthis->postive == CGRAPH_FALSE)
                          : CGRAPH_FALSE);
}

TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t _size = z->size;
    cgraph_size_t len = CGRAPH_MIN(x->len, y->len),
                  size = CGRAPH_MAX(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, _size, size + 1, &error);
    if (CGRAPH_FALSE == error) {
      cgraph_size_t i;
      DATA_TYPE carry = 0;
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
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
        TYPE *_x = (TYPE *)x, *_y = (TYPE *)y;
        if ((_x->len < _y->len) ||
            ((_x->len == _y->len) && (_x->data[0] < _y->data[0]))) {
          SWAP(_x, _y);
        }
        if (CGRAPH_FALSE == x->postive) {
        } else {
        }
      }
      z->postive = x->postive;
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t _size = z->size;
    cgraph_size_t len = CGRAPH_MIN(x->len, y->len),
                  size = CGRAPH_MAX(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, _size, size, &error);
    if (CGRAPH_FALSE == error) {
      cgraph_size_t i;
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
      for (i = 1; i < len; i++, xd++, yd++, zd++) {
        *zd = *xd - *yd;
      }
      z->postive = x->postive;
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y)) {
    cgraph_size_t _size = z->size;
    cgraph_size_t len = CGRAPH_MIN(x->len, y->len), size = x->len + y->len;
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, _size, size, &error);
    if (CGRAPH_FALSE == error) {
      cgraph_size_t i;
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
      for (i = 1; i < len; i++, xd++, yd++, zd++) {
        *zd = ((*xd) * (*yd));
      }
      z->postive = x->postive;
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z) {
  cgraph_size_t _len = z->size;
  cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
  cgraph_bool_t error = CGRAPH_FALSE;
  z = FUNCTION(NAME, realloc)(z, DATA_ID, _len, len, &error);
  if (CGRAPH_FALSE == error) {
    if (x->postive == y->postive) {
      cgraph_size_t i;
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
      for (i = 1; i < len; i++, xd++, yd++, zd++) {
        *zd = ((*xd) / (*yd));
      }
      z->postive = x->postive;
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
    if (i >= len) {
      for (; i < x->len; i++, xd++) {
        if (0 != *xd) {
          flag = CGRAPH_FALSE;
          break;
        }
      }
      for (; i < y->len; i++, yd++) {
        if (0 != *yd) {
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

cgraph_bool_t FUNCTION(NAME, ne)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if ((NULL != x) && (NULL != y) && (x->postive == y->postive)) {
    cgraph_size_t len = CGRAPH_MIN(x->len, y->len), i;
    DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]);
    for (flag = CGRAPH_FALSE, i = 0; i < len; i++, xd++, yd++) {
      if (*xd != *yd) {
        flag = CGRAPH_TRUE;
        break;
      }
    }
    if (i >= len) {
      for (; i < x->len; i++, xd++) {
        if (0 != *xd) {
          flag = CGRAPH_TRUE;
          break;
        }
      }
      for (; i < y->len; i++, yd++) {
        if (0 != *yd) {
          flag = CGRAPH_TRUE;
          break;
        }
      }
    }
  } else if ((NULL == x) && (NULL == y)) {
    flag = CGRAPH_FALSE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, gr)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y) && (x->postive == y->postive)) {
    cgraph_size_t len = CGRAPH_MIN(x->len, y->len), i = 0;
    DATA_TYPE *xd = &(x->data[x->len - 1]), *yd = &(y->data[y->len - 1]);
    if (CGRAPH_FALSE == x->postive) {
      xd = &(y->data[y->len - 1]);
      yd = &(x->data[x->len - 1]);
    }
    for (; i < len; i++, xd--, yd--) {
      if (*xd <= *yd) {
        break;
      }
    }
    if (i >= len) {
      flag = CGRAPH_TRUE;
    }
  } else if ((NULL != x) && (NULL == y)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ge)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    if (x->postive == y->postive) {
      cgraph_size_t len = CGRAPH_MIN(x->len, y->len), i = 0;
      DATA_TYPE *xd = &(x->data[x->len - 1]), *yd = &(y->data[y->len - 1]);
      if (CGRAPH_FALSE == x->postive) {
        xd = &(y->data[y->len - 1]);
        yd = &(x->data[x->len - 1]);
      }
      for (; i < len; i++, xd--, yd--) {
        if (*xd < *yd) {
          break;
        }
      }
      if (i < 0) {
        flag = CGRAPH_TRUE;
      }
    } else if (CGRAPH_TRUE == x->postive && CGRAPH_FALSE == y->postive) {
      flag = CGRAPH_TRUE;
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ls)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    if (x->postive == y->postive) {
      cgraph_size_t len = CGRAPH_MIN(x->len, y->len), i = 0;
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]);
      if (CGRAPH_FALSE == x->postive) {
        xd = &(y->data[0]);
        yd = &(x->data[0]);
      }
      for (; i < len; i++, xd++, yd++) {
        if (*xd >= *yd) {
          break;
        }
      }
      if (i < 0) {
        flag = CGRAPH_TRUE;
      }
    } else if (CGRAPH_FALSE == x->postive && CGRAPH_TRUE == y->postive) {
      flag = CGRAPH_TRUE;
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, le)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    if (x->postive == y->postive) {
      cgraph_size_t len = CGRAPH_MIN(x->len, y->len), i = 0;
      DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]);
      if (CGRAPH_FALSE == x->postive) {
        xd = &(y->data[0]);
        yd = &(x->data[0]);
      }
      for (; i < len; i++, xd++, yd++) {
        if (*xd > *yd) {
          break;
        }
      }
      if (i < 0) {
        flag = CGRAPH_TRUE;
      }
    } else if (CGRAPH_FALSE == x->postive && CGRAPH_TRUE == y->postive) {
      flag = CGRAPH_TRUE;
    }
  }

  return flag;
}

TYPE *FUNCTION(NAME, format)(TYPE *cthis) {
  if (NULL != cthis) {
    DATA_TYPE *data = &(cthis->data[cthis->len - 1]);
    for (; (0 == *data) && (0 < cthis->len); data--, cthis->len--) {
    }
  }

  return cthis;
}

/**
 * @brief
 */
TYPE *FUNCTION(NAME, unit)(TYPE *cthis, const cgraph_size_t len) {
  cgraph_size_t _len = FUNCTION(NAME, minoflen)(cthis, len);
  if (NULL != cthis) {
    cthis->data[0] = 1;
    cthis->len = _len;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, unit_inv)(TYPE *cthis, const cgraph_size_t len) {
  return FUNCTION(NAME, unit)(cthis, len);
}

cgraph_size_t FUNCTION(NAME, cntones)(const TYPE *cthis) {
  cgraph_size_t size = 0;

  return size;
}

cgraph_size_t FUNCTION(NAME, cntzeros)(const TYPE *cthis) {
  return CGRAPH_TRUE;
}

#include "cgraph_template_off.h"
