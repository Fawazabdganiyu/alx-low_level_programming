#include "main.h"

/**
 * get_endianness - checks the endianness.
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int i;
	int *c;

	i = 5;
	c = &i;

	if (*c)
		return (1);
	else
		return (0);
}
