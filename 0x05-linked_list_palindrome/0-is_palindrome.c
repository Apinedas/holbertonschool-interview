#include "lists.h"

/**
 * is_palindrome - Checks if SLL is palindrome
 * @head: Pointer to SLL head
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t *curr;

	if (!head || !*head)
		return (1);

	curr = *head;
	while (curr->next)
		curr = curr->next;

	if ((*head)->n != curr->n)
		return (0);

	curr = *head;
	while (curr->next && curr->next->next)
		curr = curr->next;

	curr->next = NULL;
	return (is_palindrome(&(*head)->next));
}
