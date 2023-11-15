#include "main.h"
/**
 * mustafa_u - handle u
 * @n: unsigned
 * Return: anas
 */
int mustafa_u(unsigned int n)
{
	int anas = 0;

	int remainder = n % 10;

	char digitChar = remainder + '0';

	if (n / 10 != 0)
	{
		anas += mustafa_u(n / 10);
	}

	if (write(1, &digitChar, 1) != 1)
	{
		return (-1);
	}
	return (anas + 1);
}

/**
 * mustafa_o - handle o
 * @n: unsigned
 * Return: anas
 */
int mustafa_o(unsigned int n)
{
	int anas = 0;
	int remainder = n % 8;

	char digitChar = remainder + '0';


	if (n / 8 != 0)
	{
		anas += mustafa_o(n / 8);
	}

	if (write(1, &digitChar, 1) != 1)
	{
		return (-1);
	}
	return (anas + 1);
}

/**
 * mustafa_x - handle x
 * @n: unsigned
 * Return: anas
 */
int mustafa_x(unsigned int n)
{
	int anas = 0;
	int remainder;

	char digitChar;

	if (n / 16 != 0)
	{
		anas += mustafa_x(n / 16);
	}
	remainder = n % 16;

	if (remainder < 10)
	{
		digitChar = remainder + '0';
	}
	else
	{
		digitChar = remainder - 10 + 'a';
	}
	if (write(1, &digitChar, 1) != 1)
	{
		return (-1);
	}
	return (anas + 1);
}
/**
 * mustafa_X - hnadle X
 * @n: unsigned
 * Return: anas
 */
int mustafa_X(unsigned int n)
{
	int anas = 0;
	int reminder;

	char digitChar;

	if (n / 16 != 0)
	{
		anas += mustafa_X(n / 16);
	}
	reminder = n % 16;

	if (reminder < 10)
	{
		digitChar = reminder + '0';
	}
	else
	{
		digitChar = reminder - 10 + 'A';
	}
	if (write(1, &digitChar, 1) != 1)
	{
		return (-1);
	}
	return (anas + 1);
}

/**
 * mustafa_p - handle p
 * @p: pointer
 * Return: anas
 */
int mustafa_p(void *p)
{
	char buffer[64];
	int anas = 0;
	int i;

	sprintf(buffer, "%p", p);

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (write(1, &buffer[i], 1) != 1)
		{
			return (-1);
		}
		anas++;
	}
	return (anas);
}
