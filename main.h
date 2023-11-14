#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);

int mustafa_d(int n);
int mustafa_b(int n);
int mustafa_i(int n);
int mustafa_R(char *str);
int mustafa_r(char *str);

int mustafa_chars(va_list mo, const char *format);

int mustafa_u(unsigned int n);
int mustafa_o(unsigned int n);
int mustafa_x(unsigned int n);
int mustafa_X(unsigned int n);


#endif /* MAIN_H */

