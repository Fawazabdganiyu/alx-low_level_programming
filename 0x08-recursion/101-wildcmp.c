#include "main.h"

/**
 * wildcmp - compares two strings
 * @s1: The first string
 * @s2: The second string which can contain the special character *.
 *
 * Return: 1 if the strings can be considered identical, otherwise return 0.
 */
int wildcmp(char *s1, char *s2)
{
	/* Base condition */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s1 && *s2 == '*')
	{
		if ((*(s1 + 1) == *(s2 + 1)))
			return (wildcmp(s1 + 1, s2 + 1));
		else
			return (wildcmp(s1 + 1, s2));
	}
	return (0);
}
