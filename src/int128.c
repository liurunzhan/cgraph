#include "cgraph_base.h"
#include "cgraph_int128.h"

#define TYPE_INT128
#include "cgraph_template.h"

/** template module */
#include "template_int.ct"

#define CGRAPH_BUFFER_SIZE CGRAPH_INT128_BUFFER_SIZE
#include "template_buffer.ct"

cgraph_char_t *FUNCTION(NAME, encode)(const TYPE cthis) {
  TYPE data = CGRAPH_ABS(cthis);
  cgraph_size_t len = 0;
  for (; data; len++) {
    __cgraph_buffer__[len] = data % 10 + '0';
    data /= 10;
  }
  if (0 > cthis) {
    __cgraph_buffer__[len++] = '-';
  }
  __cgraph_buffer__[len] = '\0';
  cgraph_strrev(__cgraph_buffer__, len);

  return __cgraph_buffer__;
}

#include "cgraph_template_off.h"
