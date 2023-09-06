#include "minunit.h" 

MU_TEST(check_if_7_is_equal_8) {
  mu_check(5 == 7);
}

MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(check_if_7_is_equal_8);
}

int main() {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
