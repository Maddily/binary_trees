#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree
 * using post-order algorithm.
 *
 * @tree: A pointer to the root of a tree
 * @func: A pointer to a function to call on each node
 * The function is passed the value of the node.
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	if (tree->left)
		binary_tree_postorder(tree->left, func);

	if (tree->right)
		binary_tree_postorder(tree->right, func);

	func(tree->n);
}
