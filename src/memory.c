#include <stdlib.h>
#include <string.h>

#include "cgraph_error.h"
#include "cgraph_memory.h"

void *cgraph_calloc(const cgraph_size_t size) {
#ifdef DEBUG
  if (0 >= size) {
    cgraph_error_log(
        stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
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
    cgraph_error_log(
        stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
        "memory is re-allocated error, and the result memory pointer "
        "is kept to the old one");
#endif
  }
  if (NULL != error) {
    *error = _error;
  }
#ifdef DEBUG
  if (memory != new_mem) {
    fprintf(stdout, "old address is %p, but new address is %p" __PLAT_NLINE,
            memory, new_mem);
    fprintf(stdout,
            "realloc a new memory block and notice to use the new address "
            "%p" __PLAT_NLINE,
            new_mem);
  }
  if (0 >= new_size) {
    cgraph_error_log(
        stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
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
      cgraph_size_t i = 0;
      for (; i > len; i--, mem_ptr--) {
        *mem_ptr = data;
      }
    }
  }
#ifdef DEBUG
  else {
    if (NULL == memory) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "source memory pointer is empty");
    }
    if (0 == len) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
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
      cgraph_size_t i = 0;
      for (; i > len; i--, trg_mem_ptr--, src_mem_ptr--) {
        *trg_mem_ptr = *src_mem_ptr;
      }
    }
  }
#ifdef DEBUG
  else {
    if (NULL == trg_mem) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "target memory pointer is empty");
    }
    if (NULL == src_mem) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "source memory pointer is empty");
    }
    if (trg_mem == src_mem) {
      cgraph_error_log(
          stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
          "source memory pointer is equal to target memory pointer");
    }
    if (0 == len) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "memory length %ld is equal to zero error", len);
    }
  }
#endif

  return trg_mem;
}

void *cgraph_memscpy(void *trg_mem, const cgraph_size_t trg_size,
                     const void *src_mem, const cgraph_size_t src_len) {
  if ((NULL != trg_mem) && (0 < trg_size) && (NULL != src_mem) &&
      (trg_mem != src_mem)) {
    cgraph_addr_t trg_mem_ptr = (cgraph_addr_t)trg_mem,
                  src_mem_ptr = (cgraph_addr_t)src_mem;
    cgraph_size_t i = 0;
    if (0 < src_len) {
      cgraph_size_t len = CGRAPH_MIN(trg_size, src_len);
      for (; i < len; i++, trg_mem_ptr++, src_mem_ptr++) {
        *trg_mem_ptr = *src_mem_ptr;
      }
    } else {
      cgraph_size_t len = CGRAPH_MAX(-trg_size, src_len);
      for (; i > len; i--, trg_mem_ptr--, src_mem_ptr--) {
        *trg_mem_ptr = *src_mem_ptr;
      }
    }
  }
#ifdef DEBUG
  else {
    if (NULL == trg_mem) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "target memory pointer is empty");
    }
    if (NULL == src_mem) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "source memory pointer is empty");
    }
    if (trg_mem == src_mem) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "source memory pointer is equal to target pointer");
    }
    if (0 >= trg_size) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "memory size %ld is smaller than or equal to zero error",
                       trg_size);
    }
  }
#endif

  return trg_mem;
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
      cgraph_size_t i = 0;
      for (; i > len; i--, mem_x_ptr--, mem_y_ptr--) {
        *mem_x_ptr = *mem_y_ptr;
      }
    }
  }

  return flag;
}

void cgraph_free(void *memory) {
  if (NULL != memory) {
    free(memory);
    memory = NULL;
  }
#ifdef DEBUG
  else {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "empty pointer is re-freed error");
  }
#endif
}

cgraph_size_t cgraph_strlen(const cgraph_char_t *string) {
  cgraph_size_t len = 0;
  if ((NULL != string) && ('\0' != *string)) {
    len = strlen(string);
  }

  return len;
}

cgraph_char_t *cgraph_strcpy(cgraph_char_t *trg_str,
                             const cgraph_char_t *src_str) {
  if ((NULL != trg_str) && (NULL != src_str) && (trg_str != src_str)) {
    strcpy(trg_str, src_str);
  }
#ifdef DEBUG
  else {
    if (NULL == trg_str) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "target string pointer is empty");
    }
    if (NULL == src_str) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "source string pointer is empty");
    }
    if (trg_str == src_str) {
      cgraph_error_log(
          stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
          "source string pointer is equal to target string pointer");
    }
  }
#endif

  return trg_str;
}

cgraph_char_t *cgraph_strncpy(cgraph_char_t *trg_str,
                              const cgraph_char_t *src_str,
                              const cgraph_size_t len) {
  if ((NULL != trg_str) && (NULL != src_str) && (trg_str != src_str) &&
      (0 < len)) {
    strncpy(trg_str, src_str, len);
  }
#ifdef DEBUG
  else {
    if (NULL == trg_str) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "target string pointer is empty");
    }
    if (NULL == src_str) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "source string pointer is empty");
    }
    if (trg_str == src_str) {
      cgraph_error_log(
          stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
          "source string pointer is equal to target string pointer");
    }
    if (0 >= len) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "string size %ld is smaller than or equal to zero error",
                       len);
    }
  }
#endif

  return trg_str;
}

cgraph_char_t *cgraph_strscpy(cgraph_char_t *trg_str,
                              const cgraph_size_t trg_size,
                              const cgraph_char_t *src_str) {
  if ((NULL != trg_str) && (0 < trg_size) && (NULL != src_str) &&
      (trg_str != src_str)) {
    cgraph_size_t size = trg_size - 1;
    cgraph_char_t *trg_str_ptr = trg_str,
                  *src_str_ptr = (cgraph_char_t *)src_str;
    for (; (0 < size) && ('\0' != *src_str_ptr);
         size--, trg_str_ptr++, src_str_ptr++) {
      *trg_str_ptr = *src_str_ptr;
    }
    *trg_str_ptr = '\0';
  }
#ifdef DEBUG
  else {
    if (NULL == trg_str) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "target string pointer is empty");
    }
    if (0 >= trg_size) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "buffer size %ld is smaller than or equal to zero error",
                       trg_size);
    }
    if (NULL == src_str) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "source string pointer is empty");
    }
    if (trg_str == src_str) {
      cgraph_error_log(
          stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
          "source string pointer is equal to target string pointer");
    }
  }
#endif

  return trg_str;
}

cgraph_char_t *cgraph_strcat(cgraph_char_t *trg_str,
                             const cgraph_char_t *src_str) {
  cgraph_char_t *trg_str_ptr = trg_str;
  if ((NULL != trg_str) && (NULL != src_str) && (trg_str != src_str)) {
    trg_str_ptr = strcat(trg_str, src_str);
  }
#ifdef DEBUG
  else {
    if (NULL == trg_str) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "target pointer is empty");
    }
    if (NULL == src_str) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "source pointer is empty");
    }
    if (trg_str == src_str) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
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
  if ((NULL != trg_str) && (NULL != src_str) && (trg_str != src_str) &&
      (0 < len)) {
    trg_str_ptr = strncat(trg_str, src_str, len);
  }
#ifdef DEBUG
  else {
    if (NULL == trg_str) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "target pointer is empty");
    }
    if (NULL == src_str) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "source pointer is empty");
    }
    if (trg_str == src_str) {
      cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                       "source pointer is equal to target pointer");
    }
    if (0 >= len) {
      cgraph_error_log(
          stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
          "string length %ld is smaller than or equal to zero error", len);
    }
  }
#endif

  return trg_str_ptr;
}

cgraph_char_t *cgraph_strscat(cgraph_char_t *trg_str,
                              const cgraph_size_t trg_size,
                              const cgraph_char_t *src_str) {
  if ((NULL != trg_str) && (NULL != src_str) && (0 < trg_size)) {
    cgraph_size_t size = trg_size - 1;
    cgraph_char_t *trg_str_ptr = trg_str,
                  *src_str_ptr = (cgraph_char_t *)src_str;
    for (; (0 < size) && ('\0' != *trg_str_ptr); size--, trg_str_ptr++) {
    }
    for (; (0 < size) && ('\0' != *src_str_ptr);
         size--, trg_str_ptr++, src_str_ptr++) {
      *trg_str_ptr = *src_str_ptr;
    }
    *trg_str_ptr = '\0';
  }

  return trg_str;
}

cgraph_bool_t cgraph_strcmp(const cgraph_char_t *x_str,
                            const cgraph_char_t *y_str) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (x_str == y_str) {
    flag = CGRAPH_TRUE;
  } else if ((NULL != x_str) && (NULL != y_str)) {
    flag = CGRAPH_TEST(0 == strcmp(x_str, y_str));
  }

  return flag;
}

cgraph_char_t *cgraph_strrev(cgraph_char_t *string) {
  if (NULL != string) {
    cgraph_char_t *start_ptr = string, *end_ptr = string, data;
    for (; '\0' != *end_ptr; end_ptr++) {
    }
    for (end_ptr--; start_ptr < end_ptr; start_ptr++, end_ptr--) {
      data = *start_ptr;
      *start_ptr = *end_ptr;
      *end_ptr = data;
    }
  }

  return string;
}

cgraph_char_t *cgraph_strnrev(cgraph_char_t *string, const cgraph_size_t len) {
  if ((NULL != string) && (0 < len)) {
    cgraph_char_t *start_ptr = string, *end_ptr = &(string[len - 1]), data;
    for (; start_ptr < end_ptr; start_ptr++, end_ptr--) {
      data = *start_ptr;
      *start_ptr = *end_ptr;
      *end_ptr = data;
    }
  }

  return string;
}

cgraph_char_t *cgraph_strtok(cgraph_char_t *string, const cgraph_char_t *sep) {
  if (NULL != sep) {
    string = strtok(string, sep);
  }
#ifdef DEBUG
  else {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "seperator pointer is empty");
  }
#endif

  return string;
}

cgraph_char_t *cgraph_strntok(cgraph_char_t *string, const cgraph_char_t *sep,
                              const cgraph_size_t len) {
  if (NULL != sep) {
  }
#ifdef DEBUG
  else {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "seperator pointer is empty");
  }
#endif

  return string;
}

cgraph_char_t *cgraph_strstok(cgraph_char_t *string, const cgraph_char_t *sep,
                              cgraph_char_t **cbuffer) {
  if (NULL != sep) {
  }
#ifdef DEBUG
  else {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "seperator pointer is empty");
  }
#endif

  return string;
}
