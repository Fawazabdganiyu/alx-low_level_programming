#include "main.h"

/**
 * _memcpy - copies memory area.
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Number of bytes to copy
 *
 * Return: A pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i, dlen;

	dlen = 0;
	for (i = 0; dest[i] != '\0'; i++)
	{
		dlen++;
	}

	for (i = 0; i < n; i++)
	{
		*(dest + dlen++) = *(src + i);
	}

	return (dest);
}
