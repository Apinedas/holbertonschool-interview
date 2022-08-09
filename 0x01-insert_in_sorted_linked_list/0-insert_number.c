#include "lists.h"

/**
 * insert_node - Inserts a node on a sorted SLL
 * @head: Pointer to head pointer
 * @number: Number to insert as node
 * Return: he address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *curr;

	if (!head || !*head)
		return (NULL);

	curr = *head;
	while (curr->next && curr->next->n <= number)
		curr = curr->next;
	if (!(curr->next))
		return add_nodeint_end(head, number);

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);

	new_node->n = number;
	new_node->next = curr->next;
	curr->next = new_node;

	return (new_node);
}
