#include "ArrayLib.h"

int write_to_file(Vector v, char *filename)
{
    FILE * file = fopen("array_out.txt", "w");
    if (file == NULL) { 
        perror("Error : ");
        exit(-1);
    }
    int i = 0;
    while (i < v.count) {
        fprintf(file, "%.2lf\n", v.vector[i]);
        i++;
    }
    fclose(file);
    return 0;

}
