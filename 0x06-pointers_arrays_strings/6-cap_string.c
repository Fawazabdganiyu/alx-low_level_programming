#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: strings to capitalize its words
 *
 * Return: Capitalize words
 */
char *cap_string(char *str)
{
	int i, cap_next;

	cap_next = 1;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ',' || str[i] == '.' || str[i] == ';' || str[i] == '?'
		    || str[i] == '(' || str[i] == ')' || str[i] == '{'
		    || str[i] == '}' || str[i] == '"' || str[i] == '!'
		    || str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			cap_next = 1;
		}
		else
		{
			if (cap_next == 1 && (str[i] >= 'a' && str[i] <= 'z'))
			{
				str[i] -= 32;
				cap_next = 0;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				cap_next = 0;
			}
		}
	}
	return (str);
}
