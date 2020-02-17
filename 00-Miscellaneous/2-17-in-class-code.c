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

    /*
    char filename[] = "filename.txt";
    int n = 0;
    char s[] = "Hello, World!";
    FILE *file2 = fopen(filename, "w");
    if (file2 == NULL) { fprintf(stderr, "File %s not opened\n", filename); exit(1); }

    for (n = 0; n < 10; n++) {  // Write lines to file
        fprintf(file, "%d %s", n, s);
        printf("Write: %d %s\n", n, s);
    } 
    if (ferror(file)) {         // Check that file write successful
        fprintf(stderr, "Error writing to %s\n", filename);
        exit(2);
    }
    */

    // #########################
    // example: bad array sizing
    // C will NOT stop you from accessing array indices which are out of bounds.
    // means your are probably overwriting to space reserved for other variables, etc ...
    // #########################

    char str[10];
    int i = 0; while (i < 20) { str[i] = 'j'; i++;}
    printf("%s\n", str);

    // #########################
    // array resizing w/ realloc()
    // #########################
    int size = 10;
    int *arr = (int*) malloc(size * sizeof(int));
    if (arr == NULL) { perror("Error "); exit(1); }

    for (i = 0; i < size; i++) { 
        arr[i] = i;
        printf("%d\n", arr[i]); 
    }
    printf("\n");

    arr = (int*) realloc(arr, 25);
    arr[10] = 420;
    
    for (i = 0; i < 25; i++) { printf("%d\n", arr[i]); }



    return 0;
}