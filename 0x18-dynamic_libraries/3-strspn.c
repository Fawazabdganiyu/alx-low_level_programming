#include "main.h"

/**
 * _strspn - gets the lenght of a prefix substring
 * @s: The string to span through
 * @accept: Bytes to span for
 *
 * Return: The number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int len;

	len = 0;
	for (; *s != '\0'; s++)
	{
		char *a = accept;

		for (; *a != '\0'; a++)
		{
			if (*s == *a)
			{
				len++;
				break;
			}
		}
		if (*a == '\0')
		{
			break;
		}
	}

	return (len);
}
