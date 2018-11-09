#include <stdio.h>
#include <malloc.h>
#include "hanoi_func.h"

void release_game(List *game, size_t pins) {
   for (int i = 0; i < pins; ++i)
      release_list(game[i]);
   free(game);
}

int main(int argc, char *argv) {
    List *game = create_game(3);
    printf("Tower of Hanoi game with %ld discs has been created!\n\n", check_size(game));
    release_game(game, 3);
    return 0;
}

