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


void print(Product prod);
void print_all(ProductArray* pl);

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
    free( pl->arr );
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


void read(char* filename, ProductArray* pl) {
    // Declarations
    // ProductArray pl = make_product_array(GROW_SIZE);
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
        // make new string buffers for each line
        char* id = (char*) malloc(6 * sizeof(char));
        char* desc = (char*) malloc(50 * sizeof(char));
        if (id == NULL || desc == NULL) { perror("error: "); exit(-1); }

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
        insert_product(pl, p);
        
    }
    free(line);
    fclose(file);
}


void print(Product prod) {
    printf("\nID is: %s", prod.id);
    printf("\nDescription is: %s", prod.description);
    printf("\nPrice is: %lf", prod.price);
    printf("\nQuantity is: %d\n", prod.quantity);
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
        
        if ((*pl).arr[i].quantity < 10)
            print((*pl).arr[i]);
        i++;
    }

}


double calc_total() {

}




int main() {
    ProductArray pl = make_product_array(GROW_SIZE);
    read("Products.csv", &pl);
    
    //print_all(&pl);
    print_low(&pl);

    delete_product_array(&pl);
    return 0;
}
