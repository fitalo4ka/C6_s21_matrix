#include <time.h>

#include "s21_matrix_tests.h"

START_TEST(sub_1_normal) {
  int rows1 = 2, cols1 = 3;
  int rows2 = 2, cols2 = 3;
  matrix_t A = {0}, result = {0}, B = {0}, C = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows2, cols2, &B);
  s21_create_matrix(rows2, cols2, &C);
  A.matrix[0][0] = 0.0;
  A.matrix[0][1] = 9.0;
  A.matrix[0][2] = -1.0;
  A.matrix[1][0] = -2.0;
  A.matrix[1][1] = -3.0;
  A.matrix[1][2] = -4.0;

  B.matrix[0][0] = -4.0;
  B.matrix[0][1] = -9.0;
  B.matrix[0][2] = 5.0;
  B.matrix[1][0] = -2.0;
  B.matrix[1][1] = -8.0;
  B.matrix[1][2] = 7.0;

  C.matrix[0][0] = 4.0;
  C.matrix[0][1] = 18.0;
  C.matrix[0][2] = -6.0;
  C.matrix[1][0] = 0.0;
  C.matrix[1][1] = 5.0;
  C.matrix[1][2] = -11.0;

  int status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(A.columns, result.columns);
  ck_assert_int_eq(B.rows, result.rows);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_2_normal) {
  int rows1 = 4, cols1 = 4;
  int rows2 = 4, cols2 = 4;
  matrix_t A = {0}, result = {0}, B = {0}, C = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows2, cols2, &B);
  s21_create_matrix(rows1, cols1, &C);
  A.matrix[0][0] = -5.0;
  A.matrix[0][1] = -49.0;
  A.matrix[0][2] = 91.0;
  A.matrix[0][3] = 65.0;
  A.matrix[1][0] = -19.0;
  A.matrix[1][1] = -83.0;
  A.matrix[1][2] = 63.0;
  A.matrix[1][3] = 92.0;
  A.matrix[2][0] = -69.0;
  A.matrix[2][1] = -97.0;
  A.matrix[2][2] = -86.0;
  A.matrix[2][3] = 37.0;
  A.matrix[3][0] = -22.0;
  A.matrix[3][1] = 96.0;
  A.matrix[3][2] = 35.0;
  A.matrix[3][3] = 1.0;

  B.matrix[0][0] = -849.0;
  B.matrix[0][1] = 535.0;
  B.matrix[0][2] = 146.0;
  B.matrix[0][3] = 118.0;
  B.matrix[1][0] = 297.0;
  B.matrix[1][1] = -555.0;
  B.matrix[1][2] = 32.0;
  B.matrix[1][3] = 263.0;
  B.matrix[2][0] = 759.0;
  B.matrix[2][1] = 279.0;
  B.matrix[2][2] = -13.0;
  B.matrix[2][3] = 839.0;
  B.matrix[3][0] = 258.0;
  B.matrix[3][1] = 825.0;
  B.matrix[3][2] = -102.0;
  B.matrix[3][3] = -455.0;

  C.matrix[0][0] = 844.0;
  C.matrix[0][1] = -584.0;
  C.matrix[0][2] = -55.0;
  C.matrix[0][3] = -53.0;
  C.matrix[1][0] = -316.0;
  C.matrix[1][1] = 472.0;
  C.matrix[1][2] = 31.0;
  C.matrix[1][3] = -171.0;
  C.matrix[2][0] = -828.0;
  C.matrix[2][1] = -376.0;
  C.matrix[2][2] = -73.0;
  C.matrix[2][3] = -802.0;
  C.matrix[3][0] = -280.0;
  C.matrix[3][1] = -729.0;
  C.matrix[3][2] = 137.0;
  C.matrix[3][3] = 456.0;
  int status = s21_sub_matrix(&A, &B, &result);
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

START_TEST(sub_3_normal) {
  int rows1 = 3, cols1 = 3;
  int rows2 = 3, cols2 = 3;
  matrix_t A = {0}, result = {0}, B = {0}, C = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows2, cols2, &B);
  s21_create_matrix(rows1, cols1, &C);
  A.matrix[0][0] = -8.0;
  A.matrix[0][1] = -6.0;
  A.matrix[0][2] = 4.0;
  A.matrix[1][0] = 9.0;
  A.matrix[1][1] = -5.0;
  A.matrix[1][2] = -8.0;
  A.matrix[2][0] = -3.0;
  A.matrix[2][1] = 0.0;
  A.matrix[2][2] = -1.0;

  B.matrix[0][0] = 12.0;
  B.matrix[0][1] = 47.0;
  B.matrix[0][2] = 86.0;
  B.matrix[1][0] = 63.0;
  B.matrix[1][1] = -73.0;
  B.matrix[1][2] = -73.0;
  B.matrix[2][0] = 40.0;
  B.matrix[2][1] = 95.0;
  B.matrix[2][2] = -56.0;

  C.matrix[0][0] = -20.0;
  C.matrix[0][1] = -53.0;
  C.matrix[0][2] = -82.0;
  C.matrix[1][0] = -54.00;
  C.matrix[1][1] = 68.0;
  C.matrix[1][2] = 65.0;
  C.matrix[2][0] = -43.0;
  C.matrix[2][1] = -95.0;
  C.matrix[2][2] = 55.0;
  int status = s21_sub_matrix(&A, &B, &result);
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

START_TEST(sub_1_calc_error) {
  int rows = 2, columns = 3, rows2 = 2, columns2 = 2;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows2, columns2, &B);
  int status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(status, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_2_incorrect) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  int status = s21_sub_matrix(&A, NULL, &result);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_3_incorrect) {
  matrix_t B = {0}, result = {0};
  s21_create_matrix(2, 2, &B);
  int status = s21_sub_matrix(NULL, &B, &result);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *test_sub_matrix(void) {
  Suite *s = suite_create("\033[42m-=S21_sub_matrix=-\033[0m");
  TCase *tc = tcase_create("s21_sub_matrix_tc");

  tcase_add_test(tc, sub_1_normal);
  tcase_add_test(tc, sub_1_calc_error);
  tcase_add_test(tc, sub_2_normal);
  tcase_add_test(tc, sub_2_incorrect);
  tcase_add_test(tc, sub_3_normal);
  tcase_add_test(tc, sub_3_incorrect);

  suite_add_tcase(s, tc);
  return s;
}
