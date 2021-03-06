#include <stdio.h>

#define NKEYS 10

// prototyping :: Stucts first, then functions -- (same for ordering w/o structs)
struct point;
struct Rectangle;
struct point make();
struct Rectangle canonRect();
struct key;

void print();
void print2();
void printR();
void printk();
void printkarr();
void printk();
int MIN();
int MAX();

// structs are similar to classes in java, but more primitive
struct point {
    int x;
    int y;
};

// typedef :: don't need to use 'struct' in main() (or other methods) when instantiating
typedef struct {
    int x;
    int y;
} Point;

// nested struct
struct Rectangle {
    struct point a;
    struct point b;
};

// struct method ("constructor-ish")
struct point make(int x, int y) {
    struct point p = {x, y};
    return p;
};

struct Rectangle canonRect(struct Rectangle r) {
    struct Rectangle temp;
    temp.a.x = MIN(r.a.x, r.b.x);
    temp.a.y = MIN(r.a.y, r.b.y);
    temp.b.x = MAX(r.a.x, r.b.x);
    temp.b.y = MAX(r.a.y, r.b.y);
    return temp;
};

// arrays of Structures
struct key {
    char *word;
    int count;
};

int main() {
    struct point a;
    a.x = 2;
    a.y = 3;

    printf("a.x is %d and a.y is %d\n", a.x, a.y);
    print(a);
    printf("\n");

    // alternative declaration method::
    struct point b = {1000, 2000};
    print(b);
    printf("\n");

    struct Rectangle rect;    
    rect.a.x = 19;
    rect.a.y = 190;
    rect.b.x = 3;
    rect.b.y = 4;
    printR(rect);

    struct point c = make(10, 20);
    print(c);
    printf("\n");

    // Rectangle, reformat points
    struct Rectangle s = canonRect(rect);
    printR(s);

    // Pointers:
    struct point origin = {0, 0};
    print(origin);
    struct point *or = &origin;
  //printf("*origin = (%d, %d)\n", (*or).x (*or).y);    // for some reason this fails, but not on profs machine
    printf("*origin = (%d, %d)\n", or->x, or->y);       // this syntax is way nicer anyways.

    // #########################
    // Arrays of Structs
    // #########################
    struct key keytab[NKEYS];
    keytab[0].word = "hello";
    keytab[0].count = 5;
    printkarr(keytab, 1);

    // #########################
    // Size of Structs? Actually NO additional overhead
    // #########################
    printf("size = %d\n", sizeof(struct point));        // recall: sizeof -- actually a keyword, not function
    printf("size = %d\n", sizeof(struct key));
        // size is : sum of sizeof(int) and sizeof(*char) --- just the pointer, NOT the actually char

    // #########################
    // Recursive structs (trees)
    // #########################
    // DO NOT make a struct which constructs additional instances of itself (guarunteed infinite loop)
    // To get recursion (for ex. with trees) you'll use POINTERS YAAAY

    // Typedef :: make your struct a datatype
    // means you don't have to identify 'struct ___ ' which is real nice
    Point w;
    w.x = 12;
    w.y = 11;
    print2(w);

    return 0;
}



// print methods
void print(struct point p) {
    printf("x = %d and y = %d\n", p.x, p.y);
}

void print2 (Point p) {
    printf("x = %d and y = %d\n", p.x, p.y);
}

void printR(struct Rectangle r) {
    print(r.a); print(r.b); printf("\n");
}

void printk(struct key k) {
    printf("word is: %s and count is: %d\n", k.word,k.count);
}

void printkarr(struct key arr[], int n) {
    int i = 0;
    while (i < n) { printk(arr[i]); i++;}
}

int MIN(int a, int b) {
    if (a < b) return a;
    return b;
}

int MAX(int a, int b) {
    if (a > b) return a;
    return b;
}