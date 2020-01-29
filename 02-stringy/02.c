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

void toString(char s[], int len, int changed) {
    printf("    String is : %s\n", s);
    printf("    length is : %d\n", len);
    printf("    Changed is: %d\n\n", changed);
}

int main() {
    char s[] = "place";
    int len = length(s);
    int changed = 0;

    toString(s, len, changed);
    int i = 0;
    while (i < length(s)) {
        capitalize(&s[i], &changed);
        i++;
    }
    toString(s, len, changed);


}