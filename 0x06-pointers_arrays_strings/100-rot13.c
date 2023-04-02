#include "main.h"

/**
 * rot13 - encodes a string using rot13.
 * @str: string to encode
 *
 * Return: Encoded and decoded string
 */
char *rot13(char *str)
{
	int i, j;
	char rot13_dict[52][2] = { {'A', 'N'}, {'B', 'O'}, {'C', 'P'}, {'D', 'Q'},
				   {'E', 'R'}, {'F', 'S'}, {'G', 'T'}, {'H', 'U'},
				   {'I', 'V'}, {'J', 'W'}, {'K', 'X'}, {'L', 'Y'},
				   {'M', 'Z'}, {'N', 'A'}, {'O', 'B'}, {'P', 'C'},
				   {'Q', 'D'}, {'R', 'E'}, {'S', 'F'}, {'T', 'G'},
				   {'U', 'H'}, {'V', 'I'}, {'W', 'J'}, {'X', 'K'},
				   {'Y', 'L'}, {'Z', 'M'}, {'a', 'n'}, {'b', 'o'},
				   {'c', 'p'}, {'d', 'q'}, {'e', 'r'}, {'f', 's'},
				   {'g', 't'}, {'h', 'u'}, {'i', 'v'}, {'j', 'w'},
				   {'k', 'x'}, {'l', 'y'}, {'m', 'z'}, {'n', 'a'},
				   {'o', 'b'}, {'p', 'c'}, {'q', 'd'}, {'r', 'e'},
				   {'s', 'f'}, {'t', 'g'}, {'u', 'h'}, {'v', 'i'},
				   {'w', 'j'}, {'x', 'k'}, {'y', 'l'}, {'z', 'm'}, };

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (str[i] == rot13_dict[j][0])
			{
				str[i] = rot13_dict[j][1];
				break;
			}
		}
	}

	return (str);
}
