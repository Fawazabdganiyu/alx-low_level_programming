#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 * n: Random number
 * lastd: last digit of the random number
 *
 * Description: This program print the last digit of a random
 * number and specify if the number is greater than 5, is 0,
 * or less than 6 and not zero.
 *
 * Return: Always (0) Success
 */
int main(void)
{
	int n, lastd;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lastd = n % 10;

	if (lastd > 5)
		printf("Last digit of %d is %d and is greater than 5\n", n, lastd);
	else if (lastd == 0)
		printf("Last digit of %d is %d and is 0\n", n, lastd);
	else if (lastd < 6 && lastd != 0)
		printf("Last digit of %d is %d and is less than 6 and not 0\n", n, lastd);

	return (0);
}
