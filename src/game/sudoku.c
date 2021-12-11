#include "cgraph_sudoku.h"

cgraph_matrix_t *cgraph_sudoku_calloc(const cgraph_size_t size) {
  return cgraph_matrix_create(CGRAPH_INT_T, size, size);
}

cgraph_matrix_t *cgraph_sudoku_random(cgraph_matrix_t *cthis) {
  if (NULL != cthis) {
  }

  return cthis;
}

void cgraph_sudoku_free(cgraph_matrix_t *cthis) { cgraph_matrix_free(cthis); }

cgraph_size_t cgraph_sudoku_fprintfln(FILE *fp, const cgraph_matrix_t *cthis) {
  return 0;
}
