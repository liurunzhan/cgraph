/**
 * @file cgraph_error.h
 * @brief the apis of error functions
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_ERROR_H__
#define __CGRAPH_ERROR_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define CGRAPH_TIME_CBUF_SIZE CGRAPH_CBUF_SIZE2
#define CGRAPH_LOG_CBUF_SIZE CGRAPH_CBUF_SIZE5

typedef enum {
  CGRAPH_ERROR_NO_ERROR,               /** NO ERROR */
  CGRAPH_ERROR_ERROR,                  /** ERROR */
  CGRAPH_ERROR_OUT_OF_MEMORY,          /** OUT OF MEMORY */
  CGRAPH_ERROR_OUT_OF_INDEX,           /** OUT OF INDEX */
  CGRAPH_ERROR_INFINITE,               /** INFINITE */
  CGRAPH_ERROR_NOT_A_NUMBER,           /** NOT A NUMBER */
  CGRAPH_ERROR_DIVISOR_EQUAL_TO_ZERO,  /** DIVISOR EQUAL TO ZERO */
  CGRAPH_ERROR_MATH_ERROR,             /** MATH ERROR */
  CGRAPH_ERROR_FILE_HANDLE_EMPTY,      /** FILE HANDLE EMPTY */
  CGRAPH_ERROR_FILE_HANDLE_ERROR,      /** FILE HANDLE ERROR */
  CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS /** MAXIMUM VALUE OF ERRORS, NO USED */
} cgraph_error_t;

#ifdef DEBUG
#define cgraph_error_print(reason)                                             \
  cgraph_error((reason), (__LINE__), (__FILE__), (__FUNCTION))
#else
#define cgraph_error_print(reason) ((void)0)
#endif

void cgraph_error(cgraph_error_t reason, const cgraph_size_t line,
                  cgraph_char_t *file, const cgraph_char_t *function);

extern cgraph_char_t *cgraph_error_reason(const cgraph_error_t reason);
extern void cgraph_error_details_md(FILE *fout);
extern void cgraph_error_details_csv(FILE *fout);

extern cgraph_char_t *cgraph_error_time(void);
extern void cgraph_error_log(FILE *fp, const cgraph_char_t *file,
                             const cgraph_char_t *function,
                             const cgraph_size_t line,
                             const cgraph_char_t *format, ...);
extern void cgraph_error_log_cbuf(FILE *fp, cgraph_char_t *cbuf,
                                  cgraph_size_t len, const cgraph_char_t *file,
                                  const cgraph_char_t *function,
                                  const cgraph_size_t line,
                                  const cgraph_char_t *format, ...);

/** corresponding to the argument order of above function calling */
#define CGRAPH_ERROR_STYLE "[%s>%ld] "
#define CGRAPH_ERROR_STYLE_ENTRY __FILE__, __LINE__
#define CGRAPH_ERROR_FUNCTION_STYLE "[%s>%s>%ld] "
#define CGRAPH_ERROR_FUNCTION_STYLE_ENTRY __FILE__, __FUNCTION, __LINE__
#define CGRAPH_ERROR_TIME_STYLE "[%s@%s>%ld] "
#define CGRAPH_ERROR_TIME_STYLE_ENTRY __FILE__, __LINE__
#define CGRAPH_ERROR_TIME_FUNCTION_STYLE "[%s@%s>%s>%ld] "
#define CGRAPH_ERROR_TIME_FUNCTION_STYLE_ENTRY __FILE__, __FUNCTION, __LINE__

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_ERROR_H__ */
