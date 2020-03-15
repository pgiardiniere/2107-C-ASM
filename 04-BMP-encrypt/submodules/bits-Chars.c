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
    // get binary of n. Begins @ least significant (i.e. rightmost) digit.
    char binRep[8];
    unsigned char c = '0';          // '0' ---> (dec) 48 --> (bin) 0011 0000
    int i = 0;
    printf("base-10 '0' is : %d\n", c);
    while (c) {
        if (c & 1)
            binRep[i] = '1';
        else
            binRep[i] = '0';
        i++;
        c = c >> 1;
    }
    binRep[i] = '\0';
    stringReverse(binRep);
    printf("base-2  '0' is : %s\n", binRep);    

    // convert binRep to Char
    

    return 0;
}