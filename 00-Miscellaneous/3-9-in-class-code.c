#include <stdio.h>
#include <stdlib.h>

int main() {
    // // demonstration of bit storage of signed/unsigned ints
    // int x1 = -1;
    // unsigned int y1 = x1;
    // printf("x = %d y = %u\n", x1, y1); // x = -1, y = 4294967295

    // char x2 = -1;
    // unsigned char y2 = x2;
    // printf("x = %d y = %u\n", x2, y2); // x = -1, y = 255
    // // note that to the C compiler, the types don't matter so much as the bit-repesentation.

    // // demonstration of left shift by 1 --- is equivalent to multiplaction by 2 (makes sense)
    // // similarly, right shift (>>=) by 1 -- is equivalent to division      by 2
    // char x = 0;
    // int i = 0;
    // for(i = 0; i < 8; i++) {
    //     printf("x = %d\n", x);
    //     x <<= 1;
    // }
    // printf("\n");

    // unsigned char ux = 128;         // For unsigned nums, C does 'extra' to make sure stays nonneg
    // for (i = 0; i < 10; i++) {      // try i < 8, i < 9, i < 10 .
    //     printf("x = %d\n", ux);
    //     ux >>= 1;
    // }
    // printf("\n");

    // // Integer Promotion
    // // when adding mixed bittypes together, the result will be promoted to the biggest type
    // char ch   = 127;
    // int in    = 4567;
    // short sho = 30000;
    
    // int result = ch + in + sho;
    // printf("result is %d\n", result);
    // printf("\n");

    // // Comparing Int and Unsigned Ints
    // // for mixed signed/unsigned operands, C uses Boolean string comparison
    //     // "Promote" --> signed nums to Unsigned nums.
    //     // necessary as we promote smaller datatypes to larger
    // in = -1;
    // unsigned int unin = 0;
    // if (in > unin)  printf("x greater than y\n");   // prints this. Because promotion.
    // else            printf("x less than y\n");

    // if (in > (int)unin )    printf("same thing\n");
    // else                    printf("works now\n");  // prints this, because correct explicit cast

    // Casting larger type to lower IS legal 
    // stores the max amt of LEAST significant digits in smaller.
    int x1 = 0x00001234;
    int x2 = 0x12345678;
    short s1 = (short)x1;       // storing explicit cast
    short s2 = (short)x2;
    printf("x1=0x%08x, ", x1);  // octal representations of all nums
    printf("x2=0x%08x,\n", x2);  
    printf("s1=0x%08x, ", s1);
    printf("s2=0x%08x\n", s2);  // truncates most significant bits


    // Underflow demonstration :: unsigned, then signed
    unsigned char a = 2;
    unsigned char b = 3;
    unsigned char c = a-b;
    printf("%d\n", a);

    char x = 2;
    char y = 3;
    char z = x-y;
    printf("%d\n", a);

    // Underflow detection :: (unsigned)
    if (a >= 0 && b >=0) {
        if (c > a || c > b) printf("Underflow\n");
        else                printf("result is %d\n", c);
    }

    // Overflow Detection :: (unsigned)
    if (a >= 0 && b >= 0) {
        if (c <= a || c <= b) printf("Overflow\n");
        else                  printf("result is %d\n", c);
    }

    // C Conversion rules (integral)


    // #########################
    // Next Time :: Floats
    // #########################


    return 0;
}