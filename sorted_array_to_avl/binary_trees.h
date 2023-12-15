#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/* Basic Binary Tree Structure */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;

/* AVL Tree Structure */
typedef struct binary_tree_s avl_t;

/* Function Prototype */
avl_t *sorted_array_to_avl(int *array, size_t size);

#endif /* BINARY_TREES_H */
