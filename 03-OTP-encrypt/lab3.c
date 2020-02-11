#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_file(char* filename, unsigned long * filesize);
int write_file(char* output, char* filename, unsigned long filesize);

char* read_file(char* filename, unsigned long * filesize) {
    FILE * file = fopen(filename, "rb");                // open file. If failure, return some text
    if (file == NULL) { return "File not found"; }
    
    fseek(file, 0, SEEK_END);                           // get size in bytes, assign to filesize, rewind stream
    *filesize = (unsigned long) ftell(file);
    rewind(file);     
    
    char* contents = (char*) malloc(*filesize);          // allocate space in bytes. If failure, return text
    if (contents == NULL) { return "mem alloc failure"; }

    fread(contents, 1, *filesize, file);                // save string to contents, close file, return pointer
    fclose(file);
    return contents;
}

int write_file(char* outstr, char* filename, unsigned long filesize) {
    int written = 0;
    FILE * file = fopen(filename, "wb");                // open file. If failure, return some text
    if (file == NULL) { return -1; }

    written = fwrite(outstr, 1, filesize, file);        // write output. If not written, return some text
    if (written < filesize) { return -1; }

    return written;
}

int main() {
    char filename[] = "file.txt";
    unsigned long filesize = 0;

    // get contents of file, verify successful. If failed to get, kill main(). 
        // would be better served by do-while loop, taking new input on each attempt.
    char *fileStr = read_file(filename, &filesize);
    if (strcmp(fileStr, "File not found") == 0 || strcmp(fileStr, "mem alloc failure") == 0) { 
        printf("%s\n", "Can't read file or do mem allocation, killing main()");
        return 1;
    }

    // make outfile string
    char* outFile;
    strcpy(outFile, "encrypted-");
    strcat(outFile, filename);

    // make outStr string
    char* outStr = (char*) malloc(filesize);                // allocate space in bytes.
    if (outStr == NULL) { return 1; }                       // If failure, return
    strcpy(outStr, "Genma-notded");                         // put stuff in the space
    write_file (outStr, outFile, filesize);                 // use it for something
    free(outStr);                                           // free the space before exit.


    free(fileStr);    // since small inputs, safe to simply perform all free() statements at program exit

    return 0;
}