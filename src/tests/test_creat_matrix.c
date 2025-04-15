#include <time.h>

#include "s21_matrix_tests.h"

START_TEST(creat_1_normal) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(creat_2_both_size_less) {
  int rows = -1, columns = -1;
  matrix_t A = {0};
  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.matrix == NULL, 1);
}
END_TEST

START_TEST(creat_3_rows_less) {
  int rows = 0, columns = 7;
  matrix_t A = {0};
  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.matrix == NULL, 1);
}
END_TEST

START_TEST(creat_4_columns_less) {
  int rows = 5, columns = 0;
  matrix_t A = {0};
  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.matrix == NULL, 1);
}
END_TEST

START_TEST(creat_5_no_matrix) {
  int rows = 5, columns = 7;
  int res = s21_create_matrix(rows, columns, NULL);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

Suite *test_creat_matrix(void) {
  Suite *s = suite_create("\033[42m-=S21_creat_matrix=-\033[0m");
  TCase *tc = tcase_create("s21_creat_matrix_tc");

  tcase_add_test(tc, creat_1_normal);
  tcase_add_test(tc, creat_2_both_size_less);
  tcase_add_test(tc, creat_3_rows_less);
  tcase_add_test(tc, creat_4_columns_less);
  tcase_add_test(tc, creat_5_no_matrix);

  suite_add_tcase(s, tc);
  return s;
}
