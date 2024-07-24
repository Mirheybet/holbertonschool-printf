#include <stdarg.h>
#include "main.h"

/**
 * _printf - It is our printf function.
 * @format: variable of function , first element of variadic function
 * Return: It returns size of args .
 */

int _printf(const char *format, ...)
{
	int indexchar = 0, indexstr = 0, sizeofargument = 0;
	char *varofargs;

	va_list(args);

	va_start(args, format);
	while (format[indexchar])
	{
		if (format[indexchar] == '%' && format[indexchar + 1] == '\0')
			return (-1);
		else if (format[indexchar] == '%' && format[indexchar + 1] == '%')
			_putchar('%'), sizeofargument++, indexchar += 2;
		else if (format[indexchar] == '%' && format[indexchar + 1] == 'c')
			_putchar(va_arg(args, int)), sizeofargument++, indexchar = indexchar + 2;
		else if (format[indexchar] == '%' && format[indexchar + 1] == 's')
		{
			varofargs = va_arg(args, char*);
			while (varofargs[indexstr])
				_putchar(varofargs[indexstr]), varofargs++;
			sizeofargument += indexstr, indexchar += 2;
		}
		else
			_putchar(format[indexchar]), indexchar++, sizeofargument++;
	}
	va_end(args);
	return (sizeofargument);
}
