#include "binary_trees.h"


/**
 * binary_tree_is_full - check of all nodes have a left/right nodes
 * @tree: the binary tree
 * Return: 0 (not full) | 1 (full)
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int sl = 0, sr = 0;

	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
	{
		sl = binary_tree_is_full(tree->left);
		sr =  binary_tree_is_full(tree->right);
	}
	if (sl == 0 || sr == 0)
		return (0);

	return (1);
}
