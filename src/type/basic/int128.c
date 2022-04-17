#include "cgraph_base.h"

/** object cgraph_int128_t header */
#include "cgraph_int128.h"

/** template module */
#include "template_int.ct"

#define CGRAPH_CBUF_SIZE CGRAPH_INT128_CBUF_SIZE
#define CGRAPH_CBUF_PTR cgraph_cbuf_ptr
#include "template_cbuf.ct"

cgraph_char_t *FUNCTION(NAME, encode)(const TYPE cthis) {
  TYPE data = CGRAPH_ABS(cthis);
  cgraph_size_t len = 0;
  for (; data; len++) {
    CGRAPH_CBUF_PTR[len] = data % 10 + '0';
    data /= 10;
  }
  if (0 > cthis) {
    CGRAPH_CBUF_PTR[len++] = '-';
  }
  CGRAPH_CBUF_PTR[len] = '\0';
  cgraph_strnrev(CGRAPH_CBUF_PTR, len);

  return CGRAPH_CBUF_PTR;
}

TYPE FUNCTION(NAME, decode)(const cgraph_char_t *cstr, const cgraph_size_t len,
                            cgraph_bool_t *error) {
  TYPE res;

  return res;
}