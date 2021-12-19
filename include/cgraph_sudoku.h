/**
 * @file cgraph_sudoku.h
 * @brief the apis of Game sudoku
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_SUDOKU_H__
#define __CGRAPH_SUDOKU_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_matrix.h"

extern cgraph_matrix_t *cgraph_sudoku_calloc(const cgraph_size_t size);
extern void cgraph_sudoku_free(cgraph_matrix_t *cthis);
extern cgraph_size_t cgraph_sudoku_fprintfln(FILE *fp,
                                             const cgraph_matrix_t *cthis);
extern cgraph_matrix_t *cgraph_sudoku_random(cgraph_matrix_t *cthis);
extern cgraph_matrix_t *cgraph_sudoku_solve(cgraph_matrix_t *cthis);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_SUDOKU_H__ */
