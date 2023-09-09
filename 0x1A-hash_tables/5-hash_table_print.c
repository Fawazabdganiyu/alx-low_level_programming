#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 * @ht: The hash table to be printed
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *nodes;
	unsigned int comma = 0;

	if (ht == NULL)
		return;

	printf("{");

	if (ht->array != NULL)
	{
		for (i = 0; i < ht->size; i++)
		{
			if (ht->array[i])
			{
				if (comma)
					 printf(", ");

				nodes = ht->array[i];
				while (nodes)
				{
					printf("'%s': '%s'", nodes->key, nodes->value);
					nodes = ht->array[i]->next;
					if (nodes)
						printf(", ");
				}
				comma = 1;
			}
		}
	}
	printf("}\n");
}
