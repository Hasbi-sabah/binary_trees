#include "binary_trees.h"
#include <stdlib.h>

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;
	
	if (!parent)
		return NULL;
	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return NULL;
	if (parent->left)
	{
		node->left = parent->left;
		parent->left->parent = node;
	}
	else
		node->left = NULL;
	node->n = value;
	node->right = NULL;
	node->parent = parent;
	parent->left = node;
	return node;
}
