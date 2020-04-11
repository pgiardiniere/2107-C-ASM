#include <stdio.h>
#include <math.h>

#define EPSILON 0.01

int main() {
    // Verifying dbl_equals() logic:
    double dbl;
    dbl = 4.21;
    dbl = round(dbl * 100) / 100;
    printf("dbl is %.2lf\n", dbl);
    dbl = 4.21;
    dbl = round(dbl * 10) / 10;
    printf("dbl is %.2lf\n", dbl);
    dbl = 4.21;
    dbl = round(dbl);
    printf("dbl is %.2lf\n", dbl);

    double d1 = 1.2392;
    double d2 = 1.2312;
    double temp1, temp2, temp3, temp4;
    temp1 = round(d1 * 100);
    temp2 = round(d1 * 100) * EPSILON;
    temp3 = round(d2 * 100);
    temp4 = round(d2 * 100) * EPSILON;
    printf("temp1 is %.2lf\n", temp1);
    printf("temp2 is %.2lf\n", temp2);
    printf("temp3 is %.2lf\n", temp3);
    printf("temp4 is %.2lf\n", temp4);

    int boo = round(d1 * 100) * EPSILON == round(d2 * 100) * EPSILON; 
    printf("bool is %d\n\n", boo);


    // Verifying __binary__ search() logic:
    int arr[] = { 0, 1, 2, 3, 4 };
    int left = 0;
    int right = sizeof arr / sizeof arr[0] - 1;
    printf("left is %d and right is %d\n", left, right);

    int mid;
    mid = left + (right - left) / 2;
    printf("mid is %d\n", mid);

    return 0;
}