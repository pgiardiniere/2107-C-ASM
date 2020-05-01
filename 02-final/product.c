#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GROW_SIZE 2

typedef struct {
    char* id;
    char* description;
    double price;
    int quantity;
} Product;

typedef struct {
    Product* arr;
    int length;
    int count;
} ProductArray;

ProductArray make_product_array(int length) {
    Product* arr = (Product*) malloc(sizeof(Product) * length);
    if (arr == NULL) {
        perror("error: ");
        exit(-1);
    }
    ProductArray pl = { arr, length, 0 };
    return pl;
}

void delete_product_array(ProductArray* pl) {
    if ((*pl).arr == NULL) {
        return;
    }
    free((*pl).arr);
    (*pl).length = 0;
    (*pl).count = 0;
}

void insert_product(ProductArray* pl, Product prod) {
    // If full, double length and reallocate array according to length * sizeof struct.
    if (pl->count == pl->length) {
        (*pl).length = GROW_SIZE * pl->length;
        (*pl).arr = realloc((*pl).arr, (*pl).length * sizeof(Product));

        if ((*pl).arr == NULL) {
            perror("error : ");
            exit(-1);
        }
    }
    // Now that we're certainly not full, append the thing.
    (*pl).arr[(*pl).count] = prod;
    (*pl).count += 1;
}

ProductArray* read(char* filename) {
    // Declarations
    ProductArray pl = make_product_array(GROW_SIZE);
    char id[6];
    char desc[50];
    double price;
    int qty;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("error : ");
        exit(-1);
    }
    
    // Determine length of file
    int j = 0;
    char* line = (char*) malloc(255 * sizeof(char));
    if (line == NULL) { perror("error: "); exit(-1); }
    while (fgets(line, 255, file) != NULL) {
        j++;
    }
    rewind(file);
    
    // Read file, making products 1 line at a time.
    int i = 0;
    for (i = 0; i < j; i++) {
        fgets(line, 255, file);
        strtok(line, "\n");

        char* ptr = strtok(line, ",");
        strncpy(id, ptr, 5);
        id[5] = '\0';
        
        ptr = strtok(NULL, ",");
        strcpy(desc, ptr);

        ptr = strtok(NULL, ",");
        price = atof(ptr);

        ptr = strtok(NULL, ",");
        qty = atoi(ptr);

        Product p = { id, desc, price, qty };
    }

    // Insert product into our product array.

    free(line);
    fclose(file);
}

int main() {
    read("Products.csv");

    return 0;
}
