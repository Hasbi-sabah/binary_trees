#include "binary_trees.h"

/**
 * array_to_bst - function that builds a Binary
 * Search Tree from an array
 * @array: array
 * @size: size
 * Return: node or NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	int i;
	bst_t *root = NULL;

	if (!array)
		return (NULL);
	for (i = 0; i < (int)size; i++)
		bst_insert(&root, array[i]);
	return (root);
}
