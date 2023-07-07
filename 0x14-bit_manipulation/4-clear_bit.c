#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 * @n: The pointer to the value to set its bit.
 * @index: The index, starting from 0, of the bit to be set.
 *
 * Return: 1 if it worked or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index > (sizeof(unsigned long int *) * 8))
		return (-1);

	mask = 1UL << index;

	*n = (~*n);

	*n |= mask;

	*n = (~*n);

	return (1);

}
