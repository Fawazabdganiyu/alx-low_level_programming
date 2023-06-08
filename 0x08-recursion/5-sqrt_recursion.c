#include "main.h"

int  guess(int num, int n);
int _sqrt_recursion(int n);

/**
 * guess - Guess square root
 * @num: The initial guessed square root
 * @n: Number to be evaluated
 *
 * Return: The expected natural square root.
 *	-1 if it does not have a natural square root.
 */
int  guess(int num, int n)
{

	if (num * num > n)
		return (-1);

	if (num * num == n)
	{
		return (num);
	}

	return (guess(++num, n));
}

/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: The given number
 *
 * Return: The expected natural square root
 *	-1 if n does not have a natural square root.
 */
int _sqrt_recursion(int n)
{
	int sqrt;

	if (n < 0)
		return (-1);

	sqrt = guess(1, n);

	if (sqrt == -1)
		return (-1);

	return (sqrt);
}
