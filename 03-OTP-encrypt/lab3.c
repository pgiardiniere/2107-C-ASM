#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * read_file(char *filename, unsigned long *filesize);
void write_file(char *output, char *filename, unsigned long filesize);


char * read_file(char *filename, unsigned long *filesize) {
    FILE * file = fopen(filename, "rb");                // open file. If failure, return some text
    if (file == NULL) { 
        return "File not found"; 
    }
    fseek(file, 0, SEEK_END);                           // get size in bytes, assign to filesize, rewind stream
    *filesize = (unsigned long) ftell(file);
    rewind(file);     
    char* contents = (char*) malloc(*filesize);         // malloc() the space. If failure, return some text
    if (*contents == NULL) { 
        return "malloc() failed"; 
    }
    fread(contents, *filesize, 1, file);                // save string from input stream & return the pointer
    return contents;
}

void write_file(char *output, char *filename, unsigned long filesize) {

}



int main() {
    char filename[] = "file.txt";
    unsigned long filesize = 0;

    // get contents of file, verify successful. If failed to get, kill main(). 
        // would be better served by do-while loop, taking new input on each attempt.
    char *filecontent = read_file(filename, &filesize);
    if (strcmp(filecontent, "File not found") == 0 || strcmp(filecontent, "malloc() failed") == 0) { 
        printf("%s\n", "Can't read file or malloc() string, killing main()");
        return 1;
    }
    // check filecontents, free() the memory used when done.
    printf("%s\n", filecontent);
    free(filecontent);
    printf("%s\n", filecontent);

 


    return 0;
}