/**
 * @file cgraph_error.h
 * @brief the apis of error functions
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_ERROR_H__
#define __CGRAPH_ERROR_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#ifdef NDEBUG
#ifdef DEBUG
#undef DEBUG
#endif
#endif

#define CGRAPH_TIME_CBUF_SIZE CGRAPH_CBUF_SIZE2
#define CGRAPH_LOG_CBUF_SIZE CGRAPH_CBUF_SIZE5

typedef enum {
  CGRAPH_ERROR_NO_ERROR = 0,              /** NO ERROR */
  CGRAPH_ERROR_ERROR = 1,                 /** ERROR */
  CGRAPH_ERROR_OUT_OF_MEMORY = 2,         /** OUT OF MEMORY */
  CGRAPH_ERROR_OUT_OF_INDEX = 3,          /** OUT OF INDEX */
  CGRAPH_ERROR_INFINITE = 4,              /** INFINITE */
  CGRAPH_ERROR_NOT_A_NUMBER = 5,          /** NOT A NUMBER */
  CGRAPH_ERROR_DIVISOR_EQUAL_TO_ZERO = 6, /** DIVISOR EQUAL TO ZERO */
  CGRAPH_ERROR_MATH_ERROR = 7,            /** MATH ERROR */
  CGRAPH_ERROR_FILE_HANDLE_EMPTY = 8,     /** FILE HANDLE EMPTY */
  CGRAPH_ERROR_FILE_HANDLE_ERROR = 9,     /** FILE HANDLE ERROR */
  CGRAPH_ERROR_OBJECT_HANDLE_EMPTY = 10,  /** OBJECT HANDLE EMPTY */
  CGRAPH_ERROR_OBJECT_HANDLE_ERROR = 11   /** OBJECT HANDLE ERROR */
} cgraph_error_t;

#define CGRAPH_ERROR_SIZE (12)

cgraph_size_t cgraph_error_print(cgraph_error_t reason,
                                 const cgraph_size_t line, cgraph_char_t *file,
                                 const cgraph_char_t *function);

extern const cgraph_char_t *cgraph_error_reason(const cgraph_error_t reason);
extern cgraph_size_t cgraph_error_details_md(FILE *fout);
extern cgraph_size_t cgraph_error_details_csv(FILE *fout);

typedef enum {
  CGRAPH_LEVEL_DEBUG = 0,
  CGRAPH_LEVEL_INFO = 1,
  CGRAPH_LEVEL_NOTICE = 2,
  CGRAPH_LEVEL_WARN = 3,
  CGRAPH_LEVEL_ERROR = 4,
  CGRAPH_LEVEL_FATAL = 5
} cgraph_level_t;

#define CGRAPH_LEVEL_SIZE (6)

cgraph_bool_t cgraph_error_chptr(FILE *fp);
cgraph_bool_t cgraph_error_chptr_by_file(const cgraph_char_t *file);

extern const cgraph_char_t *cgraph_error_level(const cgraph_level_t level);
extern const cgraph_char_t *cgraph_error_time(void);
extern cgraph_size_t cgraph_error_printf(const cgraph_char_t *file,
                                         const cgraph_char_t *function,
                                         const cgraph_size_t line,
                                         const cgraph_level_t level,
                                         const cgraph_char_t *format, ...);
extern cgraph_size_t cgraph_error_fprintf(FILE *fp, const cgraph_char_t *file,
                                          const cgraph_char_t *function,
                                          const cgraph_size_t line,
                                          const cgraph_level_t level,
                                          const cgraph_char_t *format, ...);
extern cgraph_size_t
cgraph_error_snprintf(cgraph_char_t *cbuf, cgraph_size_t len,
                      const cgraph_char_t *file, const cgraph_char_t *function,
                      const cgraph_size_t line, const cgraph_level_t level,
                      const cgraph_char_t *format, ...);
extern cgraph_size_t
cgraph_error_fsnprintf(FILE *fp, cgraph_char_t *cbuf, cgraph_size_t len,
                       const cgraph_char_t *file, const cgraph_char_t *function,
                       const cgraph_size_t line, const cgraph_level_t level,
                       const cgraph_char_t *format, ...);

/** corresponding to the argument order of above function calling */
#define CGRAPH_ERROR_STYLE "[%s>%ld] [%s] "
#define CGRAPH_ERROR_STYLE_ENTRY __FILE__, __LINE__
#define CGRAPH_ERROR_FUNCTION_STYLE "[%s>%s>%ld] [%s] "
#define CGRAPH_ERROR_FUNCTION_STYLE_ENTRY __FILE__, __FUNCTION__, __LINE__
#define CGRAPH_ERROR_TIME_STYLE "[%s@%s>%ld] [%s] "
#define CGRAPH_ERROR_TIME_STYLE_ENTRY __FILE__, __LINE__
#define CGRAPH_ERROR_TIME_FUNCTION_STYLE "[%s@%s>%s>%ld] [%s] "
#define CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY __FILE__, __FUNCTION__, __LINE__

#ifdef __AV_ARGS__

#ifdef DEBUG
#define cgraph_error_log(level, format, ...)                                   \
  cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, level, format,        \
                      ##__AV_ARGS__)
#else
#define cgraph_error_log(level, format, ...) ((void)0)
#endif

#elif defined(__GNUC__) || defined(__clang__)

#if 0
#ifdef DEBUG
#define cgraph_error_log(level, format, args...)
cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, level, format, ##args)
#else
#define cgraph_error_log(level, format, args...) ((void)0)
#endif
#endif

#else

#ifdef DBEUG
#define cgraph_error_log(level, format, args)                                  \
  (cgraph_error_printf(CGRAPH_ERROR_FUNCTION_STYLE_ENTRY, level, ""),          \
   cgraph_error_printf(NULL, NULL, NULL, level, format, args))
#else
#define cgraph_error_log(level, format, args) ((void)0)
#endif

#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_ERROR_H__ */
