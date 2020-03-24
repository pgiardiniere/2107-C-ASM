#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char* make;
    char* model;
    int year;
    double price;
    int odom;
} Car;

void print_car(Car c) {
    printf("ID:%d\n", c.id);
    printf("Make:%s\n", c.make);
    printf("Model:%s\n", c.model);
    printf("Year:%d\n", c.year);
    printf("Price:%f\n", c.price);
    printf("Odometer:%d\n", c.odom);
}

void print_cars(Car cars[], int count) {
    int i = 0;
    Car c;
    while (i < count) {
        c = cars[i];
        print_car(c);
        i++;
    }
}

Car* make_cars() {
    Car c = {}; // comma seperated
}

Car* read_car(char* filename, int *count) {
    Car* cars = (Car*) malloc(3 * sizeof(Car));
    if (cars == NULL) { perror("Error : "); exit(-1); }

    FILE * file = fopen(filename, "r");
    if (file == NULL) { perror("Error : "); exit(-1); }

    char line[500];
    char* pch;
    while(fgets(line, 500, file) != NULL ) {
        // do stuff
    }

    fclose(file);
    return cars;
}

void write_car(Car cars[], int count, char* filename) {
    FILE * file = fopen(filename, "w");
    if (file == NULL) { perror("Error : "); exit(-1); }

    Car c;
    int i = 0;
    while (i < count) {
        c = cars[i];
        fprintf("ID:%d\n", c.id);
        fprintf("Make:%s\n", c.make);
        fprintf("Model:%s\n", c.model);
        fprintf("Year:%d\n", c.year);
        fprintf("Price:%f\n", c.price);
        fprintf("Odometer:%d\n", c.odom);
        i++;
    }
    fclose(file);
}

int main() {
    char inFile = "cars.csv";
    char outFile = "cars.txt";
    int count = 3;

    Car* cars = read_car(inFile, &count);

    

    free(cars);
    return 0;
}