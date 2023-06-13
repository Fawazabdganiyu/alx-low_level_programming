#include "main.h"

/**
 * create_array - creates an array of chars, and initializes
 * it with a specific char.
 * @size: Size of an array to be created
 * @c: The character to initialize with
 *
 * Return: NULL if size = 0
 *	pointer to the array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i;

	if (size == 0)
		return (NULL);

	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		str[i] = c;
	}

	return (str);
}
