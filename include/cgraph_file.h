#ifndef _CGRAPH_FILE_H_
#define _CGRAPH_FILE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#include "cgraph_config.h"
#include "cgraph_string.h"

FILE *cgraph_file_fopen(cgraph_char_t *file, cgraph_char_t *mode);
cgraph_boolean_t cgraph_file_fclose(FILE *fp);
cgraph_boolean_t cgraph_file_fgets(cgraph_string_t *buffer, FILE *fp);
cgraph_string_t *cgraph_file_header(FILE *fp, cgraph_string_t *buffer, cgraph_boolean_t *error);
cgraph_size_t cgraph_file_rows(FILE *fp);
cgraph_size_t cgraph_file_columns(FILE *fp, cgraph_char_t *sep, cgraph_string_t *buffer);

cgraph_boolean_t cgraph_file_line(cgraph_string_t *buffer, FILE *fp, const cgraph_size_t line);

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_FILE_H_ */
