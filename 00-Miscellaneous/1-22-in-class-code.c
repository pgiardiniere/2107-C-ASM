#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#define      PI = 3.14159            // escape sequence (i think)  -- maximally efficient (but weird)
const double Pi = 3.14159;           // const ---                  -- behaves exactly like 'final' in Java

enum Colors {Red, Green, Blue};

int main() {
    // exploration of datatypes and such
    char c = 97;
    char s[] = "128";

    int n = atoi(s);                    // atoi == Ascii TO Integer
    float f = atof(s);                  // atof == Ascii TO Float

    printf("c = %c\n", c);
    printf("s = %s, %.2f \n", s, f);       //.02 is optional, specifies 2 decimal points of precision

    enum Colors col = Green;
    // stuff

    int a = 0;
    int b = 2;
    if (a) printf("it's false yo\n");
    if (b) printf("it's true  yo\n");

    // short circuiting example, if first term evaluates to true for ||, then true
    if (b < 11 && b % 2)      printf("and false yo\n");
    if (b < 11 && b % 2 == 0) printf("and true  yo\n");

    // bitwise operators (specifically: left-shift and assignment)
    int x = 1;
    int i = 0;
    for (i=0; i<5; i++) {
        printf("%d\n", x <<= 1);    // bit-shifting left equivalent to multiplication by 2 in this case
                                    // will need them for 'safe calculator' lab (probably numbered as lab05)
    }

    return 0;
}