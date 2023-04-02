#include "main.h"

/**
 * leet - encodes a string into 1337.
 * @str: strings to encode
 *
 * Return: Encoded leet strings.
 */
char *leet(char *str)
{
	int i, j;
	char leet_lib[5][3] = {
		{'a', 'A', '4'},
		{'e', 'E', '3'},
		{'o', 'O', '0'},
		{'t', 'T', '7'},
		{'l', 'L', '1'}
	};

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (str[i] == leet_lib[j][0] || str[i] == leet_lib[j][1])
			{
				str[i] = leet_lib[j][2];
				break;
			}
		}
	}

	return (str);
}
