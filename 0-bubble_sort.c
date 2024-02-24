#include <stdio.h>
#include "sort.h"

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int *array, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                // Print the array after each swap
                for (size_t k = 0; k < size; k++) {
                    printf("%d ", array[k]);
                }
                printf("\n");
            }
        }
    }
}

