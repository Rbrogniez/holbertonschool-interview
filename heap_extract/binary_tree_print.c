#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_print - Print binary tree
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
    if (!tree)
        return;

    binary_tree_print_aux(tree, 0);
}

/**
 * binary_tree_print_aux - Print binary tree (Auxiliary function)
 * @tree: Pointer to the root node of the tree to print
 * @level: Level of the tree
 */
void binary_tree_print_aux(const binary_tree_t *tree, size_t level)
{
    size_t i;

    if (!tree)
        return;

    binary_tree_print_aux(tree->right, level + 1);

    for (i = 0; i < level; i++)
        printf("    ");

    printf("%d\n", tree->n);

    binary_tree_print_aux(tree->left, level + 1);
}
