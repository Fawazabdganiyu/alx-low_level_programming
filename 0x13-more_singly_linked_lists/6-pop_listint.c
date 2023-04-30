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

	if (*head == NULL)
		return (0);

	temp = *head;
	*head = temp->next;

	return (temp->n);
}
