#include "cgraph_sudoku.h"

cgraph_matrix_t *cgraph_sudoku_calloc(const cgraph_size_t size) {
  cgraph_matrix_t *cthis = cgraph_matrix_create(CGRAPH_INT_T, size, size);
  return cgraph_sudoku_random(cthis);
}

void cgraph_sudoku_free(cgraph_matrix_t *cthis) { cgraph_matrix_free(cthis); }

cgraph_size_t cgraph_sudoku_fprintfln(FILE *fp, const cgraph_matrix_t *cthis) {
  return 0;
}

cgraph_matrix_t *cgraph_sudoku_random(cgraph_matrix_t *cthis) {
  if (NULL != cthis) {
  }

  return cthis;
}

cgraph_matrix_t *cgraph_sudoku_solve(cgraph_matrix_t *cthis) {
  if (NULL != cthis) {
  }

  return cthis;
}
