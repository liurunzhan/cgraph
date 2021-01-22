#include "cgraph_data.h"

static const cgraph_char_t *__cgraph_true__ = "true";
static const cgraph_size_t __cgraph_true_len__ = 4;
static const cgraph_size_t __cgraph_true_size__ = 5;
static const cgraph_char_t *__cgraph_false__ = "false";
static const cgraph_size_t __cgraph_false_len__ = 5;
static const cgraph_size_t __cgraph_false_size__ = 6;

cgraph_string_t *cgraph_bool_to_string(const cgraph_bool_t x)
{
    cgraph_string_t *cthis = NULL;
    if (CGRAPH_TRUE == x) {
        cthis = cgraph_string_calloc(CGRAPH_CHAR_T, __cgraph_true_size__);
        if (NULL != cthis) {
            cthis->len = __cgraph_true_len__;
        }
    } else {
        cthis = cgraph_string_calloc(CGRAPH_CHAR_T, __cgraph_false_size__);
        if (NULL != cthis) {
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
        str = cgraph_string_calloc(1, len + 1);
        if (NULL != str) {
            cgraph_size_t i = 0;
            if (cthis->postive == CGRAPH_FALSE) {
                str->data[i] = '-';
                i++;
            }
            for (; i < len; i++) {
                str->data[i] = cthis->data[i] + '0';
            }
            str->data[i] = '\0';
        }
    }

    return str;
}

cgraph_bigint_t *cgraph_string_to_bigint(const cgraph_string_t *cthis)
{
    cgraph_size_t len = '-' == cthis->data[0] ? (cthis->len - 1) : cthis->len;
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
