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
				anas += mustafa_chars(mo, format - 1);
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
