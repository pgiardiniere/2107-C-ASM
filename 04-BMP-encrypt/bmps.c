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

    // Get filesize
    unsigned int size;
    fseek(file, SIZE_BEGIN, 0);
    fread(&size, sizeof(int), 1, file);
    rewind(file);

    // get file width in pixels
    int width;
    fseek(file, WIDTH_BEGIN, 0);
    fread(&width, sizeof(int), 1, file);
    rewind(file);
    
    // get file height in pixels
    int height;
    fseek(file, HEIGHT_BEGIN, 0);
    fread(&height, sizeof(int), 1, file);

    printf("size is %d\nWidth is %d\nHeight is %d\n", size, width, height);

    // get file contents (as before, this is already working.)
    // "file content get would go here"
    fclose(file);
    return "poop";  // gotten file content would be returned
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
    printf("size of long (bytes) is %ld\n", sizeof(long));
    printf("size of long (bits ) is %d\n", bits);

    char filename[64] = "sample.bmp";
    read_bmp(filename, &size);          // updates size according to filesize.

    Bitmap bmp = {size, width, height, str};

    return 0;       
}