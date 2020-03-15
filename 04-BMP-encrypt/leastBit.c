#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringReverse(char * str) {
    char temp[sizeof(str)];
    int i = 0;
    int j = 0;
    while (str[i]) { i++; } i--;    // walk index to end of data

    while (i > -1) {                // reverse in a temp array
        temp[j] = str[i];
        j++;
        i--;
    }
    temp[j] = '\0';
    strcpy(str, temp);              // overwrite original, reverse complete
}

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

    // ####################
    // Now, let's write this shiz to a buffer. Specifically, let's push the last bit UP by one on some of them.
    // ####################
    unsigned char string[8];
    for (i = 0; i < 8; i++) {
        string[i] = 254;
    }

    // Second thought. Let's just overwrite the least-significant bit in a char 
    unsigned char str[8]; for (i=0; i<8; i++) { str[i] = 254; }
    unsigned char vals[1]; vals[0] = 4;

    for (i=0; i<8; i++) { printf("str[i] decimal is:  %d\n", str[i]); } printf("\n");

    // unsigned char dest;      // 1111 1110
    unsigned char val;          // 0000 0001

    // this overwrites the least-significant bit in each char in str[j]
    int j = 0;
    for (i = 0; i < 1; i++) {
        val = vals[i];
        while (val) {
            while (str[j]) {
                if (val & 1)
                    { str[j] |= 1; break; }
                else
                    { str[j] &= 254; break; }
            }
            j++;
            val >>= 1;
        }
    }

    for (i=0; i<8; i++) { printf("str[i] decimal is:  %d\n", str[i]); }
    



    // int j;
    // unsigned char temp;
    // manip = 9;     // decimal 9 --> binary 0000 1001
    // for (i = 0; i < strlen(string); i++) {
    //     temp = string[i];                   // get current char     (byte)
    //     for (j = 0; j < 8; j ++) {          // get least significant bit    (OH. OHOHOH. WE BEGIN ACCESS AT LEAST SIGNIFICANT BIT)
    //         if (temp & )
    //     }
    // }



    // ##########################################################################################
    // ##########################################################################################
    // ##########################################################################################

    // char binRep[8];
    // unsigned char c = '0';          // '0' ---> (dec) 48 --> (bin) 0011 0000
    // int i = 0;

    // printf("base-10 '0' is : %d\n", c);
    
    // while (c) {                     // get binary of n. Begins @ least significant (i.e. rightmost) digit.
    //     if (c & 1)
    //         binRep[i] = '1';
    //     else
    //         binRep[i] = '0';
    //     i++;
    //     c = c >> 1;
    // }
    // binRep[i] = '\0';
    // stringReverse(binRep);
    
    // printf("base-2  '0' is : %s\n", binRep);
    
    return 0;
}