#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 *
 * @tree: A pointer to a node in a binary tree
 *
 * Return: The depth of the tree
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL || tree->parent == NULL)
		return (0);

	if (tree->parent)
		depth = binary_tree_depth(tree->parent);

	return (depth + 1);
}
