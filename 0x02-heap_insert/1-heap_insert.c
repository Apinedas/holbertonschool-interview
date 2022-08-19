#include "binary_trees.h"

/**
 * heap_tree_postorder - goes through a binary tree by post-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: 
 * @func: pointer to a function to call for each node.
 */

void heap_tree_postorder(heap_t *tree, heap_t *node ,void (*func)(heap_t *, heap_t *))
{
	if (!tree->left || !tree->right)
        func(tree, node);
	else if (tree->left && (!tree->left->left || !tree->left->right))
        heap_tree_postorder(tree->left, node, func);
	else if (tree->right && (!tree->right->left || !tree->right->right))
		heap_tree_postorder(tree->right, node, func);
	else
        heap_tree_postorder(tree->left, node, func);
}

/**
 * swap_if_higher - swaps child and parent nodes if child is higher than parent
 * @node: pointer to node to evaluate
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
        copy = node->right;
        node->right = parent->right;
        if (parent->right)
            parent->right->parent = node;
        parent->left = node->left;
        node->left = parent;
        parent->right = copy;
    }
    else
    {
        copy = node->left;
        node->left = parent->left;
        if (parent->left)
            parent->left->parent = node;
        parent->right = node->right;
        node->right = parent;
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

    new_node = (heap_t *) binary_tree_node(NULL, value);
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

    heap_tree_postorder(*root, new_node, heap_insert_aux);
    swap_if_higher(new_node, root);
    return (new_node);
}
