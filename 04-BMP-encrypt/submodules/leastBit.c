#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // printf("uchar byte = 1\n");
    // unsigned char byte = 1;         // decimal 1 --> binary 0000 0001
    // int  i = 1;
    // while (byte) {
    //     printf("bit #%d    ", i );
    //     if (byte & 1)
    //         printf("1");
    //     else
    //         printf("0");
    //     i++;        
    //     byte >>= 1;
    //     printf("\n");
    // }
    // printf("\n");

    // printf("uchar byte = 9\n");
    // byte = 9;                       // decimal 9 --> binary 0000 1001
    // i = 1;
    // while (byte) {
    //     printf("bit #%d    ", i );
    //     if (byte & 1)
    //         printf("1");
    //     else
    //         printf("0");
    //     i++;        
    //     byte >>= 1;
    //     printf("\n");
    // }
    // printf("\n");

    printf("uchar byte = 254\n");   // decimal   9 --> binary 0000 1001
    unsigned char byte = 254;       // decimal 254 --> binary 1111 1110
    int i = 1;
    while (byte) {
        printf("bit #%d    ", i );
        if (byte & 1)
            printf("1");
        else
            printf("0");
        i++;        
        byte >>= 1;
        printf("\n");
    }
    printf("\n");

    // Compare bit-by-bit
    printf("uchar byte  = 254       0000 1001\n");
    printf("uchar manip =   9       1111 1110\n");
    printf("Testing bitwise & ----- 0000 1000 -----\n");
    byte = 254;
    unsigned char manip = 9;     // decimal 9 --> binary 0000 1001
    i = 1;
    while (byte) {
        printf("bit #%d    ", i );
        if (manip & 1) {
            if (byte & 1) 
                printf("1 (same val in both)");
            else
                printf("0 (diff val)");
        }
        else {
            if (byte & 1)
                printf("0 (diff val)");
            else
                printf("1 (same val in both)");
        }
        i++;        
        byte  >>= 1;
        manip >>= 1;
        printf("\n");           //          1111 1110
    }                           //          0000 1001
    printf("\n");               // expected      1000    CORRECT


    // int j;
    // unsigned char temp;
    // manip = 9;     // decimal 9 --> binary 0000 1001
    // for (i = 0; i < strlen(string); i++) {
    //     temp = string[i];                   // get current char     (byte)
    //     for (j = 0; j < 8; j ++) {          // get least significant bit    (OH. OHOHOH. WE BEGIN ACCESS AT LEAST SIGNIFICANT BIT)
    //         if (temp & )
    //     }
    // }

    // ####################################################################################
    // Second thought. Let's just overwrite the least-significant bit in a char 
    unsigned char str[8]; for (i=0; i<8; i++) { str[i] = 254; }
    unsigned char vals[1]; vals[0] = 4;                             // toggle vals[0] = n; to try different nums. It really works!

    // unsigned char dest;      // 1111 1110                        // unnecessary variable
    unsigned char val;          // 0000 0001

    for (i=0; i<8; i++) { printf("str[i] decimal is:  %d\n", str[i]); }
    printf("\n");

    // this overwrites the least-significant bit in each char in str[j]
    int j = 0;
    for (i = 0; i < 1; i++) {
        val = vals[i];
        while (val) {                                               // technically, we don't need val either. could do while (vals[i])
            while (str[j]) {
                if (val & 1)
                    { str[j] |= 1; break; }                         // write '1' to least bit in str[j] (0000 0001)
                else
                    { str[j] &= 254; break; }                       // write '0' to least bit in str[j] (1111 1110)
            }
            j++;
            val >>= 1;
        }
    }
    for (i=0; i<8; i++) { printf("str[i] decimal is:  %d\n", str[i]); }

    return 0;
}