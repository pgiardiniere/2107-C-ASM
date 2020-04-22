#include "ArrayLib.h"

void sort(Vector *v)
{
    int i, j, minInd;
    for (i = 0; i < (*v).count-1; i++) {
        minInd = i;
        for (j = i+1; j < (*v).count; j++) {
            if ( (*v).vector[j] < (*v).vector[minInd] ) {
                minInd = j;
            }
        }
        if (minInd != i) {
            swap(v, i, minInd);
        }
    }
}
