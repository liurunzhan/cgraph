#include <stdio.h>
#include <time.h>

#include "cgraph_error.h"
#include "cgraph_file.h"

static const cgraph_char_t *__cgraph_error_strings__[] = {
    "NO ERROR",
    "ERROR",
    "OUT OF MEMORY",
    "OUT OF INDEX",
    "INFINITE",
    "NOT A NUMBER",
    "DIVISOR EQUAL TO ZERO",
    "MATH ERROR",
    "FILE HANDLE EMPTY",
    "FILE HANDLE ERROR"};

const cgraph_char_t *cgraph_error_reason(const cgraph_error_t reason) {
  return (((CGRAPH_ERROR_SIZE > reason) && (0 <= reason))
              ? __cgraph_error_strings__[reason]
              : NULL);
}

cgraph_size_t cgraph_error(cgraph_error_t reason, const cgraph_size_t line,
                           cgraph_char_t *file, const cgraph_char_t *function) {
  cgraph_size_t len = 0;
  const cgraph_char_t *reason_name = cgraph_error_reason(reason);
  const cgraph_char_t *level_name = cgraph_error_level(CGRAPH_LEVEL_ERROR);
  if (NULL != reason_name) {
    if (NULL != function) {
      len =
          cgraph_file_fprintfln(stdout, CGRAPH_ERROR_FUNCTION_STYLE "%s", file,
                                function, line, level_name, reason_name);
    } else {
      len = cgraph_file_fprintfln(stdout, CGRAPH_ERROR_STYLE "%s", file, line,
                                  level_name, reason_name);
    }

  }
#ifdef DEBUG
  else {
    cgraph_file_fprintfln(stderr,
                          CGRAPH_ERROR_STYLE "Undefined error type %d happens",
                          file, line, reason);
  }
#endif

  return len;
}

cgraph_size_t cgraph_error_details_md(FILE *fp) {
  cgraph_size_t len = 0;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_int_t i;
    len = cgraph_file_fprintfln(fp, "| ERROR TYPE | ERROR DETAIL |"
                                    "| :-: | :-: |");
    for (i = 0; i < CGRAPH_ERROR_SIZE; i++) {
      len += cgraph_file_fprintfln(fp, "| %d | %s |", i,
                                   __cgraph_error_strings__[i]);
    }
  }
#ifdef DEBUG
  else {
    cgraph_error_printf(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                        CGRAPH_LEVEL_ERROR, "file handle is error");
  }
#endif

  return len;
}

cgraph_size_t cgraph_error_details_csv(FILE *fp) {
  cgraph_size_t len = 0;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_int_t i;
    len = cgraph_file_fprintfln(fp, "ERROR TYPE,ERROR DETAIL");
    for (i = 0; i < CGRAPH_ERROR_SIZE; i++) {
      len += cgraph_file_fprintfln(fp, "%d,%s", i, __cgraph_error_strings__[i]);
    }
  }
#ifdef DEBUG
  else {
    cgraph_error_printf(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                        CGRAPH_LEVEL_ERROR, "file handle is error");
  }
#endif

  return len;
}

/**
 *
 */

static const cgraph_char_t *__cgraph_level_reasons__[CGRAPH_LEVEL_SIZE] = {
    "DEBUG",  /** LEVEL 0 : DEBUG */
    "INFO",   /** LEVEL 1 : INFO */
    "NOTICE", /** LEVEL 2 : NOTICE */
    "WARN",   /** LEVEL 3 : WARN */
    "ERROR",  /** LEVEL 4 : ERROR */
    "FATAL"   /** LEVEL 5 : FATAL */
};

const cgraph_char_t *cgraph_error_level(const cgraph_level_t level) {
  return (((CGRAPH_LEVEL_SIZE > level) && (0 <= level))
              ? __cgraph_level_reasons__[level]
              : NULL);
}

static cgraph_char_t __cgraph_time_cbuf__[CGRAPH_TIME_CBUF_SIZE];

void cgraph_error_time(void) {
  time_t local_time;
  time(&local_time);
  strftime(__cgraph_time_cbuf__, CGRAPH_TIME_CBUF_SIZE, CGRAPH_TIME_FMT,
           localtime(&local_time));
}

static FILE *cgraph_error_ptr = NULL;

cgraph_bool_t cgraph_error_chptr(FILE *fp) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_error_ptr = fp;
    res = CGRAPH_TRUE;
  }

  return res;
}

cgraph_bool_t cgraph_error_chptr_by_file(const cgraph_char_t *file) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if (CGRAPH_ISSTR(file)) {
    FILE *fp = fopen(file, "w");
    if (NULL != fp) {
      cgraph_error_ptr = fp;
      res = CGRAPH_TRUE;
    } else {
      cgraph_error_ptr = stderr;
    }
  } else {
    cgraph_error_ptr = stderr;
  }

  return res;
}

static cgraph_char_t __cgraph_log_cbuf__[CGRAPH_LOG_CBUF_SIZE];

cgraph_size_t cgraph_error_printf(const cgraph_char_t *file,
                                  const cgraph_char_t *function,
                                  const cgraph_size_t line,
                                  const cgraph_level_t level,
                                  const cgraph_char_t *format, ...) {
  cgraph_size_t len = 0;
  FILE *fp = (NULL == cgraph_error_ptr ? stderr : cgraph_error_ptr);
  const cgraph_char_t *level_name = cgraph_error_level(level);
  if (CGRAPH_ISFILE(fp) && (NULL != format) && (NULL != level_name)) {
    va_list args;
    va_start(args, format);
    cgraph_file_vsnprintf(__cgraph_log_cbuf__, CGRAPH_LOG_CBUF_SIZE, format,
                          args);
    va_end(args);
    cgraph_error_time();
    if (NULL != function) {
      len = cgraph_file_fprintfln(fp, CGRAPH_ERROR_TIME_FUNCTION_STYLE "%s",
                                  __cgraph_time_cbuf__, file, function, line,
                                  level_name, __cgraph_log_cbuf__);
    } else {
      len = cgraph_file_fprintfln(fp, CGRAPH_ERROR_TIME_STYLE "%s",
                                  __cgraph_time_cbuf__, file, line, level_name,
                                  __cgraph_log_cbuf__);
    }
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNFILE(fp)) {
      cgraph_error_printf(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "file handle is error");
    }
    if (NULL == format) {
      cgraph_error_printf(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "style format is empty");
    }
  }
#endif

  return len;
}

cgraph_size_t cgraph_error_fprintf(FILE *fp, const cgraph_char_t *file,
                                   const cgraph_char_t *function,
                                   const cgraph_size_t line,
                                   const cgraph_level_t level,
                                   const cgraph_char_t *format, ...) {
  cgraph_size_t len = 0;
  const cgraph_char_t *level_name = cgraph_error_level(level);
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
                                  level_name, __cgraph_log_cbuf__);
    } else {
      len = cgraph_file_fprintfln(fp, CGRAPH_ERROR_TIME_STYLE "%s",
                                  __cgraph_time_cbuf__, file, line, level_name,
                                  __cgraph_log_cbuf__);
    }
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNFILE(fp)) {
      cgraph_error_printf(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "file handle is error");
    }
    if (NULL == format) {
      cgraph_error_printf(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "style format is empty");
    }
  }
#endif

  return len;
}

cgraph_size_t cgraph_error_snprintf(cgraph_char_t *cbuf, cgraph_size_t size,
                                    const cgraph_char_t *file,
                                    const cgraph_char_t *function,
                                    const cgraph_size_t line,
                                    const cgraph_level_t level,
                                    const cgraph_char_t *format, ...) {
  cgraph_size_t len = 0;
  FILE *fp = (NULL == cgraph_error_ptr ? stderr : cgraph_error_ptr);
  const cgraph_char_t *level_name = cgraph_error_level(level);
  if (CGRAPH_ISFILE(fp) && CGRAPH_ISBUF(cbuf, size) && (NULL != format)) {
    va_list args;
    va_start(args, format);
    cgraph_file_vsnprintf(__cgraph_log_cbuf__, CGRAPH_LOG_CBUF_SIZE, format,
                          args);
    va_end(args);
    cgraph_error_time();
    if (NULL != function) {
      len = cgraph_file_snprintf(cbuf, size,
                                 CGRAPH_ERROR_TIME_FUNCTION_STYLE "%s",
                                 __cgraph_time_cbuf__, file, function, line,
                                 level_name, __cgraph_log_cbuf__);
    } else {
      len = cgraph_file_snprintf(cbuf, size, CGRAPH_ERROR_TIME_STYLE "%s",
                                 __cgraph_time_cbuf__, file, line, level_name,
                                 __cgraph_log_cbuf__);
    }
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNFILE(fp)) {
      cgraph_error_printf(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "file handle is error");
    }
    if ((NULL == cbuf) || (0 >= size)) {
      cgraph_error_printf(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "cbuf is empty");
    }
    if (NULL == format) {
      cgraph_error_printf(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "style format is empty");
    }
  }
#endif

  return len;
}

cgraph_size_t
cgraph_error_fsnprintf(FILE *fp, cgraph_char_t *cbuf, cgraph_size_t size,
                       const cgraph_char_t *file, const cgraph_char_t *function,
                       const cgraph_size_t line, const cgraph_level_t level,
                       const cgraph_char_t *format, ...) {
  cgraph_size_t len = 0;
  const cgraph_char_t *level_name = cgraph_error_level(level);
  if (CGRAPH_ISFILE(fp) && CGRAPH_ISBUF(cbuf, size) && (NULL != format)) {
    va_list args;
    va_start(args, format);
    cgraph_file_vsnprintf(__cgraph_log_cbuf__, CGRAPH_LOG_CBUF_SIZE, format,
                          args);
    va_end(args);
    cgraph_error_time();
    if (NULL != function) {
      len = cgraph_file_snprintf(cbuf, size,
                                 CGRAPH_ERROR_TIME_FUNCTION_STYLE "%s",
                                 __cgraph_time_cbuf__, file, function, line,
                                 level_name, __cgraph_log_cbuf__);
    } else {
      len = cgraph_file_snprintf(cbuf, size, CGRAPH_ERROR_TIME_STYLE "%s",
                                 __cgraph_time_cbuf__, file, line, level_name,
                                 __cgraph_log_cbuf__);
    }
    cgraph_file_fputs(cbuf, len, fp);
  }
#ifdef DEBUG
  else {
    if (CGRAPH_ISNFILE(fp)) {
      cgraph_error_printf(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "file handle is error");
    }
    if ((NULL == cbuf) || (0 >= size)) {
      cgraph_error_printf(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "cbuf is empty");
    }
    if (NULL == format) {
      cgraph_error_printf(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "style format is empty");
    }
  }
#endif

  return len;
}