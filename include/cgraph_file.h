/**
 * @file cgraph_file.h
 * @brief the apis of file solution
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef _CGRAPH_FILE_H_
#define _CGRAPH_FILE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define CGRAPH_FILE_BUFFER_SIZE (4096L)

extern cgraph_int_t cgraph_file_putc(FILE *fp, const cgraph_char_t *buffer,
                                     const cgraph_size_t size);
extern cgraph_int_t cgraph_file_rputc(FILE *fp, const cgraph_char_t *buffer,
                                      const cgraph_size_t size);
extern cgraph_int_t cgraph_file_fprintf(FILE *fp, const cgraph_char_t *format,
                                        ...);
extern cgraph_int_t cgraph_file_printf(const cgraph_char_t *format, ...);
extern cgraph_int_t cgraph_file_fprintln(FILE *fp, const cgraph_char_t *format,
                                         ...);
extern cgraph_int_t cgraph_file_println(const cgraph_char_t *format, ...);
extern cgraph_int_t cgraph_file_snprintf(cgraph_char_t *buffer,
                                         const cgraph_size_t size,
                                         const cgraph_char_t *format, ...);

extern FILE *cgraph_file_fopen(cgraph_char_t *file, cgraph_char_t *mode);
extern cgraph_bool_t cgraph_file_fclose(FILE *fp);
extern cgraph_size_t cgraph_file_fgetc(FILE *fp, cgraph_char_t *buffer,
                                       const cgraph_size_t size);
extern cgraph_size_t cgraph_file_fgets(FILE *fp, cgraph_char_t *buffer,
                                       const cgraph_size_t size);
extern cgraph_size_t cgraph_file_line(FILE *fp, cgraph_char_t *buffer,
                                      const cgraph_size_t size,
                                      const cgraph_size_t line);
extern cgraph_size_t cgraph_file_header(FILE *fp, cgraph_char_t *buffer,
                                        const cgraph_size_t size);
extern cgraph_size_t cgraph_file_rows(FILE *fp);
extern cgraph_size_t cgraph_file_columns(FILE *fp, cgraph_char_t *sep,
                                         cgraph_char_t *buffer,
                                         const cgraph_size_t size);

extern void cgraph_file_os(cgraph_char_t **os, cgraph_char_t **sep,
                           cgraph_char_t **end, cgraph_bool_t *isbigendian);

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_FILE_H_ */
