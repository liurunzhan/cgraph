#include "cgraph_math.h"
#include "cgraph_memory.h"
#include "cgraph_object.h"
#include "cgraph_vector.h"

#define TYPE_VECTOR
#include "template.h"

/**/
#include "struct_base.ct"

cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis)
{
    cgraph_bool_t flag = CGRAPH_FALSE;

    return flag;
}

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y)
{
    cgraph_bool_t flag = CGRAPH_TRUE;
    if ((NULL != x) && (NULL != y)) {
        if (CGRAPH_DTYPE_TYPE(x) == CGRAPH_DTYPE_TYPE(y)) {
            cgraph_size_t len = CGRAPH_MIN(x->len, y->len);
            cgraph_type_t type = CGRAPH_DTYPE_TYPE(x);
            OBJECT(type, cmp)
            (x->data, y->data, &flag, len, OBJECT(type, eq));
        } else {
            flag = CGRAPH_FALSE;
        }
    }

    return flag;
}

cgraph_bool_t FUNCTION(NAME, ne)(const TYPE *x, const TYPE *y)
{
    cgraph_bool_t flag = CGRAPH_FALSE;
    if ((NULL != x) && (NULL != y)) {
        if (CGRAPH_DTYPE_TYPE(x) == CGRAPH_DTYPE_TYPE(y)) {
            cgraph_size_t len = CGRAPH_MIN(x->len, y->len);
            cgraph_type_t type = CGRAPH_DTYPE_TYPE(x);
            OBJECT(type, cmp)
            (x->data, y->data, &flag, len, OBJECT(type, ne));
        } else {
            flag = CGRAPH_TRUE;
        }
    }

    return flag;
}

TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z)
{
    if ((NULL != x) && (NULL != y) &&
        (CGRAPH_DTYPE_TYPE(x) == CGRAPH_DTYPE_TYPE(y))) {
        cgraph_size_t len = CGRAPH_MIN(x->len, y->len);
        cgraph_bool_t error = CGRAPH_FALSE;
        cgraph_type_t type = CGRAPH_DTYPE_TYPE(x);
        cgraph_size_t z_size = (NULL != z ? z->size : 0);
        z = FUNCTION(NAME, realloc)(z, type, z_size, len, &error);
        if (CGRAPH_FALSE == error) {
            OBJECT(type, iter3v)
            (x->data, y->data, z->data, len, OBJECT(type, add));
        }
    }

    return z;
}

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z)
{
    if ((NULL != x) && (NULL != y) &&
        (CGRAPH_DTYPE_TYPE(x) == CGRAPH_DTYPE_TYPE(y))) {
        cgraph_size_t len = CGRAPH_MIN(x->len, y->len);
        cgraph_bool_t error = CGRAPH_FALSE;
        cgraph_type_t type = CGRAPH_DTYPE_TYPE(x);
        cgraph_size_t z_size = (NULL != z ? z->size : 0);
        z = FUNCTION(NAME, realloc)(z, type, z_size, len, &error);
        if (CGRAPH_FALSE == error) {
            OBJECT(type, iter3v)
            (x->data, y->data, z->data, len, OBJECT(type, sub));
        }
    }

    return z;
}

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z)
{
    if ((NULL != x) && (NULL != y) &&
        (CGRAPH_DTYPE_TYPE(x) == CGRAPH_DTYPE_TYPE(y))) {
        cgraph_size_t len = CGRAPH_MIN(x->len, y->len);
        cgraph_bool_t error = CGRAPH_FALSE;
        cgraph_type_t type = CGRAPH_DTYPE_TYPE(x);
        cgraph_size_t z_size = (NULL != z ? z->size : 0);
        z = FUNCTION(NAME, realloc)(z, type, z_size, len, &error);
        if (CGRAPH_FALSE == error) {
            OBJECT(type, iter3v)
            (x->data, y->data, z->data, len, OBJECT(type, mul));
        }
    }

    return z;
}

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z)
{
    if ((NULL != x) && (NULL != y) &&
        (CGRAPH_DTYPE_TYPE(x) == CGRAPH_DTYPE_TYPE(y))) {
        cgraph_size_t len = CGRAPH_MIN(x->len, y->len);
        cgraph_bool_t error = CGRAPH_FALSE;
        cgraph_type_t type = CGRAPH_DTYPE_TYPE(x);
        cgraph_size_t z_size = (NULL != z ? z->size : 0);
        z = FUNCTION(NAME, realloc)(z, type, z_size, len, &error);
        if (CGRAPH_FALSE == error) {
            OBJECT(type, iter3v)
            (x->data, y->data, z->data, len, (cgraph_pfunc3_t)OBJECT(type, div));
        }
    }

    return z;
}

TYPE *FUNCTION(NAME, primes)(const cgraph_int_t data)
{
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

void FUNCTION(NAME, test)(void)
{
#ifdef DEBUG

#endif
}

#include "template_off.h"
