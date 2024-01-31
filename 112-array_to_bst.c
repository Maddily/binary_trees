#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 *
 * @array: An array of values
 * @size: The size of the array
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure
*/
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *inserted_node, *tree = NULL;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		inserted_node = bst_insert(&tree, array[i]);
		if (inserted_node == NULL)
			return (NULL);
		if (i == 0)
			tree = inserted_node;
	}

	return (tree);
}
