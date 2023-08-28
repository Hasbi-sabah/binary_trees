#include "binary_trees.h"


/**
 * binary_tree_sibling - get a node's sibiling
 * @node: the node
 * Return: pointer to the sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *root;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	root = node->parent;
	if (root->left == NULL || root->right == NULL)
		return (NULL);

	if (root->left->n == node->n)
		return (root->right);
	else
		return (root->left);
}
