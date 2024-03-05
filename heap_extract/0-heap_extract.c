#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 *
 * @root: A pointer to the root node of the heap.
 *
 * Return: The value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	int root_value;
	heap_t *last_node;

	if (!root || !*root)
		return (0);

	root_value = (*root)->n;
	last_node = find_last_node(*root);

	if (last_node)
	{
		(*root)->n = last_node->n;

		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;
		free(last_node);
	}
	else
	{
		free(*root);
		*root = NULL;
	}

	if (*root)
		heapify_down(*root);

	return (root_value);
}

/**
 * free_node - Frees a node from memory.
 *
 * @node: node to free
 */
void free_node(heap_t *node)
{
	if (node)
	{
		node->parent = NULL;
		if (node->left)
			node->left->parent = NULL;
		if (node->right)
			node->right->parent = NULL;
		node->left = NULL;
		node->right = NULL;
		free(node);
	}
}

/**
 * heapify_down - Heapifies a heap from the root down.
 *
 * @node: The node to start heapifying from.
 */
void heapify_down(heap_t *node)
{
	int temp;
	heap_t *largest = node, *left = node->left, *right = node->right;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;

	if (largest != node)
	{
		temp = node->n;
		node->n = largest->n;
		largest->n = temp;

		heapify_down(largest);
	}
}

/**
 * find_last_node - Finds the last node in a heap.
 *
 * @node: The starting node.
 *
 * Return: The last node in the heap.
 */
heap_t *find_last_node(heap_t *node)
{
	heap_t *queue[100], *last = NULL;
	int front = 0, rear = 0;

	if (!node)
		return (NULL);

	if (!node->parent && !node->left && !node->right)
		return (NULL);

	queue[rear++] = node;

	while (front < rear)
	{
		last = queue[front];
		front++;

		if (last->left)
			queue[rear++] = last->left;
		if (last->right)
			queue[rear++] = last->right;
	}

	return (last);
}
