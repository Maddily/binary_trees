#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least
 * one child in a binary tree.
 *
 * @tree: A pointer to the root node in a binary tree
 *
 * Return: The number of nodes with at least one child
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes_left, nodes_right;

	if (tree == NULL)
		return (0);

	nodes_left = binary_tree_nodes(tree->left);
	nodes_right = binary_tree_nodes(tree->right);

	if (tree->left || tree->right)
		return (1 + nodes_left + nodes_right);

	return (0);
}
