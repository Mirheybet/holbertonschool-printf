#include "main.h"
/**
 * _printf - function
 * @format: pointer
 * Return: length
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, len = 0;

	va_start(args, format);
	if (format[i])
	{
		while (format[i])
		{
			if (format[i] == '%' && format[i + 1] == '\0')
				return (-1);
			else if (format[i] == '%' && format[i + 1] == 'c')
				print_char(args), len++, i = i + 2;
			else if (format[i] == '%' && format[i + 1] == 's')
			{
				len = len + print_str(args), i = i + 2;
			}
			else if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
			{
				len = len + print_int(args), i = i + 2;
			}
			else if (format[i] == '%' && format[i + 1] == '%')
			{
				_putchar('%'), len++, i = i + 2;
			}
			else
			{
				_putchar(format[i]), i++, len++;
			}
		}
	}
	va_end(args);
	return (len);
}
