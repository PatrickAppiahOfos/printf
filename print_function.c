#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable number of arguments
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed_chars++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				printed_chars++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				printed_chars++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				printed_chars += str_len;
			}
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
/**
 * main - test function
 * Return: (0)
 */

int main(void)
{
	char c = 'A';
	char *str = "Hello, World!";

	_printf("Character: %c\nString: %s\nLiteral %%\n", c, str);
	return (0);
}
