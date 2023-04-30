#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: The pointer to the head pointer.
 *
 * Return: The head node’s data (n) if successful.
 * Return 0, if the linked list is empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (*head == NULL)
		return (0);

	n = (*head)->n;

	temp = *head;
	*head = (*head)->next;
	free(temp);

	return (n);
}
