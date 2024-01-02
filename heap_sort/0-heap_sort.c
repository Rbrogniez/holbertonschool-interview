#include "sort.h"

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sift_down(int* array, size_t root, size_t size, size_t sizes)
{
    size_t max_child, swap_index;

    while (2 * root + 1 < size)
    {
        max_child = 2 * root + 1;
        swap_index = root;

        if (array[swap_index] < array[max_child])
        {
            swap_index = max_child;
        }

        if (max_child + 1 < size && array[swap_index] < array[max_child + 1])
        {
            swap_index = max_child + 1;
        }

        if (swap_index == root)
        {
            break;
        }
        else
        {
            swap(&array[root], &array[swap_index]);
            print_array(array, sizes);
            root = swap_index;
        }
    }
}

void heapify(int* array, size_t size)
{
    size_t i;

    for (i = size / 2; i > 0; i--)
    {
        sift_down(array, i - 1, size, size);
    }
}

void heap_sort(int* array, size_t size)
{
    size_t i;

    heapify(array, size);

    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        sift_down(array, 0, i, size);
    }
}
