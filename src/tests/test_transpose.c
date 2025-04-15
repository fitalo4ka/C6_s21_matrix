#include <time.h>

#include "s21_matrix_tests.h"

START_TEST(transpose_1) {
  matrix_t A;
  int res = s21_transpose(NULL, &A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 10, &A);
  A.rows = 0;
  int res = s21_transpose(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &C);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  C.matrix[0][0] = 1;
  C.matrix[0][1] = 4;
  C.matrix[1][0] = 2;
  C.matrix[1][1] = 5;
  C.matrix[2][0] = 3;
  C.matrix[2][1] = 6;
  int res = s21_transpose(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&C, &B), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(transpose_4) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  C.matrix[0][0] = 1;
  C.matrix[0][1] = 4;
  C.matrix[0][2] = 7;
  C.matrix[1][0] = 2;
  C.matrix[1][1] = 5;
  C.matrix[1][2] = 8;
  C.matrix[2][0] = 3;
  C.matrix[2][1] = 6;
  C.matrix[2][2] = 9;
  int res = s21_transpose(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&C, &B), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(transpose_5) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &C);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 6;

  C.matrix[0][0] = 1;
  C.matrix[0][1] = 3;
  C.matrix[0][2] = 5;
  C.matrix[1][0] = 2;
  C.matrix[1][1] = 4;
  C.matrix[1][2] = 6;
  int res = s21_transpose(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&C, &B), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

Suite *test_transpose(void) {
  Suite *s = suite_create("\033[42m-=S21_transpose=-\033[0m");
  TCase *tc = tcase_create("s21_transpose_tc");

  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_3);
  tcase_add_test(tc, transpose_4);
  tcase_add_test(tc, transpose_5);

  suite_add_tcase(s, tc);
  return s;
}