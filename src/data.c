#include "cgraph_data.h"

static const cgraph_char_t *__cgraph_true__ = CGRAPH_BOOL_TRUE;
static const cgraph_size_t __cgraph_true_len__ = CGRAPH_BOOL_TRUE_LEN;
static const cgraph_size_t __cgraph_true_size__ = (__cgraph_true_len__ + 1);
static const cgraph_char_t *__cgraph_false__ = CGRAPH_BOOL_FALSE;
static const cgraph_size_t __cgraph_false_len__ = CGRAPH_BOOL_FALSE_LEN;
static const cgraph_size_t __cgraph_false_size__ = (__cgraph_false_len__ + 1);

cgraph_string_t *cgraph_bool_to_string(const cgraph_bool_t x)
{
    cgraph_string_t *cthis = NULL;
    if (CGRAPH_TRUE == x) {
        cthis = cgraph_string_calloc(CGRAPH_CHAR_T, __cgraph_true_size__);
        if (NULL != cthis) {
            cgraph_string_initd(cthis, __cgraph_true__, __cgraph_true_size__);
            cthis->len = __cgraph_true_len__;
        }
    } else if (CGRAPH_FALSE == x) {
        cthis = cgraph_string_calloc(CGRAPH_CHAR_T, __cgraph_false_size__);
        if (NULL != cthis) {
            cgraph_string_initd(cthis, __cgraph_false__, __cgraph_false_size__);
            cthis->len = __cgraph_false_len__;
        }
    }

    return cthis;
}

cgraph_string_t *cgraph_bigint_to_string(const cgraph_bigint_t *cthis)
{
    cgraph_string_t *str = NULL;
    if (NULL != cthis) {
        cgraph_size_t len = cthis->postive ? cthis->len : (cthis->len + 1);
        str = cgraph_string_calloc(CGRAPH_CHAR_T, len);
        if (NULL != str) {
            cgraph_size_t i = 0;
            if (CGRAPH_FALSE == cthis->postive) {
                str->data[i++] = '-';
            }
            for (; i < len; i++) {
                str->data[i] = cthis->data[i] + '0';
            }
        }
    }

    return str;
}

cgraph_bigint_t *cgraph_string_to_bigint(const cgraph_string_t *cthis)
{
    cgraph_size_t len = ('-' == cthis->data[0] ? (cthis->len - 1) : cthis->len);
    cgraph_bigint_t *object = cgraph_bigint_calloc(1, len);
    if (NULL != object) {
        cgraph_size_t i = 0;
        if ('-' == cthis->data[i]) {
            object->postive = CGRAPH_FALSE;
            i++;
        }
        for (; i < len; i++) {
            object->data[i] = cthis->data[i] - '0';
        }
    }

    return object;
}
