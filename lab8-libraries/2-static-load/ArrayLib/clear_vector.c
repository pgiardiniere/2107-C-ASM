#include "../ArrayLib.h"

// Writes zeros to the elements of a vector and sets count to zero.
void clear_vector(Vector *v)
{
    printf("clear_vector()\n");
    print_min(*v);
    int i;
    for (i = 0; i < (*v).count; i++) {
        (*v).vector[i] = (double) 0;
    }
    (*v).count = 0;
    print_min(*v);
}
