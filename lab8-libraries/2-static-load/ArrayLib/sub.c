#include "../ArrayLib.h"

Vector sub(Vector v1, Vector v2)
{
    if (v1.count != v2.count)
        return empty_vector();
    Vector v3 = create_vector(v1.count);
    int i;
    for (i = 0; i < v1.count; i++) {
        insert(&v3, v1.vector[i] - v2.vector[i]);
    }
    return v3;
}
