#include <stdio.h>
#include "main.h"

int  _sqrt(int guess, int n);
int check_prime(int num, int min, int max);
int is_prime_number(int n);

/**
 * _sqrt - get square root
 * @guess: the guessed square root
 * @n: Number to be evaluated
 *
 * Return: The expected square root.
 */
int  _sqrt(int guess, int n)
{
	if (guess * guess >= n)
		return (guess / 1);

	return (_sqrt(guess + 1, n));
}

/**
 * check_prime - checks if the given number is prime
 * @num: The given number
 * @min: The min. range
 * @max: The max. range of factors of num
 *
 * Return: 1 if prime and 0 otherwise
 */
int check_prime(int num, int min, int max)
{
	/* Base condition */
	if (min > max)
		return (1);

	if (num % min == 0)
		return (0);

	return (check_prime(num, min + 1, max));
}

/**
 * is_prime_number - checks if a number is prime number
 * @n: The given number
 *
 * Return: 1 if the input integer is a prime number
 *	0 if otherwise
 */
int is_prime_number(int n)
{
	int prime = 7;

	if (n < 2)
		return (0);

	prime = check_prime(n, 2, _sqrt(1, n));

	return (prime);
}
