#include <stdlib.h>
#include <string.h>

#include "cgraph_error.h"
#include "cgraph_memory.h"

void *cgraph_calloc(const cgraph_size_t size) {
  void *cthis = NULL;
  if (0 < size) {
    cthis = calloc(size, 1);
  }
#ifdef DEBUG
  if (0 >= size) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "memory size %ld is a negative number or equal to zero",
                     size);
  }
#endif

  return cthis;
}

void *cgraph_realloc(void *cthis, const cgraph_size_t old_size,
                     const cgraph_size_t new_size, cgraph_bool_t *error) {
  void *_cthis = cthis;
  if (0 < new_size) {
    /** memory lazy release */
    if (new_size > old_size) {
      _cthis = realloc(cthis, new_size);
      if (NULL != _cthis) {
        memset(CGRAPH_PTRADDR2V(_cthis, old_size), 0, new_size - old_size);
      } else {
#ifdef DEBUG
        cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                         "memory is re-allocated error, and the "
                         "pointer is kept to the old one");
#endif
        _cthis = cthis;
        if (NULL != error) {
          *error = CGRAPH_TRUE;
        }
      }
    }
  }
#ifdef DEBUG
  if (0 >= new_size) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "error flag pointer is empty");
  }
#endif

  return _cthis;
}

void *cgraph_memset(void *cthis, cgraph_size_t size, cgraph_uint_t data) {
  if (NULL != cthis) {
    memset(cthis, data & 0xFF, size);
  }
#ifdef DEBUG
  if (NULL == cthis) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "source pointer is empty");
  }
#endif

  return cthis;
}

void *cgraph_memcpy(void *object, const void *cthis, const cgraph_size_t size) {
  if ((NULL != object) && (NULL != cthis) && (object != cthis) && (0 < size)) {
    memcpy(object, cthis, size);
  }
#ifdef DEBUG
  if (NULL == object) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "target pointer is empty");
  }
  if (NULL == cthis) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "source pointer is empty");
  }
  if (object == cthis) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "source pointer is equal to target pointer");
  }
  if (0 >= size) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "memory size %ld is a negative number or equal to zero",
                     size);
  }
#endif

  return object;
}

void *cgraph_memscpy(void *object, const cgraph_size_t size,
                     const cgraph_size_t old_len, const void *cthis,
                     const cgraph_size_t new_len) {
  if ((NULL != object) && (NULL != cthis) && (object != cthis) && (0 < size)) {
    cgraph_char_t *_object = ((cgraph_char_t *)object) + old_len,
                  *_cthis = (cgraph_char_t *)cthis;
    cgraph_size_t i = old_len, j = 0;
    for (; (j < new_len) && (i < size); i++) {
      *_object = *_cthis;
    }
  }
#ifdef DEBUG
  if (NULL == object) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "target pointer is empty");
  }
  if (NULL == cthis) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "source pointer is empty");
  }
  if (object == cthis) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "source pointer is equal to target pointer");
  }
  if (0 >= size) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "memory size %ld is a negative number or equal to zero",
                     size);
  }
#endif

  return object;
}

cgraph_char_t *cgraph_strcpy(cgraph_char_t *object,
                             const cgraph_char_t *cthis) {
  cgraph_char_t *_object = object;
  if ((NULL != object) && (NULL != cthis) && (object != cthis)) {
    _object = strcpy(object, cthis);
  }
#ifdef DEBUG
  if (NULL == object) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "target pointer is empty");
  }
  if (NULL == cthis) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "source pointer is empty");
  }
  if (object == cthis) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "source pointer is equal to target pointer");
  }
#endif

  return _object;
}

cgraph_char_t *cgraph_strncpy(cgraph_char_t *object, const cgraph_char_t *cthis,
                              const cgraph_size_t len) {
  cgraph_char_t *_object = object;
  if ((NULL != object) && (NULL != cthis) && (object != cthis)) {
    _object = strncpy(object, cthis, len);
  }
#ifdef DEBUG
  if (NULL == object) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "target pointer is empty");
  }
  if (NULL == cthis) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "source pointer is empty");
  }
  if (object == cthis) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "source pointer is equal to target pointer");
  }
#endif

  return _object;
}

cgraph_char_t *cgraph_strscpy(cgraph_char_t *object, const cgraph_size_t size,
                              const cgraph_char_t *cthis) {
  if ((NULL != object) && (NULL != cthis)) {
    cgraph_size_t _size = size - 1;
    cgraph_char_t *_object = object, *_cthis = (cgraph_char_t *)cthis;
    for (; (0 < _size) && ('\0' != *_cthis); _size--, _object++, _cthis++) {
      *_object = *_cthis;
    }
    *_object = '\0';
  }

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
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "target pointer is empty");
  }
  if (NULL == cthis) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "source pointer is empty");
  }
  if (object == cthis) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
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
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "target pointer is empty");
  }
  if (NULL == cthis) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "source pointer is empty");
  }
  if (object == cthis) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
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

void cgraph_free(void *cthis) {
  if (NULL != cthis) {
    free(cthis);
    cthis = NULL;
  }
#ifdef DEBUG
  else {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "empty pointer is freed");
  }
#endif
}

cgraph_bool_t cgraph_memcmp(const void *x, const void *y,
                            const cgraph_size_t size) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (x == y) {
    flag = CGRAPH_TRUE;
  } else if ((NULL != x) && (NULL != y) && (0 < size)) {
    if (0 == memcmp(x, y, size)) {
      flag = CGRAPH_TRUE;
    }
  }
#ifdef DEBUG
  if (NULL == x) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "target pointer is empty");
  }
  if (NULL == y) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "source pointer is empty");
  }
  if (0 >= size) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "length %ld is a negative number or equal to zero", size);
  }
#endif

  return flag;
}

cgraph_bool_t cgraph_strcmp(const cgraph_char_t *x, const cgraph_char_t *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    if (0 == strcmp(x, y)) {
      flag = CGRAPH_TRUE;
    }
  }
#ifdef DEBUG
  if (NULL == x) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "target pointer is empty\n");
  }
  if (NULL == y) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "source pointer is empty");
  }
#endif

  return flag;
}
