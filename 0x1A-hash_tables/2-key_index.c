#include "hash_tables.h"

/**
 * key_index - gives the index of the a key
 * @key: The key of the hash table
 * @size: The size of of the array of the hash table
 *
 * Return: The index at which the key/value pair should be stored in
 *	the array of the hash table
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index;

	index = hash_djb2(key);

	return (index % size);
}
