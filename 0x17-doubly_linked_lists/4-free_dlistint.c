#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list.
 * @head: A pointer to the head node
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	if (head == NULL)
		return;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
