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

void *cgraph_realloc(void *cthis, const cgraph_size_t old_size,
                     const cgraph_size_t new_size, cgraph_bool_t *error) {
  cgraph_bool_t _error = CGRAPH_TRUE;
  void *_cthis = cthis;
  if (old_size == new_size) {
    _error = CGRAPH_FALSE;
  } else if ((0 < new_size) && (NULL != (_cthis = realloc(cthis, new_size)))) {
    cgraph_size_t delta_size = new_size - old_size;
    _error = CGRAPH_FALSE;
    if (0 < delta_size) {
      memset(CGRAPH_PTRADDR2V(_cthis, old_size), 0, delta_size);
    }
  } else {
    _cthis = cthis;
#ifdef DEBUG
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "memory is re-allocated error, and the memory pointer "
                     "is kept to the old one");
#endif
  }
  if (NULL != error) {
    *error = _error;
  }
#ifdef DEBUG
  if (cthis != _cthis) {
    fprintf(stdout, "old address is %p, but new address is %p" __PLAT_NLINE,
            cthis, _cthis);
    fprintf(stdout,
            "realloc a new memory block and notice to use the new address "
            "%p" __PLAT_NLINE,
            _cthis);
  }
  if (0 >= new_size) {
    cgraph_error_log(
        stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
        "memory size %ld is a negative number or equal to zero error",
        new_size);
  }
#endif

  return _cthis;
}

void *cgraph_memset(void *cthis, cgraph_uint_t data, cgraph_size_t size) {
  if (NULL != cthis) {
    if (0 < size) {
      memset(cthis, data, size);
    } else {
      cgraph_addr_t _cthis = (cgraph_addr_t)cthis;
      cgraph_size_t i = 0;
      for (; i > size; i--, _cthis--) {
        *_cthis = data;
      }
    }
  }
#ifdef DEBUG
  if (NULL == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source memory pointer is empty");
  }
  if (0 == size) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "memory size %ld is equal to zero error", size);
  }
#endif

  return cthis;
}

void *cgraph_memcpy(void *object, const void *cthis, const cgraph_size_t size) {
  if ((NULL != object) && (NULL != cthis) && (object != cthis)) {
    if (0 < size) {
      memcpy(object, cthis, size);
    } else {
      cgraph_addr_t _object = (cgraph_addr_t)object,
                    _cthis = (cgraph_addr_t)cthis;
      cgraph_size_t i = 0;
      for (; i > size; i--, _object--, _cthis--) {
        *_object = *_cthis;
      }
    }
  }
#ifdef DEBUG
  if (NULL == object) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "target memory pointer is empty");
  }
  if (NULL == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source memory pointer is empty");
  }
  if (object == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source pointer is equal to target pointer");
  }
  if (0 == size) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "memory size %ld is equal to zero error", size);
  }
#endif

  return object;
}

void *cgraph_memscpy(void *object, const cgraph_size_t size, const void *cthis,
                     const cgraph_size_t len) {
  if ((NULL != object) && (NULL != cthis) && (object != cthis) && (0 < size)) {
    cgraph_addr_t _object = (cgraph_addr_t)object,
                  _cthis = (cgraph_addr_t)cthis;
    cgraph_size_t i = 0;
    if (0 < len) {
      cgraph_size_t _len = CGRAPH_MIN(size, len);
      for (; i < _len; i++, _object++, _cthis++) {
        *_object = *_cthis;
      }
    } else {
      cgraph_size_t _len = CGRAPH_MAX(-size, len);
      for (; i > _len; i--, _object--, _cthis--) {
        *_object = *_cthis;
      }
    }
  }
#ifdef DEBUG
  if (NULL == object) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "target memory pointer is empty");
  }
  if (NULL == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source memory pointer is empty");
  }
  if (object == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source memory pointer is equal to target pointer");
  }
  if (0 >= size) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "memory size %ld is smaller than or equal to zero error",
                     size);
  }
#endif

  return object;
}

cgraph_bool_t cgraph_memcmp(const void *x, const void *y,
                            const cgraph_size_t size) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((x == y) || (0 == size)) {
    flag = CGRAPH_TRUE;
  } else if ((NULL != x) && (NULL != y)) {
    if (0 < size) {
      flag = CGRAPH_TEST(0 == memcmp(x, y, size));
    } else {
      cgraph_addr_t _x = (cgraph_addr_t)x, _y = (cgraph_addr_t)y;
      cgraph_size_t i = 0;
      for (; i > size; i--, _x--, _y--) {
        *_x = *_y;
      }
    }
  }
#ifdef DEBUG
  if (NULL == x) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "target memory pointer is empty");
  }
  if (NULL == y) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source memory pointer is empty");
  }
#endif

  return flag;
}

void cgraph_free(void *cthis) {
  if (NULL != cthis) {
    free(cthis);
    cthis = NULL;
  }
#ifdef DEBUG
  if (NULL == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "empty pointer is re-freed error");
  }
#endif
}

cgraph_size_t cgraph_strlen(const cgraph_char_t *cthis) {
  cgraph_size_t len = 0;
  if (NULL != cthis) {
    len = strlen(cthis);
  }
#ifdef DEBUG
  if (NULL == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "string pointer is empty error");
  }
#endif

  return len;
}

cgraph_char_t *cgraph_strcpy(cgraph_char_t *object,
                             const cgraph_char_t *cthis) {
  if ((NULL != object) && (NULL != cthis) && (object != cthis)) {
    strcpy(object, cthis);
  }
#ifdef DEBUG
  if (NULL == object) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "target string pointer is empty");
  }
  if (NULL == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source string pointer is empty");
  }
  if (object == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source string pointer is equal to target string pointer");
  }
#endif

  return object;
}

cgraph_char_t *cgraph_strncpy(cgraph_char_t *object, const cgraph_char_t *cthis,
                              const cgraph_size_t len) {
  if ((NULL != object) && (NULL != cthis) && (object != cthis)) {
    strncpy(object, cthis, len);
  }
#ifdef DEBUG
  if (NULL == object) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "target string pointer is empty");
  }
  if (NULL == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source string pointer is empty");
  }
  if (object == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source string pointer is equal to target string pointer");
  }
#endif

  return object;
}

cgraph_char_t *cgraph_strscpy(cgraph_char_t *object, const cgraph_size_t size,
                              const cgraph_char_t *cthis) {
  if ((NULL != object) && (NULL != cthis) && (object != cthis)) {
    cgraph_size_t _size = size - 1;
    cgraph_char_t *_object = object, *_cthis = (cgraph_char_t *)cthis;
    for (; (0 < _size) && ('\0' != *_cthis); _size--, _object++, _cthis++) {
      *_object = *_cthis;
    }
    *_object = '\0';
  }
#ifdef DEBUG
  if (NULL == object) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "target string pointer is empty");
  }
  if (NULL == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source string pointer is empty");
  }
  if (object == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source string pointer is equal to target string pointer");
  }
#endif

  return object;
}

cgraph_char_t *cgraph_strcat(cgraph_char_t *object,
                             const cgraph_char_t *cthis) {
  cgraph_char_t *_object = object;
  if ((NULL != object) && (NULL != cthis) && (object != cthis)) {
    _object = strcat(object, cthis);
  }
#ifdef DEBUG
  if (NULL == object) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "target pointer is empty");
  }
  if (NULL == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source pointer is empty");
  }
  if (object == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source pointer is equal to target pointer");
  }
#endif

  return _object;
}

cgraph_char_t *cgraph_strncat(cgraph_char_t *object, const cgraph_char_t *cthis,
                              const cgraph_size_t len) {
  cgraph_char_t *_object = object;
  if ((NULL != object) && (NULL != cthis) && (object != cthis)) {
    _object = strncat(object, cthis, len);
  }
#ifdef DEBUG
  if (NULL == object) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "target pointer is empty");
  }
  if (NULL == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source pointer is empty");
  }
  if (object == cthis) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source pointer is equal to target pointer");
  }
#endif

  return _object;
}

cgraph_char_t *cgraph_strscat(cgraph_char_t *object, const cgraph_size_t size,
                              const cgraph_char_t *cthis) {
  if ((NULL != object) && (NULL != cthis)) {
    cgraph_size_t _size = size - 1;
    cgraph_char_t *_object = object, *_cthis = (cgraph_char_t *)cthis;
    for (; (0 < _size) && ('\0' != *_object); _size--, _object++) {
    }
    for (; (0 < _size) && ('\0' != *_cthis); _size--, _object++, _cthis++) {
      *_object = *_cthis;
    }
    *_object = '\0';
  }

  return object;
}

cgraph_bool_t cgraph_strcmp(const cgraph_char_t *x, const cgraph_char_t *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    flag = CGRAPH_TEST(0 == strcmp(x, y));
  }
#ifdef DEBUG
  if (NULL == x) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "target pointer is empty\n");
  }
  if (NULL == y) {
    cgraph_error_log(stderr, CGRAPH_ERROR_FUNCTION_STYLE_ENTRY,
                     "source pointer is empty");
  }
#endif

  return flag;
}

cgraph_char_t *cgraph_strrev(cgraph_char_t *object) {
  if (NULL != object) {
    cgraph_char_t *start = object, *end = object, tmp;
    for (; '\0' != *end; end++) {
    }
    for (end--; start < end; start++, end--) {
      tmp = *start;
      *start = *end;
      *end = tmp;
    }
  }

  return object;
}

cgraph_char_t *cgraph_strnrev(cgraph_char_t *object, const cgraph_size_t size) {
  if (NULL != object) {
    cgraph_char_t *start = object, *end = &(object[size - 1]), tmp;
    for (; start < end; start++, end--) {
      tmp = *start;
      *start = *end;
      *end = tmp;
    }
  }

  return object;
}
