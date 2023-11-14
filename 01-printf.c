#include "main.h"
/**
 * mustafa_b - handle %b
 * @n: integer
 * Return: anas
 */
int mustafa_b(int n)
{
	int anas = 0;
	int mami = 1;

	for (int i = 31; i >= 0; i--)
	{
		char bit = (n >> i) & 1;

		if (bit == 1)
		{
			mami = 0;
		}
		if (!mami)
		{
			char bitChar = bit + '0';

			if (write(1, &bitChar, 1) != 1)
			{
				return (-1);
			}
			anas++;
		}
	}
	if (anas == 0)
	{
		char zerChar = '0';

		if (write(1, zerChar, 1) != 1)
		{
			return (-1);
		}
		anas++;
	}
	return (anas);
}

/**
 * mustafa_d - handle d
 * @n: integer number
 * Return: anas
 */
int mustafa_d(int n)
{
	int anas = 0;

	if (n < 0)
	{
		char anfal = '-';

		if (write(1, &anfal, 1) != 1)
		{
			return (-1);
		}
		anas++;
		n = -n;
	}
	anas += print_int(n);

	return (anas);
}

/**
 * mustafa_i - handle i
 * @n: integer
 * Return: anas
 */
int mustafa_i(int n)
{
	int anas = print_int(n);

	return (anas);
}

/**
 * mustafa_R - handle R
 * @str: string ro rot13
 * Return: anas
 */
int mustafa_R(char *str)
{
	int anas = 0;

	if (str == NULL)
	{
		return (write(1, "(null)", 6)); }
	while (*str)
	{
		char k = *str;
		char root13 = k;

		if ((k >= 'A' && k <= 'Z') || (k >= 'a' && k <= 'z'))
		{
			char basee = (k >= 'a') ? 'a' : 'A';

			root13 = (k - basee + 13) % 26 + basee;
		}
		if (write(1, &root13, 1) != 1)
		{
			return (-1);
		}
		anas++;
		str++;
	}
	return (anas);
}

/**
 * mustafa_r - handle r
 * @str: reverse
 * Return: anas
 */
int mustafa_r(char *str)
{
	int anas = 0;
	int len = 0;
	int i;

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[len] != '\0')
	{
		len++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (write(1, &str[i], 1 != 1))
		{
			return (-1);
		}
		anas++;
	}
	return (anas);
}
