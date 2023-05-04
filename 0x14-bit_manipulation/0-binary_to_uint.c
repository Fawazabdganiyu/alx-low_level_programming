#include <stdlib.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: A pointer to the string 0 and 1 chars.
 *
 * Return: The converted value, or 0, if there is one or more chars in b that
 * is not 0 or 1. And 0, if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int ans;
	int i;

	if (b == NULL)
		return (0);

	ans = 0;
	for (i = 0; b[i]; i++)
	{
		if ((b[i] != '1') && (b[i] != '0'))
			return (0);

		ans <<= 1;
		ans += (b[i] - '0');
	}

	return (ans);
}
