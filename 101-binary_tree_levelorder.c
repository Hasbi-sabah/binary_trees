#include "binary_trees.h"
#include <stdlib.h>


size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return 0;

	return 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
}

void saver(const binary_tree_t *tree, int *tree_arr, int index)
{
	if (!tree)
		return;
	tree_arr[index] = tree->n;
	if (tree->left)
		saver(tree->left, tree_arr, (2 * index) + 1);
	if (tree->right)
		saver(tree->right, tree_arr, (2 * index) + 2);
}

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int size, i;
	int *tree_arr;

	if (!tree || !func)
		return; 
	size = binary_tree_size(tree);
	tree_arr = calloc(size, sizeof(int));
	saver(tree, tree_arr, 0);
	for (i = 0; i < size; i++)
		func(tree_arr[i]);
	free(tree_arr);
}
