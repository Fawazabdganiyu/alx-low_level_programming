#include "hash_tables.h"

/**
 * add_node - adds a node to the beginning of the linked list
 * @head: A pointer to the head node pointer
 * @index: The index of the key in the hash table.
 * @key: The key, string
 * @value: The value corresponding to a key
 *
 * Return: A pointer to a new node
 */
hash_node_t *add_node(hash_node_t **head, unsigned long int index,
		const char *key, const char *value)
{
	hash_node_t *new;

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
		return (NULL);

	new->key = strdup(key);
	new->value = strdup(value);

	new->next = head[index];
	head[index] = new;

	return (new);
}

/**
 * search_list - searches the linked list for existing key
 * @head: A pointer to the head node of the list.
 * @key: The key, string
 *
 * Return: A pointer to the node where the key is found or NULL
 */
hash_node_t *search_list(hash_node_t *head, const char *key)
{
	while (head && (strcmp(head->key, key) != 0))
		head = head->next;

	if (head != NULL)
		return (head);

	return (NULL);
}

/**
 * hash_table_set - adds an element to the hash table.
 * @ht: The hash table to add or update the key/value to.
 * @key: The key of the hash table.
 * @value: The value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t **head, *update_node, *first_node;
	char *temp;

	if (strcmp(key, "") == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	/* Check if the index is NULL (Available for storage) */
	head = ht->array;
	first_node = ht->array[index];
	if (first_node == NULL)
	{	/* Set at this index */
		add_node(head, index, key, value);
	}
	else
	{	/* Check the bucket */
		update_node = search_list(*head, key);
		if (update_node != NULL)
		{	/* Update the bucket */
			temp = update_node->value;
			update_node->value = strdup(value);
			free(temp);
		}
		else /* Handle collision */
			/* Add it to the beginning of the list */
			add_node(head, index, key, value);
	}

	return (1);

}
