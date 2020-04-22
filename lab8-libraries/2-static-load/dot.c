#include "ArrayLib.h"

double dot(Vector v1, Vector v2)
{
    if (v1.count != v2.count) {
        printf("Dimension mismatch - exiting");
        exit(-1);
    }
    double dbl = 0;
    int i;
    for (i = 0; i < v1.count; i++) {
        dbl += v1.vector[i] * v2.vector[i];
    }
    return dbl;
}
