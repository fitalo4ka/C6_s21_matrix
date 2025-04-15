#include <time.h>

#include "s21_matrix_tests.h"

START_TEST(sum_1_normal) {
  int rows1 = 2, cols1 = 2;
  int rows2 = 2, cols2 = 2;
  matrix_t A = {0}, result = {0}, B = {0}, C = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows2, cols2, &B);
  s21_create_matrix(rows2, cols2, &C);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 6.0;
  B.matrix[0][1] = 7.0;
  B.matrix[1][0] = 8.0;
  B.matrix[1][1] = 9.0;

  C.matrix[0][0] = 7.0;
  C.matrix[0][1] = 9.0;
  C.matrix[1][0] = 11.0;
  C.matrix[1][1] = 13.0;
  int status = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(A.columns, result.columns);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);
  ck_assert_int_eq(status, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_2_normal) {
  int rows1 = 1, cols1 = 5;
  int rows2 = 1, cols2 = 5;
  matrix_t A = {0}, result = {0}, B = {0}, C = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows2, cols2, &B);
  s21_create_matrix(rows2, cols2, &C);
  A.matrix[0][0] = -7.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 0.0;
  A.matrix[0][3] = -1.0;
  A.matrix[0][4] = 1.0;

  B.matrix[0][0] = 52.0;
  B.matrix[0][1] = -68.0;
  B.matrix[0][2] = -42.0;
  B.matrix[0][3] = -14.0;
  B.matrix[0][4] = -17.0;

  C.matrix[0][0] = 45.0;
  C.matrix[0][1] = -63.0;
  C.matrix[0][2] = -42.0;
  C.matrix[0][3] = -15.0;
  C.matrix[0][4] = -16.0;
  int status = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(A.columns, result.columns);
  ck_assert_int_eq(B.rows, result.rows);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);
  ck_assert_int_eq(status, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_3_normal) {
  int rows1 = 1, cols1 = 5;
  int rows2 = 1, cols2 = 5;
  matrix_t A = {0}, result = {0}, B = {0}, C = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows2, cols2, &B);

  s21_create_matrix(rows2, cols2, &C);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = -1.0;
  A.matrix[0][2] = 0.0;
  A.matrix[0][3] = -1.0;
  A.matrix[0][4] = 1.0;

  B.matrix[0][0] = 851.0;
  B.matrix[0][1] = -565.0;
  B.matrix[0][2] = 67.0;
  B.matrix[0][3] = 597.0;
  B.matrix[0][4] = -103.0;

  C.matrix[0][0] = 850.0;
  C.matrix[0][1] = -566.0;
  C.matrix[0][2] = 67.0;
  C.matrix[0][3] = 596.0;
  C.matrix[0][4] = -102.0;
  int status = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(A.columns, result.columns);
  ck_assert_int_eq(B.rows, result.rows);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);
  ck_assert_int_eq(status, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_1_calc_error) {
  int rows = 2, columns = 3, rows2 = 2, columns2 = 2;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows2, columns2, &B);
  int status = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(status, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_2_incorrect) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  int status = s21_sum_matrix(&A, NULL, &result);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_3_incorrect) {
  matrix_t B = {0}, result = {0};
  s21_create_matrix(2, 2, &B);
  int status = s21_sum_matrix(NULL, &B, &result);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *test_sum_matrix(void) {
  Suite *s = suite_create("\033[42m-=S21_sum_matrix=-\033[0m");
  TCase *tc = tcase_create("s21_sum_matrix_tc");

  tcase_add_test(tc, sum_1_normal);
  tcase_add_test(tc, sum_1_calc_error);
  tcase_add_test(tc, sum_2_normal);
  tcase_add_test(tc, sum_2_incorrect);
  tcase_add_test(tc, sum_3_normal);
  tcase_add_test(tc, sum_3_incorrect);

  suite_add_tcase(s, tc);
  return s;
}