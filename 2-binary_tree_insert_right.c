#include "binary_trees.h"


/**
 *
 *
 *
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *tmp;

	if (parent == NULL)
		return NULL;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return NULL;

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	/**check parent->right if not null **/
	if (parent->right != NULL)
	{
		tmp = parent->right;
		node->right = tmp;
		node->right->parent = node;
	}

	parent->right = node;
	return node;
}
