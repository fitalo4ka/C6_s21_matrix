#include "s21_matrix_tests.h"
int main() {
  int failed = 0;
  Suite *s21_matrix_tests[] = {test_creat_matrix(),
                               test_sub_matrix(),
                               test_sum_matrix(),
                               test_mult_number(),
                               test_transpose(),
                               test_determinant(),
                               test_mult_matrix(),
                               test_calc_complements(),
                               test_inverse_matrix(),
                               test_equal_matrix(),
                               NULL};
  for (int i = 0; s21_matrix_tests[i] != NULL; i++) {
    printf("\033[46m/start\033[0m ");
    SRunner *sr = srunner_create(s21_matrix_tests[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);
  return failed == 0 ? 0 : 1;
}
