#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: The head pointer
 * @index: The index of the node, starting at 0
 *
 * Return: returns the nth node of a listint_t linked list.
 *	If the node does not exist, return NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current;
	unsigned int current_index;

	current = head;

	current_index = 0;
	while (current)
	{
		if (current_index == index)
		{
			return (current);
		}
		current = current->next;
		current_index++;
	}

	return (NULL);
}
