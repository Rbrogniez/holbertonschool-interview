#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void siftdown(int array[], int nodeValue, int root, int last);
void heap_sort(int *array, size_t size);

#endif /* LISTS_H */
