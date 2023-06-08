#include <stdio.h>
#include "main.h"

int _strlen(char *s);
int compare_str(char *s, int i, int len);
int is_palindrome(char *s);

/**
 * _strlen - Calculate the lenght of a string
 * @s: the given string
 *
 * Return: The lenght of the string
 */
int _strlen(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + _strlen(s + 1));
}

/**
 * compare_str - compare if a given string is palindrome
 * @s: The given string
 * @i: Constant number just for iteration
 * @len: The length of the given string
 *
 * Return: 1 if the strings are the same and 0 if otherwise
 */
int compare_str(char *s, int i, int len)
{
	/* Base condition*/
	if (s[i] == '\0' || len <=  0)
		return (1);

	if (s[i] != s[len - 1])
		return (0);

	return (compare_str(s, i + 1, len - 1));
}

/**
 * is_palindrome - check if a string is a palindrome
 * @s: The string to check
 *
 * Return: 1 if it is a palindrome
 *	0 if otherwise
 */
int is_palindrome(char *s)
{
	int compare, len;

	if (*s == '\0')
		return (1);

	len = _strlen(s);

	compare = compare_str(s, 0, len);
	if (compare == 1)
		return (1);

	return (0);
}
