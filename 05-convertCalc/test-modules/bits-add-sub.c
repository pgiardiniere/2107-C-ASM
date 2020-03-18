#include <stdio.h>
#include <limits.h>     // for INT_MIX & INT_MAX calls
#include <stdlib.h>     // for exit() call

int add (int a, int b) {
    // Do the bitwise addition
    int x = a;              // required as we're doing bit ops, but want to check against initial vals later.
    int y = b;
    int carry;
    while (y != 0) {
        carry = x & y;      // Get  all the 1s which will go left one position (i.e. that sum to 2)
        x =     x ^ y;      // Save the  0s/1s which stay in current  position
        y = carry << 1;     // Push all carried 1s left
    }
    int c = x;

    // Detect whether we over/underflowed. If not, return result.
    if (a >= 0 && b >= 0 && c < a) {
        printf("Overflow\n"); return(0);
    }
    else if (a <= 0 && b <= 0 && c > a) {
        printf("Underflow\n"); return(0);
    }
    else {
        printf("Calculation is in-bounds. Result is %d\n", c);
        return c;
    }
}

int _add (int a, int b) {
    int x = a;
    int y = b;
    int carry;
    while (y & 0xFFFFFFFF) {    // while y has ANY non-zero 1 bits
        carry = x & y;
        x =     x ^ y;
        y = carry << 1;
    }
    int c = x;

    // Detect Underflow
    // Maximum possible underflow (INT_MIN + INT_MIN) yields 0. Min underflow is INT_MAX. Thus underflow -> c:Positive (0 <= c <= INT_MAX)
    int aNonPositive = a & INT_MIN;
    int bNonPositive = a & INT_MIN;
    x = c;
    x = ~x;                     // bitwise negate, if X was positive (underflow), make negative
    x = x >> 31;                // get x most significant digit
    if (aNonPositive)
        if (bNonPositive)
            if (x) { printf("Underflow\n"); return(0); }    // If X had overflowed, 

    // Detect Overflow
    // Maximum possible overflow (INT_MAX + INT_MAX) yields -2. Min overflow is INT_MIN. Thus underflow -> c:Negative (INT_MIN <= c <= -2)
    int aNonNegative; if (aNonPositive) aNonNegative = 0;   // if (a <= 0), then !(a > 0)
    int bNonNegative; if (aNonPositive) bNonNegative = 0;
    x = c;
    x = x >> 31;
    if (aNonNegative)
        if (bNonNegative)
            if (x) { printf("Overflow\n"); return(0); }

    printf("Calculation is in-bounds. Result is %d\n", c);
    return c;
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

    add(10000023, 1235456);

    // // Over/Underflow bounds testing
    // add(INT_MAX, 1);
    // add(INT_MIN, -1);
    // add(INT_MIN, INT_MIN);
    // add(INT_MAX, INT_MAX);

    printf("\n");

    _add(10000023, 1235456);

    // // Over/Underflow bounds testing
    // _add(INT_MAX, 1);
    // _add(INT_MIN, -1);
    // _add(INT_MIN, INT_MIN);
    // _add(INT_MAX, INT_MAX);

    return 0;
}