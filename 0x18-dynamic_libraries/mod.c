/**
 * mod - finds the modulus of two integer
 * @a: The first operand
 * @b: The second operand
 *
 * Return: The remainder of division of a by b if b > 0, a otherwise.
 */
int mod(int a, int b)
{
	if (b < 0)
		return (a);

	return (a % b);
}
