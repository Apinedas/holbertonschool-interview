#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new node of a binary tree
 * @parent: Binary tree node parent
 * @value: Binary tree node value
 * Return: Pointer to new node, or NULL on fail
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
