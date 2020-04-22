#include "../ArrayLib.h"

int insert(Vector *v, double dbl)
{
    // Reallocate if vector is full
    if (v->count == v->length) {
        (*v).length = 2 * v->length;
        (*v).vector = realloc( (*v).vector, sizeof(double)*v->length ); 
        if ((*v).vector == NULL) {
            perror("Error : "); exit(-1);
        }
    }
    // Insert the double
    (*v).vector[(*v).count] = dbl;
    (*v).count++;
}
