#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes a binary tree
 *
 * @tree: A pointer to the root node of a tree
*/
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	free(tree);
}
