#include "main.h"

/**
 * string_toupper - changes all lowercase letters of a string to uppercase.
 * @str: string to change
 * Return: Uppercase strings.
 */
char *string_toupper(char *str)
{
	int i, len;

	for (i = 0; *str != '\0'; i++)
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str -= 32;
		}
	}

	return (str);
}
