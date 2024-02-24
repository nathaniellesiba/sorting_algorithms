#include "sort.h"

/*
 * swap - swaps two integers in array
 * @x: first int to swap
 * @y: second int to swap
 */

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


/* bubble_sort - sort array of int in ascending order
 * @array: an array of int to sort
 * @size: the size of the array
 *
 * Description: prints swapped array after each swap
 */

void bubble_sort(int *array, size_t size) {
    size_t i, len = size;
    bool bubbly;

    if (array == NULL || size < 2) {
        return;
    }

    do {
        bubbly = false;
        for (i = 0; i < len - 1; i++) {
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
                bubbly = true;
            }
        }
        len--;
    } while (bubbly);
}
