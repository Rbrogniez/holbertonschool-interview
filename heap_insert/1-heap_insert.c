#include <stdlib.h>
#include "binary_trees.h"

/**
 * swap - Swaps two node values.
 * @a: First node to swap.
 * @b: Second node to swap.
 */
void swap(heap_t **a, heap_t **b)
{
    int temp = (*a)->n;
    (*a)->n = (*b)->n;
    (*b)->n = temp;
}

/**
 * heapify - Fixes the Max Heap property after insertion.
 * @node: Node to start heapifying from.
 */
void heapify(heap_t *node)
{
    heap_t *largest = node;
    if (node->left && node->left->n > largest->n)
        largest = node->left;
    if (node->right && node->right->n > largest->n)
        largest = node->right;

    if (largest != node)
    {
        swap(&node, &largest);
        heapify(largest);
    }
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * @value: Value to store in the new node.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node = binary_tree_node(*root, value);
    if (!new_node)
        return (NULL);

    if (!*root)
    {
        *root = new_node;
        return (new_node);
    }

    heap_t *temp = *root;
    while (temp->left && temp->right)
    {
        if (temp->left && temp->right)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (!temp->left)
        temp->left = new_node;
    else
        temp->right = new_node;

    while (new_node->parent && new_node->parent->n < new_node->n)
    {
        swap(&new_node->parent, &new_node);
        new_node = new_node->parent;
    }

    return (new_node);
}
