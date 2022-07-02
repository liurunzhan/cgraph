#include "cgraph.h"

int main(int argc, char *argv[]) {
  cgraph_matrix_t *sudoku = cgraph_sudoku_calloc(9);
  cgraph_sudoku_fprintfln(stdout, sudoku);
  cgraph_sudoku_free(sudoku);

  return 0;
}