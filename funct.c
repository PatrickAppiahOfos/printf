#include "main.h"
#include <unsistd.h>

/*print character*/

int print_char(va_list types, char buffer[])
{
	char c = va_arg(types, int);

	return (write(1, &c, 1));
}
/*print a string**/

int print_string(va_list types, char buffer[])
{
	char *str = va_arg(types, char *);

	if (str == NULL)
		str = "(null)";
	int length = 0;

	while (str[length] != '\0')
		length++;

	return (write(1, str, length));
}

/*** Print % sing*****/

int print_percent(va_list types, char buffer[])
{
	UNUSED(types);

	return (write(1, "%", 1));
}

/****print int***/

int print_int(va_list types, char buffer[])
{
	int n = va_arg(types, int);
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	unsigned int num;

	if (n < 0)
	{
		num = (unsigned int)((-1) * n);
		is_negative = 1;
	}
	else
	{
		num = (unsigned int)n;
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_number(is_negative, i, buffer));
}
/*print_bin*/

int print_binary(va_list types, char buffer[])
{
	unsigned int n = va_arg(types, unsigned int);
	unsigned int m = 2147483648;
	unsigned int a[32];
	int count;

	a[0] = n / m;
	for (unsigned int i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}

	for (unsigned int i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}

	return (count);
}
