#include "binary_trees.h"
#include <limits.h>

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return inorder(tree, INT_MIN);
}
int inorder(const binary_tree_t *tree, int prev)
{
	if (!tree)
		return (1);
	if (!inorder(tree->left, prev))
		return (0);
	if (prev > tree->n)
		return (0);
	prev = tree->n;
	return (inorder(tree->right, prev));
}
