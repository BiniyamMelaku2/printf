#include "holberton.h"

/**
 * _printf - produces output according to a format.
 * @format: format string
 * Return: number of printed chars
 */
int _printf(const char *format, ...)
{
va_list arglist;
int index = 0, j = 0, count_char = 0;
char *msg = "Unknown:[";
format_chars format_char [] =
{
{"c", print_char},
{"s", print_string},
{"d", print_digit}, 
{"i", print_digit}, 
{"%", print_sign},
{NULL, NULL},
};

va_start(arglist, format);
while(format != NULL && format[index] != '\0')
{
if (format[index] == '%')      /* ("%d", 23), ("%r")  */
{
index++;
for (j = 0; format_char[j].ch != NULL; j++)
{
if (*format_char[j].ch == format[index])
{
count_char += format_char[j].func(arglist);
break;
}
}
switch (format[index])
{
case ('b'):
count_char += print_converted(convert(va_arg(arglist, int), 2));
break;
case ('o'):
count_char += print_converted(convert(va_arg(arglist, int), 8));
break;
case ('X'):
count_char += print_converted(convert(va_arg(arglist, int), 16));
break;

default:  
write(1, msg, 10);
_putchar(37); 
_putchar(format[index]);
_putchar(']');
count_char += 2;
}
/*if (j > 4)
{
}*/
index++;
}
_putchar(format[index]);
count_char++;
index++;
}
va_end(arglist);
return (count_char);
}
