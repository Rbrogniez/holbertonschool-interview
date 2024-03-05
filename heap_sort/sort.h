#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify_array(int *array, size_t size, size_t index, size_t originalSize);
void swap_value(int *a, int *b);

#endif /* SORT_H */
