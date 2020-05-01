#include "ArrayLib.h"

Vector get_from_con()
{
    printf("Enter your doubles, i.e. <numeric>.<numeric><Enter>\n");
    printf("Hit enter a second time to exit, i.e. <Enter><Enter>\n");
    double dbl = 1.0;
    char in[255];    
    
    Vector v = create_vector(1);
    fgets(in, 255, stdin);
    in[strcspn(in, "\n")] = 0;
    dbl = atof(in);

    while (dbl != 0.0) {
        insert(&v, dbl);
        fgets(in, 255, stdin);
        in[strcspn(in, "\n")] = 0;
        dbl = atof(in);
    }

    if (v.count == 0)
        return empty_vector();
    else
        return v;
}
