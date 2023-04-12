#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of your program,
 * with each argument followed by a newline in the new string.
 * @ac: The number of arguments to be passed to the program.
 * @av: An array of arguments passed to the program.
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
		len = 0;
		for (; *arg != '\0'; arg++)
		{
			len++;
		}
		T_len += len + 1;
	}
	str = malloc(sizeof(char) * T_len + 1);
	if (str == NULL)
		return (NULL);

	s_len = 0;
	for (i = 0; i < ac; i++)
	{
		arg = av[i];
		for (; *arg != '\0'; arg++)
		{
			str[s_len] = *arg;
			s_len++;
		}
		str[s_len] = '\n';
		s_len++;
	}
	str[s_len] = '\0';

	return (str);
}
