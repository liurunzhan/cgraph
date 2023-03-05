#include <stdlib.h>
#include <string.h>

#include "cgraph_error.h"
#include "cgraph_math.h"
#include "cgraph_memory.h"

void *cgraph_calloc(const cgraph_size_t size) {
  void *res = NULL;
  if ((0 >= size) || (NULL == (res = calloc(size, 1)))) {
    goto CERROR;
  }

  return res;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                        CGRAPH_LEVEL_FATAL,
                        "memory size %ld is an unsupported value", size);
#endif

  return NULL;
}

void *cgraph_realloc(void *mem, const cgraph_size_t size1,
                     const cgraph_size_t size2, cgraph_bool_t *error) {
  void *mem2 = mem;
  cgraph_size_t dsize = size2 - size1;
  if ((0 == dsize) || (0 >= size2) || (NULL == (mem2 = realloc(mem, size2)))) {
    goto CERROR;
  }
  if (0 < dsize) {
    memset(CGRAPH_PTRADDR2V(mem2, size1), 0, dsize);
  }

  if (NULL != error) {
    *error = CGRAPH_FALSE;
  }
#ifdef DEBUG
  if (mem != mem2) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_INFO,
        "old address " CGRAPH_VARADDR_OUT_FMT
        " is not equal to the new one " CGRAPH_VARADDR_OUT_FMT __PLAT_LEND,
        mem, mem2);
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_INFO,
                          "realloc a new memory and notice to use the new "
                          "address " CGRAPH_VARADDR_OUT_FMT __PLAT_LEND,
                          mem2);
  }
#endif

  return mem2;
  /* errors output for debugging */
CERROR:
  if (NULL != error) {
    *error = CGRAPH_TRUE;
  }
#ifdef DEBUG
  if (0 == dsize) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "reallocated memory size %ld is equal to the previous", size2);
  }
  if (0 >= size2) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "reallocated memory size %ld is an unsupported value, "
        "keep it as default address",
        size2);
  }
  if (NULL == mem2) {
  }
#endif

  return mem;
}

void *cgraph_memset(void *mem, cgraph_uint_t ch, cgraph_size_t n) {
  if ((NULL == mem) || (0 == n)) {
    goto CERROR;
  }
  if (0 < n) {
    memset(mem, ch, n);
  } else {
    cgraph_addr_t pmem = (cgraph_addr_t)mem;
    CGRAPH_RLOOP(i, 0, n)
    *(pmem--) = ch;
    CGRAPH_LOOP_END
  }

  return mem;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (NULL == mem) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source memory is empty");
  }
  if (0 == n) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "copied memory size %ld is an unsupported value", n);
  }
#endif

  return mem;
}

void *cgraph_memcpy(void *dest, const void *src, const cgraph_size_t n) {
  if ((NULL == dest) || (NULL == src) || (0 == n)) {
    goto CERROR;
  }
  if (dest != src) {
    if (0 < n) {
      memcpy(dest, src, n);
    } else {
      cgraph_addr_t pdest = (cgraph_addr_t)dest, psrc = (cgraph_addr_t)src;
      CGRAPH_RLOOP(i, 0, n)
      *(pdest--) = *(psrc--);
      CGRAPH_LOOP_END
    }
  }

  return dest;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (NULL == dest) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "destination memory is empty");
  }
  if (NULL == src) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source memory is empty");
  }
  if (0 == n) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "copied memory size %ld is an unsupported value", n);
  }
#endif

  return dest;
}

void *cgraph_memscpy(void *dest, const void *src, const cgraph_size_t dn,
                     const cgraph_size_t sn) {
  if ((NULL == dest) || (NULL == src) || (0 >= dn) || (0 == sn)) {
    goto CERROR;
  }
  if (dest != src) {
    cgraph_addr_t pdest = (cgraph_addr_t)dest, psrc = (cgraph_addr_t)src;
    if (0 < sn) {
      cgraph_size_t n = CGRAPH_MIN(dn, sn);
      CGRAPH_LOOP(i, 0, n)
      *(pdest++) = *(psrc++);
      CGRAPH_LOOP_END
    } else {
      cgraph_size_t n = CGRAPH_MAX(-dn, sn);
      CGRAPH_RLOOP(i, 0, n)
      *(pdest--) = *(psrc--);
      CGRAPH_LOOP_END
    }
  }

  return dest;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (NULL == dest) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "destination memory pointer is empty");
  }
  if (NULL == src) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source memory pointer is empty");
  }
  if (0 >= dn) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "destination memory size %ld is an unsupported value",
                          dn);
  }
  if (0 == sn) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "copied memory size %ld is an unsupported value", sn);
  }
#endif

  return dest;
}

cgraph_size_t cgraph_memlen(const void *mem, const cgraph_uint_t end) {
  cgraph_size_t n = 0;
  if (NULL != mem) {
    cgraph_addr_t pmem = (cgraph_addr_t)mem;
    for (; end != *pmem; pmem++, n++) {
    }
  }

  return n;
}

void *cgraph_memend(const void *mem, const cgraph_uint_t end) {
  cgraph_addr_t pmem = (cgraph_addr_t)mem;
  if (NULL != pmem) {
    for (; end != *pmem; pmem++) {
    }
  }

  return pmem;
}

cgraph_bool_t cgraph_memcmp(const void *mem1, const void *mem2,
                            const cgraph_size_t n) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((mem1 == mem2) || (0 == n)) {
    flag = CGRAPH_TRUE;
  } else if ((NULL != mem1) && (NULL != mem2)) {
    if (0 < n) {
      flag = CGRAPH_TEST(0 == memcmp(mem1, mem2, n));
    } else {
      cgraph_addr_t pmem1 = (cgraph_addr_t)mem1, pmem2 = (cgraph_addr_t)mem2;
      CGRAPH_RLOOP(i, 0, n)
      *(pmem1--) = *(pmem2--);
      CGRAPH_LOOP_END
    }
  }

  return flag;
}

void *cgraph_memrev(void *mem, cgraph_size_t n) {
  cgraph_uint_t data;
  cgraph_addr_t pstart = (cgraph_addr_t)mem, pend = ((cgraph_addr_t)mem) + n,
                ptmp = (cgraph_addr_t)&data;
  if ((NULL == mem) || (0 >= n)) {
    goto CERROR;
  }
  for (; pstart < pend; pstart++, pend--) {
    *ptmp = *pstart;
    *pstart = *pend;
    *pend = *ptmp;
  }

  return mem;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (NULL == mem) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory pointer is empty");
  }
  if (0 >= n) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "mem length %ld is equal to zero error", n);
  }
#endif

  return mem;
}

void *cgraph_memchr(const void *mem, cgraph_int_t ch, const cgraph_size_t n) {
  if ((NULL == mem) || (0 >= n)) {
    goto CERROR;
  }

  return memchr(mem, ch, n);
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (NULL == mem) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory pointer is empty");
  }
  if (0 == n) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory length %ld is equal to zero error", n);
  }
#endif

  return NULL;
}

void *cgraph_memrchr(const void *mem, cgraph_int_t ch, const cgraph_size_t n) {
  cgraph_addr_t pmem = ((cgraph_addr_t)mem) + n;
  cgraph_size_t i = 0;
  if ((NULL == mem) || (0 >= n)) {
    goto CERROR;
  }
  for (; (ch != *pmem) && (n > i); pmem--, i++) {
  }

  return (n > i) ? pmem : NULL;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (NULL == mem) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "memory pointer is empty");
  }
  if (0 >= n) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "mem length %ld is equal to zero error", n);
  }
#endif

  return NULL;
}

void cgraph_free(void *mem) {
  if (NULL != mem) {
    free(mem);
    mem = NULL;
  }
}

cgraph_size_t cgraph_abitlen(const void *mem, const cgraph_size_t n) {
  cgraph_size_t bits = 0;
  if ((NULL != mem) && (0 < n)) {
    cgraph_addr_t pmem = (cgraph_addr_t)mem;
    cgraph_size_t i = 0;
    for (; (0 == *pmem) && (n > i); i++, pmem++) {
    }
    bits = ((n - i) << 3) + cgraph_math_abitlen(*pmem);
  }

  return bits;
}

cgraph_size_t cgraph_adatlen(const void *mem, const cgraph_size_t n,
                             const cgraph_size_t datsize,
                             cgraph_bool_t (*func)(const void *data)) {
  cgraph_size_t datlen = n;
  if ((NULL != mem) && (0 < n)) {
    cgraph_addr_t pmem = (cgraph_addr_t)mem;
    for (; (CGRAPH_TRUE == func(pmem)) && (0 < datlen);
         pmem += datsize, datlen--) {
    }
  }

  return datlen;
}

cgraph_bool_t cgraph_datcmp(const void *dest, const void *src,
                            const cgraph_size_t n, const cgraph_size_t datsize,
                            cgraph_bool_t (*func)(const void *x,
                                                  const void *y)) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if ((NULL != dest) && (NULL != src) && (0 < n)) {
    cgraph_addr_t pdest = (cgraph_addr_t)dest, psrc = (cgraph_addr_t)src;
    res = CGRAPH_TRUE;
    CGRAPH_LOOP(i, 0, n)
    if (CGRAPH_FALSE == func(pdest, psrc)) {
      res = CGRAPH_FALSE;
      break;
    }
    pdest += datsize;
    psrc += datsize;
    CGRAPH_LOOP_END
  }

  return res;
}

cgraph_size_t cgraph_strlen(const cgraph_char_t *str) {
  return CGRAPH_ISSTR(str) ? strlen(str) : 0;
}

cgraph_char_t *cgraph_strend(const cgraph_char_t *str) {
  cgraph_char_t *pstr = (cgraph_char_t *)str;
  if (CGRAPH_ISSTR(pstr)) {
    while ('\0' != *(++pstr)) {
    }
  }

  return pstr;
}

cgraph_char_t *cgraph_strcpy(cgraph_char_t *dest, const cgraph_char_t *src) {
  if (CGRAPH_ISNSTR2V(dest, src)) {
    goto CERROR;
  }

  return strcpy(dest, src);
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(dest)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "destination string is empty");
  }
  if (CGRAPH_ISNSTR(src)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (dest == src) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "source string pointer is equal to destination string pointer");
  }
#endif

  return dest;
}

cgraph_char_t *cgraph_strncpy(cgraph_char_t *dest, const cgraph_char_t *src,
                              const cgraph_size_t n) {
  if (CGRAPH_ISNSTR2V(dest, src) || (0 >= n)) {
    goto CERROR;
  }
  return strncpy(dest, src, n);
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(dest)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "destination string is empty");
  }
  if (CGRAPH_ISNSTR(src)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (dest == src) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "source string pointer is equal to destination string pointer");
  }
  if (0 >= n) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "string size %ld is smaller than or equal to zero error", n);
  }
#endif

  return dest;
}

cgraph_char_t *cgraph_strscpy(cgraph_char_t *dest, const cgraph_char_t *src,
                              const cgraph_size_t n) {
  cgraph_size_t size = n - 1;
  cgraph_char_t *pdest = dest, *psrc = (cgraph_char_t *)src;
  if (CGRAPH_ISNSTR2V(dest, src) || (0 >= size)) {
    goto CERROR;
  }
  for (; (0 < size) && ('\0' != *psrc); size--) {
    *(pdest++) = *(psrc++);
  }
  *pdest = '\0';

  return dest;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (NULL == dest) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "destination string pointer is empty");
  }
  if (0 >= n) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "buffer n %ld is smaller than or equal to zero error",
                          n);
  }
  if (CGRAPH_ISNSTR(src)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (dest == src) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "source string pointer is equal to destination string pointer");
  }
#endif

  return dest;
}

cgraph_char_t *cgraph_strcat(cgraph_char_t *dest, const cgraph_char_t *src) {
  if (CGRAPH_ISNSTR2V(dest, src)) {
    goto CERROR;
  }

  return strcat(dest, src);
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(dest)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "destination string is empty");
  }
  if (CGRAPH_ISNSTR(src)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (dest == src) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source pointer is equal to destination pointer");
  }
#endif

  return dest;
}

cgraph_char_t *cgraph_strncat(cgraph_char_t *dest, const cgraph_char_t *src,
                              const cgraph_size_t n) {
  if (CGRAPH_ISNSTR2V(dest, src) || (0 >= n)) {
    goto CERROR;
  }

  return strncat(dest, src, n);
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(dest)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "destination string is empty");
  }
  if (CGRAPH_ISNSTR(src)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (dest == src) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source pointer is equal to destination pointer");
  }
  if (0 >= n) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "string length %ld is smaller than or equal to zero error", n);
  }
#endif

  return dest;
}

cgraph_char_t *cgraph_strscat(cgraph_char_t *dest, const cgraph_char_t *src,
                              const cgraph_size_t n) {
  cgraph_size_t size = n - 1;
  cgraph_char_t *pdest = dest, *psrc = (cgraph_char_t *)src;
  if (CGRAPH_ISNSTR2V(dest, src) || (0 >= size)) {
    goto CERROR;
  }
  for (; (0 < size) && ('\0' != *pdest); size--, pdest++) {
  }
  for (; (0 < size) && ('\0' != *psrc); size--) {
    *(pdest++) = *(psrc++);
  }
  *pdest = '\0';

  return dest;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(dest)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "destination string is empty");
  }
  if (CGRAPH_ISNSTR(src)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (dest == src) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source pointer is equal to destination pointer");
  }
  if (0 >= n) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "string length %ld is smaller than or equal to zero error", n);
  }
#endif

  return dest;
}

cgraph_bool_t cgraph_strcmp(const cgraph_char_t *str1,
                            const cgraph_char_t *str2) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (str1 == str2) {
    flag = CGRAPH_TRUE;
  } else if ((NULL != str1) && (NULL != str2)) {
    if (('\0' == *str1) && ('\0' == *str2)) {
      flag = CGRAPH_TRUE;
    } else if (('\0' != *str1) && ('\0' != *str2)) {
      flag = CGRAPH_TEST(0 == strcmp(str1, str2));
    }
  }

  return flag;
}

cgraph_bool_t cgraph_strcasecmp(const cgraph_char_t *str1,
                                const cgraph_char_t *str2) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (str1 == str2) {
    flag = CGRAPH_TRUE;
  } else if ((NULL != str1) && (NULL != str2)) {
    if (('\0' == *str1) && ('\0' == *str2)) {
      flag = CGRAPH_TRUE;
    } else if (('\0' != *str1) && ('\0' != *str2)) {
      cgraph_char_t *pstr1 = (cgraph_char_t *)str1,
                    *pstr2 = (cgraph_char_t *)str2;
      flag = CGRAPH_TRUE;
    }
  }

  return flag;
}

cgraph_bool_t cgraph_strncmp(const cgraph_char_t *str1,
                             const cgraph_char_t *str2, const cgraph_size_t n) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (str1 == str2) {
    flag = CGRAPH_TRUE;
  } else if ((NULL != str1) && (NULL != str2)) {
    if (('\0' == *str1) && ('\0' == *str2)) {
      flag = CGRAPH_TRUE;
    } else if (('\0' != *str1) && ('\0' != *str2)) {
      flag = CGRAPH_TEST(0 == strncmp(str1, str2, n));
    }
  }

  return flag;
}

cgraph_bool_t cgraph_strncasecmp(const cgraph_char_t *str1,
                                 const cgraph_char_t *str2,
                                 const cgraph_size_t n) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if (str1 == str2) {
    flag = CGRAPH_TRUE;
  } else if ((NULL != str1) && (NULL != str2)) {
    if (('\0' == *str1) && ('\0' == *str2)) {
      flag = CGRAPH_TRUE;
    } else if (('\0' != *str1) && ('\0' != *str2)) {
      cgraph_char_t *pstr1 = (cgraph_char_t *)str1,
                    *pstr2 = (cgraph_char_t *)str2;
      flag = CGRAPH_TRUE;
    }
  }

  return flag;
}

cgraph_char_t *cgraph_strrev(cgraph_char_t *str) {
  cgraph_char_t *pstart = str, *pend = str;
  if (CGRAPH_ISNSTR(str)) {
    goto CERROR;
  }
  for (; '\0' != *pend; pend++) {
  }
  for (pend--; pstart < pend; pstart++, pend--) {
    cgraph_char_t data = *pstart;
    *pstart = *pend;
    *pend = data;
  }

  return str;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "source string is empty");
#endif

  return str;
}

cgraph_char_t *cgraph_strnrev(cgraph_char_t *str, const cgraph_size_t n) {
  cgraph_char_t *pstart = str, *pend = str + n;
  if (CGRAPH_ISNSTR(str) || (0 >= n)) {
    goto CERROR;
  }
  for (; pstart < pend; pstart++, pend--) {
    cgraph_char_t data = *pstart;
    *pstart = *pend;
    *pend = data;
  }

  return str;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "seperator string is empty");
  }
  if (0 >= n) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "string length %ld is smaller than or equal to zero error", n);
  }
#endif

  return str;
}

cgraph_char_t *cgraph_strtok(cgraph_char_t *str, const cgraph_char_t *sep) {
  if (CGRAPH_ISNSTR2V(str, sep)) {
    goto CERROR;
  }

  return strtok(str, sep);
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (CGRAPH_ISNSTR(sep)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "seperator string is empty");
  }
  if (str == sep) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is equal to seperator string");
  }
#endif

  return str;
}

cgraph_char_t *cgraph_strntok(cgraph_char_t *str, const cgraph_char_t *sep,
                              const cgraph_size_t n) {
  if (CGRAPH_ISNSTR2V(str, sep) || (0 >= n)) {
    goto CERROR;
  }

  return NULL;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (CGRAPH_ISNSTR(sep)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "seperator string is empty");
  }
  if (str == sep) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is equal to seperator string");
  }
#endif

  return str;
}

cgraph_char_t *cgraph_strstok(cgraph_char_t *str, const cgraph_char_t *sep,
                              cgraph_char_t **cbuf) {
  if (CGRAPH_ISNSTR2V(str, sep)) {
    goto CERROR;
  }

  return NULL;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (CGRAPH_ISNSTR(sep)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "seperator string is empty");
  }
  if (str == sep) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is equal to seperator string");
  }
#endif

  return str;
}

cgraph_char_t *cgraph_strchr(const cgraph_char_t *str, cgraph_int_t ch) {
  if (CGRAPH_ISNSTR(str)) {
    goto CERROR;
  }

  return strchr(str, ch);
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "source string is empty");
#endif

  return NULL;
}

cgraph_char_t *cgraph_strnchr(const cgraph_char_t *str, cgraph_int_t ch,
                              const cgraph_size_t n) {
  cgraph_char_t *ptmp = NULL, *pstr = (cgraph_char_t *)str;
  cgraph_size_t i = 0;
  if (CGRAPH_ISNSTR(str) || (0 >= n)) {
    goto CERROR;
  }
  for (; ('\0' != *pstr) && (n > i); i++, pstr++) {
    if (ch == *pstr) {
      ptmp = pstr;
      break;
    }
  }

  return ptmp;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (0 >= n) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "string length %ld is smaller than or equal to zero error", n);
  }
#endif

  return NULL;
}

cgraph_char_t *cgraph_strchrn(const cgraph_char_t *str, cgraph_int_t ch,
                              const cgraph_size_t n) {
  cgraph_char_t *ptmp = NULL, *pstr = (cgraph_char_t *)str;
  cgraph_size_t cnt = 0;
  if (CGRAPH_ISNSTR(str) || (0 >= n)) {
    goto CERROR;
  }
  for (; '\0' != *pstr; pstr++) {
    if (ch == *pstr) {
      cnt += 1;
      if (cnt >= n) {
        ptmp = pstr;
        break;
      }
    }
  }

  return ptmp;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (0 >= n) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "given character number %ld is smaller than or equal to zero error", n);
  }
#endif

  return NULL;
}

cgraph_char_t *cgraph_strrchr(const cgraph_char_t *str, cgraph_int_t ch) {
  if (CGRAPH_ISNSTR(str)) {
    goto CERROR;
  }

  return strrchr(str, ch);
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "source string is empty");
#endif

  return NULL;
}

cgraph_char_t *cgraph_strnrchr(const cgraph_char_t *str, cgraph_int_t ch,
                               const cgraph_size_t n) {
  cgraph_char_t *ptmp = NULL, *pstr = (cgraph_char_t *)str;
  cgraph_size_t i = 0;
  if (CGRAPH_ISNSTR(str) || (0 >= n)) {
    goto CERROR;
  }
  for (; ('\0' != *pstr) && (n > i); pstr++, i++) {
    if (ch == *pstr) {
      ptmp = pstr;
    }
  }

  return ptmp;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (0 >= n) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "string length %ld is smaller than or equal to zero error", n);
  }
#endif

  return NULL;
}

cgraph_char_t *cgraph_strrchrn(const cgraph_char_t *str, cgraph_int_t ch,
                               const cgraph_size_t n) {
  cgraph_char_t *ptmp = NULL, *pstr = (cgraph_char_t *)str;
  cgraph_size_t cnt = 0;
  if (CGRAPH_ISNSTR(str) || (0 >= n)) {
    goto CERROR;
  }
  for (; '\0' != *pstr; pstr++) {
    if (ch == *pstr) {
      ptmp = pstr;
      cnt += 1;
    }
  }
  if ((NULL == ptmp) || (n > cnt)) {
    goto CERROR;
  }
  for (pstr = ptmp, cnt = 0; str != pstr; pstr--) {
    if (ch == *pstr) {
      cnt += 1;
      if (cnt >= n) {
        ptmp = pstr;
        break;
      }
    }
  }

  return ptmp;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(str)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (0 >= n) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "the number of given character %c is %ld, smaller than "
        "or equal to zero error",
        ch, n);
  }
  if (NULL == ptmp) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "given character %c is not in input string", ch);
  }
  if (n > cnt) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "the number of given character %c is %ld, greater than real one %ld",
        ch, n, cnt);
  }
#endif

  return NULL;
}

cgraph_char_t *cgraph_strstr(const cgraph_char_t *src, cgraph_char_t *dest) {
  if (CGRAPH_ISNSTR2V(src, dest)) {
    goto CERROR;
  }

  return strstr(src, dest);
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(dest)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "destination string is empty");
  }
  if (CGRAPH_ISNSTR(src)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (dest == src) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is equal to destination string");
  }
#endif

  return NULL;
}

cgraph_char_t *cgraph_strnstr(const cgraph_char_t *src, cgraph_char_t *dest,
                              const cgraph_size_t n) {
  cgraph_char_t *ptmp = NULL;
  if (CGRAPH_ISNSTR2V(src, dest) || (0 >= n)) {
    goto CERROR;
  }

  return ptmp;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(dest)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "destination string is empty");
  }
  if (CGRAPH_ISNSTR(src)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (dest == src) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is equal to destination string");
  }
  if (0 >= n) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "string length %ld is smaller than or equal to zero error", n);
  }
#endif

  return NULL;
}

cgraph_char_t *cgraph_strstrn(const cgraph_char_t *src, cgraph_char_t *dest,
                              const cgraph_size_t n) {
  cgraph_char_t *ptmp = NULL;
  if (CGRAPH_ISNSTR2V(src, dest) || (0 >= n)) {
    goto CERROR;
  }

  return ptmp;
  /* errors output for debugging */
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNSTR(dest)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "destination string is empty");
  }
  if (CGRAPH_ISNSTR(src)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "source string is empty");
  }
  if (0 >= n) {
    cgraph_error_printfln(
        CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
        "given character number %ld is smaller than or equal to zero error", n);
  }
#endif

  return NULL;
}
