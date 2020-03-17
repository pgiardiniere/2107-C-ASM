#include <stdio.h>
#include <limits.h>     // for INT_MIX & INT_MAX calls
#include <stdlib.h>     // for exit() call

int add (int a, int b) {
    // Do the bitwise addition
    int c;

    // Detect whether we over/underflowed. If not, return result.
    if (a >= 0 && b >= 0 && c < a) {      // do  a+b, if c<a, then we overflowed
        printf("Overflow\n"); return(0);
    }
    else if (a <= 0 && b <= 0 && c > a) { // do -a-b, if c>a, then we underflowed
        printf("Underflow\n"); return(0);
    }
    else {
        printf("Calculation is in-bounds. Result is %d\n", c);
        return c;
    }
}

int sub (int a, int b) {
    // Do the bitwise subtraction
    int c;

    // Detect whether we over/underflowed. If not, return result.
    if (a >= 0 && b <= 0 && c < a) {
        printf("Overflow\n"); return(0);
    }
    else if (a <= 0 && b >= 0 && c > a) {
        printf("Underflow\n"); return(0);
    }
    else {
        printf("Calculation is in-bounds. Result is %d\n", c);
        return c;
    }
}

int main() {

    return 0;
}