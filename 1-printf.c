#include "main.h"
/**
 * _printf - handle format specifier d and i
 * @format: character string
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
			anas += write(1, format, 1); }
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

