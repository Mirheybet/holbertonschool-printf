#include "unistd.h"
#include "main.h"
#include <stdarg.h>
/**
 * _putchar- function
 * @c: parameter
 * Return: 0
 */
int _putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

/**
 * print_char- function of printing char
 * @arg: list of arguments
 * Return: a
 */

int print_char(va_list arg)
{
	char a;

	a = _putchar(va_arg(arg, int));
	return (a);
}

/**
 * print_str- function of printing string
 * @arg: list of arguments
 * Return: i
 */


int print_str(va_list arg)
{
	char *c;
	int i = 0;

	c = va_arg(arg, char *);
	if (c == NULL)
		c = "(null)";

	while (c[i] != '\0')
	{
		_putchar(c[i]);
		i++;
	}

	return (i);
}

/**
 * print_int- function of printing int
 * @arg: list of arguments
 * Return: k
 */

int print_int(va_list arg)
{
	int num = va_arg(arg, int);
	int num_length = 0;
	char nums[12];
	int k = 0;

	num_length = snprintf(nums, sizeof(nums), "%d", num);

	while (k < num_length)
	{
		_putchar(nums[k]);
		k++;
	}

	return (k);

}
