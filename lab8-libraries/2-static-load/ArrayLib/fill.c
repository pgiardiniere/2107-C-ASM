#include "../ArrayLib.h"

// Writes a double to a vector's elements.
void fill(Vector *v, double dbl)
{
    print_min(*v);
    int i;
    for (i = 0; i < (*v).count; i++) {
        (*v).vector[i] = dbl;
    }
    print_min(*v);
}
