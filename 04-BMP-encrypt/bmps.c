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

int main() {
    unsigned long size = 1500056;
    unsigned int width = 1000;
    unsigned int length= 500;
    char str[1500056];
    Bitmap bmp = {size, width, length, str};

    
    return 0;       
}