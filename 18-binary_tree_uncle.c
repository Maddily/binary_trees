#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 *
 * @node: A pointer to a node whose sibling is to be found
 *
 * Return: A pointer to the sibling
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	return (
		node->parent->left == node ?
		node->parent->right : node->parent->left
	);
}

/**
 * binary_tree_uncle - Finds the uncle of a node
 *
 * @node: A pointer to the node whose uncle is to be located
 *
 * Return: A pointer to the uncle
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}
