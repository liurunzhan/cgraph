#include <time.h>

#include "cgraph_error.h"
#include "cgraph_file.h"

static cgraph_char_t *__cgraph_error_strings__[] = {"NO ERROR",
                                                    "ERROR",
                                                    "OUT OF MEMORY",
                                                    "OUT OF INDEX",
                                                    "INFINITE",
                                                    "NOT A NUMBER",
                                                    "DIVISOR EQUAL TO ZERO",
                                                    "MATH ERROR",
                                                    "FILE HANDLE EMPTY",
                                                    "FILE HANDLE ERROR",
                                                    NULL};

#define CGRAPH_ERROR_STRING(reason) (__cgraph_error_strings__[reason])

cgraph_size_t cgraph_error(cgraph_error_t reason, const cgraph_size_t line,
                           cgraph_char_t *file, const cgraph_char_t *function) {
  cgraph_size_t len = 0;
  if (reason < CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS) {
    if (NULL != function) {
      len = cgraph_file_fprintfln(
          stderr, CGRAPH_ERROR_FUNCTION_STYLE "TYPE %d -> %s", file, function,
          line, reason, CGRAPH_ERROR_STRING(reason));
    } else {
      len = cgraph_file_fprintfln(stderr, CGRAPH_ERROR_STYLE "TYPE %d -> %s",
                                  file, line, reason,
                                  CGRAPH_ERROR_STRING(reason));
    }
  }
#ifdef DEBUG
  if (reason >= CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS) {
    cgraph_file_fprintfln(stderr,
                          CGRAPH_ERROR_STYLE "Undefined error type %d happens",
                          file, line, reason);
  }
#endif

  return len;
}

cgraph_char_t *cgraph_error_reason(const cgraph_error_t reason) {
  return (reason < CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS
              ? CGRAPH_ERROR_STRING(reason)
              : CGRAPH_ERROR_STRING(CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS));
}

cgraph_size_t cgraph_error_details_md(FILE *fp) {
  cgraph_size_t len = 0;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_int_t i;
    len = cgraph_file_fprintfln(fp, "| ERROR TYPE | ERROR DETAIL |"
                                    "| :-: | :-: |");
    for (i = 0; i < CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS; i++) {
      len +=
          cgraph_file_fprintfln(fp, "| %d | %s |", i, CGRAPH_ERROR_STRING(i));
    }
  }
#ifdef DEBUG
  else {
    cgraph_file_fprintfln(stderr, CGRAPH_ERROR_STYLE "file handle is error!",
                          CGRAPH_ERROR_STYLE_ENTRY);
  }
#endif

  return len;
}

cgraph_size_t cgraph_error_details_csv(FILE *fp) {
  cgraph_size_t len = 0;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_int_t i;
    len = cgraph_file_fprintfln(fp, "ERROR TYPE,ERROR DETAIL");
    for (i = 0; i < CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS; i++) {
      len += cgraph_file_fprintfln(fp, "%d,%s", i, CGRAPH_ERROR_STRING(i));
    }
  }
#ifdef DEBUG
  else {
    cgraph_file_fprintfln(stderr, CGRAPH_ERROR_STYLE "file handle is error!",
                          CGRAPH_ERROR_STYLE_ENTRY);
  }
#endif

  return len;
}

static cgraph_char_t __cgraph_time_cbuf__[CGRAPH_TIME_CBUF_SIZE];

cgraph_char_t *cgraph_error_time(void) {
  time_t local_time;
  time(&local_time);
  strftime(__cgraph_time_cbuf__, CGRAPH_TIME_CBUF_SIZE, "%Y-%m-%d %H:%M:%S",
           localtime(&local_time));

  return __cgraph_time_cbuf__;
}

static cgraph_char_t __cgraph_log_cbuf__[CGRAPH_LOG_CBUF_SIZE];

cgraph_size_t cgraph_error_log(FILE *fp, const cgraph_char_t *file,
                               const cgraph_char_t *function,
                               const cgraph_size_t line,
                               const cgraph_char_t *format, ...) {
  cgraph_size_t len = 0;
  if (CGRAPH_ISFILE(fp) && (NULL != format)) {
    va_list args;
    va_start(args, format);
    cgraph_file_vsnprintf(__cgraph_log_cbuf__, CGRAPH_LOG_CBUF_SIZE, format,
                          args);
    va_end(args);
    cgraph_error_time();
    if (NULL != function) {
      len = cgraph_file_fprintfln(fp, CGRAPH_ERROR_TIME_FUNCTION_STYLE "%s",
                                  __cgraph_time_cbuf__, file, function, line,
                                  __cgraph_log_cbuf__);
    } else {
      len = cgraph_file_fprintfln(fp, CGRAPH_ERROR_TIME_STYLE "%s",
                                  __cgraph_time_cbuf__, file, line,
                                  __cgraph_log_cbuf__);
    }
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNFILE(fp)) {
      cgraph_file_fprintfln(stderr, CGRAPH_ERROR_STYLE "file handle is error!",
                            CGRAPH_ERROR_STYLE_ENTRY);
    }
    if (NULL == format) {
      cgraph_file_fprintfln(stderr, CGRAPH_ERROR_STYLE "style format is empty!",
                            CGRAPH_ERROR_STYLE_ENTRY);
    }
  }
#endif

  return len;
}

cgraph_size_t cgraph_error_log_cbuf(FILE *fp, cgraph_char_t *cbuf,
                                    cgraph_size_t size,
                                    const cgraph_char_t *file,
                                    const cgraph_char_t *function,
                                    const cgraph_size_t line,
                                    const cgraph_char_t *format, ...) {
  cgraph_size_t len = 0;
  if (CGRAPH_ISFILE(fp) && CGRAPH_ISBUF(cbuf, size) && (NULL != format)) {
    va_list args;
    va_start(args, format);
    cgraph_file_vsnprintf(cbuf, size, format, args);
    va_end(args);
    cgraph_error_time();
    len = cgraph_file_fprintfln(fp, "%s: %s", __cgraph_time_cbuf__, cbuf);
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNFILE(fp)) {
      cgraph_file_fprintfln(stderr, CGRAPH_ERROR_STYLE "file handle is error!",
                            CGRAPH_ERROR_STYLE_ENTRY);
    }
    if ((NULL == cbuf) || (0 >= size)) {
      cgraph_file_fprintfln(stderr, CGRAPH_ERROR_STYLE "cbuf is empty!",
                            CGRAPH_ERROR_STYLE_ENTRY);
    }
    if (NULL == format) {
      cgraph_file_fprintfln(stderr, CGRAPH_ERROR_STYLE "style format is empty!",
                            CGRAPH_ERROR_STYLE_ENTRY);
    }
  }
#endif

  return len;
}
