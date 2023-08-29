#include "binary_trees.h"
#include <limits.h>

/**
 *
 *
 */
bst_t *insert_node(bst_t **tree, bst_t *node)
{
	if (tree == NULL)
		return (*tree);

	if ((*tree)->n > node->n)
		(*tree)->left = insert_node(tree, node);
	else if ((*tree)->n < node->n)
		(*tree)->right = insert_node(tree, node);

	return (node);
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
	if (!(*tree))
		return (node);

	return (insert_node(tree, node));
}
