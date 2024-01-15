#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

size_t tree_height(const binary_tree_t *tree);
binary_tree_t *tree_parent(binary_tree_t *root, const binary_tree_t *node);
void swap_nodes(binary_tree_t *node1, binary_tree_t *node2);
void heapify_down(binary_tree_t *node);
int heap_extract(heap_t **root);

void binary_tree_print(const binary_tree_t *tree);
void binary_tree_print_aux(const binary_tree_t *tree, size_t level);

#endif /* BINARY_TREES_H */
