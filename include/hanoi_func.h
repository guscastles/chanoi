#include <list.h>
#define LEFT_PIN 0
#define MIDDLE_PIN 1
#define RIGHT_PIN 2
#define NUMBER_OF_PINS 3

struct Pin {
    int left[3];
    int middle[3];
    int right[3];
} pins;

int* left_pin(int position);

int* right_pin(int position);

List *create_game(const size_t number_of_discs);

size_t check_size(List *list);
 
void terminate_game(List *game, size_t pins);

