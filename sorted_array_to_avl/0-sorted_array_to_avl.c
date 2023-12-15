#include "binary_trees.h"
#include <stdlib.h>

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    /* Allocate memory for new node */
    avl_t *new_node = malloc(sizeof(avl_t));
    if (new_node == NULL)
        return (NULL);

    /* Initialize the AVL tree nodes */
    size_t mid = size / 2;
    new_node->n = array[mid];
    new_node->parent = NULL;
    new_node->left = sorted_array_to_avl(array, mid);
    new_node->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);

    return (new_node);
}
