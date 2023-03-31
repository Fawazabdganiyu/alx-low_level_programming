#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random valid passwords
 *
 * Return: Always 0.
 */
int main(void)
{
	int password[98];
	int i, sum, num;

	sum = 0;
	srand(time(0));
	for (i = 0; i < 98; i++)
	{
		password[i] = rand() % 68;
		sum += (password[i] + '0');
		putchar(password[i] + '0');
		if ((2772 - sum) - '0' < 68)
		{
			num = 2772 - sum - '0';
			sum += num;
			putchar(num + '0');
			break;
		}
	}

	return (0);
}
