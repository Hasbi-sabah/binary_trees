#include "binary_trees.h"


/**
 * _pow - calculate the power of a number
 * @x: number
 * @y: power
 * Return: @n power of @y
 */
int _pow(int x, int y)
{

	if (y == 0)
		return (1);
	if (y > 0)
		return (x * _pow(x, y - 1));
	return (-1);
}

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
 * binary_tree_size - get the size of a binary tree
 * @tree: the binary tree
 * Return: number of nodes in the binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size++;
	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);
	return (size);
}

/**
 * binary_tree_is_perfect - check if a binary tree is perfect (balanced & full)
 * @tree: the binary tree
 * Return: 0 (not perfect) | 1 (perfect)
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int size, height;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	size = _pow(2, height + 1) - 1;

	if (size == (int)binary_tree_size(tree))
		return (1);

	return (0);
}
