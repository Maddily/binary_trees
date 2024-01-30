#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: A pointer to a node in a binary tree
 *
 * Return: The height, or 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		height_left = 1 + binary_tree_height(tree->left);
	else
		height_left = 1;
	if (tree->right)
		height_right = 1 + binary_tree_height(tree->right);
	else
		height_right = 1;

	return (MAX(height_left, height_right));
}

/**
 * binary_tree_balance - Finds the balance factor of a tree
 *
 * @tree: A pointer to the root node of a tree
 *
 * Return: The balance factor
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
