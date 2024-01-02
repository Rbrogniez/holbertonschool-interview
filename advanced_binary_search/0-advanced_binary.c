#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL)
        return -1;

    return advanced_binary_recursive(array, 0, size - 1, value);
}

/**
 * advanced_binary_recursive - Recursive helper function for binary search.
 * @array: Pointer to the first element of the array to search in.
 * @start: Index of the starting element in the subarray.
 * @end: Index of the ending element in the subarray.
 * @value: Value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int advanced_binary_recursive(int *array, size_t start, size_t end, int value)
{
    size_t mid, i;

    if (start > end)
        return -1;

    printf("Searching in array: ");
    for (i = start; i <= end; i++)
    {
        printf("%d", array[i]);
        if (i < end)
            printf(", ");
    }
    printf("\n");

    mid = (start + end) / 2;

    if (array[mid] == value)
        return mid;

    if (array[mid] < value)
        return advanced_binary_recursive(array, mid + 1, end, value);
    else
        return advanced_binary_recursive(array, start, mid - 1, value);
}
