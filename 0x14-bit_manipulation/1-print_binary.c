#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask, size;
	int leading_zeros = 1;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	/* Get the number of bits in unsigned long int(8 bytes) = 8 * 8 bits */
	size = sizeof(n) * 8;

	/* Start the masking from the largest bit then reduces the bits by 1 */
	for (mask = (1UL << (size - 1)); mask > 0; mask >>= 1)
	{
		if (n & mask)
		{
			leading_zeros = 0;
			_putchar('1');
		}
		else if (!leading_zeros)
		{
			_putchar('0');
		}
	}
}
