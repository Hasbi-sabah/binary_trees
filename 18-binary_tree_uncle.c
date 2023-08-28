#include "binary_trees.h"


/**
 *
 *
 *
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *ancestor;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	ancestor = node->parent;
	if (ancestor->left == NULL || ancestor->right == NULL)
		return (NULL);

	if (ancestor->left->n == node->n)
		return (ancestor->right);
	else
		return (ancestor->left);
}

/**
 * binary_tree_uncle - 
 *
 *
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *ancestor, *uncle;

	if (node == NULL || node->parent == NULL)
                return (NULL);

	ancestor = node->parent;
	uncle = binary_tree_sibling(ancestor);

	return (uncle);
}
