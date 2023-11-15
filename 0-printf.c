#include "main.h"

/**
 * _printf - Produce output according to format
 * @format: a character string
 * Return: anas
 */

int _printf(const char *format, ...)
{

	int anas = 0;
	va_list mo;

	va_start(mo, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				anas += mustafa_d(va_arg(mo, int));
			}
			else if (*format == 'b')
			{
				anas += mustafa_b(va_arg(mo, int));
			}
			else if (*format == 'R')
			{
				anas += mustafa_R(va_arg(mo, char *));
			}
			else if (*format == 'r')
			{
				anas += mustafa_chars(mo, format);
			}
		}
		else
		{
			anas += write(1, format, 1);
		}
		format++;
	}
	va_end(mo);
	return (anas);
}

/**
 * mustafa_chars - handle c, s, %, S
 * @mo: mo
 * @format: format
 * Return: anas
 */
int mustafa_chars(va_list mo, const char *format)
{
	int anas = 0;

	if (*format == 'c')
	{
		char c = va_arg(mo, int);

		anas += write(1, &c, 1);
	}
	else if (*format == 's')
	{
		anas += mustafa_s(va_arg(mo, char *));
	}
	else if (*format == '%')
	{
		anas += write(1, format, 1);
	}
	else if (*format == 'S')
	{
		anas += mustafa_S(va_arg(mo, char *));
	}
	else
	{
		anas += mustafa_numbers(mo, format);
	}
	return (anas);
}

/**
 * mustafa_numbers - handle u, o, x, X
 * @format: format
 * @mo: mo
 * Return: anas
 */
int mustafa_numbers(va_list mo, const char *format)
{
	int anas = 0;

	if (*format == 'u')
	{
		anas += mustafa_u(va_arg(mo, unsigned int));
	}
	else if (*format == 'o')
	{
		anas += mustafa_o(va_arg(mo, unsigned int));
	}
	else if (*format == 'x')
	{
		anas += mustafa_x(va_arg(mo, unsigned int));
	}
	else if (*format == 'X')
	{
		anas += mustafa_X(va_arg(mo, unsigned int));
	}
	else
	{
		anas += mustafa_pointer(mo, format);
	}
	return (anas);
}

/**
 * mustafa_pointer - handle p
 * @mo: mo
 * @format: format
 * Return: anas
 */
int mustafa_pointer(va_list mo, const char *format)
{
	int anas = 0;

	if (*format == 'p')
	{
		anas += mustafa_p(va_arg(mo, void *));
	}
	else
	{
		char precent = '%';

		if (write(1, &precent, 1) != 1)
		{
			return (-1);
		}
		anas++;
		if (*format)
		{
			if (write(1, format, 1) != 1)
			{
				return (-1);
			}
			anas++;
		}
	}
	return (anas);
}
