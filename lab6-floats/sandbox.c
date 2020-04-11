#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <float.h>

typedef struct {
    int sign;
    int exp;
    float mant;
    int mode;
} flt;

int main() {
    printf("size of int   is %lu\n", sizeof(int));
    printf("size of float is %lu\n", sizeof(float));

    flt fl = { 1, 4, 2, 1 };

    int result;
    result = (int) pow(2, fl.exp);
    printf("result is %d\n", result);

    return 0;
}