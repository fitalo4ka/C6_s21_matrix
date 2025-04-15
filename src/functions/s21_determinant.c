#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = OK;
  if (!A || A->rows < 1 || A->columns < 1 || result == NULL) {
    status = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else {
      *result = find_determinant(*A, A->rows);
    }
  }
  return status;
}

double find_determinant(matrix_t A, int rows) {
  double res = 0;
  int sign = 1;
  if (rows == 1) {
    res = A.matrix[0][0];
  } else {
    matrix_t B = {0};
    s21_create_matrix(A.rows - 1, A.columns - 1, &B);
    for (int i = 0; i < rows; ++i) {
      minor_matrix(A, 0, i, &B);
      res += sign * A.matrix[0][i] * find_determinant(B, rows - 1);
      sign *= -1;
    }
    s21_remove_matrix(&B);
  }
  return res;
}

void minor_matrix(const matrix_t A, const int skip_i, const int skip_j,
                  matrix_t *res) {
  for (int i = 0; i < A.rows; ++i) {
    if (i == skip_i) {
      continue;
    }
    for (int j = 0; j < A.columns; ++j) {
      if (j == skip_j) {
        continue;
      }
      res->matrix[i - (i > skip_i)][j - (j > skip_j)] = A.matrix[i][j];
    }
  }
}