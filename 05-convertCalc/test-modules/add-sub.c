#include <stdio.h>
#include <limits.h>     // for INT_MIX & INT_MAX calls
#include <stdlib.h>     // for exit() call

int add (int a, int b) {
    int c = a + b;
    if (a >= 0 && b >= 0 && c < a) { // do  a+b, if c<a, then we overflowed
        printf("Overflow\n"); return(0);
    }

    else if (a >= 0 && b <= 0 && c > a) { // do  a-b, if c>a, then we underflowed
        printf("Underflow\n"); return(0);
    }

    else if (a <= 0 && b >= 0 && c < a) { // do -a+b, if c<a, then we overflowed
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
    int c = a + b;

}

int main() {
    // Testing :: Order of submissions
    // a >= 0, b >= 0   (a Pos, b Pos)
    // a >= 0, b <= 0   (a Pos, b Neg)
    // a <= 0, b >= 0   (a Neg, b Pos)
    // a <= 0, b <= 0   (a Neg, b Neg)
    int a; int b;
    
    a = INT_MAX;
    b = INT_MAX;
    add(a, b);      // a + b  Should be  4 mil   Will overflow,   -(something)
    // sub(a, b)    // a - b  Should be  0
    
    a = INT_MAX;    // a + b  Should be  -1
    b = INT_MIN;    // a - b  Should be  4 mil   Will underflow,  -(something)
    add(a, b);
    // sub(a, b)

    a = INT_MIN;    // a + b  Should be  -1
    b = INT_MAX;    // a - b  Should be  -4 mil  Will underflow,  +(something)
    add(a, b);
    // sub(a, b)

    a = INT_MIN;    // a + b  Should be   -4 mil  Will underflow, +(something)
    b = INT_MIN;    // a - b  Should be   0
    add(a, b);
    // sub(a, b)

    return 0;
}