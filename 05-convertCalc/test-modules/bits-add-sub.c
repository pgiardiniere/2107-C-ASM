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

    // detect whether a, b are >= 0
    int aNonPositive = a & INT_MIN;
    int bNonPositive = a & INT_MIN;

    printf("Calculation in/out of bounds. Result is %d\n", c);
    // DETECT OVERFLOW
    int aNonNegative = a & INT_MIN;
    int bNonNegative = b & INT_MIN;
    // determine whether A has a higher significant digit than C. If so, then (a > c). Implies Overflow. 
    x = c;
    y = a;
    while (x) {
        while (y) {
            x >>= 1;
            y >>= 1;
        }
    }
    if (aNonNegative)
        if (bNonNegative)
            if (y) 
                { printf("Overflow\n"); return(0); }

    // // DETECT UNDERFLOW
    // int aNonPositive = a & INT_MIN;
    // int bNonPositive = a & INT_MIN;
    // // Maximum possible underflow (INT_MIN + INT_MIN) yields result of 0. Thus if we underflow, result C is non-negative.
    // x = c;
    // x = ~x;                     // bitwise negate, if X was positive (underflow), make negative
    // x = x >> 31;                // get x most significant digit
    // x = x & 1;                  // expect :: 1 if we underflowed. 0 If operation successful.
    // if (aNonPositive)
    //     if (bNonPositive)
    //         if (x) { printf("Underflow\n"); return(0); }    // If X had overflowed, 

    // Return Result
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
    add(2, 1);
    add(10, 5);
    add(INT_MAX, 1);
    add(INT_MIN, -1);

    printf("\n");

    _add(2, 1);
    _add(10, 5);
    _add(INT_MAX, 1);
    _add(INT_MIN, -1);

    return 0;
}