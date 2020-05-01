#include "ArrayLib.h"

// Calculate and return the sum of the elements in a vector.
double sum(Vector v)
{
    double result = 0.0;
    int i = 0;
    while ( i < v.count) {
        result += v.vector[i];
        i++;
    }
    return result;
}
