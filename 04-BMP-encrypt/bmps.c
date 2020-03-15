// TIME ALLOWING ::: 
// create code so that I can read in bmp file header data INTO my Bitmap struct
// Since we're calling read_bmp on the entire file,
// then I am putting entire file contents into a giant char array
// so all I have to do is translate that arr's contents from chars into unsigned long & 2 unsigned ints
// actually, filesize will already be taken care of
// so I only really need it to ge the width and height.
// which 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HEADER_SIZE 56
#define SIZE_BEGIN 2
#define WIDTH_BEGIN 18
#define HEIGHT_BEGIN 22

typedef struct Bitmap {
    unsigned long size;
    unsigned int width;
    unsigned int height;
    char * str;
} Bitmap;

// read in BMP Header data, store in struct properly
char* read_bmp(char* filename, unsigned long * filesize) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) { perror("Error "); exit(1); }

    fseek(file, 0, SEEK_END);
    *filesize = (unsigned long) ftell(file);
    rewind(file);

    // char str[*filesize];
    char* str = malloc(*filesize);
    fread(str, 1, *filesize, file);
    fclose(file);

    return str;

    // debug :: not really working right. Trying to data from header.
    printf("size is %lu\n", *filesize);
    printf("first 56 bytes of file (i.e. the bmp header) is as follows:\n");
    
    int i;    
    i = SIZE_BEGIN;         // i.e. offset = 2
    printf("unsigned int SIZE is:\n");
    while (i < SIZE_BEGIN + 32) {
        printf("%c ", str[i]);
        i++;
    }
    // i = WIDTH_BEGIN;        // i.e. offset = 18
    // printf("unsigned int SIZE is %u\n", str[i]);
    // i = HEIGHT_BEGIN;       // i.e. offset = 22
    // printf("unsigned int SIZE is %u\n", str[i]);
}

int main() {
    unsigned long size;                 // actual :: 1500056
    unsigned int width;                 // actual :: 1000
    unsigned int height;                // actual :: 500
    char str[1500056];                  // actual :: 1500056
    // Bitmap bmp = {size, width, height, str};

    // read in data from BMP header
    int bits = sizeof(int) * 8;
    printf("size of int (bytes) is %ld\n", sizeof(int));
    printf("size of int (bits ) is %d\n", bits);

    bits = sizeof(long) * 8;
    printf("size of int (bytes) is %ld\n", sizeof(int));
    printf("size of int (bits ) is %d\n", bits);

    char filename[64] = "sample.bmp";
    read_bmp(filename, &size);          // updates size according to filesize.


    Bitmap bmp = {size, width, height, str};

    return 0;       
}