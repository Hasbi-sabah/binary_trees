#include "binary_trees.h"

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return 0;
	if (!binary_tree_balance(tree) && binary_tree_is_full(tree))
		return 1;
	return 0;
}

int binary_tree_balance(const binary_tree_t *tree)
{
	int h_l = 0, h_r = 0;
	if (!tree)
		return 0;
	if (tree->left)
		h_l = 1 + binary_tree_height(tree->left);
	if (tree->right)
		h_r = 1 + binary_tree_height(tree->right);
	return (h_l - h_r);
}

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lv, rv, max;

	if (tree == NULL)
		return 0;

	lv = tree->left? 1 + binary_tree_height(tree->left): 0;
	rv = tree->right? 1 + binary_tree_height(tree->right): 0;

	max = lv > rv? lv : rv;
	return (max);
}
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return 0;
	if ((!tree->left && !tree->right) || binary_tree_is_dble_parent(tree))
		return 1;
	return 0;
}

int binary_tree_is_dble_parent(const binary_tree_t *node)
{
	if (!node)
		return 0;
	if (node->left && node->right && (binary_tree_is_dble_parent(node->left) || (!node->left->left && !node->left->right)) && (binary_tree_is_dble_parent(node->right) || (!node->right->left && !node->right->right)))
		return 1;
	return 0;
}
