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
    
    // Read file 1 line at a time.
    int i = 0;
    for (i = 0; i < j; i++) {
        fgets(line, 255, file);
        strtok(line, "\n");

        // Get product datafields from line.
        char* ptr = strtok(line, ",");
        strncpy(id, ptr, 5);
        id[5] = '\0';
        
        ptr = strtok(NULL, ",");
        strcpy(desc, ptr);

        ptr = strtok(NULL, ",");
        price = atof(ptr);

        ptr = strtok(NULL, ",");
        qty = atoi(ptr);

        // Make product and insert.
        Product p = { id, desc, price, qty };
        insert_product(&pl, p);
    }

    free(line);
    fclose(file);

    return &pl;
}


void print(Product prod) {
    printf("\nID is: %s", prod.id);
    printf("\nDescription is: %s", prod.description);
    printf("\nPrice is: %lf", prod.price);
    printf("\nQuantity is: %d", prod.quantity);
}


void print_all(ProductArray* pl) {
    int i = 0;
    while (i < (*pl).count) {
        print((*pl).arr[i]);
        i++;
    }
}

void print_low(ProductArray* pl) {
    int i = 0;
    while (i < (*pl).count) {
        
        if ((*pl).arr[0].quantity < 10)
            print((*pl).arr[i]);
        i++;
    }

}


double calc_total() {

}




int main() {
    ProductArray* pl = read("Products.csv");
    
    // print_all(&pl);
    // print_low(&pl);

    delete_product_array(pl);
    return 0;
}
