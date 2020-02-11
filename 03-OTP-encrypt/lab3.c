#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototypes
// char* read_file(char* filename, unsigned long * filesize);
// int write_file(char* output, char* filename, unsigned long filesize);
// void printMenu()

void printMenu() {
    printf("    Encrypt a file:  1\n");
    printf("    Decrypt a file:  2\n");
    printf("    Exit:            3\n");
    printf("    Enter a choice:  ");
}

char* read_file(char* filename, unsigned long * filesize) {
    FILE * file = fopen(filename, "rb");                // open file. If failure, return some text
    if (file == NULL) { return "File not found"; }
    
    fseek(file, 0, SEEK_END);                           // get size (bytes), assign to filesize, rewind strm
    *filesize = (unsigned long) ftell(file);
    rewind(file);     
    
    char* contents = (char*) malloc(*filesize);          // allocate space in bytes. If failure, return text
    if (contents == NULL) { return "mem alloc failure"; }

    fread(contents, 1, *filesize, file);                // save string,  close file, return pointer
    fclose(file);
    return contents;
}

int write_file(char* outstr, char* filename, unsigned long filesize) {
    int written = 0;
    FILE * file = fopen(filename, "wb");                // open file. If failure, return some text
    if (file == NULL) { return -1; }

    written = fwrite(outstr, 1, filesize, file);        // write output. If not written, return some text
    if (written < filesize) { return -1; }

    fclose(file);
    return written;
}

int main() {
    // Get user input
    int coerced;
    char in[256];
    do {
        // if (coerced < 1 || coerced > 3) printf("That didn't work. Try a valid menu option. They are:\n");
        printMenu();
        fgets(in, 256, stdin);
        in[strcspn(in, "\n")] = 0;
        coerced = atoi(in);
    } while (coerced < 1 || coerced > 3);
    printf("\n");

    char filename[] = "file.txt";
    unsigned long filesize = 0;

    // get contents of file, verify successful. If failed to get, kill main(). 
        // would be better served by do-while loop, taking new input on each attempt.
    char *fileStr = read_file(filename, &filesize);
    if (strcmp(fileStr, "File not found") == 0 || strcmp(fileStr, "mem alloc failure") == 0) { 
        return 1;
    }

    // make outfile string
    char outFile[256];
    strcpy(outFile, "encrypted-");
    strcat(outFile, filename);

    // make outStr string
    char* outStr = (char*) malloc(filesize);                // allocate space in bytes.
    if (outStr == NULL) { return 1; }                       // If failure, return
    strcpy(outStr, "Genma-notded");                         // put stuff in the space
    write_file (outStr, outFile, filesize);                 // use it for something 
    free(outStr);                                           // free the space before exit.
    free(fileStr);    // since small inputs, safe to perform all free() statements at program exit

    
    return 0;
}