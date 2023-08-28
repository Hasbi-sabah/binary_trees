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
 binary_tree_t *root = NULL;
 size_t depth;
 depth = binary_tree_depth(root);
 printf("Depth of: %lu\n", depth);
 return (0);
}
