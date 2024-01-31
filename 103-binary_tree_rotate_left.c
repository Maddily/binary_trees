#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 *
 * @tree: A pointer to the root of a binary tree
 *
 * Return: A pointer to the new root of the rotated tree
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *old_root, *new_root, *old_left;

	if (tree == NULL)
		return (NULL);

	old_root = tree;
	new_root = old_root->right;
	old_left = new_root->left;

	new_root->left = old_root;
	new_root->parent = NULL;

	old_root->right = old_left;
	old_root->parent = new_root;

	return (new_root);
}
