#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int bst;

    root = binary_tree_node(NULL, 97);
    root->right = binary_tree_node(root->right, 99);
    root->right->right = binary_tree_node(root->right, 98);

    binary_tree_print(root);
    bst = binary_tree_is_bst(root);
    printf("Is %d bst: %d\n", root->n, bst);
    bst = binary_tree_is_bst(root->left);
    printf("Is %d bst: %d\n", root->left->n, bst);

    binary_tree_print(root);
    bst = binary_tree_is_bst(root);
    printf("Is %d bst: %d\n", root->n, bst);
    return (0);
}
