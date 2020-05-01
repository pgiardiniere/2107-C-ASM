#include <stdio.h>
#include <stdlib.h>

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
    ProductArray products = { arr, length, 0 };
    return products;
}

void delete_product_array(ProductArray* products) {
    if ((*products).arr == NULL) {
        return;
    }
    free((*products).arr);
    (*products).length = 0;
    (*products).count = 0;
}

void insert_product(ProductArray* products, Product prod) {
    // If full, double length and reallocate array according to length * sizeof struct.
    if (products->count == products->length) {
        (*products).length = GROW_SIZE * products->length;
        (*products).arr = realloc((*products).arr, (*products).length * sizeof(Product));

        if ((*products).arr == NULL) {
            perror("error : ");
            exit(-1);
        }
    }
    // Now that we're certainly not full, append the thing.
    (*products).arr[(*products).count] = prod;
    (*products).count += 1;
}

ProductArray* read(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("error : ");
        exit(-1);
    }
    // Create a product array to store file contents.
    ProductArray products = make_product_array(GROW_SIZE);
    // Make product from file text: First, determine length of file
    int j = 0;
    char* line;
    while (fgets(line, 255, file) != NULL) {
        j++;
    }
    rewind(file);
    // Second, read each line, making a product from each.
    int i = 0;
    for (i = 0; i < j; i++) {
        fgets(line, 255, file);
        strtok(line, "\n");     // overwrite fgets trailing newline with null char
        
    }


    // Insert product into our product array.

    fclose(file);
}

int main() {
    printf("hi\n");

    // read("Products.txt");

    return 0;
}
