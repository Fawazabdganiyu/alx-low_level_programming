#include <stdio.h>

void __attribut__((constructor)) print(void);

/**
 * print - Print before main print
 */
void print(void)
{
	printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}
