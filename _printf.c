#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0; /* Keep track of the number of characters printed */

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* Move past the '%' */

			/* Handle the conversion specifier */
			switch (*format)
			{
				case 'c':
					/* Print a single character */
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
				{
					/* Print a string */
					const char *str = va_arg(args, const char *);
					while (*str)
					{
						putchar(*str);
						str++;
						count++;
					}
					break;
				}
				case '%':
					/* Print a literal '%' */
					putchar('%');
					count++;
					break;
				default:
					/* Unsupported specifier, just print the character */
					putchar(*format);
					count++;
					break;
			}
		}
		else
		{
			/* Regular character, just print it */
			putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);
	return count;
}
