#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf.
 *
 * @node: A pointer to a node in a binary tree
 *
 * Return: 1 if the node is a leaf, 0 otherwise
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return (node != NULL && node->left == NULL && node->right == NULL);
}
