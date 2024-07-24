#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_string - This functions is for print of string
 * @sizestr: int variable | for size
 * @str: array of char variable | for input string
 * Return: size of string
 */

int print_string(int sizestr, char *str)
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
		sizestr = sizestr + 6;
	}
	else
	{
		while (str[index] != '\0')
		{
			_putchar(str[index]);
			index++;
			sizestr++;
		}
	}
	return (sizestr);
}

/**
 * print_char - This function is for printf of char
 * @sizechar: variable of integer | for size
 * @varchar: variable of char | for input char
 * Return: size of char
 */

int print_char(int sizechar, char varchar)
{
	_putchar(varchar);
	sizechar++;
	return (sizechar);
}

/**
 * _printf - main printf (char , string , percent)
 * @format: variable of char array | it is main variable
 * Return: size of main input
 */

int _printf(const char *format, ...)
{
	va_list(args);
	int indexelement = 0, size = 0;

	if (format == NULL)
		return (-1);
	if (*format == '%' && *(format + 1) == 0)
		return (-1);

	va_start(args, format);

	while (format[indexelement])
	{
		if (format[indexelement] == '%' && format[indexelement + 1] == 'c')
		{
			size = print_char(size, (char)va_arg(args, int)), indexelement += 2;
		}
		else if (format[indexelement] == '%' && format[indexelement + 1] == 's')
		{
			size = print_string(size, va_arg(args, char *)), indexelement += 2;
		}
		else if (format[indexelement] == '%' && format[indexelement + 1] == '%')
		{
			_putchar('%'), size++, indexelement += 2;
		}
		else
		{
			size++, _putchar(format[indexelement]), indexelement++;
		}

	}
	va_end(args);
	return (size);
}
