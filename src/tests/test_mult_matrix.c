#include <time.h>

#include "s21_matrix_tests.h"

START_TEST(multi_mtx_1_incorrect) {
  matrix_t A;
  int result = s21_mult_matrix(NULL, &A, &A);
  ck_assert_int_eq(result, INCORRECT_MATRIX);
}
END_TEST

START_TEST(multi_mtx_2_incorrect) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &B);
  A.rows = 0;
  int result = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(multi_mtx_3_calc_error) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &B);
  int result = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(multi_mtx_4_normal) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);
  s21_create_matrix(2, 2, &C);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 6.0;
  A.matrix[1][2] = 7.0;

  B.matrix[0][0] = 3.0;
  B.matrix[0][1] = 7.0;
  B.matrix[1][0] = 10.0;
  B.matrix[1][1] = 14.0;
  B.matrix[2][0] = 17.0;
  B.matrix[2][1] = 21.0;

  C.matrix[0][0] = 74;
  C.matrix[0][1] = 98;
  C.matrix[1][0] = 191;
  C.matrix[1][1] = 259;
  int res = s21_mult_matrix(&A, &B, &D);
  ck_assert_int_eq(s21_eq_matrix(&D, &C), 1);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(multi_mtx_5_normal) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &C);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 6.0;
  A.matrix[1][2] = 7.0;
  A.matrix[2][0] = 8.0;
  A.matrix[2][1] = 9.0;
  A.matrix[2][2] = 10.0;

  B.matrix[0][0] = 3.0;
  B.matrix[0][1] = 7.0;
  B.matrix[0][2] = 10.0;
  B.matrix[1][0] = 14.0;
  B.matrix[1][1] = 17.0;
  B.matrix[1][2] = 21.0;
  B.matrix[2][0] = 24.0;
  B.matrix[2][1] = 28.0;
  B.matrix[2][2] = 31.0;

  C.matrix[0][0] = 103.0;
  C.matrix[0][1] = 125.0;
  C.matrix[0][2] = 145.0;
  C.matrix[1][0] = 264.0;
  C.matrix[1][1] = 326.0;
  C.matrix[1][2] = 383.0;
  C.matrix[2][0] = 390.0;
  C.matrix[2][1] = 489.0;
  C.matrix[2][2] = 579.0;
  int res = s21_mult_matrix(&A, &B, &D);
  ck_assert_int_eq(s21_eq_matrix(&C, &D), 1);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

Suite *test_mult_matrix(void) {
  Suite *s = suite_create("\033[42m-=S21_mult_matrix=-\033[0m");
  TCase *tc = tcase_create("s21_mult_matrix_tc");

  tcase_add_test(tc, multi_mtx_1_incorrect);
  tcase_add_test(tc, multi_mtx_2_incorrect);
  tcase_add_test(tc, multi_mtx_3_calc_error);
  tcase_add_test(tc, multi_mtx_4_normal);
  tcase_add_test(tc, multi_mtx_5_normal);

  suite_add_tcase(s, tc);
  return s;
}