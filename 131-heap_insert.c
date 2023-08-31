#include "binary_trees.h"

heap_t *heap_search(heap_t **root, int value, int *flag)
{
	if (value > tree->n)
	{
		return (NULL);
	}

	if (tree->left)
	{
		if (value >= tree->left->n)
		{
			*flag = -1;
			return (*root);
		}
		is_heap(tree->left);
	}
	if (tree->right)
	{
		if (value >= tree->right->n)
		{
			*flag = 1;
			return (*root);
		}
		is_heap(tree->right);
	}
	if (!tree->left)
	{
		*flag = -1;
		return (*root);
	}
	*flag = 1;
	return (*root);
}
heap_t *heap_insert(heap_t **root, int value)
{
	int flag;
	heap_t *pa, *node;

	if (!*root)
	{
		node = binary_tree_node(NULL, value);
		return (*root = node);
	}
	pa = heap_search(root, value, &flag);
	node = binary_tree_node(pa, value);
	if (flag == - 1)
	{
		if (pa->left)
		{

		}
		pa->left = node;
	}
}
