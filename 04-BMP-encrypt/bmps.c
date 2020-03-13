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
    unsigned int length;
    char * str;
} Bitmap;

char* read_bmp(char* filename, unsigned long * filesize) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) { perror("Error "); exit(1); }

    fseek(file, 0, SEEK_END);


    return ;
}

int main() {
    unsigned long size = 1500056;
    unsigned int width = 1000;
    unsigned int length= 500;
    char str[1500056];
    Bitmap bmp = {size, width, length, str};

    int bits = sizeof(int) * 8;
    printf("size of int (bytes) is %d\n", sizeof(int));
    printf("size of int (bits ) is %d\n", bits);

    char filename[64] = "sample.bmp";
    read_bmp(filename, &size);          // updates size according to filesize.


    return 0;       
}