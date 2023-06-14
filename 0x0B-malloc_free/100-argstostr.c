#include "main.h"
int _strlen(char *s);
char *argstostr(int ac, char **av);

/**
 * _strlen - calculate the lenght of a string
 * @s: the string to determine its length
 *
 * Return: the calculate lenght of string
 */
int _strlen(char *s)
{
	int len = 0;

	for (; *s; s++)
		len++;

	return (len);
}

/**
 * argstostr - concatenates all the arguments of a program,
 * with each argument followed by a newline in the new string.
 * @ac: The number of arguments to be passed to the program.
 * @av: A pointer to an array of arguments passed to the program.
 *
 * Return: NULL if ac == 0 or av == NULL. Returns a pointer to a new string,
 * or NULL if it fails.
 */
char *argstostr(int ac, char **av)
{
	int i, len, T_len, s_len;
	char *arg, *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	T_len = 0;
	for (i = 0; i < ac; i++)
	{
		arg = av[i];
		len = _strlen(arg);
		T_len += len + 1;
	}
	str = malloc(sizeof(char) * T_len + 1);
	if (str == NULL)
		return (NULL);

	s_len = 0;
	for (i = 0; i < ac; i++)
	{
		arg = av[i];
		for (; *arg; arg++)
			str[s_len++] = *arg;

		str[s_len++] = '\n';
	}
	str[s_len] = '\0';

	return (str);
}
