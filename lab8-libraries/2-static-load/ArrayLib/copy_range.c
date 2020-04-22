#include "../ArrayLib.h"

// Copies a range from a vector to a new vector, and returns it.
Vector copy_range(Vector v1, int from, int to)
{
    // Check that range is valid.
    if (to < from || to < 0 || from >= v1.count || to >= v1.count) {
        printf("copy_range() error - you entered an invalid range\n\n");
        exit(-1);
    }
    // Copy the range from v1 into v2.
    Vector v2 = create_vector(v1.count);
    int i;
    for (i = from; i < to; i++) {
        insert( &v2, v1.vector[i] );
    }
    printf("v1 has"); print_min(v1);
    printf("v3 has"); print_min(v2);
    return v2;
}
