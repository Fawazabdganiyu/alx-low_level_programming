#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - frees a listint_t list.
 * @head: The pointer to head pointer.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp, *temp2;

	if (*head == NULL)
		return;
	temp = *head;
	while (temp)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	*head = NULL;
}
