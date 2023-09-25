#include "minunit.h" 
#include "../src/human.h"
#include "../src/board.h"
#include "../src/ships.h"
#include "../src/shoot.h"

element_t testBoard[TAM][TAM] = {
  {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
  {WATER, DESTROYER, DESTROYER, DESTROYER, WATER, WATER, WATER, WATER, WATER, WATER},
  {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
  {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
  {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
  {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
  {WATER, WATER, WATER, SUBMARIN, SUBMARIN, WATER, WATER, WATER, WATER, WATER},
  {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
  {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
  {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
};



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

MU_TEST(test_k6_is_not_invalid) {
  char move[4] = "K6";
  mu_check(!isFormatValid(move));
}

MU_TEST(test_g11_is_not_invalid) {
  char move[4] = "g11";
  mu_check(!isFormatValid(move));
}

MU_TEST(test_hit_submarin) {
  char move1[4] = "g4";
  char move2[4] = "g5";
  
  mu_check(5 == 5);
}

MU_TEST(test_hit_destroyer) {
  char move1[4] = "b2";
  char move2[4] = "b3";
  char move3[4] = "b4";
  
  mu_check(4 == 4);
}

MU_TEST(test_hit_aircraft) {
  char move1[4] = "c1";
  char move2[4] = "d1";
  char move3[4] = "e1";
  char move4[4] = "f1";
  char move5[4] = "g1";
  
  mu_check(2 == 2);
}

MU_TEST(test_hit_tanker) {
  char move1[4] = "j7";
  char move2[4] = "j8";
  char move3[4] = "j9";
  char move4[4] = "j9";
  
  mu_check(6 == 6);
}

MU_TEST_SUITE(test_deny_not_invalid_moves) {
  MU_RUN_TEST(test_k6_is_not_invalid);
  MU_RUN_TEST(test_g11_is_not_invalid);
  MU_RUN_TEST(test_hit_submarin);
  MU_RUN_TEST(test_hit_destroyer);
  MU_RUN_TEST(test_hit_aircraft);
  MU_RUN_TEST(test_hit_tanker);
}

int main() {
  MU_RUN_SUITE(test_suite_str_to_chute_t);
  MU_RUN_SUITE(test_deny_not_invalid_moves);
  MU_RUN_SUITE(test_suite_isEqual_tests);

  MU_REPORT();
  return MU_EXIT_CODE;
}