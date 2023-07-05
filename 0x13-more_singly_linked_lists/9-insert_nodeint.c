#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: The pointer to the given node pointer
 * @idx: The index of the list where the new node should be added.
 * @n: The new node data (n) to be inserted.
 *
 * Return: The address of the new node or NULL if it failed.
 * NULL, if it is not possible to add the new node at index idx.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node;
	listint_t *current;
	unsigned int current_index;

	if (head == NULL)
		return (NULL);
	/* Allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	/* Input the new node data */
	new_node->n = n;

	/* Consider when the node is to be added at the beginning */
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	/* locate the idx if valid */
	current = *head;
	current_index = 0;
	while (current && current_index < idx - 1)
	{
		current = current->next;
		current_index++;
	}
	/* Return NULL if !valid */
	if (current == NULL)
	{
		free(new_node);
		return (NULL);
	}
	/* Assign the address accordingly */
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
