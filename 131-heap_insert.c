#include "binary_trees.h"

heap_t *heap_search(heap_t **root, int value, int *flag)
{
	if (value > (*root)->n)
	{
		flag = 0;
		return ((*root)->parent);
	}

	if (!(*root)->left)
	{
		*flag = -1;
		return (*root)->parent;
	}
	else if (!(*root)->right)
	{
		*flag = 1;
		return (*root)->parent;
	}
	if ((*root)->left)
	{
		if (value <= (*root)->n)
		{
			*flag = -1;
			return (*root)->parent;
		}
		heap_search(&(*root)->left, value, flag);
	}
	if ((*root)->right)
	{
		if (value <= (*root)->n)
		{
			*flag = 1;
			return (*root)->parent;
		}
		heap_search(&(*root)->right, value, flag);
	}
	return (NULL);
}
heap_t *heap_insert(heap_t **root, int value)
{
	int flag;
	heap_t *pa, *node;

	if (!*root)
	{
		node = binary_tree_node(NULL, value);
		*root = node;
		return (node);
	}
	pa = heap_search(root, value, &flag);
	node = binary_tree_node(pa, value);
	if (flag == 0)
	{
		node->left = *root;
		(*root)->parent = node;
		(*root) = node;
	}
	if (flag == - 1)
	{
		if (pa->left)
		{
			pa->left->parent = node;
			node->left = pa->left; 
			pa->left = node;
		}
		else
			pa->left = node;
	}
	if (flag == 1)
	{
		if (pa->right)
		{
			pa->right->parent = node;
			node->right = pa->right; 
			pa->right = node;
		}
		else
			pa->right = node;
	}
	return (node);
}
