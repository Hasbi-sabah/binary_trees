#include "binary_trees.h"
#include <limits.h>
#include <math.h>

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
 * update_avl - fix avl tree after inserting a node
 * @node: node inserted
 */
void update_avl(avl_t *node)
{
	size_t isBalanced;

	if (node->parent->parent == NULL)
		return;

	isBalanced = binary_tree_balance(node->parent->parent);

	if (abs((int)isBalanced) <= 1)
		return;

	if ((int)isBalanced < 0)
	{
		if (node->parent->left == node)
		{
			node = binary_tree_rotate_right(node->parent);
			node = node->right;
		}
		node = binary_tree_rotate_left(node->parent->parent);
	}
	else
	{
		if (node->parent->right == node)
		{
			node = binary_tree_rotate_left(node->parent);
			node = node->left;
		}
		node = binary_tree_rotate_right(node->parent->parent);
	}
}

/**
 * avl_insert - insert a new node in an AVL
 * @tree: tree
 * @value: value of the new node
 * Return: node (success) | NULL (failed)
 */
avl_t *avl_insert(avl_t **tree, int value)
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

	node = insertNode(tree, node);
	if (node == NULL)
		return (NULL);

	update_avl(node);

	return (node);
}
