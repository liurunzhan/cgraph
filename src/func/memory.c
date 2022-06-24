#include <stdlib.h>
#include <string.h>

#include "cgraph_error.h"
#include "cgraph_math.h"
#include "cgraph_memory.h"

void *cgraph_calloc(const cgraph_size_t size) {
  void *res = NULL;
  if ((0 >= size) || (NULL == (res = calloc(size, 1)))) {
    goto ERROR;
  }

  return res;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                        CGRAPH_LEVEL_FATAL,
                        "memory size %ld is an unsupported value", size);
#endif

  return NULL;
}

void *cgraph_realloc(void *memory, const cgraph_size_t old_size,
                     const cgraph_size_t new_size, cgraph_bool_t *error) {
  void *new_mem = memory;
  cgraph_size_t delta_size = new_size - old_size;
  if ((0 == delta_size) || (0 >= new_size) ||
      (NULL == (new_mem = realloc(memory, new_size)))) {
    goto ERROR;
  }
  if (0 < delta_size) {
    memset(CGRAPH_PTRADDR2V(new_mem, old_size), 0, delta_size);
  }

  if (NULL != error) {
    *error = CGRAPH_FALSE;
  }
#ifdef DEBUG
  if (memory != new_mem) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_INFO,
        "old address " CGRAPH_VARADDR_OUT_FMT
        " is not equal to the new one " CGRAPH_VARADDR_OUT_FMT __PLAT_LEND,
        memory, new_mem);
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_INFO,
        "realloc a new memory block and notice to use the new "
        "address " CGRAPH_VARADDR_OUT_FMT __PLAT_LEND,
        new_mem);
  }
#endif

  return new_mem;
  /* errors output for debugging */
ERROR:
  if (NULL != error) {
    *error = CGRAPH_TRUE;
  }
#ifdef DEBUG
  if (0 == delta_size) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "reallocated memory size %ld is equal to the previous", new_size);
  }
  if (0 >= new_size) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "reallocated memory size %ld is an unsupported value, "
        "keep it as default address",
        new_size);
  }
  if (NULL == new_mem) {
  }
#endif

  return memory;
}

void *cgraph_memset(void *memory, cgraph_uint_t data, cgraph_size_t len) {
  if ((NULL == memory) || (0 == len)) {
    goto ERROR;
  }
  if (0 < len) {
    memset(memory, data, len);
  } else {
    cgraph_addr_t mem_ptr = (cgraph_addr_t)memory;
    CGRAPH_RLOOP(i, 0, len)
    *(mem_ptr--) = data;
    CGRAPH_LOOP_END
  }

  return memory;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (NULL == memory) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source memory pointer is empty");
  }
  if (0 == len) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "copied memory size %ld is an unsupported value",
                          len);
  }
#endif

  return memory;
}

void *cgraph_memcpy(void *trg_mem, const void *src_mem,
                    const cgraph_size_t len) {
  if ((NULL == trg_mem) || (NULL == src_mem) || (0 == len)) {
    goto ERROR;
  }
  if (trg_mem != src_mem) {
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

  return trg_mem;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (NULL == trg_mem) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target memory pointer is empty");
  }
  if (NULL == src_mem) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source memory pointer is empty");
  }
  if (0 == len) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "copied memory size %ld is an unsupported value",
                          len);
  }
#endif

  return trg_mem;
}

void *cgraph_memscpy(void *trg_mem, const void *src_mem,
                     const cgraph_size_t trg_size,
                     const cgraph_size_t src_len) {
  if ((NULL == trg_mem) || (NULL == src_mem) || (0 >= trg_size) ||
      (0 == src_len)) {
    goto ERROR;
  }
  if (trg_mem != src_mem) {
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

  return trg_mem;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (NULL == trg_mem) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target memory pointer is empty");
  }
  if (NULL == src_mem) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source memory pointer is empty");
  }
  if (0 >= trg_size) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target memory size %ld is an unsupported value",
                          trg_size);
  }
  if (0 == src_len) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "copied memory size %ld is an unsupported value",
                          src_len);
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
  cgraph_uint_t data;
  cgraph_addr_t start_ptr = (cgraph_addr_t)memory,
                end_ptr = ((cgraph_addr_t)memory) + len,
                tmp_ptr = (cgraph_addr_t)&data;
  if ((NULL == memory) || (0 >= len)) {
    goto ERROR;
  }
  for (; start_ptr < end_ptr; start_ptr++, end_ptr--) {
    *tmp_ptr = *start_ptr;
    *start_ptr = *end_ptr;
    *end_ptr = *tmp_ptr;
  }

  return memory;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (NULL == memory) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory pointer is empty");
  }
  if (0 >= len) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory length %ld is equal to zero error", len);
  }
#endif

  return memory;
}

void *cgraph_memchr(const void *memory, cgraph_int_t ch,
                    const cgraph_size_t len) {
  if ((NULL == memory) || (0 >= len)) {
    goto ERROR;
  }

  return memchr(memory, ch, len);
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (NULL == memory) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory pointer is empty");
  }
  if (0 == len) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory length %ld is equal to zero error", len);
  }
#endif

  return NULL;
}

void *cgraph_memrchr(const void *memory, cgraph_int_t ch,
                     const cgraph_size_t len) {
  cgraph_addr_t mem_ptr = ((cgraph_addr_t)memory) + len;
  cgraph_size_t i = 0;
  void *ptr = NULL;
  if ((NULL == memory) || (0 >= len)) {
    goto ERROR;
  }
  while ((ch != *(mem_ptr--)) && (len > (i++))) {
  }
  if (i < len) {
    ptr = mem_ptr;
  }

  return ptr;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (NULL == memory) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory pointer is empty");
  }
  if (0 >= len) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory length %ld is equal to zero error", len);
  }
#endif

  return NULL;
}

void cgraph_free(void *memory) {
  if (NULL != memory) {
    free(memory);
    memory = NULL;
  }
}

cgraph_size_t cgraph_abitlen(const void *memory, const cgraph_size_t len) {
  cgraph_size_t bits = 0;
  if ((NULL != memory) && (0 < len)) {
    cgraph_addr_t ptr = (cgraph_addr_t)memory;
    cgraph_size_t i = 0;
    for (; (0 == *ptr) && (i < len); i++, ptr++) {
    }
    bits = ((len - i) << 3) + cgraph_math_abitlen(*ptr);
  }

  return bits;
}

cgraph_size_t cgraph_adatlen(const void *memory, const cgraph_size_t len,
                             const cgraph_size_t datsize,
                             cgraph_bool_t (*func)(const void *data)) {
  cgraph_size_t datlen = len;
  if ((NULL != memory) && (0 < len)) {
    cgraph_addr_t ptr = (cgraph_addr_t)memory;
    for (; func(ptr) && (0 < datlen); ptr += datsize, datlen--) {
    }
  }

  return datlen;
}

cgraph_bool_t
cgraph_datcmp(const void *trg_mem, const void *src_mem, const cgraph_size_t len,
              const cgraph_size_t datsize,
              cgraph_bool_t (*func)(const void *x, const void *y)) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if ((NULL != trg_mem) && (NULL != src_mem) && (0 < len)) {
    cgraph_addr_t trg_ptr = (cgraph_addr_t)trg_mem,
                  src_ptr = (cgraph_addr_t)src_mem;
    res = CGRAPH_TRUE;
    CGRAPH_LOOP(i, 0, len)
    if (!func(trg_ptr, src_ptr)) {
      res = CGRAPH_FALSE;
      break;
    }
    trg_ptr += datsize;
    src_ptr += datsize;
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
  if (CGRAPH_ISNSTR2V(trg_str, src_str)) {
    goto ERROR;
  }

  return strcpy(trg_str, src_str);
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(trg_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string is empty");
  }
  if (CGRAPH_ISNSTR(src_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (trg_str == src_str) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "source string pointer is equal to target string pointer");
  }
#endif

  return trg_str;
}

cgraph_char_t *cgraph_strncpy(cgraph_char_t *trg_str,
                              const cgraph_char_t *src_str,
                              const cgraph_size_t len) {
  if (CGRAPH_ISNSTR2V(trg_str, src_str) || (0 >= len)) {
    goto ERROR;
  }
  return strncpy(trg_str, src_str, len);
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(trg_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string is empty");
  }
  if (CGRAPH_ISNSTR(src_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (trg_str == src_str) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "source string pointer is equal to target string pointer");
  }
  if (0 >= len) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "string size %ld is smaller than or equal to zero error", len);
  }
#endif

  return trg_str;
}

cgraph_char_t *cgraph_strscpy(cgraph_char_t *trg_str,
                              const cgraph_char_t *src_str,
                              const cgraph_size_t trg_size) {
  cgraph_size_t size = trg_size - 1;
  cgraph_char_t *trg_str_ptr = trg_str, *src_str_ptr = (cgraph_char_t *)src_str;
  if (CGRAPH_ISNSTR2V(trg_str, src_str) || (0 >= trg_size)) {
    goto ERROR;
  }
  for (; (0 < size) && ('\0' != *src_str_ptr); size--) {
    *(trg_str_ptr++) = *(src_str_ptr++);
  }
  *trg_str_ptr = '\0';

  return trg_str;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (NULL == trg_str) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string pointer is empty");
  }
  if (0 >= trg_size) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "buffer size %ld is smaller than or equal to zero error", trg_size);
  }
  if (CGRAPH_ISNSTR(src_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (trg_str == src_str) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "source string pointer is equal to target string pointer");
  }
#endif

  return trg_str;
}

cgraph_char_t *cgraph_strcat(cgraph_char_t *trg_str,
                             const cgraph_char_t *src_str) {
  if (CGRAPH_ISNSTR2V(trg_str, src_str)) {
    goto ERROR;
  }

  return strcat(trg_str, src_str);
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(trg_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string is empty");
  }
  if (CGRAPH_ISNSTR(src_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (trg_str == src_str) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source pointer is equal to target pointer");
  }
#endif

  return trg_str;
}

cgraph_char_t *cgraph_strncat(cgraph_char_t *trg_str,
                              const cgraph_char_t *src_str,
                              const cgraph_size_t len) {
  if (CGRAPH_ISNSTR2V(trg_str, src_str) || (0 >= len)) {
    goto ERROR;
  }

  return strncat(trg_str, src_str, len);
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(trg_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string is empty");
  }
  if (CGRAPH_ISNSTR(src_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (trg_str == src_str) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source pointer is equal to target pointer");
  }
  if (0 >= len) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "string length %ld is smaller than or equal to zero error", len);
  }
#endif

  return trg_str;
}

cgraph_char_t *cgraph_strscat(cgraph_char_t *trg_str,
                              const cgraph_char_t *src_str,
                              const cgraph_size_t trg_size) {
  cgraph_size_t size = trg_size - 1;
  cgraph_char_t *trg_str_ptr = trg_str, *src_str_ptr = (cgraph_char_t *)src_str;
  if (CGRAPH_ISNSTR2V(trg_str, src_str) || (0 >= trg_size)) {
    goto ERROR;
  }
  while ((0 < (size--)) && ('\0' != *(trg_str_ptr++))) {
  }
  for (; (0 < size) && ('\0' != *src_str_ptr); size--) {
    *(trg_str_ptr++) = *(src_str_ptr++);
  }
  *trg_str_ptr = '\0';

  return trg_str;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(trg_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string is empty");
  }
  if (CGRAPH_ISNSTR(src_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (trg_str == src_str) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source pointer is equal to target pointer");
  }
  if (0 >= trg_size) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "string length %ld is smaller than or equal to zero error", trg_size);
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
  cgraph_char_t *start_ptr = string, *end_ptr = string;
  if (CGRAPH_ISNSTR(string)) {
    goto ERROR;
  }
  for (; '\0' != *end_ptr; end_ptr++) {
  }
  for (end_ptr--; start_ptr < end_ptr; start_ptr++, end_ptr--) {
    cgraph_char_t data = *start_ptr;
    *start_ptr = *end_ptr;
    *end_ptr = data;
  }

  return string;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "source string is empty");
#endif

  return string;
}

cgraph_char_t *cgraph_strnrev(cgraph_char_t *string, const cgraph_size_t len) {
  cgraph_char_t *start_ptr = string, *end_ptr = string + len - 1;
  if (CGRAPH_ISNSTR(string) || (0 >= len)) {
    goto ERROR;
  }
  for (; start_ptr < end_ptr; start_ptr++, end_ptr--) {
    cgraph_char_t data = *start_ptr;
    *start_ptr = *end_ptr;
    *end_ptr = data;
  }

  return string;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(string)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "seperator string is empty");
  }
  if (0 >= len) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "string length %ld is smaller than or equal to zero error", len);
  }
#endif

  return string;
}

cgraph_char_t *cgraph_strtok(cgraph_char_t *string, const cgraph_char_t *sep) {
  if (CGRAPH_ISNSTR2V(string, sep)) {
    goto ERROR;
  }

  return strtok(string, sep);
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(string)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (CGRAPH_ISNSTR(sep)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "seperator string is empty");
  }
  if (string == sep) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is equal to seperator string");
  }
#endif

  return string;
}

cgraph_char_t *cgraph_strntok(cgraph_char_t *string, const cgraph_char_t *sep,
                              const cgraph_size_t len) {
  if (CGRAPH_ISNSTR2V(string, sep) || (0 >= len)) {
    goto ERROR;
  }

  return NULL;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(string)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (CGRAPH_ISNSTR(sep)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "seperator string is empty");
  }
  if (string == sep) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is equal to seperator string");
  }
#endif

  return string;
}

cgraph_char_t *cgraph_strstok(cgraph_char_t *string, const cgraph_char_t *sep,
                              cgraph_char_t **cbuf) {
  if (CGRAPH_ISNSTR2V(string, sep)) {
    goto ERROR;
  }

  return NULL;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(string)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (CGRAPH_ISNSTR(sep)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "seperator string is empty");
  }
  if (string == sep) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is equal to seperator string");
  }
#endif

  return string;
}

cgraph_char_t *cgraph_strchr(const cgraph_char_t *string, cgraph_int_t ch) {
  if (CGRAPH_ISNSTR(string)) {
    goto ERROR;
  }

  return strchr(string, ch);
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "source string is empty");

#endif

  return NULL;
}

cgraph_char_t *cgraph_strnchr(const cgraph_char_t *string, cgraph_int_t ch,
                              const cgraph_size_t len) {
  cgraph_char_t *ptr = NULL, *str_ptr = (cgraph_char_t *)string;
  cgraph_size_t i = 0;
  if (CGRAPH_ISNSTR(string) || (0 >= len)) {
    goto ERROR;
  }
  for (; ('\0' != *str_ptr) && (i < len); i++, str_ptr++) {
    if (ch == *str_ptr) {
      ptr = str_ptr;
      break;
    }
  }

  return ptr;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(string)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (0 >= len) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "string length %ld is smaller than or equal to zero error", len);
  }
#endif

  return NULL;
}

cgraph_char_t *cgraph_strchrn(const cgraph_char_t *string, cgraph_int_t ch,
                              const cgraph_size_t num) {
  cgraph_char_t *ptr = NULL, *str_ptr = (cgraph_char_t *)string;
  cgraph_size_t cnt = 0;
  if (CGRAPH_ISNSTR(string) || (0 >= num)) {
    goto ERROR;
  }
  for (; '\0' != *str_ptr; str_ptr++) {
    if (ch == *str_ptr) {
      cnt += 1;
      if (cnt >= num) {
        ptr = str_ptr;
        break;
      }
    }
  }

  return ptr;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(string)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (0 >= num) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "given character number %ld is smaller than or equal to zero error",
        num);
  }
#endif

  return NULL;
}

cgraph_char_t *cgraph_strrchr(const cgraph_char_t *string, cgraph_int_t ch) {
  if (CGRAPH_ISNSTR(string)) {
    goto ERROR;
  }

  return strrchr(string, ch);
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "source string is empty");
#endif

  return NULL;
}

cgraph_char_t *cgraph_strnrchr(const cgraph_char_t *string, cgraph_int_t ch,
                               const cgraph_size_t len) {
  cgraph_char_t *ptr = NULL, *str_ptr = (cgraph_char_t *)string;
  cgraph_size_t i = 0;
  if (CGRAPH_ISNSTR(string) || (0 >= len)) {
    goto ERROR;
  }
  for (; ('\0' != *str_ptr) && (i < len); str_ptr++, i++) {
    if (ch == *str_ptr) {
      ptr = str_ptr;
    }
  }

  return ptr;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(string)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (0 >= len) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "string length %ld is smaller than or equal to zero error", len);
  }
#endif

  return NULL;
}

cgraph_char_t *cgraph_strrchrn(const cgraph_char_t *string, cgraph_int_t ch,
                               const cgraph_size_t num) {
  cgraph_char_t *ptr = NULL, *str_ptr = (cgraph_char_t *)string;
  cgraph_size_t cnt = 0;
  if (CGRAPH_ISNSTR(string) || (0 >= num)) {
    goto ERROR;
  }
  for (; '\0' != *str_ptr; str_ptr++) {
    if (ch == *str_ptr) {
      ptr = str_ptr;
      cnt += 1;
    }
  }
  if ((NULL == ptr) || (num > cnt)) {
    goto ERROR;
  }
  for (str_ptr = ptr, cnt = 0; string != str_ptr; str_ptr--) {
    if (ch == *str_ptr) {
      cnt += 1;
      if (cnt >= num) {
        ptr = str_ptr;
        break;
      }
    }
  }

  return ptr;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(string)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (0 >= num) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "the number of given character %c is %ld, smaller than "
        "or equal to zero error",
        ch, num);
  }
  if (NULL == ptr) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "given character %c is not in input string", ch);
  }
  if (num > cnt) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "the number of given character %c is %ld, greater than real one %ld",
        ch, num, cnt);
  }
#endif

  return NULL;
}

cgraph_char_t *cgraph_strstr(const cgraph_char_t *src_str,
                             cgraph_char_t *trg_str) {
  if (CGRAPH_ISNSTR2V(src_str, trg_str)) {
    goto ERROR;
  }

  return strstr(src_str, trg_str);
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(trg_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string is empty");
  }
  if (CGRAPH_ISNSTR(src_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (trg_str == src_str) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is equal to target string");
  }
#endif

  return NULL;
}

cgraph_char_t *cgraph_strnstr(const cgraph_char_t *src_str,
                              cgraph_char_t *trg_str, const cgraph_size_t len) {
  cgraph_char_t *ptr = NULL;
  if (CGRAPH_ISNSTR2V(src_str, trg_str) || (0 >= len)) {
    goto ERROR;
  }

  return ptr;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(trg_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string is empty");
  }
  if (CGRAPH_ISNSTR(src_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (trg_str == src_str) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is equal to target string");
  }
  if (0 >= len) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "string length %ld is smaller than or equal to zero error", len);
  }
#endif

  return NULL;
}

cgraph_char_t *cgraph_strstrn(const cgraph_char_t *src_str,
                              cgraph_char_t *trg_str, const cgraph_size_t num) {
  cgraph_char_t *ptr = NULL;
  if (CGRAPH_ISNSTR2V(src_str, trg_str) || (0 >= num)) {
    goto ERROR;
  }

  return ptr;
  /* errors output for debugging */
ERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(trg_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "target string is empty");
  }
  if (CGRAPH_ISNSTR(src_str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (0 >= num) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "given character number %ld is smaller than or equal to zero error",
        num);
  }
#endif

  return NULL;
}
