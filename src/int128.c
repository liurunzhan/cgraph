#include "cgraph_base.h"

/***/
#include "cgraph_int128.h"

/** template module */
#include "template_int.ct"

#define CGRAPH_CBUF_SIZE CGRAPH_INT128_CBUF_SIZE
#include "template_cbuf.ct"

cgraph_char_t *FUNCTION(NAME, encode)(const TYPE cthis) {
  TYPE data = CGRAPH_ABS(cthis);
  cgraph_size_t len = 0;
  for (; data; len++) {
    __cgraph_cbuf__[len] = data % 10 + '0';
    data /= 10;
  }
  if (0 > cthis) {
    __cgraph_cbuf__[len++] = '-';
  }
  __cgraph_cbuf__[len] = '\0';
  cgraph_strnrev(__cgraph_cbuf__, len);

  return __cgraph_cbuf__;
}
