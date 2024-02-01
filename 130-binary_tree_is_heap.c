#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: A pointer to the root node of a binary tree
 *
 * Return: The size of the tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_complete_recursive - Helper function that checks if
 * a binary tree is complete
 *
 * @tree: A pointer to a node
 * @index: The index of the node
 * @size: The number of nodes
 *
 * Return: 1 if complete, 0 otherwise
*/
int is_complete_recursive(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete_recursive(tree->left, 2 * index + 1, size) &&
		is_complete_recursive(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: A pointer to the root of a binary tree
 *
 * Return: 1 if complete, 0 otherwise
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_complete_recursive(tree, 0, binary_tree_size(tree)));
}

/**
 * binary_tree_is_heap_helper - Checks if a binary tree
 * is a valid Max Binary Heap
 *
 * @tree: A pointer to the root of a tree
 *
 * Return: 1 if it's a max binary heap, 0 otherwise
*/
int binary_tree_is_heap_helper(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if ((tree->left && tree->n < tree->left->n) ||
	(tree->right && tree->n < tree->right->n))
		return (0);

	if (!binary_tree_is_complete(tree))
		return (0);

	return (binary_tree_is_heap_helper(tree->left) &&
		binary_tree_is_heap_helper(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 *
 * @tree: A pointer to the root of a tree
 *
 * Return: 1 if it's a max binary heap, 0 otherwise
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_heap_helper(tree));
}
