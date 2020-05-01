#include "ArrayLib.h"

// Create a vector of doubles.
Vector create_vector(int length)
{
    double* ptr = (double*) malloc(sizeof(double) * length);
    if (ptr == NULL) {
        printf("Warning: malloc() failure. Returning empty vector\n");
        Vector v = empty_vector();
        return v;
    }
    Vector v = {ptr, 0, length};
    return v;
}
