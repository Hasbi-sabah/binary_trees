#include "binary_trees.h"


/**
 * binary_tree_height - calculate the height of a binary tree
 * @tree: the binary tree
 * Return: number of nodes
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lv, rv, max;

	if (tree == NULL)
		return (0);

	lv = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	rv = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	max = lv > rv ? lv : rv;
	return (max);
}

/**
 * binary_tree_balance - check if a binary tree is balanced or not
 * Description: check if all nodes have a left/right nodes
 *
 * @tree: the binary tree
 * Return: 0 not balanced | 1 balanced
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t lv, rv;

	if (tree == NULL)
		return (0);

	lv = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	rv = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (lv - rv);
}
