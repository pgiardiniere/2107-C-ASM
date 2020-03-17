#include <stdio.h>
#include <limits.h>     // for INT_MIX & INT_MAX calls
#include <stdlib.h>     // for exit() call

void overflowAdd() {    // Requires a,b such that...
    int a = INT_MAX;    // a >= 0   (a is Positive)
    int b = INT_MAX;    // b >= 0   (b is Positive)
    int c = a + b;

    printf("a is %d\n", a);
    printf("b is %d\n", b);
    printf("c is %d\n", c);

    // For (a,b) >= (0,0) --> (c >= a || c >= b)
    //                    --> !(c < a || c < b)
    if (c < 0)          printf("overflow (less stringent check)\n");    // works even in case of INT_MAX ++ INT_MAX, easier to grok
    if (c < a || c < b) printf("overflow (more stringent check)\n");

    // Terse detection ::
    if (a >= 0 && b >= 0 && c < 0)
        printf("overflow (less stringent check)\n");

}

void underflowAdd() {


}

void underflowSub() {   // Requires a,b such that...
    int a = INT_MIN;    // a <= 0   (a is Negative)
    int b = 1;          // b >= 0   (b is Positive)
    int c = a - b;      // **subtraction ALWAYS in a-b order.

    printf("a is %d\n", a);
    printf("b is %d\n", b);
    printf("c is %d\n", c);

    // For (a,b) : (a <= 0, b >=0 ) --> (c <= a || c <= b)
    //                              --> !(c > a || c > b)               // really, we could simplify to !(c > a)
    if (c > 0)          printf("underflow (less stringent check)\n");
    if (c > a || c > b) printf("underflow (more stringent check)\n");

}



void overflowSub() {

}




int main() {
    // overflowAdd();   // works as expected
    underflowSub();
    
    return 0;
}

