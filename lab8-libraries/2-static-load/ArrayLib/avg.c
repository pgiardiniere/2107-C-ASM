#include "../ArrayLib.h"

double avg(Vector v)
{
    double sigma = sum(v);
    return sigma / v.count;
}
