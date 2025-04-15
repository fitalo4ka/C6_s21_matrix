#include <time.h>

#include "s21_matrix_tests.h"

START_TEST(inverse_1_calc_error) {
  int res = s21_inverse_matrix(NULL, NULL);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(inverse_2_incorrect) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 10, &A);
  A.rows = 0;
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_3_calc_error) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 9, &A);
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_4_normal) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &C);
  A.matrix[0][0] = 42.12849;
  C.matrix[0][0] = 1 / 42.12849;
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&B, &C), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_5_normal) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  C.matrix[0][0] = 1;
  C.matrix[0][1] = -1;
  C.matrix[0][2] = 1;
  C.matrix[1][0] = -38;
  C.matrix[1][1] = 41;
  C.matrix[1][2] = -34;
  C.matrix[2][0] = 27;
  C.matrix[2][1] = -29;
  C.matrix[2][2] = 24;
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&B, &C), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_6_calc_error) {
  matrix_t A;
  matrix_t B;
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
  A.matrix[2][2] = 13;
  A.matrix[2][3] = 14;
  A.matrix[2][4] = 15;
  A.matrix[3][0] = 16;
  A.matrix[3][1] = 17;
  A.matrix[3][2] = 18;
  A.matrix[3][3] = 19;
  A.matrix[3][4] = 20;
  A.matrix[4][0] = 21;
  A.matrix[4][1] = 22;
  A.matrix[4][2] = 23;
  A.matrix[4][3] = 24;
  A.matrix[4][4] = 25;
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_inverse_matrix(void) {
  Suite *s = suite_create("\033[42m-=S21_inverse_matrix=-\033[0m");
  TCase *tc = tcase_create("s21_inverse_matrix_tc");

  tcase_add_test(tc, inverse_1_calc_error);
  tcase_add_test(tc, inverse_2_incorrect);
  tcase_add_test(tc, inverse_3_calc_error);
  tcase_add_test(tc, inverse_4_normal);
  tcase_add_test(tc, inverse_6_calc_error);
  tcase_add_test(tc, inverse_5_normal);

  suite_add_tcase(s, tc);
  return s;
}