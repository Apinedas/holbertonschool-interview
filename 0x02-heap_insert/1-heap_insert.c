#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: Height of tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);
	return (right_height > left_height ? right_height : left_height);
}

/**
 * hp_is_perfect - aux function for perfect binary tree
 * @tree: Pointer to node
 * @lvl: Node lvl
 * @height: Height from tree node
 * Return: 1 if tree is perfect, 0 otherwise
*/

int hp_is_perfect(const binary_tree_t *tree, int height, int lvl)
{
	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (height == lvl ? 1 : 0);
	if (!(tree->left) || !(tree->right))
		return (0);
	return (hp_is_perfect(tree->left, height, lvl + 1) *
		   hp_is_perfect(tree->right, height, lvl + 1));
}


/**
 * hp_tree_post - goes through a binary tree by post-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: node to exec function
 * @func: pointer to a function to call for each node.
 */

void hp_tree_post(heap_t *tree, heap_t *node, void (*func)(heap_t *, heap_t *))
{
	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);
	int left_perfect = hp_is_perfect(tree->left, left_height, 0);
	int right_perfect = hp_is_perfect(tree->right, right_height, 0);

	if (!tree->left || !tree->right)
		func(tree, node);
	else if ((left_perfect && !right_perfect) ||
			 (left_perfect && right_perfect && (right_height < left_height)))
		hp_tree_post(tree->right, node, func);
	else
		hp_tree_post(tree->left, node, func);
}

/**
 * swap_if_higher - swaps child and parent nodes if child is higher than parent
 * @node: pointer to node to evaluate
 * @root: double pointer to root of heap
 */

void swap_if_higher(heap_t *node, heap_t **root)
{
	heap_t *copy = NULL, *parent = NULL;

	if (!node || !node->parent || node->n <= node->parent->n)
		return;

	parent = node->parent;

	if (node->left)
		node->left->parent = parent;
	if (node->right)
		node->right->parent = parent;
	if (parent->left == node)
	{
		copy = node->right, node->right = parent->right;
		if (parent->right)
			parent->right->parent = node;
		parent->left = node->left, node->left = parent;
		parent->right = copy;
	}
	else
	{
		copy = node->left, node->left = parent->left;
		if (parent->left)
			parent->left->parent = node;
		parent->right = node->right, node->right = parent;
		parent->left = copy;
	}
	if (parent->parent)
	{
		if (parent->parent->left == parent)
			parent->parent->left = node;
		else
			parent->parent->right = node;
	}
	node->parent = parent->parent;
	parent->parent = node;

	if ((*root)->parent && !(node->parent))
		*root = node;
	swap_if_higher(node, root);
}

/**
 * heap_insert_aux - inserts a value into a Max Binary Heap, as left as posible
 * @tree: pointer to tree node to insert node into
 * @node: pointer to the node to insert
 * Return: pointer to the inserted node, or NULL on failure
 */

void heap_insert_aux(heap_t *tree, heap_t *node)
{
	node->parent = tree;
	if (!tree->left)
		tree->left = node;
	else
		tree->right = node;
}

/**
 * heap_insert - nserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: is the value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;

	new_node = (heap_t *)binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	new_node->n = value;
	if (!*root)
	{
		new_node->parent = NULL;
		new_node->left = NULL;
		new_node->right = NULL;
		*root = new_node;
		return (new_node);
	}

	hp_tree_post(*root, new_node, heap_insert_aux);
	swap_if_higher(new_node, root);
	return (new_node);
}
