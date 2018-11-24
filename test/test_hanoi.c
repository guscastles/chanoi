#include <CUnit/CUnit.h>
#include "hanoi_func.h"

void test_left_pin(void) {
   int *left = left_pin(0);
   left[2] = 1;
   CU_ASSERT(left[1] == 0);
   CU_ASSERT(left[2] == 1);
}

void test_right_pin(void) {
   int *right = right_pin(0);
   right[2] = 1;
   CU_ASSERT(right[1] == 0);
   CU_ASSERT(right[2] == 1);
}

void test_create_game(void) {
   const size_t number_of_discs = 3;
   List *pin_list = create_game(number_of_discs);
   CU_ASSERT_EQUAL(list_size(pin_list[LEFT_PIN]), number_of_discs);
   CU_ASSERT_EQUAL(list_size(pin_list[MIDDLE_PIN]), 0);
   CU_ASSERT_EQUAL(list_size(pin_list[RIGHT_PIN]), 0);
   CU_ASSERT_EQUAL(check_size(pin_list), NUMBER_OF_PINS);
   CU_ASSERT_EQUAL(element_at(pin_list[LEFT_PIN], 0), 3);
   CU_ASSERT_EQUAL(element_at(pin_list[LEFT_PIN], 1), 2);
   CU_ASSERT_EQUAL(element_at(pin_list[LEFT_PIN], 2), 1);
}

void test_terminate_game(void) {
   const size_t number_of_discs = 3;
   List *game = create_game(number_of_discs);
   terminate_game(game, number_of_discs);
   //CU_ASSERT_EQUAL(game, '\0');
}


List *move_pin(List *game, int start_pin, int end_pin) {
   if (list_size(game[end_pin]) == 0) {
      Tuple top = pop(game[start_pin]);
      game[start_pin] = top.list;
      game[end_pin] = append_element(game[end_pin], top.element);
   }
   return game;
 }

void test_move_first_disc(void) {
   List *game = create_game(3);
   game = move_pin(game, 0, 1);
   CU_ASSERT_EQUAL(element_at(game[1], 0), 1);
   CU_ASSERT_EQUAL(list_size(game[0]), 2);
}

