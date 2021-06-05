#include "cgraph_base.h"
#include "cgraph_int128.h"

#define TYPE_INT128
#include "cgraph_template.h"

/** template module */
#include "template_int.ct"

static cgraph_char_t __int128_buffer__[CGRAPH_INT128_BUFFER_SIZE];

void FUNCTION(NAME, clrbuffer)(void) {
  cgraph_memset(__int128_buffer__, CGRAPH_INT128_BUFFER_SIZE, 0);
}

__INLINE cgraph_size_t FUNCTION(NAME, lenofbuffer)(void) {
  return CGRAPH_INT128_BUFFER_SIZE;
}

cgraph_char_t *FUNCTION(NAME, encode)(const TYPE cthis) {
  TYPE data = CGRAPH_ABS(cthis);
  cgraph_size_t len = 0;
  for (; data; len++) {
    __int128_buffer__[len] = data % 10 + '0';
    data /= 10;
  }
  if (0 > cthis) {
    __int128_buffer__[len++] = '-';
  }
  __int128_buffer__[len] = '\0';
  cgraph_strrev(__int128_buffer__, len);

  return __int128_buffer__;
}

#include "cgraph_template_off.h"
