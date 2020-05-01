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
    // if full, double length and reallocate array according to length * sizeof struct.
    if (products->count == products->length) {
        (*products).length = GROW_SIZE * products->length;
        (*products).arr = realloc((*products).arr, (*products).length * sizeof(Product));

        if ((*products).arr == NULL) {
            perror("error : ");
            exit(-1);
        }
    }

    // now that we're sure not full, append the thing.
    

}

int main() {
    printf("hi\n");
    return 0;
}
