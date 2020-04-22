#include "../ArrayLib.h"

// Swaps two elements in a vector.
void swap(Vector *v, int i, int j)
{
    double temp = (*v).vector[i];
    (*v).vector[i] = (*v).vector[j];
    (*v).vector[j] = temp;
}
