/**
 * SECTION: error
 * @short_description: error handle functions
 * @title: error
 */

#include <stdio.h>
#include <time.h>

#include "cgraph_error.h"
#include "cgraph_file.h"

static const cgraph_char_t *__cgraph_error_strings__[CGRAPH_ERROR_SIZE] = {
    "NO ERROR",
    "ERROR",
    "OUT OF MEMORY",
    "OUT OF INDEX",
    "INFINITE",
    "NOT A NUMBER(NaN)",
    "DIVISOR EQUAL TO ZERO",
    "MATH ERROR",
    "FILE HANDLE EMPTY",
    "FILE HANDLE ERROR",
    "OBJECT HANDLE EMPTY",
    "OBJECT HANDLE ERROR"};

const cgraph_char_t *cgraph_error_reason(const cgraph_error_t reason) {
  return (((0 <= reason) && (CGRAPH_ERROR_SIZE > reason))
              ? __cgraph_error_strings__[reason]
              : NULL);
}

cgraph_size_t cgraph_error_print(cgraph_error_t reason,
                                 const cgraph_size_t line, cgraph_char_t *file,
                                 const cgraph_char_t *function) {
  cgraph_size_t len = 0;
  const cgraph_char_t *reason_name = cgraph_error_reason(reason);
  const cgraph_char_t *level_name = cgraph_error_level(CGRAPH_LEVEL_ERROR);
  if (NULL == reason_name) {
    goto CERROR;
  }
  if (NULL != function) {
    len = cgraph_file_fprintfln(stdout, CGRAPH_ERROR_FUNCTION_STYLE "%s", file,
                                function, line, level_name, reason_name);
  } else {
    len = cgraph_file_fprintfln(stdout, CGRAPH_ERROR_STYLE "%s", file, line,
                                level_name, reason_name);
  }

  return len;
CERROR:
#ifdef DEBUG
  cgraph_file_fprintfln(stderr,
                        CGRAPH_ERROR_STYLE "Undefined error type %d happens",
                        file, line, reason);
#endif

  return 0;
}

cgraph_size_t cgraph_error_details_md(FILE *fp) {
  cgraph_size_t len = 0;
  if (CGRAPH_ISNFILE(fp)) {
    goto CERROR;
  }
  len = cgraph_file_fprintfln(fp, "| ERROR TYPE | ERROR DETAIL |"
                                  "| :-: | :-: |");
  CGRAPH_LOOP(i, 0, CGRAPH_ERROR_SIZE)
  len +=
      cgraph_file_fprintfln(fp, "| %d | %s |", i, __cgraph_error_strings__[i]);
  CGRAPH_LOOP_END

  return len;
CERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                        CGRAPH_LEVEL_ERROR, "file handle is error");
#endif

  return 0;
}

cgraph_size_t cgraph_error_details_csv(FILE *fp) {
  cgraph_size_t len = 0;
  if (CGRAPH_ISNFILE(fp)) {
    goto CERROR;
  }
  len = cgraph_file_fprintfln(fp, "ERROR TYPE,ERROR DETAIL");
  CGRAPH_LOOP(i, 0, CGRAPH_ERROR_SIZE)
  len += cgraph_file_fprintfln(fp, "%d,%s", i, __cgraph_error_strings__[i]);
  CGRAPH_LOOP_END

  return len;
CERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                        CGRAPH_LEVEL_ERROR, "file handle is error");
#endif

  return 0;
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
              : __cgraph_level_reasons__[CGRAPH_LEVEL_DEFAULT]);
}

static cgraph_char_t __cgraph_time_cbuf__[CGRAPH_TIME_CBUF_SIZE];

const cgraph_char_t *cgraph_error_time(void) {
  time_t local_time;
  time(&local_time);
  strftime(__cgraph_time_cbuf__, CGRAPH_TIME_CBUF_SIZE, CGRAPH_TIME_FMT,
           localtime(&local_time));
  return __cgraph_time_cbuf__;
}

static FILE *cgraph_error_ptr = NULL;

cgraph_bool_t cgraph_error_init(FILE *fp) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if (CGRAPH_ISFILE(fp)) {
    cgraph_error_ptr = fp;
    res = CGRAPH_TRUE;
  }

  return res;
}

cgraph_bool_t cgraph_error_init_by_file(const cgraph_char_t *file) {
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

cgraph_size_t cgraph_error_printfln(const cgraph_char_t *file,
                                    const cgraph_char_t *function,
                                    const cgraph_size_t line,
                                    const cgraph_level_t level,
                                    const cgraph_char_t *format, ...) {
  cgraph_size_t len = 0;
  FILE *fp = (NULL == cgraph_error_ptr ? stderr : cgraph_error_ptr);
  const cgraph_char_t *level_name = cgraph_error_level(level);
  if (CGRAPH_ISNFILE(fp) || (NULL == level_name)) {
    goto CERROR;
  }
  if (NULL != file) {
    if (NULL != function) {
      len = cgraph_file_fprintf(fp, CGRAPH_ERROR_TIME_FUNCTION_STYLE,
                                cgraph_error_time(), file, function, line,
                                level_name);
    } else {
      len = cgraph_file_fprintf(fp, CGRAPH_ERROR_TIME_STYLE,
                                cgraph_error_time(), file, line, level_name);
    }
  }
  if (NULL != format) {
    va_list args;
    va_start(args, format);
    cgraph_file_vsnprintf(__cgraph_log_cbuf__, CGRAPH_LOG_CBUF_SIZE, format,
                          args);
    va_end(args);
    len += cgraph_file_fprintfln(fp, "%s", __cgraph_log_cbuf__);
  }

  return len;
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNFILE(fp)) {
    cgraph_error_printfln(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "file handle is error");
  }
  if (NULL == format) {
    cgraph_error_printfln(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "style format is empty");
  }
#endif

  return 0;
}

cgraph_size_t cgraph_error_fprintfln(FILE *fp, const cgraph_char_t *file,
                                     const cgraph_char_t *function,
                                     const cgraph_size_t line,
                                     const cgraph_level_t level,
                                     const cgraph_char_t *format, ...) {
  cgraph_size_t len = 0;
  const cgraph_char_t *level_name = cgraph_error_level(level);
  if (CGRAPH_ISNFILE(fp) || (NULL == level_name)) {
    goto CERROR;
  }
  if (NULL != file) {
    if (NULL != function) {
      len = cgraph_file_fprintf(fp, CGRAPH_ERROR_TIME_FUNCTION_STYLE,
                                cgraph_error_time(), file, function, line,
                                level_name);
    } else {
      len = cgraph_file_fprintf(fp, CGRAPH_ERROR_TIME_STYLE,
                                cgraph_error_time(), file, line, level_name);
    }
  }
  if (NULL != format) {
    va_list args;
    va_start(args, format);
    cgraph_file_vsnprintf(__cgraph_log_cbuf__, CGRAPH_LOG_CBUF_SIZE, format,
                          args);
    va_end(args);
    len += cgraph_file_fprintfln(fp, "%s", __cgraph_log_cbuf__);
  }

  return len;
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNFILE(fp)) {
    cgraph_error_printfln(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "file handle is error");
  }
  if (NULL == format) {
    cgraph_error_printfln(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "style format is empty");
  }
#endif

  return 0;
}

cgraph_size_t cgraph_error_snprintfln(cgraph_char_t *cbuf, cgraph_size_t size,
                                      const cgraph_char_t *file,
                                      const cgraph_char_t *function,
                                      const cgraph_size_t line,
                                      const cgraph_level_t level,
                                      const cgraph_char_t *format, ...) {
  cgraph_size_t len = 0;
  FILE *fp = (NULL == cgraph_error_ptr ? stderr : cgraph_error_ptr);
  const cgraph_char_t *level_name = cgraph_error_level(level);
  if (CGRAPH_ISNFILE(fp) || CGRAPH_ISNBUF(cbuf, size) || (NULL == level_name)) {
    goto CERROR;
  }
  if (NULL != file) {
    if (NULL != function) {
      len = cgraph_file_snprintf(cbuf, size, CGRAPH_ERROR_TIME_FUNCTION_STYLE,
                                 cgraph_error_time(), file, function, line,
                                 level_name);
    } else {
      len = cgraph_file_snprintf(cbuf, size, CGRAPH_ERROR_TIME_STYLE,
                                 cgraph_error_time(), file, line, level_name);
    }
  }
  if (NULL != format) {
    va_list args;
    va_start(args, format);
    len += cgraph_file_vsnprintf(cbuf, size - len, format, args);
    va_end(args);
  }

  return len;
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNFILE(fp)) {
    cgraph_error_printfln(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "file handle is error");
  }
  if ((NULL == cbuf) || (0 >= size)) {
    cgraph_error_printfln(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "cbuf is empty");
  }
  if (NULL == format) {
    cgraph_error_printfln(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "style format is empty");
  }
#endif

  return 0;
}

cgraph_size_t cgraph_error_fsnprintfln(FILE *fp, cgraph_char_t *cbuf,
                                       cgraph_size_t size,
                                       const cgraph_char_t *file,
                                       const cgraph_char_t *function,
                                       const cgraph_size_t line,
                                       const cgraph_level_t level,
                                       const cgraph_char_t *format, ...) {
  cgraph_size_t len = 0;
  const cgraph_char_t *level_name = cgraph_error_level(level);
  if (CGRAPH_ISNFILE(fp) || CGRAPH_ISNBUF(cbuf, size) || (NULL == level_name)) {
    goto CERROR;
  }
  if (NULL != file) {
    if (NULL != function) {
      len = cgraph_file_snprintf(cbuf, size,
                                 CGRAPH_ERROR_TIME_FUNCTION_STYLE "%s",
                                 cgraph_error_time(), file, function, line,
                                 level_name, __cgraph_log_cbuf__);
    } else {
      len = cgraph_file_snprintf(cbuf, size, CGRAPH_ERROR_TIME_STYLE "%s",
                                 cgraph_error_time(), file, line, level_name,
                                 __cgraph_log_cbuf__);
    }
  }
  if (NULL != format) {
    va_list args;
    va_start(args, format);
    len += cgraph_file_vsnprintf(cbuf, size - len, format, args);
    va_end(args);
  }
  len = cgraph_file_fputs(cbuf, len, fp);

  return len;
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNFILE(fp)) {
    cgraph_error_printfln(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "file handle is error");
  }
  if ((NULL == cbuf) || (0 >= size)) {
    cgraph_error_printfln(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "cbuf is empty");
  }
  if (NULL == format) {
    cgraph_error_printfln(CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY,
                          CGRAPH_LEVEL_FATAL, "style format is empty");
  }
#endif

  return 0;
}
