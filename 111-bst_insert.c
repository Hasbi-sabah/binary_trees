#include "binary_trees.h"
#include <limits.h>

/**
 *
 *
 *
 */
bst_t *insertNode(bst_t **tree, bst_t *node)
{
	if ((*tree)->n == node->n)
		return NULL;

	if ((*tree)->n > node->n)
	{
		if ((*tree)->left)
			return (insertNode(&(*tree)->left, node));
		else
		{
			(*tree)->left = node;
			node->parent = (*tree);
			return (node);
		}
	}
	if ((*tree)->n < node->n)
	{
		if ((*tree)->right)
			return (insertNode(&(*tree)->right, node));
		else
		{
			(*tree)->right = node;
			node->parent = (*tree);
			return (node);
		}
	}
	return (NULL);

}
/**
 * binary_tree_is_bst - check if bt is bst
 * @tree: tree
 * Return: 0 or 1
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node;

	node = binary_tree_node(NULL, value);
	if (node == NULL)
		return (NULL);

	if ((*tree) == NULL)
	{
		(*tree) = node;
		return (node);
	}

	return (insertNode(tree, node));
}
