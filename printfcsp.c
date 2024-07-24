#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"

/**
 * printf_string - This function is for prtinf string
 * @strsize: integer variable is for string line length
 * @str: array of char is for input string line
 * Return: This function returns length of string
 */

int printf_string(int strsize, char *str)
{
	int index = 0;

	if (!str)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		strsize = strsize + 6;
	}
	else
	{
		while (str[index] != '\0')
		{
			_putchar(str[index]);
			index++;
			strsize++;
		}
	}
	return (strsize);
}

/**
 * printf_char - This function is for printf char
 * @charsize: integer variable is for input line length
 * @charvar: it is char variable for input char element
 * Return: This function returns size of line
 */
int printf_char(int charsize, char charvar)
{
	_putchar(charvar);
	charsize++;
	return (charsize);
}

/**
 * _printf - This function is main function
 * @format: This is first element of variadic function
 * Return: It returns size of line
 */

int _printf(const char *format, ...)
{
	va_list(args);

	int index = 0, size = 0;

	if (format == NULL)
		return (-1);
	if (format[0] == '%' && format[1] == 0)
		return (-1);


	va_start(args, format);

	while (format[index])
	{
		if (format[index] == '%' && format[index + 1] == 'c')
		{
			size = printf_char(size, (char)va_arg(args, int)), index += 2;
		}
		else if (format[index] == '%' && format[index + 1] == 's')
		{
			size = printf_string(size, va_arg(args, char *)), index += 2;
		}
		else if (format[index] == '%' && format[index + 1] == '%')
		{
			_putchar('%'), size++, index += 2;
		}
		else
		{
			size++, _putchar(format[index]), index++;
		}

	}
	va_end(args);
	return (size);
}
