#include <stdlib.h>
#include "binary_trees.h"

/**
 * tree_height - Calculate the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree
 */
size_t tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree)
        return (0);

    left_height = tree_height(tree->left);
    right_height = tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * tree_parent - Find the parent of a node in a binary tree
 * @root: Pointer to the root node of the tree
 * @node: Pointer to the node for which to find the parent
 * Return: Pointer to the parent node
 */
binary_tree_t *tree_parent(binary_tree_t *root, const binary_tree_t *node)
{
    if (!root || !node)
        return (NULL);

    if (root->left == node || root->right == node)
        return (root);

    if (tree_parent(root->left, node))
        return (tree_parent(root->left, node));
    return (tree_parent(root->right, node));
}

/**
 * swap_nodes - Swap the values of two binary tree nodes
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_nodes(binary_tree_t *node1, binary_tree_t *node2)
{
    int temp;

    temp = node1->n;
    node1->n = node2->n;
    node2->n = temp;
}

/**
 * heapify_down - Heapify the heap down from a given node
 * @node: Pointer to the node from which to heapify down
 */
void heapify_down(binary_tree_t *node)
{
    binary_tree_t *largest, *left, *right;

    while (1)
    {
        largest = node;
        left = node->left;
        right = node->right;

        if (left && left->n > largest->n)
            largest = left;

        if (right && right->n > largest->n)
            largest = right;

        if (largest == node)
            break;

        swap_nodes(node, largest);
        node = largest;
    }
}

/**
 * heap_extract - Extract the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: Value stored in the root node
 */
int heap_extract(heap_t **root)
{
    int value;
    size_t height;
    binary_tree_t *last_node;

    if (!root || !*root)
        return (0);

    value = (*root)->n;
    height = tree_height(*root);

    if (height == 1)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    last_node = tree_parent(*root, *root + ((1 << (height - 1)) - 2));
    if (last_node->right)
    {
        (*root)->n = last_node->right->n;
        free(last_node->right);
        last_node->right = NULL;
    }
    else
    {
        (*root)->n = last_node->left->n;
        free(last_node->left);
        last_node->left = NULL;
    }

    heapify_down(*root);

    return (value);
}
