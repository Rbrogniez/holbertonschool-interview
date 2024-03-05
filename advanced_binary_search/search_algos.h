#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H
#include <stddef.h>

int advanced_binary(int *array, size_t size, int value);
int binary_recursion(int *array, size_t size, size_t low, size_t high,
					 int value);
void print_array(int *array, size_t start, size_t size);

#endif /* SEARCH_ALGOS_H */
