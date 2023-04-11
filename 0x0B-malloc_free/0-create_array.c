#include <stdlib.h>

/**
 * create_array - creates an array of chars, and initializes it
 * with a specific char.
 * @size: Size of array to be created.
 * @c: The character to be printed.
 * Return: NULL if size = 0. Return a pointer to the array or NULL if fail.
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *ar;

	if (size == 0)
	{
		return (NULL);
	}

	ar = malloc(sizeof(char) * size);
	if (ar == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		ar[i] = c;
	}
	return (ar);
}
