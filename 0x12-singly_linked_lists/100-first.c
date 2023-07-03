#include <stdio.h>

/**
 * print - Prints before the main function is executed
 */
void __attribute__((constructor)) print(void)
{
	printf("You're beat! and yet, you must allow,\n"
"I bore my house upon my back!\n");
}
