#include "main.h"

/**
 * _strncat - concatenates two strings.
 * @dest: Destination pointer where the string is added
 * @src: source string that is added
 * @n: number of bytes to be added from src
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, dlen;

	dlen = 0;
	for (i = 0; dest[i] != '\0'; i++)
	{
		dlen++;
	}
	for (i = 0; src[i] && i < n; i++)
	{
		dest[dlen++] = src[i];
	}

	return (dest);
}
