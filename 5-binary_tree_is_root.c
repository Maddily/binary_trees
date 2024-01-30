#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is the root node
 *
 * @node: A pointer to a node in a binary tree
 *
 * Return: 1 if the node is the root, 0 otherwise
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node != NULL && node->parent == NULL);
}
