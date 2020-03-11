#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_float_bits(char *s, float f){
    int i = 0, j = 0;
    int n = *(int*)&f;          // pointer trick to get length of msg, similar thing here
    char bits[33];              // convert size from char pointer to int pointer

    for(i=0; i<32; i++) {
        if(n&1)                 // if lowest order bit is a one,
            bits[31-i] = '1';   //      store it as a one       (in the arr)
        else                    // if lowest order bit is a 0
            bits[31-i] = '0';   //      store it as a 0         (in he arr)
        n >>= 1;                // move to the next bit                 ... so, bitwise op only checks last/first bit..?
    }
    bits[i] = '\0';
    printf("Bits %s: %s\n", s, bits);
    return;
}

int main() {
    // #########################
    // This Time :: Floats
    // #########################
    print_float_bits("float", 15.375);

    // what happens when placing int into a float
    unsigned int y = UINT_MAX;                  // requires <limits.h>
    float f;
    f = y;
    printf("y = %u f = %f\n", y, f);            // float is off-by-one
    double d;
    d = y;
    printf("y = %u d = %f\n", y, d);            // double is correct



    return 0;
}