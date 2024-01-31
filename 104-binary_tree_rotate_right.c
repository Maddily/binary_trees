#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 *
 * @tree: A pointer to the root of a binary tree
 *
 * Return: A pointer to the new root of the rotated tree
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *old_root, *new_root, *old_right;

	if (tree == NULL)
		return (NULL);

	old_root = tree;
	new_root = old_root->left;
	old_right = new_root->right;

	new_root->right = old_root;
	new_root->parent = old_root->parent;

	old_root->left = old_right;
	old_root->parent = new_root;

	if (old_right)
		old_right->parent = old_root;

	return (new_root);
}
