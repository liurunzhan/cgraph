#include <stdlib.h>
#include <string.h>

#include "cgraph_error.h"
#include "cgraph_file.h"

#if __PLAT_NLINE_TYPE == __PLAT_NLINE_UNIX
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#define access access
#else
#include <io.h>
#include <windows.h>
#define access _access
#endif

#ifndef F_OK
#define F_OK 0
#endif

__INLINE cgraph_bool_t cgraph_file_ispath(const cgraph_char_t *path) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if (NULL != path) {
    res = CGRAPH_TEST(0 == access(path, F_OK));
  }

  return res;
}

__INLINE cgraph_bool_t cgraph_file_isfile(const cgraph_char_t *path) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if (NULL != path) {
  }

  return res;
}

__INLINE cgraph_bool_t cgraph_file_isrfile(const cgraph_char_t *path) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if (NULL != path) {
    FILE *fp = fopen(path, "r");
    if (NULL != fp) {
      res = CGRAPH_TRUE;
      fclose(fp);
    }
  }

  return res;
}

__INLINE cgraph_bool_t cgraph_file_isdir(const cgraph_char_t *path) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if (NULL != path) {
  }

  return res;
}

cgraph_char_t *cgraph_file_joinpath(cgraph_char_t *buffer,
                                    const cgraph_size_t size,
                                    const cgraph_char_t *path) {
  if ((NULL != buffer) && (0 < size)) {
    strcat(buffer, __PLAT_NLINE);
    strcat(buffer, path);
  }

  return buffer;
}

cgraph_char_t **cgraph_file_walk(const cgraph_char_t *path) {
  cgraph_char_t **ext = NULL;
#if __PLAT_NLINE_TYPE == __PLAT_NLINE_UNIX
  DIR *dptr;
  struct dirent *eptr;
  if (NULL == (dptr = opendir(path))) {
    fprintf(stderr, "read directory %s error!\n", path);
    exit(-1);
  }
  while (NULL != (eptr = readdir(dptr))) {
    char *file = eptr->d_name;
  }
  closedir(dptr);

#else
  if (strcmp(path, "/") == 0 || strcmp(path, "\\") == 0) {
    DWORD dwSize = MAX_PATH;
    char szLogicalDrives[MAX_PATH] = {0};
    DWORD dwResult = GetLogicalDriveStringsA(dwSize, szLogicalDrives);
    if (dwResult > 0 && dwResult <= MAX_PATH) {
      char *szSingleDrive = szLogicalDrives;
      while (*szSingleDrive) {
        szSingleDrive += strlen(szSingleDrive) + 1;
      }
    }
  }
#endif

  return ext;
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

/** vsnprintf function or macro function */
#if __STDC_VERSION__ >= 199901L
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
#undef __NO_VSNPRINTF
#define fprintf fprintf
#define vfprintf vfprintf
#define vsprintf _vsprintf
#define vsnprintf _vsnprintf
#else
#define fprintf fprintf
#define vfprintf vfprintf
#define vsprintf vsprintf
#define vsnprintf vsprintf
#endif
#endif

/** output functions */
cgraph_size_t cgraph_file_fputs(FILE *fp, const cgraph_char_t *buffer,
                                const cgraph_size_t size) {
  cgraph_size_t _size = 0;
  if (NULL != buffer) {
    if (0 < size) {
      _size = fwrite(buffer, size, 1, fp);
    } else {
      _size = fputs(buffer, fp);
    }
  }
#ifdef DEBUG
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file handle is error");
  }
#endif

  return _size;
}

cgraph_size_t cgraph_file_rfputs(FILE *fp, const cgraph_char_t *buffer,
                                 const cgraph_size_t size) {
  cgraph_size_t _size = 0;
  if ((NULL != buffer) && (0 < size)) {
    cgraph_size_t i;
    cgraph_char_t *data = (cgraph_char_t *)&buffer[size - 1];
    for (i = 0, _size = size; i < size; i++, data--) {
      fputc(*data, fp);
    }
  }
#ifdef DEBUG
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file handle is error");
  }
#endif

  return _size;
}

__INLINE cgraph_size_t cgraph_file_sprintnl(cgraph_char_t *buffer,
                                            const cgraph_size_t size,
                                            const cgraph_size_t pos) {
  if ((NULL != buffer) && ((pos + __PLAT_NLINE_SIZE) < size)) {
    buffer += pos;
#if __PLAT_NLINE_TYPE == __PLAT_NLINE_WIN
    *(buffer++) = __PLAT_NLINE_C0;
    *(buffer++) = __PLAT_NLINE_C1;
#else
    *(buffer++) = __PLAT_NLINE_C;
#endif
  }

  return __PLAT_NLINE_SIZE;
}

__INLINE cgraph_size_t cgraph_file_fprintln(FILE *fp) {
  return fputs(__PLAT_NLINE, fp);
}

cgraph_size_t cgraph_file_printnl(void) { return cgraph_file_fprintln(stdout); }

cgraph_size_t cgraph_file_vfprintf(FILE *fp, const cgraph_char_t *format,
                                   va_list args) {
  return vfprintf(fp, format, args);
}

cgraph_size_t cgraph_file_fprintf(FILE *fp, const cgraph_char_t *format, ...) {
  cgraph_size_t _size = 0;
  va_list args;
  va_start(args, format);
  _size = vfprintf(fp, format, args);
  va_end(args);
#ifdef DEBUG
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file handle is error");
  }
#endif

  return _size;
}

cgraph_size_t cgraph_file_printf(const cgraph_char_t *format, ...) {
  cgraph_size_t _size = 0;
  va_list args;
  va_start(args, format);
  _size = vfprintf(stdout, format, args);
  va_end(args);

  return _size;
}

cgraph_size_t cgraph_file_fprintfln(FILE *fp, const cgraph_char_t *format,
                                    ...) {
  cgraph_size_t _size = 0;
  va_list args;
  va_start(args, format);
  _size = vfprintf(fp, format, args);
  va_end(args);
  if (_size > 0) {
    _size += cgraph_file_fprintln(fp);
  }
#ifdef DEBUG
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file handle is error");
  }
#endif

  return _size;
}

cgraph_size_t cgraph_file_printfln(const cgraph_char_t *format, ...) {
  cgraph_size_t _size = 0;
  va_list args;
  va_start(args, format);
  _size = vfprintf(stdout, format, args);
  va_end(args);
  if (_size > 0) {
    _size += cgraph_file_fprintln(stdout);
  }

  return _size;
}

cgraph_size_t cgraph_file_vsnprintf(cgraph_char_t *buffer,
                                    const cgraph_size_t size,
                                    const cgraph_char_t *format, va_list args) {
#if defined(DEBUG) && defined(__NO_VSNPRINTF)
  if (BUFSIZ < size) {
    fprintf(stderr,
            "buffer size %ld is bigger than default size %d for vsnprintf "
            "undefined!\n",
            size, BUFSIZ);
  }
#endif
  return vsnprintf(buffer,
#ifndef __NO_VSNPRINTF
                   size,
#endif
                   format, args);
}

cgraph_size_t cgraph_file_snprintf(cgraph_char_t *buffer,
                                   const cgraph_size_t size,
                                   const cgraph_char_t *format, ...) {
  cgraph_size_t _size = 0;
  if ((NULL != buffer) && (0 < size)) {
    va_list args;
    va_start(args, format);
    _size = cgraph_file_vsnprintf(buffer, size, format, args);
    va_end(args);
  }
#ifdef DEBUG
  if ((NULL == buffer) || (0 >= size)) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file buffer is empty");
  }
  if (0 >= size) {
  }
#endif

  return _size;
}

FILE *cgraph_file_fopen(cgraph_char_t *file, cgraph_char_t *mode) {
  FILE *fp = fopen(file, mode);
  if (NULL == fp) {
#ifdef DEBUG
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "%s in style %s is opened error", file, mode);
#endif
    abort();
  }

  return fp;
}

cgraph_bool_t cgraph_file_fclose(FILE *fp) {
  if ((NULL == fp) || (0 != ferror(fp))) {
#ifdef DEBUG
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file handle is error before closed");
#endif
    clearerr(fp);
    abort();
  }

  return CGRAPH_TEST(0 == fclose(fp));
}

cgraph_size_t cgraph_file_fgets(FILE *fp, cgraph_char_t *buffer,
                                const cgraph_size_t size) {
  cgraph_size_t len = 0, _size = size - 1;
  if ((NULL != buffer) && (0 < _size)) {
    cgraph_char_t ch;
    for (; (len < _size) && 0 != feof(fp); len++, buffer++) {
#if __PLAT_NLINE_TYPE == __PLAT_NLINE_WIN
      if (__PLAT_NLINE_C0 == (ch = fgetc(fp))) {
        if (__PLAT_NLINE_C1 == (ch = fgetc(fp))) {
          break;
        }
        *buffer = __PLAT_NLINE_C0;
        continue;
      }
#else
      if (__PLAT_NLINE_C == (ch = fgetc(fp))) {
        break;
      }
#endif
      *buffer = ch;
    }
    *buffer = '\0';
  }
#ifdef DEBUG
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file handle is error");
  }
  if ((NULL == buffer) || (0 >= size)) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file buffer is empty");
  }
#endif

  return len;
}

cgraph_size_t cgraph_file_whole(FILE *fp, cgraph_char_t *buffer,
                                const cgraph_size_t size) {
  cgraph_size_t len = 0;
  if ((NULL != buffer) && ((len = cgraph_file_size(fp)) < size)) {
    len = fread(buffer, len, 1, fp);
    *(buffer + len) = '\0';
  } else {
    len = 0;
  }
#ifdef DEBUG
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file handle is error");
  }
  if ((NULL == buffer) || (0 >= size)) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file buffer is empty");
  }
#endif

  return len;
}

cgraph_size_t cgraph_file_header(FILE *fp, cgraph_char_t *buffer,
                                 const cgraph_size_t size) {
  cgraph_size_t len = 0;
  if ((NULL != buffer) && (0 < size)) {
    fpos_t fp_init;
    fgetpos(fp, &fp_init);
    rewind(fp);
    len = cgraph_file_fgets(fp, buffer, size);
    fsetpos(fp, &fp_init);
  }
#ifdef DEBUG
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file handle is error");
  }
  if ((NULL == buffer) || (0 >= size)) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file buffer is empty");
  }
#endif

  return len;
}

cgraph_size_t cgraph_file_row(FILE *fp, cgraph_char_t *buffer,
                              const cgraph_size_t size,
                              const cgraph_size_t row) {
  cgraph_size_t len = 0, i = 0;
  for (; i < row; i++) {
    len = cgraph_file_fgets(fp, buffer, size);
    if (len <= 0) {
      break;
    }
  }
#ifdef DEBUG
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file handle is error");
  }
  if ((NULL == buffer) || (0 >= size)) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file buffer is empty");
  }
  if (0 >= row) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "row number %ld is smaller than or equal to zero", row);
  }
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
#if __PLAT_NLINE_TYPE == __PLAT_NLINE_WIN
      if (('\r' == (ch = fgetc(fp))) && ('\n' == (ch = fgetc(fp)))) {
#else
      if (__PLAT_NLINE_C == (ch = fgetc(fp))) {
#endif
        rows += 1;
      }
    }
    fsetpos(fp, &fp_init);
  }
#ifdef DEBUG
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file handle is error");
  }
#endif

  return rows;
}

cgraph_size_t cgraph_file_columns(FILE *fp, cgraph_char_t *sep,
                                  cgraph_char_t *buffer,
                                  const cgraph_size_t size) {
  cgraph_size_t columns = 0;
  if (NULL != sep) {
    char *str = NULL;
    cgraph_file_header(fp, buffer, size);
    str = strtok(buffer, sep);
    while (NULL != str) {
      columns += 1;
      str = strtok(NULL, sep);
    }
  }
#ifdef DEBUG
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file handle is error");
  }
  if (NULL == sep) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "line seperator is error");
  }
#endif

  return columns;
}

cgraph_int32_t cgraph_file_size32(FILE *fp) {
  cgraph_int32_t len = 0;
  if ((NULL != fp) && (0 == ferror(fp))) {
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
  }
#ifdef DEBUG
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file handle is error");
  }
#endif

  return len;
}

cgraph_int64_t cgraph_file_size64(FILE *fp) {
  cgraph_int64_t len = 0;
  if ((NULL != fp) && (0 == ferror(fp))) {
#if __WORDSIZE == 32
    fpos_t pos_init, pos_end;
    fgetpos(fp, &pos_init);
    fseek(fp, 0, SEEK_END);
    fgetpos(fp, &pos_end);
    len = pos_end - pos_init;
#else
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
#endif
  }
#ifdef DEBUG
  if ((NULL == fp) || (0 != ferror(fp))) {
    cgraph_error_log(stderr, __FILE__, __LINE__, __FUNCTION,
                     "file handle is error");
  }
#endif

  return len;
}

cgraph_size_t cgraph_file_size(FILE *fp) {
#if __WORDSIZE == 64
  return cgraph_file_size64(fp);
#else
  return cgraph_file_size32(fp);
#endif
}

static const cgraph_char_t *_platform = __PLAT_NAME;
static const cgraph_char_t *_path_split = __PLAT_PSPLIT;
static const cgraph_char_t *_new_line = __PLAT_NLINE;

const static union cgraph_endian_t {
  cgraph_int32_t num;
  cgraph_int8_t byte[4];
} cgraph_file_endian = {1};

void cgraph_file_os(cgraph_char_t **os, cgraph_char_t **path_sep,
                    cgraph_char_t **file_end, cgraph_bool_t *isbigendian) {
  if (NULL != os) {
    *os = (cgraph_char_t *)_platform;
  }
  if (NULL != path_sep) {
    *path_sep = (cgraph_char_t *)_path_split;
  }
  if (NULL != file_end) {
    *file_end = (cgraph_char_t *)_new_line;
  }
  if (NULL != isbigendian) {
#if __PLAT_ENDIAN == 1
    *isbigendian = CGRAPH_TRUE;
#else
    *isbigendian = (cgraph_file_endian.byte[3] ? CGRAPH_FALSE : CGRAPH_TRUE);
#endif
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
