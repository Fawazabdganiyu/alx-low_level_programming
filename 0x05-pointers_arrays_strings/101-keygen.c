#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * password_gen - generates random valid passwords
 *
 * Return: The generated password
 */
int main(void)
{
	int i, randd;
	char *numbers[11], *letters[27], *LETTERS[27], *symbols[9], *password[10];

	i = 0;
	randd = 0;

	srand(time(0));

	numbers[11] = "0123456789";
	letters[27] = "abcdefghijklmnopqrstuvwxyz";
	LETTERS[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	symbols[9] = "!@#$^&*?";

	randd = rand() % 4;
	for (i = 0; i < 10; i++)
	{
		if (randd == 1)
		{
			password[i] = numbers[rand() % 10];
			randd = rand() % 4;
			printf("%s", password[i]);
		}
		else  if (randd == 2)
		{
			password[i] = symbols[rand() % 8];
			randd = rand() % 4;
			printf("%s", password[i]);
		}
		else if (randd == 3)
		{
			password[i] = LETTERS[rand() % 26];
			randd = rand() % 4;
			printf("%s", password[i]);
		}
		else
		{
			password[i] = letters[rand() % 26];
			randd = rand() % 4;
			printf("%s", password[i]);
		}
	}
}
