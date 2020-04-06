#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define INIT_SIZE 4
#define EPSILON 0.01

/*
    This lab requires you to write functions that manage
    and process double precision data vectors.  The includes,
    defines, Vector struct, function prototypes, skeleton
    functions and test code in main have been included to
    get you started.

    I suggest writing the functions in order
    of appearance below because some functions, either directly
    or indirectly depend on others.  You have to create a vector
    and insert elements before printing a vector.  The sum function
    can be used in avg, avg can be used in var and var in stdv.  The
    dbl_equals function should be used to compare doubles within a
    threshold to account for arithmetic precision errors on doubles.

    Make sure that you check that file open and memory allocation
    is successful before using the file or memory.  Points will be
    deducted if you code can crash in any way.  So be sure to
    consider and handle all possible threats that may crash your
    application.
        
        i.e. Use:
    if (ptr == NULL) {perror("Error : "); exit(-1); }
    ... and possibly empty_vector() for good measure

    This code will be used in your final project to create static
    and dynamic libraries.
*/


/*
    Struct for a vector of double.  It contains a pointer
    to a vector of double, an integer for allocated length
    of the vector and and integer for the count of double
    inserted.
*/
typedef struct {
    double *vector;
    int count;
    int length;
} Vector;


// Prototypes
Vector create_vector(int length);
Vector empty_vector();                      // Not called from main()
int insert(Vector *vec, double dbl);
void print_vec(Vector vec);
void print_min(Vector vec);
void delete_vector(Vector *vec);
Vector copy(Vector vec);
Vector copy_range(Vector vec, int from, int to);
void clear_vector(Vector *vec);             // Not called from main()
void zeros(Vector *vec);
void fill(Vector *vec, double dbl);
Vector read_from_file(char *filename);
int write_to_file(Vector vec, char *filename);
Vector get_from_con();
void add_from_con(Vector *vec);
void swap(Vector *vec, int i, int j);
void sort(Vector *vec);
void reverse(Vector *vec);
int dbl_equals(double d1, double d2);       // Not called from main()
int search(Vector vec, double dbl);
double sum(Vector vec);
double avg(Vector vec);
double var(Vector vec);
double stdv(Vector vec);
Vector add(Vector v1, Vector v2);
Vector sub(Vector v1, Vector v2);
Vector mul(Vector v1, Vector v2);
Vector divv(Vector v1, Vector v2);
double dot(Vector v1, Vector v2);
int equals(Vector v1, Vector v2);


int main()
{
    // Test create, insert and print
    printf("\nTest create, insert and print\n####################\n");
    Vector v1 = create_vector(2);
    insert(&v1, 1.0);
    insert(&v1, 2.0);
    insert(&v1, 3.0);
    insert(&v1, 4.0);
    insert(&v1, 5.0);
    print_vec(v1);
    printf("\n");

    // Test copy and copy range
    printf("Test copy and copy range\n####################\n");
    Vector v2 = copy(v1);
    // print_vec(v2);
    Vector v3 = copy_range(v1, 1, 3);
    // print_vec(v3);
    printf("\n");

    // Test zeros and fill
    printf("Test zeros and fill\n####################\n");
    zeros(&v3);
    // print_vec(v3);
    fill(&v2, 1.0);
    // print_vec(v2);
    printf("\n");

    // // Test read and write
    // printf("Test read and write\n");
    // Vector v4 = read_from_file("array_in.txt");
    // print_vec(v4);
    // write_to_file(v1, "array_out.txt");
    // printf("\n");

    // // Test get from con and add from con
    // Vector v5 = get_from_con();
    // print_vec(v5);
    // add_from_con(&v5);
    // print_vec(v5);
    // printf("\n");

    Vector v4 = create_vector(2);
    insert(&v4, 2.0);
    insert(&v4, 4.0);
    insert(&v4, 6.0);
    insert(&v4, 8.0);
    insert(&v4, 10.0);

    // Test swap, sort, reverse and search
    printf("Test swap, sort, reverse and search\n");
    swap(&v1, 0, 4);
    swap(&v1, 1, 3);
    print_min(v1);
    sort(&v1);
    print_min(v1);
    reverse(&v4);
    print_min(v4);
    int i = search(v4, 6.0);
    printf("Found at %d\n\n", i);

    // Test sum, avg, var and stdv
    printf("Test sum, avg, var and stdv\n");
    printf("Sum = %f\n", sum(v4));
    printf("Avg = %f\n", avg(v4));
    printf("Var = %f\n", var(v4));
    printf("Stdv = %f\n\n", stdv(v4));

    // Test add, sub, mul, divv, dot and equals
    printf("Test add, sub, mul, divv, dot and equals\n");
    Vector v6 = add(v1, v4);
    printf("   "); print_min(v1); printf(" + "); print_min(v4);
    print_min(v6);
    Vector v7 = sub(v6, v4);
    printf("   "); print_min(v6); printf(" - "); print_min(v4);
    print_min(v7);
    Vector v8 = mul(v1, v4);
    printf("   "); print_min(v1); printf(" * "); print_min(v4);
    print_min(v8);
    Vector v9 = divv(v8, v4);
    printf("   "); print_min(v8); printf(" / "); print_min(v4);
    print_min(v9);
    double dbl = dot(v1, v4);
    printf("   "); print_min(v1); printf(" . "); print_min(v4);
    printf("Dot = %f\n", dbl);
    i = equals(v1, v4);
    printf("    "); print_min(v1); printf(" == "); print_min(v4);
    printf("Equals = %d\n", i);
    i = equals(v1, v1);
    printf("    "); print_min(v1); printf(" == "); print_min(v1);
    printf("Equals = %d\n", i);

    // Free memory
    delete_vector(&v1);
    delete_vector(&v2);
    delete_vector(&v3);
    delete_vector(&v4);
    // delete_vector(&v5);
    delete_vector(&v6);
    delete_vector(&v7);
    delete_vector(&v8);
    delete_vector(&v9);

    return 0;
}

/*
    Single vector functions
*/

/*
    Function to create a vector of double.  It accepts the
    integer length of the vector to be created and returns
    a Vector struct containing the length of the allocated
    vector, the count (initialized to zero) of doubles
    inserted, and the allocated vector.
*/
Vector create_vector(int length)
{
    double* ptr = (double*) malloc(sizeof(double) * length);
    if (ptr == NULL) {
        printf("Warning: malloc() failure. Returning empty vector\n");
        Vector v = empty_vector();
        return v;
    }
    Vector v = {ptr, 0, length};
    return v;
}

/*
    Create an empty vector with vector pointer set to NULL,
    length set to zero and count set to zero.  This is used
    when something fails during the creation of a Vector or
    other functions that return a Vector.
*/
Vector empty_vector()
{
    Vector v = {NULL, 0, 0};
    return v;
}


/*
    Inserts a double into a vector of double.  If the
    vector is full (i.e. count == length), the length of
    the vector should be doubled and the data from the old
    vector should be copied and the old vector freed.  If
    the length is zero, use the defined initial size.
    
    You can use malloc, which requires you to manually copy
    and free the old vector or try realloc.
*/
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


//  Prints the count, length and elements of a vector to screen.
void print_vec(Vector v)
{
    printf("Vector.length is %d\n", v.length);
    printf("Vector.count is %d\n", v.count);
    printf("Vector contents is [ ");
    int i;
    for (i = 0; i < v.count; i++) {
        printf("%.2lf, ", v.vector[i]);
    }
    printf("]\n\n");
}


void print_min(Vector v)
{
    printf(" [ ");
    int i;
    for (i = 0; i < v.count; i++) {
        printf("%.2lf, ", v.vector[i]);
    }
    printf("]\n\n");
}


/*
    Frees the memory allocated for the vector, and sets
    the count and length to zero.  Make sure not the free
    an empty (NULL) vector.
*/
void delete_vector(Vector *v)
{
    if ((*v).vector == NULL) {
        return;
    }
    free((*v).vector);
    (*v).count = 0;
    (*v).length = 0;
}


/*
    Creates a new vector with equal count, length and
    elements and returns the vector.
*/
Vector copy(Vector v1)
{
    Vector v2 = create_vector(v1.length);
    int i;
    for (i = 0; i < v1.count; i++) {
        insert( &v2, v1.vector[i] );
    }
    printf("v1 has"); print_min(v1);
    printf("v2 has"); print_min(v2);
    return v2;
}


/*
    Copies a range from a vector to a new vector and
    returns the new vector.  The count and length should
    be equal to the number of elements copied.  Remember
    to check for invalid operations:
        to less than from
        to less than zero
        from greater than or equal to count

        to greater than or equal to count
        is my addition, because checking array bounds is A Good Thing.
*/
Vector copy_range(Vector v1, int from, int to)
{
    // Check that range is valid.
    if (to < from || to < 0 || from >= v1.count || to >= v1.count) {
        printf("copy_range() error - you entered an invalid range\n\n");
        exit(-1);
    }
    // Copy the range from v1 into v2.
    Vector v2 = create_vector(v1.count);
    int i;
    for (i = from; i < to; i++) {
        insert( &v2, v1.vector[i] );
    }
    printf("v1 has"); print_min(v1);
    printf("v3 has"); print_min(v2);
    return v2;
}


// Writes zeros to the elements of a vector and sets count to zero.
void clear_vector(Vector *v)
{
    printf("clear_vector()\n");
    print_min(*v);
    int i;
    for (i = 0; i < (*v).count; i++) {
        (*v).vector[i] = (double) 0;
    }
    (*v).count = 0;
    print_min(*v);
}


// Writes zeros to a vector's elements.
void zeros(Vector *v)
{
    printf("zeros()\n");
    print_min(*v);
    int i;
    for (i = 0; i < (*v).count; i++) {
        (*v).vector[i] = (double) 0;
    }
    print_min(*v);
}



// Writes a double to a vector's elements.
void fill(Vector *v, double dbl)
{
    printf("fill()\n");
    print_min(*v);
    int i;
    for (i = 0; i < (*v).count; i++) {
        (*v).vector[i] = dbl;
    }
    print_min(*v);
}



//  Reads a vector from a file with one double on
//  each line in the file and returns the vector.
//  Remember that scanf returns a -1 after reading
//  the last element in a file.
Vector read_from_file(char *filename)
{
    FILE * file = fopen("array_in.txt", "r");
    if (file == NULL) { 
        perror("Error : ");
        exit(-1);
    }
    // Get length from file

    
    // int i = 0;
    // while (i != -1) {
    //     // i = fscanf();
    // }

    fclose(file);
}


/*
    Writes a vector's elements to a file.
*/
//int write_to_file(Vector vec, char *filename){
//}


/*
    Creates a new vector and gets the elements from
    keyboard input.  Accepts and inserts doubles into
    the vector until Enter is pressed 
    (without any other chars).  
    
    Remember that scanf will not work unless a
    required data type is entered.
    You should use gets and check for '\0', when Enter only is pressed.
*/
Vector get_from_con()
{

}


/*
    Adds elements to a vector and gets the elements from
    keyboard input.  Accepts and inserts doubles into
    the vector until Enter is pressed (without any other
    chars). Remember that scanf will not work unless a
    required data type is entered. You should use gets
    and check for '\0', when Enter only is pressed.
*/
void add_from_con(Vector *vec)
{

}


// Swaps two elements in a vector.
void swap(Vector *v, int i, int j)
{
    double temp = (*v).vector[i];
    (*v).vector[i] = (*v).vector[j];
    (*v).vector[j] = temp;
}


// Sorts a vector using selection sort. Linearly probes all indices,
// getting smallest val to swap into position.
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


// Reverses the elements of a vector.
void reverse(Vector *v)
{
    double temp;
    int i = 0;
    int j = (*v).count - 1;
    while (i < j) {
        swap(v, i, j);
        i++;
        j--;
    }
}


// Checks if two doubles are equal given the defined EPSILON == 0.01
int dbl_equals(double d1, double d2)
{
    if ( round(d1 * 100) * EPSILON == round(d2 * 100) * EPSILON) {
        return 1;
    }
    return 0;
}


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


// Calculate and return the sum of the elements in a vector.
double sum(Vector v)
{
    double result = 0.0;
    int i = 0;
    while ( i < v.count) {
        result += v.vector[i];
        i++;
    }
    return result;
}


// Calculate and return the average of the elements in a vector.
double avg(Vector v)
{
    double sigma = sum(v);
    return sigma / v.count;
}


// Calculate and return the variance of the elements in a vector.
double var(Vector v)
{
    Vector temp = create_vector(v.length);
    double mean = avg(v);
    int i = 0;
    while (i < v.count) {
        insert(&temp, pow(v.vector[i] - mean, 2));
        i++;
    }
    double variance = avg(temp);
    delete_vector(&temp);
    return variance;
}


// Calculate and return the standard deviation of the elements in a vector.
double stdv(Vector v)
{
    return sqrt(var(v));
}


/*
    Multiple vector functions
*/

/*
    Perform an element by element addition of two vectors,
    where v3[i] = v1[i] + v2[i] and return the resulting
    vector.
*/
Vector add(Vector v1, Vector v2)
{
    if (v1.count != v2.count)
        return empty_vector();
    Vector v3 = create_vector(v1.count);
    int i;
    for (i = 0; i < v1.count; i++) {
        insert(&v3, v1.vector[i] + v2.vector[i]);
    }
    return v3;
}


/*
    Perform an element by element subtraction of one vector from
    another, where v3[i] = v1[i] - v2[i] and return the resulting
    vector.
*/
Vector sub(Vector v1, Vector v2)
{
    if (v1.count != v2.count)
        return empty_vector();
    Vector v3 = create_vector(v1.count);
    int i;
    for (i = 0; i < v1.count; i++) {
        insert(&v3, v1.vector[i] - v2.vector[i]);
    }
    return v3;
}


/*
    Perform an element by element multiplication of two vectors,
    where v3[i] = v1[i] * v2[i] and return the resulting
    vector.
*/
Vector mul(Vector v1, Vector v2)
{
    if (v1.count != v2.count)
        return empty_vector();
    Vector v3 = create_vector(v1.count);
    int i;
    for (i = 0; i < v1.count; i++) {
        insert(&v3, v1.vector[i] * v2.vector[i]);
    }
    return v3;
}


/*
    Perform an element by element division of two vectors,
    where v3[i] = v1[i] / v2[i] and return the resulting
    vector.
*/
Vector divv(Vector v1, Vector v2)
{
    if (v1.count != v2.count)
        return empty_vector();
    Vector v3 = create_vector(v1.count);
    int i;
    for (i = 0; i < v1.count; i++) {
        insert(&v3, v1.vector[i] / v2.vector[i]);
    }
    return v3;
}


/*
    Perform the calculation of the dot product of two vectors,
    where dbl += v1[i] * v2[i] and return the resulting
    double.
*/
double dot(Vector v1, Vector v2)
{
    if (v1.count != v2.count) {
        printf("Dimension mismatch - exiting");
        exit(-1);
    }
    double dbl = 0;
    int i;
    for (i = 0; i < v1.count; i++) {
        dbl += v1.vector[i] * v2.vector[i];
    }
    return dbl;
}


/*
    Perform an element by element comparison of two vectors.
    If for every i, v1[i] == v2[i], and the count is equal
    return 1, otherwise zero.
*/
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
