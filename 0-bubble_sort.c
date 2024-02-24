#include "sort.h"

/*
 * swap - swaps two integers in array
 * @x: first int to swap
 * @y: second int to swap
 */
void swap(int *x, int *y)
{
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

void bubble_sort(int *array, size_t size) 
{
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

