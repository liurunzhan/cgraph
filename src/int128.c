#include "cgraph_base.h"
#include "cgraph_int128.h"

#define TYPE_INT128
#include "cgraph_template.h"

/** template module */
#include "template_int.ct"

#define CGRAPH_CBUFFER_SIZE CGRAPH_INT128_CBUFFER_SIZE
#include "template_cbuffer.ct"

cgraph_char_t *FUNCTION(NAME, encode)(const TYPE cthis) {
  TYPE data = CGRAPH_ABS(cthis);
  cgraph_size_t len = 0;
  for (; data; len++) {
    __cgraph_cbuffer__[len] = data % 10 + '0';
    data /= 10;
  }
  if (0 > cthis) {
    __cgraph_cbuffer__[len++] = '-';
  }
  __cgraph_cbuffer__[len] = '\0';
  cgraph_strnrev(__cgraph_cbuffer__, len);

  return __cgraph_cbuffer__;
}

#include "cgraph_template_off.h"
