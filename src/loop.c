#include <stdio.h>
#include <malloc.h>

void loop(long max, long next) {
    if (next < max) {
	char *str = malloc(200);
	sprintf(str, "Next value is %ld", next);
	printf("%s\n", str);
	free(str);
	loop(max, next + 1);
    }
}

int main(void) {
    loop(174301, 0);
    return 0;
}
