#include "main.h"

/**
 * string_nconcat - concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The number of bytes in s2 to include.
 * Return: A pointer to a newly allocated space in memory, which contains
 *	s1 followed by the first n bytes of s2, and null terninated.
 *	Return NULL if the function fails.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, s1_len, s2_len, len, str_len;
	char *str;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (s1_len = 0; s1[s1_len]; s1_len++)
		;
	for (s2_len = 0; s2[s2_len]; s2_len++)
		;

	if (n >= s2_len)
		len = s1_len + s2_len + 1;
	else
		len = s1_len + n + 1;

	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);

	str_len = 0;
	for (i = 0; s1[i]; i++)
	{
		str[i] = s1[i];
		str_len++;
	}
	for (i = 0; i < n && s2[i]; i++)
	{
		str[str_len++] = s2[i];
	}
	str[str_len++] = '\0';

	return (str);
}
