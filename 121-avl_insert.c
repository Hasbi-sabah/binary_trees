#include "binary_trees.h"
#include <limits.h>
#include <math.h>

void avl_balancer(avl_t **tree, int val);

/**
 * insert_helper - insert a node in AVL tree
 * @tree: AVL tree
 * @parent: node parent
 * @node: double pointer to the new node
 * @val: the value of the new node
 * Return: NULL (failed) | node/tree (success)
 */
avl_t *insert_helper(avl_t **tree, avl_t *parent, avl_t **node, int val)
{
	if (*tree == NULL)
	{
		*node = binary_tree_node(parent, val);
		return (*node);
	}
	if ((*tree)->n > val)
	{
		(*tree)->left = insert_helper(&(*tree)->left, *tree, node, val);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < val)
	{
		(*tree)->right = insert_helper(&(*tree)->right, *tree, node, val);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	avl_balancer(tree, val);
	return (*tree);
}

/**
 * avl_balancer - balance the AVL tree
 * @tree: AVL tree
 * @val: value of the node to insert
 */
void avl_balancer(avl_t **tree, int val)
{
	int isBalanced;

	isBalanced = binary_tree_balance(*tree);
	if (isBalanced > 1 && (*tree)->left->n > val)
		*tree = binary_tree_rotate_right(*tree);

	else if (isBalanced > 1 && (*tree)->left->n < val)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (isBalanced < -1 && (*tree)->right->n < val)
		*tree = binary_tree_rotate_left(*tree);
	else if (isBalanced < -1 && (*tree)->right->n > val)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
}

/**
 * avl_insert - insert a new node in an AVL
 * @tree: tree
 * @val: val of the new node
 * Return: node (success) | NULL (failed)
 */
avl_t *avl_insert(avl_t **tree, int val)
{
	bst_t *node = NULL;

	if ((*tree) == NULL)
	{
		(*tree) = binary_tree_node(*tree, val);
		return (*tree);
	}

	insert_helper(tree, *tree, &node, val);
	return (node);
}
