#include "minunit.h" 
#include "../src/human.h"
#include "../src/board.h"
#include "../src/ships.h"

/** private functions to test **/

int assert_chute(chute_t c1, chute_t c2) {
  return c1.x == c2.x && c1.y == c2.y;
}

/** tests for isEqual function **/

MU_TEST(test_if_two_structs_are_the_same) {
  element_t s1 = { 2, 'S', 'H' };
  element_t s2 = { 2, 'S', 'H' };

  mu_check(isEqual(s1, s2));
}

MU_TEST_SUITE(test_suite_isEqual_tests) {
  MU_RUN_TEST(test_if_two_structs_are_the_same);
}

/** tests converting strings to struct chute_t **/

MU_TEST(test_convert_a1_to_00) {
  char str_test[4] = "a1";
  chute_t expecetd = {
    0,
    0
  };

  chute_t result = strToChute(str_test);
  mu_check(assert_chute(expecetd, result));
}

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
  MU_RUN_TEST(test_convert_a1_to_00);
}

/** tests checking for invalid moves **/

MU_TEST(test_k6_is_invalid) {
  char move[4] = "K6";
  mu_check(!isFormatValid(move));
}

MU_TEST(test_g11_is_invalid) {
  char move[4] = "g11";
  mu_check(!isFormatValid(move));
}

MU_TEST_SUITE(test_deny_invalid_moves) {
  MU_RUN_TEST(test_k6_is_invalid);
  MU_RUN_TEST(test_g11_is_invalid);
}

int main() {
  MU_RUN_SUITE(test_suite_str_to_chute_t);
  MU_RUN_SUITE(test_deny_invalid_moves);
  MU_RUN_SUITE(test_suite_isEqual_tests);

  MU_REPORT();
  return MU_EXIT_CODE;
}
