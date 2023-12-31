#include "binary_trees.h"

/**
 * binary_tree_leaves - calculate the number of leaves in a binary tree
 * @tree: the binary tree
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int flag = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		flag = 1;
	flag += binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
	return (flag);
}
