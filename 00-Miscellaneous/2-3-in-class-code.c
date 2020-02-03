#include <stdio.h>

// problem :: passing by value. 
void badSwap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void addressVal(int *a, int *b) {
    printf("       a address: %u\n", a);
    a++;
    printf("       a address: %u\n", a);
}

int StrLen(char *s) {
    int i = 0;
    while (*(s++) != '\0') { i++; }     // dereference, compare, then increment address location
    return i;
}

void StrCopy(char * dest, char *src) {
    while (*src != '\0') { *(dest++) = *(src++); }
    *dest = '\0';   // remember, if you comment this out or forget to add null char termination,
                    // StrLen could be messed up (as it reads the garbage stored in mem)
}

int main() {

    int n = 5;
    int *n_ptr = &n;  // get the memory address of primitive var 'n', store it in *ptr
    
    int m = 10;
    int *m_ptr = &m;

    printf("n = %d and n_ptr = %u\n", n, n_ptr);
    printf("m = %d and m_ptr = %u\n", m, m_ptr);    // m declared later, has higher memory address

    printf("n = %d and n_ptr = %u and n = %d\n", n, n_ptr, *n_ptr); // de-reference w/ * to get the value
    printf("n = %d and n_ptr = %u and n = %d\n", n, n_ptr, *n_ptr);

    // create a new reference to the same int 'n' and modify value stored in location
    int *ptr = n_ptr;
    printf("%u %u\n", *ptr, *n_ptr);
    *ptr *= 10;
    printf("%u %u\n", *ptr, *n_ptr);

    // memory allocation quirk :: this is assigning memory location size of 1 int above m_ptr
    // which is to say, 4 bytes ahead
    ptr = m_ptr + 1;
    printf("%u %u\n", *ptr, *m_ptr);    

    // get sizeof datatype (in bytes): (different (esp. older) computer architectures have diff default vals)
    printf( "size = %u\n", sizeof(int));

    // remember: unary operators will take effect before dereferencing address.
    // you will incremement pointer address and not the value stored at the memory location
    // Solution: You can use parens to make your intent explicit & more readable
    *(++n_ptr);

    // #########################
    // pointer passing:
    // #########################
    int a = 5;
    int b = 10;

    printf("\nbadSwap()\n");    
    printf("a = %d b = %d\n", a, b);
    badSwap(a, b);
    printf("a = %d b = %d\n", a, b);

    printf("\nswap()\n");
    printf("a = %d b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d b = %d\n", a, b);
    // #########################

    // what if we modify the address in the method?
    // EVERYTHING is passed by value.
    // including the address you passed.
    // so if you change the address in a different method, it is only messed up within that method.
    printf("main() a address: %u\n", &a);
    addressVal(&a, &b);
    printf("main() a address: %u\n", &a);

    // arrays take place in a contiguous memory block
    printf("\nArray indeces\n");
    int nums[] = {1, 2, 3, 4, 5};
    int i = 0;
    while (i < 5) {
        printf("%u\n", &nums[i]);
        i++;
    }

    // more array pointer stuff
    int *array_ptr;
    array_ptr = nums;

    printf("array_ptr = %u\n", array_ptr);
    for (i = 0; i < 5; i++) {
        printf("%d %u\n", *array_ptr, array_ptr);
        array_ptr++;
    }

    // #########################
    // now, char arrays --- indexing in an outside function
    // #########################
    // length()
    char string[] = "Hello, World!"; 
    printf("\n%s \n", string);
    int len = StrLen(string);
    printf("%d\n", len);

    // StrCopy()
    printf("\nStrCopy()\n");
    char copied[50];
    StrCopy(copied, string);
    printf("%s\n", copied);
    printf("%d\n", StrLen(copied));

    // #########################

    return 0;
}