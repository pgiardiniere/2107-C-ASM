#include "ArrayLib.h"

// Reverses the elements of a vector.
void reverse(Vector *v)
{
    double temp;
    int i = 0;
    int j = (*v).count - 1;
    while (i < j) {
        swap(v, i, j);
        i++;
        j--;
    }
}
