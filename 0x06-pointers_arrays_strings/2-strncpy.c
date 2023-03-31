#include "main.h"

/**
 * _strncpy - concatenates two strings.
 * @dest: Destination pointer where the string is added
 * @src: source string that is added
 * @n: number of bytes to be added from src
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, slen;

	slen = 0;
	for (i = 0; src[i] != '\0'; i++)
	{
		slen++;
	}

	for (i = 0; src[i] && i < n; i++)
	{
		dest[i] = src[i];
	}

	for (i = slen; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}
