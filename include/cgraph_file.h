#ifndef _CGRAPH_FILE_H_
#define _CGRAPH_FILE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#include "cgraph_config.h"
#include "cgraph_string.h"

extern FILE *cgraph_file_fopen(cgraph_char_t *file, cgraph_char_t *mode);
extern cgraph_boolean_t cgraph_file_fclose(FILE *fp);
extern cgraph_boolean_t cgraph_file_fgets(cgraph_string_t *buffer, FILE *fp);
extern cgraph_string_t *cgraph_file_header(FILE *fp, cgraph_string_t *buffer, cgraph_boolean_t *error);
extern cgraph_size_t cgraph_file_rows(FILE *fp);
extern cgraph_size_t cgraph_file_columns(FILE *fp, cgraph_char_t *sep, cgraph_string_t *buffer);

extern cgraph_boolean_t cgraph_file_line(cgraph_string_t *buffer, FILE *fp, const cgraph_size_t line);

extern void cgraph_file_os(cgraph_char_t **os, cgraph_char_t **sep, cgraph_boolean_t *isbigendian);

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_FILE_H_ */
