#include <stdio.h>

int main() {
    // demonstration of bit storage of signed/unsigned ints
    int x = -1;
    unsigned int y = x;
    printf("x = %d y = %u\n", x, y); // x = -1, y = 4294967295

    return 0;
}