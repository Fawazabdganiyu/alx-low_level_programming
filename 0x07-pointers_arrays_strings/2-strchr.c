#include "main.h"
#include <stddef.h>

/**
 * _strchr - locates a character in a string.
 * @s: The string to search.
 * @c: The character to locate
 *
 * Return: The first occurence of the string to a pointer or NULL of not found.
 */
char *_strchr(char *s, char c)
{
	for (; *s != '\0'; s++)
	{
		if (*s == c)
		{
			return (s);
		}
	}
	return (NULL);
}
