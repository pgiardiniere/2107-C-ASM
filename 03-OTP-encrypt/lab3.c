#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * read_file(char *filename, unsigned long *filesize);
void write_file(char *output, char *filename, unsigned long filesize);


char * read_file(char *filename, unsigned long *filesize) {
    FILE * file = fopen(filename, "rb");
    if (file == NULL) { return "File not found"; }




    *filesize = 10 ;    // = fseek()
    return filename;
}

void write_file(char *output, char *filename, unsigned long filesize) {

}


int main() {
    char filename[] = "file.txt";
    unsigned long filesize = 0;

    char *filecontent = read_file(filename, &filesize);
    if (strcmp(filecontent, "File not found") == 0) printf("%s\n", filecontent);    // works

    printf("%d\n", filesize);
    return 0;
}