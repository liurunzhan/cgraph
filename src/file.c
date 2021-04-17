#include <stdlib.h>
#include <string.h>

#include "cgraph_error.h"
#include "cgraph_file.h"

#ifdef __NO_VSNPRINTF
#undef __NO_VSNPRINTF
#endif

#if defined(fprintf)
#undef fprintf
#endif

#if defined(vfprintf)
#undef vfprintf
#endif

#if defined(vsprintf)
#undef vsprintf
#endif

#if defined(vsnprintf)
#undef vsnprintf
#endif

/** vsnprintf function or macro function */
#if CGRAPH_STDC_VERSION >= 199901L
#define fprintf fprintf
#define vfprintf vfprintf
#define vsprintf vsprintf
#define vsnprintf vsnprintf
#else
#define __NO_VSNPRINTF
#if defined(__GNUC__) || defined(__clang__)
#define fprintf __extension__ fprintf
#define vfprintf __extension__ vfprintf
#define vsprintf __extension__ vsprintf
#define vsnprintf __extension__ vsprintf
#elif defined(_MSC_VER)
#define fprintf fprintf
#define vfprintf vfprintf
#define vsprintf _vsprintf
#define vsnprintf _vsprintf
#else
#define fprintf fprintf
#define vfprintf vfprintf
#define vsprintf vsprintf
#define vsnprintf vsprintf
#endif
#endif

/** output functions */
cgraph_int_t cgraph_file_putc(FILE *fp, const cgraph_char_t *buffer,
                              const cgraph_size_t size) {
  if ((NULL != buffer) && (0 < size)) {
    cgraph_size_t i;
    cgraph_char_t *data = (cgraph_char_t *)buffer;
    for (i = 0; i < size; i++, data++) {
      fputc(*data, fp);
    }
  }
  return size;
}

cgraph_int_t cgraph_file_rputc(FILE *fp, const cgraph_char_t *buffer,
                               const cgraph_size_t size) {
  if ((NULL != buffer) && (0 < size)) {
    cgraph_size_t i;
    cgraph_char_t *data = (cgraph_char_t *)&buffer[size - 1];
    for (i = 0; i < size; i++, data--) {
      fputc(*data, fp);
    }
  }
  return size;
}

cgraph_int_t cgraph_file_fprintf(FILE *fp, const cgraph_char_t *format, ...) {
  cgraph_int_t _size = 0;
  va_list args;
  va_start(args, format);
  _size = vfprintf(fp, format, args);
  va_end(args);

  return _size;
}

cgraph_int_t cgraph_file_printf(const cgraph_char_t *format, ...) {
  cgraph_int_t _size = 0;
  va_list args;
  va_start(args, format);
  _size = vfprintf(stdout, format, args);
  va_end(args);

  return _size;
}

cgraph_int_t cgraph_file_fprintln(FILE *fp, const cgraph_char_t *format, ...) {
  cgraph_int_t _size = 0;
  va_list args;
  va_start(args, format);
  _size = vfprintf(fp, format, args);
  va_end(args);
  if (_size > 0) {
    _size += fprintf(fp, "%s", CGRAPH_PLAT_NLINE);
  }

  return _size;
}

cgraph_int_t cgraph_file_println(const cgraph_char_t *format, ...) {
  cgraph_int_t _size = 0;
  va_list args;
  va_start(args, format);
  _size = vfprintf(stdout, format, args);
  va_end(args);
  if (_size > 0) {
    _size += fprintf(stdout, "%s", CGRAPH_PLAT_NLINE);
  }

  return _size;
}

cgraph_int_t cgraph_file_snprintf(cgraph_char_t *buffer,
                                  const cgraph_size_t size,
                                  const cgraph_char_t *format, ...) {
  cgraph_int_t _size = 0;
  if ((NULL != buffer) && (0 < size)) {
    va_list args;
    va_start(args, format);
    _size = vsnprintf(buffer,
#ifndef __NO_VSNPRINTF
                      size,
#endif
                      format, args);
    va_end(args);
  }

  return _size;
}

FILE *cgraph_file_fopen(cgraph_char_t *file, cgraph_char_t *mode) {
  FILE *fp = fopen(file, mode);
  if (NULL == fp) {
#ifdef DEBUG
    fflush(stdout);
    cgraph_error_log(stderr, __FILE__, __LINE__, __CGRAPH_FUNCTION,
                     "%s in style %s is opened error", file, mode);
    fflush(stderr);
#endif
    abort();
  }

  return fp;
}

cgraph_bool_t cgraph_file_fclose(FILE *fp) {
  if ((NULL == fp) || (0 != ferror(fp))) {
#ifdef DEBUG
    fflush(stdout);
    cgraph_error_log(stderr, __FILE__, __LINE__, __CGRAPH_FUNCTION,
                     "file handle is error before closed");
    fflush(stderr);
#endif
    clearerr(fp);
    abort();
  }

  return CGRAPH_TEST(0 == fclose(fp));
}

cgraph_size_t cgraph_file_fgetc(FILE *fp, cgraph_char_t *buffer,
                                const cgraph_size_t size) {
  cgraph_size_t len = 0, _size = size - 1;
  if (NULL != buffer) {
    cgraph_char_t *data = buffer;
    for (; (len < _size) && 0 != feof(fp); len++, data++) {
      *data = fgetc(fp);
    }
    *data = '\0';
  }

  return len;
}

cgraph_size_t cgraph_file_fgets(FILE *fp, cgraph_char_t *buffer,
                                const cgraph_size_t size) {
  cgraph_size_t len = 0, _size = size;
  if (NULL != buffer) {
    cgraph_char_t *data = buffer, ch;
    for (_size -= 1; (len < _size) && 0 != feof(fp); len++, data++) {
#if CGRAPH_PLAT_FEND < CGRAPH_PLAT_FEND_WIN
      if (CGRAPH_PLAT_NLINE_C == (ch = fgetc(fp))) {
        break;
      }
#else
      if ('\r' == (ch = fgetc(fp))) {
        if ('\n' == (ch = fgetc(fp))) {
          break;
        }
        *data++ = '\r';
      }
#endif
      *data = ch;
    }
    *data = '\0';
  }
#ifdef DEBUG
  fflush(stdout);
  if ((NULL == fp) || (0 != ferror(fp))) {

    cgraph_error_log(stderr, __FILE__, __LINE__, __CGRAPH_FUNCTION,
                     "file handle is error");
  }
  if (NULL == buffer) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __CGRAPH_FUNCTION,
                     "file buffer is empty");
  }
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __CGRAPH_FUNCTION,
                     "file handle is error");
  }
  fflush(stderr);
#endif

  return len;
}

cgraph_size_t cgraph_file_header(FILE *fp, cgraph_char_t *buffer,
                                 const cgraph_size_t size) {
  cgraph_size_t len = 0;
  if ((NULL != fp) && (0 == ferror(fp))) {
    fpos_t fp_init;
    fgetpos(fp, &fp_init);
    rewind(fp);
    len = cgraph_file_fgets(fp, buffer, size);
    fsetpos(fp, &fp_init);
  }
#ifdef DEBUG
  fflush(stdout);
  if (NULL != buffer) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __CGRAPH_FUNCTION,
                     "file buffer is empty");
  }
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __CGRAPH_FUNCTION,
                     "file handle is error");
  }
  fflush(stderr);
#endif

  return len;
}

cgraph_size_t cgraph_file_rows(FILE *fp) {
  cgraph_size_t rows = 0;
  if ((NULL != fp) && (0 == ferror(fp))) {
    char ch;
    fpos_t fp_init;
    fgetpos(fp, &fp_init);
    while (0 != feof(fp)) {
#if CGRAPH_PLAT_FEND < CGRAPH_PLAT_FEND_WIN
      if (CGRAPH_PLAT_NLINE_C == (ch = fgetc(fp))) {
#else
      if (('\r' == (ch = fgetc(fp))) && ('\n' == (ch = fgetc(fp)))) {
#endif
        rows += 1;
      }
    }
    fsetpos(fp, &fp_init);
  }

  return rows;
}

cgraph_size_t cgraph_file_columns(FILE *fp, cgraph_char_t *sep,
                                  cgraph_char_t *buffer,
                                  const cgraph_size_t size) {
  cgraph_size_t columns = 0;
  if ((NULL != fp) && (0 == ferror(fp))) {
    char *str = NULL;
    cgraph_file_header(fp, buffer, size);
    str = strtok(buffer, sep);
    while (NULL != str) {
      columns += 1;
      str = strtok(NULL, sep);
    }
  }

  return columns;
}

cgraph_size_t cgraph_file_line(FILE *fp, cgraph_char_t *buffer,
                               const cgraph_size_t size,
                               const cgraph_size_t line) {
  cgraph_size_t len = 0;
  if ((NULL != fp) && (0 == ferror(fp))) {
    cgraph_size_t i = 0;
    for (; i < line; i++) {
      len = cgraph_file_fgets(fp, buffer, size);
      if (len <= 0) {
        break;
      }
    }
  }
#ifdef DEBUG
  fflush(stdout);
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __CGRAPH_FUNCTION,
                     "file handle is error");
  }
  if (NULL == buffer) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __CGRAPH_FUNCTION,
                     "file buffer is empty");
  }
  if (line < 0) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __CGRAPH_FUNCTION,
                     "line number %ld is a negative number", line);
  }
  fflush(stderr);
#endif

  return len;
}

static const cgraph_char_t *_platform = CGRAPH_PLAT_NAME;
static const cgraph_char_t *_path_split = CGRAPH_PLAT_PSPLIT;
static const cgraph_char_t *_new_line = CGRAPH_PLAT_NLINE;

const static union cgraph_endian_t {
  cgraph_int32_t num;
  cgraph_int8_t byte[4];
} cgraph_file_endian = {1};

void cgraph_file_os(cgraph_char_t **os, cgraph_char_t **sep,
                    cgraph_char_t **end, cgraph_bool_t *isbigendian) {
  *os = (cgraph_char_t *)_platform;
  *sep = (cgraph_char_t *)_path_split;
  *end = (cgraph_char_t *)_new_line;
  if (NULL != isbigendian) {
    *isbigendian = (cgraph_file_endian.byte[3] ? CGRAPH_FALSE : CGRAPH_TRUE);
  }
}

#ifdef __NO_VSNPRINTF
#undef __NO_VSNPRINTF
#endif

#if defined(fprintf)
#undef fprintf
#endif

#if defined(vfprintf)
#undef vfprintf
#endif

#if defined(vsprintf)
#undef vsprintf
#endif

#if defined(vsnprintf)
#undef vsnprintf
#endif
