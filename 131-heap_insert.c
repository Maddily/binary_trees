#include "binary_trees.h"

/**
 * find_parent - Finds the first parent with 1 or 0 children
 *
 * @root: A pointer to the root of a tree
 *
 * Return: A pointer to the parent
*/
heap_t *find_parent(heap_t *root)
{
	heap_t *parent = NULL;

	while (root)
	{
		parent = root;

		if (root->left && root->right)
		{
			if (!root->left->left || !root->left->right)
				return (root->left);
			if (!root->right->left || !root->right->right)
				return (root->right);
			root = root->left;
		}
		else
		{
			return (root);
		}
	}

	return (parent);
}
/**
 * heapify_up - Restores the Max Heap property
 * by swapping the node with its parent
 *
 * @node: A pointer to the newly inserted node.
 *
 * Return: A pointer to the new node after moving it
 */
heap_t *heapify_up(heap_t *node)
{
	int temp;
	heap_t *parent;

	while (node->parent && node->n > node->parent->n)
	{
		parent = node->parent;

		temp = node->n;
		node->n = node->parent->n;
		parent->n = temp;

		node = parent;
	}

	return (node);
}

/**
 * heap_insert - Inserts a value in a Max Binary Heap
 *
 * @root: A double pointer to the root of a max binary heap
 * @value: The value of the node to be inserted
 *
 * Return: A pointer to the new node or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (!*root)
	{
		new_node = binary_tree_node(NULL, value);
		if (!new_node)
			return (NULL);
		*root = new_node;
		return (*root);
	}

	parent = find_parent(*root);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	return (heapify_up(new_node));
}
