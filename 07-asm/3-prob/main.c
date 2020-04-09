#include <stdio.h>

void dblit(int *arr, int length);

void print_arr(int* arr) {
    printf("[ ");
    int i = 0;
    while (i < 3) {
        printf("%d, ", arr[i]);
        i++;
    }
    printf("]\n");
}

int main() {
    int arr[] = {1, 2, 3};
    print_arr(arr);
    dblit(arr, 3);
    print_arr(arr);
}
