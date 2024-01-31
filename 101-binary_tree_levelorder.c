#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order algorithm
 *
 * @tree: A pointer to the root of the tree
 * @func: A pointer to a function to call on each node's value
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	listint_t *front, *rear, *temp;

	if (tree == NULL || func == NULL)
		return;

	front = malloc(sizeof(listint_t));
	if (front == NULL)
		return;

	front->node = (binary_tree_t *)tree;
	front->next = NULL;
	rear = front;
	if (tree && func)
	{
		while (front != NULL)
		{
			func(front->node->n);
			if (front->node->left)
			{
				rear->next = malloc(sizeof(listint_t));
				if (rear->next == NULL)
					return;
				rear = rear->next;
				rear->node = front->node->left;
				rear->next = NULL;
			}
			if (front->node->right)
			{
				rear->next = malloc(sizeof(listint_t));
				if (rear->next == NULL)
					return;
				rear = rear->next;
				rear->node = front->node->right;
				rear->next = NULL;
			}
			temp = front;
			front = front->next;
			free(temp);
		}
	}
}
