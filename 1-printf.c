#include "main.h"
/**
 * _printf - produce output handle (d, i) specifier
 * @format: the inserted format
 * Return: anas
 */
int _printf(const char *format, ...)
{
	va_list mo;

	va_start(mo, format);

	int anas = 0;

	while (*format)
	{
		int num, temp, digits, i;

		char buffer[12];

		if (*format != '%' && (*(format + 1) == 'd' && *(format + 1) == 'i'))
		{
			num = va_arg(mo, int);
			if (num < 0)
			{
				anas += write(1, "-", 1);
				num = -num; }
			temp = num;
			digits = 1;

			while (temp /= 10)
			{
				digits++; }
			for (i = digits - 1; i >= 0; i--)
			{
				buffer[i] = num % 10 + '0';
				num /= 10; }
			anas += write(1, buffer, digits);
			format += 2;
		}
		else
		{
			anas += write(1, format, 1);
			format++;
		}
	}
	va_end(mo);
	return (anas);
}
