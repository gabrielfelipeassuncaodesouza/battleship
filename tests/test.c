#include "minunit.h"
#include "../src/board.h"
#include "../src/human.h"
#include "../src/ia.h"
#include "../src/render.h"
#include "../src/ships.h"
#include "../src/stack.h"

#include <stdlib.h>
#include <time.h>

/** private functions to test **/

element_t board[TAM][TAM] = {
    { WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER },
    { WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER },
    { WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER },
    { WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER },
    { WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER },
    { WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER },
    { WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER },
    { WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER },
    { WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER },
    { WATER, WATER, WATER, WATER, WATER, ERROR, WATER, WATER, WATER, WATER },
};

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

/** Queue functionality **/

MU_TEST(test_adding_on_stack) {
  stack_t *head = NULL;

  add(&head, (chute_t){1, 0});

  mu_assert_int_eq(head->hit.x, 1);
  mu_assert_int_eq(head->hit.y, 0);
}

MU_TEST(test_removing_on_stack) {
  stack_t *head = NULL;

  add(&head, (chute_t){1, 0});
  add(&head, (chute_t){12, -2});
  add(&head, (chute_t){4, 2});
  add(&head, (chute_t){6, 7});

  rem(&head);

  mu_assert_int_eq(head->hit.x, 4);
  mu_assert_int_eq(head->hit.y, 2);
}

MU_TEST_SUITE(test_stack_functionality) {
  MU_RUN_TEST(test_adding_on_stack);
  MU_RUN_TEST(test_removing_on_stack);
}

MU_TEST(test_if_iaput_works) {
  chute_t test;
  int xlim = TAM, ylim = TAM;

  for(int i = 0; i < 10000; i++) {
    test = iaPut(xlim, ylim);
    mu_check(test.x < xlim && test.x >= 0);
    mu_check(test.y < ylim && test.y >= 0);
  }
}

MU_TEST(test_iaput_with_variable_limits) {
  chute_t test;
  int i, j;
  for(int i = 1; i < 1000; i++) {
    for(int j = (rand() % i); j <= i; j++) {
      if(j == 0) j = 1;

      test = iaPut(i, j);
      mu_check(test.x < i && test.x >= 0);
      mu_check(test.y < j && test.y >= 0);
    }
  }
}

MU_TEST(test_iadir_function) {
  char ret;
  for(int i = 0; i < 10000; i++) {
    ret = iaDir();
    mu_check(ret == 'H' || ret == 'V');
  }
}

MU_TEST(test_getneighbours_function_bottom_of_board) {
  stack_t* test = NULL;

  getNeighbours(board, &test, (chute_t){ 9, 4});
  chute_t expected[3] = { (chute_t){9, 5}, (chute_t){ 9, 3}, (chute_t){8, 4} };

  int i = 0;
  for(stack_t* aux = test; aux != NULL; aux = aux->next) {
    mu_check(assert_chute(aux->hit, expected[i++]));
  }
}

MU_TEST(test_getneighbours_function_top_of_board) {
  stack_t* test = NULL;

  getNeighbours(board, &test, (chute_t){ 0, 4});
  chute_t expected[3] = { (chute_t){ 0, 5}, (chute_t){1, 4}, (chute_t){0, 3} };

  int i = 0;
  for(stack_t* aux = test; aux != NULL; aux = aux->next) {
    mu_check(assert_chute(aux->hit, expected[i++]));
  }
}

MU_TEST(test_getneighbours_function_center_of_board) {
  stack_t* test = NULL;

  getNeighbours(board, &test, (chute_t){ 4, 2});
  chute_t expected[4] = { (chute_t){ 4, 3}, (chute_t){5, 2}, (chute_t){4, 1}, (chute_t){3, 2} };

  int i = 0;
  for(stack_t* aux = test; aux != NULL; aux = aux->next) {
    mu_check(assert_chute(aux->hit, expected[i++]));
  }
}

MU_TEST_SUITE(test_ia_functions) {
  MU_RUN_TEST(test_if_iaput_works);
  MU_RUN_TEST(test_iaput_with_variable_limits);
  MU_RUN_TEST(test_iadir_function);
  MU_RUN_TEST(test_getneighbours_function_center_of_board);
  MU_RUN_TEST(test_getneighbours_function_top_of_board);
  MU_RUN_TEST(test_getneighbours_function_bottom_of_board);
}

int main() {
  srand(time(NULL));

  MU_RUN_SUITE(test_suite_str_to_chute_t);
  MU_RUN_SUITE(test_deny_invalid_moves);
  MU_RUN_SUITE(test_suite_isEqual_tests);
  MU_RUN_SUITE(test_stack_functionality);

  MU_RUN_SUITE(test_ia_functions);

  MU_REPORT();
  return MU_EXIT_CODE;
}
