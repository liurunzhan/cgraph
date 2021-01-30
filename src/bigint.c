#include "cgraph_bigint.h"
#include "cgraph_file.h"
#include "cgraph_math.h"
#include "cgraph_memory.h"

#define TYPE_BIGINT
#include "template.h"

/** template module */
#include "data_base.ct"

cgraph_int_t FUNCTION(NAME, fprintf)(FILE *fp, const TYPE *cthis)
{
    cgraph_int_t size = 0;
    if (NULL != cthis) {
        cgraph_size_t i = cthis->len - 1;
        cgraph_int_t tmp = cthis->data[i];
        for (i--; i >= 0; i--) {
            tmp = cthis->data[i] * 256 + tmp;
            fprintf(fp, "%d\n", tmp);
            fprintf(fp, "%c\n", (tmp % 10) + '0');
            tmp = tmp / 10;
            fprintf(fp, "%c\n", (tmp % 10) + '0');
            tmp = tmp / 10;
        }
        fprintf(fp, "%c\n", (tmp % 10) + '0');
        size = cthis->len;
    }

    return size;
}

/**
  @brief BKDR Hash Algorithm
  @brief hash = (hash * 31) + cthis->data[i]
*/
cgraph_size_t FUNCTION(NAME, hash)(const TYPE *cthis)
{
    cgraph_size_t hash = 0;
    if (NULL != cthis) {
        cgraph_size_t i;
        hash = cthis->postive;
        for (i = 0; i < cthis->len; i++) {
            hash = hash * 31 + cthis->data[i];
        }
    }

    return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis)
{
    cgraph_bool_t flag = CGRAPH_FALSE;
    if (NULL != cthis) {
        cgraph_size_t i;
        flag = CGRAPH_TRUE;
        for (i = 0; i < cthis->len; i++) {
            if ((cthis->data[i] > 10) || (cthis->data[i] < 0)) {
                flag = CGRAPH_FALSE;
                break;
            }
        }
    }

    return flag;
}

TYPE *FUNCTION(NAME, abs)(TYPE *cthis)
{
    if (NULL != cthis) {
        cthis->postive = CGRAPH_TRUE;
    }

    return cthis;
}

TYPE *FUNCTION(NAME, opp)(TYPE *cthis)
{
    if (NULL != cthis) {
        cthis->postive =
            ((CGRAPH_TRUE == cthis->postive) ? CGRAPH_FALSE : CGRAPH_TRUE);
    }

    return cthis;
}

cgraph_bool_t FUNCTION(NAME, ispos)(const TYPE *cthis)
{
    return ((NULL != cthis) ? cthis->postive : CGRAPH_FALSE);
}

cgraph_bool_t FUNCTION(NAME, isneg)(const TYPE *cthis)
{
    return ((NULL != cthis) ? CGRAPH_TEST(cthis->postive == CGRAPH_FALSE)
                            : CGRAPH_FALSE);
}

TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z)
{
    if ((NULL != x) && (NULL != y)) {
        cgraph_size_t _size = CGRAPH_SIZE(z);
        cgraph_size_t len = CGRAPH_MIN(x->len, y->len),
                      size = CGRAPH_MAX(x->len, y->len);
        cgraph_bool_t error = CGRAPH_FALSE;
        z = FUNCTION(NAME, realloc)(z, DATA_ID, _size, size + 1, &error);
        if (CGRAPH_FALSE == error) {
            cgraph_size_t i;
            DATA_TYPE carry = 0;
            DATA_TYPE *xd = &(x->data[x->len - 1]),
                      *yd = &(y->data[y->len - 1]), *zd = &(z->data[size]);
            if (x->postive == y->postive) {
                z->postive = x->postive;
                for (i = 0; i < len; i++, xd--, yd--, zd--) {
                    *zd = (*xd + *yd + carry);
                    carry = (((*zd < *xd) || (*zd < *yd)) ? 1 : 0);
                }
                for (; i < x->len; i++, xd--, zd--) {
                    *zd = (*xd + carry);
                    carry = ((*zd < *xd) ? 1 : 0);
                }
                for (; i < y->len; i++, yd--, zd--) {
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
                if (CGRAPH_FALSE == x->postive) {

                } else {
                }
            }
            z->postive = x->postive;
        }
    }

    return z;
}

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z)
{
    if ((NULL != x) && (NULL != y)) {
        cgraph_size_t _len = CGRAPH_LEN(z);
        cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
        cgraph_bool_t error = CGRAPH_FALSE;
        z = FUNCTION(NAME, realloc)(z, DATA_ID, _len, len, &error);
        if (CGRAPH_FALSE == error) {
            cgraph_size_t i;
            DATA_TYPE *xd = &(x->data[x->len - 1]),
                      *yd = &(y->data[y->len - 1]),
                      *zd = &(z->data[z->len - 1]);
            for (i = 1; i < len; i++, xd--, yd--, zd--) {
                *zd = *xd - *yd;
            }
            z->postive = x->postive;
        }
    }

    return z;
}

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z)
{
    if ((NULL != x) && (NULL != y)) {
        cgraph_size_t _size = CGRAPH_SIZE(z);
        cgraph_size_t len = CGRAPH_MIN(x->len, y->len),
                      size = CGRAPH_MAX(x->len, y->len);
        cgraph_bool_t error = CGRAPH_FALSE;
        z = FUNCTION(NAME, realloc)(z, DATA_ID, _size, size, &error);
        if (CGRAPH_FALSE == error) {
            cgraph_size_t i;
            DATA_TYPE *xd = &(x->data[x->len - 1]),
                      *yd = &(y->data[y->len - 1]),
                      *zd = &(z->data[z->len - 1]);
            for (i = 1; i < len; i++, xd--, yd--, zd--) {
                *zd = ((*xd) * (*yd));
            }
            z->postive = x->postive;
        }
    }

    return z;
}

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z)
{
    cgraph_size_t _len = CGRAPH_LEN(z);
    cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
    cgraph_bool_t error = CGRAPH_FALSE;
    z = FUNCTION(NAME, realloc)(z, DATA_ID, _len, len, &error);
    if (CGRAPH_FALSE == error) {
        if (x->postive == y->postive) {
            cgraph_size_t i;
            DATA_TYPE *xd = &(x->data[x->len - 1]),
                      *yd = &(y->data[y->len - 1]),
                      *zd = &(z->data[z->len - 1]);
            for (i = 1; i < len; i++, xd--, yd--, zd--) {
                *zd = ((*xd) / (*yd));
            }
            z->postive = x->postive;
        }
    }

    return z;
}

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y)
{
    cgraph_bool_t flag = CGRAPH_FALSE;
    if ((NULL != x) && (NULL != y) && (x->postive == y->postive)) {
        cgraph_size_t i, min = CGRAPH_MIN(x->len, y->len);
        DATA_TYPE *xd = &(x->data[x->len - 1]), *yd = &(y->data[y->len - 1]);
        for (i = 0; i < min; i++, xd--, yd--) {
            if (*xd != *yd) {
                break;
            }
        }
        if (i >= min) {
            for (; i < x->len; i++, xd--) {
                if (0 != *xd) {
                    break;
                }
            }
            for (; i < y->len; i++, yd--) {
                if (0 != *yd) {
                    break;
                }
            }
            if ((i >= x->len) && (i >= y->len)) {
                flag = CGRAPH_TRUE;
            }
        }
    } else if ((NULL == x) && (NULL == y)) {
        flag = CGRAPH_TRUE;
    }

    return flag;
}

cgraph_bool_t FUNCTION(NAME, ne)(const TYPE *x, const TYPE *y)
{
    return CGRAPH_TEST(CGRAPH_FALSE == FUNCTION(NAME, eq)(x, y));
}

cgraph_bool_t FUNCTION(NAME, gr)(const TYPE *x, const TYPE *y)
{
    cgraph_bool_t flag = CGRAPH_FALSE;
    if ((NULL != x) && (NULL != y)) {
        if (x->postive == y->postive) {
            cgraph_size_t i, min = CGRAPH_MIN(x->len, y->len);
            DATA_TYPE *xd = &(x->data[x->len - 1]),
                      *yd = &(y->data[y->len - 1]);
            if (CGRAPH_TRUE == x->postive) {
                for (i = 0; i < min; i++, xd--, yd--) {
                    if (*xd <= *yd) {
                        break;
                    }
                }
            } else {
                for (i = 0; i < min; i++, xd--, yd--) {
                    if (*xd >= *yd) {
                        break;
                    }
                }
            }
            if (i < 0) {
                flag = CGRAPH_TRUE;
            }
        } else if ((CGRAPH_TRUE == x->postive) &&
                   (CGRAPH_FALSE == y->postive)) {
            flag = CGRAPH_TRUE;
        }
    } else if ((NULL != x) && (NULL == y)) {
        flag = CGRAPH_TRUE;
    }

    return flag;
}

cgraph_bool_t FUNCTION(NAME, ge)(const TYPE *x, const TYPE *y)
{
    cgraph_bool_t flag = CGRAPH_FALSE;
    if ((NULL != x) && (NULL != y)) {
        if (x->postive == y->postive) {
            cgraph_size_t i, len = CGRAPH_MIN(x->len, y->len);
            if (CGRAPH_TRUE == x->postive) {
                for (i = len - 1; i >= 0; i--) {
                    if (x->data[i] < y->data[i]) {
                        break;
                    }
                }
            } else if (CGRAPH_FALSE == x->postive) {
                for (i = len - 1; i >= 0; i--) {
                    if (x->data[i] > y->data[i]) {
                        break;
                    }
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

cgraph_bool_t FUNCTION(NAME, ls)(const TYPE *x, const TYPE *y)
{
    cgraph_bool_t flag = CGRAPH_FALSE;
    if ((NULL != x) && (NULL != y)) {
        if (x->postive == y->postive) {
            cgraph_size_t i, len = CGRAPH_MIN(x->len, y->len);
            if (CGRAPH_TRUE == x->postive) {
                for (i = len - 1; i >= 0; i--) {
                    if (x->data[i] >= y->data[i]) {
                        break;
                    }
                }
            } else if (CGRAPH_FALSE == x->postive) {
                for (i = len - 1; i >= 0; i--) {
                    if (x->data[i] <= y->data[i]) {
                        break;
                    }
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

cgraph_bool_t FUNCTION(NAME, le)(const TYPE *x, const TYPE *y)
{
    cgraph_bool_t flag = CGRAPH_FALSE;
    if ((NULL != x) && (NULL != y)) {
        if (x->postive == y->postive) {
            cgraph_size_t i, len = CGRAPH_MIN(x->len, y->len);
            if (CGRAPH_TRUE == x->postive) {
                for (i = len - 1; i >= 0; i--) {
                    if (x->data[i] > y->data[i]) {
                        break;
                    }
                }
            } else if (CGRAPH_FALSE == x->postive) {
                for (i = len - 1; i >= 0; i--) {
                    if (x->data[i] < y->data[i]) {
                        break;
                    }
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

TYPE *FUNCTION(NAME, format)(TYPE *cthis)
{
    if (NULL != cthis) {
        DATA_TYPE *data = cthis->data;
        while ((0 == *data) && (0 < cthis->len)) {
            cthis->len -= 1;
            data++;
        }
        cthis->data = data;
    }

    return cthis;
}

TYPE *FUNCTION(NAME, unit)(const cgraph_size_t size)
{
    cgraph_size_t _size = (size > 1 ? size : 1);
    TYPE *cthis = FUNCTION(NAME, calloc)(DATA_ID, _size);
    if (NULL != cthis) {
        cthis->len = 1;
        cthis->data[0] = 1;
    }

    return cthis;
}

TYPE *FUNCTION(NAME, unit_inv)(const cgraph_size_t size)
{
    return FUNCTION(NAME, unit)(size);
}

TYPE *FUNCTION(NAME, zero)(const cgraph_size_t size)
{
    cgraph_size_t _size = (size > 1 ? size : 1);
    TYPE *cthis = FUNCTION(NAME, calloc)(DATA_ID, _size);
    if (NULL != cthis) {
        cthis->len = 1;
    }

    return cthis;
}

#include "template_off.h"
