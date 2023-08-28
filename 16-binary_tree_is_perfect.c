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
 * binary_tree_balance - check if the binary tree is balanced.
 * @tree: the binary tree
 * Return: 0 (not balanced) | 1 (balanced)
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

/**
 * binary_tree_is_perfect - check if a binary tree is perfect (balanced & full)
 * @tree: the binary tree
 * Return: 0 (not perfect) | 1 (perfect)
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int balanced, full;

	balanced = binary_tree_balance(tree);
	full = binary_tree_is_full(tree);

	if (!balanced && full)
		return (1);

	return (0);
}
