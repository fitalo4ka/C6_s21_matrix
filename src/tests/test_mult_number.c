#include <time.h>

#include "s21_matrix_tests.h"

START_TEST(num_mul_0_normal) {
  int rows1 = 2, cols1 = 3;
  matrix_t A = {0}, result = {0}, B = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows1, cols1, &B);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = -6.0;

  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 10.0;
  B.matrix[0][2] = 15.0;
  B.matrix[1][0] = 20.0;
  B.matrix[1][1] = 25.0;
  B.matrix[1][2] = -30.0;
  int status = s21_mult_number(&A, 5.0, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(num_mul_1_normal) {
  int rows1 = 2, cols1 = 2;
  matrix_t A = {0}, result = {0}, B = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows1, cols1, &B);
  A.matrix[0][0] = 121239.113;
  A.matrix[0][1] = 2401.12392;
  A.matrix[1][0] = -348901.2;
  A.matrix[1][1] = 2389014;

  B.matrix[0][0] = 375841.2503;
  B.matrix[0][1] = 7443.484152;
  B.matrix[1][0] = -1081593.72;
  B.matrix[1][1] = 7405943.4;

  int status = s21_mult_number(&A, 3.1, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(num_mul_2_normal) {
  int rows1 = 5, cols1 = 2;
  matrix_t A = {0}, result = {0}, B = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows1, cols1, &B);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 1.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[2][0] = 0.0;
  A.matrix[2][1] = -1.0;
  A.matrix[3][0] = 1.0;
  A.matrix[3][1] = 1.0;
  A.matrix[4][0] = 0.0;
  A.matrix[4][1] = 1.0;

  B.matrix[0][0] = -1990.8087;
  B.matrix[0][1] = 1990.8087;
  B.matrix[1][0] = 1990.8087;
  B.matrix[1][1] = 0.0;
  B.matrix[2][0] = 0.0;
  B.matrix[2][1] = -1990.8087;
  B.matrix[3][0] = 1990.8087;
  B.matrix[3][1] = 1990.8087;
  B.matrix[4][0] = 0.0;
  B.matrix[4][1] = 1990.8087;

  int status = s21_mult_number(&A, 1990.8087, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(num_mul_3_normal) {
  int rows1 = 3, cols1 = 3;
  matrix_t A = {0}, result = {0}, B = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows1, cols1, &B);
  A.matrix[0][0] = 121239.122013;
  A.matrix[0][1] = 2401.12392;
  A.matrix[0][2] = -348901.2;
  A.matrix[1][0] = 2389014;
  A.matrix[1][1] = 912039.12389;
  A.matrix[1][2] = 129034.23400;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 1203;
  A.matrix[2][2] = 9000000.123;

  B.matrix[0][0] = 473063415.139012752;
  B.matrix[0][1] = 9368955.02794368;
  B.matrix[0][2] = -1361378987.8848;
  B.matrix[1][0] = 9321703282.656;
  B.matrix[1][1] = 3558689105.66288656;
  B.matrix[1][2] = 503479193.781536;
  B.matrix[2][0] = 0;
  B.matrix[2][1] = 4693990.512;
  B.matrix[2][2] = 35117136479.934192;

  int status = s21_mult_number(&A, 3901.904, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_num_1_incorrect) {
  matrix_t R = {0};
  int status = s21_mult_number(NULL, 2, &R);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&R);
}
END_TEST

Suite *test_mult_number(void) {
  Suite *s = suite_create("\033[42m-=S21_mult_number=-\033[0m");
  TCase *tc = tcase_create("s21_mult_number_tc");

  tcase_add_test(tc, mul_num_1_incorrect);
  tcase_add_test(tc, num_mul_0_normal);
  tcase_add_test(tc, num_mul_1_normal);
  tcase_add_test(tc, num_mul_2_normal);
  tcase_add_test(tc, num_mul_3_normal);

  suite_add_tcase(s, tc);
  return s;
}