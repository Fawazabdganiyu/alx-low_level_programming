#include <stdlib.h>

/**
 * malloc_checked - allocates memory using malloc.
 * @b: The size of bytes to be alocated.
 *
 * Return: A pointer to the allocated memory. if malloc fails,
 * the malloc_checked function should cause normal process
 * termination with a status value of 98.
 */
void malloc_checked(unsigned int b)
{
	char *str;

	str = malloc(b);
	if (str == NULL)
		exit(98);
}
