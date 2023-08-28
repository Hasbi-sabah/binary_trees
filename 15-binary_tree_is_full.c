#include "binary_trees.h"

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return 0;
	if (binary_tree_is_leaf(tree) || binary_tree_is_dble_parent(tree))
		return 1;
	return 0;
}

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return 0;
	if (!node->left && !node->right)
		return 1;
	return 0;
}

int binary_tree_is_dble_parent(const binary_tree_t *node)
{
	if (!node)
		return 0;
	if (node->left && node->right && (binary_tree_is_dble_parent(node->left) || binary_tree_is_leaf(node->left)) && (binary_tree_is_dble_parent(node->right) || binary_tree_is_leaf(node->right)))
		return 1;
	return 0;
}
