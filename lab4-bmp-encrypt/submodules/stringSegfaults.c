// The code here was exported from bmps.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // #########################
    // Useful String Functions
    // #########################
    char str[64];
    strcpy(str, "hey");             // strcpy  --- copies entire string FROM dest INTO src
    printf("%s\n", str);
    strncpy(str, "you idiot", 3);   // strncpy --- copies only Num characters FROM dest INTO src
    printf("%s\n", str);

    strcat(str, " idiot");          // strcat   --- copies entire string FROM dest INTO src
    printf("%s\n", str);
    strncat(str, " jk ily", 3);     // strncat  --- copies only Num character FROM dest INTO src
    printf("%s\n", str);

    // #########################
    // ALL THE WAYS TO SEGFAULT WITH STRINGS IN C HAHAHAHAHAHHAHAHAHAAHAHAHAHA
    // #########################

    // This code segfaults
    // Why? String Literals behave differently when assigned to
        // char* varName
        // char  varName[]
    char* tempStr = malloc(20);
    char* tempStr2 = malloc(20);
    tempStr2 = "Argh C";
    tempStr  = "Ayoo";
    strcpy(tempStr2, tempStr);
    // https://stackoverflow.com/questions/164194/why-do-i-get-a-segmentation-fault-when-writing-to-a-string-initialized-with-cha
        // The fix TL;DR
        // char  varName[] makes a COPY of the string literal in a writeable portion of memory. use those if need mutable string literals.


    // #########################
    // Demonstration of slight difference between a general 'char-buffer' and a string:
    // #########################
    
    // C defines a string as a null-terminated sequence of chars.
    // But if your sequence (array) is larger than the null-terminated character, you can keep putting stuff after the 'end' of the string part
    // Hence the use of the more general term 'buffer'
    
    // code below for example (assumes pre-filled bmp.str[])

    // int i;
    // for (i = 0; i < 4; i++) {
    //     if (i == 0) (bmp.str[i]) = 'h';
    //     if (i == 0) (bmp.str[i]) = 'e';
    //     if (i == 0) (bmp.str[i]) = 'y';
    //     if (i == 0) (bmp.str[i]) = '\0';
    // }

    // int i;
    // for (i = 0; i < 1500056; i++) {
    //     printf("%c ", bmp.str[i]);
    //     if (i % 56 == 0) printf("\n");
    // }
    return 0;
}