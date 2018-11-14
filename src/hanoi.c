#include <stdio.h>
#include <malloc.h>
#include "hanoi_func.h"

int main(int argc, char **argv) {
    List *game = create_game(3);
    printf("Tower of Hanoi game with %ld discs has been created!\n\n", check_size(game));
    terminate_game(game, 3);
    return 0;
}

