#include <malloc.h>
#include "hanoi_func.h"

int* left_pin(int position) {
    return pins.left;
}

int* right_pin(int position) {
    return pins.right;
}

int* middle_pin(int position) {
    return NULL;
}

List *create_game(const size_t number_of_discs) {
   List *pin_list = calloc(NUMBER_OF_PINS, sizeof(List));
   for (int i = 0; i < NUMBER_OF_PINS; ++i)
      pin_list[i] = create_list(0);
   for (int i = number_of_discs; i > 0; --i)
      pin_list[LEFT_PIN] = append_element(pin_list[LEFT_PIN], i);
   
   return pin_list;
}

size_t check_size(List *list) {
   List current_list = list[0];
   int counter = 0;
   while (current_list.list != NULL)
      current_list = list[++counter];
   
   return counter;
}

void terminate_game(List *game, size_t pins) {
   for (int i = 0; i < pins; ++i)
      release_list(game[i]);
   free(game);
}

