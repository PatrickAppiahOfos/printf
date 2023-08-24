#include "main.h"

int _printf(const char *format, ...)
{
        int char_ = 0;
        va_list list_of_arguments;

        if (format == NULL)
                return (-1);

        va_start(list_of_arguments, format);

        while (*format)
        {
                if (*format != '%')
                {
                        write(1, format, 1);
                        char_++;
                }
                else
                {
                        format++;
                        if (*format == '\0')
                                break;
                        if (*format == '%')
                        {
                                write(1, format, 1);
                                char_++;
                        }

                        else if (*format == 'c')
                        {
                                char c = va_arg(list_of_arguments, int);

                                write(1, &c, 1);
                                char_++;
                        }

                        else if (*format == 's')
                        {
                                char *str = va_arg(list_of_arguments, char*);
                                int str_len = 0;

                                while (str[str_len] != '\0')
                                        str_len++;

                                write(1, str, str_len);
                                char_ += str_len;
                        }
                }

                format++;
        }
        va_end(list_of_arguments);

        return (char_);
}
