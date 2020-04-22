#include "ArrayLib.h"

void print_min(Vector v)
{
    printf(" [ ");
    int i;
    for (i = 0; i < v.count; i++) {
        printf("%.2lf, ", v.vector[i]);
    }
    printf("]\n\n");
}
