#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - custom printf function
 * @format: format
 * Return: printed chars
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	unsigned int chars = 0;
	const char *c = format;

	while (*c != '\0')
	{
		if (*c == '%')
		{
			c++;
			if (*c == 'd' || *c == 'i')
			{
				int num = va_arg(args, int);

				chars += printf("%d", num);
			}
			else
			{
				putchar('%');
				putchar(*c);
				chars += 2;
			}
		}
		else
		{
			putchar(*c);
			chars++;
		}
		c++;
	}
	va_end(args);
	return (chars);
}

/**
 * main - test the function
 * Return: (0)
 */

int main(void)
{
	int num = 42;

	_printf("This is a number: %d\n", num);
	return (0);
}
