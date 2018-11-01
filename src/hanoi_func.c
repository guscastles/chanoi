#include "hanoi_func.h"
#include <regex.h>

#define NULL (int*) 0

int* left_pin(int position) {
    return pins.left;
}

int* right_pin(int position) {
    return pins.right;
}

int* middle_pin(int position) {
    return NULL;
}

