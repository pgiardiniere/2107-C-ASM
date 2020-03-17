#include <stdio.h>
#include <limits.h>     // for INT_MIX & INT_MAX calls
#include <stdlib.h>     // for exit() call

int add (int a, int b) {
    int c = a + b;
    if (a >= 0 && b >= 0 && c < a) {      // do  a+b, if c<a, then we overflowed
        printf("Overflow\n"); return(0);
    }

    // **********  This block is redundant  **********
    // else if (a >= 0 && b <= 0 && c > a) { // do  a-b, if c>a, then we underflowed
    //     printf("Underflow\n"); return(0);
    // }

    // else if (a <= 0 && b >= 0 && c < a) { // do -a+b, if c<a, then we overflowed
    //     printf("Overflow\n"); return(0);
    // }
    // ***********************************************

    else if (a <= 0 && b <= 0 && c > a) { // do -a-b, if c>a, then we underflowed
        printf("Underflow\n"); return(0);
    }

    else {
        printf("Calculation is in-bounds. Result is %d\n", c);
        return c;
    }
}

int sub (int a, int b) {
    int c = a - b;
    // Redundant :: pos - pos CAN'T underflow
    // if (a >= 0 && b >= 0 && c < a) {
    //     printf("Overflow\n"); return(0);
    // }

    if (a >= 0 && b <= 0 && c < a) {      // do  a+b, if c<a, then we overflowed
        printf("Overflow\n"); return(0);
    }

    else if (a <= 0 && b >= 0 && c > a) { // do -a-b, if c>a, then we underflowed
        printf("Underflow\n"); return(0);
    }

    // Redundant :: neg - neg CAN'T overflow
    // else if (a <= 0 && b <= 0 && c > a) { // do -a+b, if c>a, then we underflowed
    //     printf("Underflow\n"); return(0);
    // }

    else {
        printf("Calculation is in-bounds. Result is %d\n", c);
        return c;
    }
}

void testAdd() {
    int a; int b; int c;
    // Case :: a Pos, b Pos
    a = INT_MAX;
    b = INT_MAX;
    add(a, b);
    // Case :: a Pos, b Neg
    a = 0;
    b = INT_MIN;
    add(a, b);
    // Case :: a Neg, b Pos
    a = INT_MIN;
    b = 0;
    add(a, b);
    // Case :: a Neg, b Neg
    a = INT_MIN;
    b = INT_MIN;
    add(a, b);
}

void testSub() {
    int a; int b; int c;
    // Case :: a Pos, b Pos
    a = INT_MAX;
    b = INT_MAX;
    sub(a, b);                  // Expect ::  0             Actual ::  0
    // Case :: a Pos, b Neg
    a = 0;
    b = INT_MIN;
    sub(a, b);                  // Expect :: Overflow       Actual :: Overflow
    // Case :: a Neg, b Pos
    a = INT_MIN;
    b = 1;
    sub(a, b);                  // Expect :: Underflow      Actual :: Underflow
    // Case :: a Neg, b Neg
    a = INT_MIN;
    b = INT_MIN;
    sub(a, b);                  // Expect :: 0              Actual :: 0
}

int main() {
    testAdd(); printf("\n");
    testSub(); printf("\n");

    return 0;
}