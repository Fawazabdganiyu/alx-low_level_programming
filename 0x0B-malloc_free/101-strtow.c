#include <stdio.h>
#include "main.h"

/**
 * _free - free an allocated memory
 * @arr: a pointer to 2D array
 * @n: number of array element
 **/
void _free(char **arr, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

/**
 * row_num - Calculate number of each word separated by space in the string
 * @str: The string to be examined
 *
 * Return: number of each word separated by space in the string
 */
int row_num(char *str)
{
	int i, count = 0;
	int alpha = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			if (alpha == 0)
				count++;
			alpha = 1;
		}
		else
		{
			alpha = 0;
		}
	}

	return (count);
}

/**
 * strtow - splits a string into words.
 * @str: the string to split
 *
 * Return: a pointer to an array of strings (words)
 *	NULL if str == NULL or str == ""
 *	NULL if function fails
 */
char **strtow(char *str)
{
	char **arr, *s;
	int row = row_num(str), i, j, k;

	if (row == 0)
		return (NULL);
	if (str == NULL || *str == '\0')
		return (NULL);

	arr = malloc(sizeof(char *) * (row + 1));
	if (arr == NULL)
		return (NULL);

	s = str;
	i = 0;
	while (*s != '\0' && i < row)
	{
		while (*s == ' ')
			s++;
		j = 0;
		while (s[j] != ' ' && s[j] != '\0')
			j++;

		arr[i] = malloc(sizeof(char) * (j + 1));
		if (arr[i] == NULL)
		{
			_free(arr, i);
			return (NULL);
		}

		for (k = 0; k < j; k++)
			arr[i][k] = s[k];
		arr[i][k] = '\0';

		s += j;
		i++;
	}
	arr[i] = NULL;

	return (arr);
}
