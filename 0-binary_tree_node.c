#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: parent
 * @value: value
 * Return: pointer to the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->parent = parent;
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
