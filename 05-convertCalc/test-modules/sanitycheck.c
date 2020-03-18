#include <stdio.h>
#include <limits.h>

int main() {
    // // Max possible addition underflow
    int x = INT_MIN;
    int y = INT_MIN;
    // int c = x + y;
    // printf("result is %d\n", c);

    // // Max possible addition overflow
    // x = INT_MAX;
    // y = INT_MAX;
    // c = x + y;
    // printf("result is %d\n", c);

    // Check :: Is x negative?
    x = -1;
    printf("x is %d\n", x);
    x <<= 31;
    printf("x is %d\n", x);
    if (x == INT_MIN) printf("yep it's int_min alright\n");
    
    // x >>= 31;
    // x >>= 1;
    // x >>= 1;

    int minBitNot = ~(INT_MIN);
    printf("INT_MIN bitwise Not is %d\n", minBitNot);
    int zerBitNot = ~(0);
    printf("0       bitwise Not is %d\n", zerBitNot);

    if (zerBitNot == 0xFFFFFFFF) printf("IT'S FULL UP MY DUDE\n");
    if (minBitNot == INT_MAX) printf("It's flipped over my dude\n");

    return 0;
}