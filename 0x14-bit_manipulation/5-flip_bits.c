#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip to get
 * from one number to another.
 * @n: The value to flip its bit.
 * @m: The desired value to obtain after flipping.
 *
 * Return: The number of bits flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff, size, mask;
	int count;

	/* Get the bit that would changed in n to the one in m */
	diff = n ^ m;

	size = (sizeof(unsigned long int) * 8) - 1;

	/* Count numbers of on bits in diff */
	count = 0;
	for (mask = 1UL << size; mask > 0; mask >>= 1)
	{
		if ((diff & mask))
			count++;
	}

	return (count);
}
