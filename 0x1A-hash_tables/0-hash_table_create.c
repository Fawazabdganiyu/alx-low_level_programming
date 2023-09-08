#include "hash_tables.h"

/**
 * create_hash_item - creates and initialise array of nodes of the hash node
 * @size: The size of the array.
 *
 * Return: A pointer to the array of nodes of the hash node.
 */
hash_node_t **create_hash_item(unsigned long int size)
{
	hash_node_t **array;
	unsigned long int i;

	array = malloc(sizeof(hash_node_t *) * size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = NULL;

	return (array);
}

/**
 * hash_table_create - reates a hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	hash_node_t **array;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;

	/* Create array of hash items */
	array = create_hash_item(size);

	ht->array = array;

	return (ht);
}
