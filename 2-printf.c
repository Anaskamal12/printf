#include "main.h"
/**
 * mustafa_chars - handle u, o, x, X
 * @mo: mo
 * @format: insert format
 * Return: anas
 */
int mustafa_chars(va_list mo, const char *format)
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
	return (anas);
}
