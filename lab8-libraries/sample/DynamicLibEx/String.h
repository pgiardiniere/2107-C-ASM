/*
    Header file for string functions
*/

// If the header file with prototypes is not included,
// include it.
#ifndef String
    #define String

    // Basic and enhanced string function prototypes
    void toUpper(char s[]);
    int strLen(char s[]);
    void strCat(char dest[], char src[]);
    void strCpy(char dest[], char src[]);
    int strCmp(char s[], char t[]);
    int strCmpIgnoreCase(char s[], char t[]);
    int strEql(char s[], char t[]);
    int strEqlIgnoreCase(char s[], char t[]);

#endif
