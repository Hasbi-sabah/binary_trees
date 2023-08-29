#include "binary_trees.h"

/**
 * binary_tree_depth - function that measures the depth
 * of a node in a binary tree
 * @tree: tree
 * Return: depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
		return (1 + binary_tree_depth(tree->parent));
	return (0);
}

/**
 * binary_trees_ancestor - function that finds the lowest
 * common ancestor of two nodes
 * @fi: first
 * @se: second
 * Return: a pointer to the lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *fi,
		const binary_tree_t *se)
{
	size_t depth1, depth2;
	const binary_tree_t *tmp1, *tmp2;

	depth1 = binary_tree_depth(fi);
	depth2 = binary_tree_depth(se);

	if (depth1 == 0 || depth2 == 0)
		return (NULL);


	tmp1 = fi;
	tmp2 = se;
	if (depth1 > depth2)
	{
		while (depth1 != depth2)
		{
			tmp1 = tmp1->parent;
			depth1--;
		}
	}
	else if (depth1 < depth2)
	{
		while (depth1 != depth2)
		{
			tmp2 = tmp2->parent;
			depth2--;
		}
	}

	while (tmp1 != tmp2)
	{
		tmp1 = tmp1->parent;
		tmp2 = tmp2->parent;
	}

	return ((binary_tree_t *)tmp1);
}
