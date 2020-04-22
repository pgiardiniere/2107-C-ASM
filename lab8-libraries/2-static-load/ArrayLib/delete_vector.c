#include "../ArrayLib.h"

void delete_vector(Vector *v)
{
    if ((*v).vector == NULL) {
        return;
    }
    free((*v).vector);
    (*v).count = 0;
    (*v).length = 0;
}
