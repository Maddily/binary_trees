#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

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

/**
 * struct listint_s - singly linked list
 * @node: A pointer to a node in a binary tree
 * @next: points to the next node in the list
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
	binary_tree_t *node;
	struct listint_s *next;
} listint_t;

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
/* Measures the depth of a node in a binary tree */
size_t binary_tree_depth(const binary_tree_t *tree);
/* Measures the size of a binary tree */
size_t binary_tree_size(const binary_tree_t *tree);
/* Counts the leaves in a binary tree */
size_t binary_tree_leaves(const binary_tree_t *tree);
/* Counts the nodes with at least one child in a binary tree */
size_t binary_tree_nodes(const binary_tree_t *tree);
/* Measures the balance factor of a binary tree */
int binary_tree_balance(const binary_tree_t *tree);
/* Checks if a binary tree is full */
int binary_tree_is_full(const binary_tree_t *tree);
/* Checks if a binary tree is perfect */
int binary_tree_is_perfect(const binary_tree_t *tree);
/* Finds the sibling of a node */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
/* Finds the uncle of a node */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
/* Finds the lowest common ancestor of two nodes */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second);
/* Traverses a binary tree using level-order algorithm */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
/* Checks if a binary tree is complete */
int binary_tree_is_complete(const binary_tree_t *tree);
/* Performs a left-rotation on a binary tree */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
/* Performs a right-rotation on a binary tree */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

void binary_tree_print(const binary_tree_t *tree);

#endif
