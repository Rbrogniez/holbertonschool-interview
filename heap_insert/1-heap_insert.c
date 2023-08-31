#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: Root of the tree
 * Return: The size
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t s = 0;

	if (!tree)
		return (0);

	s = binary_tree_size(tree->left) + binary_tree_size(tree->right);

	return (s + 1);
}

/**
 * find_parent - Find the parent for the first empty place
 *
 * @root: Root of the tree
 * @i: Index of the parent wanted
 * @size: Size of the tree
 * Return: The node with the place
 */

heap_t *find_parent(heap_t *root, size_t i, size_t size)
{
	heap_t *left, *right;

	if (i == size)
		return (root);
	if (i > size)
		return (NULL);

	left = find_parent(root->left, 2 * i + 1, size);
	right = find_parent(root->right, 2 * i + 2, size);

	if (left)
		return (left);
	else if (right)
		return (right);
	else
		return (NULL);
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 *
 * @root: Root of the tree
 * @value: Value to insert
 * Return: The new node
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node, *parent, *temp;
	size_t size;
	int t;

	if (!root)
		return (NULL);
	node = binary_tree_node(NULL, value);
	if (!node)
		return (NULL);
	if (!(*root))
	{
		*root = node;
		return (node);
	}
	size = binary_tree_size(*root);
	parent = find_parent(*root, 0, (size - 1) / 2);
	if (!parent->left)
		parent->left = node;
	else
		parent->right = node;
	node->parent = parent;

	temp = node;
	while (temp->parent && temp->n > temp->parent->n)
	{
		t = temp->n;
		temp->n = temp->parent->n;
		temp->parent->n = t;
		temp = temp->parent;
	}

	return (temp);
}
