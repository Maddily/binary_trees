#include "binary_trees.h"

/**
 * find_parent - Finds the parent to which a child is to be given
 *
 * @tree: A pointer to the root of a binary search tree
 * @value: The value of the node to be inserted
 *
 * Return: A pointer to the parent to which a child is to be given
*/
bst_t *find_parent(bst_t *tree, int value)
{
	bst_t *parent = NULL;

	while (tree)
	{
		parent = tree;

		if (value < tree->n)
			tree = tree->left;
		else if (value > tree->n)
			tree = tree->right;
		else
			return (NULL);
	}

	return (parent);
}

/**
 * bst_insert - Inserts a node into a binary search tree
 *
 * @tree: A double pointer to the root node of a BST
 * @value: The value of the new node
 *
 * Return: A pointer to the new node or NULL on failure
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *parent;

	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		if (new_node == NULL)
			return (NULL);
		*tree = new_node;
		return (*tree);
	}
	else
	{
		parent = find_parent(*tree, value);
		if (parent == NULL)
			return (NULL);

		new_node = binary_tree_node(parent, value);
		if (new_node == NULL)
			return (NULL);

		if (value < parent->n)
			parent->left = new_node;
		else
			parent->right = new_node;

		return (new_node);
	}
}
