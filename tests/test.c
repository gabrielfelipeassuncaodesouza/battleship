#include "minunit.h" 
#include "../src/human.h"

/** private functions to test **/

int assert_chute(chute_t c1, chute_t c2) {
  return c1.x == c2.x && c1.y == c2.y;
}

/** tests converting strings to struct chute_t **/

MU_TEST(test_convert_a2_to_01) {
  char str_test[4] = "a2";
  chute_t expecetd = {
    0,
    1
  };

  chute_t result = strToChute(str_test);
  mu_check(assert_chute(expecetd, result));
}

MU_TEST_SUITE(test_suite_str_to_chute_t) {
  MU_RUN_TEST(test_convert_a2_to_01);
}

/** tests checking for invalid moves **/

MU_TEST(test_e6_is_invalid) {
  char move[4] = "E6";

  mu_check(!isFormatValid(move));
}

MU_TEST_SUITE(test_deny_invalid_moves) {
  MU_RUN_TEST(test_e6_is_invalid);
}

int main() {
  MU_RUN_SUITE(test_suite_str_to_chute_t);
  MU_RUN_SUITE(test_deny_invalid_moves);

  MU_REPORT();
  return MU_EXIT_CODE;
}
