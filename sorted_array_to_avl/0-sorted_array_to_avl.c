#include "binary_trees.h"

/**
 * sorted_array_to_avl - Transforms a sorted array into a balanced AVL tree
 *
 * @array: Pointer to the first element of the sorted array of integers
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the tree, or NULL if the array is empty
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (sorted_array_to_avl_recursive(array, 0, size - 1));
}

/**
 * add_node - Adds a node to the AVL tree
 *
 * @n: The value to add to the node
 *
 * Return: A pointer to the new node, or NULL if the node could not be created.
 */
avl_t *add_node(int n)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);

	node->n = n;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * sorted_array_to_avl_recursive - Creates an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the sorted array
 * @start: The starting index of the subarray to be processed
 * @end: The ending index of the subarray to be processed
 *
 * Return: A pointer to the root of the AVL tree, or NULL if an error occurred
 */
avl_t *sorted_array_to_avl_recursive(int *array, int start, int end)
{
	int mid = (start + end) / 2;
	avl_t *root;

	if (start > end)
		return (NULL);

	root = add_node(array[mid]);
	if (!root)
		return (NULL);
	root->left = sorted_array_to_avl_recursive(array, start, mid - 1);
	if (root->left)
		root->left->parent = root;

	root->right = sorted_array_to_avl_recursive(array, mid + 1, end);
	if (root->right)
		root->right->parent = root;

	return (root);
}
