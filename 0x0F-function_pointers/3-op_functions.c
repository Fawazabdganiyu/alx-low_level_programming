#include "3-calc.h"

/**
 * op_add - sum two integers
 * @a: First operand
 * @b: Second operand
 *
 * Return: The sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtracts two integers
 * @a: First operand
 * @b: Second operand
 *
 * Return: The difference between a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiply two integers
 * @a: First operand
 * @b: Second operand
 *
 * Return: The product of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides two integers
 * @a: First operand
 * @b: Second operand
 *
 * Return: The result of division of a by b
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - give the modulus of two integers
 * @a: First operand
 * @b: Second operand
 *
 * Return: The remainder of the division of a by b
 */
int op_mod(int a, int b)
{
	return (a % b);
}
