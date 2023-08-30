#include "binary_trees.h"

/**
 * bst_remove - function that removes a node from a BST
 * @root: root
 * @value: value
 * Return: node or 0
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *d_node, *successor;

	d_node = bst_search(root, value);
	if (!d_node)
		return (NULL);
	if (d_node->left && d_node->right)
	{
		for (successor = d_node->right; successor && successor->left;)
			successor = successor->left;
		d_node->n = successor->n;
		d_node = successor;
	}
	if (d_node->left)
	{
		d_node->left->parent = d_node->parent;
		if (d_node == d_node->parent->right)
			d_node->parent->right = d_node->left;
		else
			d_node->parent->left = d_node->left;
	}
	else if (d_node->right)
	{
		d_node->right->parent = d_node->parent;
		if (d_node == d_node->parent->right)
			d_node->parent->right = d_node->right;
		else
			d_node->parent->left = d_node->right;
	}
	else
	{
		if (d_node == d_node->parent->right)
			d_node->parent->right = NULL;
		else
			d_node->parent->left = NULL;
		d_node->parent = NULL;
	}
	free(d_node);
	return (root);

}

/**
 * bst_search - function that searches for a value in a BST
 * @tree: tree
 * @value: value
 * Return: pointer to the node containing a value equals to value
 */
bst_t *bst_search(bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (value == tree->n)
		return (tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	if (value > tree->n)
		return (bst_search(tree->right, value));
	return (NULL);
}
