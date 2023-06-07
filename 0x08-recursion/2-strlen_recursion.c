#include "main.h"

/**
 * _strlen_recursion - returns the length of a string.
 * @s: The string to determine its length.
 *
 * Return: The number of bytes in the given string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + _strlen_recursion(s + 1));
}
