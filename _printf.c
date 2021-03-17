#include "holberton.h"
/**
 * _printf - main entry.
 * @format: list of types of arguments passed
 * Return: void
 **/
int _printf(const char *format, ...)
{
int count = 0;
va_list valist;
if (format == NULL || (format[0] == '%' && format[1] == '\0'))
return (-1);

va_start(valist, format);

for (; *format != '\0'; format++)
{
if (*format != '%')
{
_putchar(*format);
count++;
}
else
{
format++;
count += format_spec(&format, valist);
}
}
va_end(valist);
return (count);
}
