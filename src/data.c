#include "cgraph_data.h"

cgraph_string_t *cgraph_bigint_2string(const cgraph_bigint_t *cthis)
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

cgraph_bigint_t *cgraph_bigint_string2(const cgraph_string_t *cthis)
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