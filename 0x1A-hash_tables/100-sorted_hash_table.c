#include "hash_tables.h"

shash_node_t *add_node(shash_node_t **head, unsigned long int index,
		shash_node_t *new);
shash_node_t *search_slist(shash_node_t *head, const char *key);
void insert_bucket(shash_table_t *ht, shash_node_t *new);
void sorted_insert(shash_table_t *ht, shash_node_t *new);
shash_node_t **create_array(unsigned long int size);

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);

/**
 * add_node - adds a node to the beginning of the linked list
 * @head: A pointer to the head node pointer
 * @index: The index of the key in the hash table.
 * @new: The new node to be added.
 *
 * Return: A pointer to a new node
 */
shash_node_t *add_node(shash_node_t **head, unsigned long int index,
		shash_node_t *new)
{
	new->next = head[index];
	head[index] = new;

	return (new);
}

/**
 * search_slist - searches the linked list for existing key
 * @head: A pointer to the head node of the list.
 * @key: The key, string
 *
 * Return: A pointer to the node where the key is found or NULL
 */
shash_node_t *search_slist(shash_node_t *head, const char *key)
{
	while (head && (strcmp(head->key, key) != 0))
		head = head->next;

	if (head != NULL)
		return (head);

	return (NULL);
}

/**
 * insert_bucket - insert node in the bucket and handle collision appropriately
 * @ht: A pointer to the hash table
 * @new: A pointer to the new node to be added.
 */
void insert_bucket(shash_table_t *ht, shash_node_t *new)
{
	unsigned long int index;
	shash_node_t **head, *update_node, *first_node;
	char *temp;

	index = key_index((const unsigned char *)new->key, ht->size);

	/* Check if the index is NULL (Available for storage) */
	head = ht->array;
	first_node = ht->array[index];
	if (first_node == NULL)
	{	/* Set at this index */
		add_node(head, index, new);
	}
	else
	{	/* Check the bucket */
		update_node = search_slist(first_node, new->key);
		if (update_node != NULL)
		{	/* Update the bucket */
			temp = update_node->value;
			update_node->value = new->value;
			free(temp);
		}
		else /* Handle collision */
			/* Add it to the beginning of the list */
			add_node(head, index, new);
	}
}

/**
 * sorted_insert - insert new node in the hash table in sorted manner.
 * @ht: A sorted hash table
 * @new: The new node to be inserted in sorted way.
 */
void sorted_insert(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *temp;
	int i;
	unsigned long int new_key, node_key;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
		return;
	}
	for (i = 0; new->key[i]; i++)
		new_key += new->key[i]; /* Get the values of new key */

	temp = ht->shead;
	while (temp)
	{
		i = 0;
		for (i = 0; temp->key[i]; i++)
			node_key += temp->key[i];
		if (node_key >= new_key)
		{	/* Insert before this node */
			new->snext = temp;
			new->sprev = temp->sprev;
			temp->sprev = new;
			if (temp->sprev == NULL)
				ht->shead = new;
			return;
		}

		temp = temp->snext;
	} /* Add it to the end */
	temp = ht->shead;
	while (temp && temp->snext)
		temp = temp->snext;
	new->snext = NULL;
	new->sprev = temp;
	temp->snext = new;
	ht->stail = new;
}
/**
 * create_array - creates a pointer to an array of pointers
 * @size: The size of the array to be created.
 *
 * Return: A pointer to the created pointers array
 */
shash_node_t **create_array(unsigned long int size)
{
	shash_node_t **array;
	unsigned long int i;

	array = malloc(sizeof(shash_node_t *) * size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = NULL;

	return (array);
}

/**
 * shash_table_create - create sorted hash table
 * @size: The size of the sorted hash table
 *
 * Return: A pointer to the created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sht;
	shash_node_t **array;

	sht = malloc(sizeof(shash_table_t));
	if (sht == NULL)
		return (NULL);

	sht->size = size;

	array = create_array(size);
	sht->array = array;
	sht->shead = NULL;
	sht->stail = NULL;

	return (sht);
}

/**
 * shash_table_set - sets a key-value sorted in a hash table
 * @ht: The sorted hash table to set to
 * @key: The key, string to set
 * @value: The corresponding key value to set.
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new;

	if (ht == NULL || key == NULL || value == NULL || *key == '\0')
		return (0);

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
		return (0);

	new->key = strdup(key);
	new->value = strdup(value);
	new->next = NULL;
	new->snext = NULL;
	new->sprev = NULL;

	sorted_insert(ht, new);
	insert_bucket(ht, new);

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key.
 * @ht: A pointer to a given hash table structure.
 * @key: The key to be retrieved
 *
 * Return: The value associated with the element, or
 *	NULL if they couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *head, *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	/* Get the key index */
	index = key_index((const unsigned char *)key, ht->size);

	head = ht->array[index];
	node = search_slist(head, key);
	if (node != NULL)
		return (node->value);

	return (NULL);
}
