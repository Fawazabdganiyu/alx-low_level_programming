#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index (index)
 *	of a dlistint_t linked list.
 * @head: A pointer to the head pointer
 * @index: The index of the node that should be deleted. Index starts at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)

{
	dlistint_t *current;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	current = *head;
	/* Delete at the beginning */
	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}
	while (current)
	{
		if (i == index)
		{
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->prev->next = current->next;
			free(current);
			return (1);
		}
		i++;
		current = current->next;
	}
	return (-1);

}
