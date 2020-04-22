#include "ArrayLib.h"

// Creates full-copy of existing vector and returns it.
Vector copy(Vector v1)
{
    Vector v2 = create_vector(v1.length);
    int i;
    for (i = 0; i < v1.count; i++) {
        insert( &v2, v1.vector[i] );
    }
    printf("v1 has"); print_min(v1);
    printf("v2 has"); print_min(v2);
    return v2;
}
