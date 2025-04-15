#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (!A || A->rows < 1 || A->columns < 1 || !result) {
    status = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else {
    double det = 0.0;
    s21_determinant(A, &det);
    if (fabs(det) < EPSILON) {
      status = CALCULATION_ERROR;
    } else if (A->rows == 1) {
      s21_create_matrix(1, 1, result);
      result->matrix[0][0] = (1 / A->matrix[0][0]);
    } else {
      det = 1.0 / det;
      matrix_t minor_matr = {0}, trans_matr = {0};
      s21_calc_complements(A, &minor_matr);
      s21_transpose(&minor_matr, &trans_matr);
      s21_remove_matrix(&minor_matr);
      s21_mult_number(&trans_matr, det, result);
      s21_remove_matrix(&trans_matr);
    }
  }
  return status;
}