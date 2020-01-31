// Coded by Pete Giardiniere
// Includes 2 print functions. 
    // printVertical() --- outputs per assignment specs exactly (currently called in main)
    // print()         --- outputs in horizontal format

#include <stdio.h>

int length (char str[]) {
    int i = 0;
    while (str[i] != '\n') { i++; }
    return i;
}

int isLower(char *c) {
    if (*c >= 'a' && *c <= 'z') return 1;
    else return 0;
}

void toUpper(char *c) {
    if (*c >= 'a' && *c <= 'z') *c -= 32;
}

void capitalize(char *c, int *changed) {
    if (isLower(c)) {
        toUpper(c);
        *changed += 1;      // use += as ++ increments pointer pos, not the value stored in changed
    }
}

// in-place reverse, avoids copying & pointer complications
void reverse (char s[], int right) {
    int left = 0;
    char tmp;
    while (left < right) {
        tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
}

void getString(char s[]) {
    printf("Please input a string, max length 256 characters. Hit enter when finished\n");
    fgets(s, 256, stdin);
}

void print(char s[], int len, int changed) {
    printf("    String is : %s", s);
    printf("    length is : %d\n", len);
    printf("    Changed is: %d\n\n", changed);
}

void printVertical(char s[], int len, int changed) {
    int i = 0;
    for (i = 0; i < len; i++) 
        printf("    %c\n", s[i]); 
    printf("    length is : %d\n", len);
    printf("    Changed is: %d\n\n", changed);    
}

int main() {
    char s[256];
    getString(s);
    int len = length(s);
    int changed = 0;

    printVertical(s, len, changed);
    int i = 0;
    while (i < length(s)) {
        capitalize(&s[i], &changed);
        i++;
    }
    reverse(s, len-1);
    printVertical(s, len, changed);
}