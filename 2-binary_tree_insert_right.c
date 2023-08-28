#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - function that inserts a node
 * as the right-child of another node
 * @parent: parent
 * @value: value
 * Return: pointer to the created node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	if (parent->right)
	{
		node->right = parent->right;
		parent->right->parent = node;
	}
	else
		node->right = NULL;
	node->n = value;
	node->left = NULL;
	node->parent = parent;
	parent->right = node;
	return (node);
}
