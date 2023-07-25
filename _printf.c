#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Prints formatted output to stdout.
 * @format: The format string containing conversion specifiers.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
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
