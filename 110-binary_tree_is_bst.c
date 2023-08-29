#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_bst - check if bt is bst
 * @tree: tree
 * Return: 0 or 1
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev;

	if (!tree)
		return (0);
	prev = INT_MIN;
	return (inorder(tree, &prev));
}

/**
 * inorder - helper
 * @tree: tree
 * @prev: prev
 * Return: 0 or 1
 */
int inorder(const binary_tree_t *tree, int *prev)
{
	if (!tree)
		return (1);
	if (!inorder(tree->left, prev))
		return (0);
	if (*prev >= tree->n)
		return (0);
	*prev = tree->n;
	return (inorder(tree->right, prev));
}
