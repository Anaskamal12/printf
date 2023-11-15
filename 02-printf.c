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

/**
 * mustafa_S - handle S
 * @str: string
 * Return: anas
 */
int mustafa_S(char *str)
{
	int anas = 0;

	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (*str)
	{
		if ((*str < 32 && *str > 0) || *str >= 127)
		{
			char escape[5];

			anas += write(1, "\\", 1);
			anas += write(1, "x", 1);
			sprintf(escape, "%02X", (unsigned char)*str);
			anas += write(1, escape, 2);
		}
		else
		{
			anas += write(1, str, 1);
		}
		str++;
	}
	return (anas);
}

/**
 * mustafa_s - handle s
 * @str: arguments
 * Return: void
 */
int mustafa_s(char *str)
{
	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	else
	{
		int anas = 0;

		while (*str)
		{
			anas += write(1, str, 1);
			str++;
		}
		return (anas);
	}
}

