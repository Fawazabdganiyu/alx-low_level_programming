#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: A pointer to the head pointer
 * @idx: The index of the list where the new node should be added.
 *	Index starts at 0
 * @n: An integer to be stored
 *
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current, *new;
	unsigned int i = 0;

	if (h == NULL || *h == NULL)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (idx == 0)
	{
		new->prev = NULL;
		new->next = *h;
		(*h)->prev = new;
		*h = new;
		return (new);
	}

	current = *h;
	while (current)
	{
		if (i == idx - 1)
		{
			new->next = current->next;
			current->next->prev = new;
			new->prev = current;
			current->next = new;
			return (new);
		}
		i++;
		current = current->next;
	}

	free(new);
	return (NULL);
}
