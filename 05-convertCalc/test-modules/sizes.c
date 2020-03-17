#include <stdio.h>
#include <limits.h>     // for INT_MIX & INT_MAX calls

int main() {
    unsigned long size = sizeof(int);
    printf("sizeof int is %lu\n", size);
    printf("bitsof int is %lu\n", size*8);
    printf("bit representation :: 32 bits\n");
    printf("0000 0000 0000 0000 0000 0000 0000 0000\n");
    printf("hex representation :: 32 bits\n");
    printf("FFFF FFFF\n");                                                  // ^> implies we have 0x80000000        (Verified)
    printf("Integer Min is %d with hexcode %x\n", INT_MIN, INT_MIN);        // define __INT_MIN__ ( -INT_MAX - 1)   == (decimal) -2,147,483,648
    printf("Integer Max is  %d with hexcode %x\n", INT_MAX, INT_MAX);       // define __INT_MAX__ 0x7fffffff        == (decimal)  2,147,483,647
    //                                                                      // MIN binary :: 1000 0000 0000 0000 0000 0000 0000 0000
    //                                                                      // MAX binary :: 0111 1111 1111 1111 1111 1111 1111 1111
    return 0;                                                               //  -1 binary :: 1111 1111 1111 1111 1111 1111 1111 1111    
}