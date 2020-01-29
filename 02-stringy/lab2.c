#include <stdio.h>

char str[] = "placeholder";

int length(char str[]) {
    int i = 0;
    while (str[i] != '\0') { i++; }
    return i;
}

int isLower(char c) {    
    if (c >= 'a' && c <= 'z') return 1;
    else return 0;
}

char toUpper(char c){
    c -= 32;
    return c;
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
    // copy global var 'str' into 's' 
    int len = length(str);
    char s[len];
    int i = 0;
    while (str[i] != '\0') { 
        s[i] = str[i];
        i++;
    }
    s[len] = '\0';

    // print each character (and position) to screen.
    int j = 0;
    while (j < len) {
        printf("charat %d is %c\n", j, s[j]);
        j++;
    }

    // test toUpper
    printf("%c\n", toUpper('d'));

    // test isLower
    printf("%d\n", isLower('D'));
    printf("%d\n", isLower('d'));
    printf("%d\n", isLower('4'));

    return 0;
}