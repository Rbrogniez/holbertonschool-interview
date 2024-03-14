#include "sort.h"
#include <stdlib.h>

/* Helper function to get the maximum value in the array */
int getMax(int *array, size_t size) {
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	return max;
}

/* Helper function to perform counting sort */
void countSort(int *array, size_t size, int exp) {
	int *output = malloc(size * sizeof(int));
	int count[10] = {0}; /* Declaration moved up */
	size_t i;

	if (output == NULL) {
		/* Handle allocation failure */
		return;
	}

	for (i = 0; i < size; i++) {
		count[(array[i] / exp) % 10]++;
	}

	for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}

	for (i = size; i > 0; i--) {
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	for (i = 0; i < size; i++) {
		array[i] = output[i];
	}

	free(output);
}

/* Main Radix Sort function */
void radix_sort(int *array, size_t size) {
	int max;
	int exp;

	if (size < 2) {
		return; /* Array already sorted */
	}

	max = getMax(array, size); /* Moved declaration to the beginning */
	for (exp = 1; max / exp > 0; exp *= 10) {
		countSort(array, size, exp);
		print_array(array, size);
	}
}
