#include "../ArrayLib.h"

// Writes zeros to a vector's elements.
void zeros(Vector *v)
{
    print_min(*v);
    int i;
    for (i = 0; i < (*v).count; i++) {
        (*v).vector[i] = (double) 0;
    }
    print_min(*v);
}
