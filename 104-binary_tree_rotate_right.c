#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function that performs
 * a right-rotation on a binary tree
 * @tree: tree
 * Return: pointer to the root node of the tree to rotate
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *left_child;

	if (!tree || !tree->left)
		return (NULL);

	left_child = tree->left;
	if (left_child->right)
		left_child->right->parent = tree;
	tree->left = left_child->right;

	left_child->parent = tree->parent;
	if (!tree->parent)
		;
	else if (tree == tree->parent->right)
		tree->parent->right = left_child;
	else
		tree->parent->left = left_child;

	tree->parent = left_child;
	left_child->right = tree;

	return (left_child);
}
