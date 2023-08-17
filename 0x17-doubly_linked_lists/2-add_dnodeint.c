#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 * @head: A pointer to the head node pointer
 * @n: An integer to be added
 *
 * Return: The address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	if (*head != NULL)
		(*head)->prev = new;
	new->next = *head;
	new->prev = NULL;
	*head = new;

	return (new);
}
