#include <stdio.h>
#include <stdlib.h>

char * read_file(char *filename, unsigned long *size);
void write_file(char *output, char *filename, unsigned long size);


char * read_file(char *filename, unsigned long *size) {
    
    printf("%s, %d\n", filename, *size);
    return filename;
}

void write_file(char *output, char *filename, unsigned long size) {

}


int main() {
    char filename[] = "file.txt";
    unsigned long filesize = 10;         // 10 bytes

    read_file(filename, &filesize);

    printf("der\n");
    return 0;
}