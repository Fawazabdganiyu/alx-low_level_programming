#include "main.h"

/**
 * is_prime_number -Verify if prime number or not
 * @n: The numner to be verified
 *
 * Return: 1 if the input integer is a prime number, otherwise 0.
 */
int is_prime_number(int n)
{
	int i;

	if (n <= 1)
	{
		return (0);
	}

	for (i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			return (0);
		}
	}
	return (1);
}
