#include <stdio.h>

int polynomial(int a, int b, int c, int x);

// Compile using: 
// gcc -o main main.c polynomial.s
int main() {
    int y = polynomial(4,3,2,1);
    printf("y = %d\n", y);
}
