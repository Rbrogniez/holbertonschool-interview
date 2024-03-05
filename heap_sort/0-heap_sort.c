#include "sort.h"
#include <unistd.h>

/**
 * heap_sort - Sorts an array of integers in ascending order
 *
 * @array: array of integers
 * @size: size of the array
*/
void heap_sort(int *array, size_t size)
{
	ssize_t i;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify_array(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap_value(&array[0], &array[i]);
		print_array(array, size);
		heapify_array(array, i, 0, size);
	}
}

/**
 * heapify_array - Transforms the array into a Max Heap tree
 *
 * @array: array of integer
 * @size: size of the array to heapify
 * @index: current index
 * @originalSize: original size of the array to print it
*/
void heapify_array(int *array, size_t size, size_t index, size_t originalSize)
{
	size_t max, left, right;

	max = index;
	left = 2 * index + 1;
	right = 2 * index + 2;

	if (left < size && array[left] > array[max])
		max = left;

	if (right < size && array[right] > array[max])
		max = right;

	if (max != index)
	{
		swap_value(&array[index], &array[max]);
		print_array(array, originalSize);
		heapify_array(array, size, max, originalSize);
	}
}

/**
 * swap_value - Swaps the value between 2 nodes
 *
 * @a: first integer
 * @b: second integer
*/
void swap_value(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
