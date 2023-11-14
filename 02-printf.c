#include "main.h"

/**
 * print_int - print intege
 * @n: integer
 * Return: 1
 */
int print_int(int n)
{
	if (n < 0)
	{
		char anfal = '-';

		if (write(1, &anfal, 1) != 1)
		{
			return (-1);
		}
		n = -n;
	}
	if (n / 10 != 0)
	{
		int anas = print_int(n / 10);

		char digitChar = n % 10 + '0';

		if (write(1, &digitChar, 1) != 1)
		{
			return (-1);
		}
		return (anas + 1);
	}
	else
	{
		char digitChar = n + '0';

		if (write(1, &digitChar, 1) != 1)
		{
			return (-1);
		}
		return (1);
	}
}
