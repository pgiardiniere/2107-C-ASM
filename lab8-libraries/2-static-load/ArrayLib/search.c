#include "../ArrayLib.h"

//  Perform a binary search on a sorted vector and return
//  the index of the element if found and -1 if not found.
int search(Vector v, double dbl)
{
    int left = 0;
    int right = v.count-1;
    int mid;
    // While we haven't crossed indices, check midpoint halfway between edges
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (dbl_equals(v.vector[mid], dbl)) {
            return mid;
        }
        if (v.vector[mid] > dbl) {
            left = mid + 1;
        }
        if (v.vector[mid] < dbl) {
            right = mid - 1;
        }
    }
    return -1;
}
