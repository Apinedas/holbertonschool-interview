#include "binary_trees.h"

/**
 * heapify - entry to heapify
 * Desc: heapify function that organizes position in the max_heap
 * @root: double pointer to the root node of the heap
 * Return: Nothing, void function
 */
void heapify(binary_tree_t *root)
{
	binary_tree_t *child = NULL;
	int temp = 0;

	while (1)
	{
		if (!root->left)
			break;
		else if (!root->right)
			child = root->left;
		else
		{
			if (root->left->n >= root->right->n)
				child = root->left;
			else
				child = root->right;
		}

		if (root->n >= child->n)
			break;

		temp = root->n;
		root->n = child->n;
		child->n = temp;

		root = child;
	}
}

/**
 * get_nodes - entry to get num nodes
 * Desc: get_nodes function to the  nodes of heap tree
 * @root: double pointer to the root node of the heap
 * Return: nodes in heap tree
 */
int get_nodes(heap_t *root)
{
	int l = 0, r = 0;

	if (!root)
		return (0);

	l = get_nodes(root->left);
	r = get_nodes(root->right);

	return (1 + l + r);
}

/**
 * get_node_end - entry to get node end
 * Desc: get_node_end function to get the last node in min_heap
 * @root: pointer to root node of the heap
 * Return: pointer to the last node of the heap
 */
binary_tree_t *get_node_end(heap_t *root)
{
	int nodes = 0, size_heap = 0;
	binary_tree_t *end_node = NULL;

	size_heap = get_nodes(root);

	for (nodes = 1; nodes <= size_heap; nodes <<= 1)
		;
	nodes >>= 2;

	for (end_node = root; nodes > 0; nodes >>= 1)
	{
		if (size_heap & nodes)
			end_node = end_node->right;
		else
			end_node = end_node->left;
	}

	return (end_node);
}

/**
 * heap_extract - entry to heap extract
 * Desc: heap_extract function that extracts
 * the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, 0 if it fails
 */
int heap_extract(heap_t **root)
{
	binary_tree_t *end_node = NULL, *head_node = NULL;
	int extracted_num = 0;

	if (!root || !*root)
		return (0);

	head_node = *root;
	if (!head_node->left && !head_node->right)
	{
		extracted_num = head_node->n;
		free(head_node);
		*root = NULL;
		return (extracted_num);
	}

	head_node = *root;
	extracted_num = head_node->n;

	end_node = get_node_end(*root);

	if (end_node->parent->left == end_node)
		end_node->parent->left = NULL;
	else
		end_node->parent->right = NULL;

	end_node->left = head_node->left;
	end_node->right = head_node->right;
	end_node->parent = head_node->parent;

	if (head_node->left)
		head_node->left->parent = end_node;
	if (head_node->right)
		head_node->right->parent = end_node;

	*root = end_node;
	free(head_node);

	heapify(*root);

	return (extracted_num);
}
