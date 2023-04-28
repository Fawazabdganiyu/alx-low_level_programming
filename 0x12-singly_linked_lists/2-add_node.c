#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_node- adds a new node at the beginning of a list_t list.
 * @head: The pointer to head node
 * @str: The malloc.ed string in the list_t list.
 *
 * Return: The address of the new element or NULL of it fails.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	int len;

	if (head == NULL || str == NULL)
		return (NULL);

	/* Allocate new node */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	for (len = 0; str[len]; len++)
		;

	new_node->len = len;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
