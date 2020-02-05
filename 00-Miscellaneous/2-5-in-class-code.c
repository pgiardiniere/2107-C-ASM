# include <stdio.h>
# include <string.h>

int numcompA(char *sl, char *s2);
int numcompD(char *sl, char *s2);
void swap2(void *v[], char *left, char *last);
void printNums();

// command line arguments ::
// argc     contains    num of args entered     'ARGument Count'
// argv     contains    the arguments           'ARgument _'
int main(int argc, char *argv[]) {

    // arrays of pointers
    char *days[7]; 
    days[0] = "Sunday";
    days[1] = "Monday";
    days[2] = "Tuesday";
    days[3] = "Thursday";
    days[4] = "Friday";
    days[5] = "Saturday";
    days[6] = "Sunday";
    // print
    int i = 0;
    for (i = 0; i < 7; i++)
        printf("%s\n", days[i]);
    printf("\n");

    // sort array of pointers --- working with pointers is faster than directly on strings themselves
    int j;
    char *temp;
    int min = 0;
    for (i = 0; i < 6; i++) {
        min = i;
        for (j = i+1; j < 7; j++) {
            if (strcmp(days[min], days[j]) > 0)
                min = j;
        }
        temp = days[i];
        days[i] = days[j];
        days[j] = days[i];
    }
    // print
    for (i = 0; i < 7; i++)
        printf("%s\n", days[i]);
    printf("\n");

    // NEXT:: Matrices. i,j,k are standard iterators. If need more, don't use L ...
    int matrix[][3] = { {1,2,3},{4,5,6},{7,8,9} };

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");   // format rows
    }
    printf("\n");


    char *month[] = {"Illegal month", "January",
        "February", "March", "April"}; // illegal as no 0-date month
    printf("month = %s\n", month[0]);
    printf("month = %s\n", month[3]);
    printf("\n");

    // Pointers vs Multi-Dimensional Arrays

    // #########################
    // NEXT :: Command Line Arguments
    // #########################
    printf("argv[0] = %s\n", argv[0]);  // prints the first terminal arg passed to execute program
    printf("\n");

    // print all args (space delimited): 
    // ./2-5-in-class-code hey yo doi
    i = 0;
    for(i=0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    printf("\n");

    i = 0;
    int n = 0;
    int sum = 0;
    // if (argv[i]) > 0  basically, if argument was passed, try to coirce (ATOI()) to integer,
    // add to sum (unfinished segment)

    // #########################
    // NEXT :: Pointers to Functions
    // #########################

    // call the qsort
    int asc = 1;
    char *ptr_arr[] = { "5", "3", "2", "1", "4" };
    qsort1(ptr_arr, 0, 9, (int (*)(void*, void*))(asc ? numcompA : numcompD));

    // #########################
    // NEXT :: malloc()
    // #########################
    // when using malloc(), ALWAYS
    // always always always
    // write a "free;" statement after you're done
    // this (ideally) stops any potential memory leaks you have.

    return 0;
}

// what are all these funcions...
// OH fucking qsort means we're implementing QuickSort here
// but importantly, we're QuickSorting
// and choosing our implementation of that QuickSort by passing as variables to QSort1 
// the pointers of the functions it's going to use

// important note:: function(void *foo)
// in this context, void *foo

// means we are passing (by value) a pointer which references UNTYPED data
// so, by extension, functions are untyped in C

// this is the simpler version of qsort1 below --- i.e. this deals with nums, qsort1 works with funcs
int numcompA(char *s1, char *s2){
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    // v1 > v2 |||| v2 < v1 ----- descending (our use here)
    // v1 < v2 |||| v2 > v1 ----- ascending
    if(v1 > v2) { return -1; }
    else if(v2 < v1) { return 1; }
    else { return 0; }
}
// copy of numCompA to make the function call work
int numcompD(char *s1, char *s2){
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    // v1 > v2 |||| v2 < v1 ----- descending (our use here)
    // v1 < v2 |||| v2 > v1 ----- ascending
    if(v1 > v2) { return -1; }
    else if(v2 < v1) { return 1; }
    else { return 0; }
}

void swap2(void *v[], char *left, char *last) {
    char *temp;
    temp = v[*left];
    v[*left] =v[*last];
    v[*last] = *temp;    
}

void printNums(char *arr[]) {
    // printf();
}
 
void qsort1(void *v[], int left, int right,
    int (*comp)(void *, void *)){
    int i, last;
    if(left >= right)
        return;
    swap2(v, left, (left + right)/2);
    last = left;
    for(i = left+1; i <= right; i++)
        if((*comp)(v[i], v[left]) < 0)
    swap2(v, ++last, i);
    swap2(v, left, last);
    qsort1(v, left, last-1, comp);
    qsort1(v, last+1, right, comp);
}