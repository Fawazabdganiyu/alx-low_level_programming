#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	_putchar(n & (1 << 11));
}
