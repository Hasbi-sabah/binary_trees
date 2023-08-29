#include "binary_trees.h"
#include <limits.h>

/**
 * insertNode - insert node helper
 * @tree: BST
 * @node: node to isnert
 * Return: node (success) | NULL (failed)
 */
bst_t *insertNode(bst_t **tree, bst_t *node)
{
	if ((*tree)->n == node->n)
	{
		free(node);
		return (NULL);
	}

	if ((*tree)->n > node->n)
	{
		if ((*tree)->left)
			return (insertNode(&(*tree)->left, node));

		(*tree)->left = node;
		node->parent = (*tree);
		return (node);
	}
	else
	{
		if ((*tree)->right)
			return (insertNode(&(*tree)->right, node));

		(*tree)->right = node;
		node->parent = (*tree);
		return (node);
	}
}
/**
 * bst_insert - insert a new node in a BST
 * @tree: tree
 * @value: value of the new node
 * Return: node (success) | NULL (failed)
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node;

	node = binary_tree_node(NULL, value);
	if (node == NULL)
		return (NULL);

	if ((*tree) == NULL || !tree)
	{
		(*tree) = node;
		return (node);
	}

	return (insertNode(tree, node));
}
