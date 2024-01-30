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
	size_t height_left, height_right;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	height_left = binary_tree_traverse_n_count_side(tree->left);
	height_right = binary_tree_traverse_n_count_side(tree->right);

	return ((height_left >= height_right) ? height_left + 1 : height_right + 1);
}

/**
 * binary_tree_traverse_n_count_side - Traverses a binary tree
 * and counts the edges
 *
 * @tree: A pointer to a node in a binary tree
 *
 * Return: The height of the tree
*/
size_t binary_tree_traverse_n_count_side(const binary_tree_t *tree)
{
	size_t height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
	{
		height += 1 + binary_tree_traverse_n_count_side(tree->left);
	}
	if (tree->right)
	{
		height += 1 + binary_tree_traverse_n_count_side(tree->right);
	}

	return (height);
}
