#include "binary_trees.h"
#include <limits.h>
#include <math.h>

/**
 * insert_node - insert node helper
 * @tree: BST
 * @node: node to isnert
 * Return: node (success) | NULL (failed)
 */
bst_t *insert_node(bst_t **tree, bst_t *node)
{
	if ((*tree)->n == node->n)
	{
		free(node);
		return (NULL);
	}

	if ((*tree)->n > node->n)
	{
		if ((*tree)->left)
			return (insert_node(&(*tree)->left, node));

		(*tree)->left = node;
		node->parent = (*tree);
		return (node);
	}
	else
	{
		if ((*tree)->right)
			return (insert_node(&(*tree)->right, node));

		(*tree)->right = node;
		node->parent = (*tree);
		return (node);
	}
}

/**
 * update_avl - fix avl tree after inserting a node
 * @tree: AVL tree
 * @node: node inserted
 */
void update_avl(avl_t **tree, avl_t *node)
{
	size_t isBalanced;

	if (node->parent->parent == NULL)
		return;

	isBalanced = binary_tree_balance(node->parent->parent);

	if (abs((int)isBalanced) <= 1)
		return;

	if ((int)isBalanced < 0)
	{
		if (node->parent->left == NULL)
			node = binary_tree_rotate_left(node->parent->parent);
		else
		{
			node = binary_tree_rotate_right(node->parent);
			node = binary_tree_rotate_left(node->parent);
		}
	}
	else
	{
		if (node->parent->right == NULL)
			node = binary_tree_rotate_right(node->parent->parent);
		else
		{
			node = binary_tree_rotate_left(node->parent);
			node = binary_tree_rotate_right(node->parent);
		}
	}
	if (node->parent == NULL)
		(*tree) = node;
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

	node = insert_node(tree, node);
	if (node == NULL)
		return (NULL);

	update_avl(tree, node);

	return (node);
}
