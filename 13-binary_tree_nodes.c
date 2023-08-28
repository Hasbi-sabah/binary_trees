#include "binary_trees.h"

/**
 * binary_tree_nodes - count nodes with at least one child in a binary tree
 * @tree: the binary tree
 * Return: number of nodes with at least one child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	if (tree->left || tree->right)
	{
		size++;
		if (tree->left)
			size += binary_tree_nodes(tree->left);
		if (tree->right)
			size += binary_tree_nodes(tree->right);
	}
	return (size);
}
