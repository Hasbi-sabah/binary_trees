#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_l, h_r;

	if (tree->left)
		h_l = 1 + binary_tree_height(tree->left);
	else
		h_l = 0;

	if (tree->right)
		h_r = 1 + binary_tree_height(tree->right);
	else
		h_r = 0;

	if (h_l > h_r)
		return h_l;
	return h_r;
}
