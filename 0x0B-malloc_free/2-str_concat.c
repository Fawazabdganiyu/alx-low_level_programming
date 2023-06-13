#include "main.h"

unsigned int _strlen(char *s);
char *str_concat(char *s1, char *s2);

/**
 * _strlen - calculates the string length
 * @s: the string to calculate its length
 *
 * Return: the length of string calculated
 */
unsigned int _strlen(char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
		;

	return (i);
}

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: a pointer to the new concatenated string
 *	NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int len1, len2, str_len, i, j;
	char *str;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	str_len = len1 + len2 + 1;

	str = malloc(sizeof(char) * str_len);
	if (str == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
	{
		str[i] = s1[i];
	}

	for (j = 0; s2[j]; j++)
	{
		str[i++] = s2[j];
	}
	str[i] = '\0';

	return (str);
}
