#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int main() {

    // #########################
    // String tokenization :: read csv formatted file w/ strtok()
    // #########################
    char line[500];
    FILE * file = fopen("data.txt", "r");
    if (file == NULL) { perror("Error "); exit(1); }
    char* pch;

    while(fgets(line, 500, file) != NULL ) {
        // printf(line);                    // whole line print
        
        pch = strtok (line, ",");           // tokenized lines print
        while (pch != NULL) {
            printf("%s\n", pch);
            pch = strtok (NULL, ",");
        }
    }

    // #########################
    // fprintf  --- diff from printf() --- fprintf allows toggling Output stream    
    // stderr stream always prints within console (won't redirect to file)
    // #########################
    char filename[] = "filename.txt";
    int n = 0;
    char s[] = "Hello, World!";
    FILE *file = fopen(filename, "w");
    if (file == NULL) { fprintf(stderr, "File %s not opened\n", filename); exit(1); }

    for (n = 0; n < 10; n++) {  // Write lines to file
        fprintf(file, "%d %s", n, s);
        printf("Write: %d %s\n", n, s);
    } 
    if (ferror(file)) {         // Check that file write successful
        fprintf(stderr, "Error writing to %s\n", filename);
        exit(2);
    }

    return 0;
}