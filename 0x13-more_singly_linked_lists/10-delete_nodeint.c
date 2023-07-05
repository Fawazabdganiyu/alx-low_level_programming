#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index (index)
 * of a listint_t linked list.
 * @head: A pointer to the head pointer
 * @index: The index of the node that should be deleted.
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *previous;
	listint_t *current;
	unsigned int current_index;

	if (*head == NULL)
		return (-1);

	/* Consider if the deletion is at the beginning */
	if (index == 0)
	{	current = *head;
		*head = (*head)->next;
		free(current);
		return (1);
	}

	/* Check if the index is valid and move the pointer accordingly */
	previous = NULL;
	current_index = 0;
	current = *head;
	while (current && current_index < index)
	{
		previous = current;
		current = current->next;
		current_index++;
	}

	/* Consider if !valid */
	if (current == NULL)
		return (-1);

	/* Reassign the pointer accordingly and free the deleted node */
	previous->next = current->next;
	free(current);

	return (1);
}
