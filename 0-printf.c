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
		else if (*(format + 1) == 'd' || *(format + 1) == 'i')
		{
			int num = va_arg(mo, int);
			int temp = num;
			int len = 1;

			while (temp /= 10)
			{
				len++; }
			char buffer[12];
			char *ptr = buffer + len;

			do {
				*--ptr = num % 10 + '0';
				num /= 10;
			} while (num);
			anas += write(1, ptr, len);
			format++;
		} else if (*(format + 1) == '%')
		{
			anas += write(1, "%", 1);
			format++; }
		format++;
	}
	va_end(mo);
	return (anas);
}
