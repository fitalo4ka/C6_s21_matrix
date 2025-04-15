#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "s21_matrix_tests.h"

START_TEST(deter_1) {
  int result = s21_determinant(NULL, NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(deter_2) {
  matrix_t A;
  double det;
  s21_create_matrix(10, 10, &A);
  A.rows = 0;
  int res = s21_determinant(&A, &det);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(deter_3) {
  matrix_t A;
  double det;
  s21_create_matrix(10, 9, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(deter_4) {
  matrix_t A;
  double det;
  double det_true = 984.1238;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 984.1238;
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+08);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(deter_5) {
  matrix_t A;
  double det;
  double det_true = -347879921061.4686565;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 18248.2488;
  A.matrix[0][1] = 91293.124898;
  A.matrix[0][2] = 300.1;
  A.matrix[1][0] = 390.1123;
  A.matrix[1][1] = 44.5;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 1238.4;
  A.matrix[2][2] = 9999.99;

  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+06);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(deter_6) {
  matrix_t A;
  double det;
  double det_true = -40;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+06);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(deter_7) {
  matrix_t A;
  double det;
  double det_true = -1369800;
  s21_create_matrix(5, 5, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[0][4] = 5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 7;
  A.matrix[1][2] = 8;
  A.matrix[1][3] = 9;
  A.matrix[1][4] = 10;
  A.matrix[2][0] = 11;
  A.matrix[2][1] = 12;
  A.matrix[2][2] = 49;
  A.matrix[2][3] = 14;
  A.matrix[2][4] = 15;
  A.matrix[3][0] = 161;
  A.matrix[3][1] = 17;
  A.matrix[3][2] = 18;
  A.matrix[3][3] = 19;
  A.matrix[3][4] = 20;
  A.matrix[4][0] = 64;
  A.matrix[4][1] = 48;
  A.matrix[4][2] = 1;
  A.matrix[4][3] = 2;
  A.matrix[4][4] = 3;
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+06);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(deter_8) {
  matrix_t A;
  double det;
  double det_true = 17187;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 9;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 96;
  A.matrix[1][1] = 1931;
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+06);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_determinant(void) {
  Suite *s = suite_create("\033[42m-=S21_determinant=-\033[0m");
  TCase *tc = tcase_create("s21_determinant_tc");

  tcase_add_test(tc, deter_1);
  tcase_add_test(tc, deter_2);
  tcase_add_test(tc, deter_3);
  tcase_add_test(tc, deter_4);
  tcase_add_test(tc, deter_5);
  tcase_add_test(tc, deter_6);
  tcase_add_test(tc, deter_7);
  tcase_add_test(tc, deter_8);

  suite_add_tcase(s, tc);
  return s;
}