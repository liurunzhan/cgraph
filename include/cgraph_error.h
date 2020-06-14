#ifndef _CGRAPH_ERROR_H_
#define _CGRAPH_ERROR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "cgraph_config.h"

#define CGRAPH_TIME_BUFFER_SIZE 256
#define CGRAPH_LOG_BUFFER_SIZE 2048

typedef enum 
{
  CGRAPH_ERROR_NO_ERROR,                  /* NO ERROR */
  CGRAPH_ERROR_ERROR,                     /* ERROR */
  CGRAPH_ERROR_OUT_OF_MEMORY,             /* OUT OF MEMORY */
  CGRAPH_ERROR_OUT_OF_INDEX,              /* OUT OF INDEX */
  CGRAPH_ERROR_INFINITE,                  /* INFINITE */
  CGRAPH_ERROR_NOT_A_NUMBER,              /* NOT A NUMBER */
  CGRAPH_ERROR_DIVISOR_EQUAL_TO_ZERO,     /* DIVISOR EQUAL TO ZERO */   
  CGRAPH_ERROR_MATH_ERROR,                /* MATH ERROR */
  CGRAPH_ERROR_FILE_HANDLE_EMPTY,         /* FILE HANDLE EMPTY */
  CGRAPH_ERROR_FILE_HANDLE_ERROR,         /* FILE HANDLE ERROR */
  CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS    /* MAXIMUM VALUE OF ERRORS, NO USED */
}cgraph_error_t;

#define cgraph_error_print(reason) \
  cgraph_error((reason), (__LINE__), (__FILE__))

void cgraph_error(cgraph_error_t reason, const cgraph_size_t line, cgraph_char_t *file);

extern cgraph_char_t *cgraph_error_reason(const cgraph_error_t reason);
extern void cgraph_error_details_md(FILE *fout);
extern void cgraph_error_details_csv(FILE *fout);

extern cgraph_char_t *cgraph_error_time(void);
extern void cgraph_error_log(FILE *fp, const cgraph_char_t *file, const cgraph_size_t line, const cgraph_char_t *format, ...);
extern void cgraph_error_log_buffer(FILE *fp, const cgraph_char_t *file, const cgraph_size_t line, cgraph_char_t *buffer, cgraph_size_t len, const cgraph_char_t *format, ...);

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_ERROR_H_ */