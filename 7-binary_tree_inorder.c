#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses a binary tree
 * using in-order algorithm.
 *
 * @tree: A pointer to the root of a tree
 * @func: A pointer to a function to call on each node
 * The function is passed the value of the node.
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	if (tree->left)
		binary_tree_inorder(tree->left, func);

	func(tree->n);

	if (tree->right)
		binary_tree_inorder(tree->right, func);
}
