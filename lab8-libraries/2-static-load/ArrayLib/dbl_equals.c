#include "../ArrayLib.h"

// Checks if two doubles are equal given the defined EPSILON == 0.01
int dbl_equals(double d1, double d2)
{
    if ( round(d1 * 100) * EPSILON == round(d2 * 100) * EPSILON) {
        return 1;
    }
    return 0;
}
