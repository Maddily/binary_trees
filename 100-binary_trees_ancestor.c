#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 *
 * @tree: A pointer to a node in a binary tree
 *
 * Return: The depth of the tree
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL || tree->parent == NULL)
		return (0);

	if (tree->parent)
		depth = binary_tree_depth(tree->parent);

	return (depth + 1);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	if (first == NULL || second == NULL)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	if (depth_first == depth_second)
		return (first->parent);
	else if (depth_first < depth_second && second->parent == first)
		return ((binary_tree_t *)first);
	else if (depth_second < depth_first && first->parent == second)
		return ((binary_tree_t *)second);
	else
		return (depth_first < depth_second ? first->parent : second->parent);

	return (NULL);
}
