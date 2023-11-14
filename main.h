#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int mustafa_d(int n);
int mustafa_b(int n);
int mustafa_i(int n);
int mustafa_R(char *str);
int mustafa_r(char *str);
int mustafa_chars(va_list mo, const char *format);


#endif /* MAIN_H */

