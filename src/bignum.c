#include <ctype.h>

#include "cgraph_base.h"
#include "cgraph_bignum.h"

#define TYPE_BIGNUM
#include "cgraph_template.h"

/**template module*/
#include "template_data.ct"

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

/*
  BKDR Hash Algorithm
  hash = (hash * 31) + (cthis->data[i] - '0')
*/
cgraph_size_t FUNCTION(NAME, hash)(const TYPE *cthis) {
  cgraph_size_t hash = 0, i;
  if (NULL != cthis) {
    for (i = 0; i < cthis->len; i++) {
      hash = (hash * 31) + (cthis->data[i] - '0');
    }
  }

  return CGRAPH_ABS(hash);
}

CGRAPH_INLINE cgraph_int_t FUNCTION(NAME, signbit)(const TYPE *cthis) {
  return CGRAPH_TEST(cthis->data[0] != '-');
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (NULL != cthis) {
    cgraph_size_t i = 0, point_cnt = 0;
    flag = CGRAPH_TRUE;
    if (('+' == cthis->data[i]) || ('-' == cthis->data[i])) {
      i++;
    }
    for (; i < cthis->len; i++) {
      if ('0' > cthis->data[i] || '9' < cthis->data[i]) {
        if ('.' == cthis->data[i]) {
          point_cnt++;
        }
        if (1 < point_cnt) {
          flag = CGRAPH_FALSE;
          break;
        }
      }
    }
  }

  return flag;
}

TYPE *FUNCTION(NAME, abs)(TYPE *cthis) {
  if ((NULL != cthis) && ('-' == cthis->data[0])) {
    cthis->data += 1;
    cthis->len -= 1;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, opp)(TYPE *cthis) {
  if (NULL != cthis) {
    if ('-' == cthis->data[0]) {
      cthis->data += 1;
      cthis->len -= 1;
    } else {
      cthis->data -= 1;
      cthis->len += 1;
      cthis->data[0] = '-';
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, format)(TYPE *cthis) {
  if (NULL != cthis) {
    DATA_TYPE *data = &(cthis->data[0]);
    for (; ('0' == *data) && (0 < cthis->len); data++, cthis->len--) {
    }
    cthis->data = data;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z) { return z; }

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z) { return z; }

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z) { return z; }

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z) { return z; }

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    if ((x->len == y->len) && (x->point == y->point)) {
      if (x->data[0] == y->data[0]) {
        cgraph_size_t i;
        for (i = x->point - 1; i >= 0; i--) {
          if (x->data[i] != y->data[i]) {
            break;
          }
        }
        if (i < 0) {
          for (i = x->point; i < x->len; i++) {
            if (x->data[i] != y->data[i]) {
              break;
            }
          }
          if (i >= x->len) {
            flag = CGRAPH_TRUE;
          }
        }
      }
    }
  } else if ((NULL == x) && (NULL == y)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ne)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    if ((x->len == y->len) && (x->point == y->point)) {
      if (x->data[0] == y->data[0]) {
        cgraph_size_t i;
        for (i = x->point - 1; i >= 0; i--) {
          if (x->data[i] == y->data[i]) {
            break;
          }
        }
        if (i < 0) {
          for (i = x->point; i < x->len; i++) {
            if (x->data[i] == y->data[i]) {
              break;
            }
          }
          if (i >= x->len) {
            flag = CGRAPH_TRUE;
          }
        }
      }
    }
  } else if (NULL != x && NULL == y) {
    flag = CGRAPH_TRUE;
  } else if (NULL == x && NULL != y) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, gr)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    if (x->data[0] == y->data[0]) {
      cgraph_size_t i, j;
      for (i = x->point - 1, j = y->point - 1; i >= 0 && j >= 0; i--, j--) {
        if (x->data[i] <= y->data[j]) {
          break;
        }
      }
      if (i < 0) {
        for (i = x->point, j = y->point; i < x->len && j < y->len; i++, j++) {
          if (x->data[i] <= y->data[j]) {
            break;
          }
        }
        if (i >= x->len) {
          flag = CGRAPH_TRUE;
        }
      }
    } else if ('-' == y->data[0]) {
      flag = CGRAPH_TRUE;
    }
  } else if (NULL != x && NULL == y) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ge)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    if (x->data[0] == y->data[0]) {
      cgraph_size_t i, j;
      for (i = x->point - 1, j = y->point - 1; i >= 0 && j >= 0; i--, j--) {
        if (x->data[i] < y->data[j]) {
          break;
        }
      }
      if (i < 0) {
        for (i = x->point, j = y->point; i < x->len && j < y->len; i++, j++) {
          if (x->data[i] < y->data[j]) {
            break;
          }
        }
        if (i >= x->len) {
          flag = CGRAPH_TRUE;
        }
      }
    } else if ('-' == y->data[0]) {
      flag = CGRAPH_TRUE;
    }
  } else if (NULL != x && NULL == y) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ls)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    if (x->data[0] == y->data[0]) {
      cgraph_size_t i, j;
      for (i = x->point - 1, j = y->point - 1; i >= 0 && j >= 0; i--, j--) {
        if (x->data[i] <= y->data[j]) {
          break;
        }
      }
      if (i < 0) {
        for (i = x->point, j = y->point; i < x->len && j < y->len; i++, j++) {
          if (x->data[i] <= y->data[j]) {
            break;
          }
        }
        if (i >= x->len) {
          flag = CGRAPH_TRUE;
        }
      }
    } else if ('-' == y->data[0]) {
      flag = CGRAPH_TRUE;
    }
  } else if (NULL != x && NULL == y) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, le)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    if (x->data[0] == y->data[0]) {
      cgraph_size_t i, j;
      for (i = x->point - 1, j = y->point - 1; i >= 0 && j >= 0; i--, j--) {
        if (x->data[i] <= y->data[j]) {
          break;
        }
      }
      if (i < 0) {
        for (i = x->point, j = y->point; i < x->len && j < y->len; i++, j++) {
          if (x->data[i] <= y->data[j]) {
            break;
          }
        }
        if (i >= x->len) {
          flag = CGRAPH_TRUE;
        }
      }
    } else if ('-' == y->data[0]) {
      flag = CGRAPH_TRUE;
    }
  } else if (NULL != x && NULL == y) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isnan)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (NULL != cthis) {
    if (2 <= cthis->len) {
      if ('N' == cthis->data[0] || 'n' == cthis->data[0]) {
        if ('A' == cthis->data[1] || 'a' == cthis->data[1]) {
          if ((3 <= cthis->len) &&
              ('N' == cthis->data[2] || 'n' == cthis->data[2])) {
            flag = CGRAPH_TRUE;
          }
        }
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isinf)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ispinf)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;

  return flag;
}

cgraph_bool_t FUNCTION(NAME, isninf)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;

  return flag;
}

TYPE *FUNCTION(NAME, unit)(TYPE *cthis, const cgraph_size_t len) {
  cgraph_size_t _len = FUNCTION(NAME, minoflen)(cthis, len);
  if (NULL != cthis) {
    cthis->len = _len;
    cthis->point = 1;
    cthis->data[0] = '1';
    cthis->data[1] = '.';
    cthis->data[2] = '0';
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

#include "cgraph_template_off.h"
