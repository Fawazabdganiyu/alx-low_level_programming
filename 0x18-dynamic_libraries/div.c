/**
 * div - finds the quotient of division of two integers
 * @a: The first operand
 * @b: The second operand
 *
 * Return: The quotient if b > 0, 0 otherwise.
 */
int div(int a, int b)
{
	if (b < 0)
		return (0);

	return (a / b);
}
