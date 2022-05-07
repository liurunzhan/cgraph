#include "cgraph_file.h"
#include "cgraph_math.h"
#include "cgraph_sudoku.h"

cgraph_matrix_t *cgraph_sudoku_calloc(const cgraph_size_t size) {
  cgraph_matrix_t *cthis = cgraph_matrix_create(CGRAPH_INT_T, size, size);
  return cgraph_sudoku_random(cthis);
}

void cgraph_sudoku_free(cgraph_matrix_t *cthis) { cgraph_matrix_free(cthis); }

cgraph_size_t cgraph_sudoku_fprintfln(FILE *fp, const cgraph_matrix_t *cthis) {
  cgraph_size_t len = 0;
  if (NULL != cthis) {
    cgraph_int_t *data = (cgraph_int_t *)cthis->data;
    CGRAPH_LOOP(i, 0, cthis->row)
    CGRAPH_LOOP(j, 0, cthis->column - 1)
    len += cgraph_file_fprintf(fp, "%d ", *(data++));
    CGRAPH_LOOP_END
    len += cgraph_file_fprintf(fp, "%d\n", *(data++));
    CGRAPH_LOOP_END
  }

  return len;
}

cgraph_matrix_t *cgraph_sudoku_random(cgraph_matrix_t *cthis) {
  if (NULL != cthis) {
    cgraph_int_t *data = (cgraph_int_t *)cthis->data;
    CGRAPH_LOOP(i, 0, cthis->row)
    CGRAPH_LOOP(j, 0, cthis->column)
    CGRAPH_LOOP_END
    CGRAPH_LOOP_END
  }

  return cthis;
}

cgraph_matrix_t *cgraph_sudoku_solve(cgraph_matrix_t *cthis) {
  if (NULL != cthis) {
  }

  return cthis;
}
