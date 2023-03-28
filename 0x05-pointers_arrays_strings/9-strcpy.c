#include "main.h"

/**
 * _strcpy -  copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @dest: copy to
 * @src: string source
 *
 * Return: copied string in dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i, len;

	len = 0;
	for (i = 0; src[i] != '\0'; i++)
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}

	for (; i <= len; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}
