#include "main.h"

/**
 * _calloc - allocates memory for an array, using malloc.
 * @nmemb: The number of elements of the array.
 * @size: The size of each element of the array.
 * Return: A pointer to the allocated memory.
 *	If nmemb or size is 0, then _calloc returns NULL
 *	If malloc fails, then _calloc returns NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *str;

	if (nmemb == 0 || size == 0)
		return (NULL);

	str = malloc(size * nmemb);
	if (str == NULL)
		return (NULL);

	for (i = 0; i < nmemb; i++)
		str[i] = 0;

	return (str);
}
