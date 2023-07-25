#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int printed_chars = 0;
	char c;
	const char *str;

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* Move past the '%' */
			switch (*format)
			{
			case 'c':
				c = va_arg(args, int);
				putchar(c);
				printed_chars++;
				break;
			case 's':
				str = va_arg(args, const char *);
				while (*str)
				{
					putchar(*str);
					str++;
					printed_chars++;
				}
				break;
			case '%':
				putchar('%');
				printed_chars++;
				break;
			default:
				/* If an unsupported conversion specifier is encountered, ignore it */
				break;
			}
		}
		else
		{
			putchar(*format);
			printed_chars++;
		}

		format++;
	}

	va_end(args);
	return printed_chars;
}
