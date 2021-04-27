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

void cgraph_error(cgraph_error_t reason, const cgraph_size_t line,
                  cgraph_char_t *file, const cgraph_char_t *function) {
  if (reason < CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS) {
    if (NULL != function) {
      cgraph_file_fprintfln(stderr,
                            "%s happens in FUNCTION %s Line %ld of File %s",
                            CGRAPH_ERROR_STRING(reason), function, line, file);
    } else {
      cgraph_file_fprintfln(stderr, "%s happens in Line %ld of File %s",
                            CGRAPH_ERROR_STRING(reason), line, file);
    }
  }
#ifdef DEBUG
  if (reason >= CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS) {
    cgraph_file_fprintfln(stderr,
                          "Undefined error %d happens in Line %ld of File %s",
                          reason, line, file);
  }
#endif
}

cgraph_char_t *cgraph_error_reason(const cgraph_error_t reason) {
  return (reason < CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS
              ? CGRAPH_ERROR_STRING(reason)
              : CGRAPH_ERROR_STRING(CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS));
}

void cgraph_error_details_md(FILE *fp) {
  if ((NULL != fp) && (0 == ferror(fp))) {
    cgraph_int_t i;
    cgraph_file_fprintfln(fp, "| ERROR TYPE | ERROR DETAIL |"
                              "| :-: | :-: |");
    for (i = 0; i < CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS; i++) {
      cgraph_file_fprintfln(fp, "| %d | %s |", i, CGRAPH_ERROR_STRING(i));
    }
  }
#ifdef DEBUG
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_file_fprintfln(stderr, "FILE %s of LINE %d : file handle is error!",
                          __FILE__, __LINE__);
  }
#endif
}

void cgraph_error_details_csv(FILE *fp) {
  if ((NULL != fp) && (0 == ferror(fp))) {
    cgraph_int_t i;
    cgraph_file_fprintfln(fp, "ERROR TYPE,ERROR DETAIL");
    for (i = 0; i < CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS; i++) {
      cgraph_file_fprintfln(fp, "%d,%s", i, CGRAPH_ERROR_STRING(i));
    }
  }
#ifdef DEBUG
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_file_fprintfln(stderr, "FILE %s of LINE %d : file handle is error!",
                          __FILE__, __LINE__);
  }
#endif
}

static cgraph_char_t __cgraph_time_buffer__[CGRAPH_TIME_BUFFER_SIZE];

cgraph_char_t *cgraph_error_time(void) {
  time_t local_time;
  time(&local_time);
  strftime(__cgraph_time_buffer__, CGRAPH_TIME_BUFFER_SIZE, "%Y-%m-%d %X",
           localtime(&local_time));

  return __cgraph_time_buffer__;
}

static cgraph_char_t __cgraph_log_buffer__[CGRAPH_LOG_BUFFER_SIZE];

void cgraph_error_log(FILE *fp, const cgraph_char_t *file,
                      const cgraph_size_t line, const cgraph_char_t *function,
                      const cgraph_char_t *format, ...) {
  if ((NULL != fp) && (0 == ferror(fp)) && (NULL != format)) {
    va_list args;
    va_start(args, format);
    cgraph_file_vsnprintf(__cgraph_log_buffer__, CGRAPH_LOG_BUFFER_SIZE, format,
                          args);
    va_end(args);
    cgraph_error_time();
    if (NULL != function) {
      cgraph_file_fprintfln(
          fp, "FUNCTION %s LINE %ld of FILE %s at TIME %s : %s", function, line,
          file, __cgraph_time_buffer__, __cgraph_log_buffer__);
    } else {
      cgraph_file_fprintfln(fp, "LINE %ld of FILE %s at TIME %s : %s", line,
                            file, __cgraph_time_buffer__,
                            __cgraph_log_buffer__);
    }
  }
#ifdef DEBUG
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_file_fprintfln(stderr, "FILE %s of LINE %d : file handle is error!",
                          __FILE__, __LINE__);
  }
  if (NULL == format) {
    cgraph_file_fprintfln(stderr, "FILE %s of LINE %d : style format is empty!",
                          __FILE__, __LINE__);
  }
#endif
}

void cgraph_error_log_buffer(FILE *fp, cgraph_char_t *buffer,
                             cgraph_size_t size, const cgraph_char_t *file,
                             const cgraph_size_t line,
                             const cgraph_char_t *function,
                             const cgraph_char_t *format, ...) {
  if ((NULL != fp) && (0 == ferror(fp)) && (NULL != buffer) && (0 < size) &&
      (NULL != format)) {
    va_list args;
    va_start(args, format);
    cgraph_file_vsnprintf(buffer, size, format, args);
    va_end(args);
    cgraph_error_time();
    cgraph_file_fprintfln(fp, "%s: %s", __cgraph_time_buffer__, buffer);
  }
#ifdef DEBUG
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_file_fprintfln(stderr, "FILE %s of LINE %d : file handle is error!",
                          __FILE__, __LINE__);
  }
  if ((NULL == buffer) || (0 >= size)) {
    cgraph_file_fprintfln(stderr, "FILE %s of LINE %d : buffer is empty!",
                          __FILE__, __LINE__);
  }
  if (NULL == format) {
    cgraph_file_fprintfln(stderr, "FILE %s of LINE %d : style format is empty!",
                          __FILE__, __LINE__);
  }
#endif
}
