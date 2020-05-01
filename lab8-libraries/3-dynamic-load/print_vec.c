#include "ArrayLib.h"

// Prints the count, length and elements of a vector to screen.
void print_vec(Vector v)
{
    printf("Vector.length is %d\n", v.length);
    printf("Vector.count is %d\n", v.count);
    printf("Vector contents is [ ");
    int i;
    for (i = 0; i < v.count; i++) {
        printf("%.2lf, ", v.vector[i]);
    }
    printf("]\n\n");
}
