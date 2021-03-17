#include "holberton.h"
/**
 * print_char - print char
 * @valist: valist that have the argument to print
 * Return: 1 on success
 **/
int print_char(va_list valist)
{
_putchar(va_arg(valist, int));
return (1);
}
/**
 * print_str - print string.
 * @valist: valist argument to print
 * Return: len of string
 **/
int print_str(va_list valist)
{
char *str;
int i = 0;
str = va_arg(valist, char *);
if (!str)
str = "(null)";
while (str[i])
_putchar(str[i++]);
return (i);
}
