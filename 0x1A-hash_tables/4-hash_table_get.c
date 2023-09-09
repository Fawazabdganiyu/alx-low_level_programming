#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: A pointer to a given hash table structure.
 * @key: The key to be retrieved
 *
 * Return: The value associated with the element, or
 *	NULL if they couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *head, *node;

	if (ht == NULL || key == NULL)
		return (NULL);

	/* Get the key index */
	index = key_index((const unsigned char *)key, ht->size);

	head = ht->array[index];
	node = search_list(head, key);
	if (node != NULL)
		return (node->value);

	return (NULL);
}
