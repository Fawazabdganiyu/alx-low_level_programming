#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: The string to search
 * @needle: The substring to be located
 *
 * Return: A pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		if (*haystack == *needle)
		{
			return (haystack);
		}
	}

	return ('\0');
}
