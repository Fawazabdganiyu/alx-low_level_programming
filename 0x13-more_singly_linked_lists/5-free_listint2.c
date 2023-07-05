#include "lists.h"

/**
 * free_listint2 - frees a listint_t list.
 * @head: A pointer to the head pointer.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL || *head == NULL)
		return;

	while (*head)
	{
		temp = *head;
		free(temp);
		*head = temp->next;
	}
	*head = NULL;
}
