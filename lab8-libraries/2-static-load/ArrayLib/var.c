#include "../ArrayLib.h"

// Calculate and return the variance of the elements in a vector.
double var(Vector v)
{
    Vector temp = create_vector(v.length);
    double mean = avg(v);
    int i = 0;
    while (i < v.count) {
        insert(&temp, pow(v.vector[i] - mean, 2));
        i++;
    }
    double variance = avg(temp);
    delete_vector(&temp);
    return variance;
}
