#include "search_algos.h"
#include <stdio.h>

/**
 * advanced_binary - Searches for the value with a binary search algorithm.
 *
 * @array: Pointer to the first element of the array to search.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The index of the first occurrence of the value in the array, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (binary_recursion(array, size, 0, size - 1, value));
}

/**
 * binary_recursion - Executes the binary search algorithm recursively.
 *
 * @array: array to search
 * @size: size of the array
 * @low: first index to look at
 * @high: last index to look at
 * @value: value to search for
 *
 * Return: The index of the first occurrence of the value in the array, or -1
 */
int binary_recursion(int *array, size_t size, size_t low, size_t high,
					 int value)
{
	size_t middle = low + (high - low) / 2;

	if (middle >= size)
		return (-1);

	print_array(array, low, high);

	if (array[middle] > value)
		return (binary_recursion(array, size, low, middle, value));
	else if (array[middle] < value)
		return (binary_recursion(array, size, middle + 1, high, value));

	if (array[middle] == value && middle == low)
		return (middle);

	return (binary_recursion(array, size, low, middle, value));
}

/**
 * print_array - Prints the part of the array that is being searched
 *
 * @array: array to print
 * @start: starting index
 * @end: ending index
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		if (i != end)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}
}
