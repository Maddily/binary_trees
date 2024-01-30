#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>


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

/*Binary Tree*/
typedef struct binary_tree_s binary_tree_t;

/*Binary Search Tree*/
typedef struct binary_tree_s bst_t;

/*AVL Tree*/
typedef struct binary_tree_s avl_t;

/*Max Binary Heap*/
typedef struct binary_tree_s heap_t;

/* Creates a binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
/* Inserts a node as the left child of another node */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
/* Inserts a node as the right child of another node */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
/* Deletes a binary tree */
void binary_tree_delete(binary_tree_t *tree);
/* Checks if a node is a leaf */
int binary_tree_is_leaf(const binary_tree_t *node);
/* Checks if a node is the root node */
int binary_tree_is_root(const binary_tree_t *node);
/* Traverses a binary tree using pre-order algorithm */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
/* Traverses a binary tree using in-order algorithm */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
/* Traverses a binary tree using post-order algorithm */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
/* Measures the height of a binary tree */
size_t binary_tree_height(const binary_tree_t *tree);
/* Recursive function to find height */
size_t binary_tree_traverse_n_count_side(const binary_tree_t *tree);
/* Measures the depth of a node in a binary tree */
size_t binary_tree_depth(const binary_tree_t *tree);
/* Recursive function to find depth */
size_t binary_tree_traverse_n_count_depth(const binary_tree_t *tree);
/* Measures the size of a binary tree */
size_t binary_tree_size(const binary_tree_t *tree);
/* Counts the leaves in a binary tree */
size_t binary_tree_leaves(const binary_tree_t *tree);
/* Counts the nodes with at least one child in a binary tree */
size_t binary_tree_nodes(const binary_tree_t *tree);


void binary_tree_print(const binary_tree_t *tree);

#endif
