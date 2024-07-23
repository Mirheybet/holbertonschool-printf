#include <unistd.h>
/**
 * _putchar - pdshufj sufa iutchar
 * @c: c is
 * Return: always 0
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
