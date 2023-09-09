#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table.
 * @ht: The hash table to be deleted
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *temp, *node;
	unsigned long int i;

	if (ht == NULL)
		return;

	if (ht->array != NULL)
	{
		for (i = 0; i < ht->size; i++)
		{
			if (ht->array[i] != NULL)
			{	node = ht->array[i];
				while (node != NULL)
				{
					temp = node->next;
					free(node->key);
					free(node->value);
					free(node);
					node = temp;
				}
			}

		}
		free(ht->array);
		free(ht);
	}
}
