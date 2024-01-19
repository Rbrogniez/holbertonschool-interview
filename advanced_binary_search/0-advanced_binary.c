#include "search_algos.h"

/**
 * print_array - Prints an array of integers.
 * @array: Pointer to the first element of the array to print.
 * @size: Number of elements in array.
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	printf("Searching in array: ");
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");

}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in array.
 * @value: Value to search for.
 *
 * Return: Index where value is located.
 * -1 if value is not present or array is NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
	int mid;
	int ret;

	if (!array)
		return (-1);
	print_array(array, size);
	if (size == 1 && array[0] != value)
		return (-1);
	else if (size <= 2 && array[0] == value)
		return (0);
	mid = size / 2 - 1 + size % 2;
	if (array[mid] < value)
	{
		ret = advanced_binary(array + mid + 1, size - mid - 1, value);
		if (ret != -1)
			ret += mid + 1;
	}
	else
		ret = advanced_binary(array, mid + 1, value);
	return (ret);
}
