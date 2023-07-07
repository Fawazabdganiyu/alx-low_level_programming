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
	unsigned int dec, ans = 0;
	int i, len, n;

	if (b == NULL)
		return (0);
	/* Get the length of string b */
	for (len = 0; b[len]; len++)
		;
	/* Initialise the number of shift (highest binary power) */
	n = len - 1;

	for (i = 0; b[i]; i++)
	{
		if ((b[i] != '1') && (b[i] != '0'))
			return (0);

		/* Convert to decimal */

		dec = ((b[i] - '0') << n--);
		/* Add up the numbers in dec */
		ans += dec;
	}

	return (ans);
}
