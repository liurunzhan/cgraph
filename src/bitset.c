#include "cgraph_base.h"
#include "cgraph_bitset.h"

#define TYPE_BITSET
#include "cgraph_template.h"

/*template module*/
#include "template_data.ct"

cgraph_int_t FUNCTION(NAME, fprintf)(FILE *fp, const TYPE *cthis) {
  cgraph_int_t size = 0;
  if (NULL != cthis) {
    cgraph_size_t i;
    DATA_TYPE *data = &(cthis->data[0]);
    for (i = 0; i < cthis->len; i++, data++) {
      fprintf(fp, OUT_FORMAT, *data);
    }
    size = cthis->len;
  }

  return size;
}

static const cgraph_uint8_t cgraph_uint8_bits[8] = {1,    0x02, 0x04, 0x08,
                                                    0x10, 0x20, 0x40, 0x80};

cgraph_size_t FUNCTION(NAME, hash)(const TYPE *cthis) {
  cgraph_size_t hash = 0;
  if (NULL != cthis) {
    cgraph_size_t i;
    DATA_TYPE *data = &(cthis->data[0]);
    for (i = 0; i < cthis->len; i++, data++) {
      hash = (hash << 4) ^ (hash >> 28) ^ *data;
    }
  }

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis) {
  return CGRAPH_TEST(NULL != cthis);
}

CGRAPH_INLINE cgraph_int_t FUNCTION(NAME, signbit)(const TYPE *cthis) {
  return CGRAPH_TRUE;
}

TYPE *FUNCTION(NAME, bit)(const TYPE *cthis, const cgraph_size_t postion) {
  TYPE *res = FUNCTION(NAME, calloc)(DATA_ID, 1);
  if (NULL != res) {
    res->data[0] = BITSET_GET_BIT(cthis, postion);
    res->len = 1;
  }

  return res;
}

TYPE *FUNCTION(NAME, set)(TYPE *cthis, const cgraph_size_t postion) {
  cgraph_size_t i = BITSET_BYTE_POSTION(postion),
                j = BITSET_BIT_POSTION(postion);
  DATA_TYPE tmp = cthis->data[i], left_bits = ((tmp >> (j + 1)) << (j + 1)),
            right_bits = ((j == 0) ? 0 : (tmp ^ (~((DATA_ONES >> j) << j))));
  cthis->data[i] = left_bits + right_bits + (1 << j);

  return cthis;
}

TYPE *FUNCTION(NAME, clr)(TYPE *cthis, const cgraph_size_t pos) {
  cgraph_size_t i = pos / DATA_BITS, j = pos % DATA_BITS;
  DATA_TYPE tmp = cthis->data[i], left_bits = ((tmp >> (j + 1)) << (j + 1)),
            right_bits = ((j == 0) ? 0 : (tmp ^ (~((DATA_ONES >> j) << j))));
  cthis->data[i] = left_bits + right_bits;

  return cthis;
}

TYPE *FUNCTION(NAME, bits)(const TYPE *cthis, const cgraph_size_t min,
                           const cgraph_size_t max) {
  TYPE *res = NULL;

  return res;
}

TYPE *FUNCTION(NAME, sets)(TYPE *cthis, const cgraph_size_t min,
                           const cgraph_size_t max) {
  return cthis;
}

TYPE *FUNCTION(NAME, clrs)(TYPE *cthis, const cgraph_size_t min,
                           const cgraph_size_t max) {
  return cthis;
}

TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z) {
  cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
  cgraph_bool_t error = CGRAPH_FALSE;
  z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
  if (CGRAPH_FALSE == error) {
    DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
    cgraph_size_t i = 0;
    z->len = len;
    for (i = 0; i < len; i++, xd++, yd++, zd++) {
      *zd = (*xd) + (*yd);
    }
    for (; i < x->len; xd++, zd++) {
      *zd = *xd;
    }
    for (; i < y->len; yd++, zd++) {
      *zd = *yd;
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z) {
  cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
  cgraph_bool_t error = CGRAPH_FALSE;
  z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
  if (CGRAPH_FALSE == error) {
    DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
    cgraph_size_t i = 0;
    z->len = len;
    for (i = 0; i < len; i++, xd++, yd++, zd++) {
      *zd = (*xd) - (*yd);
    }
    for (; i < x->len; xd++, zd++) {
      *zd = *xd;
    }
    for (; i < y->len; yd++, zd++) {
      *zd = ~(*yd);
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z) {
  cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
  cgraph_bool_t error = CGRAPH_FALSE;
  z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
  if (CGRAPH_FALSE == error) {
    DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
    cgraph_size_t i = 0;
    for (i = 0; i < len; i++, xd++, yd++, zd++) {
      *zd = (*xd) * (*yd);
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z) {
  cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
  cgraph_bool_t error = CGRAPH_FALSE;
  z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
  if (CGRAPH_FALSE == error) {
    DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
    cgraph_size_t i = 0;
    for (i = 0; i < len; i++, xd++, yd++, zd++) {
      *zd = (*xd) / (*yd);
    }
  }

  return z;
}

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y) && (x->len == y->len)) {
    DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]);
    cgraph_size_t i;
    for (flag = CGRAPH_TRUE, i = 0; i < x->len; i++, xd++, yd++) {
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

cgraph_bool_t FUNCTION(NAME, ne)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_TRUE;
  if ((NULL != x) && (NULL != y) && (x->len == y->len)) {
    DATA_TYPE *xd = &(x->data[x->len - 1]), *yd = &(y->data[y->len - 1]);
    cgraph_size_t i;
    for (flag = CGRAPH_FALSE, i = 0; i < x->len; i++, xd--, yd--) {
      if (*xd != *yd) {
        flag = CGRAPH_TRUE;
        break;
      }
    }
  } else if ((NULL == x) && (NULL == y)) {
    flag = CGRAPH_FALSE;
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, gr)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ge)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ls)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;

  return flag;
}

cgraph_bool_t FUNCTION(NAME, le)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;

  return flag;
}

TYPE *FUNCTION(NAME, and)(const TYPE *x, const TYPE *y, TYPE *z) {
  cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
  cgraph_bool_t error = CGRAPH_FALSE;
  z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
  if (CGRAPH_FALSE == error) {
    DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
    cgraph_size_t i = 0;
    for (i = 0; i < len; i++, xd++, yd++, zd++) {
      *zd = CGRAPH_AND(*xd, *yd);
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, or)(const TYPE *x, const TYPE *y, TYPE *z) {
  cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
  cgraph_bool_t error = CGRAPH_FALSE;
  z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
  if (CGRAPH_FALSE == error) {
    DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
    cgraph_size_t i = 0;
    for (i = 0; i < len; i++, xd++, yd++, zd++) {
      *zd = CGRAPH_OR(*xd, *yd);
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, xor)(const TYPE *x, const TYPE *y, TYPE *z) {
  cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
  cgraph_bool_t error = CGRAPH_FALSE;
  z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
  if (CGRAPH_FALSE == error) {
    DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
    cgraph_size_t i = 0;
    for (i = 0; i < len; i++, xd++, yd++, zd++) {
      *zd = CGRAPH_XOR(*xd, *yd);
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, xnor)(const TYPE *x, const TYPE *y, TYPE *z) {
  cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
  cgraph_bool_t error = CGRAPH_FALSE;
  z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
  if (CGRAPH_FALSE == error) {
    DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]), *zd = &(z->data[0]);
    cgraph_size_t i = 0;
    for (i = 0; i < len; i++, xd++, yd++, zd++) {
      *zd = CGRAPH_XNOR(*xd, *yd);
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, not )(const TYPE *x, TYPE *y) {
  cgraph_size_t len = x->len;
  cgraph_bool_t error = CGRAPH_FALSE;
  y = FUNCTION(NAME, realloc)(y, DATA_ID, 0, len, &error);
  if (CGRAPH_FALSE == error) {
    DATA_TYPE *xd = &(x->data[0]), *yd = &(y->data[0]);
    cgraph_size_t i = 0;
    for (i = 0; i < len; i++, xd++, yd++) {
      *yd = CGRAPH_NOT(*xd);
    }
  }

  return y;
}

TYPE *FUNCTION(NAME, abs)(TYPE *cthis) { return cthis; }

TYPE *FUNCTION(NAME, opp)(TYPE *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i;
    DATA_TYPE *cthisd = &(cthis->data[0]);
    for (i = 0; i < cthis->len; i++, cthisd++) {
      *cthisd = ~(*cthisd);
    }
  }

  return cthis;
}

TYPE *FUNCTION(NAME, unit)(TYPE *cthis, const cgraph_size_t len) {
  cgraph_size_t _len = FUNCTION(NAME, minoflen)(cthis, len);
  if (NULL != cthis) {
    cgraph_memset(cthis->data, DATA_MAX, _len);
    cthis->len = _len;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, unit_inv)(TYPE *cthis, const cgraph_size_t len) {
  return FUNCTION(NAME, unit)(cthis, len);
}

#include "cgraph_template_off.h"
