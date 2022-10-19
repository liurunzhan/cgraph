/**
 * @file cgraph_file.h
 * @brief the apis of file functions
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_FILE_H__
#define __CGRAPH_FILE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define CGRAPH_FILE_CBUF_SIZE CGRAPH_CBUF_SIZE5

extern cgraph_bool_t cgraph_file_ispath(const cgraph_char_t *path);
extern cgraph_bool_t cgraph_file_isfile(const cgraph_char_t *path);
extern cgraph_bool_t cgraph_file_isrfile(const cgraph_char_t *path);
extern cgraph_bool_t cgraph_file_isdir(const cgraph_char_t *path);
extern cgraph_bool_t cgraph_file_issuffix(const cgraph_char_t *path,
                                          const cgraph_char_t *suffix);
extern cgraph_bool_t cgraph_file_startswith(const cgraph_char_t *path,
                                            const cgraph_char_t *prefix);
extern cgraph_bool_t cgraph_file_endswith(const cgraph_char_t *path,
                                          const cgraph_char_t *suffix);

extern cgraph_char_t *cgraph_file_path(cgraph_char_t *buffer,
                                       const cgraph_size_t size,
                                       const cgraph_char_t *path);
extern cgraph_char_t *cgraph_file_name(cgraph_char_t *buffer,
                                       const cgraph_size_t size,
                                       const cgraph_char_t *path);
extern cgraph_char_t *cgraph_file_suffix(cgraph_char_t *buffer,
                                         const cgraph_size_t size,
                                         const cgraph_char_t *path);

extern cgraph_char_t *cgraph_file_joinpath(cgraph_char_t *root,
                                           const cgraph_size_t size,
                                           const cgraph_char_t *path);

extern cgraph_size_t cgraph_file_fputs(const cgraph_char_t *cbuf,
                                       const cgraph_size_t size, FILE *fp);
extern cgraph_size_t cgraph_file_frputs(const cgraph_char_t *cbuf,
                                        const cgraph_size_t size, FILE *fp);
extern cgraph_size_t cgraph_file_sprintln(cgraph_char_t *cbuf,
                                          const cgraph_size_t size,
                                          const cgraph_size_t pos);
extern cgraph_size_t cgraph_file_fprintln(FILE *fp);
extern cgraph_size_t cgraph_file_println(void);
extern cgraph_size_t cgraph_file_vfprintf(FILE *fp, const cgraph_char_t *format,
                                          va_list args);
extern cgraph_size_t cgraph_file_fprintf(FILE *fp, const cgraph_char_t *format,
                                         ...);
extern cgraph_size_t cgraph_file_printf(const cgraph_char_t *format, ...);
extern cgraph_size_t cgraph_file_fprintfln(FILE *fp,
                                           const cgraph_char_t *format, ...);
extern cgraph_size_t cgraph_file_printfln(const cgraph_char_t *format, ...);
extern cgraph_size_t cgraph_file_vsnprintf(cgraph_char_t *cbuf,
                                           const cgraph_size_t size,
                                           const cgraph_char_t *format,
                                           va_list args);
extern cgraph_size_t cgraph_file_snprintf(cgraph_char_t *cbuf,
                                          const cgraph_size_t size,
                                          const cgraph_char_t *format, ...);
extern cgraph_size_t cgraph_file_fsnprintf(FILE *fp, cgraph_char_t *cbuf,
                                           const cgraph_size_t size,
                                           const cgraph_char_t *format, ...);
extern cgraph_size_t cgraph_file_fflush(FILE *fp);

extern FILE *cgraph_file_fopen(cgraph_char_t *file, cgraph_char_t *mode);
extern cgraph_bool_t cgraph_file_fclose(FILE *fp);
extern cgraph_size_t cgraph_file_fgets(cgraph_char_t *cbuf,
                                       const cgraph_size_t size, FILE *fp);
extern cgraph_size_t cgraph_file_fread(cgraph_char_t *cbuf,
                                       const cgraph_size_t size, FILE *fp);
extern cgraph_size_t cgraph_file_header(cgraph_char_t *cbuf,
                                        const cgraph_size_t size, FILE *fp);
extern cgraph_size_t cgraph_file_row(cgraph_char_t *cbuf,
                                     const cgraph_size_t size,
                                     const cgraph_size_t line, FILE *fp);
extern cgraph_size_t cgraph_file_rows(FILE *fp);
extern cgraph_size_t cgraph_file_columns(cgraph_char_t *cbuf,
                                         const cgraph_size_t size,
                                         cgraph_char_t *sep, FILE *fp);
extern cgraph_int32_t cgraph_file_size32(FILE *fp);
extern cgraph_int64_t cgraph_file_size64(FILE *fp);
extern cgraph_size_t cgraph_file_size(FILE *fp);

extern void cgraph_file_os(cgraph_char_t **os, cgraph_char_t **path_sep,
                           cgraph_char_t **line_end,
                           cgraph_bool_t *isbigendian);
extern cgraph_bool_t cgraph_file_iswin(void);
extern cgraph_bool_t cgraph_file_isuxowin(void);
extern cgraph_bool_t cgraph_file_isunix(void);
extern const cgraph_char_t *cgraph_file_psplit(void);
extern const cgraph_char_t *cgraph_file_lend(void);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_FILE_H__ */
