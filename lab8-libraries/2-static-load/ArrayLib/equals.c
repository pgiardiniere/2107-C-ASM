#include "../ArrayLib.h"

int equals(Vector v1, Vector v2)
{
    if (v1.count != v2.count)
        return 0;
    int i;
    for (i = 0; i < v1.count; i++) {
        if ( !dbl_equals(v1.vector[i], v2.vector[i]) )
            return 0;
    }
    return 1;
}
