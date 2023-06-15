#include <stdlib.h>
#include <stdio.h>

/**
 * _isdigit - checks for a digit (0 through 9)
 * @c: character to check
 *
 * Return: 1 if c is a digit, 0 if otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _atoi - converts string to number
 * @s: strings to be converted
 *
 * Return: The value of the converted string.
 */
int _atoi(char *s)
{
	int sign;
	unsigned int num;

	sign = 1;
	num = 0;
	while (*s)
	{
		if (*s == '-')
		{
			sign *= -1;
		}
		else if ((*s >= '0') && (*s <= '9'))
		{
			num = (num * 10) + (*s - '0');
		}
		else if (num > 0)
		{
			break;
		}
		s++;
	}
	return (num * sign);
}

/**
 * _strlen - returns the length of a string
 * @s: string to return its length
 *
 * Return: len, as the length of the string.
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; s[len]; len++)
		;

	return (len);
}

/**
 * main - multiplies two positive numbers.
 * @ac: Number of arguments passed to the program.
 * @av: A pointer to an array of arguments passed to the program
 *
 * Return: The product of the two positive numbers
 */
int main(int ac, char **av)
{
	int mul = 1, i, j, num, len;
	char *arg;

	if (ac != 3)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 1; i < ac; i++)
	{
		arg = av[i];
		len = _strlen(arg);

		for (j = 0; j < len; j++)
		{
			if (!(_isdigit(arg[j])))
			{
				printf("Error\n");
				exit(98);
			}
		}

		num = _atoi(arg);
		mul *= num;
	}

	printf("%d\n", mul);

	return (0);
}
