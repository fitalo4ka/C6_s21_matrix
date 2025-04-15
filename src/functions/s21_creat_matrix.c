#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;
  if ((!result) || (rows < 1) || (columns < 1)) {
    status = INCORRECT_MATRIX;
  } else {
    double **matrix =
        calloc(1, sizeof(double) * rows * columns + sizeof(double *) * rows);
    for (int i = 0; i < rows; ++i) {
      *(matrix + i) =
          (double *)((double **)((double *)matrix + i * columns) + rows);
    }
    result->matrix = matrix;
    result->rows = rows;
    result->columns = columns;
  }
  return status;
}