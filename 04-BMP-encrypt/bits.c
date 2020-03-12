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
    char binRep[16];
    unsigned int n = 4;             // Binary : 0000 0000 0000 0100
    int i = 0;

    printf("base-10 n is : %d\n", n);
    
    while (n) {                     // get binary of n. Begins @ least significant (i.e. rightmost) digit.
        if (n & 1)
            binRep[i] = '1';
        else
            binRep[i] = '0';
        i++;
        n = n >> 1;
    }
    binRep[i] = '\0';
    stringReverse(binRep);
    
    printf("base-2  n is : %s\n", binRep);
    
    // testing calloc().
    char str[10];
    str[9] = '\0';
    i = 0;
    while (i < 10) {
        printf("%c ", str[i] + 48);
        i++;
    }
    printf("\n");
    // calloc() works as expected
    
    return 0;
}