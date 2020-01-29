#include <stdio.h>

int length (char str[]) {
    int i = 0;
    while (str[i] != '\0') { i++; }
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
        *changed += 1;
    }
}

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

void getString() {

}

void print(char s[], int len, int changed) {
    printf("    String is : %s\n", s);
    printf("    length is : %d\n", len);
    printf("    Changed is: %d\n\n", changed);
}

int main() {
    char s[] = {'p','l','a','c','e','\0'}; 
    int len = length(s);
    int changed = 0;

    print(s, len, changed);
    int i = 0;
    while (i < length(s)) {
        capitalize(&s[i], &changed);
        i++;
    }
    print(s, len, changed);

    reverse(s, len-1);
    print(s, len, changed);
}