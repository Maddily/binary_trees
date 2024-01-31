#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 *
 * @tree: A pointer to the root of a binary search tree
 * @value: The value for which to be searched
 *
 * Return: A pointer to the node containing the value
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	return (
		value < tree->n ?
		bst_search(tree->left, value) : bst_search(tree->right, value)
		);
}
