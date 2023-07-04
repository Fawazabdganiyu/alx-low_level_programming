#include <stdlib.h>
#include "main.h"

/**
 * set_string - sets the value of a pointer to a char.
 * @s: A pointer to the string to set.
 * @to: The character to set to.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
