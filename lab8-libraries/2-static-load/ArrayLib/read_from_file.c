#include "../ArrayLib.h"

Vector read_from_file(char *filename)
{
    FILE * file = fopen("array_in.txt", "r");
    if (file == NULL) { 
        perror("Error : ");
        exit(-1);
    }
    // Count lines in file in i, that is our num of doubles.
    int i = 0;
    char str[255];    
    while (fgets(str, 255, file) != NULL) {
        i++;
    }
    rewind(file);

    if (i == 0) {
        fclose(file);
        return empty_vector();
    }

    Vector v = create_vector(i);
    double temp;
    for (i = 0; i < v.length; i++) {
        fscanf(file, "%lf", &temp);
        insert(&v, temp);
    }
    fclose(file);
    return v;
}
