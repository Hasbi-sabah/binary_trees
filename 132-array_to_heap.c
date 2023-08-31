#include "binary_trees.h"

/**
 * array_to_heap - function that builds a Binary
 * Search Tree from an array
 * @array: array
 * @size: size
 * Return: node or NULL
 */
avl_t *array_to_heap(int *array, size_t size)
{
	int i;
	bst_t *root = NULL;

	if (!array)
		return (NULL);
	for (i = 0; i < (int)size; i++)
		heap_insert(&root, array[i]);
	return (root);
}
