#include "cgraph_base.h"
#include "cgraph_object.h"

/****/
#include "cgraph_vector.h"

/** template module */
#include "template_struct.ct"

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    cgraph_type_t type = CGRAPH_DTYPE_TYPE(x);
    cgraph_size_t len = x->len;
    if ((type == CGRAPH_DTYPE_TYPE(y)) && (len == y->len)) {
      OBJECT(type, cmp)
      (x->data, y->data, &flag, len, OBJECT(type, eq));
    }
  } else if ((NULL == x) && (NULL == y)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}

TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y) &&
      (CGRAPH_DTYPE_TYPE(x) == CGRAPH_DTYPE_TYPE(y))) {
    cgraph_size_t len = CGRAPH_MIN(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    cgraph_type_t type = CGRAPH_DTYPE_TYPE(x);
    cgraph_size_t z_size = CGRAPH_SIZE(z);
    z = FUNCTION(NAME, realloc)(z, type, z_size, len, &error);
    if (CGRAPH_FALSE == error) {
      OBJECT(type, for3v)
      (x->data, y->data, z->data, len, OBJECT(type, add));
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y) &&
      (CGRAPH_DTYPE_TYPE(x) == CGRAPH_DTYPE_TYPE(y))) {
    cgraph_size_t len = CGRAPH_MIN(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    cgraph_type_t type = CGRAPH_DTYPE_TYPE(x);
    cgraph_size_t z_size = CGRAPH_SIZE(z);
    z = FUNCTION(NAME, realloc)(z, type, z_size, len, &error);
    if (CGRAPH_FALSE == error) {
      OBJECT(type, for3v)
      (x->data, y->data, z->data, len, OBJECT(type, sub));
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y) &&
      (CGRAPH_DTYPE_TYPE(x) == CGRAPH_DTYPE_TYPE(y))) {
    cgraph_size_t len = CGRAPH_MIN(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    cgraph_type_t type = CGRAPH_DTYPE_TYPE(x);
    cgraph_size_t z_size = CGRAPH_SIZE(z);
    z = FUNCTION(NAME, realloc)(z, type, z_size, len, &error);
    if (CGRAPH_FALSE == error) {
      OBJECT(type, for3v)
      (x->data, y->data, z->data, len, OBJECT(type, mul));
    }
  }

  return z;
}

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z) {
  if ((NULL != x) && (NULL != y) &&
      (CGRAPH_DTYPE_TYPE(x) == CGRAPH_DTYPE_TYPE(y))) {
    cgraph_size_t len = CGRAPH_MIN(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    cgraph_type_t type = CGRAPH_DTYPE_TYPE(x);
    cgraph_size_t z_size = CGRAPH_SIZE(z);
    z = FUNCTION(NAME, realloc)(z, type, z_size, len, &error);
    if (CGRAPH_FALSE == error) {
      OBJECT(type, for3v)
      (x->data, y->data, z->data, len, OBJECT(type, div));
    }
  }

  return z;
}

cgraph_bool_t FUNCTION(NAME, find)(const TYPE *cthis, const void *x) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if ((NULL != cthis) && (NULL != x)) {
    cgraph_type_t type = CGRAPH_DTYPE_TYPE(cthis);
    cgraph_addr_t data = OBJECT(type, data)(cthis);
    CGRAPH_LOOP(i, 0, cthis->len)
    OBJECT(type, eq)(data, (void *)x, &res);
    if (CGRAPH_TRUE == res) {
      break;
    }
    data += OBJECT(type, tstrusize)();
    CGRAPH_LOOP_END
  }

  return res;
}

TYPE *FUNCTION(NAME, push)(TYPE *cthis, const void *x) {
  if ((NULL != cthis) && (NULL != x)) {
    cgraph_type_t type = CGRAPH_DTYPE_TYPE(cthis);
    if (NULL != x) {
      cthis->len += 1;
    }
  }

  return cthis;
}

void *FUNCTION(NAME, pop)(TYPE *cthis) {
  void *res = NULL;
  if (CGRAPH_HASDATA(cthis)) {
    cgraph_type_t type = CGRAPH_DTYPE_TYPE(cthis);
    res = (cgraph_addr_t)cthis->data + cthis->len * OBJECT(type, tstrusize)();
    cthis->len -= 1;
  }

  return res;
}

TYPE *FUNCTION(NAME, delete)(TYPE *cthis, const void *x) {
  if ((NULL != cthis) && (NULL != x)) {
    cgraph_type_t type = CGRAPH_DTYPE_TYPE(cthis);
    CGRAPH_LOOP(i, 0, cthis->len)
    break;
    CGRAPH_LOOP_END
  }

  return cthis;
}

TYPE *FUNCTION(NAME, primes)(const cgraph_int_t data) {
  TYPE *primes = FUNCTION(NAME, calloc)(CGRAPH_INT_T, data);
  TYPE *isprime = FUNCTION(NAME, calloc)(CGRAPH_BOOL_T, data);
  if (NULL != isprime) {
    if (NULL != primes) {
      primes->len = cgraph_math_primes(primes->data, isprime->data, data);
    }
    cgraph_vector_free(isprime);
  }

  return primes;
}
