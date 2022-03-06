#include <stdlib.h>
#include <string.h>

#include "cgraph_error.h"
#include "cgraph_memory.h"

static cgraph_bool_t cgraph_uint8_dateq0(const void *data);
static cgraph_bool_t cgraph_uint8_dateq(const void *x, const void *y);

void *cgraph_calloc(const cgraph_size_t size) {
#ifdef DEBUG
  if (0 >= size) {
    cgraph_error_printf(
        CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_FATAL,
        "memory size %ld is a negative number or equal to zero error", size);
  }

#endif
  return (0 < size) ? calloc(size, 1) : NULL;
}

void *cgraph_realloc(void *memory, const cgraph_size_t old_size,
                     const cgraph_size_t new_size, cgraph_bool_t *error) {
  cgraph_bool_t _error = CGRAPH_TRUE;
  void *new_mem = memory;
  if (old_size == new_size) {
    _error = CGRAPH_FALSE;
  } else if ((0 < new_size) &&
             (NULL != (new_mem = realloc(memory, new_size)))) {
    cgraph_size_t delta_size = new_size - old_size;
    _error = CGRAPH_FALSE;
    if (0 < delta_size) {
      memset(CGRAPH_PTRADDR2V(new_mem, old_size), 0, delta_size);
    }
  } else {
    new_mem = memory;
#ifdef DEBUG
    cgraph_error_printf(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_INFO,
        "memory is re-allocated error, and the result memory pointer "
        "is kept to the old one");
#endif
  }
  if (NULL != error) {
    *error = _error;
  }
#ifdef DEBUG
  if (memory != new_mem) {
    cgraph_error_printf(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_INFO,
        "old address is " CGRAPH_VARADDR_OUT_FMT
        ", but new address is " CGRAPH_VARADDR_OUT_FMT __PLAT_LEND,
        memory, new_mem);
    cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_INFO,
                        "realloc a new memory block and notice to use the new "
                        "address " CGRAPH_VARADDR_OUT_FMT __PLAT_LEND,
                        new_mem);
  }
  if (0 >= new_size) {
    cgraph_error_printf(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "memory size %ld is a negative number or equal to zero error",
        new_size);
  }
#endif

  return new_mem;
}

void *cgraph_memset(void *memory, cgraph_uint_t data, cgraph_size_t len) {
  if ((NULL != memory) && (0 != len)) {
    if (0 < len) {
      memset(memory, data, len);
    } else {
      cgraph_addr_t mem_ptr = (cgraph_addr_t)memory;
      CGRAPH_RLOOP(i, 0, len)
      *(mem_ptr--) = data;
      CGRAPH_LOOP_END
    }
  }
#ifdef DEBUG
  else {
    if (NULL == memory) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source memory pointer is empty");
    }
    if (0 == len) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory length %ld is equal to zero error", len);
    }
  }
#endif

  return memory;
}

void *cgraph_memcpy(void *trg_mem, const void *src_mem,
                    const cgraph_size_t len) {
  if ((NULL != trg_mem) && (NULL != src_mem) && (trg_mem != src_mem) &&
      (0 != len)) {
    if (0 < len) {
      memcpy(trg_mem, src_mem, len);
    } else {
      cgraph_addr_t trg_mem_ptr = (cgraph_addr_t)trg_mem,
                    src_mem_ptr = (cgraph_addr_t)src_mem;
      CGRAPH_RLOOP(i, 0, len)
      *(trg_mem_ptr--) = *(src_mem_ptr--);
      CGRAPH_LOOP_END
    }
  }
#ifdef DEBUG
  else {
    if (NULL == trg_mem) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target memory pointer is empty");
    }
    if (NULL == src_mem) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source memory pointer is empty");
    }
    if (trg_mem == src_mem) {
      cgraph_error_printf(
          CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
          "source memory pointer is equal to target memory pointer");
    }
    if (0 == len) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory length %ld is equal to zero error", len);
    }
  }
#endif

  return trg_mem;
}

void *cgraph_memscpy(void *trg_mem, const void *src_mem,
                     const cgraph_size_t trg_size,
                     const cgraph_size_t src_len) {
  if ((NULL != trg_mem) && (NULL != src_mem) && (trg_mem != src_mem) &&
      (0 < trg_size) && (0 != src_len)) {
    cgraph_addr_t trg_mem_ptr = (cgraph_addr_t)trg_mem,
                  src_mem_ptr = (cgraph_addr_t)src_mem;
    if (0 < src_len) {
      cgraph_size_t len = CGRAPH_MIN(trg_size, src_len);
      CGRAPH_LOOP(i, 0, len)
      *(trg_mem_ptr++) = *(src_mem_ptr++);
      CGRAPH_LOOP_END
    } else {
      cgraph_size_t len = CGRAPH_MAX(-trg_size, src_len);
      CGRAPH_RLOOP(i, 0, len)
      *(trg_mem_ptr--) = *(src_mem_ptr--);
      CGRAPH_LOOP_END
    }
  }
#ifdef DEBUG
  else {
    if (NULL == trg_mem) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target memory pointer is empty");
    }
    if (NULL == src_mem) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source memory pointer is empty");
    }
    if (trg_mem == src_mem) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source memory pointer is equal to target pointer");
    }
    if (0 >= trg_size) {
      cgraph_error_printf(
          CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
          "memory size %ld is smaller than or equal to zero error", trg_size);
    }
  }
#endif

  return trg_mem;
}

cgraph_size_t cgraph_memlen(const void *memory, const cgraph_uint8_t end) {
  cgraph_size_t len = 0;
  if (NULL != memory) {
    cgraph_addr_t ptr = (cgraph_addr_t)memory;
    for (; end != *ptr; ptr++, len++) {
    }
  }

  return len;
}

void *cgraph_memend(const void *memory, const cgraph_uint8_t end) {
  cgraph_addr_t ptr = (cgraph_addr_t)memory;
  if (NULL != memory) {
    for (; end != *ptr; ptr++) {
    }
    ptr -= 1;
  }

  return ptr;
}

cgraph_bool_t cgraph_memcmp(const void *x_mem, const void *y_mem,
                            const cgraph_size_t len) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((x_mem == y_mem) || (0 == len)) {
    flag = CGRAPH_TRUE;
  } else if ((NULL != x_mem) && (NULL != y_mem)) {
    if (0 < len) {
      flag = CGRAPH_TEST(0 == memcmp(x_mem, y_mem, len));
    } else {
      cgraph_addr_t mem_x_ptr = (cgraph_addr_t)x_mem,
                    mem_y_ptr = (cgraph_addr_t)y_mem;
      CGRAPH_RLOOP(i, 0, len)
      *(mem_x_ptr--) = *(mem_y_ptr--);
      CGRAPH_LOOP_END
    }
  }

  return flag;
}

void *cgraph_memrev(void *memory, cgraph_size_t len) {
  if ((NULL != memory) && (0 < len)) {
    cgraph_uint_t data;
    cgraph_addr_t start_ptr = (cgraph_addr_t)memory,
                  end_ptr = ((cgraph_addr_t)memory) + len,
                  tmp_ptr = (cgraph_addr_t)&data;
    for (; start_ptr < end_ptr; start_ptr++, end_ptr--) {
      *tmp_ptr = *start_ptr;
      *start_ptr = *end_ptr;
      *end_ptr = *tmp_ptr;
    }
  }
#ifdef DEBUG
  else {
    if (NULL == memory) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory pointer is empty");
    }
    if (0 == len) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory length %ld is equal to zero error", len);
    }
  }
#endif

  return memory;
}

void *cgraph_memchr(const void *memory, cgraph_int_t ch,
                    const cgraph_size_t len) {
  void *ptr = NULL;
  if ((NULL != memory) && (0 < len)) {
    ptr = memchr(memory, ch, len);
  }
#ifdef DEBUG
  else {
    if (NULL == memory) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory pointer is empty");
    }
    if (0 == len) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory length %ld is equal to zero error", len);
    }
  }
#endif

  return ptr;
}

void *cgraph_memrchr(const void *memory, cgraph_int_t ch,
                     const cgraph_size_t len) {
  void *ptr = NULL;
  if ((NULL != memory) && (0 < len)) {
    cgraph_addr_t mem_ptr = ((cgraph_addr_t)memory) + len;
    cgraph_size_t i = 0;
    while ((ch != *(mem_ptr--)) && (len > (i++))) {
    }
    if (i < len) {
      ptr = mem_ptr;
    }
  }
#ifdef DEBUG
  else {
    if (NULL == memory) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory pointer is empty");
    }
    if (0 == len) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory length %ld is equal to zero error", len);
    }
  }
#endif

  return ptr;
}

void cgraph_free(void *memory) {
  if (NULL != memory) {
    free(memory);
    memory = NULL;
  }
#ifdef DEBUG
  else {
    cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "empty pointer is re-freed error");
  }
#endif
}

cgraph_size_t cgraph_bitlen(const void *memory, const cgraph_size_t len) {
  cgraph_size_t bits = 0;
  if ((NULL != memory) && (0 < len)) {
    cgraph_addr_t ptr = (cgraph_addr_t)memory;
    cgraph_size_t i = 0;
    for (; (0 == *ptr) && (i < len); i++, ptr++) {
    }
    bits = ((len - i) << 3) + 1;
  }

  return bits;
}

cgraph_bool_t cgraph_uint8_dateq0(const void *data) {
  return (0 == *(cgraph_addr_t)data);
}

cgraph_size_t cgraph_datlen(const void *memory, const cgraph_size_t len,
                            const cgraph_size_t datsize,
                            cgraph_memeq0_func_t func) {
  cgraph_size_t datlen = len;
  if ((NULL != memory) && (0 < len)) {
    cgraph_size_t _datsize = datsize;
    cgraph_memeq0_func_t _func = func;
    cgraph_addr_t ptr = (cgraph_addr_t)memory;
    if (NULL == func) {
      _datsize = 1;
      _func = cgraph_uint8_dateq0;
    }
    for (; _func(ptr) && (0 < datlen); ptr += _datsize, datlen--) {
    }
  }

  return datlen;
}

cgraph_bool_t cgraph_uint8_dateq(const void *x, const void *y) {
  return *(cgraph_addr_t)x == *(cgraph_addr_t)y;
}

cgraph_bool_t cgraph_datcmp(const void *trg_mem, const void *src_mem,
                            const cgraph_size_t len,
                            const cgraph_size_t datsize,
                            cgraph_memeq_func_t func) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if ((NULL != trg_mem) && (NULL != src_mem) && (0 < len)) {
    cgraph_size_t _datsize = datsize;
    cgraph_memeq_func_t _func = func;
    cgraph_addr_t trg_ptr = (cgraph_addr_t)trg_mem,
                  src_ptr = (cgraph_addr_t)src_mem;
    if (NULL == func) {
      _datsize = 1;
      _func = cgraph_uint8_dateq;
    }
    res = CGRAPH_TRUE;
    CGRAPH_LOOP(i, 0, len)
    if (!_func(trg_ptr, src_ptr)) {
      res = CGRAPH_FALSE;
      break;
    }
    trg_ptr += _datsize;
    src_ptr += _datsize;
    CGRAPH_LOOP_END
  }

  return res;
}

cgraph_size_t cgraph_strlen(const cgraph_char_t *string) {
  return CGRAPH_ISSTR(string) ? strlen(string) : 0;
}

cgraph_char_t *cgraph_strend(const cgraph_char_t *string) {
  cgraph_char_t *ptr = (cgraph_char_t *)string;
  if (CGRAPH_ISSTR(string)) {
    while ('\0' != *(++ptr)) {
    }
    ptr -= 1;
  }

  return ptr;
}

cgraph_char_t *cgraph_strcpy(cgraph_char_t *trg_str,
                             const cgraph_char_t *src_str) {
  if (CGRAPH_ISSTR(trg_str) && CGRAPH_ISSTR(src_str) && (trg_str != src_str)) {
    strcpy(trg_str, src_str);
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNSTR(trg_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string is empty");
    }
    if (CGRAPH_ISNSTR(src_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
    }
    if (trg_str == src_str) {
      cgraph_error_printf(
          CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
          "source string pointer is equal to target string pointer");
    }
  }
#endif

  return trg_str;
}

cgraph_char_t *cgraph_strncpy(cgraph_char_t *trg_str,
                              const cgraph_char_t *src_str,
                              const cgraph_size_t len) {
  if (CGRAPH_ISSTR(trg_str) && CGRAPH_ISSTR(src_str) && (trg_str != src_str) &&
      (0 < len)) {
    strncpy(trg_str, src_str, len);
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNSTR(trg_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string is empty");
    }
    if (CGRAPH_ISNSTR(src_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
    }
    if (trg_str == src_str) {
      cgraph_error_printf(
          CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
          "source string pointer is equal to target string pointer");
    }
    if (0 >= len) {
      cgraph_error_printf(
          CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
          "string size %ld is smaller than or equal to zero error", len);
    }
  }
#endif

  return trg_str;
}

cgraph_char_t *cgraph_strscpy(cgraph_char_t *trg_str,
                              const cgraph_char_t *src_str,
                              const cgraph_size_t trg_size) {
  if (CGRAPH_ISSTR(trg_str) && CGRAPH_ISSTR(src_str) && (trg_str != src_str) &&
      (0 < trg_size)) {
    cgraph_size_t size = trg_size - 1;
    cgraph_char_t *trg_str_ptr = trg_str,
                  *src_str_ptr = (cgraph_char_t *)src_str;
    for (; (0 < size) && ('\0' != *src_str_ptr); size--) {
      *(trg_str_ptr++) = *(src_str_ptr++);
    }
    *trg_str_ptr = '\0';
  }
#ifdef DEBUG
  else {
    if (NULL == trg_str) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string pointer is empty");
    }
    if (0 >= trg_size) {
      cgraph_error_printf(
          CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
          "buffer size %ld is smaller than or equal to zero error", trg_size);
    }
    if (CGRAPH_ISNSTR(src_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
    }
    if (trg_str == src_str) {
      cgraph_error_printf(
          CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
          "source string pointer is equal to target string pointer");
    }
  }
#endif

  return trg_str;
}

cgraph_char_t *cgraph_strcat(cgraph_char_t *trg_str,
                             const cgraph_char_t *src_str) {
  cgraph_char_t *trg_str_ptr = trg_str;
  if (CGRAPH_ISSTR(trg_str) && CGRAPH_ISSTR(src_str) && (trg_str != src_str)) {
    trg_str_ptr = strcat(trg_str, src_str);
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNSTR(trg_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string is empty");
    }
    if (CGRAPH_ISNSTR(src_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
    }
    if (trg_str == src_str) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source pointer is equal to target pointer");
    }
  }
#endif

  return trg_str_ptr;
}

cgraph_char_t *cgraph_strncat(cgraph_char_t *trg_str,
                              const cgraph_char_t *src_str,
                              const cgraph_size_t len) {
  cgraph_char_t *trg_str_ptr = trg_str;
  if (CGRAPH_ISSTR(trg_str) && CGRAPH_ISSTR(src_str) && (trg_str != src_str) &&
      (0 < len)) {
    trg_str_ptr = strncat(trg_str, src_str, len);
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNSTR(trg_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string is empty");
    }
    if (CGRAPH_ISNSTR(src_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
    }
    if (trg_str == src_str) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source pointer is equal to target pointer");
    }
    if (0 >= len) {
      cgraph_error_printf(
          CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
          "string length %ld is smaller than or equal to zero error", len);
    }
  }
#endif

  return trg_str_ptr;
}

cgraph_char_t *cgraph_strscat(cgraph_char_t *trg_str,
                              const cgraph_char_t *src_str,
                              const cgraph_size_t trg_size) {
  if (CGRAPH_ISSTR(trg_str) && CGRAPH_ISSTR(src_str) && (0 < trg_size)) {
    cgraph_size_t size = trg_size - 1;
    cgraph_char_t *trg_str_ptr = trg_str,
                  *src_str_ptr = (cgraph_char_t *)src_str;
    while ((0 < (size--)) && ('\0' != *(trg_str_ptr++))) {
    }
    for (; (0 < size) && ('\0' != *src_str_ptr); size--) {
      *(trg_str_ptr++) = *(src_str_ptr++);
    }
    *trg_str_ptr = '\0';
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNSTR(trg_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string is empty");
    }
    if (CGRAPH_ISNSTR(src_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
    }
    if (trg_str == src_str) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source pointer is equal to target pointer");
    }
    if (0 >= trg_size) {
      cgraph_error_printf(
          CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
          "string length %ld is smaller than or equal to zero error", trg_size);
    }
  }
#endif

  return trg_str;
}

cgraph_bool_t cgraph_strcmp(const cgraph_char_t *x_str,
                            const cgraph_char_t *y_str) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (x_str == y_str) {
    flag = CGRAPH_TRUE;
  } else if ((NULL != x_str) && (NULL != y_str)) {
    if (('\0' == *x_str) && ('\0' == *y_str)) {
      flag = CGRAPH_TRUE;
    } else {
      flag = CGRAPH_TEST(0 == strcmp(x_str, y_str));
    }
  }

  return flag;
}

cgraph_char_t *cgraph_strrev(cgraph_char_t *string) {
  if (CGRAPH_ISSTR(string)) {
    cgraph_char_t *start_ptr = string, *end_ptr = string, data;
    while ('\0' != *(end_ptr++)) {
    }
    for (end_ptr--; start_ptr < end_ptr; start_ptr++, end_ptr--) {
      data = *start_ptr;
      *start_ptr = *end_ptr;
      *end_ptr = data;
    }
  }
#ifdef DEBUG
  else {
    cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "source string is empty");
  }
#endif

  return string;
}

cgraph_char_t *cgraph_strnrev(cgraph_char_t *string, const cgraph_size_t len) {
  if (CGRAPH_ISSTR(string) && (0 < len)) {
    cgraph_char_t *start_ptr = string, *end_ptr = NULL, data;
    cgraph_size_t i = 0;
    while (('\0' != *(start_ptr++)) && (len > (i++))) {
    }
    for (end_ptr = start_ptr, start_ptr = string; start_ptr < end_ptr;
         start_ptr++, end_ptr--) {
      data = *start_ptr;
      *start_ptr = *end_ptr;
      *end_ptr = data;
    }
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNSTR(string)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "seperator string is empty");
    }
    if (0 >= len) {
      cgraph_error_printf(
          CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
          "string length %ld is smaller than or equal to zero error", len);
    }
  }
#endif

  return string;
}

cgraph_char_t *cgraph_strtok(cgraph_char_t *string, const cgraph_char_t *sep) {
  if (CGRAPH_ISSTR(string) && CGRAPH_ISSTR(sep)) {
    string = strtok(string, sep);
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNSTR(string)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
    }
    if (CGRAPH_ISNSTR(sep)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "seperator string is empty");
    }
  }
#endif

  return string;
}

cgraph_char_t *cgraph_strntok(cgraph_char_t *string, const cgraph_char_t *sep,
                              const cgraph_size_t len) {
  if (CGRAPH_ISSTR(string) && CGRAPH_ISSTR(sep) && (0 < len)) {
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNSTR(sep)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "seperator string is empty");
    }
  }
#endif

  return string;
}

cgraph_char_t *cgraph_strstok(cgraph_char_t *string, const cgraph_char_t *sep,
                              cgraph_char_t **cbuf) {
  if (CGRAPH_ISSTR(string) && CGRAPH_ISSTR(sep)) {
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNSTR(string)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
    }
    if (CGRAPH_ISNSTR(sep)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "seperator string is empty");
    }
  }
#endif

  return string;
}

cgraph_char_t *cgraph_strchr(const cgraph_char_t *string, cgraph_int_t ch) {
  cgraph_char_t *ptr = NULL;
  if (CGRAPH_ISSTR(string)) {
    ptr = strchr(string, ch);
  }
#ifdef DEBUG
  else {
    cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "source string is empty");
  }
#endif

  return ptr;
}

cgraph_char_t *cgraph_strnchr(const cgraph_char_t *string, cgraph_int_t ch,
                              const cgraph_size_t len) {
  cgraph_char_t *ptr = NULL;
  if (CGRAPH_ISSTR(string) && (0 < len)) {
    cgraph_size_t i = 0;
    cgraph_char_t *str_ptr = (cgraph_char_t *)string;
    for (; ('\0' != *str_ptr) && (i < len); i++, str_ptr++) {
      if (ch == *str_ptr) {
        ptr = str_ptr;
        break;
      }
    }
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNSTR(string)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
    }
    if (0 >= len) {
      cgraph_error_printf(
          CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
          "string length %ld is smaller than or equal to zero error", len);
    }
  }
#endif

  return ptr;
}

cgraph_char_t *cgraph_strchrn(const cgraph_char_t *string, cgraph_int_t ch,
                              const cgraph_size_t num) {
  cgraph_char_t *ptr = NULL;
  if (CGRAPH_ISSTR(string) && (0 < num)) {
    cgraph_size_t cnt = 0;
    cgraph_char_t *str_ptr = (cgraph_char_t *)string;
    for (; '\0' != *str_ptr; str_ptr++) {
      if (ch == *str_ptr) {
        cnt += 1;
        if (cnt >= num) {
          ptr = str_ptr;
          break;
        }
      }
    }
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNSTR(string)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
    }
    if (0 >= num) {
      cgraph_error_printf(
          CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
          "given character number %ld is smaller than or equal to zero error",
          num);
    }
  }
#endif

  return ptr;
}

cgraph_char_t *cgraph_strrchr(const cgraph_char_t *string, cgraph_int_t ch) {
  cgraph_char_t *ptr = NULL;
  if (CGRAPH_ISSTR(string)) {
    ptr = strrchr(string, ch);
  }
#ifdef DEBUG
  else {
    cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "source string is empty");
  }
#endif

  return ptr;
}

cgraph_char_t *cgraph_strnrchr(const cgraph_char_t *string, cgraph_int_t ch,
                               const cgraph_size_t len) {
  cgraph_char_t *ptr = NULL;
  if (CGRAPH_ISSTR(string) && (0 < len)) {
    cgraph_char_t *str_ptr = (cgraph_char_t *)string;
    cgraph_size_t i = 0;
    for (; ('\0' != *str_ptr) && (i < len); str_ptr++, i++) {
      if (ch == *str_ptr) {
        ptr = str_ptr;
      }
    }
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNSTR(string)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
    }
    if (0 >= len) {
      cgraph_error_printf(
          CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
          "string length %ld is smaller than or equal to zero error", len);
    }
  }
#endif

  return ptr;
}

cgraph_char_t *cgraph_strrchrn(const cgraph_char_t *string, cgraph_int_t ch,
                               const cgraph_size_t num) {
  cgraph_char_t *ptr = NULL;
  if (CGRAPH_ISSTR(string) && (0 < num)) {
    cgraph_char_t *str_ptr = (cgraph_char_t *)string;
    for (; '\0' != *str_ptr; str_ptr++) {
      if (ch == *str_ptr) {
        ptr = str_ptr;
      }
    }
    if (NULL != ptr) {
      cgraph_size_t cnt = 0;
      for (str_ptr = ptr; string != str_ptr; str_ptr--) {
        if (ch == *str_ptr) {
          cnt += 1;
          if (cnt >= num) {
            ptr = str_ptr;
            break;
          }
        }
      }
    }
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNSTR(string)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
    }
    if (0 >= num) {
      cgraph_error_printf(
          CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
          "given character number %ld is smaller than or equal to zero error",
          num);
    }
  }
#endif

  return ptr;
}

cgraph_char_t *cgraph_strstr(const cgraph_char_t *src_str,
                             cgraph_char_t *trg_str) {
  cgraph_char_t *ptr = NULL;
  if (CGRAPH_ISSTR(src_str) && CGRAPH_ISSTR(trg_str)) {
    ptr = strstr(src_str, trg_str);
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNSTR(trg_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string is empty");
    }
    if (CGRAPH_ISNSTR(src_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
    }
  }
#endif

  return ptr;
}

cgraph_char_t *cgraph_strnstr(const cgraph_char_t *src_str,
                              cgraph_char_t *trg_str, const cgraph_size_t len) {
  cgraph_char_t *ptr = NULL;
  if (CGRAPH_ISSTR(src_str) && CGRAPH_ISSTR(trg_str) && (0 < len)) {
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNSTR(trg_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string is empty");
    }
    if (CGRAPH_ISNSTR(src_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
    }
    if (0 >= len) {
      cgraph_error_printf(
          CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
          "string length %ld is smaller than or equal to zero error", len);
    }
  }
#endif

  return ptr;
}

cgraph_char_t *cgraph_strstrn(const cgraph_char_t *src_str,
                              cgraph_char_t *trg_str, const cgraph_size_t num) {
  cgraph_char_t *ptr = NULL;
  if (CGRAPH_ISSTR(src_str) && CGRAPH_ISSTR(trg_str) && (0 < num)) {
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNSTR(trg_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string is empty");
    }
    if (CGRAPH_ISNSTR(src_str)) {
      cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
    }
    if (0 >= num) {
      cgraph_error_printf(
          CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
          "given character number %ld is smaller than or equal to zero error",
          num);
    }
  }
#endif

  return ptr;
}
