/**
 * SECTION: file
 * @short_description: file handle functions
 * @title: file
 */

#include "cgraph_error.h"
#include "cgraph_math.h"
#include "cgraph_memory.h"

#include "cgraph_file.h"

#include <stdlib.h>

#if (defined(__HAVE_DIRENT_H) && defined(__HAVE_SYS_STAT_H) &&                 \
     defined(__HAVE_UNISTD_H)) ||                                              \
    (__PLAT_LEND_TYPE == __PLAT_LEND_UNIX)
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#define access access
#elif (defined(__HAVE_IO_H) && defined(__HAVE_WINDOWS_H)) || (1 == 1)
#include <io.h>
#include <windows.h>
#define access _access
#endif

#ifndef F_OK
#define F_OK 0
#endif

cgraph_bool_t cgraph_file_ispath(const cgraph_char_t *path) {
  cgraph_bool_t res = CGRAPH_FALSE;
#ifdef access
  if (CGRAPH_ISSTR(path)) {
    res = CGRAPH_TEST(0 == access(path, F_OK));
  }
#endif

  return res;
}

cgraph_bool_t cgraph_file_isfile(const cgraph_char_t *path) {
  cgraph_bool_t res = CGRAPH_FALSE;
#ifdef access
  if (CGRAPH_ISSTR(path)) {
  }
#endif

  return res;
}

cgraph_bool_t cgraph_file_isrfile(const cgraph_char_t *path) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if (CGRAPH_ISSTR(path)) {
    FILE *fp = fopen(path, "r");
    if (CGRAPH_ISFILE(fp)) {
      res = CGRAPH_TRUE;
      fclose(fp);
    }
  }

  return res;
}

cgraph_bool_t cgraph_file_isdir(const cgraph_char_t *path) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if (CGRAPH_ISSTR(path)) {
  }

  return res;
}

cgraph_bool_t cgraph_file_issuffix(const cgraph_char_t *path,
                                   const cgraph_char_t *suffix) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if (CGRAPH_ISSTR(path) && CGRAPH_ISSTR(suffix)) {
    cgraph_char_t *ppath = (cgraph_char_t *)path,
                  *psuffix = (cgraph_char_t *)suffix;
    for (; '\0' != *ppath; ppath++) {
      if ('.' == *ppath) {
        cgraph_char_t *ptmp = ++ppath, *ppoint = NULL;
        for (; (*ptmp == *psuffix) && ('\0' != *ptmp) && ('\0' != *psuffix);
             ptmp++, psuffix++) {
          if (('.' == *ptmp) && (NULL == ppoint)) {
            ppoint = ptmp;
          }
        }
        if (('\0' == *ptmp) && (*ptmp == *psuffix)) {
          res = CGRAPH_TRUE;
          break;
        } else {
          psuffix = (cgraph_char_t *)suffix;
          ppath = (NULL != ppoint) ? ppoint - 1 : ptmp;
        }
      }
    }
  }

  return res;
}

cgraph_bool_t cgraph_file_startswith(const cgraph_char_t *path,
                                     const cgraph_char_t *prefix) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if (CGRAPH_ISSTR(path) && CGRAPH_ISSTR(prefix)) {
    cgraph_char_t *ppath = (cgraph_char_t *)path,
                  *pprefix = (cgraph_char_t *)prefix;
    for (res = CGRAPH_TRUE; ('\0' != *ppath) && ('\0' != *pprefix);
         ppath++, pprefix++) {
      if (*ppath != *pprefix) {
        res = CGRAPH_FALSE;
        break;
      }
    }
    if ((CGRAPH_TRUE == res) && ('\0' == *ppath)) {
      res = CGRAPH_FALSE;
    }
  }

  return res;
}

cgraph_bool_t cgraph_file_endswith(const cgraph_char_t *path,
                                   const cgraph_char_t *suffix) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if (CGRAPH_ISSTR(path) && CGRAPH_ISSTR(suffix)) {
    cgraph_char_t *ppath = (cgraph_char_t *)path,
                  *psuffix = (cgraph_char_t *)suffix;
    cgraph_size_t path_len = 0, suffix_len = 0;
    for (; '\0' != ppath[path_len]; path_len++) {
    }
    for (; '\0' != psuffix[suffix_len]; suffix_len++) {
    }
    if (path_len >= suffix_len) {
      ppath += (path_len - suffix_len);
      for (res = CGRAPH_TRUE, path_len = 0; path_len < suffix_len; path_len++) {
        if (ppath[path_len] != psuffix[path_len]) {
          res = CGRAPH_FALSE;
          break;
        }
      }
    }
  }

  return res;
}

cgraph_char_t *cgraph_file_path(cgraph_char_t *buffer, const cgraph_size_t size,
                                const cgraph_char_t *path) {
  cgraph_size_t _size = size - 1;
  if (CGRAPH_ISSTR(path) && CGRAPH_ISBUF(buffer, _size)) {
    cgraph_size_t i = 0, split_pos = 0;
    for (; ('\0' != path[i]) && (i < _size); i++) {
      buffer[i] = path[i];
      if (cgraph_math_isnline(path[i], path[i + 1])) {
        split_pos = i;
      }
    }
    if (0 < split_pos) {
      buffer[split_pos] = '\0';
    } else {
      buffer[i] = '\0';
    }
  }

  return buffer;
}

cgraph_char_t *cgraph_file_name(cgraph_char_t *buffer, const cgraph_size_t size,
                                const cgraph_char_t *path) {
  cgraph_size_t _size = size - 1;
  if (CGRAPH_ISSTR(path) && CGRAPH_ISBUF(buffer, _size)) {
    cgraph_size_t i = 0, split_pos = 0;
    for (; '\0' != path[i]; i++) {
      cgraph_int_t num = cgraph_math_isnline(path[i], path[i + 1]);
      if (num > 0) {
        num -= 1;
        if ('\0' != path[i + num]) {
          split_pos = i;
        } else {
          split_pos = -1;
        }
      }
    }
    if (0 <= split_pos) {
      cgraph_char_t *ppath = (cgraph_char_t *)&(path[split_pos]);
      for (i = 0; ('\0' != ppath[i]) && (i < _size); i++) {
        buffer[i] = ppath[i];
      }
      if ('\0' == ppath[i]) {
        buffer[i] = '\0';
      } else {
        buffer[0] = '\0';
      }
    }
  }

  return buffer;
}

cgraph_char_t *cgraph_file_suffix(cgraph_char_t *buffer,
                                  const cgraph_size_t size,
                                  const cgraph_char_t *path) {
  cgraph_size_t _size = size - 1;
  if (CGRAPH_ISSTR(path) && CGRAPH_ISBUF(buffer, _size)) {
    cgraph_size_t i = 0, split_pos = 0;
    for (; '\0' != path[i]; i++) {
      if ('.' == path[i]) {
        split_pos = i;
      }
    }
    if (0 < split_pos) {
      cgraph_char_t *ppath = (cgraph_char_t *)&(path[split_pos]);
      for (i = 0; ('\0' != ppath[i]) && (i < _size); i++) {
        buffer[i] = ppath[i];
      }
      if ('\0' == ppath[i]) {
        buffer[i] = '\0';
      } else {
        buffer[0] = '\0';
      }
    }
  }

  return buffer;
}

cgraph_char_t *cgraph_file_joinpath(cgraph_char_t *root,
                                    const cgraph_size_t size,
                                    const cgraph_char_t *path) {
  cgraph_strncat(root, __PLAT_PSPLIT, size);
  cgraph_strncat(root, path, size);

  return root;
}

cgraph_char_t **cgraph_file_walk(const cgraph_char_t *path) {
  cgraph_char_t **ext = NULL;
#ifdef access
#if __PLAT_LEND_TYPE == __PLAT_LEND_UNIX
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
cgraph_size_t cgraph_file_fputs(const cgraph_char_t *cbuf,
                                const cgraph_size_t size, FILE *fp) {
  cgraph_size_t _size = 0;
  if (CGRAPH_ISNFILE(fp) || (NULL == cbuf)) {
    goto CERROR;
  }
  if (0 < size) {
    _size = fwrite(cbuf, size, 1, fp);
  } else {
    _size = fputs(cbuf, fp);
  }

  return _size;
CERROR:
#ifdef DEBUG
  if (NULL == cbuf) {
  }
  if (CGRAPH_ISNFILE(fp)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "file handle is error");
  }
#endif

  return 0;
}

cgraph_size_t cgraph_file_frputs(const cgraph_char_t *cbuf,
                                 const cgraph_size_t size, FILE *fp) {
  cgraph_char_t *data = NULL;
  if (CGRAPH_ISNBUF(cbuf, size)) {
    goto CERROR;
  }
  for (data = (cgraph_char_t *)CGRAPH_VARADDR(cbuf[size - 1]); cbuf <= data;
       data--) {
    fputc(*data, fp);
  }

  return size;
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNFILE(fp)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "file handle is error");
  }
#endif

  return 0;
}

__INLINE__ cgraph_size_t cgraph_file_sprintln(cgraph_char_t *cbuf,
                                              const cgraph_size_t size,
                                              const cgraph_size_t pos) {
  if ((NULL != cbuf) && ((pos + __PLAT_LEND_SIZE) < size)) {
    cbuf += pos;
#if __PLAT_LEND_TYPE == __PLAT_LEND_WIN
    *(cbuf++) = __PLAT_LEND_C0;
    *(cbuf++) = __PLAT_LEND_C1;
#else
    *(cbuf++) = __PLAT_LEND_C;
#endif
  }

  return __PLAT_LEND_SIZE;
}

__INLINE__ cgraph_size_t cgraph_file_fprintln(FILE *fp) {
  return fputs(__PLAT_LEND, fp);
}

cgraph_size_t cgraph_file_println(void) { return cgraph_file_fprintln(stdout); }

cgraph_size_t cgraph_file_vfprintf(FILE *fp, const cgraph_char_t *format,
                                   va_list args) {
  return vfprintf(fp, format, args);
}

cgraph_size_t cgraph_file_fprintf(FILE *fp, const cgraph_char_t *format, ...) {
  cgraph_size_t _size = 0;
  va_list args;
  if (CGRAPH_ISNFILE(fp)) {
    goto CERROR;
  }
  va_start(args, format);
  _size = vfprintf(fp, format, args);
  va_end(args);

  return _size;
CERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "file handle is error");
#endif

  return 0;
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
  if (CGRAPH_ISNFILE(fp)) {
    goto CERROR;
  }
  va_start(args, format);
  _size = vfprintf(fp, format, args);
  va_end(args);
  if (_size > 0) {
    _size += cgraph_file_fprintln(fp);
  }

  return _size;
CERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "file handle is error");
#endif

  return 0;
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

cgraph_size_t cgraph_file_vsnprintf(cgraph_char_t *cbuf,
                                    const cgraph_size_t size,
                                    const cgraph_char_t *format, va_list args) {
  if (BUFSIZ >= size) {
    goto CERROR;
  }

  return vsnprintf(cbuf,
#ifndef __NO_VSNPRINTF
                   size,
#endif
                   format, args);
CERROR:
#if defined(DEBUG) && defined(__NO_VSNPRINTF)
  fprintf(stderr,
          "cbuf size %ld is bigger than default size %d for vsnprintf "
          "undefined!\n",
          size, BUFSIZ);
#endif

  return 0;
}

cgraph_size_t cgraph_file_snprintf(cgraph_char_t *cbuf,
                                   const cgraph_size_t size,
                                   const cgraph_char_t *format, ...) {
  cgraph_size_t _size = 0;
  va_list args;
  if (CGRAPH_ISNBUF(cbuf, size)) {
    goto CERROR;
  }
  va_start(args, format);
  _size = cgraph_file_vsnprintf(cbuf, size, format, args);
  va_end(args);

  return _size;
CERROR:
#ifdef DEBUG
  if ((NULL == cbuf) || (0 >= size)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "file cbuf is empty");
  }
#endif

  return 0;
}

extern cgraph_size_t cgraph_file_fsnprintf(FILE *fp, cgraph_char_t *cbuf,
                                           const cgraph_size_t size,
                                           const cgraph_char_t *format, ...) {
  cgraph_size_t _size = 0;
  va_list args;
  if (CGRAPH_ISNBUF(cbuf, size)) {
    goto CERROR;
  }
  va_start(args, format);
  _size = cgraph_file_vsnprintf(cbuf, size, format, args);
  va_end(args);
  cgraph_file_fputs(cbuf, _size, fp);

  return _size;
CERROR:
#ifdef DEBUG
  if ((NULL == cbuf) || (0 >= size)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "file cbuf is empty");
  }
  if (0 >= size) {
  }
#endif

  return 0;
}

cgraph_size_t cgraph_file_fflush(FILE *fp) {
  if (CGRAPH_ISNFILE(fp)) {
    goto CERROR;
  }

  return fflush(fp);
CERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "file handle is error");
#endif

  return 0;
}

FILE *cgraph_file_fopen(cgraph_char_t *file, cgraph_char_t *mode) {
  FILE *fp = fopen(file, mode);
  if (NULL == fp) {
    goto CERROR;
  }

  return fp;
CERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "%s in style %s is opened error", file, mode);
#endif

  return NULL;
}

cgraph_bool_t cgraph_file_fclose(FILE *fp) {
  if (CGRAPH_ISNFILE(fp)) {
    goto CERROR;
  }

  return CGRAPH_TEST(0 == fclose(fp));
CERROR:
  if (NULL != fp) {
    clearerr(fp);
  }
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "file handle is error before closed");
#endif

  return CGRAPH_FALSE;
}

cgraph_size_t cgraph_file_fgets(cgraph_char_t *cbuf, const cgraph_size_t size,
                                FILE *fp) {
  cgraph_size_t len = 0, _size = size - 1;
  if (CGRAPH_ISBUF(cbuf, _size)) {
    cgraph_char_t ch;
    for (; (len < _size) && 0 != feof(fp); len++, cbuf++) {
#if __PLAT_LEND_TYPE == __PLAT_LEND_WIN
      if (__PLAT_LEND_C0 == (ch = fgetc(fp))) {
        if (__PLAT_LEND_C1 == (ch = fgetc(fp))) {
          break;
        }
        *cbuf = __PLAT_LEND_C0;
        continue;
      }
#else
      if (__PLAT_LEND_C == (ch = fgetc(fp))) {
        break;
      }
#endif
      *cbuf = ch;
    }
    *cbuf = '\0';
  }

  return len;
#ifdef DEBUG
  if (CGRAPH_ISNFILE(fp)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "file handle is error");
  }
  if (CGRAPH_ISNBUF(cbuf, size)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "file cbuf is empty");
  }
#endif

  return 0;
}

cgraph_size_t cgraph_file_fread(cgraph_char_t *cbuf, const cgraph_size_t size,
                                FILE *fp) {
  cgraph_size_t len = 0;
  if (CGRAPH_ISNBUF(cbuf, size) || ((len = cgraph_file_size(fp)) < size) ||
      (0 == len)) {
    goto CERROR;
  }
  len = fread(cbuf, len, 1, fp);
  *(cbuf + len) = '\0';

  return len;
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNFILE(fp)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "file handle is error");
  }
  if (CGRAPH_ISNBUF(cbuf, size)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "file cbuf is empty");
  }
#endif

  return 0;
}

cgraph_size_t cgraph_file_header(cgraph_char_t *cbuf, const cgraph_size_t size,
                                 FILE *fp) {
  cgraph_size_t len = 0;
  fpos_t fp_init;
  if (CGRAPH_ISNBUF(cbuf, size)) {
    goto CERROR;
  }
  fgetpos(fp, &fp_init);
  rewind(fp);
  len = cgraph_file_fgets(cbuf, size, fp);
  fsetpos(fp, &fp_init);

  return len;
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNFILE(fp)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "file handle is error");
  }
  if (CGRAPH_ISNBUF(cbuf, size)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "file cbuf is empty");
  }
#endif
  return 0;
}

cgraph_size_t cgraph_file_row(cgraph_char_t *cbuf, const cgraph_size_t size,
                              const cgraph_size_t row, FILE *fp) {
  cgraph_size_t len = 0;
  if (CGRAPH_ISNFILE(fp) || CGRAPH_ISNBUF(cbuf, size) || (0 >= row)) {
    goto CERROR;
  }
  CGRAPH_LOOP(i, 0, row)
  len = cgraph_file_fgets(cbuf, size, fp);
  if (len <= 0) {
    break;
  }
  CGRAPH_LOOP_END

  return len;
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNFILE(fp)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "file handle is error");
  }
  if (CGRAPH_ISNBUF(cbuf, size)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "file cbuf is empty");
  }
  if (0 >= row) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "row number %ld is smaller than or equal to zero",
                          row);
  }
#endif

  return 0;
}

cgraph_size_t cgraph_file_rows(FILE *fp) {
  cgraph_size_t rows = 0;
  cgraph_char_t ch;
  fpos_t fp_init;
  if (CGRAPH_ISNFILE(fp)) {
    goto CERROR;
  }
  fgetpos(fp, &fp_init);
  while (0 != feof(fp)) {
#if __PLAT_LEND_TYPE == __PLAT_LEND_WIN
    if (('\r' == (ch = fgetc(fp))) && ('\n' == (ch = fgetc(fp)))) {
#else
    if (__PLAT_LEND_C == (ch = fgetc(fp))) {
#endif
      rows += 1;
    }
  }
  fsetpos(fp, &fp_init);

  return rows;
CERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "file handle is error");
#endif

  return 0;
}

cgraph_size_t cgraph_file_columns(cgraph_char_t *cbuf, const cgraph_size_t size,
                                  cgraph_char_t *sep, FILE *fp) {
  cgraph_size_t columns = 0;
  char *cstr = NULL;
  if (CGRAPH_ISNSTR(sep)) {
    goto CERROR;
  }
  cgraph_file_header(cbuf, size, fp);
  cstr = cgraph_strtok(cbuf, sep);
  while (NULL != cstr) {
    columns += 1;
    cstr = cgraph_strtok(NULL, sep);
  }

  return columns;
CERROR:
#ifdef DEBUG
  if (CGRAPH_ISNFILE(fp)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "file handle is error");
  }
  if (CGRAPH_ISNSTR(sep)) {
    cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                          "line seperator is error");
  }
#endif

  return 0;
}

cgraph_int32_t cgraph_file_size32(FILE *fp) {
  cgraph_int32_t len = 0;
  if (CGRAPH_ISNFILE(fp)) {
    goto CERROR;
  }
  fseek(fp, 0, SEEK_END);
  len = ftell(fp);

  return len;
CERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "file handle is error");
#endif

  return 0;
}

cgraph_int64_t cgraph_file_size64(FILE *fp) {
  cgraph_int64_t len = 0;
#if __WORDSIZE == 32
  fpos_t pos_init, pos_end;
#endif
  if (CGRAPH_ISNFILE(fp)) {
    goto CERROR;
  }
#if __WORDSIZE == 32
  fgetpos(fp, &pos_init);
  fseek(fp, 0, SEEK_END);
  fgetpos(fp, &pos_end);
  len = pos_end - pos_init;
#else
  fseek(fp, 0, SEEK_END);
  len = ftell(fp);
#endif

  return len;
CERROR:
#ifdef DEBUG
  cgraph_error_printfln(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, CGRAPH_LEVEL_ERROR,
                        "file handle is error");
#endif
  return 0;
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
static const cgraph_char_t *_line_end = __PLAT_LEND;

/** judge platform information */
#if __PLAT_ENDIAN == __PLAT_ENDIAN_NONE
const static union cgraph_endian_t {
  cgraph_int32_t num;
  cgraph_uint8_t byte[4];
} cgraph_file_endian = {1};
#endif

void cgraph_file_os(cgraph_char_t **os, cgraph_char_t **path_sep,
                    cgraph_char_t **line_end, cgraph_bool_t *isbigendian) {
  if (NULL != os) {
    *os = (cgraph_char_t *)_platform;
  }
  if (NULL != path_sep) {
    *path_sep = (cgraph_char_t *)_path_split;
  }
  if (NULL != line_end) {
    *line_end = (cgraph_char_t *)_line_end;
  }
  if (NULL != isbigendian) {
#if __PLAT_ENDIAN == __PLAT_ENDIAN_LITTLE
    *isbigendian = CGRAPH_FALSE;
#elif __PLAT_ENDIAN == __PLAT_ENDIAN_BIG
    *isbigendian = CGRAPH_TRUE;
#else
    *isbigendian = (cgraph_file_endian.byte[3] ? CGRAPH_TRUE : CGRAPH_FALSE);
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
