#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry ponit
 * n: Random number
 *
 * Description: This program will assign a random number
 * to the variable n each time it is executed
 * and print whether the number stored in the variable n
 * is positive or negative.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0)
		printf("%u is positive\n", n);
	else if (n < 0)
		printf("%d is negative\n", n);
	else
		printf("%u is zero\n", n);
	return (0);
}
