#include <stdarg.h>
#include "main.h"

/**
 * _printf - It is our printf function.
 * @format: variable of function , first element of variadic function
 * Return: It returns size of args .
 */

int _printf(const char *format, ...)
{
	int indexforchars = 0, indexforstrings = 0, sizeofargument = 0;
	char *varof_args;

	va_list(args);

	va_start(args, format);

	while (format[indexforchars])
	{
		if (format[indexforchars] == '%' && format[indexforchars + 1] == '\0')
			return (-1);
		else if (format[indexforchars] == '%' && format[indexforchars + 1] == '%')
		{
			indexforchars++, sizeofargument++, _putchar('%');
		}
		else if (format[indexforchars] == '%' && format[indexforchars + 1] == 'c')
		{
			indexforchars += 2, sizeofargument++, _putchar(va_arg(args, int));
		}
		else if (format[indexforchars] == '%' && format[indexforchars + 1] == 's')
		{
			varof_args = va_arg(args, char*);
			while (format[indexforstrings])
			{
				_putchar(varof_args[indexforstrings]);
				indexforstrings++;
			}
			indexforchars += 2;
			sizeofargument += indexforstrings;
		}
		else
		{
			_putchar(format[indexforchars]);
			indexforchars++, sizeofargument++;
		}

	}
	va_end(args);
	return (sizeofargument);
}
