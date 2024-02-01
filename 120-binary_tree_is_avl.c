#include "binary_trees.h"

/**
 * has_duplicates_helper - Recursively checks if a tree
 * has duplicate values
 *
 * @tree: A pointer to the root of a tree
 * @prev_value: A pointer to the previous value
 *
 * Return: 1 if there are duplicate values, 0 otherwise
*/
int has_duplicates_helper(const binary_tree_t *tree, int *prev_value)
{
	if (tree == NULL)
		return (0);

	if (has_duplicates_helper(tree->left, prev_value))
		return (1);

	if (*prev_value == tree->n)
		return (1);

	*prev_value = tree->n;

	return (has_duplicates_helper(tree->right, prev_value));
}

/**
 * has_duplicates - Checks if a tree has duplicate values
 *
 * @tree: A pointer to the root of a tree
 *
 * Return: 1 if there are duplicate values, 0 otherwise
*/
int has_duplicates(const binary_tree_t *tree)
{
	int prev_value = 0;

	return (has_duplicates_helper(tree, &prev_value));
}

/**
 * is_bst_helper - Checks if a binary tree is a binary search tree
 *
 * @tree: A pointer to the root of a binary tree
 * @left_boundary: The left boundary for the value of a node
 * @right_boundary: The right boundary for the value of a node
 *
 * Return: 1 if it's a valid binary search tree, 0 otherwise
*/
int is_bst_helper(const binary_tree_t *tree, int left_boundary,
	int right_boundary)
{
	if (tree == NULL)
		return (1);
	if (tree->n > right_boundary || tree->n < left_boundary)
		return (0);

	return (is_bst_helper(tree->left, left_boundary, tree->n) &&
	is_bst_helper(tree->right, tree->n, right_boundary));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a binary search tree
 *
 * @tree: A pointer to the root of a binary tree
 *
 * Return: 1 if it's a valid binary search tree, 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL || has_duplicates(tree))
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

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

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 *
 * @tree: A pointer to the root of a tree
 *
 * Return: 1 if it's a valid AVL tree, 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance_factor;

	if (tree == NULL)
		return (1);

	if (!binary_tree_is_bst(tree))
		return (0);

	balance_factor = binary_tree_balance(tree);
	if (balance_factor >= -1 && balance_factor <= 1)
		return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));

	return (0);
}
