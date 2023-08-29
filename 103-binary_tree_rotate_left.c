#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function that performs
 * a left-rotation on a binary tree
 * @tree: tree
 * Return: pointer to the root node of the tree to rotate
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right_child;

	if (!tree || !tree->right)
		return (NULL);

	right_child = tree->right;
	tree->right = right_child->left;

	right_child->parent = tree->parent;
	if (!tree->parent)
		;
	else if (tree == tree->parent->right)
		tree->parent->right = right_child;
	else
		tree->parent->left = right_child;

	tree->parent = right_child;
	right_child->left = tree;

	return (right_child);
}
