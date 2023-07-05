#include "lists.h"

/**
 * free_listint - frees a listint_t list.
 * @head: A pointer to the head node
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
