#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes.
 * @s: The string to search
 * @accept: The sring to match for any occurence of byte
 *
 * Return: A pointer to the byte in s that matches one of the bytes
 * in accept, or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	char *p, *a;

	for (p = s; *p != '\0'; p++)
	{
		for (a = accept; *a != '\0'; a++)
		{
			if (*p == *a)
			{
				return (p);
			}
		}
	}
	return ('\0');
}
