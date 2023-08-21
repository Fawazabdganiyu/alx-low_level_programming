#include "main.h"

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
