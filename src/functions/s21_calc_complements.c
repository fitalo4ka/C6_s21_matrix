#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (!A || !result || A->rows < 1 || A->columns < 1) {
    status = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    if (A->rows != 1) {
      matrix_t matr = {0};
      s21_create_matrix(A->rows - 1, A->columns - 1, &matr);

      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          minor_matrix(*A, i, j, &matr);
          double det = 0;
          s21_determinant(&matr, &det);
          result->matrix[i][j] = det * pow(-1, i + j);
        }
      }
      s21_remove_matrix(&matr);
    } else {
      result->matrix[0][0] = A->matrix[0][0];
    }
  }
  return status;
}