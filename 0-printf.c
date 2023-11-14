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

	if (format == NULL)
		return (-1);
	va_start(mo, format);
	while (*format)
	{
		if (*format != '%' || (*(format + 1) == '%' && (format++, 1)))
		{
			anas += write(1, format, 1);
		}
		else if (*(format + 1) == 'c')
		{
			char c = va_arg(mo, int);

			anas += write(1, &c, 1);
			format++;
		}
		else if (*(format + 1) == 's')
		{
			char *str = va_arg(mo, char*);

			anas += write(1, str, strlen(str));
			format++;
		}
		else if (*(format + 1) == '%')
		{
			anas += write(1, "%", 1);
			format++;
		}
		format++;
	}
	va_end(mo);
	return (anas);
}
