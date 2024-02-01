#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array
 *
 * @array: A pointer to the first element of the array
 * @size: The size of the array
 *
 * Return: A pointer to the root node of the heap or NULL on failure
*/
heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;
	heap_t *tree = NULL, *new_node;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		new_node = heap_insert(&tree, array[i]);
		 binary_tree_print(tree);
		if (!new_node)
			return (NULL);
	}

	return (tree);
}
