#include "binary_trees.h"


size_t binary_tree_height(const binary_tree_t *tree)
{
        size_t lv, rv, max;

        if (tree == NULL)
                return 0;

        lv = tree->left? 1 + binary_tree_height(tree->left): 0;
        rv = tree->right? 1 + binary_tree_height(tree->right): 0;

        max = lv > rv? lv : rv;
        return (max);
}

/**
 * binary_tree_balance - 
 *
 *
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t lv, rv;

	if (tree == NULL)
		return 0;

	lv = tree->left? 1 + binary_tree_height(tree->left): 0;
        rv = tree->right? 1 + binary_tree_height(tree->right): 0;

	return (lv - rv);
}
