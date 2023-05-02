#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list.
 * @head: The pointer to the head pointer.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous;
	listint_t *next;

	previous = NULL;
	next = NULL;
	while (*head != NULL)
	{
		next = (*head)->next;
		(*head)->next = previous;
		previous = *head;
		*head = next;
	}
	*head = previous;
	return (previous);
}
