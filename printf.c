#include "main.c"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - prints a functions
 * @format: return format
 * Return: (0)
 */

int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	va_list args;

	va_start(args, format);

	int printed_chars = 0;

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;  /*Move past '%'*/
			if (format[i] == '\0')
				break;
			if (format[i] == 'c')
			{
				char c = va_arg(args, int); /** 'char' is promoted to 'int' */

				write(1, &c, 1);
				printed_chars++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
					str = "(null)";
				int j = 0;

				while (str[j] != '\0')
				{
					write(1, &str[j], 1);
					j++;
					printed_chars++;
				}
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				printed_chars++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
	}

	va_end(args);

	return (printed_chars);
}
