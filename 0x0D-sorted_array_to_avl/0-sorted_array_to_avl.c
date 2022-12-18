#include "binary_trees.h"

/**
 * binary_search - recursive function
 * @array: pointer to the first array's element
 * @start: first array's element
 * @end: last element
 * @parent: node
 * Return: pointer to head of AVL
 **/

avl_t *binary_search(int *array, int start, int end, avl_t *parent)
{
	int middle_element;
	avl_t *node;

	if (start > end)
		return (NULL);

	middle_element = (start + end) / 2;
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = array[middle_element];
	node->parent = parent;
	node->left = binary_search(array, start, middle_element - 1, node);
	node->right = binary_search(array, middle_element + 1, end, node);
	return (node);
}

/**
 * sorted_array_to_avl - Function array
 * @array: pointer
 * @size: array
 * Return: Pointer
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);
	return (binary_search(array, 0, size - 1, NULL));
}