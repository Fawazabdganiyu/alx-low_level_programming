#include <string.h>
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
 * normal_len - calculate the normal length  a given string
 * @str: the string to get its normal lenght
 *
 * Return: the normal lenght of the given string
 */
int normal_len(char *str)
{
	int count = 0;
	int i;
	int blank = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			if (blank == 1)
			{
				count++;
			}
			blank = 0;
		}
		else
		{
			count++;
			blank = 1;
		}
	}

	return (count);
}

/**
 * normalise - represent a given string in its normal form with only a blank
 * @str: the string to normalise
 *
 * Return: the normalise string
 */
char *normalise(char *str)
{
	char *s;
	int i, j = 0;
	int blank = 0;
	int len;

	len = normal_len(str);
	s = malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			if (blank == 1)
			{
				s[j++] = str[i];
			}
			blank = 0;
		}
		else
		{
			s[j++] = str[i];
			blank = 1;
		}
	}
	s[j] = '\0';

	return (s);
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

	if (str == NULL || strcmp(str, ""))
		return (NULL);

	arr = malloc(sizeof(char *) * (row + 1));
	if (arr == NULL)
		return (NULL);

	s = normalise(str);
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
		{
			arr[i][k] = s[k];
		}
		arr[i][k] = '\0';

		s += j;
		i++;
	}
	arr[i] = NULL;

	return (arr);
}
