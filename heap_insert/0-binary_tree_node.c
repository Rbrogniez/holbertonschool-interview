#include "binary_trees.h"

/**
 * binary_tree_node - Create a node
 *
 * @parent: Parent of the node
 * @value: value of the node
 * Return: The node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);

	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->n = value;

	return (node);
}
