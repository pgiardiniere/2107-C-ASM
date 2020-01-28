// notes: Am using 2 print funcs to different types.

#include <stdio.h>          // may use no other libraries in this assignment

int length(char str[]) {
    int i = 0;
    char c;
    do { i++; } while (c != '\0');

    return i;
}

int isLower(char c) {    
    char a = 'a';
    char z = 'z';
    // char A = 'A';
    // char Z = 'Z';
    // char zero = '0';
    // char nine = '9';

    // printf("a index is %d\n", a); // 97
    // printf("z index is %d\n", z); // 122
    // printf("A index is %d\n", A); // 65
    // printf("Z index is %d\n", Z); // 90
    // printf("0 index is %d\n", zero); // 48
    // printf("9 index is %d\n", nine); // 57

    // printInt(z-a); // diff is 25
    // printInt(Z-A); // diff is 25
    // printInt(a-A); // diff is 32 (imp)
    // printInt(z-Z); // diff is 32 (imp)

    if (c >= a && c <= z) return 1;
    else return 0;
}

void toUpper(char c){
    
    // in-place reassignment? seems like based on instructions
}

// // throws a warning for now, can do "return *s" to silence
// char getString(char s[]) {
//     printf("Enter an input string\n");

//     return s;
// }

void capitalizeAndCount(char str[]) {

}

void printInt(int i) { printf("%d\n", i); }
void printString(char s[]) { printf("%s\n", s); }

int main() {
    char c = 'c';
    char C = 'C';
    char doi = '{';
    printInt(isLower(c));
    printInt(isLower(C));
    printInt(isLower(doi));

    char s[] = "poop";
    int len = length(s);

    return 0;
}