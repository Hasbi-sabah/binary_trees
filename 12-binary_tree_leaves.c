#include "binary_trees.h"

/**
 * binary_tree_leaves - 
 *
 *
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t size = 0;
	if (tree == NULL)
		return 0;

	if (tree->left)
		size += 1;
	if (tree->right)
		size += 1;

	if (!tree->left && !tree->right)
		return (1);

	return (size);
}
